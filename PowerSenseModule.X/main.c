/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
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
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/adc1.h"
#include "calibration.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/tmr3.h"

#define NUM_CAL_POINTS      10              // Number of calibration points
#define DIFFAMP_GAIN        80
#define OPAMP_UNITY_GAIN    1
#define R_SHUNT             0.004

#define I_EFF_GAIN          DIFFAMP_GAIN * OPAMP_UNITY_GAIN;

#define R_V_DIV_1           1000000.0           // 1MOhm
#define R_V_DIV_2           499000.0            // 499kOhm
#define R_DIFF_1            1200.0              // 1.2kOhm
#define R_DIFF_2            75000.0             // 75kOhm
#define R_S                 0.004               // 4mOhm


void TMR1_InterruptCallback (void);
// dummy functions for now - test basic functionality
uint16_t ProcessCurrent(uint16_t);
uint16_t ProcessVoltage(uint16_t);
void CAN_send(uint16_t);    

// current and voltage calibration data - ideal points need to be set
cal_point_t current_cal_data[NUM_CAL_POINTS];
cal_point_t voltage_cal_data[NUM_CAL_POINTS];

/*
                         Main application
 */
int main(void)
{
    double current_readings[ADC_BUF_SIZE / 2];
    double voltage_readings[ADC_BUF_SIZE / 2];
    
    double current_avg = 0;
    double voltage_avg = 0;
    
    // initialize the device
    SYSTEM_Initialize();
    
    while (1)
    {
        if (ADC1_IsDataReady() == true) {
            ADC1_AcknowledgeDataReady();  
            
            uint16_t *data = ADC1_GetBufferPtr(); 
            
            // process sampled data
            uint16_t buffer_index = 0;
            uint16_t i;
            for (i = 0; i < ADC_BUF_SIZE / 2; i++) {
                buffer_index = i * 2;
                current_readings[i] = ProcessCurrent(CalibrateData(data[buffer_index], current_cal_data, NUM_CAL_POINTS));   
                voltage_readings[i] = ProcessVoltage(CalibrateData(data[buffer_index + 1], voltage_cal_data, NUM_CAL_POINTS));  
            }
            
            // average data
            for (i = 0; i < ADC_BUF_SIZE / 2; i++) {
                current_avg += current_readings[i];
                voltage_avg += voltage_readings[i];
            }
            current_avg /= ADC_BUF_SIZE / 2;
            voltage_avg /= ADC_BUF_SIZE / 2;
                
            // send data over CAN
            //CAN_send(current_avg);
            //CAN_send(voltage_avg);
        }
    }
    return 1; 
}


uint16_t ProcessCurrent(uint16_t data) {
    
    double adcVoltage, fOneBatteryCurrent = 0;
    
    // Converting to actual voltage
    adcVoltage = 5.0 * (data / 1023.0);
    
    // Getting current going through battery
    fOneBatteryCurrent =  R_DIFF_1 / (R_DIFF_2 * R_S) * adcVoltage;
    
    return fOneBatteryCurrent;
}



// The following function takes the value read by the
// ADC and returns the voltage of the F1 battery
uint16_t ProcessVoltage(uint16_t data) {
    
    double adcVoltage, fOneBatteryVoltage = 0;
    
    // Converting to actual voltage
    adcVoltage = 5.0 * (data / 1023.0);
    
    // Getting voltage of actual battery using circuit analysis
    fOneBatteryVoltage = adcVoltage * ( R_V_DIV_1 / R_V_DIV_2 + 1);
    
    return fOneBatteryVoltage;
}


void CAN_Send(uint16_t data) {
    return;
}

/**
 End of File
*/

