#include "power_sense_module.h"
#include "device_parameters.h"


double PSM_ProcessCurrent(uint16_t data) {
    double adcVoltage, fOneBatteryCurrent = 0;
    
    // Converting to actual voltage
    adcVoltage = 5.0 * (data / 1023.0);
    
    // Getting current going through battery
    fOneBatteryCurrent =  R_DIFF_1 / (R_DIFF_2 * R_S) * adcVoltage;
    
    return fOneBatteryCurrent;
}


double PSM_ProcessVoltage(uint16_t data) {
    double adcVoltage, fOneBatteryVoltage = 0;
    
    // Converting to actual voltage
    adcVoltage = 5.0 * (data / 1023.0);
    
    // Getting voltage of actual battery using circuit analysis
    fOneBatteryVoltage = adcVoltage * ( (R_V_DIV_1 + R_V_DIV_2) / R_V_DIV_2);
    
    return fOneBatteryVoltage;
}