/************************************************************************************************************************/
/*File          :       HLED_init.h                                                                                     */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       11/12/2023                                                                                      */
/*SWC           :       LED                                                                                             */
/************************************************************************************************************************/

#ifndef HLED_INIT_H_
#define HLED_INIT_H_

#include "STD_TYPES.h"


#define LED_ONE    0
#define LED_TWO    1
#define LED_THREE  2
#define LED_FOUR   3

typedef enum
{
 HLED_enuOK,
 HLED_enuDIOError,
 HLED_enuInvalidActivestate,
 HLED_enuInvalidLed,
 HLED_enuInvalidState,
 HLED_enuNOK
}HLED_enuErrorStatus_t;

typedef enum
{

 HLED_enuActiveLow,
 HLED_enuActiveHigh
 
}HLED_enuActiveState_t;

typedef enum
{
 HLED_enuOFF,
 HLED_enuON

}HLED_enuState_t;

typedef struct
{
	u8  Port;
	u8  Pin;
	HLED_enuActiveState_t ActiveMode;
	HLED_enuState_t       State;

}HLED_strLED_t;


HLED_enuErrorStatus_t HLED_enuInit(void);
HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedName,  HLED_enuState_t Copy_u8State);


















#endif