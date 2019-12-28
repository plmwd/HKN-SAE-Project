/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
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
    Section: Includes
*/

#include "xc.h"
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Configure General Peripheral Inputs
     ***************************************************************************/
    //DCME (Debug/calibrate mode enable) - RA0 - digital input - pull down
    TRISAbits.TRISA0 = 1;    
    CNPDAbits.CNPDA0 = 1;
    CNPUAbits.CNPUA0 = 0;
    ANSELAbits.ANSA0 = 0;
    
    //HIGH_IE (High current mode enable) - RA1 - digital input
    TRISAbits.TRISA1 = 1;
    CNPDAbits.CNPDA1 = 0;
    CNPUAbits.CNPUA1 = 0;
    ANSELAbits.ANSA1 = 0;
    
    //IIN (ADC current measurement) - RB0 - analog input
    TRISBbits.TRISB0 = 1;
    CNPDBbits.CNPDB0 = 0;
    CNPUBbits.CNPUB0 = 0;
    ANSELBbits.ANSB0 = 1;
    
    //VIN (ADC voltage measurement) - RB1 - analog input
    TRISBbits.TRISB1 = 1;
    CNPDBbits.CNPDB1 = 0;
    CNPUBbits.CNPUB1 = 0;
    ANSELBbits.ANSB1 = 1;
    
    
    /****************************************************************************
     * Configure General Peripheral Outputs
     ***************************************************************************/
    //LED_R (Red LED) - RB14 - digital output - pull down
    TRISBbits.TRISB14 = 0;
    CNPDBbits.CNPDB14 = 1;
    CNPUBbits.CNPUB14 = 0;
    
    //LED_G (Green LED) - RB15 - digital output - pull down
    TRISBbits.TRISB15 = 0;
    CNPDBbits.CNPDB15 = 1;
    CNPUBbits.CNPUB15 = 0;
    
    //CAN_STBY (CAN standby) - RB13 - digital output 
    TRISBbits.TRISB13 = 0;
    CNPDBbits.CNPDB13 = 0;
    CNPUBbits.CNPUB13 = 0;
    
    //CAN_TX (CAN transmit) - RB11
//    TRISBbits.TRISB11 = 0;
    CNPDBbits.CNPDB11 = 0;
    CNPUBbits.CNPUB11 = 0;
    
    //CAN_RX (CAN receive) - RB12
//    TRISBbits.TRISB12 = 0;
    CNPDBbits.CNPDB12 = 0;
    CNPUBbits.CNPUB12 = 0;
    
    //debug
    TRISAbits.TRISA4 = 0;
    ANSELAbits.ANSA4 = 0;
    
    /****************************************************************************
     * Configure Configurable Peripheral Outputs
     ***************************************************************************/
//    CAN_TX_SetHigh();       //RB11
//    CAN_TX_SetLow();
//    CAN_TX_SetHigh();
//    CAN_TX_SetLow();
    
    //debug
    _LATA4 = 1;
    _LATA4 = 0;
    _LATA4 = 1;
    _LATA4 = 0;
    
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPINR26bits.C1RXR = 0x002C;    //RB12->ECAN1:C1RX
    RPOR4bits.RP43R = 0x000E;    //RB11->ECAN1:C1TX

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
    
//    CAN_TX_SetHigh();
//    CAN_TX_SetLow();
//    CAN_TX_SetHigh();
//    CAN_TX_SetLow();
    
    //debug
    _LATA4 = 1;
    _LATA4 = 0;
    _LATA4 = 1;
    _LATA4 = 0;
    
    //__builtin_write_OSCCONL(OSCCON | (1<<6));       // Lock Registers

}


