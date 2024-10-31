/*
 * MTIMERS_prog.c
 *
 *  Created on: Jan 14, 2024
 *      Author: Mina
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"
#include "MTIMERS_interface.h"
#include "MTIMERS_priv.h"
#include "MTIMERS_config.h"

/*Global pointer to function for TIMER0 ISR */
void (*TIMER_pfvTIMER0Func)(void)=NULL;

/*Global pointer to function for TIMER1 ISR */
void (*TIMER_pfvTIMER1Func)(void)=NULL;

/*Global pointer to function for TIMER2 ISR */
void (*TIMER_pfvTIMER2Func)(void)=NULL;

/*COUNTER FOR ISR FUNCTION*/
u8 ISR_Counter = 0;
/*COUNTER FOR TIMER0 CTC ISR FUNCTION*/
u16 TIMER0_CTC_ISR_COUNTER = 0;

/*COUNTER FOR TIMER0 CTC ISR FUNCTION*/
u16 TIMER1_CTC_ISR_COUNTER = 0;

/*COUNTER FOR TIMER2 CTC ISR FUNCTION*/
u16 TIMER2_CTC_ISR_COUNTER = 0;
/*Global Variable to save value of timer 0*/
u8 TIMER0_VALUE = 0 ;

/*Global Variable to save value of timer 1*/
u16 TIMER1_VALUE = 0 ;

/*Global Variable to save value of timer 2*/
u8 TIMER2_VALUE = 0 ;

MTIMERS_enuErrorStatus_t MTIMERS_enuInit(void)
{
	/* Initialize a variable to hold the value of TCCR0 register */
	u8 LOC_u8TIMERRegValue = 0;

	/* Initialize a variable to store the status of timer initialization */
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;

	/* Check if TIMER0 is enabled */
#if MTIMER_TIMER0 == MTIMER_ENABLE

	/* Check the selected waveform generation mode for TIMER0 */
	if ((TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_NORMAL_MODE) || \
		(TIMER0_WAVEFORM_GENERATION_MODE ==  TIMER0_WAVEFORM_GENERATION_MODE_PHASE_CORRECT_MODE)    || \
		(TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_CTC_MODE)    || \
		(TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_FPWM_MODE))
	{
		/* Save the current value of TCCR0 */
		LOC_u8TIMERRegValue = TCCR0;

		/* Clear the waveform generation mode bits */
		LOC_u8TIMERRegValue &= TCCR0_TIMER0_WAVEFORM_GENERATION_MODE_CLEAR_MASK;

		/* Set the selected waveform generation mode for TIMER0 */
		LOC_u8TIMERRegValue |= TIMER0_WAVEFORM_GENERATION_MODE;

		/* Update TCCR0 with the new configuration */
		TCCR0 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected waveform generation mode is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_WAVEFORM_GENERATION_MODE_ERROR;
	}

	/* Check if the selected waveform generation mode is NORMAL_MODE */
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_NORMAL_MODE

	/* Check the selected compare match output mode for NORMAL_MODE */
	if ((TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_SET_OC0))
	{
		/* Save the current value of TCCR0 */
		LOC_u8TIMERRegValue = TCCR0;

		/* Clear the compare match output mode bits for NORMAL_MODE */
		LOC_u8TIMERRegValue &= TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for NORMAL_MODE */
		LOC_u8TIMERRegValue |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE;

		/* Update TCCR0 with the new configuration */
		TCCR0 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for NORMAL_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR;
	}
#endif

	/* Check if the selected waveform generation mode is CTC_MODE */
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_CTC_MODE

	/* Check the selected compare match output mode for CTC_MODE */
	if ((TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER0_COMPARE_MATCH_OUTPUT_MODE_SET_OC0))
	{
		/* Save the current value of TCCR0 */
		LOC_u8TIMERRegValue = TCCR0;

		/* Clear the compare match output mode bits for CTC_MODE */
		LOC_u8TIMERRegValue &= TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for CTC_MODE */
		LOC_u8TIMERRegValue |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE;

		/* Update TCCR0 with the new configuration */
		TCCR0 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for CTC_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR;
	}
#endif


	/* Check if the selected waveform generation mode is PWM_MODE */
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_PHASE_CORRECT_MODE

	/* Check the selected compare match output mode for PWM_MODE */
	if ((TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE== TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NON_INVERTING_ON_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_INVERTING_ON_OC0))
	{
		/* Save the current value of TCCR0 */
		LOC_u8TIMERRegValue = TCCR0;

		/* Clear the compare match output mode bits for PWM_MODE */
		LOC_u8TIMERRegValue &= TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for PWM_MODE */
		LOC_u8TIMERRegValue |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE;

		/* Update TCCR0 with the new configuration */
		TCCR0 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for PWM_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR;
	}
#endif


	/* Check if the selected waveform generation mode is FPWM_MODE */
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_FPWM_MODE

	/* Check the selected compare match output mode for FPWM_MODE */
	if ((TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NON_INVERTING_ON_OC0) || \
			(TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_INVERTING_ON_OC0))
	{
		/* Save the current value of TCCR0 */
		LOC_u8TIMERRegValue = TCCR0;

		/* Clear the compare match output mode bits for FPWM_MODE */
		LOC_u8TIMERRegValue &= TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for FPWM_MODE */
		LOC_u8TIMERRegValue |= TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE;

		/* Update TCCR0 with the new configuration */
		TCCR0 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for FPWM_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR;

	}

#endif
#endif

#if MTIMER_TIMER1 == MTIMER_ENABLE
	u16 LOC_u16TIMERRegValue=0;
	           /* Check the selected waveform generation mode for TIMER1 */
		if (    (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_NORMAL_MODE)                 || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_8BIT_MODE)               || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_9BIT_MODE)               || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_10BIT_MODE)              || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_CTC_MODE_OCR1A)              || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_FPWM_8BIT_MODE)              || \
			    (TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_FPWM_9BIT_MODE)              || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_FPWM_10BIT_MODE)             || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_FREQ_CORRECT_ICR1) || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_FREQ_CORRECT_OCR1A)|| \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_CORRECT_ICR1)      || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_CORRECT_OCR1A)     || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_CTC_MODE_ICR1)                || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_FPWM_MODE_ICR1)              || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_CTC_MODE)                    || \
				(TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_FPWM_MODE_OCR1A))


		{
			/* Save the current value of TCCR1 (u16) */
			LOC_u16TIMERRegValue = TCCR1;

			/* Clear the waveform generation mode bits */
			LOC_u16TIMERRegValue &= TCCR1_TIMER1_WAVEFORM_GENERATION_MODE_CLEAR_MASK;

			/* Set the selected waveform generation mode for TIMER0 */
			LOC_u16TIMERRegValue |= TIMER1_WAVEFORM_GENERATION_MODE;

			/* Update TCCR1 (u16) with the new configuration */
			TCCR1 = LOC_u16TIMERRegValue;
		}
		else
		{
			/* Set an error status if the selected waveform generation mode is invalid */
			Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_WAVEFORM_GENERATION_MODE_ERROR;
		}


		/* Check if the selected waveform generation mode is NORMAL_MODE */
	#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_NORMAL_MODE

		/* Check the selected compare match output mode for NORMAL_MODE */
		if ((TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A) || \
				(TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC1A)  || \
				(TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC1A)   || \
				(TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_OC1A))
		{
			/* Save the current value of TCCR1A (u8) */
			LOC_u8TIMERRegValue = TCCR1A;

			/* Clear the compare match output mode bits for NORMAL_MODE */
			LOC_u8TIMERRegValue &= TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

			/* Set the selected compare match output mode for NORMAL_MODE */
			LOC_u8TIMERRegValue |= TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE;

			/* Update TCCR1A (u8) with the new configuration */
			TCCR1A = LOC_u8TIMERRegValue;
		}
		else
		{
			/* Set an error status if the selected compare match output mode for NORMAL_MODE is invalid */
			Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR;
		}
	#endif


#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_WAVEFORM_GENERATION_MODE_CTC_MODE_OCR1A

	/* Check the selected compare match output mode for CTC_MODE */
	if ((TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_OC1A))
	{
		/* Save the current value of  TCCR1A (u8) */
		LOC_u8TIMERRegValue =  TCCR1A ;

		/* Clear the compare match output mode bits for CTC_MODE */
		LOC_u8TIMERRegValue &= TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for CTC_MODE */
		LOC_u8TIMERRegValue |= TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE;

		/* Update  TCCR1A (u8) with the new configuration */
		TCCR1A = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for CTC_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR;
	}
#endif

#if TIMER1_WAVEFORM_GENERATION_MODE ==  TIMER1_WAVEFORM_GENERATION_MODE_FPWM_MODE_OCR1A

		if ((TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_OC1A))
		{
			/* Save the current value of  TCCR1A (u8) */
			LOC_u8TIMERRegValue =  TCCR1A ;

			/* Clear the compare match output mode bits for FPWM_MODE */
			LOC_u8TIMERRegValue &= TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

			/* Set the selected compare match output mode for FPWM_MODE */
			LOC_u8TIMERRegValue |= TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE;

			/* Update  TCCR1A (u8) with the new configuration */
			TCCR1A = LOC_u8TIMERRegValue;
		}
		else
		{
			/* Set an error status if the selected compare match output mode for CTC_MODE is invalid */
			Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR;
		}

#endif

#if TIMER1_WAVEFORM_GENERATION_MODE ==  TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_CORRECT_OCR1A
		if ((TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_ON_UP_COUNTING_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_ON_UP_COUNTING_OC1A) || \
			(TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_ON_UP_COUNTING_OC1A))
		{
			/* Save the current value of  TCCR1A (u8) */
			LOC_u8TIMERRegValue =  TCCR1A ;

			/* Clear the compare match output mode bits for CTC_MODE */
			LOC_u8TIMERRegValue &= TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

			/* Set the selected compare match output mode for CTC_MODE */
			LOC_u8TIMERRegValue |= TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE;

			/* Update  TCCR1A (u8) with the new configuration */
			TCCR1A = LOC_u8TIMERRegValue;
		}
		else
		{
			/* Set an error status if the selected compare match output mode for CTC_MODE is invalid */
			Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE_ERROR;
		}

#endif
#endif

#if MTIMER_TIMER2 == MTIMER_ENABLE
	/* Check the selected waveform generation mode for TIMER2 */
	if ((TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_NORMAL_MODE) || \
			(TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_PWM_MODE) || \
			(TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_CTC_MODE) || \
			(TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_FPWM_MODE))
	{
		/* Save the current value of TCCR2 */
		LOC_u8TIMERRegValue = TCCR2;

		/* Clear the waveform generation mode bits */
		LOC_u8TIMERRegValue &= TCCR2_TIMER2_WAVEFORM_GENERATION_MODE_CLEAR_MASK;

		/* Set the selected waveform generation mode for TIMER0 */
		LOC_u8TIMERRegValue |= TIMER2_WAVEFORM_GENERATION_MODE;

		/* Update TCCR0 with the new configuration */
		TCCR2 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected waveform generation mode is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER2_WAVEFORM_GENERATION_MODE_ERROR;
	}

	/* Check if the selected waveform generation mode is NORMAL_MODE */
#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_NORMAL_MODE

	/* Check the selected compare match output mode for NORMAL_MODE */
	if ((TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2))
	{
		/* Save the current value of TCCR2 */
		LOC_u8TIMERRegValue = TCCR2;

		/* Clear the compare match output mode bits for NORMAL_MODE */
		LOC_u8TIMERRegValue &= TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for NORMAL_MODE */
		LOC_u8TIMERRegValue |= TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE;

		/* Update TCCR2 with the new configuration */
		TCCR2 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for NORMAL_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR;
	}
#endif

	/* Check if the selected waveform generation mode is CTC_MODE */
#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_CTC_MODE

	/* Check the selected compare match output mode for CTC_MODE */
	if ((TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2))
	{
		/* Save the current value of TCCR2 */
		LOC_u8TIMERRegValue = TCCR2;

		/* Clear the compare match output mode bits for CTC_MODE */
		LOC_u8TIMERRegValue &= TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for CTC_MODE */
		LOC_u8TIMERRegValue |= TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE;

		/* Update TCCR2 with the new configuration */
		TCCR2 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for CTC_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR;
	}
#endif


	/* Check if the selected waveform generation mode is PWM_MODE */
#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_PWM_MODE

	/* Check the selected compare match output mode for PWM_MODE */
	if ((TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNECTED_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2))
	{
		/* Save the current value of TCCR2 */
		LOC_u8TIMERRegValue = TCCR2;

		/* Clear the compare match output mode bits for PWM_MODE */
		LOC_u8TIMERRegValue &= TCCR2_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for PWM_MODE */
		LOC_u8TIMERRegValue |= TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE;

		/* Update TCCR2 with the new configuration */
		TCCR2 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for PWM_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR;
	}
#endif


	/* Check if the selected waveform generation mode is FPWM_MODE */
#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_WAVEFORM_GENERATION_MODE_FPWM_MODE

	/* Check the selected compare match output mode for FPWM_MODE */
	if ((TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNECTED_OC2) || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2)    || \
			(TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2))
	{
		/* Save the current value of TCCR2 */
		LOC_u8TIMERRegValue = TCCR2;

		/* Clear the compare match output mode bits for FPWM_MODE */
		LOC_u8TIMERRegValue &= TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK;

		/* Set the selected compare match output mode for FPWM_MODE */
		LOC_u8TIMERRegValue |= TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE;

		/* Update TCCR2 with the new configuration */
		TCCR2 = LOC_u8TIMERRegValue;
	}
	else
	{
		/* Set an error status if the selected compare match output mode for FPWM_MODE is invalid */
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR;

	}

#endif


#endif


	return Ret_enuTIMERS_ErrorStatus;
}



MTIMERS_enuErrorStatus_t MTIMERS_enuSetTime_Timer0( MTIMERS_enuTimerModes Copy_enuTimerMode,MTIMERS_enuTimerValues Copy_enuTimerValue )
{
	u8 LOC_u8TIMERRegValue = 0;
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;

	if (MTIMER_TIMER0 == MTIMER_DISABLE)
	{
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_ENABLE_ERROR;
	}
	else
	{
		/*Save te value to check in ISR*/
		TIMER0_VALUE = Copy_enuTimerValue;
		switch (Copy_enuTimerMode)
		{
		case MTIMER_enuOVERFLOW:

			/*Set The Enable Bit Of OVERFLOW Interrupt  */
			SET_BIT(TIMSK,0);

			/*Set Global interrupt */
			SET_BIT(SREG,7);

			/* Set value of the preload in TCNT0 Register compared with Copy_TIMER0_PRELOAD_VALUES Array */
			TCNT0 = Copy_TIMER0_PRELOAD_OVERFLOW_VALUES[Copy_enuTimerValue];

			/* Save the value that is inside TCCR0 */
			LOC_u8TIMERRegValue = TCCR0;

			/* Clear the Prescaler bits */
			LOC_u8TIMERRegValue &= TCCR0_TIMER0_CLOCK_SELECT_CLEAR_MASK;

			/* Check if the timer value is 10ms or 25ms */
			if ((Copy_enuTimerValue == MTIMER_enu10MS || Copy_enuTimerValue == MTIMER_enu25MS))
			{
				/* Set the prescaler to divide the clock by 256 */
				LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_256;
				TCCR0 = LOC_u8TIMERRegValue;
			}

			else if (Copy_enuTimerValue >= MTIMER_enu50MS && Copy_enuTimerValue <= MTIMER_enu5SEC)
						{
							/* Set the prescaler to divide the clock by 1024 */
							LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_1024;
							TCCR0 = LOC_u8TIMERRegValue;
						}
			break;
		case MTIMER_enuCTC :
			/*Set The Enable Bit Of CTC Interrupt  */
			SET_BIT(TIMSK,1);

			/*Set Global interrupt */
			SET_BIT(SREG,7);

			/* Set value of the preload in TCNT0 Register compared with Copy_TIMER0_PRELOAD_VALUES Array */
			OCR0 = Copy_TIMER0_NUMBER_OF_INTERRUPTS_CTC_VALUES[Copy_enuTimerValue];

			/* Save the value that is inside TCCR0 */
			LOC_u8TIMERRegValue = TCCR0;

			/* Clear the Prescaler bits */
			LOC_u8TIMERRegValue &= TCCR0_TIMER0_CLOCK_SELECT_CLEAR_MASK;


			/* Check if the timer value is 10ms or 25ms */
			if ((Copy_enuTimerValue == MTIMER_enu10MS || Copy_enuTimerValue == MTIMER_enu25MS))
			{
				/* Set the prescaler to divide the clock by 64 */
				LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_64;
				TCCR0 = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu50MS || Copy_enuTimerValue == MTIMER_enu100MS))
			{
				/* Set the prescaler to divide the clock by 256 */
				LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_256;
				TCCR0 = LOC_u8TIMERRegValue;
			}


			else if (Copy_enuTimerValue >= MTIMER_enu500MS && Copy_enuTimerValue <= MTIMER_enu5SEC)
			{
				/* Set the prescaler to divide the clock by 1024 */
				LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_1024;
				TCCR0 = LOC_u8TIMERRegValue;
			}
			break;


		default:           break;
		}
	}
	return Ret_enuTIMERS_ErrorStatus;
}

MTIMERS_enuErrorStatus_t MTIMERS_enuSetTime_Timer1( MTIMERS_enuTimerModes Copy_enuTimerMode,MTIMERS_enuTimerValues Copy_enuTimerValue )
{
	u8 LOC_u8TIMERRegValue = 0;
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;

	if (MTIMER_TIMER1 == MTIMER_DISABLE)
	{
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_ENABLE_ERROR;
	}
	else
	{   /*Save the value to check in ISR*/
		TIMER1_VALUE = Copy_enuTimerValue;

		switch (Copy_enuTimerMode)
		{
		case MTIMER_enuOVERFLOW:

			/*Set The Enable Bit Of OVERFLOW Interrupt  */
			SET_BIT(TIMSK,2);

			/*Set Global interrupt */
			SET_BIT(SREG,7);

			/* Set value of the preload in TCNT1(16 bit) Register compared with Copy_TIMER1_PRELOAD_VALUES Array */
			TCNT1 = Copy_TIMER1_PRELOAD_OVERFLOW_VALUES[Copy_enuTimerValue];

			/* Save the value that is inside TCCR0 */
			LOC_u8TIMERRegValue= TCCR1B;

			/* Clear the Prescaler bits */
			LOC_u8TIMERRegValue &= TCCR1B_TIMER1_CLOCK_SELECT_CLEAR_MASK ;

			/* Check if the timer value is 10ms or 25ms or 50ms */
			if ((Copy_enuTimerValue == MTIMER_enu10MS || Copy_enuTimerValue == MTIMER_enu25MS || Copy_enuTimerValue == MTIMER_enu50MS ))
			{
				/* Set the prescaler to divide the clock by No Prescalling */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_NOPRESCALING ;
				TCCR1B = LOC_u8TIMERRegValue;
			}

			else if ((Copy_enuTimerValue == MTIMER_enu100MS || Copy_enuTimerValue == MTIMER_enu500MS ))
			{
				/* Set the prescaler to divide the clock by 8 */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_8 ;
				TCCR1B = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu1SEC || Copy_enuTimerValue == MTIMER_enu2SEC ))
			{
				/* Set the prescaler to divide the clock by 64 */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_64 ;
				TCCR1B = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu5SEC  ))
			{
				/* Set the prescaler to divide the clock by 256 */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_256 ;
				TCCR1B = LOC_u8TIMERRegValue;
			}
			else
			{

			}
			break;
		case MTIMER_enuCTC :
			/*Set The Enable Bit Of CTC Interrupt  */
			SET_BIT(TIMSK,4);

			/*Set Global interrupt */
			SET_BIT(SREG,7);

			/* Set value of the preload in OCR1A Register compared with Copy_TIMER1_CTC_VALUES Array */
			OCR1A = Copy_TIMER1_NUMBER_OF_INTERRUPTS_CTC_VALUES[Copy_enuTimerValue];

			/* Save the value that is inside TCCR1B */
			LOC_u8TIMERRegValue = TCCR1B;

			/* Clear the Prescaler bits */
			LOC_u8TIMERRegValue &= TCCR1B_TIMER1_CLOCK_SELECT_CLEAR_MASK;


			/* Check if the timer value is 10ms or 25ms or 50*/
			if ((Copy_enuTimerValue == MTIMER_enu10MS || Copy_enuTimerValue == MTIMER_enu25MS || \
				Copy_enuTimerValue == MTIMER_enu50MS ))
			{
				/* Set the prescaler to divide the clock over 64 */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_64 ;
				TCCR1B = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu100MS || Copy_enuTimerValue == MTIMER_enu500MS || \
					Copy_enuTimerValue == MTIMER_enu1SEC ))
			{
				/* Set the prescaler to divide the clock over 256 */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_256 ;
				TCCR1B = LOC_u8TIMERRegValue;
			}

			else if ((Copy_enuTimerValue == MTIMER_enu2SEC || Copy_enuTimerValue == MTIMER_enu5SEC ))
			{
				/* Set the prescaler to divide the clock over 1024 */
				LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_1024 ;
				TCCR1B = LOC_u8TIMERRegValue;
			}
			else
			{

			}
			break;

		    default:           break;
		}


	}
	return Ret_enuTIMERS_ErrorStatus;
}



MTIMERS_enuErrorStatus_t MTIMERS_enuSetTime_Timer2( MTIMERS_enuTimerModes Copy_enuTimerMode,MTIMERS_enuTimerValues Copy_enuTimerValue )
{
	u8 LOC_u8TIMERRegValue = 0;
	/*Save the value to check in ISR*/
	TIMER2_VALUE = Copy_enuTimerValue;

	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;

	if (MTIMER_TIMER2 == MTIMER_DISABLE)
	{
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER2_ENABLE_ERROR;
	}
	else
	{
		switch (Copy_enuTimerMode)
		{

		case MTIMER_enuOVERFLOW:
			/* Set The Enable Bit Of OVERFLOW Interrupt */
			SET_BIT(TIMSK, 6);

			/* Set Global interrupt */
			SET_BIT(SREG, 7);

			/* Set value of the preload in TCNT2 Register compared with Copy_TIMER2_PRELOAD_VALUES Array */
			TCNT2 = Copy_TIMER2_PRELOAD_OVERFLOW_VALUES[Copy_enuTimerValue];

			/* Save the value that is inside TCCR2 */
			LOC_u8TIMERRegValue = TCCR2;

			/* Clear the Prescaler bits */
			LOC_u8TIMERRegValue &= TCCR2_TIMER2_CLOCK_SELECT_CLEAR_MASK;

			/* Check if the timer value is 10ms or 25ms */
			if ((Copy_enuTimerValue == MTIMER_enu10MS || Copy_enuTimerValue == MTIMER_enu25MS))
			{
				/* Set the prescaler to divide the clock by 256 */
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_256;
				TCCR2 = LOC_u8TIMERRegValue;
			}

			/* Check if the timer value is between 50ms and 5 seconds */
			else if (Copy_enuTimerValue >= MTIMER_enu50MS && Copy_enuTimerValue <= MTIMER_enu5SEC)
			{
				/* Set the prescaler to divide the clock by 1024 */
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_1024;
				TCCR2 = LOC_u8TIMERRegValue;
			}
			else
			{

			}
			break;

		case MTIMER_enuCTC:
			/*Set The Enable Bit Of CTC Interrupt  */
			SET_BIT(TIMSK,7);

			/*Set Global interrupt */
			SET_BIT(SREG,7);

			/* Set value of the number of interrupts in OCR2 Register compared with Copy_TIMER0_PRELOAD_VALUES Array */
			OCR2 = Copy_TIMER2_NUMBER_OF_INTERRUPTS_CTC_VALUES[Copy_enuTimerValue];

			/* Save the value that is inside TCCR2 */
			LOC_u8TIMERRegValue = TCCR2;

			/* Clear the Prescaler bits */
			LOC_u8TIMERRegValue &= TCCR2_TIMER2_CLOCK_SELECT_CLEAR_MASK;

			/* Check if the timer value is 10ms or 25ms */
			if ((Copy_enuTimerValue == MTIMER_enu10MS ||Copy_enuTimerValue == MTIMER_enu25MS || Copy_enuTimerValue == MTIMER_enu50MS ))
			{
				/* Set the prescaler to divide the clock by 64 */
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_8;
				TCCR2 = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu100MS || Copy_enuTimerValue == MTIMER_enu500MS  ))
			{
				/* Set the prescaler to divide the clock by 128*/
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_32;
				TCCR2 = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu1SEC ))
			{
				/* Set the prescaler to divide the clock by 256 */
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_64;
				TCCR2 = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu2SEC  ))
			{
				/* Set the prescaler to divide the clock by 1024 */
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_128;
				TCCR2 = LOC_u8TIMERRegValue;
			}
			else if ((Copy_enuTimerValue == MTIMER_enu5SEC  ))
			{
				/* Set the prescaler to divide the clock by 1024 */
				LOC_u8TIMERRegValue |= TIMER2_CLOCK_SELECT_PRESCALLER_OVER_256;
				TCCR2 = LOC_u8TIMERRegValue;
			}
			else
			{

			}
			break;

		default:                                                             break;
		}

	}
	return Ret_enuTIMERS_ErrorStatus;
}


MTIMERS_enuErrorStatus_t MTIMERS_enuSetDutyCycle_Timer1( u8 Copy_u8DutyCycle)
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus =  MTIMER_enuOK;
	u16 LOC_u8TIMERRegValue = 0;
	u16 LOC_u16TIMEROverFlowTime = 0xFFFF;
	u16 LOC_u16TIMERDutyCycleValue=0;

	if(Copy_u8DutyCycle > 100 )
	{
		Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_DUTY_CYCLE_VALUE_ERROR;
	}
	else
	{
       if(TIMER1_PWM_MODE == TIMER1_FAST_PWM_MODE)
       {
    	   if(TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC1A)
    	   {

    		   LOC_u16TIMERDutyCycleValue = (((u16)(Copy_u8DutyCycle) * (LOC_u16TIMEROverFlowTime)) -1 ) /100;
    		   OCR1A = LOC_u16TIMERDutyCycleValue  ;

    	   }
    	   else if(TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_OC1A)
    	   {
    	   }
    	   else
    	   {

    	   }



       }
       else if(TIMER1_PWM_MODE == TIMER1_PHASE_CORRECT_MODE)
       {
    	   if(TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_ON_UP_COUNTING_OC1A)
    	   {

    	   }
    	   else if(TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_ON_UP_COUNTING_OC1A)
    	   {
    	   }
    	   else
    	   {

    	   }


       }


	}

	/* Save the value that is inside TCCR1B */
	LOC_u8TIMERRegValue = TCCR1B;

	/* Clear the Prescaler bits */
	LOC_u8TIMERRegValue &= TCCR1B_TIMER1_CLOCK_SELECT_CLEAR_MASK;

	/* Set the prescaler to divide the clock over 64 */
	LOC_u8TIMERRegValue |= TIMER1_CLOCK_SELECT_PRESCALLER_OVER_64;
	TCCR1B = LOC_u8TIMERRegValue;



	return Ret_enuTIMERS_ErrorStatus;
}


// Function to set the duty cycle for Fast PWM mode on Timer0
MTIMERS_enuErrorStatus_t MTIMERS_enuSetDutyCycleFastPWM_Timer0(u8 Copy_u8DutyCycle, MTIMERS_enuPWM_MODES Copy_u8PWMType) {
    // Initialize error status variable
    MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
    // Local variable to store the value of the Timer register
    u8 LOC_u8TIMERRegValue = 0;
    // Maximum overflow time value for Timer0
    u8 LOC_u8TIMEROverFlowTime = 0xFF;
    // Variable to store the duty cycle value
    u8 LOC_u8TIMERDutyCycleValue = 0;

    // Check if the duty cycle value is valid (within 0 to 100)
    if (Copy_u8DutyCycle > 100) {
        Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_DUTY_CYCLE_VALUE_ERROR;
    }

    // Check the waveform generation mode of Timer0
    if (TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_FPWM_MODE) {
        // Switch based on the PWM type
        switch (Copy_u8PWMType) {
            case MTIMER_enuINVETED_MODE:
                // Check if the compare match output mode is inverting
                if (TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_INVERTING_ON_OC0) {
                    // Calculate the duty cycle value for inverted mode
                    LOC_u8TIMERDutyCycleValue = ((1 - Copy_u8DutyCycle) * (LOC_u8TIMEROverFlowTime)) / 100;
                    // Set the duty cycle value in OCR0 register
                    OCR0 = LOC_u8TIMERDutyCycleValue;
                } else {
                    // Do nothing if the compare match output mode is not inverting
                }
                break;
            case MTIMER_enuNON_INVETED_MODE:
                // Check if the compare match output mode is non-inverting
                if (TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NON_INVERTING_ON_OC0) {
                    // Calculate the duty cycle value for non-inverted mode
                    LOC_u8TIMERDutyCycleValue = (((Copy_u8DutyCycle) * (LOC_u8TIMEROverFlowTime))) / 100;
                    // Set the duty cycle value in OCR0 register
                    OCR0 = LOC_u8TIMERDutyCycleValue;
                } else {
                    // Do nothing if the compare match output mode is not non-inverting
                }
                break;
            default:
                break;
        }
    } else {
        // Set error status if the waveform generation mode is not Fast PWM mode
        Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR;
    }

    // Save the value of TCCR0 register
    LOC_u8TIMERRegValue = TCCR0;

    // Clear the prescaler bits in TCCR0 register
    LOC_u8TIMERRegValue &= TCCR0_TIMER0_CLOCK_SELECT_CLEAR_MASK;

    // Set the prescaler to divide the clock by 8
    LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_8;

    // Update TCCR0 register with the new prescaler value
    TCCR0 = LOC_u8TIMERRegValue;

    // Return the error status
    return Ret_enuTIMERS_ErrorStatus;
}


// Function to set the duty cycle for Phase Correct PWM mode on Timer0
MTIMERS_enuErrorStatus_t MTIMERS_enuSetDutyCyclePhaseCorrection_Timer0(u8 Copy_u8DutyCycle, MTIMERS_enuPWM_MODES Copy_u8PWMType) {
    // Initialize error status variable
    MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
    // Local variable to store the value of the Timer register
    u8 LOC_u8TIMERRegValue = 0;
    // Maximum overflow time value for Timer0
    u8 LOC_u8TIMEROverFlowTime = 0xFF;
    // Variable to store the duty cycle value
    u8 LOC_u8TIMERDutyCycleValue = 0;

    // Check if the duty cycle value is valid (within 0 to 100)
    if (Copy_u8DutyCycle > 100) {
        Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER1_DUTY_CYCLE_VALUE_ERROR;
    }

    // Check the waveform generation mode of Timer0
    if (TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_WAVEFORM_GENERATION_MODE_PHASE_CORRECT_MODE) {
        // Switch based on the PWM type
        switch (Copy_u8PWMType) {
            case MTIMER_enuINVETED_MODE:
                // Check if the compare match output mode is inverting
                if (TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_INVERTING_ON_OC0) {
                    // Calculate the duty cycle value for inverted mode
                    LOC_u8TIMERDutyCycleValue = ((1 - Copy_u8DutyCycle) * (LOC_u8TIMEROverFlowTime)) / 100;
                    // Set the duty cycle value in OCR0 register
                    OCR0 = LOC_u8TIMERDutyCycleValue;
                } else {
                    // Do nothing if the compare match output mode is not inverting
                }
                break;
            case MTIMER_enuNON_INVETED_MODE:
                // Check if the compare match output mode is non-inverting
                if (TIMER0_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE == TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NON_INVERTING_ON_OC0) {
                    // Calculate the duty cycle value for non-inverted mode
                    LOC_u8TIMERDutyCycleValue = (((Copy_u8DutyCycle) * (LOC_u8TIMEROverFlowTime))) / 100;
                    // Set the duty cycle value in OCR0 register
                    OCR0 = LOC_u8TIMERDutyCycleValue;
                } else {
                    // Do nothing if the compare match output mode is not non-inverting
                }
                break;
            default:
                break;
        }
    } else {
        // Set error status if the waveform generation mode is not Phase Correct PWM mode
        Ret_enuTIMERS_ErrorStatus = MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR;
    }

    // Save the value of TCCR0 register
    LOC_u8TIMERRegValue = TCCR0;

    // Clear the prescaler bits in TCCR0 register
    LOC_u8TIMERRegValue &= TCCR0_TIMER0_CLOCK_SELECT_CLEAR_MASK;

    // Set the prescaler to divide the clock by 8
    LOC_u8TIMERRegValue |= TIMER0_CLOCK_SELECT_PRESCALLER_OVER_8;

    // Update TCCR0 register with the new prescaler value
    TCCR0 = LOC_u8TIMERRegValue;

    // Return the error status
    return Ret_enuTIMERS_ErrorStatus;
}




/*CALLBACK FUNCTION FOR TIMER0 OVERFLOW MODE */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER0_OVERFLOW(void (*Copy_pfvTIMER0Func)(void))
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
	if(Copy_pfvTIMER0Func == NULL)
	{
		Ret_enuTIMERS_ErrorStatus = MTIMER_enuNullPointerError;
	}
	else
	{
		TIMER_pfvTIMER0Func = Copy_pfvTIMER0Func;
	}
	return Ret_enuTIMERS_ErrorStatus;
}

MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER0_CTC(void (*Copy_pfvTIMER0Func)(void))
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
		if(Copy_pfvTIMER0Func == NULL)
		{
			Ret_enuTIMERS_ErrorStatus = MTIMER_enuNullPointerError;
		}
		else
		{
			TIMER_pfvTIMER0Func = Copy_pfvTIMER0Func;
		}
		return Ret_enuTIMERS_ErrorStatus;

}

MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER1_OVERFLOW(void (*Copy_pfvTIMER1Func)(void))
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
			if(Copy_pfvTIMER1Func == NULL)
			{
				Ret_enuTIMERS_ErrorStatus = MTIMER_enuNullPointerError;
			}
			else
			{
				TIMER_pfvTIMER1Func = Copy_pfvTIMER1Func;
			}
			return Ret_enuTIMERS_ErrorStatus;
}

MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER1_CTC(void (*Copy_pfvTIMER1Func)(void))
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
			if(Copy_pfvTIMER1Func == NULL)
			{
				Ret_enuTIMERS_ErrorStatus = MTIMER_enuNullPointerError;
			}
			else
			{
				TIMER_pfvTIMER1Func = Copy_pfvTIMER1Func;
			}
			return Ret_enuTIMERS_ErrorStatus;
}



/*CALLBACK FUNCTION FOR TIMER2 OVERFLOW MODE */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER2_OVERFLOW(void (*Copy_pfvTIMER2Func)(void))
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
	if(Copy_pfvTIMER2Func == NULL)
	{
		Ret_enuTIMERS_ErrorStatus = MTIMER_enuNullPointerError;
	}
	else
	{
		TIMER_pfvTIMER2Func = Copy_pfvTIMER2Func;
	}
	return Ret_enuTIMERS_ErrorStatus;
}

MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER2_CTC(void (*Copy_pfvTIMER2Func)(void))
{
	MTIMERS_enuErrorStatus_t Ret_enuTIMERS_ErrorStatus = MTIMER_enuOK;
		if(Copy_pfvTIMER2Func == NULL)
		{
			Ret_enuTIMERS_ErrorStatus = MTIMER_enuNullPointerError;
		}
		else
		{
			TIMER_pfvTIMER2Func = Copy_pfvTIMER2Func;
		}
		return Ret_enuTIMERS_ErrorStatus;

}


/*OVERFLOW ISR FUNCTION FOR TIMER 0*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	ISR_Counter ++;
	if(TIMER_pfvTIMER0Func!=NULL)
	{
		if(ISR_Counter == Copy_TIMER0_NUMBER_OF_INTERRUPTS_OVERFLOW_VALUES[TIMER0_VALUE] )
		{
			TIMER_pfvTIMER0Func();
			ISR_Counter = 0;
		}
	}
	else
	{
		/*do nothing*/
	}

}

/*CTC ISR FUNCTION FOR TIMER 0*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	TIMER0_CTC_ISR_COUNTER ++;
	if(TIMER_pfvTIMER0Func!=NULL)
	{
		if(TIMER0_CTC_ISR_COUNTER == 1000 )
		{
			TIMER_pfvTIMER0Func();
			TIMER0_CTC_ISR_COUNTER = 0;
		}
	}
	else
	{
		/*do nothing*/
	}

}

/*OVERFLOW ISR FUNCTION FOR TIMER 1*/
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	ISR_Counter ++;
	if(TIMER_pfvTIMER1Func!=NULL)
	{
		if(ISR_Counter == Copy_TIMER1_NUMBER_OF_INTERRUPTS_OVERFLOW_VALUES[TIMER1_VALUE] )
		{
			TIMER_pfvTIMER1Func();
			ISR_Counter = 0;
		}
	}
	else
	{
		/*do nothing*/
	}

}

/*CTC ISR FUNCTION FOR TIMER 1*/
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	//TIMER1_CTC_ISR_COUNTER ++;
	if(TIMER_pfvTIMER1Func!=NULL)
	{
		//if(TIMER1_CTC_ISR_COUNTER == 1000 )
		//{
			TIMER_pfvTIMER1Func();
			//TIMER1_CTC_ISR_COUNTER = 0;
		//}
	}
	else
	{

	}

}


/*OVERFLOW ISR FUNCTION FOR TIMER 2*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	ISR_Counter ++;
	if(TIMER_pfvTIMER2Func!=NULL)
	{

		if(ISR_Counter == Copy_TIMER2_NUMBER_OF_INTERRUPTS_OVERFLOW_VALUES[TIMER2_VALUE])
		{
			TIMER_pfvTIMER2Func();
			ISR_Counter = 0;
		}
	}
	else
	{
		/*do nothing*/
	}

}

/*CTC ISR FUNCTION FOR TIMER 2*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	TIMER2_CTC_ISR_COUNTER ++;
	if(TIMER_pfvTIMER2Func!=NULL)
	{

		if(TIMER2_CTC_ISR_COUNTER == 1000)
		{
			TIMER_pfvTIMER2Func();
			TIMER2_CTC_ISR_COUNTER = 0;
		}
	}
	else
	{
		/*do nothing*/
	}

}

