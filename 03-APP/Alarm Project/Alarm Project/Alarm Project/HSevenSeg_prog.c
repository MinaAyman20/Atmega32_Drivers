#include "STD_TYPES.h"
#include "Bit_Math.h"

#include "HSevenSeg_init.h"
#include "HSevenSeg_config.h"
#include "HSevenSeg_priv.h"

#include "MPort_Interface.h"
#include "DIO.h"

extern HSEVENSEG_strSevenSegConfigration SEVENSEG_Config[NUMBER_OF_SEVENSEG];

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuInit(void)
{
    HSEVENSEG_enuErrorStatus_t Ret_enu7SegErrorStatus = HSEVENSEG_enuOK;
    MPORT_strConfig_t LOC_strCurren7Seg;
    u8 volatile LOC_u8Counter=0;
  for(LOC_u8Counter=0; LOC_u8Counter < NUMBER_OF_SEVENSEG; LOC_u8Counter++)  
  {
     if((SEVENSEG_Config[LOC_u8Counter].ConnectionType  == HSEVENSEG_enuCommonCathod) ||  (SEVENSEG_Config [LOC_u8Counter].ConnectionType  == HSEVENSEG_enuCommonAnode))
     {
      /*******************************************LED1************************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led1.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led1.PinNum ;
        
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /*************************************************LED2*******************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led2.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led2.PinNum ;
        
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);

      /************************************************LED3*********************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led3.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led3.PinNum ;

         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /************************************************LED4*********************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led4.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led4.PinNum ;
         
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /************************************************LED5*********************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led5.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led5.PinNum ;
         
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /************************************************LED6*********************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led6.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led6.PinNum ;
         
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /************************************************LED7*********************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Led7.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Led7.PinNum ;
         
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /************************************************Dot*********************************************************************/
        LOC_strCurren7Seg.Port = SEVENSEG_Config[LOC_u8Counter].Dot.PortNum;
        LOC_strCurren7Seg.Pin  = SEVENSEG_Config[LOC_u8Counter].Dot.PinNum ;
         
         if(SEVENSEG_Config[LOC_u8Counter].ConnectionType == HSEVENSEG_enuCommonCathod)
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_LOW;
        }
        else
        {
            LOC_strCurren7Seg.Mode = MPORT_enu_OUTPUT_HIGH;
        }
          
           MPORT_enuSetConfig(&LOC_strCurren7Seg);
      /************************************************EndOfLeds****************************************************************/     
     }
     
     else
     {
       Ret_enu7SegErrorStatus = HSEVENSEG_enuConnectionTypeError;
     }
  }
    return Ret_enu7SegErrorStatus ;
}
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetCustomizeValue(u8 Copy_enuSevenSegNum , u32 Copy_u32Value)
{
  HSEVENSEG_enuErrorStatus_t Ret_enu7SegErrorStatus = HSEVENSEG_enuOK;

  if(Copy_enuSevenSegNum > NUMBER_OF_SEVENSEG )
  {
    Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegNumError;
  }
  else
  {
       //HSEVENSEG_strSevenSegConfigration  *LOC_CurrentSeg = &SEVENSEG_Config[Copy_enuSevenSegNum];

       if((SEVENSEG_Config[Copy_enuSevenSegNum] .ConnectionType == HSEVENSEG_enuCommonCathod) || (SEVENSEG_Config[Copy_enuSevenSegNum] .ConnectionType == HSEVENSEG_enuCommonAnode))
       {
           switch(Copy_u32Value)
           {
            case 0:

            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuLOW);
            
            break;
            case 1 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuLOW);
            
            break;
            
            case 2 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;
            
            case 3 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;

            case 4 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;
            
            case 5 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;

            case 6 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;

            case 7 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuLOW);
            break;

            case 8 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;

            case 9 :
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led1.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led2.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led3.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led4.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led5.PinNum,MPORT_enuLOW);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led6.PinNum,MPORT_enuHIGH);
            DIO_enuSetPinValue(SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PortNum,SEVENSEG_Config[Copy_enuSevenSegNum] .Led7.PinNum,MPORT_enuHIGH);
            break;  

            default: Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegLimitError;                   break;
           }
       }
       else
       {
          Ret_enu7SegErrorStatus = HSEVENSEG_enuConnectionTypeError;
       }
  }
  return Ret_enu7SegErrorStatus; 
}

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetDirectValue(u32 Copy_u32Value)
{
  HSEVENSEG_enuErrorStatus_t Ret_enu7SegErrorStatus = HSEVENSEG_enuNOK;

  if(Copy_u32Value>9999)
  {
    Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegLimitError;
  }
  #if   NUMBER_OF_SEVENSEG == 1
  if(Copy_u32Value>9)
  {
    Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegLimitError;
  }
  else
  {
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum1,Copy_u32Value);
  }

  #elif NUMBER_OF_SEVENSEG == 2
  u8 LOC_u8Digit1=0;
  u8 LOC_u8Digit2=0;
  if(Copy_u32Value>99)
  {
    Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegLimitError;
  }
  else
  {
    LOC_u8Digit2 = Copy_u32Value % 10 ;
    Copy_u32Value /= 10 ;
    LOC_u8Digit1=Copy_u32Value;

    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum1,LOC_u8Digit1);
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum2,LOC_u8Digit2);
  }


  #elif NUMBER_OF_SEVENSEG == 3
   u8 LOC_u8Digit1=0;
   u8 LOC_u8Digit2=0;
   u8 LOC_u8Digit3=0;
  if(Copy_u32Value>999)
  {
    Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegLimitError;
  }
  else
  {
    LOC_u8Digit3 = Copy_u32Value % 10 ;
    Copy_u32Value /= 10 ;
    LOC_u8Digit2 = Copy_u32Value % 10 ;
    Copy_u32Value /= 10 ;
    LOC_u8Digit1 =Copy_u32Value; 
    
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum1,LOC_u8Digit1);
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum2,LOC_u8Digit2);
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum3,LOC_u8Digit3);
  }
  
  #elif NUMBER_OF_SEVENSEG == 4
  u8 LOC_u8Digit1=0;
  u8 LOC_u8Digit2=0;
  u8 LOC_u8Digit3=0;
  u8 LOC_u8Digit4=0;

  if(Copy_u32Value>9999)
  {
    Ret_enu7SegErrorStatus = HSEVENSEG_enuSevenSegLimitError;
  }
  else
  {
    LOC_u8Digit4 = Copy_u32Value % 10 ;
    Copy_u32Value /= 10 ;
    LOC_u8Digit3 = Copy_u32Value % 10 ;
    Copy_u32Value /= 10 ;
    LOC_u8Digit2 = Copy_u32Value % 10 ; 
    Copy_u32Value /= 10 ;
    LOC_u8Digit1 = Copy_u32Value ;
    
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum1,LOC_u8Digit1);
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum2,LOC_u8Digit2);
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum3,LOC_u8Digit3);
    HSEVENSEG_enuSetCustomizeValue(HSEVENSEG_enuSevenSegNum4,LOC_u8Digit4);
   
    
    
    
    
    
  }
  #else 

  #endif
  
return Ret_enu7SegErrorStatus;
  

}