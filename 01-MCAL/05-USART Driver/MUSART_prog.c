/*
 * MUSART_prog.c
 *
 *  Created on: Mar 26, 2024
 *      Author: Mina
 */
#include "MUSART_interface.h"

#define UCSRA_RXC_BIT      7 // Receive Complete (UCSRA)
#define UCSRA_TXC_BIT      6 // Transmit Complete (UCSRA)
#define UCSRA_UDRE_BIT     5 // USART Data Register Empty (UCSRA)
#define UCSRA_FE_BIT       4 // Frame Error (UCSRA)
#define UCSRA_DOR_BIT      3 // Data OverRun (UCSRA)
#define UCSRA_PE_BIT       2 // Parity Error (UCSRA)
#define UCSRA_U2X_BIT      1 // Double the USART Transmission Speed (UCSRA)
#define UCSRA_MPCM_BIT     0 // Multi-processor Communication Mode (UCSRA)

#define UCSRB_RXCIE_BIT    7 // RX Complete Interrupt Enable (UCSRB)
#define UCSRB_TXCIE_BIT    6 // TX Complete Interrupt Enable (UCSRB)
#define UCSRB_UDRIE_BIT    5 // USART Data Register Empty Interrupt Enable (UCSRB)
#define UCSRB_RXEN_BIT     4 // Receiver Enable (UCSRB)
#define UCSRB_TXEN_BIT     3 // Transmitter Enable (UCSRB)
#define UCSRB_UCSZ2_BIT    2 // Character Size Bit 2 (UCSRB)
#define UCSRB_RXB8_BIT     1 // Receive Data Bit 8 (UCSRB)
#define UCSRB_TXB8_BIT 	   0


#define UCSRC_URSEL_BIT   7 // Register Select (UCSRC)
#define UCSRC_UMSEL_BIT   6 // USART Mode Select (UCSRC)
#define UCSRC_UPM1_BIT    4 // Parity Mode Bit 1 (UCSRC)
#define UCSRC_UPM0_BIT    5 // Parity Mode Bit 0 (UCSRC)
#define UCSRC_USBS_BIT    3 // Stop Bit Select (UCSRC)
#define UCSRC_UCSZ1_BIT   2 // Character Size Bit 1 (UCSRC)
#define UCSRC_UCSZ0_BIT   1 // Character Size Bit 0 (UCSRC)
#define UCSRC_UCPOL_BIT   0 // Clock Polarity (UCSRC)

typedef struct
{
    u8*  Data;
    u32  Pos;
    u32  Size;
}Buffer_t;

typedef struct
{
    Buffer_t Buffer;
    u32      State;
    TxCB     CB;
}TxBuffer_t;

typedef struct
{
    Buffer_t Buffer;
    u32      State;
    RxCB     CB;
}RxBuffer_t;

typedef enum {
    TX_STATE_READY,
    TX_STATE_BUSY,
} TxState_t;
typedef enum {
    RX_STATE_READY,
    RX_STATE_BUSY,
} RxState_t;

// Initialize TxBuffer with the state set to ready
static volatile TxBuffer_t TxBuffer = {
    .Buffer = { .Data = NULL, .Pos = 0, .Size = 0 },        // Initialize buffer parameters
    .State = TX_STATE_READY,                                // Set the state to ready
    .CB = NULL                                              // Initialize callback function pointer
};
static volatile RxBuffer_t RxBuffer = {
    .Buffer = { .Data = NULL, .Pos = 0, .Size = 0 },       // Initialize buffer parameters
    .State = RX_STATE_READY,                               // Set the state to ready
    .CB = NULL                                             // Initialize callback function pointer
};

void MUSART_enuInit(void)
{
    
#if USART_MODE == USART_ENABLE

u8 LOC_u8UCSRC_REG =0;  // Initialize LOC_u8UCSRC_REG variable to store control register values

 // Enable USART0 and configure its control registers
UCSRB |= (1 << UCSRB_RXEN_BIT);   // Enable receiver (Receiver Enable)
UCSRB |= (1 << UCSRB_TXEN_BIT);   // Enable transmitter (Transmitter Enable)
SREG  |= (1 << 7);  // Enable global interrupts

// Configure USART mode
LOC_u8UCSRC_REG |= (1 << UCSRC_URSEL_BIT);  // Set URSEL bit to select UCSRC register for writing

// Configure USART word length
#if (USART_WORD_LENGTH == USART_5Bit_WORDLENGTH)
     LOC_u8UCSRC_REG &= ~(1 << UCSRC_UCSZ0_BIT);  // Clear UCSZ0 bit for 5-bit word length
     LOC_u8UCSRC_REG&= ~(1 << UCSRC_UCSZ1_BIT);  // Clear UCSZ1 bit for 5-bit word length
     UCSRB &= ~(1 << UCSRB_UCSZ2_BIT);  // Clear UCSZ2 bit for 5-bit word length
#elif (USART_WORD_LENGTH == USART_6Bit_WORDLENGTH)
     LOC_u8UCSRC_REG |=  (1 << UCSRC_UCSZ0_BIT);  // Set UCSZ0 bit for 6-bit word length
     LOC_u8UCSRC_REG &= ~(1 << UCSRC_UCSZ1_BIT);  // Clear UCSZ1 bit for 6-bit word length
     UCSRB &= ~(1 << UCSRB_UCSZ2_BIT);  // Clear UCSZ2 bit for 6-bit word length
#elif (USART_WORD_LENGTH == USART_7Bit_WORDLENGTH)
     LOC_u8UCSRC_REG &= ~(1 << UCSRC_UCSZ0_BIT);  // Clear UCSZ0 bit for 7-bit word length
     LOC_u8UCSRC_REG |=  (1 << UCSRC_UCSZ1_BIT);  // Set UCSZ1 bit for 7-bit word length
     UCSRB &= ~(1 << UCSRB_UCSZ2_BIT);  // Clear UCSZ2 bit for 7-bit word length
#elif (USART_WORD_LENGTH == USART_8Bit_WORDLENGTH)
     LOC_u8UCSRC_REG |=  (1 << UCSRC_UCSZ0_BIT);  // Set UCSZ0 bit for 8-bit word length
     LOC_u8UCSRC_REG |=  (1 << UCSRC_UCSZ1_BIT);  // Set UCSZ1 bit for 8-bit word length
     UCSRB &= ~(1 << UCSRB_UCSZ2_BIT);  // Clear UCSZ2 bit for 8-bit word length
#elif (USART_WORD_LENGTH == USART_9Bit_WORDLENGTH)
    LOC_u8UCSRC_REG |= (1 << UCSRC_UCSZ0_BIT);   // Set UCSZ0 bit for 9-bit word length
    LOC_u8UCSRC_REG |= (1 << UCSRC_UCSZ1_BIT);   // Set UCSZ1 bit for 9-bit word length
    UCSRB |= (1 << UCSRB_UCSZ2_BIT);   // Set UCSZ2 bit for 9-bit word length
#else
    // Handle error: invalid USART word length option
#endif

#if USART_ASYNC_MODE == USART_SYNCHRONOUS 
    #if USART_CLOCK_POLARITY == TRANSMIT_AT_RISING_EDGE
        LOC_u8UCSRC_REG    &= ~(1 << UCSRC_UCPOL_BIT); // Clear the bit to set transmit at rising edge
    #elif USART_CLOCK_POLARITY == TRANSMIT_AT_FALLING_EDGE
        UCSRC |= (1 << UCSRC_UCPOL_BIT); // Set the bit to set transmit at falling edge
    #endif
#endif

// Configure USART parity mode
#if (USART_PARITY_MODE == USART_PARITY_DISABLED)
        LOC_u8UCSRC_REG &= ~(1 << UCSRC_UPM0_BIT);  // Clear UPM0 bit for disabled parity
        LOC_u8UCSRC_REG &= ~(1 << UCSRC_UPM1_BIT);  // Clear UPM1 bit for disabled parity
#elif (USART_PARITY_MODE == USART_EVEN_PARITY)
    LOC_u8UCSRC_REG &= ~(1 << UCSRC_UPM0_BIT);  // Clear UPM0 bit for even parity
    LOC_u8UCSRC_REG |= (1 << UCSRC_UPM1_BIT);   // Set UPM1 bit for even parity
#elif (USART_PARITY_MODE == USART_ODD_PARITY)
    LOC_u8UCSRC_REG |= (1 << UCSRC_UPM0_BIT);   // Set UPM0 bit for odd parity
    LOC_u8UCSRC_REG |= (1 << UCSRC_UPM1_BIT);   // Set UPM1 bit for odd parity
#else
    // Handle error: invalid USART parity mode option
#endif


// Configure USART stop bits
#if (USART_STOP_BITS == USART_STOPBIT_ONE)
    LOC_u8UCSRC_REG &= ~(1 << UCSRC_USBS_BIT);  // Clear USBS bit for one stop bit
#elif (USART_STOP_BITS == USART_STOPBIT_TWO)
    LOC_u8UCSRC_REG |= (1 << UCSRC_USBS_BIT);   // Set USBS bit for two stop bits
#else
    // Handle error: invalid USART stop bits option
#endif
    
   UCSRC = LOC_u8UCSRC_REG;  // Set the value of UCSRC register

    UCSRC &= ~(1 << UCSRC_URSEL_BIT);  // Clear URSEL bit to select UBRRH register for writing
    u16 Loc_u16TempRegister = (u16)((SYSCLK_FREQUENCY / (16 * BAUD_RATE)) - 1);  // Calculate baud rate register value
    UBRRH = (u8)(Loc_u16TempRegister >> 8);    /* MSB at Loc_u16TempRegister */  // Set UBRRH register value
    UBRRL = (u8)Loc_u16TempRegister;           /* LSB at Loc_u16TempRegister */  // Set UBRRL register value

#endif
}

MUSART_enuErrorStatus MUSART_enuSendByteSync(u8 USART_BYTE)
{
     MUSART_enuErrorStatus Ret_enuUSART_ErrorStatus = MUSART_enuOK;
    if(USART_MODE == USART_ENABLE)
    {
          UDR = USART_BYTE;                   /* Put data into buffer, sends the data */
          while (!(UCSRA & (1 << UCSRA_TXC_BIT))); 
         
    }
    else
    {   
           Ret_enuUSART_ErrorStatus = MUSART_enuNOK;          
    }
    return Ret_enuUSART_ErrorStatus ;
}


MUSART_enuErrorStatus MUSART_enuRecieveByteSync(u8* USART_BYTE)
{
    MUSART_enuErrorStatus Ret_enuUSART_ErrorStatus = MUSART_enuOK;
    if(USART_MODE == USART_DISABLE)
    {
         Ret_enuUSART_ErrorStatus = MUSART_enuNOK;
    }
    else
    {
          while ( !(UCSRA & (1<<UCSRA_RXC_BIT)) );   /* Wait for data to be received */
           *USART_BYTE = UDR;                         /* Get and return received data from buffer */
    }
        return Ret_enuUSART_ErrorStatus ;
}

MUSART_enuErrorStatus MUSART_enuSendBufferAsync(u8* USART_BUFFER, u16 LENGTH, TxCB CB)
{
    MUSART_enuErrorStatus Ret_enuUSART_ErrorStatus = MUSART_enuOK;
    
    if (USART_MODE == USART_DISABLE)
    {
        Ret_enuUSART_ErrorStatus = MUSART_enuNOK;
    }
    else if (USART_BUFFER == NULL && CB == NULL)
    {  
        Ret_enuUSART_ErrorStatus = MUSART_enuNULL_POINTER;
    }
    else
    {
        if (TxBuffer.State == TX_STATE_READY)
        { 
            TxBuffer.State = TX_STATE_BUSY;
            TxBuffer.Buffer.Data = USART_BUFFER;
            TxBuffer.Buffer.Pos = 0;
            TxBuffer.Buffer.Size = LENGTH;
            TxBuffer.CB = CB;       
             
            // Enable TXC interrupt (Transmit Complete Interrupt Enable)
            UCSRB |= (1 << UCSRB_TXCIE_BIT);
            
            // Transmit the first byte immediately
            UDR = TxBuffer.Buffer.Data[0];
            TxBuffer.Buffer.Pos++;
        }
        else
        {
            // TxBuffer is not ready for transmission, handle accordingly
            Ret_enuUSART_ErrorStatus = MUSART_enuTX_STATE_BUSY;
        }
    }
    
    return Ret_enuUSART_ErrorStatus;
}

MUSART_enuErrorStatus MUSART_enuRecieveBufferAsync(u8* USART_BUFFER,u16 LENGTH,RxCB CB)
{
     MUSART_enuErrorStatus Ret_enuUSART_ErrorStatus = MUSART_enuOK;
     if(USART_MODE == USART_DISABLE)
     {
         Ret_enuUSART_ErrorStatus = MUSART_enuNOK;
     }
    // Check if USART ID is valid
    
    else if (USART_BUFFER == NULL && CB == NULL)
    {
        Ret_enuUSART_ErrorStatus = MUSART_enuNULL_POINTER;
    }
    else
    {
      
        if(RxBuffer.State == RX_STATE_READY)
        {    
            
             RxBuffer.State = RX_STATE_BUSY;
             RxBuffer.Buffer.Data = USART_BUFFER;
             RxBuffer.Buffer.Pos = 0;
             RxBuffer.Buffer.Size = LENGTH;
             RxBuffer.CB = CB; 
             UCSRB |= (1 << UCSRB_RXCIE_BIT);  // Enable RXC interrupt (Receive Complete Interrupt Enable)
        }
         else
        {
             // TxBuffer is not ready for transmission
             Ret_enuUSART_ErrorStatus = RX_STATE_BUSY;
        }

    }
     return Ret_enuUSART_ErrorStatus ;
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{    
    
    // Transmit data if there is more data to send
    if (TxBuffer.Buffer.Pos < TxBuffer.Buffer.Size)
    {
        UDR = TxBuffer.Buffer.Data[TxBuffer.Buffer.Pos];
        TxBuffer.Buffer.Pos++;
    }
    else
    {
        // All data has been transmitted, so disable TXC interrupt
        UCSRB &= ~(1 << UCSRB_TXCIE_BIT);
        
        // Set the state to indicate that transmission is complete
        TxBuffer.State = TX_STATE_READY;

        // Call the callback function if it is assigned
        if (TxBuffer.CB)
        {
            TxBuffer.CB();
        }
    }
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{  
    // Receive data if there is space available in the receive buffer
    if (RxBuffer.Buffer.Pos < RxBuffer.Buffer.Size)
    {
        RxBuffer.Buffer.Data[RxBuffer.Buffer.Pos] = UDR;
        RxBuffer.Buffer.Pos++;
    }
    else
    {
        // Clear the RXC flag and set RxBuffer state to ready
        UCSRB &= ~(1 << UCSRB_RXCIE_BIT);  // Enable RXC interrupt (Receive Complete Interrupt Enable)
        RxBuffer.State = RX_STATE_READY;

        // Call the callback function if it is assigned
        if (RxBuffer.CB)
        {
            RxBuffer.CB();
        }
    }
}
