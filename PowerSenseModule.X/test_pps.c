#include "device_configuration.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include <libpic30.h>
#include <stdio.h>

#ifdef DEBUG_PPS

// PCB TODO: repurpose programming header or remove it??
void main(void) {
    // testing if the PGD and PGC pins are usable after the programmer is removed.
    SYSTEM_Initialize();
    uint8_t c = 0;
    
    while (1) {
        printf("test\n\r");
        __delay_ms(1000);
    }
    
//    test_SetDigitalPin();
//    test_SetDigitalOutput();
//    
//    while (1) {
//        test_SetLow();
//        __delay_ms(500);
//        test_SetHigh();
//        __delay_ms(500);
//    }
}

#endif
