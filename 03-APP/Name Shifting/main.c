/*
 * main.c
 *
 *  Created on: Dec 31, 2023
 *      Author: Mina
 */

#include "../HAL/HLCD/HLCD_interface.h"
#include <avr/delay.h>
u8 customChar[] = {
		0x1F,
		0x11,
		0x11,
		0x1F,
		0x11,
		0x11,
		0x11,
		0x1F
};
int main (void)
{
	HLCD_enuLCDPinConfigration();
	HLCD_voidLCDInit();
	HLCD_voidSendString("MINA AYMAN",HLCD_enuFirstLine,HLCD_enuPosition0);
	_delay_ms(500);
	while(1)
	{
		for(int i=0 ; i<16;i++)
		{
			HLCD_voidLCDSendCommand(HLCD_SHIFTING_RIGHT);
			_delay_ms(500);
		}

		for(int i=0 ; i<26;i++)
		{
			HLCD_voidLCDSendCommand(HLCD_SHIFTING_LEFT);
			_delay_ms(500);
		}
		for(int i=0 ; i<10;i++)
		{
			HLCD_voidLCDSendCommand(HLCD_SHIFTING_RIGHT);
			_delay_ms(500);
		}

	}
	return 0;
}

