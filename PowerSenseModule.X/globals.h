/* 
 * File:   globals.h
 * Author: Paul
 *
 * Created on August 16, 2019, 3:17 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#include "can.h"

//#define DEBUG 

//Number of TX+RX message buffers must equal a total of 4, 6, 8, 12, 16, 24, or 32
//Set C1FCTRLbits.DMABS accordingly - in order -        0, 1, 2, 3,   4,  5,     6
#define CAN_MSG_SIZE        8        // num words per can message
#define NUM_CANTX_MSGS      1       // num messages for can tx buffer - MUST be 1 for now
#define NUM_CANRX_MSGS      7       // num messages for can rx buffer


extern can_msg_t* canTXBuffer;
extern can_msg_t* canRXBuffer;
//extern can_msg_t canTXBuffer[NUM_CANTX_MSGS] __attribute__((aligned));
//extern can_msg_t canRXBuffer[NUM_CANRX_MSGS] __attribute__((aligned));



#endif	/* GLOBALS_H */
