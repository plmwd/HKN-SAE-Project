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
    
    unsigned int test = 'z';
    
    while(1)
    {
        // Wait until the buffer contains something
        while(UART1_ReceiveBufferIsEmpty())
        {

            //wait
        }
        test = UART1_Read();

        printf("I scanned : %c\n\r", test);
    }

    
}
#endif
