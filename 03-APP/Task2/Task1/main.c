/*
 * main.c
 *
 * Created: 12/3/2023 7:10:59 PM
 *  Author: Mina
 */ 

#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "MPort_Interface.h"
#include "Mport_Priv.h"

u8 counter = 0;

int main(void)
{
	 PORT_voidPortInit();
    while(1)
    {
		while(GET_BIT(PINB,0) == 0);                        //to mahowa mash mtdas 3alih mat3mlsh 7aga
		counter++;                                          //awl mahy5rog mn alwhile aly fatt hyzwd al counter
		while(GET_BIT(PINB,0) == 1 );                          //tol mahowa matdas 3alih mat3mlsh 7aga ma7na zwdna 5las f al 5twa aly fatt
		
		if(counter>15)
		{
			counter = 0;
		}
		PORTA = counter;
       
    }
}