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


//typedef struct DMAxREGS_struct {
//    char name[NAME_LENGTH];
//    volatile DMA0CONBITS*   CONbits;
//    volatile DMA0REQBITS*   REQbits;
//    volatile DMA0STAHBITS*  STAH;
//    volatile uint16_t*      STAL;
//    volatile DMA0STBHBITS*  STBH;
//    volatile uint16_t*      STBL;
//    volatile uint16_t*      PAD;
//    volatile DMA0CNTBITS    CNT;
//} DMAxREGS;

typedef struct {
// DMAxCON: general DMA channel control settings
    uint8_t SIZE:1;
    uint8_t DIR:1;
    uint8_t HALF:1;
    uint8_t NULLW:1;
    uint8_t AMODE:2;
    uint8_t MODE:2;
    
//DMAxRREQ: peripheral interrupt routine service ID (IRQ)
    uint8_t IRQSEL:8;
    
//DMAxPAD: peripheral data address
    uint16_t PAD;
    
//DMAxCNT: number of transfers per data block 
    uint16_t CNT:14;
    
} dma_channel_settings_t;


/**
 * Channel allocations
 */
//#define DMA_ADC_CH      0
#define DMA_CANTX_CH    0
#define DMA_CANRX_CH    1

typedef enum {DMA_GOOD, DMA_ERROR, DMA_CH_ALREADY_ACTIVE, DMA_INVALID_CH} dma_status_t;


/**
 * Initializes the specified DMA channel with initialization data. 
 * Also will block reinitialization if channel is initialized and active.
 * Must terminate channel before reinitialization.
 * @param ch            channel to be initialized
 * @param init_data     initialization data
 * @return              0 if successful, 1 if failure
 */
dma_status_t DMA_InitializeChannel(uint8_t ch, dma_channel_settings_t ch_settings, uint16_t *buffer_addr);

/**
 * Terminates channel - deactivates it.
 * @param ch            channel to be initialized
 * @return              0 if successful, 1 if failure
 */
dma_status_t DMA_TerminateChannel(uint8_t ch);

#endif	/* DMA_H */

