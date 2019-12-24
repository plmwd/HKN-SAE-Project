#include "dma.h"
#include "globals.h"

/**************************************************************************
 * 
 *                            INIT CONFIGS
 * 
 **************************************************************************/
DMAINIT DMA_CANRX_InitConfig =   {  .SIZE   = 0,    // word transfer
                                    .DIR    = 0,    // peripheral to RAM direction  
                                    .HALF   = 0,    // interrupt after all transfers
                                    .NULLW  = 0,    // normal operation 
                                    .AMODE  = 2,    // peripheral controls address 
                                    .MODE   = 0,    // continuous, ping-pong disabled
                                    .IRQSEL = 0x22,    
                                    .PAD    = 0x440,     
                                    .CNT    = CAN_MSG_SIZE - 1 
                                    };

DMAINIT DMA_CANTX_InitConfig =   {  .SIZE   = 0,    // word transfer
                                    .DIR    = 1,    // RAM to peripheral
                                    .HALF   = 0,    // interrupt after all transfers
                                    .NULLW  = 0,    // normal operation 
                                    .AMODE  = 2,    // peripheral controls address 
                                    .MODE   = 0,    // continuous, ping-pong disabled
                                    .IRQSEL = 0x46,             
                                    .PAD    = 0x442,    
                                    .CNT    = CAN_MSG_SIZE - 1
                                    };

DMAINIT DMA_UARTTX_InitConfig =  {  .SIZE   = 0,    // 
                                    .DIR    = 0,    // 
                                    .HALF   = 0,    // 
                                    .NULLW  = 0,    // 
                                    .AMODE  = 0,    // 
                                    .MODE   = 0,    // 
                                    .IRQSEL = 0,    //         
                                    .PAD    = 0,    //
                                    .CNT    = 0     //
                                    };

DMAINIT DMA_UARTRX_InitConfig =  {  .SIZE   = 0,    // 
                                    .DIR    = 0,    // 
                                    .HALF   = 0,    // 
                                    .NULLW  = 0,    // 
                                    .AMODE  = 0,    // 
                                    .MODE   = 0,    // 
                                    .IRQSEL = 0,    //         
                                    .PAD    = 0,    //
                                    .CNT    = 0     //
                                    };


/**************************************************************************
 * 
 *                              INIT
 * 
 **************************************************************************/
uint8_t active_chs[NUM_DMA_CH] = { 0 };

void DMA_Initialize() {
    DMA_InitializeChannel(DMA_CANRX_CHANNEL, DMA_CANRX_InitConfig, (void*)canRXBuffer);
    DMA_InitializeChannel(DMA_CANTX_CHANNEL, DMA_CANTX_InitConfig, (void*)canTXBuffer);
    //DMA_InitializeChannel(DMA_UARTTX_CHANNEL, DMA_UARTTX_InitConfig, (void*));
    //DMA_InitializeChannel(DMA_UARTRX_CHANNEL, DMA_UARTRX_InitConfig, (void*));
}


uint16_t DMA_InitializeChannel(DMA_CHANNEL ch, DMAINIT init_data, void* addr) {
    // check for invalid channel number
    if ((ch >= NUM_DMA_CH) || (ch < 0))
        return 1;
    
    // if channel is active, then return error, if not, then set active
    if (active_chs[ch] == 1)
        return 1;
    else 
        active_chs[ch] = 1;
    
    // channel enabling needs to be last
    switch (ch)
    {
        case DMA_CHANNEL_0:
            DMA0CONbits.SIZE = init_data.SIZE;
            DMA0CONbits.DIR = init_data.DIR;
            DMA0CONbits.HALF = init_data.HALF;
            DMA0CONbits.NULLW = init_data.NULLW;
            DMA0CONbits.AMODE = init_data.AMODE;
            DMA0CONbits.MODE = init_data.MODE;
            DMA0REQbits.IRQSEL = init_data.IRQSEL;
            DMA0STAL = (uint16_t)addr;
            DMA0PAD = init_data.PAD;
            DMA0CNTbits.CNT = init_data.CNT;
            IEC0bits.DMA0IE = 1;
            break;
        case DMA_CHANNEL_1:
            DMA1CONbits.SIZE = init_data.SIZE;
            DMA1CONbits.DIR = init_data.DIR;
            DMA1CONbits.HALF = init_data.HALF;
            DMA1CONbits.NULLW = init_data.NULLW;
            DMA1CONbits.AMODE = init_data.AMODE;
            DMA1CONbits.MODE = init_data.MODE;
            DMA1REQbits.IRQSEL = init_data.IRQSEL;
            DMA1STAL = (uint16_t)addr;
            DMA1PAD = init_data.PAD;
            DMA1CNTbits.CNT = init_data.CNT;
            IEC0bits.DMA1IE = 1;
            break;
        case DMA_CHANNEL_2:
            DMA2CONbits.SIZE = init_data.SIZE;
            DMA2CONbits.DIR = init_data.DIR;
            DMA2CONbits.HALF = init_data.HALF;
            DMA2CONbits.NULLW = init_data.NULLW;
            DMA2CONbits.AMODE = init_data.AMODE;
            DMA2CONbits.MODE = init_data.MODE;
            DMA2REQbits.IRQSEL = init_data.IRQSEL;
            DMA2STAL = (uint16_t)addr;
            DMA2PAD = init_data.PAD;
            DMA2CNTbits.CNT = init_data.CNT;
            break;
        case DMA_CHANNEL_3:
            DMA3CONbits.SIZE = init_data.SIZE;
            DMA3CONbits.DIR = init_data.DIR;
            DMA3CONbits.HALF = init_data.HALF;
            DMA3CONbits.NULLW = init_data.NULLW;
            DMA3CONbits.AMODE = init_data.AMODE;
            DMA3CONbits.MODE = init_data.MODE;
            DMA3REQbits.IRQSEL = init_data.IRQSEL;
            DMA3STAL = (uint16_t)addr;
            DMA3PAD = init_data.PAD;
            DMA3CNTbits.CNT = init_data.CNT;
            break;
        default:
            return 1;
    }
    
    return 0;
}

uint16_t DMA_TerminateChannel(DMA_CHANNEL ch) {
    
    switch (ch)
    {
        case 0:
            DMA0CONbits.CHEN = 0;       // channel enable
            DMA0REQbits.IRQSEL = 0;     // interrupt address link
            DMA0PAD = 0;                // peripheral register address link
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
            return 1;
            
    }
    
    active_chs[ch] = 0;
        
    return 0;
}
