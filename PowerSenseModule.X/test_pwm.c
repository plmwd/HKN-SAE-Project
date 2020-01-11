#include "device_configuration.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#include <libpic30.h>
#include <stdio.h>
#include "mcc_generated_files/pwm.h"

#ifdef DEBUG_PWM

void main(void) {
    SYSTEM_Initialize();
    PWM_ModuleEnable();
    
    _TRISB15 = 0;
    
    while(1) {
        _LATB15 = 1;
        __delay_ms(500);
        _LATB15 = 0;
        __delay_ms(500);
    }
}

#endif
