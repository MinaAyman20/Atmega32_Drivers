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
//#include <string.h>


s32 Result=0;
s32 Operands[12];
u8 Operations[11];
s8 Digits[16];

u8 OperandsCounter=0;          /*How many operands entered*/
u8 OperationsCounter=0;        /*how many operations*/
u8 DigitsCounter=0;            /*how many digits is entered including math symbols*/












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
//while(1){
	//HKEYPAD_enuErrorStatus_t Ret_enuKEYPADErrorStatus = HKEYPAD_enuOK;
	u8 LOC_u8CurrentCol = 0 ;
	u8 LOC_u8CurrentRow = 0 ;
	u8 LOC_u8CurrentRowStatus = 0 ;
	*Add_pKeyStatus=NULL;          // Initialize the key status

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

		}
	else
		{
			//do nothing
		}
	}

//}

void HKEYPAD_vCalculator(void)
{

int NUM1 = 0;
int NUM2 = 0;
int Result = 0;
char Operator = 0;

// Display the prompt for the first number
HLCD_voidSendString("First Numb = ", HLCD_enuFirstLine, HLCD_enuPosition0);
HKEYPAD_enuGetKey(&NUM1);
NUM1 = NUM1 - '0';
HLCD_enuWriteNumber(NUM1);
_delay_ms(600);
HLCD_voidLCDCLR();

// Display the prompt for the operator
HLCD_voidSendString("Operator = ", HLCD_enuFirstLine, HLCD_enuPosition0);
HKEYPAD_enuGetKey(&Operator);
HLCD_voidLCDSendData(Operator);  // Display the selected operator
_delay_ms(600);
HLCD_voidLCDCLR();

// Display the prompt for the second number
HLCD_voidSendString("Second Numb = ", HLCD_enuFirstLine, HLCD_enuPosition0);
HKEYPAD_enuGetKey(&NUM2);
NUM2 = NUM2 - '0';
HLCD_enuWriteNumber(NUM2);
_delay_ms(600);
HLCD_voidLCDCLR();

// Perform the calculation based on the selected operator
switch (Operator) {
    case '+':
        Result = NUM1 + NUM2;
        break;
    case '-':
        Result = NUM1 - NUM2;
        break;
    case '*':
        Result = NUM1 * NUM2;
        break;
    case '/':
        if (NUM2 != 0) {
            Result = NUM1 / NUM2;
        } else {
            HLCD_voidSendString("Division by zero!", HLCD_enuFirstLine, HLCD_enuPosition0);
            return;
        }
        break;
    default:
        HLCD_voidSendString("Invalid Operator", HLCD_enuFirstLine, HLCD_enuPosition0);
        return;
}

// Display the result
HLCD_voidSendString("Result = ", HLCD_enuSecondLine, HLCD_enuPosition0);
HLCD_enuWriteNumber(Result);

_delay_ms(1000);

HLCD_voidLCDCLR();

}









/*void HKEYPAD_vCalculator(void) {
    int NUM1 = 0;
    int NUM2 = 0;
    int Result = 0;
    char Operator = 0;

    // Display the prompt for the first number
    HLCD_voidSendString("First Numb = ", HLCD_enuFirstLine, HLCD_enuPosition0);
    HKEYPAD_enuGetKey(&NUM1);
    while (NUM1 == '=') {
        HKEYPAD_enuGetKey(&NUM1);  // Make sure NUM1 is not '=' initially
        NUM1 = NUM1 - '0';
    }
    HLCD_enuWriteNumber(NUM1);
    _delay_ms(600);
    HLCD_voidLCDCLR();

    // Display the prompt for the operator
    HLCD_voidSendString("Operator = ", HLCD_enuFirstLine, HLCD_enuPosition0);
    HKEYPAD_enuGetKey(&Operator);
    HLCD_voidLCDSendData(Operator);  // Display the selected operator
    _delay_ms(600);
    HLCD_voidLCDCLR();

    // Display the prompt for the second number
    HLCD_voidSendString("Second Numb = ", HLCD_enuFirstLine, HLCD_enuPosition0);
    //HKEYPAD_enuGetKey(&NUM2);
    while (NUM2 == '=') {
        HKEYPAD_enuGetKey(&NUM2);  // Make sure NUM2 is not '=' initially
        NUM1 = NUM1 - '0';
    }
    HLCD_enuWriteNumber(NUM2);
    _delay_ms(600);
    HLCD_voidLCDCLR();

    // Allow user to enter more digits for NUM1 and NUM2
    while (1) {
        char key = 0;
        HKEYPAD_enuGetKey(&key);

        if (key == '=') {
            break;  // Exit the loop when equal button is pressed
        } else if (key >= '0' && key <= '9') {
            if (NUM1 < 10) {
                // Append to NUM1 if it is a single-digit number
                NUM1 = NUM1 * 10 + (key - '0');
            } else {
                // Append to NUM2 if NUM1 is already a double-digit number
                NUM2 = NUM2 * 10 + (key - '0');
            }
            HLCD_enuWriteNumber(NUM1);  // Display NUM1 or NUM2, depending on the condition
            _delay_ms(600);
            HLCD_voidLCDCLR();
        }
    }

    // Perform the calculation based on the selected operator
    switch (Operator) {
        case '+':
            Result = NUM1 + NUM2;
            break;
        case '-':
            Result = NUM1 - NUM2;
            break;
        case '*':
            Result = NUM1 * NUM2;
            break;
        case '/':
            if (NUM2 != 0) {
                Result = NUM1 / NUM2;
            } else {
                HLCD_voidSendString("Division by zero!", HLCD_enuFirstLine, HLCD_enuPosition0);
                return;
            }
            break;
        default:
            HLCD_voidSendString("Invalid Operator", HLCD_enuFirstLine, HLCD_enuPosition0);
            return;
    }

    // Display the result
    HLCD_voidSendString("Result = ", HLCD_enuSecondLine, HLCD_enuPosition0);
    HLCD_enuWriteNumber(Result);

    _delay_ms(1000);

    HLCD_voidLCDCLR();
}*/

