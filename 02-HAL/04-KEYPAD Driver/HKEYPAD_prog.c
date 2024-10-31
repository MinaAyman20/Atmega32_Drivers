/*
 * HKEYPAD_prog.c
 *
 *  Created on: Jan 6, 2024
 *      Author: Mina
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"
#include "HKEYPAD_interface.h"
#include "HKEYPAD_config.h"
#include "HKEYPAD_priv.h"
#include "../../MCAL/01-PORT/MPort_Interface.h"
#include "../../MCAL/00-DIO/DIO.h"
#include "../../HAL/HLCD/HLCD_interface.h"
#include <avr/delay.h>

extern HKEYPAD_enuKeypad_t KEYPAD_PinConfig [(NUMBER_OF_ROWS)*(NUMBER_OF_COLUMNS)];
extern u8 HKEYPAD_u8KEYPADMAP[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];


HKEYPAD_enuErrorStatus_t HKEYPAD_enuInit(void)
{
	HKEYPAD_enuErrorStatus_t Ret_enuKEYPADErrorStatus = HKEYPAD_enuOK;

	/*Creating struct of port configration to take Keypad pin cofigration*/
	MPORT_strConfig_t LOC_strCurrentKeypad;

	int LOC_u8Iterator = 0;

	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < NUMBER_OF_ROWS_COL ; LOC_u8Iterator++)
	{
		/* Check if the connection type is either INPUT_PULLUP or OUTPUT_HIGH */
		if((KEYPAD_PinConfig[LOC_u8Iterator].Connectiontype == HKEYPAD_enuINPUT_PULLUP) || (KEYPAD_PinConfig[LOC_u8Iterator].Connectiontype == HKEYPAD_enuOUTPUT_HIGH))
		{
			/* Set port and pin based on the configuration */
			LOC_strCurrentKeypad.Port =  KEYPAD_PinConfig[LOC_u8Iterator].Port;
			LOC_strCurrentKeypad.Pin  =  KEYPAD_PinConfig[LOC_u8Iterator].Pin ;

			 /* Set mode based on the connection type */
			if(KEYPAD_PinConfig[LOC_u8Iterator].Connectiontype == HKEYPAD_enuINPUT_PULLUP)
			{
				LOC_strCurrentKeypad.Mode = MPORT_enu_INPUT_PU;
			}
			else if(KEYPAD_PinConfig[LOC_u8Iterator].Connectiontype == HKEYPAD_enuOUTPUT_HIGH)
			{
				LOC_strCurrentKeypad.Mode =MPORT_enu_OUTPUT_HIGH;
			}
			/* Configure the port for the keypad */
			if(MPORT_enuSetConfig(&LOC_strCurrentKeypad) )
			{
				Ret_enuKEYPADErrorStatus  = HKEYPAD_enuDIOError;
			}

		}
		else
		{
			Ret_enuKEYPADErrorStatus = HKEYPAD_enuInvalidConnection;
		}

	}
	/*return error*/
	return Ret_enuKEYPADErrorStatus;
}


void HKEYPAD_enuGetKey(u8 *Add_pKeyStatus)
{
	//HKEYPAD_enuErrorStatus_t Ret_enuKEYPADErrorStatus = HKEYPAD_enuOK;
	u8 LOC_u8CurrentCol = 0 ;
	u8 LOC_u8CurrentRow = 0 ;
	u8 LOC_u8CurrentRowStatus = 0 ;
	*Add_pKeyStatus=NULL;          // Initialize the key status
	while(1)
	{
		for(LOC_u8CurrentCol = KEYPAD_COL_START  ; LOC_u8CurrentCol< NUMBER_OF_ROWS_COL; LOC_u8CurrentCol++)
		{
			// Set the current column LOW to scan the rows
			DIO_enuSetPinValue(KEYPAD_PinConfig[ LOC_u8CurrentCol ].Port, KEYPAD_PinConfig[ LOC_u8CurrentCol ].Pin,MPORT_enuLOW );

			for(LOC_u8CurrentRow = KEYPAD_ROW_START ; LOC_u8CurrentRow < NUMBER_OF_ROWS ; LOC_u8CurrentRow++)
			{
				 // Read the status of the current row
				DIO_enuGetPinValue(KEYPAD_PinConfig[ LOC_u8CurrentRow ].Port,KEYPAD_PinConfig[ LOC_u8CurrentRow].Pin,&LOC_u8CurrentRowStatus );
				// Check if a key is pressed
				if(LOC_u8CurrentRowStatus == MPORT_enuLOW )
				{
					// Update the key status based on the key map
					*Add_pKeyStatus= HKEYPAD_u8KEYPADMAP[ LOC_u8CurrentRow ][LOC_u8CurrentCol - NUMBER_OF_COLUMNS ];

					 // Debouncing delays
					_delay_ms(10);

					while(LOC_u8CurrentRowStatus == MPORT_enuLOW)
					{
						DIO_enuGetPinValue(KEYPAD_PinConfig[ LOC_u8CurrentRow].Port,KEYPAD_PinConfig[LOC_u8CurrentRow].Pin,&LOC_u8CurrentRowStatus );
					}
					_delay_ms(10);
					// Break out of the row scanning loop
					break;
				}

			}
			 // Set the current column HIGH after scanning
			DIO_enuSetPinValue(KEYPAD_PinConfig[LOC_u8CurrentCol].Port, KEYPAD_PinConfig[LOC_u8CurrentCol].Pin,MPORT_enuHIGH );
			// Check if a key is detected, and exit the column scanning loop
			if(*Add_pKeyStatus != NULL)
			{
				break;
			}
			else
			{
				//do nothing
			}
		}
		// Check if a key is detected, and exit the main loop
		if(*Add_pKeyStatus != NULL)
		{
			break;
		}
	else
		{
			//do nothing
		}
	}

}

