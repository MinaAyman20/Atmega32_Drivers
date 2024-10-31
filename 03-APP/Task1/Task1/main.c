/*
 * main.c
 *
 * Created: 12/3/2023 7:10:59 PM
 *  Author: Mina
 */ 

#include "MPort_Interface.h"
#include "DIO.h"
#include <util/delay.h>

int main(void)
{
	 PORT_voidPortInit();
    while(1)
    {
		DIO_enuSetPinValue(DIO_enuPort_A,DIO_enuPin_0,DIO_enuHigh);
		_delay_ms(500);
		DIO_enuSetPinValue(DIO_enuPort_A,DIO_enuPin_0,DIO_enuLow);
		_delay_ms(500);
       
    }
}