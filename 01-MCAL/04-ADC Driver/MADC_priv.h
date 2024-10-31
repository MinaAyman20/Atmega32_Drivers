/*
 * MADC_priv.h
 *
 *  Created on: Feb 7, 2024
 *      Author: Mina
 */

#ifndef MCAL_05_MADC_MADC_PRIV_H_
#define MCAL_05_MADC_MADC_PRIV_H_

#include "MADC_interface.h"

// Definitions for ADC register addresses
#define   ADMUX       (*(unsigned volatile char*)0x27)  // ADC Multiplexer Selection Register
#define   ADCSRA      (*(unsigned volatile char*)0x26)  // ADC Control and Status Register A
#define   ADCH        (*(unsigned volatile char*)0x25)  // ADC Data Register High
#define   ADCL        (*(unsigned volatile char*)0x24)  // ADC Data Register Low
#define   SFIOR       (*(unsigned volatile char*)0x50)  // Special Function IO Register
#define   SREG        *((unsigned volatile char*)0x5F)  // Status Register
#define   ADC         *((unsigned volatile short int*)0x24)  // ADC Data Register (16-bit)

// Bit positions in ADC Multiplexer Selection Register (ADMUX)
#define ADMUX_REFS1         7  // Reference selection bit 1
#define ADMUX_REFS0         6  // Reference selection bit 0
#define ADMUX_ADLAR         5  // ADC Left Adjust Result

// Bit positions in ADC Control and Status Register A (ADCSRA)
#define ADCSRA_ADEN         7  // ADC enable
#define ADCSRA_ADSC         6  // Start conversion
#define ADCSRA_ADATE        5  // Auto trigger enable
#define ADCSRA_ADIF         4  // Interrupt flag
#define ADCSRA_ADIE         3  // Interrupt enable
#define ADCSRA_ADPS2        2  // Prescaler bit 2
#define ADCSRA_ADPS1        1  // Prescaler bit 1
#define ADCSRA_ADPS0        0  // Prescaler bit 0


// ADC state constants for asynchronous operation
#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1


// Mask definition for clearing bits related to analog channel and gain selection in ADMUX
#define ADMUX_ANALOG_CHANNEL_AND_GAIN_SELECTION_CLEAR_MASK 0XE0

// Mask definition for clearing bits related to voltage reference selection in ADMUX
#define ADMUX_VOLTAGE_REFRENCE_CLEAR_MASK 0X3F

// Mask definition for clearing bits related to prescaler selection in ADCSRA
#define ADCSRA_PRESCALLER_CLEAR_MASK 0XF8

// Mask definition for clearing bits related to triggering source selection in SFIOR
#define SFIOR_TRIGGERING_SOURCE_CLEAR_MASK 0x1F





#endif /* MCAL_05_MADC_MADC_PRIV_H_ */
