/*
 * MADC_config.h
 *
 *  Created on: Feb 7, 2024
 *      Author: Mina
 */

#ifndef MCAL_05_MADC_MADC_CONFIG_H_
#define MCAL_05_MADC_MADC_CONFIG_H_

#include "MADC_interface.h"
#include "MADC_priv.h"

#define  MADC_TIMEOUT      50000


/*
 *  CONFIGRATION OPTIONS
 *  1-MADC_ENABLE
 *  2-MADC_DISABLE
 */
#define  MADC_STATE    MADC_ENABLE

/*
 *  CONFIGRATION OPTIONS
 *
 *  1- MADC_INT_ENABLE
 *  2- MADC_INT_DISABLE
 */
#define MADC_INT_STATUS                    MADC_INT_ENABLE


/*
 *  CONFIGRATION OPTIONS
 *
 *  1-  MADC_ADC0_SINGLE_ENDEDD
 *  2-  MADC_ADC1_SINGLE_ENDEDD
 *  3-  MADC_ADC2_SINGLE_ENDEDD
 *  4-  MADC_ADC3_SINGLE_ENDEDD
 *  5-  MADC_ADC4_SINGLE_ENDEDD
 *  6-  MADC_ADC5_SINGLE_ENDEDD
 *  7-  MADC_ADC6_SINGLE_ENDEDD
 *  8-  MADC_ADC7_SINGLE_ENDEDD
 *  9-  MADC_DIFFRITIAL_ADC0_ADC0_GAINx10
 *  10- MADC_DIFFRITIAL_ADC1_ADC0_GAINx10
 *  11- MADC_DIFFRITIAL_ADC0_ADC0_GAINx200
 *  12- MADC_DIFFRITIAL_ADC1_ADC0_GAINx200
 *  13- MADC_DIFFRITIAL_ADC2_ADC2_GAINx10
 *  14- MADC_DIFFRITIAL_ADC3_ADC2_GAINx10
 *  15- MADC_DIFFRITIAL_ADC2_ADC2_GAINx200
 *  16- MADC_DIFFRITIAL_ADC3_ADC2_GAINx200
 *  17- MADC_DIFFRITIAL_ADC0_ADC1_GAINx1
 *  18- MADC_DIFFRITIAL_ADC1_ADC1_GAINx1
 *  19- MADC_DIFFRITIAL_ADC2_ADC1_GAINx1
 *  20- MADC_DIFFRITIAL_ADC3_ADC1_GAINx1
 *  21- MADC_DIFFRITIAL_ADC4_ADC1_GAINx1
 *  22- MADC_DIFFRITIAL_ADC5_ADC1_GAINx1
 *  23- MADC_DIFFRITIAL_ADC6_ADC1_GAINx1
 *  24- MADC_DIFFRITIAL_ADC7_ADC1_GAINx1
 *  25- MADC_DIFFRITIAL_ADC0_ADC2_GAINx1
 *  26- MADC_DIFFRITIAL_ADC1_ADC2_GAINx1
 *  27- MADC_DIFFRITIAL_ADC2_ADC2_GAINx1
 *  28- MADC_DIFFRITIAL_ADC3_ADC2_GAINx1
 *  29- MADC_DIFFRITIAL_ADC4_ADC2_GAINx1
 *  30- MADC_DIFFRITIAL_ADC5_ADC2_GAINx1
 *
 */
#define MADC_CHANNEL         MADC_ADC0_SINGLE_ENDEDD


/*
 *  CONFIGRATION OPTIONS
 *
 *  1- MADC_AREF
 *  2- MADC_AVCC
 *  3- MADC_2.56V_INTERNAL
 */
#define MADC_VOLTAGEREF                      MADC_AVCC


/*
 *  CONFIGRATION OPTIONS
 *
 *  1- MADC_LEFT_ADJUST
 *  2- MADC_RIGHT_ADJUST
 */
#define MADC_DATA_ADJUST                     MADC_RIGHT_ADJUST

/*
 *  CONFIGRATION OPTIONS
 *
 *  1- MADC_CLOCK_SELECT_PRESCALLER_OVER_2
 *  2- MADC_CLOCK_SELECT_PRESCALLER_OVER_4
 *  3- MADC_CLOCK_SELECT_PRESCALLER_OVER_8
 *  4- MADC_CLOCK_SELECT_PRESCALLER_OVER_16
 *  5- MADC_CLOCK_SELECT_PRESCALLER_OVER_32
 *  6- MADC_CLOCK_SELECT_PRESCALLER_OVER_64
 *  7- MADC_CLOCK_SELECT_PRESCALLER_OVER_128
 */
#define MADC_PRESCALLER                     MADC_CLOCK_SELECT_PRESCALLER_OVER_32

/*
 *  CONFIGRATION OPTIONS
 *
 *  1- MADC_AUTO_TRIGGER_ENABLE
 *  2- MADC_AUTO_TRIGGER_DISABLE
 */
#define  MADC_AUTO_TRIGGER             MADC_AUTO_TRIGGER_ENABLE

/*
 *  CONFIGRATION OPTIONS
 *
 *  1- MADC_SINGLE_CONVERSION 
 *  2- MADC_FREE_RUNNING 
 *  3- MADC_ANALOG_COMPARATOR 
 *  4- MADC_EXTI0
 *  5- MADC_TIM0_CTC
 *  6- MADC_TIM0_OVF 
 *  7- MADC_TIM1_CTC_CHANNEL_B 
 *  8- MADC_TIM1_OVF
 *  9- MADC_TIM1_ICU
 * 
 */
#define MADC_TRIGGERING_SOURCE   MADC_FREE_RUNNING
  

#endif /* MCAL_05_MADC_MADC_CONFIG_H_ */
