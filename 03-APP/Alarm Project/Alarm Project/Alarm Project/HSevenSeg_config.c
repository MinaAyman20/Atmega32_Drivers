#include "HSevenSeg_init.h"
#include "Mport_interface.h"
#include "HSevenSeg_config.h"

HSEVENSEG_strSevenSegConfigration SEVENSEG_Config[NUMBER_OF_SEVENSEG] =
{
 
 [HSEVENSEG_enuSevenSegNum1] =
 {
    .Led1.PortNum=MPORT_enuPort_C,
    .Led1.PinNum=MPORT_enuPin_0  ,

    .Led2.PortNum=MPORT_enuPort_C,
    .Led2.PinNum=MPORT_enuPin_1  ,
     
    .Led3.PortNum=MPORT_enuPort_C,
    .Led3.PinNum=MPORT_enuPin_2  ,

    .Led4.PortNum=MPORT_enuPort_C,
    .Led4.PinNum=MPORT_enuPin_3  ,
   
    .Led5.PortNum=MPORT_enuPort_C,
    .Led5.PinNum=MPORT_enuPin_4  ,

    .Led6.PortNum=MPORT_enuPort_C,
    .Led6.PinNum=MPORT_enuPin_5  ,
     
    .Led7.PortNum=MPORT_enuPort_C,
    .Led7.PinNum=MPORT_enuPin_6  ,

    .Dot.PortNum=MPORT_enuPort_C,
    .Dot.PinNum=MPORT_enuPin_7  ,

    .ConnectionType = HSEVENSEG_enuCommonCathod
 },

[HSEVENSEG_enuSevenSegNum2] =
 {
    .Led1.PortNum=MPORT_enuPort_D,
    .Led1.PinNum=MPORT_enuPin_0  ,

    .Led2.PortNum=MPORT_enuPort_D,
    .Led2.PinNum=MPORT_enuPin_1  ,
     
    .Led3.PortNum=MPORT_enuPort_D,
    .Led3.PinNum=MPORT_enuPin_2  ,

    .Led4.PortNum=MPORT_enuPort_D,
    .Led4.PinNum=MPORT_enuPin_3  ,
   
    .Led5.PortNum=MPORT_enuPort_D,
    .Led5.PinNum=MPORT_enuPin_4  ,

    .Led6.PortNum=MPORT_enuPort_D,
    .Led6.PinNum=MPORT_enuPin_5  ,
     
    .Led7.PortNum=MPORT_enuPort_D,
    .Led7.PinNum=MPORT_enuPin_6  ,

    .Dot.PortNum=MPORT_enuPort_D,
    .Dot.PinNum=MPORT_enuPin_7  ,

    .ConnectionType = HSEVENSEG_enuCommonCathod
 }

 /*[HSEVENSEG_enuSevenSegNum3] =
 {
    .Led1.PortNum=MPORT_enuPort_C,
    .Led1.PinNum=MPORT_enuPin_0  ,

    .Led2.PortNum=MPORT_enuPort_C,
    .Led2.PinNum=MPORT_enuPin_1  ,
     
    .Led3.PortNum=MPORT_enuPort_C,
    .Led3.PinNum=MPORT_enuPin_2  ,

    .Led4.PortNum=MPORT_enuPort_C,
    .Led4.PinNum=MPORT_enuPin_3  ,
   
    .Led5.PortNum=MPORT_enuPort_C,
    .Led5.PinNum=MPORT_enuPin_4  ,

    .Led6.PortNum=MPORT_enuPort_C,
    .Led6.PinNum=MPORT_enuPin_5  ,
     
    .Led7.PortNum=MPORT_enuPort_C,
    .Led7.PinNum=MPORT_enuPin_6  ,

    .Dot.PortNum=MPORT_enuPort_C,
    .Dot.PinNum=MPORT_enuPin_7  ,

    .ConnectionType = HSEVENSEG_enuCommonCathod
 },
 
 [HSEVENSEG_enuSevenSegNum4] =
 {
    .Led1.PortNum=MPORT_enuPort_D,
    .Led1.PinNum=MPORT_enuPin_0  ,

    .Led2.PortNum=MPORT_enuPort_D,
    .Led2.PinNum=MPORT_enuPin_1  ,
     
    .Led3.PortNum=MPORT_enuPort_D,
    .Led3.PinNum=MPORT_enuPin_2  ,

    .Led4.PortNum=MPORT_enuPort_D,
    .Led4.PinNum=MPORT_enuPin_3  ,
   
    .Led5.PortNum=MPORT_enuPort_D,
    .Led5.PinNum=MPORT_enuPin_4  ,

    .Led6.PortNum=MPORT_enuPort_D,
    .Led6.PinNum=MPORT_enuPin_5  ,
     
    .Led7.PortNum=MPORT_enuPort_D,
    .Led7.PinNum=MPORT_enuPin_6  ,

    .Dot.PortNum=MPORT_enuPort_D,
    .Dot.PinNum=MPORT_enuPin_7  ,

    .ConnectionType = HSEVENSEG_enuCommonCathod
 }*/
};