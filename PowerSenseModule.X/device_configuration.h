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
 * FRC_NORMAL : unaltered FRC oscillator, FCY = 7.37MHz / 2 = 3.685MHz
 * FRC_40MHz: closest cycle frequency to 40MHz (39.698MHz)
 * FRC_SLOWEST: slowest FRC frequency, 14.39KHz
 * POSC_24MHz: Primary, external oscillator at 24MHz
 * CLOCK_DEBUG: internal clock on OSC2 - can't be used with primary oscillator
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
 * UART1BR_9600Hz
 * UART1BR_19200Hz
 * UART1BR_128KHz
 * UART1_ENABLE: enable UART1 initialization at startup
 * 
 ***********************************************************************
 * ADC OPTIONS 
 ***********************************************************************
 * ADC1_BURST: enable ADC burst sampling operation 
 * ADC1_BURST_FREQ: if ADC_BURST is defined, optionally can define a burst frequency (needs testing)
 * ADC1_BURST_SMPL_FREQ: unsigned long, if ADC_BURST is defined, don't define for fastest frequency and define user defined sample frequency (not implemented)
 * 
 * ADC1_CONTINUOUS: enable ADC for continuous sampling (not implemented)
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
    

#define FRC_40MHz
#define CLOCK_DEBUG

#define TMR1_ENABLE

#define TMR3_ENABLE

#define CAN1_ENABLE
#define CAN1BR_125KHz

#define UART1_ENABLE
#define UART1BR_9600Hz

#define ADC1_ENABLE
//#define ADC1_BURST

#define UART1BR_2400Hz









































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



#endif	/* DEVICE_CONFIGURATION_H */

