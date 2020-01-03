#include "device_configuration.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/mcc.h"
#include <libpic30.h>

#ifdef DEBUG_ADC

#define NUM_SAMPLES     10
void main() {
    SYSTEM_Initialize();
    
    // setup ADC
    uint16_t sample[NUM_SAMPLES];
    ADC1_ConfigureSampleMode(MANUAL_BLOCKING);
    ADC1_ConfigureChannelMode(SINGLE_CH);
    ADC1_SetPrecision(ADC_12BIT);
    ADC1_Enable();
    
    
    while (1) {
        ADC1_SampleInput(IIN_ANALOG_INPUT, sample, NUM_SAMPLES);
        for (uint8_t i = 0; i < NUM_SAMPLES; i++) {
            printf("sample #%d: %d\n\r", i, sample[i]);
        }
        
        printf("------------------------------------------\n\n\r");
        __delay_ms(2000);
    }
    
}

#endif
