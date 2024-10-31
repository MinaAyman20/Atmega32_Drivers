/*
 * MADC_prog.c
 *
 *  Created on: Feb 7, 2024
 *      Author: Mina
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"

#include "MADC_interface.h"
#include "MADC_config.h"
#include "MADC_priv.h"

/*Global pointer to function to carry the notification function called by ISR*/
static void (*MADC_pvCBFunc)(void)= NULL;

/* Global pointer to carry the conversion result in the Asynchronous execution */
static u16* MADC_pu16AsynchConversionResult = NULL;

/*Global Chain To Save the User Input */
static Chain_t MADC_GChain;

/*Global flag for the ADC ISR State*/
static u8 MADC_u8ISRState ;

/*Global for Channel index in Chaining mode */
u8 MADC_ChannelIndex =0;


MADC_enuADCErrorStatus_t MADC_enuADCInit(void)
{
    u8 LOC_u8ADCRegValue = 0;
    MADC_enuADCErrorStatus_t Ret_enuADCErrorStatus = MADC_enuOK;

    // Check if ADC module is disabled
    if (MADC_STATE == MADC_DISABLE)
    {
        Ret_enuADCErrorStatus = MADC_enuDISABLED;
    }
    else
    {
        // Enable ADC module
        ADCSRA |= (1 << ADCSRA_ADEN);

        // Configure voltage reference for ADC
        LOC_u8ADCRegValue = ADMUX;
        LOC_u8ADCRegValue &= ADMUX_VOLTAGE_REFRENCE_CLEAR_MASK;
        LOC_u8ADCRegValue |= MADC_VOLTAGEREF;
        ADMUX = LOC_u8ADCRegValue;

        // Configure data adjustment mode
        if (MADC_DATA_ADJUST == MADC_LEFT_ADJUST)
        {
            ADMUX |= (1 << ADMUX_ADLAR); // Set ADLAR bit for left adjustment
        }
        else if (MADC_DATA_ADJUST == MADC_RIGHT_ADJUST)
        {
            ADMUX &= ~(1 << ADMUX_ADLAR); // Clear ADLAR bit for right adjustment
        }
        else
        {
            Ret_enuADCErrorStatus = MADC_enuDATA_ADJUST_ERROR;
        }

        // Configure ADC prescaler
        LOC_u8ADCRegValue = ADCSRA;
        LOC_u8ADCRegValue &= ADCSRA_PRESCALLER_CLEAR_MASK;
        LOC_u8ADCRegValue |= MADC_PRESCALLER;
        ADCSRA = LOC_u8ADCRegValue;

        // Configure ADC interrupt enable/disable based on MADC_INT_STATUS
        if (MADC_INT_STATUS == MADC_INT_ENABLE)
        {
            ADCSRA |= (1 << ADCSRA_ADIE); // Set ADIE bit for Enable Interrupt
        }
        else if (MADC_INT_STATUS == MADC_INT_DISABLE)
        {
            ADCSRA &= ~(1 << ADCSRA_ADIE); // Clear ADIE bit for Disable Interrupt
        }
        else
        {
            Ret_enuADCErrorStatus = MADC_enuINT_STATUS_ERROR;
        }
    }

    return Ret_enuADCErrorStatus;
}

MADC_enuADCErrorStatus_t MADC_u8StartConversionSync(u8 Copy_u8Channel, u16* Copy_pu16Result)
{
    // Initialize local variables
    u16 LOC_u16Digital_Read = 0;
    u32 Local_u32TimeoutCounter = 0;
    MADC_enuADCErrorStatus_t Ret_enuADCErrorStatus = MADC_enuOK;

    // Ensure automatic trigger mode is enabled
    ADCSRA |= (1 << ADCSRA_ADATE);

    // Check if the result pointer is valid
    if (Copy_pu16Result != NULL)
    {
        // Select the ADC channel
        ADMUX &= ADMUX_ANALOG_CHANNEL_AND_GAIN_SELECTION_CLEAR_MASK;
        ADMUX |= Copy_u8Channel;

        // Start ADC conversion
        ADCSRA |= (1 << ADCSRA_ADSC);

        // Wait for conversion to complete or timeout
        while (((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0) && (Local_u32TimeoutCounter < MADC_TIMEOUT))
        {
            Local_u32TimeoutCounter++;
        }

        // Check for timeout error
        if (Local_u32TimeoutCounter == MADC_TIMEOUT)
        {
            Ret_enuADCErrorStatus = MADC_enuTIMEOUT_STATE_ERROR;
        }
        else
        {
            // Clear ADC interrupt flag
            ADCSRA |= (1 << ADCSRA_ADIF);

            // Assign ADC result to the provided pointer
            *Copy_pu16Result = ADC;
        }
    }
    else
    {
        // Set error status if the result pointer is NULL
        Ret_enuADCErrorStatus = MADC_enuNULL_POINTER_ERROR;
    }

    return Ret_enuADCErrorStatus;
}


MADC_enuADCErrorStatus_t MADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_pu16Result, void (*Copy_pvEndOfJobFunc)(void)) {
    u32 Local_u32TimeoutCounter = 0;
    MADC_enuADCErrorStatus_t Ret_enuADCErrorStatus = MADC_enuOK;

    if ((Copy_pu16Result != NULL) && (Copy_pvEndOfJobFunc!= NULL)) {
        // Set asynchronous conversion state
        MADC_u8ISRState = SINGLE_CHANNEL_ASYNCH;

        // Assign result pointer and callback function pointer
        MADC_pu16AsynchConversionResult = Copy_pu16Result;
        MADC_pvCBFunc = Copy_pvEndOfJobFunc;

        // Select the Channel of ADC 
        ADMUX &= ADMUX_ANALOG_CHANNEL_AND_GAIN_SELECTION_CLEAR_MASK;
        ADMUX |= Copy_u8Channel;
        
		/*Enable Global Interrupt*/
        SREG |= (1 << 7);
        // Start Conversion and enable ADC interrupt
        ADCSRA |= (1 << ADCSRA_ADSC) | (1 << ADCSRA_ADIE);
    } else
	 {
        Ret_enuADCErrorStatus = MADC_enuNULL_POINTER_ERROR;
     }
    return Ret_enuADCErrorStatus;
}

MADC_enuADCErrorStatus_t MADC_u8StartChainAsynch(Chain_t *Copy_Chain)
{
    MADC_enuADCErrorStatus_t Ret_enuADCErrorStatus = MADC_enuOK;
    u8 LOC_u8ADCRegValue = 0;

    // Check if the provided chain structure and its elements are valid
    if ((Copy_Chain != NULL) && (Copy_Chain->Channel != NULL) && (Copy_Chain->CB != NULL) && (Copy_Chain->Result != NULL))
    {
        // Set the ADC state to indicate chained-channel asynchronous mode
        MADC_u8ISRState = CHAIN_CHANNEL_ASYNCH;

        /* Assign the ADC data globally */
        MADC_pu16AsynchConversionResult = Copy_Chain->Result;
        MADC_GChain.Channel = Copy_Chain->Channel;
        MADC_GChain.Size = Copy_Chain->Size;
        MADC_GChain.CB = Copy_Chain->CB;

        // Select the conversion channel for the first element in the chain
        LOC_u8ADCRegValue = ADMUX;
        LOC_u8ADCRegValue &= ADMUX_ANALOG_CHANNEL_AND_GAIN_SELECTION_CLEAR_MASK;
        LOC_u8ADCRegValue |= MADC_GChain.Channel[MADC_ChannelIndex];
        ADMUX = LOC_u8ADCRegValue;

        // Configure auto-triggering if enabled
        if (MADC_AUTO_TRIGGER == MADC_AUTO_TRIGGER_ENABLE)
        {
            SET_BIT(ADCSRA, ADCSRA_ADATE);
            // Select ADC triggering source
            LOC_u8ADCRegValue = SFIOR;
            LOC_u8ADCRegValue &= SFIOR_TRIGGERING_SOURCE_CLEAR_MASK;
            LOC_u8ADCRegValue |= MADC_TRIGGERING_SOURCE;
            SFIOR = LOC_u8ADCRegValue;
        }
        else
        {
            CLR_BIT(ADCSRA, ADCSRA_ADATE);
        }

        // Enable global interrupts and start ADC conversion with interrupt
        SREG |= (1 << 7);
        ADCSRA |= (1 << ADCSRA_ADSC) | (1 << ADCSRA_ADIE);
    }
    else
    {
        // If any of the elements in the chain structure is NULL, set error status
        Ret_enuADCErrorStatus = MADC_enuNULL_POINTER_ERROR;
    }

    return Ret_enuADCErrorStatus;
}


/* ISR for ADC conversion complete */
void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{
	// Check if the ADC is in single-channel asynchronous mode
	if (MADC_u8ISRState == SINGLE_CHANNEL_ASYNCH)
	{
		/*Return Conversion Result*/
		*MADC_pu16AsynchConversionResult = ADC ;

		/*Call Notification Function*/
		MADC_pvCBFunc() ;

		/*Disable the Conversion Complete Interrupt*/
		CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
	}
	// Check if the ADC is in chained-channel asynchronous mode
	else if(MADC_u8ISRState == CHAIN_CHANNEL_ASYNCH )
	{
		// Increment the channel index for the chained conversion
		MADC_ChannelIndex++;
        
		// Check if all channels in the chain have been processed
		if(MADC_ChannelIndex == MADC_GChain.Size)
		{  
			/*Return Conversion Result*/
			*MADC_pu16AsynchConversionResult = ADC ;

			// Call the callback function to notify completion of the chain
			MADC_GChain.CB();

			/*Disable the Conversion Complete Interrupt*/
			CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
		}
		else
		{
			// Update the ADC multiplexer to select the next channel in the chain
			ADMUX &= ADMUX_ANALOG_CHANNEL_AND_GAIN_SELECTION_CLEAR_MASK   ;
			ADMUX |= MADC_GChain.Channel[MADC_ChannelIndex] ;

			/*Start Conversion*/
			SET_BIT(ADCSRA ,ADCSRA_ADSC) ;
		}
	}
	// No action required if the ADC is not in any recognized state
	else
	{
		/* Do Nothing */
	}
}