/*
 * main.c
 *
 * Created: 11/25/2023 1:25:56 PM
 *  Author: Mina
 */ 

#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "DIO.c"
#include <util/delay.h>


#define   PORTA       (*(unsigned volatile char*)0x3B)
#define   DDRA        (*(unsigned volatile char*)0x3A)
#define   PINA        (*(unsigned volatile char*)0x39)
#define   PORTB       (*(unsigned volatile char*)0x38)
#define   DDRB        (*(unsigned volatile char*)0x37)
#define   PINB        (*(unsigned volatile char*)0x36)
#define   PORTC       (*(unsigned volatile char*)0x35)
#define   DDRC        (*(unsigned volatile char*)0x34)
#define   PINC        (*(unsigned volatile char*)0x33)
#define   PORTD       (*(unsigned volatile char*)0x32)
#define   DDRD        (*(unsigned volatile char*)0x31)
#define   PIND        (*(unsigned volatile char*)0x30)

int counter = 0;

int main(void)
{    
	DIO_enuErrorState_t ErrorStates = DIO_enu_NOK;
	
	     
	ErrorStates = DIO_enuSetPortConfigration(DIO_enuPort_A,DIO_enuOutput);                                         //4 leds is output
	   
	ErrorStates = DIO_enuSetPinConfigration(DIO_enuPort_C,DIO_enuPin_0,DIO_enuInputExternalPulldown);              //botton is input
	
    ErrorStates = DIO_enuSetPortValue(DIO_enuPort_A,DIO_enuLow);                                                    //leds is off
	
    while(1)
    {  
		while(GET_BIT(PINC,0) == 0);                        //to mahowa mash mtdas 3alih mat3mlsh 7aga 
		counter++;                                          //awl mahy5rog mn alwhile aly fatt hyzwd al counter
		while(GET_BIT(PINC,0) ==1 );                          //tol mahowa matdas 3alih mat3mlsh 7aga ma7na zwdna 5las f al 5twa aly fatt
		
			if(counter>15)
			{
			  counter = 0;
			}
		PORTA = counter;
    }
}