#include "device_configuration.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include "power_sense_module.h"
#include "mcc_generated_files/adc1.h"
#include <libpic30.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#ifdef DEBUG_SYSTEM

#define NUM_SAMPLES_PER_CH  10
#define STR_LEN 40

void BackslashFor(uint16_t num_backslashes);

void main(void) {
    // string to display on terminal
    char display[STR_LEN];
    const uint16_t display_len = strlen(display);
    
    // create buffers for the ADC
    uint16_t current_samples[NUM_SAMPLES_PER_CH], voltage_samples[NUM_SAMPLES_PER_CH];
    double current_value = 0.0, voltage_value = 0.0;
    
    SYSTEM_Initialize();
    
    // configure and enable ADC for dual channel readings for current and voltage
    ADC1_ConfigureSampleMode(MANUAL_BLOCKING);
    ADC1_ConfigureChannelMode(DUAL_CH);
    ADC1_SetPrecision(ADC_10BIT);
    ADC1_ConfigureChannel0(VPOS_AN2, VNEG_CH0_VREFL);               // current 
    ADC1_ConfigureChannel123(VPOS_AN3_AN4_AN5, VNEG_CH123_VREFL);   // voltage
    ADC1_Enable();
    
    // display text over UART
    sprintf(display, "voltage = %.2f V\n\rcurrent = %.2f A", 0.0, 0.0);
    printf("%s", display);
    
    // main while loop
    while (1) {
        // get ADC samples
        //printf("sampling...\n\r");
//        ADC1_SampleInput(VPOS_AN2, current_samples, 1);
//        printf("measured: %u\n\r", current_samples[0]);
        ADC1_SampleChannels(current_samples, voltage_samples, 0, 0, NUM_SAMPLES_PER_CH);
        
        // calculate current and voltage from samples and take average
        for (int i = 0; i < NUM_SAMPLES_PER_CH; i++) {
            current_value += PSM_ProcessCurrent(current_samples[i]);
            voltage_value += PSM_ProcessVoltage(voltage_samples[i]);
            //printf("measured voltage: %u, %.2f\tcurrent: %u, %.2f\n\r", voltage_samples[i], voltage_value, current_samples[i], current_value * 100);
        }
        current_value /= NUM_SAMPLES_PER_CH;
        voltage_value /= NUM_SAMPLES_PER_CH;
        
        
        // display on UART
        //printf("voltage = %.2f V\tcurrent = %.2f mA\n\r", voltage_value, current_value * 1000);
        
        printf("  ");
        BackslashFor(strlen(display));
        printf("\r");
        sprintf(display, "voltage = %.2f V\n\rcurrent = %.2f mA", voltage_value, current_value * 1000);
        printf("%s", display);
        
        current_value = 0;
        voltage_value = 0;
        __delay_ms(1000);
    }
}

#endif

void BackslashFor(uint16_t num_backslashes) {
    for (int i = 0; i < num_backslashes; i++) {
        printf("\b");
    }
}
