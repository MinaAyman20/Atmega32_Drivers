/************************************************************************************************************************/
/*File          :       HSWITCH_PROG.c                                                                                  */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       11/12/2023                                                                                      */
/*SWC           :       Switch                                                                                          */
/************************************************************************************************************************/
#include "STD_TYPES.h"
#include "Bit_Math.h"

#include "MPort_Interface.h"
#include "DIO.h"

#include "HSWITCH_init.h"
#include "HSWITCH_config.h"
#include "HSWITCH_priv.h"

extern HSWITCH_enuSwitch_t SWITCHES_Config[NUMBER_OF_SWITCHES] ;

HSWITCH_enuErrorStatus_t HSWITCH_enuInit(void)
{
    int i =0 ;
  HSWITCH_enuErrorStatus_t Ret_enuSwitchErrorStatus = HSWITCH_enuOK;
  
  MPORT_strConfig_t LOC_strCurrentSwitch;
  for(i = 0 ; i < NUMBER_OF_SWITCHES ; i++)
  {
    if((SWITCHES_Config[i].Connectiontype == HSWITCH_enuPULLDOWN) || (SWITCHES_Config[i].Connectiontype == HSWITCH_enuPULLUP))
    {
        LOC_strCurrentSwitch.Port =  SWITCHES_Config[i].Port;
        LOC_strCurrentSwitch.Pin  =  SWITCHES_Config[i].Pin ;

        if(SWITCHES_Config[i].Connectiontype == HSWITCH_enuPULLDOWN)
        {
           LOC_strCurrentSwitch.Mode = MPORT_enu_INPUT_PD;
        }
        else if(SWITCHES_Config[i].Connectiontype == HSWITCH_enuPULLUP)
        {
           LOC_strCurrentSwitch.Mode =MPORT_enu_INPUT_PU;
        }
         if(MPORT_enuSetConfig(&LOC_strCurrentSwitch) )
        {
            Ret_enuSwitchErrorStatus  = HSWITCH_enuDIOError;
        }
    
    }
     else
        {
          Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection;
        }

  }
   return Ret_enuSwitchErrorStatus;
}

/*HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, HSWITCH_enuState_t* Add_u8State)
{
   HSWITCH_enuErrorStatus_t Ret_enuSwitchErrorStatus = HSWITCH_enuOK;
    if (Copy_u8SwitchName < NUMBER_OF_SWITCHES)
    {
        u8 * LOC_SwitchState = 0;
         Ret_enuSwitchErrorStatus = DIO_enuGetPinValue (SWITCHES_Config[Copy_u8SwitchName].Port,
                                                        SWITCHES_Config[Copy_u8SwitchName].Pin,
                                                        LOC_SwitchState);

        if((*LOC_SwitchState == 1) && (SWITCHES_Config[Copy_u8SwitchName].Connectiontype == HSWITCH_enuPULLDOWN) )
        {
            *Add_u8State =  HSWITCH_enuPressed;
        }
        else if((*LOC_SwitchState == 0) && (SWITCHES_Config[Copy_u8SwitchName].Connectiontype == HSWITCH_enuPULLUP) )
        {
            *Add_u8State =  HSWITCH_enuPressed;
        }
        else
        {
            *Add_u8State =  HSWITCH_enuReleased;
        }
        
    }
	return Ret_enuSwitchErrorStatus ;
}*/


HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, HSWITCH_enuState_t* Add_u8State)
{
   HSWITCH_enuErrorStatus_t Ret_enuSwitchErrorStatus = HSWITCH_enuOK;
    if (Copy_u8SwitchName < NUMBER_OF_SWITCHES)
    {
        u8 LOC_SwitchState = 0 ;
         Ret_enuSwitchErrorStatus = DIO_enuGetPinValue (SWITCHES_Config[Copy_u8SwitchName].Port,
                                                        SWITCHES_Config[Copy_u8SwitchName].Pin,
                                                        &LOC_SwitchState);

        if (SWITCHES_Config[Copy_u8SwitchName].Connectiontype == HSWITCH_enuPULLUP)
        {
            if (LOC_SwitchState == DIO_enuLow)
            {
                *Add_u8State = HSWITCH_enuPressed;
            }
            else if (LOC_SwitchState == DIO_enuHigh)
            {
                *Add_u8State = HSWITCH_enuReleased;
            }
            else
            {
                Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection; 
            }
        }
        else if (SWITCHES_Config[Copy_u8SwitchName].Connectiontype == HSWITCH_enuPULLDOWN)
        {
            if (LOC_SwitchState == DIO_enuHigh)
            {
                *Add_u8State = HSWITCH_enuPressed;
            }
            else if (LOC_SwitchState == DIO_enuLow)
            {
                *Add_u8State = HSWITCH_enuReleased;
            }
            else
            {
                Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection; 
            }
        }
        else
        {
            Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection;
        }
    }
    else
    {
        Ret_enuSwitchErrorStatus= HSWITCH_enuInvalidSwitchNum;
    }

    return Ret_enuSwitchErrorStatus;
}

/*HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, HSWITCH_enuState_t* Add_u8State)
{
    HSWITCH_enuErrorStatus_t Ret_enuSwitchErrorStatus = HSWITCH_enuOK;

    if (Copy_u8SwitchName < NUMBER_OF_SWITCHES)
    {
        u8 LOC_SwitchState;
        Ret_enuSwitchErrorStatus = DIO_enuGetPinValue(SWITCHES_Config[Copy_u8SwitchName].Port,
                                                      SWITCHES_Config[Copy_u8SwitchName].Pin,
                                                      &LOC_SwitchState);

        if (SWITCHES_Config[Copy_u8SwitchName].Connectiontype == HSWITCH_enuPULLUP)
        {
            *Add_u8State = (LOC_SwitchState == DIO_enuLow) ? HSWITCH_enuPressed : HSWITCH_enuReleased;
        }
        else if (SWITCHES_Config[Copy_u8SwitchName].Connectiontype == HSWITCH_enuPULLDOWN)
        {
            *Add_u8State = (LOC_SwitchState == DIO_enuHigh) ? HSWITCH_enuPressed : HSWITCH_enuReleased;
        }
        else
        {
            Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidConnection;
        }
    }
    else
    {
        Ret_enuSwitchErrorStatus = HSWITCH_enuInvalidSwitchNum;
    }

    return Ret_enuSwitchErrorStatus;
}*/

/*HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, HSWITCH_enuState_t* Add_u8State)
{
    if (Copy_u8SwitchName < NUMBER_OF_SWITCHES)
    {
        u8 LOC_SwitchState;
        HSWITCH_enuConnection_t switchType = SWITCHES_Config[Copy_u8SwitchName].Connectiontype;

        if (DIO_enuGetPinValue(SWITCHES_Config[Copy_u8SwitchName].Port, SWITCHES_Config[Copy_u8SwitchName].Pin, &LOC_SwitchState) == DIO_enu_OK  )
        {
            if ((switchType == HSWITCH_enuPULLUP && LOC_SwitchState == DIO_enuLow) ||
                (switchType == HSWITCH_enuPULLDOWN && LOC_SwitchState == DIO_enuHigh))
            {
                *Add_u8State = HSWITCH_enuPressed;
            }
            else if ((switchType == HSWITCH_enuPULLUP && LOC_SwitchState == DIO_enuHigh) ||
                     (switchType == HSWITCH_enuPULLDOWN && LOC_SwitchState == DIO_enuLow))
            {
                *Add_u8State = HSWITCH_enuReleased;
            }
            else
            {
                return HSWITCH_enuInvalidConnection;
            }
        }
        else
        {
            return HSWITCH_enuDIOError;
        }
    }
    else
    {
        return HSWITCH_enuInvalidSwitchNum;
    }

    return HSWITCH_enuOK;
}*/

