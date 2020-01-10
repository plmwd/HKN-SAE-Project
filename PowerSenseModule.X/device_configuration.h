/* 
 * File:   device_configuration.h
 * Author: Paul
 *
 * Created on August 10, 2019, 1:51 PM
 */

#ifndef DEVICE_CONFIGURATION_H
#define	DEVICE_CONFIGURATION_H

/**********************************************************************
 * 
 *                   DEFINED GENERATED VARIABLES
 * 
 **********************************************************************
 * FCY
 * BURST_PERIOD
 * BURST_CYCLES
 * TMR1_CLOCK_PRESCALER
 * TMR1_CLOCK_PRESCALER_BITS
 * ADC1_CONV_CLOCK_DIVIDER
 * ADC1_CONV_CLOCK_FREQ
 **********************************************************************/ 

/**********************************************************************
 * 
 *                              DEBUG
 * 
 **********************************************************************
 * Added #define [DEBUG] for different mains in different files for 
 * testing various peripherals/systems. First define "DEBUG" to 
 * comment out the main power sense main.
 * **********************************************************************
 * DEBUG : disables system main
 * DEBUG_UART : uart debug main file
 * DEBUG_UART_ALT_PIN: uses different pins for UART rx = pin 18, tx = pin 17
 * DEBUG_ADC
 * DEBUG_PPS : peripheral pin select
 * DEBUG_CAN
 ***********************************************************************/
#define DEBUG
#define DEBUG_CAN
#define DEBUG_UART_ALT_PIN

/**********************************************************************
 * 
 *                      DEVICE CONFIGURATION
 * 
 **********************************************************************
 * Use #define [OPTION] with the following options below, one from each
 * category to configure the device (ie #define FRC_NORMAL). Compiler
 * error will be generated for invalid options (ie two options from CLOCK)
 * 
 ***********************************************************************
 * CLOCK (needs testing)
 ***********************************************************************
 * FRC_40MHz: closest cycle frequency to 40MHz (39.698MHz)
 * POSC_25MHz: Primary, crystal oscillator at 25MHz
 * DEBUG_CLOCK: internal clock on OSC2 - can't be used with primary oscillator
 * 
 ***********************************************************************
 * CAN BAUD RATE
 ***********************************************************************
 * CAN1BR_1MHz          (needs testing)
 * CAN1BR_125KHz        (needs testing)
 * CAN1_ENABLE: enable CAN initialization at startup
 * 
 ***********************************************************************
 * UART BAUD RATE
 *********************************************************************** 
 * UART1BR_2400Hz
 * UART1BR_4800Hz
 * UART1BR_9600Hz - only one working atm
 * UART1BR_19200Hz
 * UART1BR_128KHz
 * UART1_ENABLE: enable UART1 initialization at startup
 * 
 ***********************************************************************
 * SAMPLING/ADC OPTIONS 
 ***********************************************************************
 * BURST_FREQ: frequency at which the bursts start - timer 1
 * SAMPLING_FREQ: frequency at which the ADC will sample. If undefined, 
 *  it's the maximum rate.
 * 
 * ADC1_ENABLE: enable ADC initialization at startup
 * 
 ***********************************************************************
 * TMR OPTIONS 
 ***********************************************************************
 * TMR1_ENABLE: enable TMR1 initialization at startup
 * TMR3_ENABLE: enable TMR3 initialization at startup
 *
 */
    

#define POSC_25MHz
#define UART1_ENABLE
#define CAN1_ENABLE
#define CAN1BR_125KHz


//#define ADC1_ENABLE
//#define BURST_FREQ 500
// SAMPLING_FREQ undefined for maximum rate























// system clock
#ifndef _XTAL_FREQ
#if defined(FRC_40MHz)

#define _XTAL_FREQ  79395351UL

#elif defined(FRC_NORMAL)

#define _XTAL_FREQ  7370000UL

#elif defined(FRC_SLOWEST)

#define _XTAL_FREQ  14395UL

#elif defined(POSC_25MHz)

#define _XTAL_FREQ  25000000UL

#else
#error NO CLOCK DEFINED
#endif
#endif

#ifndef FCY
#define FCY     _XTAL_FREQ / 2
#endif


// ADC clock
//#define BURST_PERIOD_ns     (1000000000UL / BURST_FREQ)
//#define BURST_CYCLES        ((FCY * BURST_PERIOD_ns) / 1000000000UL)

#if defined FRC_40MHz               // FCY = 20 MHz
#define ADC1_CONV_CLOCK_DIVIDER     2       
#define ADC1_CONV_CLOCK_FREQ        10000000UL


#elif defined POSC_25MHz            // FCY = 12.5 MHz
#define ADC1_CONV_CLOCK_DIVIDER     1       
#define ADC1_CONV_CLOCK_FREQ        12500000UL

#else
#error NO ADC CONVERSION CLOCK DEFINED
#endif



/*          DONT TOUCH              */
//CLOCK
#if (defined(FRC_NORMAL) && (defined(FRC_SLOWEST) || defined(FRC_40MHz) || defined(POSC_24MHz)))
#error INVALID CLOCK CONFIG
#endif
#if (defined(FRC_SLOWEST) && (defined(FRC_NORMAL) || defined(FRC_40MHz) || defined(POSC_24MHz)))
#error INVALID CLOCK CONFIG
#endif
#if (defined(FRC_40MHz) && (defined(FRC_NORMAL) || defined(FRC_SLOWEST) || defined(POSC_24MHz)))
#error INVALID CLOCK CONFIG
#endif
#if (defined(POSC_24MHz) && (defined(FRC_NORMAL) || defined(FRC_SLOWEST) || defined(FRC_40MHz)))
#error INVALID CLOCK CONFIG
#endif
#if (defined(CLOCK_DEBUG) && defined(POSC_24MHz))
#error CANT USE POSC WITH CLOCK DEBUG
#endif

//CAN
#if (defined(CAN1BR_1MHz) && defined(CAN1BR_125KHz))
#error INVALID CAN1 CONFIG
#endif

//UART
#if (defined(UART1BR_2400Hz) && (defined(UART1BR_4800Hz) || defined(UART1BR_9600Hz) || defined(UART1BR_19200Hz) || defined(UART1BR_128KHz)))
#error INVALID UART1 CONFIG
#endif
#if (defined(UART1BR_4800Hz) && (defined(UART1BR_2400Hz) || defined(UART1BR_9600Hz) || defined(UART1BR_19200Hz) || defined(UART1BR_128KHz)))
#error INVALID UART1 CONFIG
#endif
#if (defined(UART1BR_9600Hz) && (defined(UART1BR_4800Hz) || defined(UART1BR_2400Hz) || defined(UART1BR_19200Hz) || defined(UART1BR_128KHz)))
#error INVALID UART1 CONFIG
#endif
#if (defined(UART1BR_19200Hz) && (defined(UART1BR_4800Hz) || defined(UART1BR_9600Hz) || defined(UART1BR_2400Hz) || defined(UART1BR_128KHz)))
#error INVALID UART1 CONFIG
#endif
#if (defined(UART1BR_128KHz) && (defined(UART1BR_4800Hz) || defined(UART1BR_9600Hz) || defined(UART1BR_19200Hz) || defined(UART1BR_2400Hz)))
#error INVALID UART1 CONFIG
#endif


//ADC
#if(defined(ADC1_BURST) && !defined(ADC1_BURST_FREQ))
#error ADC1 BURST FREQUENCY NOT DEFINED
#endif
#if(defined(ADC1_BURST) && !defined(ADC1_BURST_SMPL_FREQ))
#warning ASSUMING FASTEST ADC1 SAMPLING FREQUENCY
#endif

//BURST SAMPLING
#if (BURST_CYCLES < 65536)
#define TMR1_CLOCK_PRESCALER_BITS   0
#define TMR1_CLOCK_PRESCALER        1

#elif (BURST_CYCLES < 65536 * 8)
#define TMR1_CLOCK_PRESCALER_BITS   1
#define TMR1_CLOCK_PRESCALER        8

#elif (BURST_CYCLES < 65536 * 64)
#define TMR1_CLOCK_PRESCALER_BITS   2
#define TMR1_CLOCK_PRESCALER        64

#elif (BURST_CYCLES < 65536 * 256)
#define TMR1_CLOCK_PRESCALER_BITS   3
#define TMR1_CLOCK_PRESCALER        256

#else
#error TIMER 1 CLOCK ERROR
#endif

#endif	/* DEVICE_CONFIGURATION_H */

