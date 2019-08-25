/* 
 * File:   globals.h
 * Author: Paul
 *
 * Created on August 16, 2019, 3:17 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#include "can.h"

#define CAN_MSG_SIZE        8        // num words per can message
#define NUM_CANTX_MSGS      1       // num messages for can tx buffer
#define NUM_CANRX_MSGS      8       // num messages for can rx buffer

extern can_msg_t canTXBuffer[NUM_CANTX_MSGS] __attribute__((aligned));
extern can_msg_t canRXBuffer[NUM_CANRX_MSGS] __attribute__((aligned));


#endif	/* GLOBALS_H */
