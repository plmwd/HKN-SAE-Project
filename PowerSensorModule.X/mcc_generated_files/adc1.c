
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
    // ASAM enabled; ADDMABM disabled; ADSIDL disabled; DONE disabled; SIMSAM Simultaneous; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC TMR3; AD12B 10-bit; ADON enabled; SSRCG disabled; 

   AD1CON1 = 0b1000000001001100;

    // CSCNA disabled; VCFG0 AVDD; VCFG1 AVSS; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every sample/conversion operation; CHPS 2 Channel; 

   AD1CON2 = 0b000000100000000;

    // SAMC 5; ADRC FOSC/2; ADCS 0; 

   AD1CON3 = 0x500;

    // CH0SA AN2; CH0SB AN2; CH0NB VREFL; CH0NA VREFL; 

   AD1CHS0 = 0b0000001000000010;

    // CSS26 disabled; CSS25 disabled; CSS24 disabled; CSS27 disabled; 

   AD1CSSH = 0x00;

    // CSS2 disabled; CSS1 disabled; CSS0 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; 

   AD1CSSL = 0x00;

    // DMABL Allocates 1 word of buffer to each analog input; ADDMAEN disabled; 

   AD1CON4 = 0x00;

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
	// ADC1 callback function 
	//ADC1_CallBack();
	
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
