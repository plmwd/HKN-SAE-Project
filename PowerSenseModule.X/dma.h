/* 
 * File:   dma.h
 * Author: Paul
 *
 * Created on August 15, 2019, 3:40 PM
 */

#ifndef DMA_H
#define	DMA_H

#include "xc.h"
#include <stdint.h>

#define NUM_DMA_CH      4

/**
 * Channel allocations
 */
#define DMA_CANTX_CH    0
#define DMA_CANRX_CH    1
#define DMA_UARTTX_CH   2       // UART and CAN must be reinitialized 
#define DMA_UARTRX_CH   3s


typedef struct DMAxINIT_struct {
// DMAxCON
    uint8_t CHEN:1;     // 0: channel disabled, 1: channel enabled
    uint8_t SIZE:1;     // transfer size - 0: word, 1: byte
    uint8_t DIR:1;      // transfer direction - 0: peripheral -> RAM, 1: RAM -> peripheral
    uint8_t HALF:1;     // generate interrupt when... 0: all data, 1: half data
    uint8_t NULLW:1;    // 0: normal operation, 1: null data write (DIR = 0)
    uint8_t AMODE:2;    // DMA channel addr mode - 0: indirect w post increment, 
                        // 1: indirect wo post increment, 2: indirect (peripheral addresses)
    uint8_t MODE:2;     // DMA operating mode - 0: continuous, ping-pong disabled
                        // 1: one-shot, ping-pong disabled, 2: continuous, ping-pong enabled 
                        // 3: one-shot, ping-pong enabled
    
//DMAxRREQ
    uint8_t IRQSEL:8;   // peripheral IRQ number
    
//DMAxSTAH
    uint8_t STAH:8;     // primary start address high
    
//DMAxSTAL
    uint16_t STAL;      // primary start address low
    
//DMAxSTBH
    uint8_t STBH:8;     // secondary start address high
    
//DMAxSTBL
    uint16_t STBL;      // secondary start address low
    
//DMAxPAD
    uint16_t PAD;       // peripheral address
    
//DMAxCNT
    uint16_t CNT:14;    // transfer count - 1
    
} DMAxINIT;


/**
 * Main initialization function
 */
void DMA_Initialize(void);

/**
 * Initializes the specified DMA channel with initialization data. 
 * Also will block reinitialization if channel is initialized and active.
 * Must terminate channel before reinitialization.
 * A channel is marked as active through "active_chs" array.
 * Buffer address must be passed through initialization function.
 * 
 * @param ch            channel to be initialized
 * @param init_data     initialization data
 * @param stah          buffer start address high
 * @param stal          buffer start address low
 * @return              0 if successful, 1 if failure
 */
uint16_t DMA_InitializeCH(uint16_t ch, DMAxINIT init_data, void* stah, void* stal);

/**
 * Terminates channel - deactivates it and removes association to peripheral.
 * 
 * @param ch            channel to be initialized
 * @return              0 if successful, 1 if failure
 */
uint16_t DMA_TerminateCH(uint16_t ch);

#endif	/* DMA_H */

