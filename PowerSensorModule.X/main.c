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

uint16_t current_calibration[10];
uint16_t voltage_calibration[10];

/*
                         Main application
 */
int main(void)
{
    uint16_t current_readings[ADC_BUF_SIZE / 2];
    uint16_t voltage_readings[ADC_BUF_SIZE / 2];
    
    uint16_t current_avg;
    uint16_t voltage_avg;
    
    // initialize the device
    SYSTEM_Initialize();
    while (1)
    {
        if (data_ready == 1) {
            data_ready = 0;    
            
            // process sampled data
            uint16_t buffer_index = 0;
            for (uint16_t i = 0; i < ADC_BUF_SIZE / 2; i++) {
                buffer_index = i * 2;
                current_readings[i] = calibrate_data(adc_buffer[buffer_index], 'I');    
                voltage_readings[i] = calibrate_data(adc_buffer[buffer_index + 1], 'V');  
            }
            
            // average data
            for (int i = 0; i < ADC_BUF_SIZE / 2; i++) {
                current_avg += current_readings[i];
                voltage_avg += voltage_readings[i];
            }
            current_avg /= ADC_BUF_SIZE / 2;
            voltage_avg /= ADC_BUF_SIZE / 2;
                
            // send data over CAN
            CAN_send(current_avg);
            CAN_send(voltage_avg);
        }
    }
    return 1; 
}

uint16_t calibrate_data(uint16_t data, char type) {
    // current
    if (type == 'I') {
        return data;        // CHANGE ME
    }
    else if (type == 'V') {
        return data;        // CHANGE ME
    }
    else 
        return data;
}

void CAN_send(uint16_t data) {
    return;
}

/**
 End of File
*/

