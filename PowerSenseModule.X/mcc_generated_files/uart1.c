// THIS FILE HAS BEEN MODIFIED BY JAN TO WORK
// WITH THE PROJECT. THE UART RX INTERRUPT HAS BEEN MODIFIED.

/**
  Section: Included Files
*/

#include "uart1.h"
#include "../device_configuration.h"

/**
  Section: Data Type Definitions
*/

/** UART Driver Queue Status

  @Summary
    Defines the object required for the status of the queue.
*/

typedef union
{
    struct
    {
            uint8_t full:1;
            uint8_t empty:1;
            uint8_t reserved:6;
    }s;
    uint8_t status;
}

UART_BYTEQ_STATUS;

/** UART Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

*/

typedef struct
{
    /* RX Byte Q */
    uint8_t                                      *rxTail ;

    uint8_t                                      *rxHead ;

    /* TX Byte Q */
    uint8_t                                      *txTail ;

    uint8_t                                      *txHead ;

    UART_BYTEQ_STATUS                        rxStatus ;

    UART_BYTEQ_STATUS                        txStatus ;

} UART_OBJECT ;

static volatile UART_OBJECT uart1_obj ;

/** UART Driver Queue Length

  @Summary
    Defines the length of the Transmit and Receive Buffers

*/

#define UART1_CONFIG_TX_BYTEQ_LENGTH 32
#define UART1_CONFIG_RX_BYTEQ_LENGTH 8

/** UART Driver Queue

  @Summary
    Defines the Transmit and Receive Buffers

*/

static uint8_t uart1_txByteQ[UART1_CONFIG_TX_BYTEQ_LENGTH] ;
static uint8_t uart1_rxByteQ[UART1_CONFIG_RX_BYTEQ_LENGTH] ;

/**
  Section: Driver Interface
*/

void UART1_Initialize(void)
{
    // Set the UART1 module to the options selected in the user interface.

    // STSEL 1; IREN disabled; PDSEL 8N; UARTEN enabled; RTSMD disabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; URXINV disabled; UEN TX_RX; 
    // Data Bits = 8; Parity = None; Stop Bits = 1;
    U1MODE = (0x8008 & ~(1<<15));  // disabling UARTEN bit
    // UTXISEL0 TX_ONE_CHAR; UTXINV disabled; OERR NO_ERROR_cleared; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; 
    U1STA = 0x00;
    
#if defined POSC_25MHz
    // BaudRate = 9600; Frequency = 12500000 Hz; BRG 325; 
    U1BRG = 0x145;
#elif defined FRC_NORMAL
#elif defined FRC_40MHz
    // BaudRate = 9600; Frequency = 40MHz Hz; BRG 325; 
    U1BRG = 1040;
#elif defined FRC_SLOWEST
#endif 
    
    
    IEC0bits.U1RXIE = 1;
    
    //Make sure to set LAT bit corresponding to TxPin as high before UART initialization
 
    UART1_Enable();  // enabling UARTEN bit

    uart1_obj.txHead = uart1_txByteQ;
    uart1_obj.txTail = uart1_txByteQ;
    uart1_obj.rxHead = uart1_rxByteQ;
    uart1_obj.rxTail = uart1_rxByteQ;
    uart1_obj.rxStatus.s.empty = true;
    uart1_obj.txStatus.s.empty = true;
    uart1_obj.txStatus.s.full = false;
    uart1_obj.rxStatus.s.full = false;
}

/**
    Maintains the driver's transmitter state machine and implements its ISR
*/

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1TXInterrupt ( void )
{ 
    if((uart1_obj.txHead == uart1_obj.txTail) && (uart1_obj.txStatus.s.full == false))
    {
        while(U1STAbits.TRMT == 0){}
        
        uart1_obj.txStatus.s.empty = true;
        IEC0bits.U1TXIE = 0;
        return;
    }

    IFS0bits.U1TXIF = 0;

    while(!(U1STAbits.UTXBF == 1))
    {
        U1TXREG = *uart1_obj.txHead;

        uart1_obj.txHead++;

        if(uart1_obj.txHead == (uart1_txByteQ + UART1_CONFIG_TX_BYTEQ_LENGTH))
        {
            uart1_obj.txHead = uart1_txByteQ;
        }

        uart1_obj.txStatus.s.full = false;

        if(uart1_obj.txHead == uart1_obj.txTail)
        {
            break;
        }
    }
}

extern bool menuStatus;

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt( void )
{
    while((U1STAbits.URXDA == 1))
    {
        *uart1_obj.rxTail = U1RXREG;
        if(*uart1_obj.rxTail == 'Z' || *uart1_obj.rxTail == 'z' )
            menuStatus = true;

        uart1_obj.rxTail++;

        if(uart1_obj.rxTail == (uart1_rxByteQ + UART1_CONFIG_RX_BYTEQ_LENGTH))
        {
            uart1_obj.rxTail = uart1_rxByteQ;
        }

        uart1_obj.rxStatus.s.empty = false;
        
        if(uart1_obj.rxTail == uart1_obj.rxHead)
        {
            //Sets the flag RX full
            uart1_obj.rxStatus.s.full = true;
            break;
        }
    }

    IFS0bits.U1RXIF = false;
   
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1ErrInterrupt( void )
{
    if ((U1STAbits.OERR == 1))
    {
        U1STAbits.OERR = 0;
    }
    
    IFS4bits.U1EIF = false;
}

/**
  Section: UART Driver Client Routines
*/

uint8_t UART1_Read( void)
{
    uint8_t data = 0;

    data = *uart1_obj.rxHead;

    uart1_obj.rxHead++;

    if (uart1_obj.rxHead == (uart1_rxByteQ + UART1_CONFIG_RX_BYTEQ_LENGTH))
    {
        uart1_obj.rxHead = uart1_rxByteQ;
    }

    if (uart1_obj.rxHead == uart1_obj.rxTail)
    {
        uart1_obj.rxStatus.s.empty = true;
    }

    uart1_obj.rxStatus.s.full = false;

    return data;
}

unsigned int UART1_ReadBuffer( uint8_t *buffer, const unsigned int bufLen)
{
    unsigned int numBytesRead = 0 ;
    while ( numBytesRead < ( bufLen ))
    {
        if( uart1_obj.rxStatus.s.empty)
        {
            break;
        }
        else
        {
            buffer[numBytesRead++] = UART1_Read () ;
        }
    }

    return numBytesRead ;
}

void UART1_Write( const uint8_t byte)
{
    IEC0bits.U1TXIE = 0;
    
    *uart1_obj.txTail = byte;

    uart1_obj.txTail++;
    
    if (uart1_obj.txTail == (uart1_txByteQ + UART1_CONFIG_TX_BYTEQ_LENGTH))
    {
        uart1_obj.txTail = uart1_txByteQ;
    }

    uart1_obj.txStatus.s.empty = false;

    if (uart1_obj.txHead == uart1_obj.txTail)
    {
        uart1_obj.txStatus.s.full = true;
    }

    IEC0bits.U1TXIE = 1 ;
}

unsigned int UART1_WriteBuffer( const uint8_t *buffer , const unsigned int bufLen )
{
    unsigned int numBytesWritten = 0 ;

    while ( numBytesWritten < ( bufLen ))
    {
        if((uart1_obj.txStatus.s.full))
        {
            break;
        }
        else
        {
            UART1_Write (buffer[numBytesWritten++] ) ;
        }
    }

    return numBytesWritten ;
}

UART1_TRANSFER_STATUS UART1_TransferStatusGet (void )
{
    UART1_TRANSFER_STATUS status = 0;

    /* The TX empty must be checked before the full in order to prevent a race
     * condition where a TX transmission could start between these two checks
     * resulting in both full and empty set at the same time.
     */
    if(uart1_obj.txStatus.s.empty)
    {
        status |= UART1_TRANSFER_STATUS_TX_EMPTY;
    }

    if(uart1_obj.txStatus.s.full)
    {
        status |= UART1_TRANSFER_STATUS_TX_FULL;
    }

    /* The RX full must be checked before the empty in order to prevent a race
     * condition where a RX reception could start between these two checks
     * resulting in both empty and full set at the same time.
     */
    if(uart1_obj.rxStatus.s.full)
    {
        status |= UART1_TRANSFER_STATUS_RX_FULL;
    }

    if(uart1_obj.rxStatus.s.empty)
    {
        status |= UART1_TRANSFER_STATUS_RX_EMPTY;
    }
    else
    {
        status |= UART1_TRANSFER_STATUS_RX_DATA_PRESENT;
    }
    return status;
}

/*
    Uart Peek function returns the character in the read sequence with
    the provided offset, without extracting it.
*/
uint8_t UART1_Peek(uint16_t offset)
{
    if( (uart1_obj.rxHead + offset) >= (uart1_rxByteQ + UART1_CONFIG_RX_BYTEQ_LENGTH))
    {
      return uart1_rxByteQ[offset - (uart1_rxByteQ + UART1_CONFIG_RX_BYTEQ_LENGTH - uart1_obj.rxHead)];
    }
    else
    {
      return *(uart1_obj.rxHead + offset);
    }
}

/*
    Uart PeekSafe function validates all the possible conditions and get the character  
    in the read sequence with the provided offset, without extracting it.
*/
bool UART1_PeekSafe(uint8_t *dataByte, uint16_t offset)
{
    uint16_t index = 0;
    bool status = true;
    
    if((offset >= UART1_CONFIG_RX_BYTEQ_LENGTH) || (uart1_obj.rxStatus.s.empty) || (!dataByte))
    {
        status = false;
    }
    else
    {    
        //Compute the offset buffer overflow range
        index = ((uart1_obj.rxHead - uart1_rxByteQ) + offset) % UART1_CONFIG_RX_BYTEQ_LENGTH;
    
        /**
         * Check for offset input value range is valid or invalid. If the range 
         * is invalid, then status set to false else true.
         */
        if(uart1_obj.rxHead < uart1_obj.rxTail) 
        {
            if((uart1_obj.rxHead + offset) > (uart1_obj.rxTail - 1))
            {
                status = false;
            }
        }
        else if(uart1_obj.rxHead > uart1_obj.rxTail)
        {
            if((uart1_rxByteQ + index) < uart1_obj.rxHead)
            {
                if( (uart1_rxByteQ + index) >= uart1_obj.rxTail )
                {
                    status = false;
                }
            } 
        }

        if(status == true)
        {
            *dataByte = UART1_Peek(offset);
        }
    }
    return status;
}

unsigned int UART1_ReceiveBufferSizeGet(void)
{
    if(!uart1_obj.rxStatus.s.full)
    {
        if(uart1_obj.rxHead > uart1_obj.rxTail)
        {
            return(uart1_obj.rxHead - uart1_obj.rxTail);
        }
        else
        {
            return(UART1_CONFIG_RX_BYTEQ_LENGTH - (uart1_obj.rxTail - uart1_obj.rxHead));
        } 
    }
    return 0;
}

unsigned int UART1_TransmitBufferSizeGet(void)
{
    if(!uart1_obj.txStatus.s.full)
    { 
        if(uart1_obj.txHead > uart1_obj.txTail)
        {
            return(uart1_obj.txHead - uart1_obj.txTail);
        }
        else
        {
            return(UART1_CONFIG_TX_BYTEQ_LENGTH - (uart1_obj.txTail - uart1_obj.txHead));
        }
    }
    return 0;
}

bool UART1_ReceiveBufferIsEmpty (void)
{
    return(uart1_obj.rxStatus.s.empty);
}

bool UART1_TransmitBufferIsFull(void)
{
    return(uart1_obj.txStatus.s.full);
}

void UART1_Enable(void)
{
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}

void UART1_Disable(void)
{
    U1MODEbits.UARTEN = 0;
    U1STAbits.UTXEN = 0;
}

uint16_t UART1_StatusGet (void)
{
    return U1STA;
}

int __attribute__((__section__(".libc.write"))) write(int handle, void *buffer, unsigned int len) {
    while(U1STAbits.TRMT == 0);
    return UART1_WriteBuffer((uint8_t *) buffer, len);
}
