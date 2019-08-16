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

typedef struct DMAxINIT_struct {
// DMAxCON
    uint8_t CHEN:1;
    uint8_t SIZE:1;
    uint8_t DIR:1;
    uint8_t HALF:1;
    uint8_t NULLW:1;
    uint8_t AMODE:2;
    uint8_t MODE:2;
    
//DMAxRREQ
    uint8_t IRQSEL:8;
    
//DMAxSTAH
    uint8_t STAH:8;
    
//DMAxSTAL
    uint16_t STAL;
    
//DMAxSTBH
    uint8_t STBH:8;
    
//DMAxSTBL
    uint16_t STBL;
    
//DMAxPAD
    uint16_t PAD;
    
//DMAxCNT
    uint16_t CNT:14;
    
} DMAxINIT;

/*
 * USE THESE FOR ACCESSING DMA CHANNEL SFR
 */
//#define DMA_CONBITS(ch)     ( (*(DMA_CHList[ch].CONbits)) )
//#define DMA_REQBITS(ch)     ( (*(DMA_CHList[ch].REQbits)) )
//#define DMA_STAH(ch)        ( (*(DMA_CHList[ch].STAH)).STA )
//#define DMA_STAL(ch)           *(DMA_CHList[ch].STAL)
//#define DMA_STBH(ch)        ( (*(DMA_CHList[ch].STBH)).STB )
//#define DMA_STBL(ch)           *(DMA_CHList[ch].STBL) 
//#define DMA_PAD(ch)            *(DMA_CHList[ch].PAD)
//#define DMA_CNT(ch)         ( (*(DMA_CHList[ch].CNT)).CNT )


/**
 * Channel allocations
 */
#define DMA_ADC_CH      0
#define DMA_CANTX_CH    1
#define DMA_CANRX_CH    2
#define DMA_UARTTX_CH   1       // UART and CAN must be reinitialized 
#define DMA_UARTRX_CH   2



/**
 * Main initialization function
 */
void DMA_Initialize(void);

/**
 * Initializes the specified DMA channel with initialization data. 
 * Also will block reinitialization if channel is initialized and active.
 * Must terminate channel before reinitialization.
 * @param ch            channel to be initialized
 * @param init_data     initialization data
 * @return              0 if successful, 1 if failure
 */
uint16_t DMA_InitializeCH(uint16_t ch, DMAxINIT init_data);

/**
 * Terminates channel - deactivates it.
 * @param ch            channel to be initialized
 * @return              0 if successful, 1 if failure
 */
uint16_t DMA_TerminateCH(uint16_t ch);

#endif	/* DMA_H */

