#include <stdio.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/uart1.h"
#include <libpic30.h>
#include "device_configuration.h"

#ifdef DEBUG_UART
int main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();
    UART1_Initialize();
    UART1_Enable();
    
    while (1) {
        printf("Hello world!\n\r");
        __delay_ms(250);
    }
    
}
#endif
