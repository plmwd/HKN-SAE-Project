#include "dma.h"
#include <stdbool.h>
//#include <string.h>



#define inactive    false
#define active      true
typedef bool activity;
activity active_chs[NUM_DMA_CH] = { inactive };


dma_status_t DMA_InitializeChannel(uint8_t ch, dma_channel_settings_t ch_settings, uint16_t *buffer_addr) {
    if ((ch >= NUM_DMA_CH) || (ch < 0))
        return DMA_INVALID_CH;
    
    if (active_chs[ch] == active)
        return DMA_CH_ALREADY_ACTIVE;
    else 
        active_chs[ch] = active;
    
    switch (ch)
    {
        case 0:
            DMA0CONbits.SIZE = ch_settings.SIZE;
            DMA0CONbits.DIR = ch_settings.DIR;
            DMA0CONbits.HALF = ch_settings.HALF;
            DMA0CONbits.NULLW = ch_settings.NULLW;
            DMA0CONbits.AMODE = ch_settings.AMODE;
            DMA0CONbits.MODE = ch_settings.MODE;
            DMA0REQbits.IRQSEL = ch_settings.IRQSEL;
            DMA0STAHbits.STA = 0;
            DMA0STAL = (uint16_t)buffer_addr;
            DMA0STBHbits.STB = 0;
            DMA0STBL = 0;
            DMA0PAD = (uint16_t)ch_settings.PAD;
            DMA0CNTbits.CNT = ch_settings.CNT;
            DMA0CONbits.CHEN = 1;
            break;
        case 1:
            DMA1CONbits.SIZE = ch_settings.SIZE;
            DMA1CONbits.DIR = ch_settings.DIR;
            DMA1CONbits.HALF = ch_settings.HALF;
            DMA1CONbits.NULLW = ch_settings.NULLW;
            DMA1CONbits.AMODE = ch_settings.AMODE;
            DMA1CONbits.MODE = ch_settings.MODE;
            DMA1REQbits.IRQSEL = ch_settings.IRQSEL;
            DMA1STAHbits.STA = 0;
            DMA1STAL = (uint16_t)buffer_addr;
            DMA1STBHbits.STB = 0;
            DMA1STBL = 0;
            DMA1PAD = (uint16_t)ch_settings.PAD;
            DMA1CNTbits.CNT = ch_settings.CNT;
            DMA1CONbits.CHEN = 1;
            break;
        case 2:
            DMA2CONbits.SIZE = ch_settings.SIZE;
            DMA2CONbits.DIR = ch_settings.DIR;
            DMA2CONbits.HALF = ch_settings.HALF;
            DMA2CONbits.NULLW = ch_settings.NULLW;
            DMA2CONbits.AMODE = ch_settings.AMODE;
            DMA2CONbits.MODE = ch_settings.MODE;
            DMA2REQbits.IRQSEL = ch_settings.IRQSEL;
            DMA2STAHbits.STA = 0;
            DMA2STAL = (uint16_t)buffer_addr;
            DMA2STBHbits.STB = 0;
            DMA2STBL = 0;
            DMA2PAD = (uint16_t)ch_settings.PAD;
            DMA2CNTbits.CNT = ch_settings.CNT;
            DMA2CONbits.CHEN = 1;
            break;
        case 3:
            DMA3CONbits.SIZE = ch_settings.SIZE;
            DMA3CONbits.DIR = ch_settings.DIR;
            DMA3CONbits.HALF = ch_settings.HALF;
            DMA3CONbits.NULLW = ch_settings.NULLW;
            DMA3CONbits.AMODE = ch_settings.AMODE;
            DMA3CONbits.MODE = ch_settings.MODE;
            DMA3REQbits.IRQSEL = ch_settings.IRQSEL;
            DMA3STAHbits.STA = 0;
            DMA3STAL = (uint16_t)buffer_addr;
            DMA3STBHbits.STB = 0;
            DMA3STBL = 0;
            DMA3PAD = (uint16_t)ch_settings.PAD;
            DMA3CNTbits.CNT = ch_settings.CNT;
            DMA3CONbits.CHEN = 1;
            break;
        default:
            return DMA_ERROR;
    }
    
    return DMA_GOOD;
}

uint16_t DMA_TerminateChannel(uint8_t ch) {
    
    switch (ch)
    {
        case 0:
            DMA0CONbits.CHEN = 0;
            DMA0REQbits.IRQSEL = 0;
            DMA0PAD = 0;
            break;
        case 1:
            DMA1CONbits.CHEN = 0;
            DMA1REQbits.IRQSEL = 0;
            DMA1PAD = 0;
            break;
        case 2:
            DMA2CONbits.CHEN = 0;
            DMA2REQbits.IRQSEL = 0;
            DMA2PAD = 0;
            break;
        case 3:
            DMA3CONbits.CHEN = 0;
            DMA3REQbits.IRQSEL = 0;
            DMA3PAD = 0;
            break;
        default:
            return DMA_ERROR;
            
    }
    
    active_chs[ch] = inactive;
        
    return DMA_GOOD;
}
