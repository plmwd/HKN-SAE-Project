/**
  ADC1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.h

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

#ifndef _ADC1_H
#define _ADC1_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
/**
  Section: ISR Helper Macros
*/

#define ADC1_ISR_FUNCTION_HEADER    void __attribute__((interrupt, no_auto_psv)) _AD1Interrupt
#define ADC_BUF_SIZE 16

extern bool adc_sampling_request_done;
extern uint16_t adc_buffer[ADC_BUF_SIZE];
   
typedef enum {
    SINGLE_CH = 0,
    DUAL_CH = 1,
    MULTI_CH = 2
} channel_mode_t;

typedef enum {
    MANUAL_BLOCKING,
    MANUAL_NONBLOCKING,
    CONTINUOUS
} sampling_mode_t;

typedef enum {
    ADC_10BIT,
    ADC_12BIT
} adc_precision_t;

typedef enum {
    VPOS_AN0_AN1_AN2 = 0,
    VPOS_AN3_AN4_AN5 = 1,
    VPOS_AN3_AN0_AN25 = 2,
    VPOS_AN0_AN25_AN6 = 3
} channel123_vpos_select_t;

typedef enum {
    VNEG_VREFL = 0,
    VNEG_AN6_AN7_AN8 = 2,
    VNEG_AN9_AN10_AN11 = 3
} channel123_vneg_select_t;

#define CH123SA_MASK    0x0019

typedef struct {
    uint16_t *ch0_buffer; 
    uint16_t ch0_buffer_size;
    
    uint16_t *ch1_buffer; 
    uint16_t ch1_buffer_size;
    
    uint16_t *ch2_buffer;
    uint16_t ch2_buffer_size;
    
    uint16_t *ch3_buffer;
    uint16_t ch3_buffer_size;
} channel_buffers_t;


inline void ADC1_SetPrecision(adc_precision_t p) {
    switch (p) {
        case ADC_10BIT:
            AD1CON1bits.AD12B = 0; 
            break;
        case ADC_12BIT:
            AD1CON1bits.AD12B = 1; 
            break;
        default: 
            AD1CON1bits.AD12B = 0; 
            break;
    };
}

void ADC1_ConfigureSampleMode(sampling_mode_t spm);

inline void ADC1_ConfigureChannelMode(channel_mode_t chm) {
    AD1CON2bits.CHPS = chm;
}

// pos_select can be between 0-63 for AN0 to AN63 respectively
// neg_select can only be 0 or 1 for VREFL and AN1 respectively
inline void ADC1_ConfigureChannel0(uint16_t pos_select, uint16_t neg_select) {
    AD1CHS0bits.CH0SA = pos_select;
    AD1CHS0bits.CH0NA = neg_select;
}

inline void ADC1_ConfigureChannel123(channel123_vpos_select_t pos, channel123_vneg_select_t neg) {
    // CHS123 is laid out weird and the CH123SA field is split up
    // CH123SA<2:1> = bits 4-3, CH123NA = bits 2-1, CH123SA<0> = bit 0
    AD1CHS123 &= ~CH123SA_MASK;
    AD1CHS123 |= ((pos >> 1) << 3) | (pos & 1);
    
    AD1CHS123bits.CH123NA = neg;
}

void ADC1_SampleChannels(uint16_t num_samples, channel_buffers_t *buffers);
void ADC1_SampleInput(uint16_t analog_input, uint16_t *buffer, uint16_t num_samples);
bool ADC1_SampleRequestComplete();

/**
  @Summary
    This function initializes ADC instance for the low current configuration

  @Description
    This routine must be called before any other ADC routine is called. 

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

 

*/

void ADC1_Initialize (void);


/**
  @Summary
    This function initializes ADC instance for the high current configuration

  @Description
    This routine must be called before any other ADC routine is called. 

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

 

*/
void ADC1_Initialize_HIMode (void);


/**
  @Summary
    This function gets the status of the "data_ready" variable

  @Description
    

  @Preconditions
    None.

  @Param
    None.

  @Returns
    "data_ready"

*/
inline bool ADC1_IsDataReady(void);


/**
  @Summary
    This function clears "data_ready" to acknowledge that the data in the buffer
    is ready.

  @Description
    

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

*/
inline void ADC1_AcknowledgeDataReady(void);


/**
  @Summary
    Clears interrupt flag

  @Description
    This routine is used to clear the interrupt flag manually.
 
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    Refer to ADC1_Initialize() for an example

*/

inline static void ADC1_InterruptFlagClear(void)
{
   IFS0bits.AD1IF = 0;
}

/**
  @Summary
    Enables interrupts.

  @Description
    This routine is used to enable the ADC1 interrupt manually.
 
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    Refer to ADC1_Initialize() for an example

*/

inline static void ADC1_InterruptEnable(void)
{  
   IEC0bits.AD1IE = 1;
}

/**
  @Summary
    Disables interrupts

  @Description
    This routine is used to disable the ADC1 interrupt manually.
 
  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    Refer to ADC1_Initialize() for an example

*/

inline static void ADC1_InterruptDisable(void)
{
   IEC0bits.AD1IE = 0;
}

/**
  @Summary
    Starts sampling manually.

  @Description
    This routine is used to start the sampling manually.
 
  @Preconditions
    ADC1_Initialize() function should have been called 
    before calling this function.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        int conversion;
        ADC1__Initialize();
        ADC1_ChannelSelect(AN1_Channel);
        ADC1_SamplingStart();
        //Provide Delay
        for(int i=0;i <1000;i++)
        {
        }
        ADC1_SamplingStop();
        while(!ADC1_IsConversionComplete())
        {
            ADC1_Tasks();   
        }
        conversion = ADC1_ConversionResultGet();
    </code>

*/

inline static void ADC1_SamplingStart(void)
{
   AD1CON1bits.SAMP = 1;
}

/**
  @Summary
    Stops sampling manually.

  @Description
    This routine is used to stop the sampling manually before conversion
    is triggered.
 
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
        int conversion;
        ADC1__Initialize();
        ADC1_ChannelSelect(AN1_Channel);
        ADC1_SamplingStart();
        //Provide Delay
        for(int i=0;i <1000;i++)
        {
        }
        ADC1_SamplingStop();
        while(!ADC1_IsConversionComplete())
        {
            ADC1_Tasks();   
        }
        conversion = ADC1_ConversionResultGet();
    </code>
*/

inline static void ADC1_SamplingStop(void)
{
   AD1CON1bits.SAMP = 0;
}


/**
  @Summary
    Returns true when the conversion is completed

  @Description
    This routine is used to determine if conversion is completed. This routine
    returns the value of the DONE bit. When conversion is complete the routine
    returns 1. It returns 0 otherwise.
 
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    Returns true if conversion is completed

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */

// TODO
inline static bool ADC1_IsConversionComplete( void )
{
    return AD1CON1bits.DONE; //Wait for conversion to complete   
}


/**
  @Summary
    Allows simultaneous sampling to be enabled manually

  @Description
    This routine is used to enable simultaneous sampling of channels manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    None.
  
  @Example
    Refer to ADC1_Initialize(); for an example

*/

inline static void ADC1_SimultaneousSamplingEnable(void)
{
    AD1CON1bits.SIMSAM = 1;
}

/**
  @Summary
    Allows simultaneous sampling to be disabled manually

  @Description
    This routine is used to disable simultaneous sampling of channels manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    None.
  
  @Example
    Refer to ADC1_Initialize(); for an example
*/

inline static void ADC1_SimultaneousSamplingDisble(void)
{
    AD1CON1bits.SIMSAM = 0;
}

/**
  @Summary
    Allows conversion clock prescaler value to be set

  @Description
    This routine is used to allow conversion clock prescaler value to be set manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    Pass in required prescaler integer value
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static void ADC1_ConversionClockPrescalerSet(uint8_t prescaler)
{
    AD1CON3bits.ADCS = prescaler - 1;
}

/**
  @Summary
    Allows module to be enabled manually

  @Description
    This routine is used to enable the ADC1 module manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    None
  
  @Example
*/

inline static void ADC1_Enable(void)
{
    AD1CON1bits.ADON = 1;
}

/**
  @Summary
    Allows module to be disabled manually

  @Description
    This routine is used to disable the ADC1 module manually
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    None
  
  @Example
*/

inline static void ADC1_Disable(void)
{
    AD1CON1bits.ADON = 0;
}



/**
  @Summary
    Allows selection of a priority for interrupt

  @Description
    This routine is used to select desired priority for interrupt.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    None

  @Param
    Pass in required integer priority value
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static void ADC1_InterruptPrioritySet( uint16_t priorityValue )
{
    _AD1IP = 0x7 & priorityValue;
}

/**
  @Summary
    Callback for ADC1.

  @Description
    This routine is callback for ADC1

  @Param
    None.

  @Returns
    None
 
  @Example 
	Refer to ADC1_Initialize(); for an example
*/
void ADC1_CallBack(void);

     

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //_ADC1_H
    
/**
 End of File
*/
