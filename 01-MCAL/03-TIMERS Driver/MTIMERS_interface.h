/*
 * MTIMERS_interface.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Mina
 */

#ifndef MCAL_03_TIMERS_MTIMERS_INTERFACE_H_
#define MCAL_03_TIMERS_MTIMERS_INTERFACE_H_

#define MTIMER_DISABLE 0
#define MTIMER_ENABLE  1

#define TIMER1_FAST_PWM_MODE       0
#define TIMER1_PHASE_CORRECT_MODE  1

#define MTIMER_INVETED_MODE       0
#define MTIMER_NON_INVETED_MODE   1

typedef enum
{
	MTIMER_enuOK,
	MTIMER_enuNOK,
	MTIMER_TIMER0_ENABLE_ERROR,
	MTIMER_TIMER1_ENABLE_ERROR,
	MTIMER_TIMER2_ENABLE_ERROR,
	MTIMER_TIMER0_WAVEFORM_GENERATION_MODE_ERROR,
	MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR,
	MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR,
	MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR,
	MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR,
    MTIMER_TIMER1_WAVEFORM_GENERATION_MODE_ERROR,
	MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR,
	MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR,
	MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR,
	MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_PHASE_CORRECT_MODE_ERROR,
	MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR,
	 MTIMER_TIMER1_DUTY_CYCLE_VALUE_ERROR,
	MTIMER_enuNullPointerError,
	MTIMER_TIMER2_WAVEFORM_GENERATION_MODE_ERROR,
	MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR,
	MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR,
	MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR,
	MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR

}MTIMERS_enuErrorStatus_t;

typedef enum
{
	MTIMER_enu10MS,
	MTIMER_enu25MS,
	MTIMER_enu50MS,
	MTIMER_enu100MS,
	MTIMER_enu500MS,
	MTIMER_enu1SEC,
	MTIMER_enu2SEC,
	MTIMER_enu5SEC

}MTIMERS_enuTimerValues;

typedef enum
{
	MTIMER_enuOVERFLOW,
	MTIMER_enuCTC

}MTIMERS_enuTimerModes;

typedef enum
{
	MTIMER_enuTIMER0,
	MTIMER_enuTIMER1,
	MTIMER_enuTIMER2
}MTIMERS_enuTimers;

typedef enum
{
  MTIMER_enuINVETED_MODE,
  MTIMER_enuNON_INVETED_MODE

}MTIMERS_enuPWM_MODES;



/* Function: MTIMERS_enuInit
 * --------------------------
 * Initializes the Timer modules (TIMER0, TIMER1, TIMER2) based on the specified configuration parameters.
 * The function configures the waveform generation mode and compare match output mode for each enabled timer.
 *
 * Returns:
 *   - MTIMERS_enuOK: Successful initialization.
 *   - MTIMER_TIMER0_WAVEFORM_GENERATION_MODE_ERROR: Invalid waveform generation mode for TIMER0.
 *   - MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR: Invalid compare match output mode for TIMER0 in NORMAL_MODE.
 *   - MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR: Invalid compare match output mode for TIMER0 in CTC_MODE.
 *   - MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR: Invalid compare match output mode for TIMER0 in PWM_MODE.
 *   - MTIMER_TIMER0_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR: Invalid compare match output mode for TIMER0 in FPWM_MODE.
 *   - MTIMER_TIMER1_WAVEFORM_GENERATION_MODE_ERROR: Invalid waveform generation mode for TIMER1.
 *   - MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR: Invalid compare match output mode for TIMER1 in NORMAL_MODE.
 *   - MTIMER_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR: Invalid compare match output mode for TIMER1 in CTC_MODE.
 *   - MTIMER_TIMER2_WAVEFORM_GENERATION_MODE_ERROR: Invalid waveform generation mode for TIMER2.
 *   - MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_NORMAL_MODE_ERROR: Invalid compare match output mode for TIMER2 in NORMAL_MODE.
 *   - MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CTC_MODE_ERROR: Invalid compare match output mode for TIMER2 in CTC_MODE.
 *   - MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_PWM_MODE_ERROR: Invalid compare match output mode for TIMER2 in PWM_MODE.
 *   - MTIMER_TIMER2_COMPARE_MATCH_OUTPUT_MODE_FAST_PWM_MODE_ERROR: Invalid compare match output mode for TIMER2 in FPWM_MODE.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuInit(void);

/* Function: MTIMERS_enuSetTime_Timer0
 * ------------------------------------
 * Sets the operating mode and time duration for TIMER0 based on the specified configuration parameters.
 * The function supports two modes: Overflow mode (continuous counting) and Compare Match (CTC) mode.
 * In Overflow mode, the function configures the timer to generate interrupts at a predefined time interval.
 * In CTC mode, the function configures the timer to generate interrupts after a specific number of counts.
 *
 * Parameters:
 *   - Copy_enuTimerMode: Selected timer mode (MTIMER_enuOVERFLOW or MTIMER_enuCTC).
 *   - Copy_enuTimerValue: Selected time duration from the predefined values in MTIMERS_enuTimerValues.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful configuration.
 *   - MTIMER_TIMER0_ENABLE_ERROR: TIMER0 is disabled, and configuration cannot be applied.
 *
 * Note:
 *   - The function uses predefined arrays (Copy_TIMER0_PRELOAD_OVERFLOW_VALUES and Copy_TIMER0_NUMBER_OF_INTERRUPTS_CTC_VALUES)
 *     to set the initial values for TCNT0 (preload) and OCR0 (number of interrupts) based on the selected time duration.
 *   - The function sets the appropriate prescaler value based on the selected time duration to control the clock frequency.
 *   - Overflow interrupts are enabled in both modes to trigger the corresponding ISR.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetTime_Timer0( MTIMERS_enuTimerModes Copy_enuTimerMode,MTIMERS_enuTimerValues Copy_enuTimerValue );


/* Function: MTIMERS_enuSetTime_Timer1
 * ------------------------------------
 * Sets the operating mode and time duration for TIMER1 based on the specified configuration parameters.
 * The function supports two modes: Overflow mode (continuous counting) and Compare Match (CTC) mode.
 * In Overflow mode, the function configures the timer to generate interrupts at a predefined time interval.
 * In CTC mode, the function configures the timer to generate interrupts after a specific number of counts.
 *
 * Parameters:
 *   - Copy_enuTimerMode: Selected timer mode (MTIMER_enuOVERFLOW or MTIMER_enuCTC).
 *   - Copy_enuTimerValue: Selected time duration from the predefined values in MTIMERS_enuTimerValues.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful configuration.
 *   - MTIMER_TIMER1_ENABLE_ERROR: TIMER1 is disabled, and configuration cannot be applied.
 *
 * Note:
 *   - The function uses predefined arrays (Copy_TIMER1_PRELOAD_OVERFLOW_VALUES and Copy_TIMER1_NUMBER_OF_INTERRUPTS_CTC_VALUES)
 *     to set the initial values for TCNT1 (preload) and OCR1A (number of interrupts) based on the selected time duration.
 *   - The function sets the appropriate prescaler value based on the selected time duration to control the clock frequency.
 *   - Overflow interrupts are enabled in both modes to trigger the corresponding ISR.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetTime_Timer1( MTIMERS_enuTimerModes Copy_enuTimerMode,MTIMERS_enuTimerValues Copy_enuTimerValue );

/* Function: MTIMERS_enuSetTime_Timer2
 * ------------------------------------
 * Sets the operating mode and time duration for TIMER2 based on the specified configuration parameters.
 * The function supports two modes: Overflow mode (continuous counting) and Compare Match (CTC) mode.
 * In Overflow mode, the function configures the timer to generate interrupts at a predefined time interval.
 * In CTC mode, the function configures the timer to generate interrupts after a specific number of counts.
 *
 * Parameters:
 *   - Copy_enuTimerMode: Selected timer mode (MTIMER_enuOVERFLOW or MTIMER_enuCTC).
 *   - Copy_enuTimerValue: Selected time duration from the predefined values in MTIMERS_enuTimerValues.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful configuration.
 *   - MTIMER_TIMER2_ENABLE_ERROR: TIMER2 is disabled, and configuration cannot be applied.
 *
 * Note:
 *   - The function uses predefined arrays (Copy_TIMER2_PRELOAD_OVERFLOW_VALUES and Copy_TIMER2_NUMBER_OF_INTERRUPTS_CTC_VALUES)
 *     to set the initial values for TCNT2 (preload) and OCR2 (number of interrupts) based on the selected time duration.
 *   - The function sets the appropriate prescaler value based on the selected time duration to control the clock frequency.
 *   - Overflow interrupts are enabled in both modes to trigger the corresponding ISR.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetTime_Timer2( MTIMERS_enuTimerModes Copy_enuTimerMode,MTIMERS_enuTimerValues Copy_enuTimerValue );

MTIMERS_enuErrorStatus_t MTIMERS_enuSetDutyCycleFastPWM_Timer0( u8 Copy_u8DutyCycle,MTIMERS_enuPWM_MODES Copy_u8PWMType );
MTIMERS_enuErrorStatus_t MTIMERS_enuSetDutyCyclePhaseCorrection_Timer0( u8 Copy_u8DutyCycle,MTIMERS_enuPWM_MODES Copy_u8PWMType );

MTIMERS_enuErrorStatus_t MTIMERS_enuSetDutyCycle_Timer1( u8 Copy_u8DutyCycle);






/* Function: MTIMERS_enuSetCallbackTIMER0_OVERFLOW
 * ----------------------------------------------
 * Sets the callback function to be executed when TIMER0 overflows in Overflow mode.
 * The provided callback function will be invoked each time TIMER0 completes a full overflow cycle.
 *
 * Parameters:
 *   - Copy_pfvTIMER0Func: Pointer to the callback function for TIMER0 Overflow mode.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful callback function registration.
 *   - MTIMER_enuNullPointerError: Attempt to register a NULL pointer as the callback function.
 *
 * Note:
 *   - The function checks if the provided callback function pointer is NULL, and if so,
 *     it returns an error (MTIMER_enuNullPointerError).
 *   - If a valid callback function pointer is provided, it is assigned to TIMER_pfvTIMER0Func
 *     for later execution in the corresponding TIMER0 Overflow ISR.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER0_OVERFLOW(void (*Copy_pfvTIMER0Func)(void));


/* Function: MTIMERS_enuSetCallbackTIMER0_CTC
 * -----------------------------------------
 * Sets the callback function to be executed when TIMER0 reaches the Compare Match value in CTC mode.
 * The provided callback function will be invoked when TIMER0's counter matches the specified Compare Match value.
 *
 * Parameters:
 *   - Copy_pfvTIMER0Func: Pointer to the callback function for TIMER0 CTC mode.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful callback function registration.
 *   - MTIMER_enuNullPointerError: Attempt to register a NULL pointer as the callback function.
 *
 * Note:
 *   - The function checks if the provided callback function pointer is NULL, and if so,
 *     it returns an error (MTIMER_enuNullPointerError).
 *   - If a valid callback function pointer is provided, it is assigned to TIMER_pfvTIMER0Func
 *     for later execution when TIMER0 reaches the Compare Match value.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER0_CTC(void (*Copy_pfvTIMER0Func)(void));

/* Function: MTIMERS_enuSetCallbackTIMER1_OVERFLOW
 * ----------------------------------------------
 * Sets the callback function to be executed when TIMER1 overflows in overflow mode.
 * The provided callback function will be invoked when the 16-bit counter of TIMER1 overflows.
 *
 * Parameters:
 *   - Copy_pfvTIMER1Func: Pointer to the callback function for TIMER1 overflow mode.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful callback function registration.
 *   - MTIMER_enuNullPointerError: Attempt to register a NULL pointer as the callback function.
 *
 * Note:
 *   - The function checks if the provided callback function pointer is NULL, and if so,
 *     it returns an error (MTIMER_enuNullPointerError).
 *   - If a valid callback function pointer is provided, it is assigned to TIMER_pfvTIMER1Func
 *     for later execution when TIMER1 overflows.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER1_OVERFLOW(void (*Copy_pfvTIMER1Func)(void));

/* Function: MTIMERS_enuSetCallbackTIMER1_CTC
 * -----------------------------------------
 * Sets the callback function to be executed when TIMER1 reaches the Compare Match value in CTC mode.
 * The provided callback function will be invoked when TIMER1 matches the value set in OCR1A register.
 *
 * Parameters:
 *   - Copy_pfvTIMER1Func: Pointer to the callback function for TIMER1 CTC mode.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful callback function registration.
 *   - MTIMER_enuNullPointerError: Attempt to register a NULL pointer as the callback function.
 *
 * Note:
 *   - The function checks if the provided callback function pointer is NULL, and if so,
 *     it returns an error (MTIMER_enuNullPointerError).
 *   - If a valid callback function pointer is provided, it is assigned to TIMER_pfvTIMER1Func
 *     for later execution when TIMER1 reaches the Compare Match value.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER1_CTC(void (*Copy_pfvTIMER1Func)(void));


/* Function: MTIMERS_enuSetCallbackTIMER2_OVERFLOW
 * ----------------------------------------------
 * Sets the callback function to be executed when TIMER2 overflows in normal mode.
 * The provided callback function will be invoked when TIMER2 completes a full cycle and overflows.
 *
 * Parameters:
 *   - Copy_pfvTIMER2Func: Pointer to the callback function for TIMER2 overflow in normal mode.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful callback function registration.
 *   - MTIMER_enuNullPointerError: Attempt to register a NULL pointer as the callback function.
 *
 * Note:
 *   - The function checks if the provided callback function pointer is NULL, and if so,
 *     it returns an error (MTIMER_enuNullPointerError).
 *   - If a valid callback function pointer is provided, it is assigned to TIMER_pfvTIMER2Func
 *     for later execution when TIMER2 overflows.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER2_OVERFLOW(void (*Copy_pfvTIMER2Func)(void));

/* Function: MTIMERS_enuSetCallbackTIMER2_CTC
 * ------------------------------------------
 * Sets the callback function to be executed when TIMER2 reaches the Compare Match value in CTC mode.
 * The provided callback function will be invoked when TIMER2 matches the value set in the OCR2 register.
 *
 * Parameters:
 *   - Copy_pfvTIMER2Func: Pointer to the callback function for TIMER2 in CTC mode.
 *
 * Returns:
 *   - MTIMER_enuOK: Successful callback function registration.
 *   - MTIMER_enuNullPointerError: Attempt to register a NULL pointer as the callback function.
 *
 * Note:
 *   - The function checks if the provided callback function pointer is NULL, and if so,
 *     it returns an error (MTIMER_enuNullPointerError).
 *   - If a valid callback function pointer is provided, it is assigned to TIMER_pfvTIMER2Func
 *     for later execution when TIMER2 matches the Compare Match value.
 */
MTIMERS_enuErrorStatus_t MTIMERS_enuSetCallbackTIMER2_CTC(void (*Copy_pfvTIMER2Func)(void));

#endif /* MCAL_03_TIMERS_MTIMERS_INTERFACE_H_ */
