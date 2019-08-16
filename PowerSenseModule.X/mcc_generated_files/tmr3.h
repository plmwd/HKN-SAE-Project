/**
  TMR3 Generated Driver API Header File 

  @Company
    Microchip Technology Inc.

  @File Name
    tmr3.h

  @Summary
    This is the generated header file for the TMR3 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for TMR3. 
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

#ifndef _TMR3_H
#define _TMR3_H

/**
  Section: Included Files
*/

#include "xc.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif


#define TMR3_Start()                    T3CONbits.TON = 1
#define TMR3_Stop()                     T3CONbits.TON = 0
#define TMR3_ClearInterruptFlag()       IFS0bits.T3IF = 0
#define TMR3_InterruptEnable()          IEC0bits.T3IE = 1
#define TMR3_InterruptDisable()         IEC0bits.T3IE = 0
        
        
/**
  Section: Interface Routines
*/

/**
  @Summary
    Initializes hardware and data for the given instance of the TMR module

  @Description
    This routine initializes hardware for the instance of the TMR module,
    using the hardware initialization given data.  It also initializes all
    necessary internal data.

  @Param
    None.

  @Returns
    None
 
*/
void TMR3_Initialize (void);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //_TMR3_H
    
/**
 End of File
*/
