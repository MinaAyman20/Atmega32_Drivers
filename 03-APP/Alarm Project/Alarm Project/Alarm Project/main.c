/*
 * main.c
 *
 * Created: 12/18/2023 6:17:30 PM
 *  Author: Mina
 */ 
#include "HSWITCH_init.h"
#include "HLED_init.h"
#include "HSevenSeg_init.h"
#include <util/delay.h>

int main(void)
{  
    PORT_voidPortInit();
    HLED_enuInit();
    HSWITCH_enuInit();
    HSEVENSEG_enuInit();

    u8 Timer = 0;
     HSWITCH_enuState_t CountUpSwitch_state = HSWITCH_enuReleased ;
	 HSWITCH_enuState_t CountDownSwitch_state = HSWITCH_enuReleased   ;
	 HSWITCH_enuState_t StartSwitch_state = HSWITCH_enuReleased     ;
    

    while(1)
    {
        HSEVENSEG_enuSetDirectValue(Timer);
            
			
			HSWITCH_enuGetSwitchState(CounterUp_Switch,&CountUpSwitch_state);
			HSWITCH_enuGetSwitchState(CounterDown_Switch,&CountDownSwitch_state);
			HSWITCH_enuGetSwitchState(Start_Switch,&StartSwitch_state);
			/*CountUpSwitch_state   =  GET_BIT(PINA,0);
			CountDownSwitch_state =  GET_BIT(PINA,2);
			StartSwitch_state     =  GET_BIT(PINA,4);*/
			
        if (CountUpSwitch_state == HSWITCH_enuPressed)
		{ 
			_delay_ms(50);
           if (CountUpSwitch_state == HSWITCH_enuPressed)
		   {  
			if(Timer<=99)
			{
                Timer++;
			}
		   HSEVENSEG_enuSetDirectValue(Timer);
		   DIO_enuSetPinValue(MPORT_enuPort_A,MPORT_enuPin_6,MPORT_enuLOW);
		   
		   }
		while(CountUpSwitch_state == HSWITCH_enuPressed)
		{
			HSWITCH_enuGetSwitchState(CounterUp_Switch,&CountUpSwitch_state);
		}
		}
		
		

		else if (CountDownSwitch_state == HSWITCH_enuPressed)
		{   
			_delay_ms(50);
			if (CountDownSwitch_state == HSWITCH_enuPressed)
			{
             if(Timer>=0)
			{
                Timer--;
			}
         HSEVENSEG_enuSetDirectValue(Timer);
		 DIO_enuSetPinValue(MPORT_enuPort_A,MPORT_enuPin_6,MPORT_enuLOW);

			}
			while(CountDownSwitch_state == HSWITCH_enuPressed)
			{
				HSWITCH_enuGetSwitchState(CounterDown_Switch,&CountDownSwitch_state);
			}
		}


        else if (StartSwitch_state == HSWITCH_enuPressed)
	    {  
			_delay_ms(50);
			if (StartSwitch_state == HSWITCH_enuPressed)
			{
			while(Timer)
	       {
		        HSEVENSEG_enuSetDirectValue(Timer);
		        _delay_ms(1000);
		        Timer--;
	       }
          DIO_enuSetPinValue(MPORT_enuPort_A,MPORT_enuPin_6,MPORT_enuHIGH);
			}
			while(StartSwitch_state == HSWITCH_enuPressed)
			{
				HSWITCH_enuGetSwitchState(Start_Switch,&StartSwitch_state);
			}
		}

    }
}