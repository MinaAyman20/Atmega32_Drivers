/*
 * MTIMERS_priv.h
 *
 *  Created on: Jan 14, 2024
 *      Author: Mina
 */

#ifndef MCAL_03_TIMERS_MTIMERS_PRIV_H_
#define MCAL_03_TIMERS_MTIMERS_PRIV_H_

#include "../../LIB/STD_TYPES.h"

/*Common Registers for Timer 0,1,2 */
#define   TIMSK       (*(unsigned volatile char*)0x59)
#define   TIFR        (*(unsigned volatile char*)0x58)
#define   SFIOR       (*(unsigned volatile char*)0x50)

/*Registers for Timer 0 */
#define   TCCR0       (*(unsigned volatile char*)0x53)
#define   TCNT0       (*(unsigned volatile char*)0x52)
#define   OCR0        (*(unsigned volatile char*)0x5C)

/*Registers for Timer 1 */
#define   TCCR1      (*(unsigned volatile short int*)0x4E)
#define   TCNT1      (*(unsigned volatile short int*)0x4C)
#define   OCR1A      (*(unsigned volatile short int*)0x4A)
#define   OCR1B      (*(unsigned volatile short int*)0x48)
#define   ICR1       (*(unsigned volatile short int*)0x46)

#define   TCCR1B      (*(unsigned volatile char*)0x4E)
#define   TCCR1A      (*(unsigned volatile char*)0x4F)
#define   TCNT1L      (*(unsigned volatile char*)0x4C)
#define   TCNT1H      (*(unsigned volatile char*)0x4D)
#define   OCR1AL      (*(unsigned volatile char*)0x4A)
#define   OCR1AH      (*(unsigned volatile char*)0x4B)
#define   OCR1BL      (*(unsigned volatile char*)0x48)
#define   OCR1BH      (*(unsigned volatile char*)0x49)
#define   ICR1L       (*(unsigned volatile char*)0x46)
#define   ICR1H       (*(unsigned volatile char*)0x47)

/*Registers for Timer 2 */
#define   TCCR2      (*(unsigned volatile char*)0x45)
#define   TCNT2      (*(unsigned volatile char*)0x44)
#define   OCR2       (*(unsigned volatile char*)0x43)
#define   ASSR       (*(unsigned volatile char*)0x42)

/*SREG Register for Global Interrupt Enable*/
#define   SREG       (*(unsigned volatile char*)0x5F)


const u8 Copy_TIMER0_PRELOAD_OVERFLOW_VALUES[] = {199,242,121,242,190,125,248,108};  // preload values of timer0
const u8 Copy_TIMER0_NUMBER_OF_INTERRUPTS_OVERFLOW_VALUES[] = {2,4,2,4,16,31,62,153};  // Number Of Interrupts values of timer0
const u8 Copy_TIMER0_NUMBER_OF_INTERRUPTS_CTC_VALUES[] = {1,3,1,3,4,8,15,39};  // Number Of Interrupts for ctc values of timer0

const u16 Copy_TIMER1_PRELOAD_OVERFLOW_VALUES[] = {51072,62144,58752,31072,24288,6072,12144,40358};  // preload values of timer1
const u16 Copy_TIMER1_NUMBER_OF_INTERRUPTS_OVERFLOW_VALUES[] = {2,4,7,2,8,2,4,3};  // Number Of Interrupts values of timer1
const u16 Copy_TIMER1_NUMBER_OF_INTERRUPTS_CTC_VALUES[] = {1250,3125,6250,3125,15625,31250,15625,39063};  // Number Of Interrupts for ctc values of timer1


const u8 Copy_TIMER2_PRELOAD_OVERFLOW_VALUES[] = {199,242,121,242,190,125,248,108};  // preload values of timer2
const u8 Copy_TIMER2_NUMBER_OF_INTERRUPTS_OVERFLOW_VALUES[] = {2,4,2,4,16,31,62,153};  // Number Of Interrupts values of timer2
const u8 Copy_TIMER2_NUMBER_OF_INTERRUPTS_CTC_VALUES[] = {10,25,50,25,125,125,125,157};  // Number Of Interrupts for ctc values of timer0

/******************************************************TIMER0*******************************************************************/

/************************************************WAVEFORM_GENERATION_MODE*******************************************************/
#define TCCR0_TIMER0_WAVEFORM_GENERATION_MODE_CLEAR_MASK              0XB7

#define TIMER0_WAVEFORM_GENERATION_MODE_NORMAL_MODE                       0X00
#define TIMER0_WAVEFORM_GENERATION_MODE_PHASE_CORRECT_MODE                0X40
#define TIMER0_WAVEFORM_GENERATION_MODE_CTC_MODE                          0X08
#define TIMER0_WAVEFORM_GENERATION_MODE_FPWM_MODE                         0X48
/*******************************************************************************************************************************/

/********************************************* Normal & CTC is selected *****************************************************************/
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0XCF

#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0        0X00
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC0             0X10
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC0              0X20
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_SET_OC0                0X30
/*******************************************************************************************************************************/

/*************************************************PHASE CORRECt is selected*****************************************************************/
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0XCF

#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0        0X00
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_RESERVED               0X10
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NON_INVERTING_ON_OC0   0X20
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_INVERTING_ON_OC0       0X30
/*******************************************************************************************************************************/

/*************************************************FPWM is selected*****************************************************************/
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0XCF

#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC0        0X00
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_RESERVED               0X10
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_NON_INVERTING_ON_OC0   0X20
#define TCCR0_TIMER0_COMPARE_MATCH_OUTPUT_MODE_INVERTING_ON_OC0       0X30
/*******************************************************************************************************************************/

/************************************************CLOCK SELECT*******************************************************************/
#define TCCR0_TIMER0_CLOCK_SELECT_CLEAR_MASK                0XF8

#define TIMER0_CLOCK_SELECT_NOPRESCALING              0X01
#define TIMER0_CLOCK_SELECT_PRESCALLER_OVER_8         0X02
#define TIMER0_CLOCK_SELECT_PRESCALLER_OVER_64        0X03
#define TIMER0_CLOCK_SELECT_PRESCALLER_OVER_256       0X04
#define TIMER0_CLOCK_SELECT_PRESCALLER_OVER_1024      0X05
#define TIMER0_CLOCK_SELECT_CLOCK_ON_FALLINGEDGE      0X06
#define TIMER0_CLOCK_SELECT_CLOCK_ON_RISINGEDGE       0X07
/*******************************************************************************************************************************/
/******************************************************TIMER1*******************************************************************/
/********************************************* Normal & CTC is selected *****************************************************************/
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0X3F

#define TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A              0X00
#define TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC1A                   0X40
#define TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC1A                    0X80
#define TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_OC1A                      0XC0
/*******************************************************************************************************************************/

/*************************************************PHASE CORRECT is selected*****************************************************************/
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A                       0X00
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_ON_UP_COUNTING_OC1A             0X40
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_ON_UP_COUNTING_OC1A              0X80
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_ON_UP_COUNTING_OC1A                0XC0
/*******************************************************************************************************************************/

/*************************************************FPWM is selected*****************************************************************/
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC1A        0X00
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC1A             0X40
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC1A              0X80
#define TCCR1A_TIMER1_COMPARE_MATCH_OUTPUT_MODE_SET_OC1A                0XC0
/*******************************************************************************************************************************/


/*******************************************************************************************************************************/

#define TCCR1_TIMER1_WAVEFORM_GENERATION_MODE_CLEAR_MASK       0XFCE7

#define TIMER1_WAVEFORM_GENERATION_MODE_NORMAL_MODE                       0X0000
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_8BIT_MODE                     0X0100
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_9BIT_MODE                     0X0200
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_10BIT_MODE                    0X0300
#define TIMER1_WAVEFORM_GENERATION_MODE_CTC_MODE_OCR1A                    0X0008
#define TIMER1_WAVEFORM_GENERATION_MODE_FPWM_8BIT_MODE                    0X0108
#define TIMER1_WAVEFORM_GENERATION_MODE_FPWM_9BIT_MODE                    0X0208
#define TIMER1_WAVEFORM_GENERATION_MODE_FPWM_10BIT_MODE                   0X0308
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_FREQ_CORRECT_ICR1       0x0010
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_FREQ_CORRECT_OCR1A      0x0110
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_CORRECT_ICR1            0x0210
#define TIMER1_WAVEFORM_GENERATION_MODE_PWM_PHASE_CORRECT_OCR1A           0x0310
#define TIMER1_WAVEFORM_GENERATION_MODE_CTC_MODE_ICR1                     0x0018
#define TIMER1_WAVEFORM_GENERATION_MODE_FPWM_MODE_ICR1                    0X0218
#define TIMER1_WAVEFORM_GENERATION_MODE_FPWM_MODE_OCR1A                   0x0318

/*******************************************************************************************************************************/

#define TCCR1B_TIMER1_CLOCK_SELECT_CLEAR_MASK         0XF8

#define TIMER1_CLOCK_SELECT_NOPRESCALING              0X01
#define TIMER1_CLOCK_SELECT_PRESCALLER_OVER_8         0X02
#define TIMER1_CLOCK_SELECT_PRESCALLER_OVER_64        0X03
#define TIMER1_CLOCK_SELECT_PRESCALLER_OVER_256       0X04
#define TIMER1_CLOCK_SELECT_PRESCALLER_OVER_1024      0X05
#define TIMER1_CLOCK_SELECT_CLOCK_ON_FALLINGEDGE      0X06
#define TIMER1_CLOCK_SELECT_CLOCK_ON_RISINGEDGE       0X07

/*******************************************************************************************************************************/
/******************************************************TIMER2*******************************************************************/
/************************************************WAVEFORM_GENERATION_MODE*******************************************************/
#define TCCR2_TIMER2_WAVEFORM_GENERATION_MODE_CLEAR_MASK              0XB7

#define TIMER2_WAVEFORM_GENERATION_MODE_NORMAL_MODE             0X00
#define TIMER2_WAVEFORM_GENERATION_MODE_PWM_MODE                0X40
#define TIMER2_WAVEFORM_GENERATION_MODE_CTC_MODE                0X08
#define TIMER2_WAVEFORM_GENERATION_MODE_FPWM_MODE               0X48
/*******************************************************************************************************************************/

/********************************************* CTC is selected *****************************************************************/
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0XCF

#define TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC2        0X00
#define TIMER2_COMPARE_MATCH_OUTPUT_MODE_TOGGLE_OC2             0X10
#define TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2              0X20
#define TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2                0X30
/*******************************************************************************************************************************/

/*************************************************PWM is selected*****************************************************************/
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0XCF

#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC2        0X00
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_RESERVED               0X10
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2              0X20
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2                0X30
/*******************************************************************************************************************************/

/*************************************************FPWM is selected*****************************************************************/
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_MASK             0XCF

#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_DISCONNCTED_OC2        0X00
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_RESERVED               0X10
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_CLEAR_OC2              0X20
#define TCCR2_TIMER2_COMPARE_MATCH_OUTPUT_MODE_SET_OC2                0X30
/*******************************************************************************************************************************/

/************************************************CLOCK SELECT*******************************************************************/
#define TCCR2_TIMER2_CLOCK_SELECT_CLEAR_MASK                0XF8

#define TIMER2_CLOCK_SELECT_NOPRESCALING              0X01
#define TIMER2_CLOCK_SELECT_PRESCALLER_OVER_8         0X02
#define TIMER2_CLOCK_SELECT_PRESCALLER_OVER_32        0X03
#define TIMER2_CLOCK_SELECT_PRESCALLER_OVER_64        0X04
#define TIMER2_CLOCK_SELECT_PRESCALLER_OVER_128       0X05
#define TIMER2_CLOCK_SELECT_PRESCALLER_OVER_256       0X06
#define TIMER2_CLOCK_SELECT_PRESCALLER_OVER_1024      0X07
/*******************************************************************************************************************************/






#endif /* MCAL_03_TIMERS_MTIMERS_PRIV_H_ */
