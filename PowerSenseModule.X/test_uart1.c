#include "device_configuration.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include <libpic30.h>
#include <stdio.h>

#ifdef DEBUG_UART
int main(void)
{   
    // initialize the device
    SYSTEM_Initialize();
    
    uint8_t c = 0;
    uint16_t outcome;
    
    while (1) {
        printf("input: \n");
        outcome = scanf("%c", &c);
        printf("read: %c, outcome: %d\n\r", c, outcome);
        printf("----------------------------\n\r");
        __delay_ms(1000);
    }
    
}
#endif
