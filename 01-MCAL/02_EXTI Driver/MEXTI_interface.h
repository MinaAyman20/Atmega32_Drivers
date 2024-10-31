/************************************************************************************************************************/
/*File          :       MEXTI_interface.h                                                                                   */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       24/12/2023                                                                                      */
/*SWC           :       EXTI                                                                                            */
/************************************************************************************************************************/

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

#define MEXTI_DISABLE 0
#define MEXTI_ENABLE  1



typedef enum
{
    MEXTI_enuOK,
    MEXTI_enuSenceControlError,
    MEXTI_enuNullPointerError,
    MEXTI_enuNOK,

}MEXTI_enuErrorStatus_t;


MEXTI_enuErrorStatus_t MEXTI_enuInit(void);
MEXTI_enuErrorStatus_t MEXTI_enuSetCallbackEXTI0(void (*Copy_pfvEXTI0Func)(void));
MEXTI_enuErrorStatus_t MEXTI_enuSetCallbackEXTI1(void (*Copy_pfvEXTI1Func)(void));
MEXTI_enuErrorStatus_t MEXTI_enuSetCallbackEXTI2(void (*Copy_pfvEXTI2Func)(void));

#endif
