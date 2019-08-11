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
    This function gets the "adc_buffer" pointer

  @Description
    

  @Preconditions
    None.

  @Param
    None.

  @Returns
    The pointer of "adc_buffer"

*/
uint16_t* ADC1_GetBufferPtr(void);

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
bool ADC1_IsDataReady(void);


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
void ADC1_AcknowledgeDataReady(void);


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
    Gets the buffer loaded with conversion results.

  @Description
    This routine is used to get the analog to digital converted values in a
    buffer. This routine gets converted values from multiple channels.
 
  @Preconditions
    This routine returns the buffer containing the conversion values only after 
    the conversion is complete. Completion status conversion can be checked using 
    ADC1_IsConversionComplete() routine.
 
  @Param
    None.

  @Returns
    Returns the count of the buffer containing the conversion values.

  @Example
    <code>
        int count;
        //Initialize for channel scanning
        ADC1_Initialize();
        ADC1_SamplingStart();
        //Provide Delay
        for(int i=0;i <1000;i++)
        {
        }
        ADC1_SamplingStop();
        while(!ADC1_IsConversionComplete())
        {
            count = ADC1_ConversionResultBufferGet();
        }
    </code>
*/

uint16_t ADC1_ConversionResultBufferGet(uint16_t *buffer);

/**
  @Summary
    Returns the ADC1 conversion value for Channel 0.

  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.
 
  @Preconditions
    The channel required must be selected before calling this routine using
    ADC1_ChannelSelect(channel). This routine returns the 
    conversion value only after the conversion is complete. Completion status 
    conversion can be checked using ADC1_IsConversionComplete()
    routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */

inline static uint16_t ADC1_Channel0ConversionResultGet(void) 
{
    return ADC1BUF0;
}

/**
  @Summary
    Returns the ADC1 conversion value from Channel 1.

  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.
 
  @Preconditions
    The channel required must be selected before calling this routine using
    ADC1_ChannelSelect(channel). This routine returns the 
    conversion value only after the conversion is complete. Completion status 
    conversion can be checked using ADC1_IsConversionComplete()
    routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */

inline static uint16_t ADC1_Channel1ConversionResultGet(void) 
{
    return ADC1BUF1;
}

/**
  @Summary
    Returns the ADC1 conversion value from Channel 2.

  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.
 
  @Preconditions
    The channel required must be selected before calling this routine using
    ADC1_ChannelSelect(channel). This routine returns the 
    conversion value only after the conversion is complete. Completion status 
    conversion can be checked using ADC1_IsConversionComplete()
    routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */

inline static uint16_t ADC1_Channel2ConversionResultGet(void) 
{
    return ADC1BUF2;
}

/**
  @Summary
    Returns the ADC1 conversion value from Channel 3.

  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.
 
  @Preconditions
    The channel required must be selected before calling this routine using
    ADC1_ChannelSelect(channel). This routine returns the 
    conversion value only after the conversion is complete. Completion status 
    conversion can be checked using ADC1_IsConversionComplete()
    routine.
   
  @Returns
    Returns the buffer containing the conversion value.

  @Param
    Buffer address
  
  @Example
    Refer to ADC1_Initialize(); for an example
 */

inline static uint16_t ADC1_Channel3ConversionResultGet(void) 
{
    return ADC1BUF3;
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

inline static bool ADC1_IsConversionComplete( void )
{
    return AD1CON1bits.DONE; //Wait for conversion to complete   
}


/**
  @Summary
    Returns the channel selected for conversion

  @Description
    This routine is used to return the channel selected for conversion.
  
  @Preconditions
    ADC1_Initialize() function should have been 
    called before calling this function.
 
  @Returns
    The value of the Channel Conversion register

  @Param
    None
  
  @Example
    Refer to ADC1_Initialize(); for an example
 
*/

inline static uint16_t ADC1_ChannelSelectGet( void )
{
    return AD1CHS0bits.CH0SA ;
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
    Allows sutomatic sampling to be enabled manually

  @Description
    This routine is used to enable automatic sampling of channels manually
  
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

inline static void ADC1_AutomaticSamplingEnable(void)
{
    AD1CON1bits.ASAM = 1;
}

/**
  @Summary
    Allows automatic sampling to be disabled manually

  @Description
    This routine is used to disable automatic sampling of channels manually
  
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

inline static void ADC1_AutomaticSamplingDisable(void)
{
    AD1CON1bits.ASAM = 0;
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
