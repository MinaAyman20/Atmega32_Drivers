/*
 * HKEYPAD_config.c

 *
 *  Created on: Jan 6, 2024
 *      Author: Mina
 */

#include "HKEYPAD_interface.h"
#include "HKEYPAD_config.h"
#include "../../MCAL/01-PORT/MPort_Interface.h"

HKEYPAD_enuKeypad_t KEYPAD_PinConfig [(NUMBER_OF_ROWS)*(NUMBER_OF_COLUMNS)]=
{
		[ROW_1 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_0,
				.Connectiontype = HKEYPAD_enuINPUT_PULLUP
		},

		[ROW_2 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_1,
				.Connectiontype = HKEYPAD_enuINPUT_PULLUP
		},

		[ROW_3 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_2,
				.Connectiontype = HKEYPAD_enuINPUT_PULLUP
		},

		[ROW_4 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_3,
				.Connectiontype = HKEYPAD_enuINPUT_PULLUP
		},

		[COL_1 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_4,
				.Connectiontype = HKEYPAD_enuOUTPUT_HIGH
		},

		[COL_2 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_5,
				.Connectiontype = HKEYPAD_enuOUTPUT_HIGH
		},

		[COL_3 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_6,
				.Connectiontype = HKEYPAD_enuOUTPUT_HIGH
		},

		[COL_4 ]=
		{
				.Port           = MPORT_enuPort_A,
				.Pin            = MPORT_enuPin_7,
				.Connectiontype = HKEYPAD_enuOUTPUT_HIGH
		}
};


const u8 HKEYPAD_u8KEYPADMAP[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] =
{
	    	{'7','8','9','/'},
			{'4','5','6','*'},
			{'1','2','3','-'},
			{'#','0','=','+'}
};
