#include "device_configuration.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/tmr1.h"

#ifdef DEBUG_ADC

void main() {
    SYSTEM_Initialize();
    TMR1_Start();       // start ADC triggering
    
    
}

#endif
