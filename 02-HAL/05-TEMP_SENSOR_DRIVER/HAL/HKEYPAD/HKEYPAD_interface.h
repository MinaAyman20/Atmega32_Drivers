/*
 * HKEYPAD_interface.h
 *
 *  Created on: Jan 6, 2024
 *      Author: Mina
 */

#ifndef HAL_HKEYPAD_HKEYPAD_INTERFACE_H_
#define HAL_HKEYPAD_HKEYPAD_INTERFACE_H_

#include "../../MCAL/01-PORT/MPort_Interface.h"

#define  ROW_1                 0
#define  ROW_2                 1
#define  ROW_3                 2
#define  ROW_4                 3

#define  COL_1                 4
#define  COL_2                 5
#define  COL_3                 6
#define  COL_4                 7

#define KEYPAD_COL_START      COL_1
#define KEYPAD_COL_END        COL_4
#define KEYPAD_ROW_START      ROW_1
#define KEYPAD_ROW_END        ROW_4


typedef enum
{
	HKEYPAD_enuOK,
	HKEYPAD_enuDIOError,
	HKEYPAD_enuInvalidConnection,
	HKEYPAD_enuNOK
}HKEYPAD_enuErrorStatus_t;


typedef enum
{
	HKEYPAD_enuINPUT_PULLUP ,
	HKEYPAD_enuOUTPUT_HIGH
}HKEYPAD_enuConnection_t;


typedef struct
{
	MPORT_enuPORT_OPTS_t Port;
	MPORT_enuPIN_OPTS_t  Pin ;
	HKEYPAD_enuConnection_t Connectiontype;
}HKEYPAD_enuKeypad_t;


/**
 * @brief Initializes the keypad by configuring its pins based on the provided keypad configuration.
 *
 * This function initializes the keypad by configuring its pins based on the specified configuration in the
 * KEYPAD_PinConfig array. It iterates through the keypad pins, checks the connection type, and configures
 * the port accordingly. If any pin configuration fails, it sets the error status accordingly.
 *
 * @return HKEYPAD_enuErrorStatus_t indicating the success or failure of keypad initialization:
 *         - HKEYPAD_enuOK: Keypad initialization successful.
 *         - HKEYPAD_enuDIOError: Error in configuring one of the keypad pins.
 *         - HKEYPAD_enuInvalidConnection: Invalid connection type specified for one of the keypad pins.
 */
HKEYPAD_enuErrorStatus_t HKEYPAD_enuInit(void);

/**
 * @brief Reads the status of the keys on the keypad.
 *
 * This function continuously scans the keypad matrix to detect key presses. It iterates through each column,
 * sets it LOW, and checks the status of each row. If a key is detected as pressed, it updates the key status
 * based on the key map and sets the value at the provided memory location (Add_pKeyStatus). The function includes
 * debouncing delays to ensure accurate key press detection.
 *
 * @param[out] Add_pKeyStatus Pointer to the memory location where the detected key status will be stored.
 *                            It is updated based on the HKEYPAD_u8KEYPADMAP.
 *
 * Note: The function operates in an infinite loop and continuously scans for key presses.
 */
void HKEYPAD_enuGetKey(u8 *Add_cpKeyStatus);

void HKEYPAD_vCalculator(void);


#endif /* HAL_HKEYPAD_HKEYPAD_INTERFACE_H_ */
