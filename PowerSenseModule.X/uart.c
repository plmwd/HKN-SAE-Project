


#include <p33EV32GM102.h>

//#include "uart.h"
#include <uart.h>
#include "device_configuration.h"
#include "mcc_generated_files/clock.h"

void __attribute__((auto_psv, interrupt)) _U1RXInterrupt(void) {

}

void __attribute__((auto_psv, interrupt)) _U1TXInterrupt(void) {

}

/*
 * 1 stop bit, no parity, 
 * 
 */
void UART_Initialize(void) {
    
#if defined(UART1BR_2400Hz)
    U1BRG = FCY / 2400UL;
#elif defined(UART1BR_4800Hz)
    U1BRG = FCY / 4800;
#elif defined(UART1BR_9600Hz)
    U1BRG = FCY / 9600;
#elif defined(UART1BR_19200Hz)
    U1BRG = FCY / 19200;
#elif defined(UART1BR_128KHz)
    U1BRG = FCY / 128000;
#endif
    
    U1MODE = 0;
    U1STA = 0;
    
    // UARTEN needs to be enabled before UTXEN
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
    
}