/************************************************************************************************************************/
/*File          :       MEXTI_config.h                                                                                   */
/*Author        :       Mina Ayman                                                                                      */
/*Date          :       24/12/2023                                                                                      */
/*SWC           :       EXTI                                                                                            */
/************************************************************************************************************************/

#ifndef MEXTI_CONFIG_H_
#define MEXTI_CONFIG_H_

/*
 *  Configration Options
 *  1-MEXTI_ENABLE
 *  2-MEXTI_DISABLE
 */
#define MEXTI_INT0    MEXTI_ENABLE
#define MEXTI_INT1    MEXTI_ENABLE
#define MEXTI_INT2    MEXTI_ENABLE


/*
 *  Configration Of Sense Control Of INT0 Options
 *  MEXTI_INT0_LOWLEVEL
 *  MEXTI_INT0_ONCHANGE 
 *  MEXTI_INT0_FALLINGEDGE 
 *  MEXTI_INT0_RISINGEDGE
*/
#define MEXTI_INT0_SENSECONTROL     MEXTI_INT0_FALLINGEDGE


/*
 *  Configration Of Sense Control Of INT0 Options
 *  MEXTI_INT1_LOWLEVEL
 *  MEXTI_INT1_ONCHANGE 
 *  MEXTI_INT1_FALLINGEDGE 
 *  MEXTI_INT1_RISINGEDGE
*/
#define MEXTI_INT1_SENSECONTROL     MEXTI_INT1_FALLINGEDGE



/*
 *  Configration Of Sense Control Of INT0 Options
 *  MEXTI_INT2_FALLINGEDGE 
 *  MEXTI_INT2_RISINGEDGE
*/
#define MEXTI_INT2_SENSECONTROL     MEXTI_INT2_FALLINGEDGE










#endif
