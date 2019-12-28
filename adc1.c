
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
#include "clock.h"

bool data_ready = 0;
uint16_t adc_buffer[ADC_BUF_SIZE] = { 0 };


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


void ADC1_Initialize (void)
{
   
   AD1CON1bits.ADON     = 1;    // Enable ADC
   AD1CON1bits.ADSIDL   = 0;    // Keep ADC running when system idle
   AD1CON1bits.ADDMABM  = 1;    // Buffer written in order of conversion
   AD1CON1bits.AD12B    = 0;    // 10-bit operation
   AD1CON1bits.FORM     = 0;    // Unsigned integer
   AD1CON1bits.SSRC     = 2;    // TMR3 starts conversion
   AD1CON1bits.SSRCG    = 0;    // 0 clock source group
   AD1CON1bits.SIMSAM   = 1;    // Sample channels simultaneously
   AD1CON1bits.ASAM     = 1;    // Auto sample after last conversion
   AD1CON1bits.SAMP     = 1;
   
   AD1CON2bits.CSCNA    = 0;    // Don't scan input
   AD1CON2bits.SMPI     = 7;    // Generate interrupt after 16 total samples (8 per CH)
   AD1CON2bits.CHPS     = 1;    // Converts CH0 and CH1
   AD1CON2bits.BUFM     = 0;    // Always fill buffer from the beginning
   AD1CON2bits.ALTS     = 0;    // Always sample MUX A 
   

    // SAMC 5; ADRC FOSC/2; ADCS 0; 

   AD1CON3bits.ADRC = 0;        // Use system clock
   AD1CON3bits.ADCS = ADC1CLOCK_GENMultiplier();

    // CH0SA AN2; CH0SB AN2; CH0NB VREFL; CH0NA VREFL; 

   AD1CHS0 = 0b0000001000000010;

    // CSS26 disabled; CSS25 disabled; CSS24 disabled; CSS27 disabled; 

   AD1CSSH = 0x00;

    // CSS2 disabled; CSS1 disabled; CSS0 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; 

   AD1CSSL = 0x00;

    // DMABL Allocates 8 word of buffer to each analog input; ADDMAEN disabled; 

   AD1CON4 = 0x04;

    // CH123SA2 CH1=OA1/AN3; CH123SB2 CH1=OA1/AN3; CH123NA CH1=VREF-; CH123NB CH1=VREF-; 

   AD1CHS123 = 0x101;

   
   adc1_obj.intSample = AD1CON2bits.SMPI;
   
   data_ready = 0;
           
   // Enabling ADC1 interrupt.
   IEC0bits.AD1IE = 1;

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
    
    
    data_ready = true;
    
    // clear the ADC interrupt flag
    IFS0bits.AD1IF = false;
}

uint16_t* ADC1_GetBufferPtr(void) {
    return &adc_buffer;
}

bool ADC1_IsDataReady(void) {
    return data_ready;
}

void ADC1_AcknowledgeDataReady(void) {
    data_ready = false;
}

/**
  End of File
*/
