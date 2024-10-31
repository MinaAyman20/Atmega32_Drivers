/************************************************************************************************************************/
/*File          :       MEXTI_priv.h                                                                                   */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       24/12/2023                                                                                      */
/*SWC           :       EXTI                                                                                            */
/************************************************************************************************************************/

#ifndef MEXTI_PRIV_H_
#define MEXTI_PRIV_H_

#define   MCUCR       (*(unsigned volatile char*)0x55)
#define   MCUCSR      (*(unsigned volatile char*)0x54)
#define   GICR        (*(unsigned volatile char*)0x5B)
#define   GIFR        (*(unsigned volatile char*)0x5A)
#define   SREG        (*(unsigned volatile char*)0x5F)


#define MCUCR_INT0_CLEAR_MASK             0XFC 
#define MCUCR_INT1_CLEAR_MASK             0XF3
#define MCUCSR_INT2_CLEAR_MASK            0xBF

#define MEXTI_INT0_LOWLEVEL               0X00
#define MEXTI_INT0_ONCHANGE               0x01
#define MEXTI_INT0_FALLINGEDGE            0x02  
#define MEXTI_INT0_RISINGEDGE             0x03

#define MEXTI_INT1_LOWLEVEL               0X00
#define MEXTI_INT1_ONCHANGE               0x04
#define MEXTI_INT1_FALLINGEDGE            0x08  
#define MEXTI_INT1_RISINGEDGE             0x0C


#define MEXTI_INT2_FALLINGEDGE            0x00  
#define MEXTI_INT2_RISINGEDGE             0x40










#endif