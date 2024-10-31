/*
 * main.c
 *
 * Created: 11/26/2023 4:34:12 PM
 *  Author: Mina
 */ 

#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "DIO.c"
#include <util/delay.h>


int main(void)
{   
	DIO_enuErrorState_t Errorstatus = DIO_enu_NOK;
	
   Errorstatus = DIO_enuSetPortConfigration(DIO_enuPort_A,DIO_enuOutput);

	
    while(1)
    {
      Errorstatus= DIO_enuSetPinValue(DIO_enuPort_A,DIO_enuPin_0,DIO_enuHigh);
        _delay_ms(250);
     Errorstatus=  DIO_enuSetPinValue(DIO_enuPort_A,DIO_enuPin_0,DIO_enuLow);
        _delay_ms(250);
    }
}