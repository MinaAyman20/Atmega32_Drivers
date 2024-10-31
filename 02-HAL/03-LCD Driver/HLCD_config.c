/************************************************************************************************************************/
/*File          :       HLCD_config.c                                                                                     */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/

#include "HLCD_interface.h"
#include "../../MCAL/01-PORT/MPort_Interface.h"

 HLCD_strLCDPinConfigration LCD_Config= {
.DATABIT0 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_0},
.DATABIT1 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_1},
.DATABIT2 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_2},
.DATABIT3 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_3},
.DATABIT4 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_4},
.DATABIT5 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_5},
.DATABIT6 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_6},
.DATABIT7 = {.PortNum = MPORT_enuPort_D, .PinNum = MPORT_enuPin_7},
.ENABLE   = {.PortNum = MPORT_enuPort_C, .PinNum = MPORT_enuPin_0},
.RS       = {.PortNum = MPORT_enuPort_C, .PinNum = MPORT_enuPin_1},
.RW       = {.PortNum = MPORT_enuPort_C, .PinNum = MPORT_enuPin_2},


 };
