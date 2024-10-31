/************************************************************************************************************************/
/*File          :       HLCD_priv.h                                                                                    */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       28/12/2023                                                                                      */
/*SWC           :       LCD                                                                                            */
/************************************************************************************************************************/


#ifndef HAL_HLCD_PRIV_H_
#define HAL_HLCD_PRIV_H_

#include "../../LIB/STD_TYPES.h"

#define HLCD_FUNCTION_SET_8BIT_CMD      (u8) ((0 << 7) | (0 << 6) | (1 << 5) | (HLCD_BIT_MODE << 4) | \
                                              (HLCD_LINES_MODE  << 3) | (HLCD_FONT_MODE << 2) | \
                                              (0 << 1) | (0 << 0))

#define HLCD_DISPLAY_ON_OFF_8BIT_CMD    (u8) ((0 << 7) | (0 << 6) | (0 << 5) | (0 << 4) | \
                                              (1  << 3) | ( HLCD_DISPLAY_MODE << 2) | \
                                              (HLCD_CURSOR_MODE << 1) | (HLCD_CURSOR_BLINKING_MODE << 0))

#define HLCD_CLEAR_DISPLAY_8BIT_CMD     (u8) 0b00000001

#define HLCD_ENTRY_MODE_8BIT_CMD        (u8) 0b00000110


#define HLCD_FUNCTION_SET_4BIT_CMD      (u8) ((0 << 7) | (0<< 6) | (0 << 5) | (0<< 4) | \
                                              (HLCD_LINES_MODE<< 3) | (HLCD_FONT_MODE<< 2) | (0 << 1) | (HLCD_BIT_MODE << 0))

#define HLCD_DISPLAY_ON_OFF_4BIT_CMD    (u8) ((0 << 7) | (0 << 6) | (0 << 5) | (0<< 4) | \
                                              (1  << 3) | ( HLCD_DISPLAY_MODE  << 2) | (HLCD_CURSOR_MODE  << 1) | (HLCD_CURSOR_BLINKING_MODE  << 0))

#define HLCD_CLEAR_DISPLAY_4BIT_CMD     (u8) 0b00000001

#define HLCD_ENTRY_MODE_4BIT_CMD        (u8) 0b00000010



#define HLCD_Fixed1_FunctionSet_4BIT_CMD       (u8) 0x02




#endif
