/*
 * MUSART_interface.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Mina
 */
#include "../../LIB/STD_TYPES.h"
#include "MUSART_priv.h"

#ifndef MCAL_06_MUSART_MUSART_INTERFACE_H_
#define MCAL_06_MUSART_MUSART_INTERFACE_H_

#define USART_DISABLE  0
#define USART_ENABLE   1

#define USART_ASYNCHRONOUS  0 // Asynchronous Operation
#define USART_SYNCHRONOUS   1 // Synchronous Operation

#define USART_PARITY_DISABLED       0// Disabled
#define USART_EVEN_PARITY           1 // Enabled, Even Parity
#define USART_ODD_PARITY            2 // Enabled, Odd Parity

#define USART_STOPBIT_ONE             0 // 1-bit
#define USART_STOPBIT_TWO             1 // 2-bit

#define USART_5Bit_WORDLENGTH         0 // 5-bit
#define USART_6Bit_WORDLENGTH         1 // 6-bit
#define USART_7Bit_WORDLENGTH         2 // 7-bit
#define USART_8Bit_WORDLENGTH         3 // 8-bit
#define USART_9Bit_WORDLENGTH         4 // 9-bit

#define TRANSMIT_AT_RISING_EDGE   0 // Rising XCK Edge
#define TRANSMIT_AT_FALLING_EDGE  1 // Falling XCK Edge



typedef enum
{
    MUSART_enuOK                 , // Enumeration for operation success
    MUSART_enuNOK                , // Enumeration for operation failure
    MUSART_enuWRONG_UARTID       ,
    MUSART_enuNULL_POINTER       ,
    MUSART_enuTX_STATE_BUSY      ,
   
}MUSART_enuErrorStatus;            // Enumeration for error status



void MUSART_enuInit(void);
MUSART_enuErrorStatus MUSART_enuSendByteSync(u8 USART_BYTE);
MUSART_enuErrorStatus MUSART_enuRecieveByteSync(u8* USART_BYTE);
MUSART_enuErrorStatus MUSART_enuSendBufferAsync(u8* USART_BUFFER,u16 LENGTH,TxCB CB);
MUSART_enuErrorStatus MUSART_enuRecieveBufferAsync(u8* USART_BUFFER,u16 LENGTH,RxCB CB);
void MUSART_vIsRx(void);


#endif
