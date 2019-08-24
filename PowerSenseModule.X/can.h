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

enum opmode{OP_Normal = 0, OP_Disable = 1, OP_Loopback = 2, OP_ListenOnly = 3, OP_Config = 4, OP_Listen = 7};

//typedef struct can_msg_word0_struct {
//    uint16_t IDE:1;         // extended identifier bit; 1: use extended frames, 0: use standard frame
//    uint16_t SRR:1;         // substitute remote request; if IDE = 0 - 1: remote frame, 0: normal frame, if IDE = 1, SRR = 1
//    uint16_t SID:11;        // standard identifier bits 
//    uint16_t :3;            // unimplemented
//} can_msg_word0_t;
//
//typedef struct can_msg_word1_struct {
//    uint16_t EIDH:12;       // extended identifier high
//    uint16_t :4;            // unimplemented
//} can_msg_word1_t;
//
//typedef struct can_msg_word2_struct {
//    uint16_t DLC:4;         // data length code bits
//    uint16_t RB0:1;         // CAN protocol reserved bit - MUST BE SET TO 0
//    uint16_t :3;            // unimplemented
//    uint16_t RB1:1;         // CAN protocol reserved bit - MUST BE SET TO 0
//    uint16_t RTR:1;         // remote transfer request; if IDE = 0 - 1: remote frame, 0: normal frame, if IDE = 1, SRR = 1
//                            // same as SRR but for extended data frames to work with message priority
//    uint16_t EIDL:6;        // extended identifier low
//} can_msg_word2_t;
//
//typedef struct msg_word3_struct {
//    uint8_t byte0; 
//    uint8_t byte1; 
//} can_msg_word3_t;
//
//typedef struct msg_word4_struct {
//    uint8_t byte2;
//    uint8_t byte3; 
//} can_msg_word4_t;
//
//typedef struct msg_word5_struct {
//    uint8_t byte4; 
//    uint8_t byte5; 
//} can_msg_word5_t;
//
//typedef struct msg_word6_struct {
//    uint8_t byte6; 
//    uint8_t byte7; 
//} can_msg_word6_t;
//
//typedef struct can_msg_word7_struct {  // receive only
//    uint16_t :8;            // unimplemented
//    uint16_t FILHIT:5;      // filter hit code - indicates which filter message was received through
//    uint16_t :3;            // unimplemented
//} can_msg_word7_t;



//typedef struct can_msg_struct {
//    can_msg_word0_t word0;
//    can_msg_word1_t word1;
//    can_msg_word2_t word2;
//    can_msg_word3_t word3_data0;
//    can_msg_word4_t word4_data1;
//    can_msg_word5_t word5_data2;
//    can_msg_word6_t word6_data3;
//    can_msg_word7_t word7;
//}can_msg_t;

typedef struct can_msg_struct {
    //order of word, then LSB to MSB
    //word 0
    uint16_t IDE:1;         // extended identifier bit; 1: use extended frames, 0: use standard frame
    uint16_t SRR:1;         // substitute remote request; if IDE = 0 - 1: remote frame, 0: normal frame, if IDE = 1, SRR = 1
    uint16_t SID:11;        // standard identifier bits
    uint16_t :3;            // unimplemented
    
    //word 1
    uint16_t EIDH:12;       // extended identifier high
    uint16_t :4;            // unimplemented
    
    //word 2
    uint16_t DLC:4;         // data length code bits
    uint16_t RB0:1;         // CAN protocol reserved bit - MUST BE SET TO 0
    uint16_t :3;            // unimplemented
    uint16_t RB1:1;         // CAN protocol reserved bit - MUST BE SET TO 0
    uint16_t RTR:1;         // remote transfer request; if IDE = 0 - 1: remote frame, 0: normal frame, if IDE = 1, SRR = 1
                            // same as SRR but for extended data frames to work with message priority
    uint16_t EIDL:6;        // extended identifier low
    
    //word 3
    uint8_t data_byte0;
    uint8_t data_byte1;
    
    //word 4
    uint8_t data_byte2;
    uint8_t data_byte3;
    
    //word 5
    uint8_t data_byte4;
    uint8_t data_byte5;
    
    //word 6
    uint8_t data_byte6;
    uint8_t data_byte7;
    
    //word 7
    uint16_t :3;            // unimplemented
    uint16_t FILHIT:5;      // filter hit code - indicates which filter message was received through
    uint16_t :8;            // unimplemented
}can_msg_t;


/*
 * Initializes the CAN module
 */
void CAN_Initialize(void);

/**
 * Transmit standard data frame over bus
 * 
 * @param buffer: TX buffer to transmit
 * @param sid: standard identifier - device address to send to 
 * @param num_bytes: number of bytes to transmit
 * 
 * @return 1 if error, 0 if successful
 */
uint16_t CAN_TransmitData(uint16_t buf_num, uint16_t sid, uint16_t num_bytes);

/**
 * Writes data of any type to a specified CAN TX buffer
 * Least significant byte has even address, most significant byte has odd address
 * 
 * Note: multi-word data will be written out of order - LS word in word n to MS word in word n+m
 *         | word n | word n+m (multi-word length, m)
 *         |--------|-----------------------------------
 *     data|   MS   |  LS
 *  buffer |   LS   |  MS
 * 
 * @param data: data pointer of what to write to the CAN TX buffer
 * @param buffer: buffer to write to
 * @param num_bytes: number of bytes of data
 * 
 * @return 1 if error, 0 if successful
 */
uint16_t CAN_WriteBuf(void* data, uint16_t buf_num, uint16_t num_bytes, uint16_t starting_byte);

void CAN_ConfigBufForStandardDataFrame(uint16_t buf_num);

#endif	/* CAN_H */

