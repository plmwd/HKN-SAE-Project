/**
  @Generated PIC24 / dsPIC33 / PIC32MM MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    system.h

  @Summary:
    This is the sysetm.h file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.125
        Device            :  dsPIC33EV32GM102
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB             :  MPLAB X v5.20
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

#include "pin_manager.h"
#include "clock.h"
#include "system.h"
#include "system_types.h"
#include "interrupt_manager.h"
#include "adc1.h"
#include "tmr1.h"
#include "tmr3.h"
#include "../dma.h"
#include "../can.h"
#include "../device_configuration.h"


void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    CAN_STBY_SetHigh();     // put the CAN transceiver in low power mode until all inits are done
    
#if defined FRC_NORMAL
    CLOCK_Initialize_FRC_NORMAL();

#elif defined FRC_SLOWEST
    CLOCK_Initialize_FRC_SLOWEST();
    
#elif defined FRC_40MHz
    CLOCK_Initialize_FRC_40MHz();
    
#elif defined POSC_24MHz
    CLOCK_Initialize_POSC_24MHz();
#endif
    
#ifdef ADC1_ENABLE
    ADC1_Initialize();
    // delay TMR init 20us for ADC to stabilize
    int i;
    for (i = 0; i < 20000/CLOCK_PeriodnsGet(); i++) {}  
#endif    

#ifdef TMR1_ENABLE
    TMR1_Initialize();
#endif
    
#ifdef TMR3_ENABLE
    TMR3_Initialize();
    
#endif
    
#ifdef CAN1_ENABLE
    CAN_Initialize(CAN_NORMAL_OPERATION_MODE);
#endif
    
    DMA_Initialize();
    
#ifdef CAN1_ENABLE
    CAN_STBY_SetLow();  // bring the CAN transceiver to wakeup mode
#endif
    
    SYSTEM_CORCONModeOperatingSet(CORCON_MODE_PORVALUES);
    INTERRUPT_GlobalEnable();
    INTERRUPT_Initialize();
}

/**
 End of File
*/