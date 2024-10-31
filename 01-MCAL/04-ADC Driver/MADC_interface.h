/*
 * MADC_interface.h
 *
 *  Created on: Feb 7, 2024
 *      Author: Mina
 */

#ifndef MCAL_05_MADC_MADC_INTERFACE_H_
#define MCAL_05_MADC_MADC_INTERFACE_H_

// Definition of function pointer type for callback function
typedef void (*CB_FUNC)(void);

// Definitions of ADC module states
#define MADC_DISABLE 0
#define MADC_ENABLE  1

// Definitions of data adjustment modes
#define MADC_RIGHT_ADJUST     0
#define MADC_LEFT_ADJUST      1

// Definitions of interrupt enable/disable states
#define MADC_INT_DISABLE      0
#define MADC_INT_ENABLE       1

// Definitions of auto-triggering enable/disable states
#define MADC_AUTO_TRIGGER_DISABLE    0
#define MADC_AUTO_TRIGGER_ENABLE     1 

// Definitions of ADC clock prescaler options
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_2      0x01
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_4      0x02
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_8      0x03
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_16     0x04
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_32     0x05
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_64     0x06
#define MADC_CLOCK_SELECT_PRESCALLER_OVER_128    0x07


// Definitions for ADC voltage reference options
#define MADC_AREF                    0x00   // External AREF pin voltage reference
#define MADC_AVCC                    0x40   // AVCC pin voltage reference
#define MADC_2_56V_INTERNAL          0xC0   // Internal 2.56V voltage reference

// Definitions for single-ended ADC channel options
#define MADC_ADC0_SINGLE_ENDEDD                                   0X00
#define MADC_ADC1_SINGLE_ENDEDD                                   0X01
#define MADC_ADC2_SINGLE_ENDEDD                                   0X02
#define MADC_ADC3_SINGLE_ENDEDD                                   0X03
#define MADC_ADC4_SINGLE_ENDEDD                                   0X04
#define MADC_ADC5_SINGLE_ENDEDD                                   0X05
#define MADC_ADC6_SINGLE_ENDEDD                                   0X06
#define MADC_ADC7_SINGLE_ENDEDD                                   0X07

#define MADC_DIFFRITIAL_ADC0_ADC0_GAINx10                         0X08
#define MADC_DIFFRITIAL_ADC1_ADC0_GAINx10                         0X09
#define MADC_DIFFRITIAL_ADC0_ADC0_GAINx200                        0X0A
#define MADC_DIFFRITIAL_ADC1_ADC0_GAINx200                        0X0B
#define MADC_DIFFRITIAL_ADC2_ADC2_GAINx10                         0X0C
#define MADC_DIFFRITIAL_ADC3_ADC2_GAINx10                         0X0D
#define MADC_DIFFRITIAL_ADC2_ADC2_GAINx200                        0X0E
#define MADC_DIFFRITIAL_ADC3_ADC2_GAINx200                        0X0F
#define MADC_DIFFRITIAL_ADC0_ADC1_GAINx1                          0X10
#define MADC_DIFFRITIAL_ADC1_ADC1_GAINx1                          0X11
#define MADC_DIFFRITIAL_ADC2_ADC1_GAINx1                          0X12
#define MADC_DIFFRITIAL_ADC3_ADC1_GAINx1                          0X13
#define MADC_DIFFRITIAL_ADC4_ADC1_GAINx1                          0X14
#define MADC_DIFFRITIAL_ADC5_ADC1_GAINx1                          0X15
#define MADC_DIFFRITIAL_ADC6_ADC1_GAINx1                          0X16
#define MADC_DIFFRITIAL_ADC7_ADC1_GAINx1                          0X17
#define MADC_DIFFRITIAL_ADC0_ADC2_GAINx1                          0X18
#define MADC_DIFFRITIAL_ADC1_ADC2_GAINx1                          0X19
#define MADC_DIFFRITIAL_ADC2_ADC2_GAINx1                          0X1A
#define MADC_DIFFRITIAL_ADC3_ADC2_GAINx1                          0X1B
#define MADC_DIFFRITIAL_ADC4_ADC2_GAINx1                          0X1C
#define MADC_DIFFRITIAL_ADC5_ADC2_GAINx1                          0X1D


// Definitions for ADC trigger sources
#define MADC_SINGLE_CONVERSION   0x00
#define MADC_FREE_RUNNING        0x00
#define MADC_ANALOG_COMPARATOR   0x20
#define MADC_EXTI0               0x40
#define MADC_TIM0_CTC            0x60
#define MADC_TIM0_OVF            0x80
#define MADC_TIM1_CTC_CHANNEL_B  0xA0
#define MADC_TIM1_OVF            0xC0
#define MADC_TIM1_ICU            0xE0

// Enumeration for ADC error status
typedef enum
{
	  MADC_enuOK,
	  MADC_enuNOK,
	  MADC_enuDISABLED,
	  MADC_enuDATA_ADJUST_ERROR,
	  MADC_enuINT_STATUS_ERROR ,
	  MADC_enuNULL_POINTER_ERROR,
	  MADC_enuTIMEOUT_STATE_ERROR ,
}MADC_enuADCErrorStatus_t;

// Structure definition for ADC chain conversion
typedef struct{

	u8* Channel;
	u16* Result;
	u8 Size;
	CB_FUNC CB;
}Chain_t;

// Function prototypes for ADC operations
MADC_enuADCErrorStatus_t MADC_enuADCInit(void);
MADC_enuADCErrorStatus_t MADC_u8StartConversionSync  ( u8 Copy_u8Channel , u16* Copy_pu16Result );
MADC_enuADCErrorStatus_t MADC_u8StartConversionAsynch( u8 Copy_u8Channel , u16* Copy_pu16Reading , void(*Copy_pvEndOfJobFunc)(void) );
MADC_enuADCErrorStatus_t MADC_u8StartChainAsynch     ( Chain_t * Copy_Chain);

#endif 
