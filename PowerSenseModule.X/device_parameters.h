/* 
 * File:   device_parameters.h
 * Author: Paul
 *
 * Created on December 29, 2019, 8:16 PM
 */

#ifndef DEVICE_PARAMETERS_H
#define	DEVICE_PARAMETERS_H

 /**********************************************************************
 * DIFFERENTIAL AMPLIFIER - CURRENT SENSING
 ***********************************************************************/
// breadboard test
//#define R_DIFF_1            10000.0              
//#define R_DIFF_2            10000.0             
//#define R_S                 99.0               

// PCB
#define R_DIFF_1            1200.0              // 1.2kOhm
#define R_DIFF_2            75000.0             // 75kOhm
#define R_S                 0.004               // 4mOhm

 /**********************************************************************
 * VOLTAGE DIVIDER - VOLTAGE SENSING
 ***********************************************************************/
// breadboard test
//#define R_V_DIV_1           1             // no division 
//#define R_V_DIV_2           1           

// PCB (1/4 divider)
#define R_V_DIV_1           14990.0           // 14.99KOhm
#define R_V_DIV_2           4990.0            // 4.99KOhm


 /**********************************************************************
 * ADC
 ***********************************************************************/
#define TAD_MIN_12b_ns      118         // nanoseconds
#define TAD_MIN_10b_ns      75          // nanoseconds
#define ADC_CONV_TIME_TAD           12
#define ADC_SAMPLE_TIME_TAD_MIN     2
#define ADC_SAMPLE_TIME_TAD         5
#define ADC_CONV_START_TIME_TAD     3
#define ADC_SAMPLE_START_TIME_TAD   3


#endif	/* DEVICE_PARAMETERS_H */

