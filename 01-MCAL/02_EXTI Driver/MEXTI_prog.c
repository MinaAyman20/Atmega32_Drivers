#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"

#include "MEXTI_interface.h"
#include "MEXTI_config.h"
#include "MEXTI_priv.h"

/*Global pointer to function for INT0 ISR */
void (*EXIT_pfvEXTI0Func)(void)=NULL;

/*Global pointer to function for INT1 ISR */
void (*EXIT_pfvEXTI1Func)(void)=NULL;

/*Global pointer to function for INT2 ISR */
void (*EXIT_pfvEXTI2Func)(void)=NULL;


MEXTI_enuErrorStatus_t MEXTI_enuInit(void)
{
	u8 volatile LOC_u8EXTIRegValue = 0;
	//To Enable Global Interupt
	  SET_BIT(SREG,7);
   MEXTI_enuErrorStatus_t Ret_enuEXTI_ErrorStatus = MEXTI_enuOK;
   #if   MEXTI_INT0 == MEXTI_ENABLE

        //Check if the Sense Control of the EXTI is Valid
    if((MEXTI_INT0_SENSECONTROL == MEXTI_INT0_LOWLEVEL    ) || (MEXTI_INT0_SENSECONTROL == MEXTI_INT0_ONCHANGE )||\
       (MEXTI_INT0_SENSECONTROL == MEXTI_INT0_FALLINGEDGE ) || (MEXTI_INT0_SENSECONTROL == MEXTI_INT0_RISINGEDGE))
      {
    	LOC_u8EXTIRegValue  =  MCUCR;
    	LOC_u8EXTIRegValue &= MCUCR_INT0_CLEAR_MASK;
    	LOC_u8EXTIRegValue |= MEXTI_INT0_SENSECONTROL ;
        MCUCR = LOC_u8EXTIRegValue;

           //To Enable peripheral Interupt
             SET_BIT(GICR,6);

       }
       else
       {
        Ret_enuEXTI_ErrorStatus = MEXTI_enuSenceControlError;
       }
#endif


   #if MEXTI_INT1 == MEXTI_ENABLE

        //Check if the Sense Control of the EXTI is Valid
    if((MEXTI_INT1_SENSECONTROL == MEXTI_INT1_LOWLEVEL    ) || (MEXTI_INT1_SENSECONTROL == MEXTI_INT1_ONCHANGE )||\
       (MEXTI_INT1_SENSECONTROL == MEXTI_INT1_FALLINGEDGE ) || (MEXTI_INT1_SENSECONTROL == MEXTI_INT1_RISINGEDGE))
       {
           LOC_u8EXTIRegValue =  MCUCR;
           LOC_u8EXTIRegValue &= MCUCR_INT1_CLEAR_MASK;
           LOC_u8EXTIRegValue |= MEXTI_INT1_SENSECONTROL ;
           MCUCR = LOC_u8EXTIRegValue;

        //To Enable peripheral Interupt
             SET_BIT(GICR,7);
             //To Enable Global Interupt
             //SET_BIT(SREG,7);
       }
       else
       {
        Ret_enuEXTI_ErrorStatus = MEXTI_enuSenceControlError;
       }
     #endif

   #if MEXTI_INT2 == MEXTI_ENABLE

        //Check if the Sense Control of the EXTI is Valid
    if((MEXTI_INT2_SENSECONTROL == MEXTI_INT2_FALLINGEDGE)|| \
       (MEXTI_INT2_SENSECONTROL == MEXTI_INT2_RISINGEDGE))
       {
    	u8 volatile LOC_u8EXTI2RegValue=0;
           LOC_u8EXTI2RegValue =  MCUCSR;
           LOC_u8EXTI2RegValue &= MCUCSR_INT2_CLEAR_MASK;
           LOC_u8EXTI2RegValue |= MEXTI_INT2_SENSECONTROL;
           MCUCSR =  LOC_u8EXTI2RegValue;

        //To Enable peripheral Interupt
        SET_BIT(GICR,5);
       }
       else
       {
        Ret_enuEXTI_ErrorStatus = MEXTI_enuSenceControlError;
       }

   #endif
    return Ret_enuEXTI_ErrorStatus;
}

MEXTI_enuErrorStatus_t MEXTI_enuSetCallbackEXTI0(void (*Copy_pfvEXTI0Func)(void))
{
   MEXTI_enuErrorStatus_t Ret_enuEXTI_ErrorStatus = MEXTI_enuOK;
   if(Copy_pfvEXTI0Func == NULL)
   {
       Ret_enuEXTI_ErrorStatus = MEXTI_enuNullPointerError;
   }
   else
   {
     EXIT_pfvEXTI0Func = Copy_pfvEXTI0Func;
   }
     return Ret_enuEXTI_ErrorStatus;
}

MEXTI_enuErrorStatus_t MEXTI_enuSetCallbackEXTI1(void (*Copy_pfvEXTI1Func)(void))
{
   MEXTI_enuErrorStatus_t Ret_enuEXTI_ErrorStatus = MEXTI_enuOK;
   if(Copy_pfvEXTI1Func == NULL)
   {
       Ret_enuEXTI_ErrorStatus = MEXTI_enuNullPointerError;
   }
   else
   {
     EXIT_pfvEXTI1Func = Copy_pfvEXTI1Func;
   }
      return Ret_enuEXTI_ErrorStatus;
}

MEXTI_enuErrorStatus_t MEXTI_enuSetCallbackEXTI2(void (*Copy_pfvEXTI2Func)(void))
{
   MEXTI_enuErrorStatus_t Ret_enuEXTI_ErrorStatus = MEXTI_enuOK;
   if(Copy_pfvEXTI2Func == NULL)
   {
       Ret_enuEXTI_ErrorStatus = MEXTI_enuNullPointerError;
   }
   else
   {
     EXIT_pfvEXTI2Func = Copy_pfvEXTI2Func;
   }
      return Ret_enuEXTI_ErrorStatus;
}
/*****************************************************************************************************************/
/*EXTI0 ISR*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXIT_pfvEXTI0Func!=NULL)
	{
		EXIT_pfvEXTI0Func();
	}
	else
	{
		/*do nothing*/
	}

}
/********************************************************************************************************************/
/*EXTI1 ISR*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXIT_pfvEXTI1Func!=NULL)
	{
		EXIT_pfvEXTI1Func();
	}
	else
	{
		/*do nothing*/
	}

}
/********************************************************************************************************************/
/*EXTI2 ISR*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXIT_pfvEXTI2Func!=NULL)
	{
		EXIT_pfvEXTI2Func();
	}
	else
	{
		/*do nothing*/
	}

}
/****************************************************************************************************************/
