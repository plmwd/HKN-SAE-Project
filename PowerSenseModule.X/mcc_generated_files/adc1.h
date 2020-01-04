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
    VNEG_CH123_VREFL = 0,
    VNEG_AN6_AN7_AN8 = 2,
    VNEG_AN9_AN10_AN11 = 3
} channel123_vneg_select_t;

typedef enum {
    VPOS_AN0 = 0, 
    VPOS_AN1 = 1, 
    VPOS_AN2 = 2, 
    VPOS_AN3 = 3, 
    VPOS_AN4 = 4, 
    VPOS_AN5 = 5, 
    VPOS_AN24 = 24,
    VPOS_AN25 = 25,
    VPOS_AN26 = 26,
    VPOS_AN27 = 27,
    VPOS_AN32 = 32
} channel0_vpos_select_t;

typedef enum {
    VNEG_CH0_VREFL = 0,
    VNEG_AN1 = 1
} channel0_vneg_select_t;

#define CH123SA_MASK    0x0019

#define ADC1_CHMODE     AD1CON2bits.CHPS

/**
  @Summary
    Sets the precision of the ADC.

  @Description
    Sets the precision of the ADC. Single channel mode supports 10 and 12 bit while 
    dual or multi channel mode only supports 10 bit.
 
  @Preconditions
    The ADC is disabled.

  @Param
    adc_precision_t p: ADC_10BIT or ADC_12BIT

  @Returns
    None.
*/
void ADC1_SetPrecision(adc_precision_t p);


/**
  @Summary
    Configures the sample mode.

  @Description
    Sets the sample mode inside the private ADC object. The two currently working 
    modes are MANUAL_BLOCKING and MANUAL_NONBLOCKING. MANUAL_BLOCKING mode means that
    when a sampling function is called, the function will loop until all of the requested
    samples have been captured. MANUAL_NONBLOCKING mode will return from the sampling
    function after starting the sampling request and the programmer must check for
    the completion of the request through the ADC1_SampleRequestComplete() function.
 
  @Preconditions
    None.

  @Param
    sampling_mode_t spm

  @Returns
    None.

*/
void ADC1_ConfigureSampleMode(sampling_mode_t spm);


/**
  @Summary
    Configures the channel mode of the ADC.

  @Description
    Sets the channel mode of the ADC. The channel mode specifies which channels to 
    sample.
 
  @Preconditions
    The ADC is disabled.

  @Param
    channel_mode_t chm

  @Returns
    None.
*/
inline static void ADC1_ConfigureChannelMode(channel_mode_t chm) {
    AD1CON2bits.CHPS = chm;
}

/**
  @Summary
    Configures channel 0's positive and negative differential inputs.

  @Description
    Configures channel 0's positive and negative inputs. The ADC will measure
    (vpos - vneg). Used to setup the channel for channel sampling.
 
  @Preconditions
    None.

  @Param
    channel0_vpos_select_t pos: positive input
    channel0_vneg_select_t neg: negative input

  @Returns
    None.
*/
inline static void ADC1_ConfigureChannel0(channel0_vpos_select_t pos, channel0_vneg_select_t neg) {
    AD1CHS0bits.CH0SA = pos;
    AD1CHS0bits.CH0NA = neg;
}


/**
  @Summary
    Configures channel 1, channel 2, and channel 3's positive and negative 
    differential inputs.

  @Description
    Configures channel 1, channel 2, and channel 3's positive and negative 
    differential inputs. The ADC will measure (vpos - vneg). Used to setup the 
    channel for channel sampling.
 
  @Preconditions
    None.

  @Param
    channel123_vpos_select_t pos: positive input
    channel123_vneg_select_t neg: negative input

  @Returns
    None.

  @Example
    <code>
    // channel 1 = AN0, channel 2 = AN1, channel 3 = AN2
    ADC1_ConfigureChannel123(VPOS_AN0_AN1_AN2, VNEG_VREFL);
    </code>
*/
inline static void ADC1_ConfigureChannel123(channel123_vpos_select_t pos, channel123_vneg_select_t neg) {
    // CHS123 is laid out weird and the CH123SA field is split up
    // CH123SA<2:1> = bits 4-3, CH123NA = bits 2-1, CH123SA<0> = bit 0
    AD1CHS123 &= ~CH123SA_MASK;
    AD1CHS123 |= ((pos >> 1) << 3) | (pos & 1);
    
    AD1CHS123bits.CH123NA = neg;
}


/**
  @Summary
    Samples channels 1, 2, and 3 n times.

  @Description
    Samples each channel (1, 2, and 3) n times. The sampling can be blocking or 
    non-blocking. 
 
  @Preconditions
    The channel and sampling mode are configured. The precision is limited to 
    10 bits for 2 or more channels. For one channel, 10 or 12 bits can be used. 

  @Param
    Channel buffers and number of samples to request.

  @Returns
    None.

  @Example
   <code>
    uint16_t ch0_buffer, ch1_buffer, ch2_buffer, ch3_buffer;
 
    // set to blocking, dual channel
    ADC1_ConfigureSampleMode(MANUAL_BLOCKING);
    ADC1_ConfigureChannelMode(DUAL_CH);
    ADC1_ConfigureChannel0(IIN_ANALOG_INPUT, VNEG_VREFL);
    ADC1_ConfigureChannel123(VPOS_AN3_AN4_AN5, VNEG_VREFL);
    ADC1_SetPrecision(ADC_10BIT);
    ADC1_Enable();
 
    ADC1_SampleChannels(&ch0_buffer, &ch1_buffer, &ch2_buffer, &ch3_buffer, NUM_SAMPLES);
   </code>
*/
void ADC1_SampleChannels(uint16_t* ch0_buffer, uint16_t* ch1_buffer, uint16_t* ch2_buffer, uint16_t* ch3_buffer, uint16_t num_samples);


/**
  @Summary
    Samples the analog input (channel 0) with negative input always VREFL n times.

  @Description
    Samples the analog input (channel 0) with negative input always VREFL n times.
     The sampling can be blocking or non-blocking. The precision can be 10 or 12 bits.
 
  @Preconditions
    The sampling mode is selected and the channel mode is SINGLE_CH.

  @Param
    Analog input, buffer, and number of samples.

  @Returns
    None.

  @Example
   <code>
    uint16_t samples[NUM_SAMPLES];
 
    // set to blocking, dual channel
    ADC1_ConfigureSampleMode(MANUAL_BLOCKING);
    ADC1_ConfigureChannelMode(SINGLE_CH);
    ADC1_SetPrecision(ADC_12BIT);
    ADC1_Enable();
 
    ADC1_SampleInput(AN0, samples, NUM_SAMPLES);
   </code>
*/
void ADC1_SampleInput(channel0_vpos_select_t input, uint16_t *buffer, uint16_t num_samples);

/**
  @Summary
    Checks to see if the sample request is complete.

  @Description
    Checks to see if the sample request is complete. Used in non-blocking sampling.
 
  @Preconditions
    The ADC has been initialized.

  @Param
    None.

  @Returns
    None.
*/
bool ADC1_SampleRequestComplete();


/**
  @Summary
    This function initializes ADC instance with default settings of 
        * 10 bit precision
        * simultaneous sampling
        * system clock 
        * manual sampling, auto convert
        * sample time of 31 TAD

  @Description
    This routine must be called before any other ADC routine is called. The ADC
    is initialized but not enabled so that the programmer can specify other settings
    through the channel and sampling configuration functions.

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

inline static void ADC1_ConversionClockPrescalerSet(uint8_t prescaler) {
    AD1CON3bits.ADCS = prescaler - 1;
}


/**
  @Summary
    Allows sample time to be set.

  @Description
    The sampling time can be set manually from 0 to 31 TAD.
  
  @Preconditions
    The ADC is not sampling.
 
  @Returns
    None

  @Param
    Pass in required sampling time integer value
*/
inline static void ADC1_SampleTimeSet(uint8_t sample_time) {
    AD1CON3bits.SAMC = sample_time;
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
