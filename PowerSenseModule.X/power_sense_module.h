/* 
 * File:   powersensemodule.h
 * Author: Paul
 *
 * Created on January 10, 2020, 11:18 PM
 */

#ifndef POWERSENSEMODULE_H
#define	POWERSENSEMODULE_H

#include <stdint.h>

#define R_V_DIV_1           1000000.0           // 1MOhm
#define R_V_DIV_2           499000.0            // 499kOhm
#define R_DIFF_1            1200.0              // 1.2kOhm
#define R_DIFF_2            75000.0             // 75kOhm
#define R_S                 0.004               // 4mOhm

double PSM_ProcessCurrent(uint16_t data);

double PSM_ProcessVoltage(uint16_t data);

#endif	/* POWERSENSEMODULE_H */

