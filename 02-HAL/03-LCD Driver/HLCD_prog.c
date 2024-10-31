/************************************************************************************************************************/
/*File          :       HLCD_prog.c                                                                                     */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/
#include "HLCD_interface.h"
#include "HLCD_priv.h"
#include "HLCD_config.h"
#include "../../MCAL/01-PORT/MPort_Interface.h"
#include "../../MCAL/00-DIO/DIO.h"
#include <util/delay.h>


extern  HLCD_strLCDPinConfigration LCD_Config;

HLCD_enuErrorStatus_t HLCD_enuLCDPinConfigration(void)
{
	HLCD_enuErrorStatus_t Ret_enuLCDErrorStatus = HLCD_enuOK;
	MPORT_strConfig_t LOC_strCurrentLCD;

	/*********************************************ALL PINS****************************************************/

	/*********************************************DATABIT0****************************************************/


	LOC_strCurrentLCD.Port = LCD_Config.DATABIT0.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT0.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT1****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT1.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT1.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT2****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT2.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT2.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT3****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT3.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT3.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT4****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT4.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT4.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT5****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT5.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT5.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT6****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT6.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT6.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************DATABIT7****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.DATABIT7.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.DATABIT7.PinNum ;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/**********************************************ENABLE*****************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.ENABLE.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.ENABLE.PinNum;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/************************************************RS************************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.RS.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.RS.PinNum;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus  = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/************************************************RW************************************************************/

	LOC_strCurrentLCD.Port = LCD_Config.RW.PortNum;
	LOC_strCurrentLCD.Pin  = LCD_Config.RW.PinNum;
	LOC_strCurrentLCD.Mode = MPORT_enu_OUTPUT_LOW;
	Ret_enuLCDErrorStatus = MPORT_enuSetConfig(&LOC_strCurrentLCD);

	/*********************************************End Of Initlization***********************************************************************/


	return Ret_enuLCDErrorStatus;
}


void HLCD_voidLCDSendCommand(u8 Copy_u8Command)
{ 
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
	/*let the RS pin LOW to send command*/
	DIO_enuSetPinValue(LCD_Config.RS.PortNum,LCD_Config.RS.PinNum,MPORT_enuLOW);
	/*let the RW pin LOW to Write command*/
	DIO_enuSetPinValue(LCD_Config.RW.PortNum,LCD_Config.RW.PinNum,MPORT_enuLOW);
	/*for loop to send command on the pins which intlized in the config file */

	for (int LOC_u8Counter = 0; LOC_u8Counter  < NUMBER_OF_LCD_PINS_8BIT; LOC_u8Counter ++) {
		// Extract each bit of the command
		u8 LOC_u8bitValue = (Copy_u8Command >> LOC_u8Counter ) & 0x01;

		// Set the bitValue to the respective data pin using DIO_enuSetPinValue
		MPORT_enuPORT_OPTS_t    LOC_enucurrentPort;
		MPORT_enuPIN_OPTS_t     LOC_enucurrentPin;

		/*switch on the counter number to Write on each data bit from 0 to 8 */

		switch (LOC_u8Counter ) {
		case 0: LOC_enucurrentPort = LCD_Config.DATABIT0.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT0.PinNum; break;
		case 1: LOC_enucurrentPort = LCD_Config.DATABIT1.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT1.PinNum; break;
		case 2: LOC_enucurrentPort = LCD_Config.DATABIT2.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT2.PinNum; break;
		case 3: LOC_enucurrentPort = LCD_Config.DATABIT3.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT3.PinNum; break;
		case 4: LOC_enucurrentPort = LCD_Config.DATABIT4.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT4.PinNum; break;
		case 5: LOC_enucurrentPort = LCD_Config.DATABIT5.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT5.PinNum; break;
		case 6: LOC_enucurrentPort = LCD_Config.DATABIT6.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT6.PinNum; break;
		case 7: LOC_enucurrentPort = LCD_Config.DATABIT7.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT7.PinNum; break;
		default:                                                                                                  break;
		}

		/*after each case we use set pin value function to set the pin with its port and pin and the bit of the command*/
		DIO_enuSetPinValue(LOC_enucurrentPort, LOC_enucurrentPin, LOC_u8bitValue);
	}
	/*Set the Enabel pin High */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuHIGH);
	/*delay 2ms*/
	_delay_ms(2);
	/*Set the Enabel pin Low */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuLOW);
	/*delay 2ms*/
	_delay_ms(2);

#elif HLCD_BIT_MODE  ==  HLCD_enu4BIT_MODE

	/*let the RS pin LOW to send command*/
	DIO_enuSetPinValue(LCD_Config.RS.PortNum,LCD_Config.RS.PinNum,MPORT_enuLOW);
	/*let the RW pin LOW to Write command*/
	DIO_enuSetPinValue(LCD_Config.RW.PortNum,LCD_Config.RW.PinNum,MPORT_enuLOW);
	/*for loop to send command on the pins which intlized in the config file */

	for (int LOC_u8Counter = 4 ; LOC_u8Counter  < NUMBER_OF_LCD_PINS_8BIT ; LOC_u8Counter ++) {
		// Extract each bit of the data
		u8 LOC_u8bitValue = (Copy_u8Command >> (LOC_u8Counter)) & 0x01;

		// Set the bitValue to the respective data pin using DIO_enuSetPinValue
		MPORT_enuPORT_OPTS_t    LOC_enucurrentPort;
		MPORT_enuPIN_OPTS_t     LOC_enucurrentPin;

		/*switch on the counter number to Write on each data bit from 4 to 8 to set high nibble first */
		switch (LOC_u8Counter ) {
		case 4: LOC_enucurrentPort = LCD_Config.DATABIT4.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT4.PinNum; break;
		case 5: LOC_enucurrentPort = LCD_Config.DATABIT5.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT5.PinNum; break;
		case 6: LOC_enucurrentPort = LCD_Config.DATABIT6.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT6.PinNum; break;
		case 7: LOC_enucurrentPort = LCD_Config.DATABIT7.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT7.PinNum; break;
		default:                                                                                                  break;
		}

		/*after each case we use set pin value function to set the pin with its port and pin and the bit of the command*/
		DIO_enuSetPinValue(LOC_enucurrentPort, LOC_enucurrentPin, LOC_u8bitValue);
	}
	/*Set the Enabel pin High */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuHIGH);
	/*delay 2ms*/
	_delay_ms(2);
	/*Set the Enabel pin Low */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuLOW);
	/*delay 2ms*/
	_delay_ms(2);
	/************************************************for low nibble****************************************/
	/*for loop to send command on the pins which intlized in the config file */
	for (int LOC_u8Counter = 0; LOC_u8Counter  < NUMBER_OF_LCD_PINS_4BIT; LOC_u8Counter ++) {
		// Extract each bit of the data
		u8 LOC_u8bitValue = (Copy_u8Command >> (LOC_u8Counter )) & 0x01;

		MPORT_enuPORT_OPTS_t    LOC_enucurrentPort;
		MPORT_enuPIN_OPTS_t     LOC_enucurrentPin;

		/*switch on the counter number to Write on each data bit from 0 to 4 to set Low nibble */
		switch (LOC_u8Counter ) {
		case 0: LOC_enucurrentPort = LCD_Config.DATABIT4.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT4.PinNum; break;
		case 1: LOC_enucurrentPort = LCD_Config.DATABIT5.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT5.PinNum; break;
		case 2: LOC_enucurrentPort = LCD_Config.DATABIT6.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT6.PinNum; break;
		case 3: LOC_enucurrentPort = LCD_Config.DATABIT7.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT7.PinNum; break;
		default:                                                                                                  break;
		}
		/*after each case we use set pin value function to set the pin with its port and pin and the bit of the command*/

		DIO_enuSetPinValue(LOC_enucurrentPort, LOC_enucurrentPin, LOC_u8bitValue);
	}
	/*Set the Enabel pin High */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuHIGH);
	/*delay 2ms*/
	_delay_ms(2);
	/*Set the Enabel pin Low */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuLOW);
	/*delay 2ms*/
	_delay_ms(2);

#endif

}

void HLCD_voidLCDSendData(u8 Copy_u8Data)
{
#if HLCD_BIT_MODE == HLCD_enu8BIT_MODE
	/*let the RS pin HIGH to send DATA*/
	DIO_enuSetPinValue(LCD_Config.RS.PortNum,LCD_Config.RS.PinNum,MPORT_enuHIGH);
	/*let the RW pin LOW to Write DATA*/
	DIO_enuSetPinValue(LCD_Config.RW.PortNum,LCD_Config.RW.PinNum,MPORT_enuLOW);
	/*for loop to send command on the pins which intlized in the config file */

	for (int LOC_u8Counter = 0; LOC_u8Counter  < NUMBER_OF_LCD_PINS_8BIT; LOC_u8Counter ++) {
		// Extract each bit of the data
		u8 LOC_u8bitValue = (Copy_u8Data >> LOC_u8Counter ) & 0x01;

		// Set the bitValue to the respective data pin using DIO_enuSetPinValue
		MPORT_enuPORT_OPTS_t    LOC_enucurrentPort;
		MPORT_enuPIN_OPTS_t     LOC_enucurrentPin;

		/*switch on the counter number to Write on each data bit from 0 to 8 */

		switch (LOC_u8Counter ) {
		case 0: LOC_enucurrentPort = LCD_Config.DATABIT0.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT0.PinNum; break;
		case 1: LOC_enucurrentPort = LCD_Config.DATABIT1.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT1.PinNum; break;
		case 2: LOC_enucurrentPort = LCD_Config.DATABIT2.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT2.PinNum; break;
		case 3: LOC_enucurrentPort = LCD_Config.DATABIT3.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT3.PinNum; break;
		case 4: LOC_enucurrentPort = LCD_Config.DATABIT4.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT4.PinNum; break;
		case 5: LOC_enucurrentPort = LCD_Config.DATABIT5.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT5.PinNum; break;
		case 6: LOC_enucurrentPort = LCD_Config.DATABIT6.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT6.PinNum; break;
		case 7: LOC_enucurrentPort = LCD_Config.DATABIT7.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT7.PinNum; break;
		default:                                                                                                  break;
		}

		/*after each case we use set pin value function to set the pin with its port and pin and the bit of the command*/
		DIO_enuSetPinValue(LOC_enucurrentPort, LOC_enucurrentPin, LOC_u8bitValue);
	}
	/*Set the Enabel pin High */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuHIGH);
	/*delay 2ms*/
	_delay_ms(2);
	/*Set the Enabel pin Low */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuLOW);
	/*delay 2ms*/
	_delay_ms(2);

#elif HLCD_BIT_MODE  ==  HLCD_enu4BIT_MODE

	/*let the RS pin HIGH to send DATA*/
	DIO_enuSetPinValue(LCD_Config.RS.PortNum,LCD_Config.RS.PinNum,MPORT_enuHIGH);
	/*let the RW pin LOW to Write DATA*/
	DIO_enuSetPinValue(LCD_Config.RW.PortNum,LCD_Config.RW.PinNum,MPORT_enuLOW);

	/*for loop to send command on the pins which intalized in the config file */
	for (int LOC_u8Counter = 4; LOC_u8Counter  < NUMBER_OF_LCD_PINS_8BIT; LOC_u8Counter ++) {
		// Extract each bit of the data
		u8 LOC_u8bitValue = (Copy_u8Data >> (LOC_u8Counter )) & 0x01;

		MPORT_enuPORT_OPTS_t    LOC_enucurrentPort;
		MPORT_enuPIN_OPTS_t     LOC_enucurrentPin;
		/*switch on the counter number to Write on each data bit from 4 to 8 to set high nibble first */

		switch (LOC_u8Counter ) {
		case 4: LOC_enucurrentPort = LCD_Config.DATABIT4.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT4.PinNum; break;
		case 5: LOC_enucurrentPort = LCD_Config.DATABIT5.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT5.PinNum; break;
		case 6: LOC_enucurrentPort = LCD_Config.DATABIT6.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT6.PinNum; break;
		case 7: LOC_enucurrentPort = LCD_Config.DATABIT7.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT7.PinNum; break;
		default:                                                                                                  break;
		}
		/*after each case we use set pin value function to set the pin with its port and pin and the bit of the command*/

		DIO_enuSetPinValue(LOC_enucurrentPort, LOC_enucurrentPin, LOC_u8bitValue);
	}
	/*let the Enabel pin High */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuHIGH);
	/*delay 2ms*/
	_delay_ms(2);
	/*let the Enabel pin Low */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuLOW);
	/*delay 2ms*/
	_delay_ms(2);
	/************************************************for low nibble *****************************************/
	/*for loop to send command on the pins which intlized in the config file */
	for (int LOC_u8Counter = 0; LOC_u8Counter  < NUMBER_OF_LCD_PINS_4BIT; LOC_u8Counter ++) {
		// Extract each bit of the data
		u8 LOC_u8bitValue = (Copy_u8Data >> (LOC_u8Counter )) & 0x01;

		MPORT_enuPORT_OPTS_t    LOC_enucurrentPort;
		MPORT_enuPIN_OPTS_t     LOC_enucurrentPin;
		/*switch on the counter number to Write on each data bit from 0 to 4 to set Low nibble */

		switch (LOC_u8Counter ) {
		case 0: LOC_enucurrentPort = LCD_Config.DATABIT4.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT4.PinNum; break;
		case 1: LOC_enucurrentPort = LCD_Config.DATABIT5.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT5.PinNum; break;
		case 2: LOC_enucurrentPort = LCD_Config.DATABIT6.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT6.PinNum; break;
		case 3: LOC_enucurrentPort = LCD_Config.DATABIT7.PortNum; LOC_enucurrentPin = LCD_Config.DATABIT7.PinNum; break;
		default:                                                                                                  break;
		}
		/*after each case we use set pin value function to set the pin with its port and pin and the bit of the command*/

		DIO_enuSetPinValue(LOC_enucurrentPort, LOC_enucurrentPin, LOC_u8bitValue);
	}
	/*Set the Enabel pin High */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuHIGH);
	/*delay 2ms*/
	_delay_ms(2);
	/*Set the Enabel pin Low */
	DIO_enuSetPinValue(LCD_Config.ENABLE.PortNum,LCD_Config.ENABLE.PinNum,MPORT_enuLOW);
	/*delay 2ms*/
	_delay_ms(2);

#endif

}

void HLCD_voidLCDInit(void)
{
#if   HLCD_BIT_MODE  ==  HLCD_enu8BIT_MODE
	/*Sending FunctionSet Command for 8 Bit Mode*/
	HLCD_voidLCDSendCommand( HLCD_FUNCTION_SET_8BIT_CMD );
	/*delay 2ms*/
	_delay_ms(2);

	/*Sending Display on/off Command for 8 Bit Mode*/
	HLCD_voidLCDSendCommand( HLCD_DISPLAY_ON_OFF_8BIT_CMD );
	/*delay 2ms*/
	_delay_ms(2);

	/*Sending Clear Display Command for 8 Bit Mode*/
	HLCD_voidLCDSendCommand( HLCD_CLEAR_DISPLAY_8BIT_CMD);
	/*delay 2ms*/
	_delay_ms(2);

	/*Sending Entry Mode Command for 8 Bit Mode*/
	HLCD_voidLCDSendCommand(HLCD_ENTRY_MODE_8BIT_CMD );
	/*delay 2ms*/
	_delay_ms(2);

#elif HLCD_BIT_MODE  ==  HLCD_enu4BIT_MODE

	/*Sending Fixed FunctionSet Command for 8 Bit Mode*/
	HLCD_voidLCDSendCommand( HLCD_Fixed1_FunctionSet_4BIT_CMD );
	/*delay 2ms*/
	_delay_ms(2);

	HLCD_voidLCDSendCommand( HLCD_FUNCTION_SET_4BIT_CMD );
	_delay_ms(2);

	HLCD_voidLCDSendCommand( HLCD_DISPLAY_ON_OFF_4BIT_CMD );
	_delay_ms(2);

	HLCD_voidLCDSendCommand( HLCD_CLEAR_DISPLAY_4BIT_CMD);
	_delay_ms(2);

	HLCD_voidLCDSendCommand(HLCD_ENTRY_MODE_4BIT_CMD );
	_delay_ms(2);



	/*HLCD_voidLCDSendCommand(0x02);
	_delay_ms(2);

	HLCD_voidLCDSendCommand( 0x28 );
	_delay_ms(2);

	HLCD_voidLCDSendCommand(0x0E );
	_delay_ms(2);

	HLCD_voidLCDSendCommand( 0x01 );
	_delay_ms(2);

	HLCD_voidLCDSendCommand( 0x80 );
	_delay_ms(1);*/


#endif
}

HLCD_enuErrorStatus_t HLCD_voidLCDGoToDDRAMLoc(HLCD_enuDDRAM_XPosition Copy_u8XPosition,HLCD_enuDDRAM_YPosition Copy_u8YPosition)
{ 
	HLCD_enuErrorStatus_t Ret_enuLCDErrorStatus = HLCD_enuOK;
	u8 Copy_u8Location = 0;
	/*Check if X Position is valid */
	if(Copy_u8XPosition > HLCD_enuSecondLine)
	{
		Ret_enuLCDErrorStatus = HLCD_enuDDRAM_XPositionError ;
	}
	/*Check if Y Position is valid */
	else if(Copy_u8YPosition >  HLCD_enuPosition15 )
	{
		Ret_enuLCDErrorStatus = HLCD_enuDDRAM_YPositionError ;
	}

	else
	{
		/*if x Position is first line*/
		if (Copy_u8XPosition == HLCD_enuFirstLine)
		{
			Copy_u8Location = Copy_u8YPosition;
		}
		/*if Y Position is Second line*/
		else
		{
			/*increment 0x40 to the address to goto the first postion of the second line*/
			Copy_u8Location = Copy_u8YPosition+0x40;
		}
		/*send command to goto postion in DDRAM */
		HLCD_voidLCDSendCommand(Copy_u8Location+128);
	}
	/*Retern Error*/
	return Ret_enuLCDErrorStatus;
}

void HLCD_voidSendString(char *copy_cstring ,HLCD_enuDDRAM_XPosition Copy_enuXPosition,HLCD_enuDDRAM_YPosition Copy_enuYPosition)
{
	u8 copy_u8Iterator =0;
	/*goto the givern postion in LCD*/
	HLCD_voidLCDGoToDDRAMLoc(Copy_enuXPosition,Copy_enuYPosition);
	/*check if the charcter is \0 or not*/
	while (copy_cstring[copy_u8Iterator]!= '\0')
	{
		/*Send data of the character*/
		HLCD_voidLCDSendData(copy_cstring[copy_u8Iterator]);
		/*increment iterator to goto next character*/
		copy_u8Iterator++;
	}
}

HLCD_enuErrorStatus_t HLCD_enuWriteNumber(u64 Copy_u32Number)
{
	u8 LOC_Digit = 0;
	u8 LOC_Index = 0;
	u8 LOC_Iterator = 0;
	u8 LOC_ReverseDigits[20] = {0}; /* Max Number Of Digits in U64 number is 20 Digit */
	HLCD_enuErrorStatus_t Ret_enuLCDErrorStatus = HLCD_enuOK;

	/* Extract each digit and convert to ASCII */
	while (Copy_u32Number > 0)
	{
		LOC_Digit = Copy_u32Number % 10;
		LOC_ReverseDigits[LOC_Index] = LOC_Digit + '0';    /* Convert The Number To ASCII Value */
		Copy_u32Number /= 10;
		LOC_Index++;
	}

	if ( Copy_u32Number < 0)
	{
		// Change number to Postive Value
		Copy_u32Number =  Copy_u32Number * (-1);
		// Send the negative sign to the LCD
		HLCD_voidLCDSendData('-');
	}

	if (LOC_Index > NUMBER_OF_LCD_COLUMNS)
	{
		/* Display the last digits on the second line */
		HLCD_voidLCDGoToDDRAMLoc(HLCD_enuSecondLine, HLCD_enuPosition0);
		for (LOC_Iterator = LOC_Index - NUMBER_OF_LCD_COLUMNS; LOC_Iterator > 0; LOC_Iterator --)
		{
			HLCD_voidLCDSendData(LOC_ReverseDigits[LOC_Iterator - 1]);
		}
		HLCD_voidLCDGoToDDRAMLoc(HLCD_enuFirstLine, HLCD_enuPosition0);
		/* Display the remaining digits on the first line */
		for (LOC_Iterator = LOC_Index; LOC_Iterator > 0; LOC_Iterator--)
		{
			HLCD_voidLCDSendData(LOC_ReverseDigits[LOC_Iterator - 1]);
		}
		/* Get the cursor back to the end of the number on the second line */
		HLCD_voidLCDGoToDDRAMLoc(HLCD_enuSecondLine, HLCD_enuPosition0);
	}
	else
	{
		/* In Case the Number Fits in a single Line */
		for (LOC_Iterator = LOC_Index; LOC_Iterator > 0; LOC_Iterator--)
		{
			HLCD_voidLCDSendData(LOC_ReverseDigits[LOC_Iterator - 1]);
		}
	}
	return Ret_enuLCDErrorStatus;
}

HLCD_enuErrorStatus_t HLCD_voidDisplaySpecialCharacter(u8 *Copy_enuPattern , HLCD_enuCGRAM_BlockNumber Copy_enuBlockNumber,\
		HLCD_enuDDRAM_XPosition Copy_enuXPosition,HLCD_enuDDRAM_YPosition Copy_enuYPosition )

{ 
	HLCD_enuErrorStatus_t Ret_enuLCDErrorStatus = HLCD_enuOK;
	u8 Copy_u8CGRAMLocation = 0;

	/*Check if Blocknumber Position is valid */
	if(Copy_enuBlockNumber > HLCD_enuBlockNumber7)
	{
		Ret_enuLCDErrorStatus = HLCD_enuBlockNumberError ;
	}
	/*Check if X Position is valid */
	else if(Copy_enuXPosition > HLCD_enuSecondLine)
	{
		Ret_enuLCDErrorStatus = HLCD_enuDDRAM_XPositionError ;
	}
	/*Check if Y Position is valid */
	else if(Copy_enuYPosition >  HLCD_enuPosition15 )
	{
		Ret_enuLCDErrorStatus = HLCD_enuDDRAM_YPositionError ;
	}
	else
	{
		/*To acess the Block*/
		Copy_u8CGRAMLocation = Copy_enuBlockNumber  * 8;
		HLCD_voidLCDSendCommand(Copy_u8CGRAMLocation+64);
		for (u8 LOC_u8iterator = 0; LOC_u8iterator  < NUMBER_OF_LCD_PINS_8BIT ;LOC_u8iterator ++)
		{
			/*to save charcter in the Block*/
			HLCD_voidLCDSendData(Copy_enuPattern[LOC_u8iterator]);
		}
		/*goto x , Y Postion*/
		HLCD_voidLCDGoToDDRAMLoc(Copy_enuXPosition,Copy_enuYPosition );
		/*Display Data which is saved*/
		HLCD_voidLCDSendData(Copy_enuBlockNumber);
	}
	/*Return Error*/
	return Ret_enuLCDErrorStatus;
}

