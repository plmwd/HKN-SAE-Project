
#include "can.h"
#include "globals.h"
#include <string.h>

/**
 * TODO:
 * TX abort: ABAT bit
 * CAN timing
 * change device clk speed
 * setup RP pins
 * exception handing?
 *  - NUM_CAN(TX/RX) out of range?
 */


void CAN_Initialize(void) {
    
    enum opmode mode = OP_Normal;
    
    C1CTRL1bits.REQOP   = OP_Config;             // request configuration operation - module acknowledges request in OPMODE
    while (C1CTRL1bits.OPMODE != OP_Config);     // wait for mode request to be acknowledged
    
    // bit timing configuration - time quanta factor, N = 20
    C1CTRL1bits.CANCKS = 0x0;
    /* Phase Segment 1 time is 8 TQ */
    C1CFG2bits.SEG1PH = 0x7;
    /* Phase Segment 2 time is set to be programmable */
    C1CFG2bits.SEG2PHTS = 0x1;
    /* Phase Segment 2 time is 6 TQ */
    C1CFG2bits.SEG2PH = 0x5;
    /* Propagation Segment time is 5 TQ */
    C1CFG2bits.PRSEG = 0x4;
    /* Bus line is sampled three times at the sample point */
    C1CFG2bits.SAM = 0x1;
    /* Synchronization Jump Width set to 4 TQ */
    C1CFG1bits.SJW = 0x3;
    /* Baud Rate pre-scaler bits set to 1:1, (i.e., TQ = (2*1*1)/FCAN) */
    C1CFG1bits.BRP = 0x0;
    
    
    // control registers
    C1CTRL1bits.REQOP   = mode;             // request normal operation - module acknowledges request in OPMODE
    while (C1CTRL1bits.OPMODE != mode);     // wait for mode request to be acknowledged
    C1CTRL1bits.CSIDL   = 0;                // continue in idle mode
    C1CTRL1bits.CANCAP  = 0;                // disable timestamping 
    C1CTRL1bits.WIN     = 1;                // use message filter
    
    C1CTRL2bits.DNCNT   = 0;                // no DeviceNet data filtering
    
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
}

uint16_t CAN_WriteBuf(void* data, can_msg_t* buffer, uint16_t num_bytes, uint16_t starting_byte) {
    //get byte addressable pointer
    char* data_byte_addr = (char*)&(buffer->word3_data0);
    
    //if number of bytes is longer than the max data field
    if ((num_bytes >= CAN_MSG_SIZE) || (starting_byte >= CAN_MSG_SIZE)) 
        return 1;   // error
    
    //add offset to select byte
    data_byte_addr += starting_byte;
    
    //copy data to location
    memcpy(data_byte_addr, data, num_bytes);
    
    return 0;
}

uint16_t CAN_TransmitData(uint16_t buffer, uint16_t sid, uint16_t num_bytes) {

}