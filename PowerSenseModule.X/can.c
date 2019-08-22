
#include "can.h"
#include "globals.h"

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
    opmode mode = OP_Normal;
    
    // control registers
    C1CTRL1bits.CSIDL   = 0;                // continue in idle mode
    C1CTRL1bits.REQOP   = mode;             // request normal operation - module awknowledges request in OPMODE
    while (C1CTRL1bits.OPMODE != mode);     // wait for mode request to be awknowledged
    C1CTRL1bits.CANCAP  = 0;                // disable timestamping 
    C1CTRL1bits.WIN     = 1;                // use message filter
    
    C1CTRL2bits.DNCNT   = 0;                // no DeviceNet data filtering
    
    
    // configure TX/RX message buffers 
    C1TR01CONbits.TXEN0 = 1;                
    if (NUM_CANTX_MSGS > 1)
        C1TR01CONbits.TXEN1 = 1;            // set buffer for TX
    else 
        goto done;
    if (NUM_CANTX_MSGS > 2)
        C1TR23CONbits.TXEN2 = 1;
    else
        goto done;
    if (NUM_CANTX_MSGS > 3)
        C1TR23CONbits.TXEN3 = 1;
    else
        goto done;
    if (NUM_CANTX_MSGS > 4)
        C1TR45CONbits.TXEN4 = 1;
    else
        goto done;
    if (NUM_CANTX_MSGS > 5)
        C1TR45CONbits.TXEN5 = 1;
    else
        goto done;
    if (NUM_CANTX_MSGS == 6)
        C1TR67CONbits.TXEN6 = 1;
    else {
        C1TR67CONbits.TXEN6 = 1;
        C1TR67CONbits.TXEN7 = 1;       
    }
    done:
    
    int i;
}