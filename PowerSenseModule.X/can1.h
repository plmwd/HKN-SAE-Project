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
#include "device_configuration.h"
#include <stdbool.h>

#define DEBUG_SID 1234

typedef enum
{
	CAN_NORMAL_MODE = 0,
	CAN_DISABLE_MODE = 1,
	CAN_LOOPBACK_MODE = 2,
	CAN_LISTEN_ONLY_MODE = 3,
	CAN_CONFIGURATION_MODE = 4,
	CAN_LISTEN_ALL_MESSAGES_MODE = 7
} can_opmode_t;

typedef enum{
    CAN_PRIORITY_HIGH = 0b11,
    CAN_PRIORITY_MEDIUM = 0b10,
    CAN_PRIORITY_LOW = 0b01,
    CAN_PRIORITY_LOWEST = 0b00
} can_tx_priority_t;

typedef enum{
    CAN_TXBUF_0 = 0,
//    CAN_TXBUF_1 = 1,
//    CAN_TXBUF_2 = 2,
//    CAN_TXBUF_3 = 3,
//    CAN_TXBUF_4 = 4,
//    CAN_TXBUF_5 = 5,
//    CAN_TXBUF_6 = 6,
//    CAN_TXBUF_7 = 7,
} can_tx_buffer_t;

typedef enum{
    CAN_SUCCESS,                    // general success
    CAN_ERROR,                      // general error
    CAN_ERR_INVALID_TXBUF,          // inputted tx buffer number invalid - either not enabled or out of range of max TX buffers
    CAN_ERR_INVALID_SID,            // SID out of bounds - 11 bit number
    CAN_ERR_INVALID_DATA_SIZE,      // data frame number of data bytes invalid - max 8
    CAN_ERR_TXBUF_DISABLED,         // can't transmit frame if it isn't enabled for TX
    CAN_ERR_TXBUF_FULL,             // previous tx not sent
    CAN_ERR_MSG_ABORTED,            // tx message aborted
    CAN_ERR_MSG_LOST_ARBITRATION    // tx message overridden by bus device with higher priority
} can_error_t;

typedef struct __attribute__((packed))can_msg_struct{
    //order of word, then LSB to MSB
    //word 0
    uint16_t use_extended_id:1;         // extended identifier bit; 1: use extended frames, 0: use standard frame
    uint16_t use_remote_frame:1;        // substitute remote request; if IDE = 0 - 1: remote frame, 0: normal frame, if IDE = 1, SRR = 1
    uint16_t standard_id:11;            // standard identifier bits
    uint16_t :3;                        // unimplemented
    
    //word 1
    uint16_t extended_id_h:12;          // extended identifier high
    uint16_t :4;                        // unimplemented
    
    //word 2
    uint16_t data_num_bytes:4;          // data length code bits
    uint16_t RB0:1;                     // CAN protocol reserved bit - MUST BE SET TO 0
    uint16_t :3;                        // unimplemented
    uint16_t RB1:1;                     // CAN protocol reserved bit - MUST BE SET TO 0
    uint16_t remote_request:1;          // remote transfer request; if IDE = 0 - 1: remote frame, 0: normal frame, if IDE = 1, SRR = 1
                                        // same as SRR but for extended data frames to work with message priority
    uint16_t extended_id_l:6;           // extended identifier low
    
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
    uint16_t :3;                        // unimplemented
    uint16_t filter_hit_code:5;         // filter hit code - indicates which filter message was received through
    uint16_t :8;                        // unimplemented
}can_message_t;

inline static can_opmode_t CAN_OperationModeGet(void) {
    return (can_opmode_t)C1CTRL1bits.OPMODE;
}

inline static void CAN_OperationModeRequest(can_opmode_t op_mode) {
    C1CTRL1bits.REQOP = op_mode;
    
    while (CAN_OperationModeGet() != op_mode);
}


inline static void CAN_UseFilterSFRWindow() {
    C1CTRL1bits.WIN = 1;
}

inline static void CAN_UseBufferSFRWindow() {
    C1CTRL1bits.WIN = 0;
}



/*
 * Initializes the CAN module
 */
can_error_t CAN_Initialize();


/**
 * Transmit standard data frame over bus
 * 
 * @param buffer: TX buffer to transmit
 * @param sid: standard identifier - device address to send to 
 * @param num_bytes: number of bytes to transmit
 * 
 * @return 1 if error, 0 if successful
 */
can_error_t CAN_TransmitData(void *data, uint8_t num_bytes, uint16_t sid, can_tx_priority_t priority);

can_error_t CAN_StartTransmission();

void CAN_TXMessageSIDSet(uint16_t sid);

void CAN_TXMessagePrioritySet(can_tx_priority_t priority);

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
can_error_t CAN_WriteTXBuffer(void* data, uint8_t num_bytes, uint16_t starting_byte);


/**
 * CAN messages can take on different formats. This function configures the buffer to be a 
 * standard data message.
 * 
 * @param buf_num: TX buffer to setup for a standard data frame
 */
void CAN_ConfigBufForStandardDataFrame(uint16_t buf_num);

void CAN1BR_1MHz_Initialize(void);

void CAN1BR_125KHz_Initialize(void);

#endif	/* CAN_H */

