#include "STD_TYPES.h"
#include "HLED_init.h"
#include "MPort_Interface.h"
#include "HLED_config.h"


HLED_strLED_t LEDS_Config[NUMBER_OF_LEDS] =
{
  [LED_ONE]=
  {
    .Port       = MPORT_enuPort_A,
    .Pin        = MPORT_enuPin_6,
    .ActiveMode = HLED_enuActiveHigh,
    .State      = HLED_enuOFF
  }
   /*[LED_TWO]=
  {
    .Port       = MPORT_enuPort_A,
    .Pin        = MPORT_enuPin_1,
    .ActiveMode = HLED_enuActiveHigh,
    .State      = HLED_enuOFF
  },
   [LED_THREE]=
  {
    .Port       = MPORT_enuPort_A,
    .Pin        = MPORT_enuPin_2,
    .ActiveMode = HLED_enuActiveHigh,
    .State      = HLED_enuOFF
  },
   [LED_FOUR]=
  {
    .Port       = MPORT_enuPort_A,
    .Pin        = MPORT_enuPin_3,
    .ActiveMode = HLED_enuActiveHigh,
    .State      = HLED_enuOFF
  }*/
  
};
