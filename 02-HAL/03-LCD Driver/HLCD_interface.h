/************************************************************************************************************************/
/*File          :       HLCD_interface.h                                                                                */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                             */
/************************************************************************************************************************/

#ifndef HAL_HLCD_INTERFACE_H_
#define HAL_HLCD_INTERFACE_H_

#include "../../MCAL/01-PORT/MPort_Interface.h"

#define HLCD_enu4BIT_MODE            0
#define HLCD_enu8BIT_MODE            1

#define HLCD_enuDISPLAY_OFF          0 
#define HLCD_enuDISPLAY_ON           1

#define HLCD_enuCURSOR_BLINKING_OFF  0
#define HLCD_enuCURSOR_BLINKING_ON   1

#define HLCD_enuCURSOR_OFF           0
#define HLCD_enuCURSOR_ON            1

#define HLCD_enu5X8                  0
#define HLCD_enu5X11                 1

#define HLCD_enuONE_LINE             0
#define HLCD_enuTWO_LINE             1

#define HLCD_SHIFTING_LEFT           0x18
#define HLCD_SHIFTING_RIGHT          0x1C
#define HLCD_CLEAR_DISPLAY           0x01

typedef enum
{
 HLCD_enuBlockNumber0,
 HLCD_enuBlockNumber1,
 HLCD_enuBlockNumber2,
 HLCD_enuBlockNumber3,
 HLCD_enuBlockNumber4,
 HLCD_enuBlockNumber5,
 HLCD_enuBlockNumber6,
 HLCD_enuBlockNumber7
}HLCD_enuCGRAM_BlockNumber;

typedef enum
{
 HLCD_enuPosition0,
 HLCD_enuPosition1,
 HLCD_enuPosition2,
 HLCD_enuPosition3,
 HLCD_enuPosition4,
 HLCD_enuPosition5,
 HLCD_enuPosition6,
 HLCD_enuPosition7,
 HLCD_enuPosition8,
 HLCD_enuPosition9,
 HLCD_enuPosition10,
 HLCD_enuPosition11,
 HLCD_enuPosition12,
 HLCD_enuPosition13,
 HLCD_enuPosition14,
 HLCD_enuPosition15
}HLCD_enuDDRAM_YPosition;

typedef enum
{
 HLCD_enuFirstLine,
 HLCD_enuSecondLine
}HLCD_enuDDRAM_XPosition;

typedef enum
{
 HLCD_enuOK,
 HLCD_enuBlockNumberError,
 HLCD_enuDDRAM_XPositionError,
 HLCD_enuDDRAM_YPositionError,
 HLCD_enuNOK
}HLCD_enuErrorStatus_t;

typedef struct
{
   MPORT_enuPORT_OPTS_t  PortNum;
   MPORT_enuPIN_OPTS_t   PinNum;
} HLCD_strLCDConfigration;

typedef struct 
{ 
    HLCD_strLCDConfigration DATABIT0 ;
    HLCD_strLCDConfigration DATABIT1 ;
    HLCD_strLCDConfigration DATABIT2 ;
    HLCD_strLCDConfigration DATABIT3 ;
    HLCD_strLCDConfigration DATABIT4 ;
    HLCD_strLCDConfigration DATABIT5 ;
    HLCD_strLCDConfigration DATABIT6 ;
    HLCD_strLCDConfigration DATABIT7 ;
    HLCD_strLCDConfigration RS       ;
    HLCD_strLCDConfigration RW       ;
    HLCD_strLCDConfigration ENABLE   ;
} HLCD_strLCDPinConfigration         ;


/**
 * @brief Configures the pins for an LCD module based on the specified configuration.
 *
 * This function configures the individual pins required for interfacing with an LCD module.
 * It sets the mode of each pin (DATABIT0 to DATABIT7, ENABLE, RS, and RW) to OUTPUT_LOW.
 * The configuration is based on the parameters provided in the global variable LCD_Config.
 *
 * @return HLCD_enuErrorStatus_t indicating the success or failure of the pin configuration:
 *         - HLCD_enuOK: Pin configuration was successful.
 *         - Other error codes: Pin configuration encountered an error.
 */
HLCD_enuErrorStatus_t HLCD_enuLCDPinConfigration(void);


/**
 * @brief Sends a command to the LCD module based on the specified command value.
 *
 * This function is responsible for sending a command to the LCD module. The command can be either
 * in 8-bit mode or 4-bit mode based on the configuration defined by the macro HLCD_BIT_MODE. It sets
 * the RS and RW pins to LOW to indicate a command write operation. The data bits of the command are
 * sent sequentially to the corresponding pins based on the configuration provided in the global
 * variable LCD_Config.
 *
 * @param Copy_u8Command: The command to be sent to the LCD module.
 *
 * @note The function supports both 8-bit and 4-bit modes. The macro HLCD_BIT_MODE should be set
 *       accordingly before including this function in the code.
 */
void HLCD_voidLCDSendCommand(u8 Copy_u8Command);


/**
 * @brief Sends data to the LCD module based on the specified data value.
 *
 * This function is responsible for sending data to the LCD module. The data can be sent in either
 * 8-bit mode or 4-bit mode based on the configuration defined by the macro HLCD_BIT_MODE. It sets
 * the RS pin to HIGH to indicate a data write operation and the RW pin to LOW. The data bits of the
 * command are sent sequentially to the corresponding pins based on the configuration provided in
 * the global variable LCD_Config.
 *
 * @param Copy_u8Data: The data to be sent to the LCD module.
 *
 * @note The function supports both 8-bit and 4-bit modes. The macro HLCD_BIT_MODE should be set
 *       accordingly before including this function in the code.
 */

void HLCD_voidLCDSendData(u8 Copy_u8Data);


/**
 * @brief Initializes the LCD module based on the specified bit mode (8-bit or 4-bit).
 *
 * This function initializes the LCD module by sending a series of command sequences based on
 * the selected bit mode (8-bit or 4-bit). It includes commands for function set, display on/off,
 * clearing the display, and setting the entry mode. The delays after each command ensure proper
 * timing for LCD initialization.
 *
 * @note The function supports both 8-bit and 4-bit modes. The macro HLCD_BIT_MODE should be set
 *       accordingly before including this function in the code.
 */

void HLCD_voidLCDInit(void);


/**
 * @brief Sets the cursor position in the LCD's DDRAM based on specified X and Y positions.
 *
 * This function calculates the DDRAM location based on the provided X and Y positions and sends
 * the appropriate command to set the cursor at that location. The X position corresponds to the
 * line (HLCD_enuFirstLine or HLCD_enuSecondLine), and the Y position corresponds to the column
 * (from 0 to 15). The function returns an error status if the provided positions are invalid.
 *
 * @param Copy_u8XPosition: Desired X position (line) on the LCD (HLCD_enuFirstLine or HLCD_enuSecondLine).
 * @param Copy_u8YPosition: Desired Y position (column) on the LCD (from 0 to 15).
 *
 * @return HLCD_enuErrorStatus_t indicating the success or failure of setting the cursor position:
 *         - HLCD_enuOK: Cursor position set successfully.
 *         - HLCD_enuDDRAM_XPositionError: Invalid X position provided.
 *         - HLCD_enuDDRAM_YPositionError: Invalid Y position provided.
 */
HLCD_enuErrorStatus_t HLCD_voidLCDGoToDDRAMLoc(HLCD_enuDDRAM_XPosition Copy_enuXPosition,HLCD_enuDDRAM_YPosition Copy_enuYPosition);


/**
 * @brief Sends a string to the specified position on the LCD.
 *
 * This function sends a string to the specified position on the LCD. It first sets the cursor
 * position in the LCD's DDRAM based on the provided X and Y positions using HLCD_voidLCDGoToDDRAMLoc().
 * Then, it iterates through the characters in the input string until it encounters the null character
 * '\0'. For each character, it sends the data to the LCD using HLCD_voidLCDSendData(). The function
 * allows displaying strings at specific locations on the LCD.
 *
 * @param copy_cstring: Pointer to the input string to be displayed on the LCD.
 * @param Copy_enuXPosition: Desired X position (line) on the LCD (HLCD_enuFirstLine or HLCD_enuSecondLine).
 * @param Copy_enuYPosition: Desired Y position (column) on the LCD (from 0 to 15).
 */
void HLCD_voidSendString(char *copy_cstring,HLCD_enuDDRAM_XPosition Copy_enuXPosition,HLCD_enuDDRAM_YPosition Copy_enuYPosition);

/**
 * @brief Writes a number to the LCD display.
 *
 * This function takes a 64-bit unsigned integer (u64) as input and writes its digits to the LCD display.
 * The function extracts each digit of the number, converts it to its ASCII equivalent, and stores the
 * reversed digits in an array. It then checks if the number is negative and adds a negative sign to the
 * LCD display. The function handles the display of the digits on the LCD, considering the width of the
 * LCD and displaying the remaining digits on the second line if needed.
 *
 * @param Copy_u32Number: 64-bit unsigned integer to be written to the LCD.
 *
 * @return HLCD_enuErrorStatus_t indicating the success or failure of writing the number to the LCD:
 *         - HLCD_enuOK: Number written successfully.
 */
HLCD_enuErrorStatus_t HLCD_enuWriteNumber(u64 Copy_u32Number);

/**
 * @brief Displays a special character at a specified position on the LCD using a custom pattern.
 *
 * This function takes an array of 8 bytes representing a custom pattern (special character) and displays it
 * at the specified position on the LCD. It first checks the validity of the block number, X position, and Y position.
 * If the positions are valid, the function calculates the CGRAM location for the given block, sends the custom pattern
 * to the CGRAM, and then displays the custom character at the specified position on the LCD.
 *
 * @param Copy_enuPattern: Pointer to an array of 8 bytes representing the custom pattern (special character).
 * @param Copy_enuBlockNumber: Enumeration representing the CGRAM block number (HLCD_enuCGRAM_BlockNumber).
 * @param Copy_enuXPosition: Enumeration representing the X position on the LCD (HLCD_enuDDRAM_XPosition).
 * @param Copy_enuYPosition: Enumeration representing the Y position on the LCD (HLCD_enuDDRAM_YPosition).
 *
 * @return HLCD_enuErrorStatus_t indicating the success or failure of displaying the special character on the LCD:
 *         - HLCD_enuOK: Special character displayed successfully.
 *         - HLCD_enuBlockNumberError: Invalid CGRAM block number.
 *         - HLCD_enuDDRAM_XPositionError: Invalid X position.
 *         - HLCD_enuDDRAM_YPositionError: Invalid Y position.
 */
HLCD_enuErrorStatus_t HLCD_voidDisplaySpecialCharacter(u8 *Copy_enuPattern , HLCD_enuCGRAM_BlockNumber Copy_enuBlockNumber,\
                                                    HLCD_enuDDRAM_XPosition Copy_enuXPosition,HLCD_enuDDRAM_YPosition Copy_enuYPosition );

#endif
