/* 
 * File:   can.h
 * Author: 904pa
 *
 * Created on August 22, 2019, 10:56 AM
 */

#ifndef CAN_H
#define	CAN_H

#include <xc.h>
#include <stdint.h>

typedef enum opmode{OP_Normal = 0, OP_Disable = 1, OP_Loopback = 2, OP_ListenOnly = 3, OP_Config = 4, OP_Listen = 7};


/*
 * Initializes the CAN module
 */
void CAN_Initialize(void);

#endif	/* CAN_H */

