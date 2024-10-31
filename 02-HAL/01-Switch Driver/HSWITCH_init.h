/************************************************************************************************************************/
/*File          :       HSWITCH_INIT.h                                                                                  */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       11/12/2023                                                                                      */
/*SWC           :       Switch                                                                                          */
/************************************************************************************************************************/

#ifndef HSWITCH_INIT_H_
#define HSWITCH_INIT_H_

#include "STD_TYPES.h"
#include "MPort_Interface.h"



#define  CounterUp_Switch      0
#define  CounterDown_Switch    1
#define  Start_Switch          2


typedef enum
{
 HSWITCH_enuOK,
 HSWITCH_enuDIOError,
 HSWITCH_enuInvalidConnection,
 HSWITCH_enuInvalidSwitchNum,
 HSWITCH_enuNOK
 
}HSWITCH_enuErrorStatus_t;

typedef enum
{
 HSWITCH_enuPULLUP,
 HSWITCH_enuPULLDOWN
 
}HSWITCH_enuConnection_t;


typedef enum{
	HSWITCH_enuReleased ,
	HSWITCH_enuPressed 
}HSWITCH_enuState_t;

typedef struct
{
  MPORT_enuPORT_OPTS_t Port;
  MPORT_enuPIN_OPTS_t Pin ;
  HSWITCH_enuConnection_t Connectiontype;
  HSWITCH_enuState_t State;

}HSWITCH_enuSwitch_t;


HSWITCH_enuErrorStatus_t HSWITCH_enuInit(void);

HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, HSWITCH_enuState_t* Add_u8State);


#endif