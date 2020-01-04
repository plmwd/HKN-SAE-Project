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
    uint16_t ch0_buffer[NUM_SAMPLES];
    uint16_t ch1_buffer[NUM_SAMPLES];
    ADC1_ConfigureSampleMode(MANUAL_BLOCKING);
    ADC1_ConfigureChannelMode(DUAL_CH);
    ADC1_ConfigureChannel0(IIN_ANALOG_INPUT, 0);
    ADC1_ConfigureChannel123(VPOS_AN3_AN4_AN5, VNEG_CH0_VREFL);
    ADC1_SetPrecision(ADC_10BIT);
    ADC1_Enable();
    
    
    while (1) {
        ADC1_SampleChannels(ch0_buffer, ch1_buffer, 0, 0, NUM_SAMPLES);
        for (uint8_t i = 0; i < NUM_SAMPLES; i++) {
            printf("ch0 sample #%d: %d\n\r", i, ch0_buffer[i]);
            printf("ch1 sample #%d: %d\n\r", i, ch1_buffer[i]);
        }
        
        printf("------------------------------------------\n\n\r");
        __delay_ms(2000);
    }
    
}

#endif
