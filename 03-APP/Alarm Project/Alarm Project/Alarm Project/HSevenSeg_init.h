/*************************************************************************************************************************************/
/*File          :       HSevenSeg_init.h                                                                                             */
/*Author        :       Mina Ayman                                                                                                   */
/*Date          :       16/12/2023                                                                                                   */
/*SWC           :       Seven Segment                                                                                                */
/*************************************************************************************************************************************/
#ifndef HSEVENSEG_INIT_H_
#define HSEVENSEG_INIT_H_

#include "STD_TYPES.h"
#include "MPort_Interface.h"

#define  HSEVENSEG_enuSevenSegNum1    0
#define  HSEVENSEG_enuSevenSegNum2    1
#define  HSEVENSEG_enuSevenSegNum3    2
#define  HSEVENSEG_enuSevenSegNum4    3  


typedef enum
{
 HSEVENSEG_enuOK,
 HSEVENSEG_enuPortError,
 HSEVENSEG_enuPinError,
 HSEVENSEG_enuConnectionTypeError,
 HSEVENSEG_enuSevenSegNumError,
 HSEVENSEG_enuSevenSegLimitError,
 HSEVENSEG_enuNOK
}HSEVENSEG_enuErrorStatus_t;

typedef enum
{
 HSEVENSEG_enuCommonCathod,
 HSEVENSEG_enuCommonAnode
}HSEVENSEG_enuConnectionType_t;


typedef struct 
{
   MPORT_enuPORT_OPTS_t  PortNum;
   MPORT_enuPIN_OPTS_t   PinNum;
} HSEVENSEG_strLedConfigration; 

typedef struct 
{ 
    HSEVENSEG_strLedConfigration Led1;
    HSEVENSEG_strLedConfigration Led2;
    HSEVENSEG_strLedConfigration Led3;
    HSEVENSEG_strLedConfigration Led4;
    HSEVENSEG_strLedConfigration Led5;
    HSEVENSEG_strLedConfigration Led6;
    HSEVENSEG_strLedConfigration Led7;
    HSEVENSEG_strLedConfigration Dot ;

    HSEVENSEG_enuConnectionType_t ConnectionType;

} HSEVENSEG_strSevenSegConfigration; 



HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuInit(void);
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetCustomizeValue(u8 Copy_enuSevenSegNum , u32 Copy_u32Value);
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetDirectValue(u32 Copy_u32Value);




#endif