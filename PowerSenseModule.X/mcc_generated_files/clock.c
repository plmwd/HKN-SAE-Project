/**
  @Generated PIC24 / dsPIC33 / PIC32MM MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    clock.c

  @Summary:
    This is the clock.c file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  dsPIC33EV32GM102
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB             :  MPLAB X v5.10
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

#include <stdint.h>
#include "xc.h"
#include "clock.h"
#include <math.h>

// ADC clock variables
#define TAD_MIN_US      75     
uint16_t TAD_ns;            // nanoseconds
uint16_t TAD_multiplier;


void CLOCK_Initialize_FRC_40MHz(void)
{
    // FRCDIV FRC/1; PLLPRE 2; DOZE 1:8; PLLPOST 1:4; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3040;
    // TUN Center Frequency-0.940%; 
    OSCTUN = 0x2C;
    // ROON disabled; ROSEL disabled; RODIV Base clock value; ROSSLP disabled; 
    REFOCON = 0x00;
    // PLLDIV 85; 
    PLLFBD = 0x55;
    // AD1MD enabled; PWMMD enabled; T3MD enabled; T4MD enabled; T1MD enabled; U2MD enabled; T2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; C1MD enabled; T5MD enabled; I2C1MD enabled; 
    PMD1 = 0x00;
    // IC4MD enabled; IC3MD enabled; OC1MD enabled; IC2MD enabled; OC2MD enabled; IC1MD enabled; OC3MD enabled; OC4MD enabled; 
    PMD2 = 0x00;
    // CMPMD enabled; 
    PMD3 = 0x00;
    // CTMUMD enabled; REFOMD enabled; 
    PMD4 = 0x00;
    // PWM2MD enabled; PWM1MD enabled; PWM3MD enabled; 
    PMD6 = 0x00;
    // DMA0MD enabled; 
    PMD7 = 0x00;
    // DMTMD enabled; SENT2MD enabled; SENT1MD enabled; 
    PMD8 = 0x00;
    // CF no clock failure; NOSC FRCPLL; CLKLOCK unlocked; OSWEN Switch is Complete; 
    __builtin_write_OSCCONH((uint8_t) (( 0x01 << _OSCCON_NOSC_POSITION ) >> 0x08 ));
    __builtin_write_OSCCONL((uint8_t) ((0x100 | _OSCCON_OSWEN_MASK) & 0xFF));
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
}

void CLOCK_Initialize_FRC_NORMAL(void) {
    // FRCDIV FRC/1; PLLPRE 2; DOZE 1:1; PLLPOST 1:2; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x00;
    // TUN Center Frequency-0%; 
    OSCTUN = 0x00;
    // ROON disabled; ROSEL disabled; RODIV Base clock value; ROSSLP disabled; 
    REFOCON = 0x00;
    // PLLDIV 0; 
    PLLFBD = 0x00;
    // AD1MD enabled; PWMMD enabled; T3MD enabled; T4MD enabled; T1MD enabled; U2MD enabled; T2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; C1MD enabled; T5MD enabled; I2C1MD enabled; 
    PMD1 = 0x00;
    // IC4MD enabled; IC3MD enabled; OC1MD enabled; IC2MD enabled; OC2MD enabled; IC1MD enabled; OC3MD enabled; OC4MD enabled; 
    PMD2 = 0x00;
    // CMPMD enabled; 
    PMD3 = 0x00;
    // CTMUMD enabled; REFOMD enabled; 
    PMD4 = 0x00;
    // PWM2MD enabled; PWM1MD enabled; PWM3MD enabled; 
    PMD6 = 0x00;
    // DMA0MD enabled; 
    PMD7 = 0x00;
    // DMTMD enabled; SENT2MD enabled; SENT1MD enabled; 
    PMD8 = 0x00;
    // CF no clock failure; NOSC FRCPLL; CLKLOCK unlocked; OSWEN Switch is Complete; 
    __builtin_write_OSCCONH((uint8_t) (0x00));
    __builtin_write_OSCCONL((uint8_t) ((0x100 | _OSCCON_OSWEN_MASK) & 0xFF));
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
}


void CLOCK_Initialize_FRC_SLOWEST(void) {
    // FRCDIV FRC/256; PLLPRE 2; DOZE 1:1; PLLPOST 1:2; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x380;
    // TUN Center Frequency-0%; 
    OSCTUN = 0x00;
    // ROON disabled; ROSEL disabled; RODIV Base clock value; ROSSLP disabled; 
    REFOCON = 0x00;
    // PLLDIV 0; 
    PLLFBD = 0x00;
    // AD1MD enabled; PWMMD enabled; T3MD enabled; T4MD enabled; T1MD enabled; U2MD enabled; T2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; C1MD enabled; T5MD enabled; I2C1MD enabled; 
    PMD1 = 0x00;
    // IC4MD enabled; IC3MD enabled; OC1MD enabled; IC2MD enabled; OC2MD enabled; IC1MD enabled; OC3MD enabled; OC4MD enabled; 
    PMD2 = 0x00;
    // CMPMD enabled; 
    PMD3 = 0x00;
    // CTMUMD enabled; REFOMD enabled; 
    PMD4 = 0x00;
    // PWM2MD enabled; PWM1MD enabled; PWM3MD enabled; 
    PMD6 = 0x00;
    // DMA0MD enabled; 
    PMD7 = 0x00;
    // DMTMD enabled; SENT2MD enabled; SENT1MD enabled; 
    PMD8 = 0x00;
    // CF no clock failure; NOSC FRC; CLKLOCK unlocked; OSWEN Switch is Complete; 
    __builtin_write_OSCCONH((uint8_t) (0x00));
    __builtin_write_OSCCONL((uint8_t) ((0x100 | _OSCCON_OSWEN_MASK) & 0xFF));
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
}


void CLOCK_Initialize_POSC_25MHz(void) {
    // FRCDIV FRC/2; PLLPRE 2; DOZE 1:1; PLLPOST 1:2; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x100;
    // TUN Center frequency; 
    OSCTUN = 0x00;
    // ROON disabled; ROSEL disabled; RODIV Base clock value; ROSSLP disabled; 
    REFOCON = 0x00;
    // PLLDIV 50; 
    PLLFBD = 0x32;
    // AD1MD enabled; PWMMD enabled; T3MD enabled; T4MD enabled; T1MD enabled; U2MD enabled; T2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; C1MD enabled; T5MD enabled; I2C1MD enabled; 
    PMD1 = 0x00;
    // IC4MD enabled; IC3MD enabled; OC1MD enabled; IC2MD enabled; OC2MD enabled; IC1MD enabled; OC3MD enabled; OC4MD enabled; 
    PMD2 = 0x00;
    // CMPMD enabled; 
    PMD3 = 0x00;
    // CTMUMD enabled; REFOMD enabled; 
    PMD4 = 0x00;
    // PWM2MD enabled; PWM1MD enabled; PWM3MD enabled; 
    PMD6 = 0x00;
    // DMA0MD enabled; 
    PMD7 = 0x00;
    // DMTMD enabled; SENT2MD enabled; SENT1MD enabled; 
    PMD8 = 0x00;
    // CF no clock failure; NOSC PRI; CLKLOCK unlocked; OSWEN Switch is Complete; 
    __builtin_write_OSCCONH((uint8_t) (2));
    __builtin_write_OSCCONL((uint8_t) (1));
    
    while (OSCCONbits.OSWEN != 0);        // wait for switch to complete
    while (OSCCONbits.COSC != 2);         // make sure CS is PRI w/o PLL
}


uint16_t CLOCK_PeriodnsGet(void) {
    return ceil(1 / (CLOCK_InstructionFrequencyGet() * 0.000000001));
}


uint16_t ADC1CLOCK_GENMultiplier(void) {
    uint16_t T_instruction_ns = CLOCK_PeriodnsGet();
    if (T_instruction_ns < TAD_MIN_US) {
        TAD_multiplier = ceil(TAD_MIN_US / T_instruction_ns);
    }
    else {
        TAD_multiplier = 0;
    }
    
    TAD_ns = T_instruction_ns * (1 + TAD_multiplier);
    
    return TAD_multiplier;
}


uint16_t ADC1CLOCK_PeriodnsGet(void) {
    return TAD_ns;
}

uint16_t ADC1CLOCK_MultiplierGet(void) {
    return TAD_multiplier;
}

void ADC1CLOCK_PeriodnsSet(uint16_t period_ns) {
    TAD_ns = period_ns;
}

void ADC1CLOCK_MultiplierSet(uint16_t multiplier) {
    TAD_multiplier = multiplier;
}