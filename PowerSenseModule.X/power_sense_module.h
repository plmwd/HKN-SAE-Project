/* 
 * File:   powersensemodule.h
 * Author: Paul
 *
 * Created on January 10, 2020, 11:18 PM
 */

#ifndef POWERSENSEMODULE_H
#define	POWERSENSEMODULE_H

#include <stdint.h>

double PSM_ProcessCurrent(uint16_t data);

double PSM_ProcessVoltage(uint16_t data);

#endif	/* POWERSENSEMODULE_H */

