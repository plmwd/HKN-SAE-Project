#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "device_configuration.h"
#include "can.h"
#include "mcc_generated_files/uart1.h"
#include <libpic30.h>

#ifdef DEBUG_CAN

void main(void) {
    SYSTEM_Initialize();
    
    uint16_t test = 0xAAAA;
    uint8_t read = 0;
    
    printf("sending...\n\r");
    
    can_status_t status;
    while (1) {
        status = CAN_TransmitData(&test, sizeof(test), 0x7FF);
        printf("status = %d\n\r", status);
        __delay_ms(750);
    }
    
    
}

#endif
