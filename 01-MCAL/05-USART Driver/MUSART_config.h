/*
 * MUSART_config.h
 *
 *  Created on: Mar 26, 2024
 *      Author: Mina
 */

#ifndef MCAL_06_MUSART_MUSART_CONFIG_H_
#define MCAL_06_MUSART_MUSART_CONFIG_H_

#define SYSCLK_FREQUENCY 8000000UL          // Example: 8 MHz

/********************************************Configration For USART1*******************************************/
#define BAUD_RATE        9600UL               // Example: 9600 baud
/*
 * OPTIONS :
 *           USART_ENABLE   
 *           USART_DISABLE  
 */
#define  USART_MODE                   USART_ENABLE
/*
 * OPTIONS :
 *
 *           USART_5Bit_WORDLENGTH   
 *           USART_6Bit_WORDLENGTH   
 *           USART_7Bit_WORDLENGTH   
 *           USART_8Bit_WORDLENGTH   
 *           USART_9Bit_WORDLENGTH   
 */
#define  USART_WORD_LENGTH            USART_8Bit_WORDLENGTH


/*
 * OPTIONS :
 *
 *           USART_PARITY_DISABLED 
 *           USART_EVEN_PARITY   
 *           USART_ODD_PARITY    
 */
#define  USART_PARITY_MODE            USART_PARITY_DISABLED

/*
 * OPTIONS :

 *           USART_STOPBIT_ONE
 *           USART_STOPBIT_TWO   
 */
#define  USART_STOP_BITS              USART_STOPBIT_ONE

/*
 * OPTIONS :
 *           USART_ASYNCHRONOUS
 *           USART_SYNCHRONOUS   
 */
#define  USART_ASYNC_MODE              USART_SYNCHRONOUS 

/*
 * OPTIONS :
 *    TRANSMIT_AT_RISING_EDGE   
 *    TRANSMIT_AT_FALLING_EDGE 
 */
 #define USART_CLOCK_POLARITY         TRANSMIT_AT_RISING_EDGE


#endif /* MCAL_06_MUSART_MUSART_CONFIG_H_ */
