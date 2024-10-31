#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "MPort_Interface.h"
#include "DIO.h"

#include "HLED_init.h"
#include "HLED_config.h"
#include "HLED_priv.h"

extern HLED_strLED_t LEDS_Config[NUMBER_OF_LEDS];

HLED_enuErrorStatus_t HLED_enuInit(void)
{
  HLED_enuErrorStatus_t Ret_enuLedsErrorStatus = HLED_enuNOK;

  MPORT_strConfig_t LOC_strCurrentLed;
  for(int i = 0 ; i< NUMBER_OF_LEDS ; i++)
  {
    if((LEDS_Config->ActiveMode == HLED_enuActiveHigh) || (LEDS_Config->ActiveMode == HLED_enuActiveLow))
    {
        LOC_strCurrentLed.Port = LEDS_Config[i].Port;
        LOC_strCurrentLed.Pin  = LEDS_Config[i].Pin;

        if((LEDS_Config[i].ActiveMode == HLED_enuActiveHigh) && (LEDS_Config[i].State == HLED_enuON))
        {
           LOC_strCurrentLed.Mode = MPORT_enu_OUTPUT_HIGH  ;
        }
       else if((LEDS_Config[i].ActiveMode == HLED_enuActiveHigh) && (LEDS_Config[i].State == HLED_enuOFF))
        {
           LOC_strCurrentLed.Mode = MPORT_enu_OUTPUT_LOW ;
        }
       else if((LEDS_Config[i].ActiveMode == HLED_enuActiveLow) && (LEDS_Config[i].State == HLED_enuON))
        {
           LOC_strCurrentLed.Mode = MPORT_enu_OUTPUT_LOW ;
        }
       else if((LEDS_Config[i].ActiveMode == HLED_enuActiveLow) && (LEDS_Config[i].State == HLED_enuOFF))
        {
           LOC_strCurrentLed.Mode = MPORT_enu_OUTPUT_HIGH ;
        }
        if(MPORT_enuSetConfig(&LOC_strCurrentLed) )
        {
           Ret_enuLedsErrorStatus = HLED_enuDIOError;
		}
    }
    else
    {
        Ret_enuLedsErrorStatus = HLED_enuInvalidActivestate;
    }
}
return Ret_enuLedsErrorStatus;
}


HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedName, HLED_enuState_t Copy_u8State)
{
   HLED_enuErrorStatus_t Ret_enuLedsErrorStatus = HLED_enuOK;
   if(Copy_u8LedName < NUMBER_OF_LEDS)
	{
		LEDS_Config[Copy_u8LedName].State = Copy_u8State;
		if((LEDS_Config[Copy_u8LedName].ActiveMode) == HLED_enuActiveHigh)
		{
			if(LEDS_Config[Copy_u8LedName].State == HLED_enuON)
			{
				DIO_enuSetPinValue(LEDS_Config[Copy_u8LedName].Port,LEDS_Config[Copy_u8LedName].Pin,MPORT_enuHIGH);
			}
			else
			{
				DIO_enuSetPinValue(LEDS_Config[Copy_u8LedName].Port,LEDS_Config[Copy_u8LedName].Pin,MPORT_enuLOW);
			}
		}
		else if((LEDS_Config[Copy_u8LedName].ActiveMode) == HLED_enuActiveLow)
		{
			if(LEDS_Config[Copy_u8LedName].State == HLED_enuON)
			{
				DIO_enuSetPinValue(LEDS_Config[Copy_u8LedName].Port,LEDS_Config[Copy_u8LedName].Pin,MPORT_enuLOW);
			}
			else
			{
				DIO_enuSetPinValue(LEDS_Config[Copy_u8LedName].Port,LEDS_Config[Copy_u8LedName].Pin,MPORT_enuHIGH);
			}
		}
		else
		{
			Ret_enuLedsErrorStatus = HLED_enuInvalidActivestate;
		}
	}
	else
	{
		Ret_enuLedsErrorStatus = HLED_enuInvalidLed;
	}		
	return Ret_enuLedsErrorStatus;
}
