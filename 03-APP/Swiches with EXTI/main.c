/*
 * main.c
 *
 *  Created on: Dec 31, 2023
 *      Author: Mina
 */

#include "../HAL/00-LED/HLED_init.h"
#include "../HAL/01-SWITCH/HSWITCH_init.h"
#include "../HAL/02-SSG/HSevenSeg_init.h"
#include <avr/delay.h>

u8 counter = 0;
HSWITCH_enuState_t CountUpSwitch_state = HSWITCH_enuReleased ;
HSWITCH_enuState_t CountDownSwitch_state = HSWITCH_enuReleased ;


void CounterUp(void)
{
	HSWITCH_enuGetSwitchState(CounterUp_Switch,&CountUpSwitch_state);
	if (CountUpSwitch_state == HSWITCH_enuPressed)
	{
		_delay_ms(50);
		if (CountUpSwitch_state == HSWITCH_enuPressed)
		{
			if(counter<=99)
			{
				counter++;
			}
			HSEVENSEG_enuSetDirectValue(counter);
			while(CountUpSwitch_state == HSWITCH_enuPressed)
			{
				HSWITCH_enuGetSwitchState(CounterUp_Switch,&CountUpSwitch_state);
			}

		}
	}
}
void CounterDown(void)
{	HSWITCH_enuGetSwitchState(CounterDown_Switch,&CountDownSwitch_state);
	if (CountDownSwitch_state == HSWITCH_enuPressed)
	{
		_delay_ms(50);
		if (CountDownSwitch_state == HSWITCH_enuPressed)
		{
			if(counter>=0)
			{
				counter--;
			}
			HSEVENSEG_enuSetDirectValue(counter);
		}
		while(CountDownSwitch_state == HSWITCH_enuPressed)
		{
			HSWITCH_enuGetSwitchState(CounterDown_Switch,&CountDownSwitch_state);
		}
	}
}

void main(void)
	{
		PORT_voidPortInit();
		HSWITCH_enuInit();
		HSEVENSEG_enuInit();
		MEXTI_enuInit();

		HSEVENSEG_enuSetDirectValue(counter);
		MEXTI_enuSetCallbackEXTI0(CounterUp);
		MEXTI_enuSetCallbackEXTI1(CounterDown);
		while(1)
		{
			        HSEVENSEG_enuSetDirectValue(counter);
					MEXTI_enuSetCallbackEXTI0(CounterUp);
					MEXTI_enuSetCallbackEXTI1(CounterDown);
		}

	}

