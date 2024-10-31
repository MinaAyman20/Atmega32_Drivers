/************************************************************************************************************************/
/*File          :       HSWITCH_CONFIG.c                                                                                */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       11/12/2023                                                                                      */
/*SWC           :       Switch                                                                                          */
/************************************************************************************************************************/

#include "HSWITCH_init.h"
#include "MPort_Interface.h"
#include "HSWITCH_config.h"

HSWITCH_enuSwitch_t SWITCHES_Config[NUMBER_OF_SWITCHES] =
{

[ CounterUp_Switch]=
{ 
    .Port           = MPORT_enuPort_A,
    .Pin            = MPORT_enuPin_0,
    .Connectiontype = HSWITCH_enuPULLUP
    
},
[CounterDown_Switch]=
{
    .Port           = MPORT_enuPort_A,
    .Pin            = MPORT_enuPin_2,
    .Connectiontype = HSWITCH_enuPULLUP
},
[Start_Switch]=
{
    .Port           = MPORT_enuPort_A,
    .Pin            = MPORT_enuPin_4,
    .Connectiontype = HSWITCH_enuPULLUP
}

};