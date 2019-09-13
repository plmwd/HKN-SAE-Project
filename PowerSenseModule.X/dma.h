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


typedef enum {
    DMA_CHANNEL_0 =  0,       
    DMA_CHANNEL_1 =  1,       
    DMA_CHANNEL_2 =  2,       
    DMA_CHANNEL_3 =  3,       
    DMA_NUMBER_OF_CHANNELS = 4
} DMA_CHANNEL;

/**
 * Channel allocations
 */
#define DMA_CANTX_CHANNEL    DMA_CHANNEL_0
#define DMA_CANRX_CHANNEL    DMA_CHANNEL_1
#define DMA_UARTTX_CHANNEL   DMA_CHANNEL_2
#define DMA_UARTRX_CHANNEL   DMA_CHANNEL_3

typedef struct __attribute__((packed)) DMAINIT_struct {
// DMAxCON
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
    
//DMAxPAD
    uint16_t PAD;       // peripheral address
    
//DMAxCNT
    uint16_t CNT:14;    // transfer count - 1
    
    
} DMAINIT;


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
 * @param addr          buffer address 
 * @return              0 if successful, 1 if failure
 */
uint16_t DMA_InitializeChannel(DMA_CHANNEL ch, DMAINIT init_data, void* addr);

/**
 @Summary
  Enables the channel in the DMA

 @Description
  This routine is used to enable a channel in the DMA. This routine
  sets the value of the CHEN bit to 1.
 
 @Preconditions
  DMA_Initializer() function should have been 
  called before calling this function.
 
 @Returns
  None

 @Param
  None
  
 */
inline static void DMA_ChannelEnable(DMA_CHANNEL  channel)
{
    switch(channel) {
        case DMA_CHANNEL_0:
                DMA0CONbits.CHEN = 1;
                break;     
        case DMA_CHANNEL_1:
                DMA1CONbits.CHEN = 1;
                break;     
        case DMA_CHANNEL_2:
                DMA2CONbits.CHEN = 1;
                break;     
        case DMA_CHANNEL_3:
                DMA3CONbits.CHEN = 1;
                break;     
        default: break;
    }
}
    
/**
 @Summary
 Disables the channel in the DMA

 @Description
  This routine is used to disable a channel in the DMA. This routine
  sets the value of the CHEN bit to 0.
 
@Preconditions
 DMA_Initializer() function should have been 
 called before calling this function.
 
@Returns
 None

@Param
 None
  
*/
inline static void DMA_ChannelDisable(DMA_CHANNEL  channel)
{
    switch(channel) {
        case DMA_CHANNEL_0:
                DMA0CONbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_1:
                DMA1CONbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_2:
                DMA2CONbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_3:
                DMA3CONbits.CHEN = 0;
                break;    
        default: break;
    }
}

/**
 * Terminates channel - deactivates it and removes association to peripheral.
 * 
 * @param ch            channel to be initialized
 * @return              0 if successful, 1 if failure
 */
uint16_t DMA_TerminateChannel(DMA_CHANNEL ch);

#endif	/* DMA_H */

