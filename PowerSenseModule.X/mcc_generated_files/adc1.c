
/**
  ADC1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.c

  @Summary
    This is the generated header file for the ADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for ADC1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.125
        Device            :  dsPIC33EV32GM102
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB 	          :  MPLAB X v5.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include "adc1.h"
#include "tmr3.h"
#include <math.h>
#include "../device_parameters.h"
#include "../device_configuration.h"

bool adc_sampling_request_done = false;
uint16_t* adc_buffer = 0;
uint16_t num_requested_samples = 0, num_completed_samples = 0, num_next_completed_samples = 0;
channel_mode_t ch_mode = 0;


/**
  Section: Data Type Definitions
*/

/* ADC Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

  @Description
    This defines the object required for the maintenance of the hardware
    instance. This object exists once per hardware instance of the peripheral.

 */
typedef struct
{
	uint8_t intSample;
}

ADC_OBJECT;

static ADC_OBJECT adc1_obj;

/**
  Section: Driver Interface
*/

//// generates 
//uint16_t ADC1_Generate_Clock_Multiplier(void) {
//    uint16_t T_instruction_ns = ceil(1000000000.0 / FCY);
//    if (T_instruction_ns < TAD_MIN_12b_ns) {
//        return ceil(TAD_MIN_US / T_instruction_ns);
//    }
//    else {
//        return 0;
//    }
//}

void ADC1_ConfigureSampleMode(sampling_mode_t spm) {
    switch (spm) {
        case MANUAL_BLOCKING:
            
            break;
        case MANUAL_NONBLOCKING:
            
            break;
        case CONTINUOUS:
            
            break;
    };
}

void ADC1_SampleChannels(uint16_t num_samples, channel_buffers_t *buffers);
void ADC1_SampleInput(uint16_t analog_input, uint16_t *buffer, uint16_t num_samples);

void ADC1_Initialize (void)
{
   AD1CON1bits.ADSIDL   = 0;    // Keep ADC running when system idle
   AD1CON1bits.ADDMABM  = 1;    // DMA Buffer written in order of conversion
   AD1CON1bits.AD12B    = 0;    // 10-bit operation in order to use 4 channels
   AD1CON1bits.FORM     = 0;    // Unsigned integer
   AD1CON1bits.SSRC     = 7;    // default auto-convert after sampling
   AD1CON1bits.SSRCG    = 0;    // 0 clock source group
   AD1CON1bits.SIMSAM   = 1;    // Sample channels simultaneously
   AD1CON1bits.ASAM     = 0;    // Manual sampling
   AD1CON1bits.SAMP     = 0;    // Hold
   
   AD1CON2bits.CSCNA    = 0;    // Don't scan input
   AD1CON2bits.SMPI     = 0;    // default generate interrupt after every conversion
   AD1CON2bits.CHPS     = 0;    // default convert channel 0
   AD1CON2bits.BUFM     = 0;    // Always fill buffer from the beginning
   AD1CON2bits.ALTS     = 0;    // Always sample MUX A 
   


   AD1CON3bits.ADRC     = 0;    // Use system clock

   // set clock divider according to system clock. Minimum clock period is 118 ns or ~13 MHz.
   // see "device_configuration.h" for frequency and divider value.
   // only for system clock - ignored for RC clock
   AD1CON3bits.ADCS     = ADC1_CONV_CLOCK_DIVIDER;
  
   // set sample time - only for automatic convert after sample
   AD1CON3bits.SAMC = ADC_SAMPLE_TIME_TAD + ADC_CONV_START_TIME_TAD + ADC_SAMPLE_START_TIME_TAD;

   // DMABL Allocates 8 word of buffer to each analog input; ADDMAEN disabled; 
   //AD1CON4 = 0x04;
   
    // default CH0SA AN0; CH0SB AN0; CH0NB VREFL; CH0NA VREFL; 
   AD1CHS0 = 0x00;

    // default CSS26 disabled; CSS25 disabled; CSS24 disabled; CSS27 disabled; 

   AD1CSSH = 0x00;

    // CSS2 disabled; CSS1 disabled; CSS0 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; 

   AD1CSSL = 0x00;

    // CH123SA2 AN0/AN1/AN2; CH123SB2 AN0/AN1/AN2; CH123NA CH1=VREF-; CH123NB CH1=VREF-; 

   AD1CHS123 = 0x00;

   
   adc1_obj.intSample = AD1CON2bits.SMPI;
   
   // initialize ADC variables
   adc_sampling_request_done = false;
   ch_mode = false;
   num_requested_samples = 0; 
   num_completed_samples = 0; 
   num_next_completed_samples = 0;
   adc_buffer = 0;
   
   ADC1_InterruptEnable();
   // programmer configures channels and sampling mode and enables the ADC
}

void __attribute__ ((weak)) ADC1_CallBack(void)
{
    // Add your custom callback code here
}

void __attribute__ ( ( __interrupt__ , auto_psv ) ) _AD1Interrupt ( void )
{
    // Disable timer 3 (ADC conversion trigger)
    TMR3_Stop();
    
	// ADC1 callback function 
	//ADC1_CallBack();
	
    // transfer ADC samples to buffer (could use DMA in the future)
    adc_buffer[0] = ADC1BUF0;
    adc_buffer[1] = ADC1BUF1;
    adc_buffer[2] = ADC1BUF2;
    adc_buffer[3] = ADC1BUF3;
    adc_buffer[4] = ADC1BUF4;
    adc_buffer[5] = ADC1BUF5;
    adc_buffer[6] = ADC1BUF6;
    adc_buffer[7] = ADC1BUF7;
    adc_buffer[8] = ADC1BUF8;
    adc_buffer[9] = ADC1BUF9;
    adc_buffer[10] = ADC1BUFA;
    adc_buffer[11] = ADC1BUFB;
    adc_buffer[12] = ADC1BUFC;
    adc_buffer[13] = ADC1BUFD;
    adc_buffer[14] = ADC1BUFE;
    adc_buffer[15] = ADC1BUFF;
    
    
    adc_sampling_request_done = true;
    
    // clear the ADC interrupt flag
    IFS0bits.AD1IF = false;
}

uint16_t* ADC1_GetBufferPtr(void) {
    return &adc_buffer;
}

bool ADC1_IsDataReady(void) {
    return adc_sampling_request_done;
}

void ADC1_AcknowledgeDataReady(void) {
    adc_sampling_request_done = false;
}

/**
  End of File
*/
