#include "dma.h"
//#include <string.h>

/*
volatile DMAxREGS DMA0REGS = {  \
                                .CONbits    = &DMA0CONbits,  \
                                .REQbits    = &DMA0REQbits,  \
                                .STAH       = &DMA0STAHbits, \
                                .STAL       = &DMA0STAL,     \
                                .STBH       = &DMA0STBHbits, \
                                .STBL       = &DMA0STBL,     \
                                .PAD        = &DMA0PAD,      \
                                .CNT        = &DMA0CNTbits  \
                                };

volatile DMAxREGS DMA1REGS = {  \
                                .CONbits    = &DMA1CONbits,  \
                                .REQbits    = &DMA1REQbits,  \
                                .STAH       = &DMA1STAHbits, \
                                .STAL       = &DMA1STAL,     \
                                .STBH       = &DMA1STBHbits, \
                                .STBL       = &DMA1STBL,     \
                                .PAD        = &DMA1PAD,      \
                                .CNT        = &DMA1CNTbits  \
                                };

volatile DMAxREGS DMA2REGS = {  \
                                .CONbits    = &DMA2CONbits,  \
                                .REQbits    = &DMA2REQbits,  \
                                .STAH       = &DMA2STAHbits, \
                                .STAL       = &DMA2STAL,     \
                                .STBH       = &DMA2STBHbits, \
                                .STBL       = &DMA2STBL,     \
                                .PAD        = &DMA2PAD,      \
                                .CNT        = &DMA2CNTbits,  \
                                };

volatile DMAxREGS DMA3REGS = {  .name = "", \
                                .CONbits    = &DMA3CONbits,  \
                                .REQbits    = &DMA3REQbits,  \
                                .STAH       = &DMA3STAHbits, \
                                .STAL       = &DMA3STAL,     \
                                .STBH       = &DMA3STBHbits, \
                                .STBL       = &DMA3STBL,     \
                                .PAD        = &DMA3PAD,      \
                                .CNT        = &DMA3CNTbits  \
                                };


volatile DMAxREGS DMA_CHList[NUM_DMA_CH] = {
                            {   .name       = ""            \
                                .CONbits    = &DMA0CONbits,  \
                                .REQbits    = &DMA0REQbits,  \
                                .STAH       = &DMA0STAHbits, \
                                .STAL       = &DMA0STAL,     \
                                .STBH       = &DMA0STBHbits, \
                                .STBL       = &DMA0STBL,     \
                                .PAD        = &DMA0PAD,      \
                                .CNT        = &DMA0CNTbits  \
                                },
                            {   .name       = ""            \
                                .CONbits    = &DMA1CONbits,  \
                                .REQbits    = &DMA1REQbits,  \
                                .STAH       = &DMA1STAHbits, \
                                .STAL       = &DMA1STAL,     \
                                .STBH       = &DMA1STBHbits, \
                                .STBL       = &DMA1STBL,     \
                                .PAD        = &DMA1PAD,      \
                                .CNT        = &DMA1CNTbits  \
                                },
                            {   .name       = ""            \
                                .CONbits    = &DMA2CONbits,  \
                                .REQbits    = &DMA2REQbits,  \
                                .STAH       = &DMA2STAHbits, \
                                .STAL       = &DMA2STAL,     \
                                .STBH       = &DMA2STBHbits, \
                                .STBL       = &DMA2STBL,     \
                                .PAD        = &DMA2PAD,      \
                                .CNT        = &DMA2CNTbits,  \
                                },
                            {   .name       = ""            \
                                .CONbits    = &DMA3CONbits,  \
                                .REQbits    = &DMA3REQbits,  \
                                .STAH       = &DMA3STAHbits, \
                                .STAL       = &DMA3STAL,     \
                                .STBH       = &DMA3STBHbits, \
                                .STBL       = &DMA3STBL,     \
                                .PAD        = &DMA3PAD,      \
                                .CNT        = &DMA3CNTbits  \
                            }
                        };
*/

/*
 *      PERIPHERAL CONFIGURATION DATA
 */

DMAxINIT DMA_ADC_INIT = {   .CHEN   = 1,     \
                            .SIZE   = 1,     \
                            .DIR    = 1,     \
                            .HALF   = 1,     \
                            .NULLW  = 1,     \
                            .AMODE  = 1,     \
                            .MODE   = 1,     \
                            .IRQSEL = 1,     \
                            .STAH   = 1,     \
                            .STAL   = 1,     \
                            .STBH   = 1,     \
                            .STBL   = 1,     \
                            .PAD    = 1,     \
                            .CNT    = 1     \
                            };


DMAxINIT DMA_CANRX_INIT = { .CHEN   = 0,     \
                            .SIZE   = 0,     \
                            .DIR    = 0,     \
                            .HALF   = 0,     \
                            .NULLW  = 0,     \
                            .AMODE  = 0,     \
                            .MODE   = 0,     \
                            .IRQSEL = 0,     \
                            .STAH   = 0,     \
                            .STAL   = 0,     \
                            .STBH   = 0,     \
                            .STBL   = 0,     \
                            .PAD    = 0,     \
                            .CNT    = 0     \
                            };

DMAxINIT DMA_CANTX_INIT = { .CHEN   = 0,     \
                            .SIZE   = 0,     \
                            .DIR    = 0,     \
                            .HALF   = 0,     \
                            .NULLW  = 0,     \
                            .AMODE  = 0,     \
                            .MODE   = 0,     \
                            .IRQSEL = 0,     \
                            .STAH   = 0,     \
                            .STAL   = 0,     \
                            .STBH   = 0,     \
                            .STBL   = 0,     \
                            .PAD    = 0,     \
                            .CNT    = 0     \
                            };


uint8_t active_chs[NUM_DMA_CH] = { 0 };


void DMA_Initialize() {
    DMA_InitializeCH(DMA_ADC_CH, DMA_ADC_INIT);
    DMA_InitializeCH(DMA_CANTX_CH, DMA_CANTX_INIT);
    DMA_InitializeCH(DMA_CANRX_CH, DMA_CANRX_INIT);
}


uint16_t DMA_InitializeCH(uint16_t ch, DMAxINIT init_data) {
    if ((ch >= NUM_DMA_CH) || (ch < 0))
        return 1;
    
    if (active_chs[ch] == 1)
        return 1;
    else 
        active_chs[ch] = 1;
    
    switch (ch)
    {
        case 0:
            DMA0CONbits.CHEN = init_data.CHEN;
            DMA0CONbits.SIZE = init_data.SIZE;
            DMA0CONbits.DIR = init_data.DIR;
            DMA0CONbits.HALF = init_data.HALF;
            DMA0CONbits.NULLW = init_data.NULLW;
            DMA0CONbits.AMODE = init_data.AMODE;
            DMA0CONbits.MODE = init_data.MODE;
            DMA0REQbits.IRQSEL = init_data.IRQSEL;
            DMA0STAHbits.STA = init_data.STAH;
            DMA0STAL = init_data.STAL;
            DMA0STBHbits.STB = init_data.STBH;
            DMA0STBL = init_data.STBL;
            DMA0PAD = init_data.PAD;
            DMA0CNTbits.CNT = init_data.CNT;
            break;
        case 1:
            DMA1CONbits.CHEN = init_data.CHEN;
            DMA1CONbits.SIZE = init_data.SIZE;
            DMA1CONbits.DIR = init_data.DIR;
            DMA1CONbits.HALF = init_data.HALF;
            DMA1CONbits.NULLW = init_data.NULLW;
            DMA1CONbits.AMODE = init_data.AMODE;
            DMA1CONbits.MODE = init_data.MODE;
            DMA1REQbits.IRQSEL = init_data.IRQSEL;
            DMA1STAHbits.STA = init_data.STAH;
            DMA1STAL = init_data.STAL;
            DMA1STBHbits.STB = init_data.STBH;
            DMA1STBL = init_data.STBL;
            DMA1PAD = init_data.PAD;
            DMA1CNTbits.CNT = init_data.CNT;
            break;
        case 2:
            DMA2CONbits.CHEN = init_data.CHEN;
            DMA2CONbits.SIZE = init_data.SIZE;
            DMA2CONbits.DIR = init_data.DIR;
            DMA2CONbits.HALF = init_data.HALF;
            DMA2CONbits.NULLW = init_data.NULLW;
            DMA2CONbits.AMODE = init_data.AMODE;
            DMA2CONbits.MODE = init_data.MODE;
            DMA2REQbits.IRQSEL = init_data.IRQSEL;
            DMA2STAHbits.STA = init_data.STAH;
            DMA2STAL = init_data.STAL;
            DMA2STBHbits.STB = init_data.STBH;
            DMA2STBL = init_data.STBL;
            DMA2PAD = init_data.PAD;
            DMA2CNTbits.CNT = init_data.CNT;
            break;
        case 3:
            DMA3CONbits.CHEN = init_data.CHEN;
            DMA3CONbits.SIZE = init_data.SIZE;
            DMA3CONbits.DIR = init_data.DIR;
            DMA3CONbits.HALF = init_data.HALF;
            DMA3CONbits.NULLW = init_data.NULLW;
            DMA3CONbits.AMODE = init_data.AMODE;
            DMA3CONbits.MODE = init_data.MODE;
            DMA3REQbits.IRQSEL = init_data.IRQSEL;
            DMA3STAHbits.STA = init_data.STAH;
            DMA3STAL = init_data.STAL;
            DMA3STBHbits.STB = init_data.STBH;
            DMA3STBL = init_data.STBL;
            DMA3PAD = init_data.PAD;
            DMA3CNTbits.CNT = init_data.CNT;
            break;
        default:
            return 1;
    }
    
    return 0;
}

uint16_t DMA_TerminateCH(uint16_t ch) {
    
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
            return 1;
            
    }
    
    active_chs[ch] = 0;
        
    return 0;
}
