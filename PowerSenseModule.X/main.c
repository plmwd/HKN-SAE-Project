/**
  @Description
    This source file provides main entry point for system intialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.95-b-SNAPSHOT
        Device            :  dsPIC33EP32GP502
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36
        MPLAB 	          :  MPLAB X v5.10
*/

// Header files
#include "mcc_generated_files/system.h"


// Functions

// float pingCurrent(void)
// The following function will ping the current sensor and return
// the instantaneous measurement from the device. The function will
// return the raw value or an error code
float pingCurrent (void)
{
    return 0.0;
}

// float pingVoltage (void)
// The following function will ping the voltage sensor and
// return the instantaneous measurement from the device.
// The function will return the raw value or an error code.
float pingVoltage (void)
{
    return 0.0;
}
// Main
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    while (1)
    {
        // Add your application code
    }
    return 1; 
}
