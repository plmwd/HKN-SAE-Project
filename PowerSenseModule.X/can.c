
#include "can.h"
#include <string.h>
#include "mcc_generated_files/pin_manager.h"
#include "device_configuration.h"
#include "dma.h"

#define CAN_NUM_RX_BUFFERS      3
#define CAN_NUM_TX_BUFFERS      1

typedef struct __attribute__((packed))
{
    unsigned priority                   :2;
    unsigned remote_transmit_enable     :1;
    unsigned send_request               :1;
    unsigned error                      :1;
    unsigned lost_arbitration           :1;
    unsigned message_aborted            :1;
    unsigned transmit_enabled           :1;
} can_tx_controls_t;

typedef struct {
    can_message_t       *tx_buffer;
    can_message_t       *rx_buffer;
    can_tx_controls_t   *tx_controls; 
} can_object_t;

can_object_t can_obj;
can_message_t can_buffer[CAN_NUM_RX_BUFFERS + CAN_NUM_TX_BUFFERS] \
        __attribute__((aligned(CAN_MSG_SIZE * (CAN_NUM_RX_BUFFERS + CAN_NUM_TX_BUFFERS))));

dma_channel_settings_t dma_canrx_settings = { 
                            .SIZE   = 0,     
                            .DIR    = 0,     
                            .HALF   = 0,     
                            .NULLW  = 0,     
                            .AMODE  = 2,     
                            .MODE   = 0,     
                            .IRQSEL = 34,     
                            .PAD    = &C1RXD,     
                            .CNT    = 7     
                            };

dma_channel_settings_t dma_cantx_settings = { 
                            .SIZE   = 0,     
                            .DIR    = 1,     
                            .HALF   = 0,     
                            .NULLW  = 0,     
                            .AMODE  = 2,     
                            .MODE   = 0,     
                            .IRQSEL = 70,     
                            .PAD    = &C1TXD,     
                            .CNT    = 7     
                            };


/**************************************************************************
 * 
 *                              ISRs
 * 
 **************************************************************************/
/**
 * CAN1 Receive Data Ready Interrupt
 */
void __attribute__((interrupt, auto_psv)) _C1RxRdyInterrupt(void) {
    
    IFS2bits.C1RXIF = 0;        // clear interrupt flag
}

/**
 * CAN1 Transmit Data Request Interrupt
 */
void __attribute__((interrupt, auto_psv)) _C1TXInterrupt(void) {
    
    IFS4bits.C1TXIF = 0;        // clear interrupt flag
}

/**
 * CAN1 Event Interrupt
 */
void __attribute__((interrupt, auto_psv)) _C1Interrupt(void) {
    if (C1ECbits.TERRCNT >= 127)
        C1TR01CONbits.TXREQ0 = 0;
    
    IFS2bits.C1IF = 0;      // clear interrupt flag
}


/**************************************************************************
 * 
 *                              INIT
 * 
 **************************************************************************/
can_status_t CAN_Initialize() {
    
    /* put the module in configuration mode */
    CAN_OperationModeRequest(CAN_CONFIGURATION_MODE);
    
    
    // ECAN control 1
    C1CTRL1bits.CSIDL = 0;      // continue operation in idle mode
    C1CTRL1bits.ABAT = 0;       // clear TX abort
    C1CTRL1bits.CANCAP = 0;     // disable CAN capture
    
    // configure CAN/DMA settings
    C1FCTRLbits.DMABS = 0;      // 4 buffers in RAM 
    C1FCTRLbits.FSA = 0;        // FIFO start TRB0 - not used
    
    // replace below baud config with inline function
#if defined(CAN1BR_1MHz)
    CAN1BR_1MHz_Initialize();
#elif defined(CAN1BR_125KHz)
    CAN1BR_125KHz_Initialize();
#endif

    /* Filter configuration */
    /* enable window to access the filter configuration registers */
    /* use filter window*/
    CAN_UseFilterSFRWindow();
	   
    C1FEN1 = 0x00;	//FLTENx disabled
    
    /* select acceptance masks for filters */

    /* Configure the masks */
    C1RXM0SIDbits.SID = 0x0; 
    C1RXM1SIDbits.SID = 0x0; 
    C1RXM2SIDbits.SID = 0x0; 

    C1RXM0SIDbits.EID = 0x0; 
    C1RXM1SIDbits.EID = 0x0; 
    C1RXM2SIDbits.EID = 0x0; 
     
    C1RXM0EID = 0x00;     	
    C1RXM1EID = 0x00;     	
    C1RXM2EID = 0x00;     	

    C1RXM0SIDbits.MIDE = 0x0; 
    C1RXM1SIDbits.MIDE = 0x0; 
    C1RXM2SIDbits.MIDE = 0x0; 
    
    /* Configure the filters */

    /* Non FIFO Mode */

    /* clear window bit to access ECAN control registers */
    CAN_UseBufferSFRWindow();       

    /* clear the buffer and overflow flags */   
    C1RXFUL1 = 0x0000;
    C1RXFUL2 = 0x0000;
    C1RXOVF1 = 0x0000;
    C1RXOVF2 = 0x0000;	

    /* configure the device to interrupt on the receive buffer full flag */
    /* clear the buffer full flags */ 	
    C1INTFbits.RBIF = 0;  

    // configure can object
    can_obj.tx_controls = (can_tx_controls_t*)&C1TR01CONbits;
    can_obj.tx_controls->transmit_enabled = true;
    can_obj.tx_controls->priority = CAN_PRIORITY_HIGH;
    can_obj.tx_buffer = can_buffer;
    can_obj.rx_buffer = can_buffer + CAN_NUM_TX_BUFFERS;
    can_obj.tx_buffer->RB0 = 0;
    can_obj.tx_buffer->RB1 = 0;
    can_obj.tx_buffer->use_extended_id = false;
    can_obj.tx_buffer->use_remote_frame = false;
    
    
    // enable interrupts
    CAN_TransmitBufferInterruptEnable();
    CAN_ReceiveBufferInterruptEnable();
    
    /* put the module in normal mode */
    CAN_OperationModeRequest(CAN_LOOPBACK_MODE);

    /* Enable CAN1 Interrupt */
    IEC2bits.C1IE = 1;

    /* Enable Receive interrupt */
    C1INTEbits.RBIE = 1;
	
    /* Enable Error interrupt*/
    C1INTEbits.ERRIE = 1;
    
    // configure DMA for CAN RX and TX
    DMA_InitializeChannel(DMA_CANTX_CH, dma_cantx_settings, (uint16_t *)can_buffer);
    DMA_InitializeChannel(DMA_CANRX_CH, dma_canrx_settings, (uint16_t *)can_buffer);
    
    return CAN_SUCCESS;
}


/**************************************************************************
 * 
 *                             FUNCTIONS
 * 
 **************************************************************************/
can_status_t CAN_WriteTXBuffer(void* data, uint8_t num_bytes, uint16_t starting_byte) {
    //get byte addressable pointer
    uint8_t* data_byte_addr = (uint8_t*)&can_obj.tx_buffer->data_byte0;
    
    //if number of bytes is longer than the max data field
    if ((num_bytes >= CAN_MSG_SIZE) || 
        (starting_byte >= CAN_MSG_SIZE) ||
        (num_bytes + can_obj.tx_buffer->data_num_bytes > CAN_MSG_SIZE)) {
            return CAN_ERR_INVALID_DATA_SIZE; 
    }
            
    
    //add offset to select byte
    data_byte_addr += starting_byte;
    
    //copy data to location
    memcpy(data_byte_addr, data, num_bytes);
    
    // tell CAN module how many new bytes to send
    // gets reset once the message is sent
    can_obj.tx_buffer->data_num_bytes += num_bytes;
    
    return CAN_SUCCESS;
}

can_status_t CAN_StartTransmission() {
    if (can_obj.tx_controls->transmit_enabled != 1)
        return CAN_ERR_TXBUF_DISABLED;
    
    if(can_obj.tx_controls->send_request == 1)
        return CAN_ERR_TXBUF_FULL;
    
    
    // send message
    can_obj.tx_controls->send_request = 1;
    
    // reset tx_buffer for new message
    // The number of bytes to send is only reset so that the data in the buffer doesn't
    // have to be cleared because once new data is written, only those new bytes 
    // will be sent, not the old data (because the old bytes are at a byte > num_bytes).
    // The SID will also be rewritten when sending data.
    //can_obj.tx_buffer.data_num_bytes = 0;
    
    return CAN_SUCCESS;
}

void CAN_TXMessageSIDSet(uint16_t sid) {
    can_obj.tx_buffer->standard_id = sid;
}

void CAN_TXMessagePrioritySet(can_tx_priority_t priority) {
    can_obj.tx_controls->priority = priority;
}

can_status_t CAN_TransmitData(void *data, uint8_t num_bytes, uint16_t sid) {
    can_status_t error;
    
    //SID must be an 11-bit number - 2^11 = 2048
    if (sid > 0x7FF)
        return CAN_ERR_INVALID_SID;   // not an 11-bit number
    
    if (num_bytes > 8 || num_bytes < 1)
        return CAN_ERR_INVALID_DATA_SIZE;   // max 8 bytes
     
    CAN_WriteTXBuffer(data, num_bytes, 0);
    CAN_TXMessageSIDSet(sid);
    
    error = CAN_StartTransmission();
    if (error != CAN_SUCCESS) {
        return error;
    }
    
    // wait for data to be sent
    while (can_obj.tx_controls->send_request == 1);
    
    // successful
    return (can_obj.tx_controls->error) ? CAN_ERROR : CAN_SUCCESS;
}


void CAN1BR_1MHz_Initialize(void) {
#if defined(FRC_40MHz)
#ifdef CAN1BR_1MHz
#warning CAN 1MHZ WITH INTERNAL FRC 40MHZ WILL BE UNRELIABLE AND BAUD WILL BE OFF
#warning ACTUAL BAUD RATE IS 992.4KHZ
#endif    

    /* Set up the baud rate*/	
    C1CFG1 = 0x00;	//BRP TQ = (2 x 1)/FCAN; SJW 1 x TQ; 
    C1CFG2 = 0x3BE;	//WAKFIL disabled; SEG2PHTS Freely programmable; SEG2PH 4 x TQ; SEG1PH 8 x TQ; PRSEG 7 x TQ; SAM 3 times at the sample point; 
    C1FCTRL = 0xC001;	//FSA Transmit/Receive Buffer TRB1; DMABS 32; 
    C1FEN1 = 0x00;	//FLTEN8 disabled; FLTEN7 disabled; FLTEN9 disabled; FLTEN0 disabled; FLTEN2 disabled; FLTEN10 disabled; FLTEN1 disabled; FLTEN11 disabled; FLTEN4 disabled; FLTEN3 disabled; FLTEN6 disabled; FLTEN5 disabled; FLTEN12 disabled; FLTEN13 disabled; FLTEN14 disabled; FLTEN15 disabled; 
    C1CTRL1 = 0x00;	//CANCKS FOSC/2; CSIDL disabled; ABAT disabled; REQOP Sets Normal Operation Mode; WIN Uses buffer window; CANCAP disabled; 

#elif defined (POSC_25MHz)
    /* Set up the baud rate*/	
    C1CFG1bits.BRP = 0;
    C1CFG1bits.SJW = 0;         // 1 TQ
    
    C1CFG2bits.WAKFIL = 0;      // CAN bus filter not used to wake up device
    C1CFG2bits.SEG1PH = 7;      // phase segment 1 is 8 TQ
    C1CFG2bits.SEG2PH = 7;      // phase segment 2 is 8 TQ
    C1CFG2bits.PRSEG = 7;       // propagation is 8 TQ
    C1CFG2bits.SAM = 1;         // sample 3 times at the sample point
    
    C1CTRL1bits.CANCKS = 1;     // FCAN = FOSC = 2 * FCY 
    
#else
#error CAN 1MHZ WITH CURRENT CLOCK NOT REALIZABLE
#endif
}

void CAN1BR_125KHz_Initialize(void) {
#if defined(FRC_40MHz)
#ifdef CAN1BR_125KHz
#warning CAN 125KHZ WITH INTERNAL FRC 40MHZ WILL BE UNRELIABLE
#warning ACTUAL BAUD RATE IS 124.6KHZ
#endif
    
    /* Set up the baud rate*/	
    C1CFG1 = 0x07;	//BRP TQ = (2 x 8)/FCAN; SJW 1 x TQ; 
    C1CFG2 = 0x3BE;	//WAKFIL disabled; SEG2PHTS Freely programmable; SEG2PH 4 x TQ; SEG1PH 8 x TQ; PRSEG 7 x TQ; SAM 3 times at the sample point; 
    C1FCTRL = 0xC001;	//FSA Transmit/Receive Buffer TRB1; DMABS 32; 
    C1FEN1 = 0x00;	//FLTEN8 disabled; FLTEN7 disabled; FLTEN9 disabled; FLTEN0 disabled; FLTEN2 disabled; FLTEN10 disabled; FLTEN1 disabled; FLTEN11 disabled; FLTEN4 disabled; FLTEN3 disabled; FLTEN6 disabled; FLTEN5 disabled; FLTEN12 disabled; FLTEN13 disabled; FLTEN14 disabled; FLTEN15 disabled; 
    C1CTRL1 = 0x00;	//CANCKS FOSC/2; CSIDL disabled; ABAT disabled; REQOP Sets Normal Operation Mode; WIN Uses buffer window; CANCAP disabled; 
    
    //C1CTRL1bits.CANCKS = 1;     //FCAN = 2 * FP

#elif defined (POSC_25MHz)
    /* Set up the baud rate*/	
    C1CFG1 = 0x04;	//BRP TQ = (2 x 5)/FCAN; SJW 1 x TQ; 
    C1CFG2 = 0x1A8;	//WAKFIL disabled; SEG2PHTS Freely programmable; SEG2PH 2 x TQ; SEG1PH 6 x TQ; PRSEG 1 x TQ; SAM Once at the sample point; 
    C1FCTRL = 0x01;	//FSA Transmit/Receive Buffer TRB1; DMABS 4; 
    C1FEN1 = 0x00;	//FLTEN8 disabled; FLTEN7 disabled; FLTEN9 disabled; FLTEN0 disabled; FLTEN2 disabled; FLTEN10 disabled; FLTEN1 disabled; FLTEN11 disabled; FLTEN4 disabled; FLTEN3 disabled; FLTEN6 disabled; FLTEN5 disabled; FLTEN12 disabled; FLTEN13 disabled; FLTEN14 disabled; FLTEN15 disabled; 
    C1CTRL1 = 0x00;	//CANCKS FOSC/2; CSIDL disabled; ABAT disabled; REQOP Sets Normal Operation Mode; WIN Uses buffer window; CANCAP disabled; 

    //C1CTRL1bits.CANCKS = 1;     //FCAN = 2 * FP
    
#elif defined(FRC_NORMAL)
#warning CAN 125KHZ WITH INTERNAL FRC 7.37MHZ WILL BE UNRELIABLE AND BAUD WILL BE OFF
#warning ACTUAL BAUD RATE IS 122.8KHZ
    
    /* Set up the baud rate*/	
    C1CFG1 = 0x02;      //BRP TQ = (2 x 3)/FCAN; SJW 1 x TQ; 
    C1CFG2 = 0x3BE;	//WAKFIL disabled; SEG2PHTS Freely programmable; SEG2PH 4 x TQ; SEG1PH 8 x TQ; PRSEG 7 x TQ; SAM 3 times at the sample point; 
    C1FCTRL = 0xC001;	//FSA Transmit/Receive Buffer TRB1; DMABS 32; 
    C1FEN1 = 0x00;	//FLTEN8 disabled; FLTEN7 disabled; FLTEN9 disabled; FLTEN0 disabled; FLTEN2 disabled; FLTEN10 disabled; FLTEN1 disabled; FLTEN11 disabled; FLTEN4 disabled; FLTEN3 disabled; FLTEN6 disabled; FLTEN5 disabled; FLTEN12 disabled; FLTEN13 disabled; FLTEN14 disabled; FLTEN15 disabled; 
    C1CTRL1 = 0x00;	//CANCKS FOSC/2; CSIDL disabled; ABAT disabled; REQOP Sets Normal Operation Mode; WIN Uses buffer window; CANCAP disabled; 
    
    C1CTRL1bits.CANCKS = 1;     //FCAN = 2 * FP
    
#else
#error CAN 1MHZ WITH CURRENT CLOCK NOT REALIZABLE
#endif
}