
#include "can.h"
#include "globals.h"
#include <string.h>
#include "mcc_generated_files/pin_manager.h"


typedef struct __attribute__((packed))
{
    unsigned priority                   :2;
    unsigned remote_transmit_enable     :1;
    unsigned send_request               :1;
    unsigned error                      :1;
    unsigned lost_arbitration           :1;
    unsigned message_aborted            :1;
    unsigned transmit_enabled           :1;
} CAN_TX_CONTROLS;

/**************************************************************************
 * 
 *                              ISRs
 * 
 **************************************************************************/
/**
 * CAN1 Receieve Data Ready Interrupt
 */
void __attribute__((interrupt, auto_psv)) _C1RxRdyInterrupt(void) {
    
    IFS2bits.C1RXIF = 0;        // clear interrupt flag
}

/**
 * CAN1 Transmit Data Request Interrupt
 */
void __attribute__((interrupt, auto_psv)) _C1TXInterrupt(void) {
#ifdef DEBUG
    C1TR01CONbits.TXREQ0 = 0;
#endif
    
    IFS4bits.C1TXIF = 0;        // clear interrupt flag
}

/**
 * CAN1 Event Interrupt
 */
void __attribute__((interrupt, auto_psv)) _C1Interrupt(void) {
    
    IFS2bits.C1IF = 0;      // clear interrupt flag
}


/**************************************************************************
 * 
 *                              INIT
 * 
 **************************************************************************/
void CAN_Initialize(CAN_OP_MODES mode) {
    /* put the module in configuration mode */
    C1CTRL1bits.REQOP = CAN_CONFIGURATION_MODE;
    while(C1CTRL1bits.OPMODE != CAN_CONFIGURATION_MODE);

    /* Set up the baud rate*/	
    C1CFG1 = 0x00;	//BRP TQ = (2 x 1)/FCAN; SJW 1 x TQ; 
    C1CFG2 = 0x3BE;	//WAKFIL disabled; SEG2PHTS Freely programmable; SEG2PH 4 x TQ; SEG1PH 8 x TQ; PRSEG 7 x TQ; SAM Once at the sample point; 
    C1FCTRL = 0xC001;	//FSA Transmit/Receive Buffer TRB1; DMABS 32; 
    C1FEN1 = 0x00;	//FLTEN8 disabled; FLTEN7 disabled; FLTEN9 disabled; FLTEN0 disabled; FLTEN2 disabled; FLTEN10 disabled; FLTEN1 disabled; FLTEN11 disabled; FLTEN4 disabled; FLTEN3 disabled; FLTEN6 disabled; FLTEN5 disabled; FLTEN12 disabled; FLTEN13 disabled; FLTEN14 disabled; FLTEN15 disabled; 
    C1CTRL1 = 0x00;	//CANCKS FOSC/2; CSIDL disabled; ABAT disabled; REQOP Sets Normal Operation Mode; WIN Uses buffer window; CANCAP disabled; 

    /* Filter configuration */
    /* enable window to access the filter configuration registers */
    /* use filter window*/
    C1CTRL1bits.WIN=1;
	   
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
    C1CTRL1bits.WIN=0;    

    // configure TX/RX message buffers 
    C1TR01CONbits.TXEN0 = 1;                
    if (NUM_CANTX_MSGS > 1)
        C1TR01CONbits.TXEN1 = 1;            // set buffer for TX
    if (NUM_CANTX_MSGS > 2)
        C1TR23CONbits.TXEN2 = 1;
    if (NUM_CANTX_MSGS > 3)
        C1TR23CONbits.TXEN3 = 1;
    if (NUM_CANTX_MSGS > 4)
        C1TR45CONbits.TXEN4 = 1;
    if (NUM_CANTX_MSGS > 5)
        C1TR45CONbits.TXEN5 = 1;
    if (NUM_CANTX_MSGS == 6)
        C1TR67CONbits.TXEN6 = 1;
    else {
        C1TR67CONbits.TXEN6 = 1;
        C1TR67CONbits.TXEN7 = 1;       
    }

    /* clear the buffer and overflow flags */   
    C1RXFUL1 = 0x0000;
    C1RXFUL2 = 0x0000;
    C1RXOVF1 = 0x0000;
    C1RXOVF2 = 0x0000;	

    /* configure the device to interrupt on the receive buffer full flag */
    /* clear the buffer full flags */ 	
    C1INTFbits.RBIF = 0;  

    /* put the module in normal mode */
    C1CTRL1bits.REQOP = mode;
    while(C1CTRL1bits.OPMODE != mode);	

}


/**************************************************************************
 * 
 *                             FUNCTIONS
 * 
 **************************************************************************/
CAN_ERR CAN_WriteBuf(void* data, uint16_t buf_num, uint16_t num_bytes, uint16_t starting_byte) {
    //get byte addressable pointer
    char* data_byte_addr = (char*)&(canTXBuffer[buf_num].data_byte0);
    
    //if number of bytes is longer than the max data field
    if ((num_bytes >= CAN_MSG_SIZE) || (starting_byte >= CAN_MSG_SIZE)) 
        return CAN_ERR_MSG_SIZE_OVERFLOW;   // error
    
    //add offset to select byte
    data_byte_addr += starting_byte;
    
    //copy data to location
    memcpy(data_byte_addr, data, num_bytes);
    
    return CAN_SUCCESS;
}


void CAN_ConfigBufForStandardDataFrame(uint16_t buf_num) {
    can_msg_t* buffer = &canTXBuffer[buf_num];
    buffer->SRR = 0;        // normal message
    buffer->IDE = 0;        // standard frame
    buffer->EIDH = 0;       // extended ID high
    buffer->EIDL = 0;       // extended ID high
    buffer->RTR = 0;        // normal message
    buffer->RB0 = 0;
    buffer->RB1 = 0;
}


CAN_ERR CAN_Transmit(CAN_TXBUF txbuf, uint16_t sid, CAN_TX_PRIOIRTY priority, uint16_t num_bytes) {
    //SID must be an 11-bit number - 2^11 = 2048
    if (sid > 2028)
        return CAN_ERR_INVALID_SID;   // not an 11-bit number
    
    if (num_bytes > 8)
        return CAN_ERR_MSG_SIZE_OVERFLOW;   // max 8 bytes
     
    CAN_TX_CONTROLS* TXControls;
    
    //request transmission
    switch(txbuf) {
        case CAN_TXBUF_0:
            TXControls = (CAN_TX_CONTROLS*)&C1TR01CONbits;
            break;
        default:
            return CAN_ERR_INVALID_TXBUF; 
    }
    
    can_msg_t* buffer = &canTXBuffer[txbuf]; 
    
    if (TXControls->transmit_enabled != 1)
        return CAN_ERR_TXBUF_DISABLED;
    
    if(TXControls->send_request == 1)
        return CAN_ERR_TXBUF_FULL;
    
    buffer->SID = sid;          // bus peripheral address
    buffer->DLC = num_bytes;    // number of bytes in buffer to send (starting from byte 0)
    
    TXControls->priority = priority;
    
    //send message
    TXControls->send_request = 1;
    
    // successful
    return (TXControls->error) ? CAN_ERROR : CAN_SUCCESS;
}