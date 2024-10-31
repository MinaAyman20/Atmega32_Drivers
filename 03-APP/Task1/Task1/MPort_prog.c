#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "MPort_Interface.h"
#include "Mport_Priv.h"
#include "MPort_config.h"


extern  MPORT_ENU_PIN_CONFIGRATIONS_t MPORT_PINCFG [NUMBER_OF_USED_PINS];


void PORT_voidPortInit()
{
 
 #if   Configration_type  == Pre_compile_configration 
    
    #if     Num_Of_Ports  == TWO_Ports
/**************************************************PORTA*************************************************************/

        #if   MPORT_PORTA_PIN0    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN0_DIR    PORT_LOW
          #define MPORT_PORTA_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN0_DIR    PORT_LOW
          #define MPORT_PORTA_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN0_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN1    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN1_DIR    PORT_LOW
          #define MPORT_PORTA_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN1_DIR    PORT_LOW
          #define MPORT_PORTA_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN1_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN2    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN2_DIR    PORT_LOW
          #define MPORT_PORTA_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN2_DIR    PORT_LOW
          #define MPORT_PORTA_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN2_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN3    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN3_DIR    PORT_LOW
          #define MPORT_PORTA_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN3_DIR    PORT_LOW
          #define MPORT_PORTA_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN3_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN4    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN4_DIR    PORT_LOW
          #define MPORT_PORTA_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN4_DIR    PORT_LOW
          #define MPORT_PORTA_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN4_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN5    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN5_DIR    PORT_LOW
          #define MPORT_PORTA_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN5_DIR    PORT_LOW
          #define MPORT_PORTA_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN5_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN6    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN6_DIR    PORT_LOW
          #define MPORT_PORTA_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN6_DIR    PORT_LOW
          #define MPORT_PORTA_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN6_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN7    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN7_DIR    PORT_LOW
          #define MPORT_PORTA_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN7_DIR    PORT_LOW
          #define MPORT_PORTA_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN7_PORT   PORT_LOW

        #endif
        

/************************************************PORTB*************************************************************/

        #if   MPORT_PORTB_PIN0    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN0_DIR    PORT_LOW
          #define MPORT_PORTB_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN0_DIR    PORT_LOW
          #define MPORT_PORTB_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN0_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN1    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN1_DIR    PORT_LOW
          #define MPORT_PORTB_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN1_DIR    PORT_LOW
          #define MPORT_PORTB_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN1_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN2    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN2_DIR    PORT_LOW
          #define MPORT_PORTB_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN2_DIR    PORT_LOW
          #define MPORT_PORTB_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN2_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN3    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN3_DIR    PORT_LOW
          #define MPORT_PORTB_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN3_DIR    PORT_LOW
          #define MPORT_PORTB_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN3_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN4    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN4_DIR    PORT_LOW
          #define MPORT_PORTB_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN4_DIR    PORT_LOW
          #define MPORT_PORTB_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN4_PORT   PORT_LOW 

        #endif        

        #if   MPORT_PORTB_PIN5    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN5_DIR    PORT_LOW
          #define MPORT_PORTB_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN5_DIR    PORT_LOW
          #define MPORT_PORTB_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN5_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN6    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN6_DIR    PORT_LOW
          #define MPORT_PORTB_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN6_DIR    PORT_LOW
          #define MPORT_PORTB_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN6_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN7   ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN7_DIR    PORT_LOW
          #define MPORT_PORTB_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN7_DIR    PORT_LOW
          #define MPORT_PORTB_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN7_PORT   PORT_LOW

        #endif       

        DDRA = CONCAT_BITS(
         MPORT_PORTA_PIN7_DIR,
         MPORT_PORTA_PIN6_DIR,
         MPORT_PORTA_PIN5_DIR,
         MPORT_PORTA_PIN4_DIR,
         MPORT_PORTA_PIN3_DIR,
         MPORT_PORTA_PIN2_DIR,
         MPORT_PORTA_PIN1_DIR,
         MPORT_PORTA_PIN0_DIR);

        DDRB = CONCAT_BITS(
         MPORT_PORTB_PIN7_DIR,
         MPORT_PORTB_PIN6_DIR,
         MPORT_PORTB_PIN5_DIR,
         MPORT_PORTB_PIN4_DIR,
         MPORT_PORTB_PIN3_DIR,
         MPORT_PORTB_PIN2_DIR,
         MPORT_PORTB_PIN1_DIR,
         MPORT_PORTB_PIN0_DIR);

        PORTA = CONCAT_BITS (
        MPORT_PORTA_PIN7_PORT,
        MPORT_PORTA_PIN6_PORT,
        MPORT_PORTA_PIN5_PORT,
        MPORT_PORTA_PIN4_PORT,
        MPORT_PORTA_PIN3_PORT,
        MPORT_PORTA_PIN2_PORT,
        MPORT_PORTA_PIN1_PORT,
        MPORT_PORTA_PIN0_PORT);   


        PORTB = CONCAT_BITS (
        MPORT_PORTB_PIN7_PORT,
        MPORT_PORTB_PIN6_PORT,
        MPORT_PORTB_PIN5_PORT,
        MPORT_PORTB_PIN4_PORT,
        MPORT_PORTB_PIN3_PORT,
        MPORT_PORTB_PIN2_PORT,
        MPORT_PORTB_PIN1_PORT,
        MPORT_PORTB_PIN0_PORT);   





    #elif   Num_Of_Ports == THREE_Ports

/**************************************************PORTA*************************************************************/

        #if   MPORT_PORTA_PIN0    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN0_DIR    PORT_LOW
          #define MPORT_PORTA_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN0_DIR    PORT_LOW
          #define MPORT_PORTA_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN0_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN1    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN1_DIR    PORT_LOW
          #define MPORT_PORTA_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN1_DIR    PORT_LOW
          #define MPORT_PORTA_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN1_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN2    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN2_DIR    PORT_LOW
          #define MPORT_PORTA_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN2_DIR    PORT_LOW
          #define MPORT_PORTA_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN2_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN3    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN3_DIR    PORT_LOW
          #define MPORT_PORTA_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN3_DIR    PORT_LOW
          #define MPORT_PORTA_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN3_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN4    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN4_DIR    PORT_LOW
          #define MPORT_PORTA_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN4_DIR    PORT_LOW
          #define MPORT_PORTA_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN4_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN5    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN5_DIR    PORT_LOW
          #define MPORT_PORTA_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN5_DIR    PORT_LOW
          #define MPORT_PORTA_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN5_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN6    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN6_DIR    PORT_LOW
          #define MPORT_PORTA_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN6_DIR    PORT_LOW
          #define MPORT_PORTA_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN6_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN7    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN7_DIR    PORT_LOW
          #define MPORT_PORTA_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN7_DIR    PORT_LOW
          #define MPORT_PORTA_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN7_PORT   PORT_LOW

        #endif

/************************************************PORTB*************************************************************/

        #if   MPORT_PORTB_PIN0    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN0_DIR    PORT_LOW
          #define MPORT_PORTB_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN0_DIR    PORT_LOW
          #define MPORT_PORTB_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN0_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN1    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN1_DIR    PORT_LOW
          #define MPORT_PORTB_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN1_DIR    PORT_LOW
          #define MPORT_PORTB_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN1_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN2    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN2_DIR    PORT_LOW
          #define MPORT_PORTB_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN2_DIR    PORT_LOW
          #define MPORT_PORTB_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN2_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN3    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN3_DIR    PORT_LOW
          #define MPORT_PORTB_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN3_DIR    PORT_LOW
          #define MPORT_PORTB_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN3_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN4    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN4_DIR    PORT_LOW
          #define MPORT_PORTB_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN4_DIR    PORT_LOW
          #define MPORT_PORTB_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN4_PORT   PORT_LOW 

        #endif        

        #if   MPORT_PORTB_PIN5    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN5_DIR    PORT_LOW
          #define MPORT_PORTB_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN5_DIR    PORT_LOW
          #define MPORT_PORTB_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN5_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN6    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN6_DIR    PORT_LOW
          #define MPORT_PORTB_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN6_DIR    PORT_LOW
          #define MPORT_PORTB_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN6_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN7   ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN7_DIR    PORT_LOW
          #define MPORT_PORTB_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN7_DIR    PORT_LOW
          #define MPORT_PORTB_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN7_PORT   PORT_LOW

        #endif       

/******************************************************PORTC*************************************************************/
        #if   MPORT_PORTC_PIN0   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN0_DIR    PORT_LOW
          #define MPORT_PORTC_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN0_DIR    PORT_LOW
          #define MPORT_PORTC_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN0_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN1   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN1_DIR    PORT_LOW
          #define MPORT_PORTC_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN1_DIR    PORT_LOW
          #define MPORT_PORTC_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN1_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN2   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN2_DIR    PORT_LOW
          #define MPORT_PORTC_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN2_DIR    PORT_LOW
          #define MPORT_PORTC_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN2_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN3   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN3_DIR    PORT_LOW
          #define MPORT_PORTC_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN3_DIR    PORT_LOW
          #define MPORT_PORTC_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN3_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN4   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN4_DIR    PORT_LOW
          #define MPORT_PORTC_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN4_DIR    PORT_LOW
          #define MPORT_PORTC_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN4_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN5   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN5_DIR    PORT_LOW
          #define MPORT_PORTC_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN5_DIR    PORT_LOW
          #define MPORT_PORTC_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN5_PORT   PORT_LOW

        #endif     

        #if   MPORT_PORTC_PIN6   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN6_DIR    PORT_LOW
          #define MPORT_PORTC_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN6_DIR    PORT_LOW
          #define MPORT_PORTC_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN6_PORT   PORT_LOW

        #endif     

        #if   MPORT_PORTC_PIN7   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN7_DIR    PORT_LOW
          #define MPORT_PORTC_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN7_DIR    PORT_LOW
          #define MPORT_PORTC_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN7_PORT   PORT_LOW

        #endif    

        DDRA = CONCAT_BITS(
         MPORT_PORTA_PIN7_DIR,
         MPORT_PORTA_PIN6_DIR,
         MPORT_PORTA_PIN5_DIR,
         MPORT_PORTA_PIN4_DIR,
         MPORT_PORTA_PIN3_DIR,
         MPORT_PORTA_PIN2_DIR,
         MPORT_PORTA_PIN1_DIR,
         MPORT_PORTA_PIN0_DIR);

        DDRB = CONCAT_BITS(
         MPORT_PORTB_PIN7_DIR,
         MPORT_PORTB_PIN6_DIR,
         MPORT_PORTB_PIN5_DIR,
         MPORT_PORTB_PIN4_DIR,
         MPORT_PORTB_PIN3_DIR,
         MPORT_PORTB_PIN2_DIR,
         MPORT_PORTB_PIN1_DIR,
         MPORT_PORTB_PIN0_DIR);

         DDRC = CONCAT_BITS(
         MPORT_PORTC_PIN7_DIR,
         MPORT_PORTC_PIN6_DIR,
         MPORT_PORTC_PIN5_DIR,
         MPORT_PORTC_PIN4_DIR,
         MPORT_PORTC_PIN3_DIR,
         MPORT_PORTC_PIN2_DIR,
         MPORT_PORTC_PIN1_DIR,
         MPORT_PORTC_PIN0_DIR);

        PORTA = CONCAT_BITS (
        MPORT_PORTA_PIN7_PORT,
        MPORT_PORTA_PIN6_PORT,
        MPORT_PORTA_PIN5_PORT,
        MPORT_PORTA_PIN4_PORT,
        MPORT_PORTA_PIN3_PORT,
        MPORT_PORTA_PIN2_PORT,
        MPORT_PORTA_PIN1_PORT,
        MPORT_PORTA_PIN0_PORT);   


        PORTB = CONCAT_BITS (
        MPORT_PORTB_PIN7_PORT,
        MPORT_PORTB_PIN6_PORT,
        MPORT_PORTB_PIN5_PORT,
        MPORT_PORTB_PIN4_PORT,
        MPORT_PORTB_PIN3_PORT,
        MPORT_PORTB_PIN2_PORT,
        MPORT_PORTB_PIN1_PORT,
        MPORT_PORTB_PIN0_PORT);   

        PORTC = CONCAT_BITS (
        MPORT_PORTC_PIN7_PORT,
        MPORT_PORTC_PIN6_PORT,
        MPORT_PORTC_PIN5_PORT,
        MPORT_PORTC_PIN4_PORT,
        MPORT_PORTC_PIN3_PORT,
        MPORT_PORTC_PIN2_PORT,
        MPORT_PORTC_PIN1_PORT,
        MPORT_PORTC_PIN0_PORT);   

   
        

    #elif   Num_Of_Ports == FOUR_Ports

        
/**************************************************PORTA*************************************************************/

        #if   MPORT_PORTA_PIN0    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN0_DIR    PORT_LOW
          #define MPORT_PORTA_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN0_DIR    PORT_LOW
          #define MPORT_PORTA_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN0_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN1    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN1_DIR    PORT_LOW
          #define MPORT_PORTA_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN1_DIR    PORT_LOW
          #define MPORT_PORTA_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN1_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN2    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN2_DIR    PORT_LOW
          #define MPORT_PORTA_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN2_DIR    PORT_LOW
          #define MPORT_PORTA_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN2_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN3    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN3_DIR    PORT_LOW
          #define MPORT_PORTA_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN3_DIR    PORT_LOW
          #define MPORT_PORTA_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN3_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN4    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN4_DIR    PORT_LOW
          #define MPORT_PORTA_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN4_DIR    PORT_LOW
          #define MPORT_PORTA_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN4_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN5    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN5_DIR    PORT_LOW
          #define MPORT_PORTA_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN5_DIR    PORT_LOW
          #define MPORT_PORTA_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN5_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN6    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN6_DIR    PORT_LOW
          #define MPORT_PORTA_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN6_DIR    PORT_LOW
          #define MPORT_PORTA_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN6_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTA_PIN7    ==  MPORT_INPUT_PU
          #define MPORT_PORTA_PIN7_DIR    PORT_LOW
          #define MPORT_PORTA_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTA_PIN7_DIR    PORT_LOW
          #define MPORT_PORTA_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTA_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTA_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTA_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTA_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTA_PIN7_PORT   PORT_LOW

        #endif

/************************************************PORTB*************************************************************/

        #if   MPORT_PORTB_PIN0    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN0_DIR    PORT_LOW
          #define MPORT_PORTB_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN0_DIR    PORT_LOW
          #define MPORT_PORTB_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN0_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN1    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN1_DIR    PORT_LOW
          #define MPORT_PORTB_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN1_DIR    PORT_LOW
          #define MPORT_PORTB_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN1_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN2    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN2_DIR    PORT_LOW
          #define MPORT_PORTB_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN2_DIR    PORT_LOW
          #define MPORT_PORTB_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN2_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTB_PIN3    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN3_DIR    PORT_LOW
          #define MPORT_PORTB_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN3_DIR    PORT_LOW
          #define MPORT_PORTB_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN3_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN4    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN4_DIR    PORT_LOW
          #define MPORT_PORTB_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN4_DIR    PORT_LOW
          #define MPORT_PORTB_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN4_PORT   PORT_LOW 

        #endif        

        #if   MPORT_PORTB_PIN5    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN5_DIR    PORT_LOW
          #define MPORT_PORTB_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN5_DIR    PORT_LOW
          #define MPORT_PORTB_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN5_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN6    ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN6_DIR    PORT_LOW
          #define MPORT_PORTB_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN6_DIR    PORT_LOW
          #define MPORT_PORTB_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN6_PORT   PORT_LOW

        #endif        

        #if   MPORT_PORTB_PIN7   ==  MPORT_INPUT_PU
          #define MPORT_PORTB_PIN7_DIR    PORT_LOW
          #define MPORT_PORTB_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTB_PIN7_DIR    PORT_LOW
          #define MPORT_PORTB_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTB_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTB_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTB_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTB_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTB_PIN7_PORT   PORT_LOW

        #endif       

/******************************************************PORTC*************************************************************/
        #if   MPORT_PORTC_PIN0   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN0_DIR    PORT_LOW
          #define MPORT_PORTC_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN0_DIR    PORT_LOW
          #define MPORT_PORTC_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN0_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN1   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN1_DIR    PORT_LOW
          #define MPORT_PORTC_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN1_DIR    PORT_LOW
          #define MPORT_PORTC_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN1_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN2   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN2_DIR    PORT_LOW
          #define MPORT_PORTC_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN2_DIR    PORT_LOW
          #define MPORT_PORTC_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN2_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN3   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN3_DIR    PORT_LOW
          #define MPORT_PORTC_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN3_DIR    PORT_LOW
          #define MPORT_PORTC_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN3_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN4   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN4_DIR    PORT_LOW
          #define MPORT_PORTC_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN4_DIR    PORT_LOW
          #define MPORT_PORTC_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN4_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTC_PIN5   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN5_DIR    PORT_LOW
          #define MPORT_PORTC_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN5_DIR    PORT_LOW
          #define MPORT_PORTC_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN5_PORT   PORT_LOW

        #endif     

        #if   MPORT_PORTC_PIN6   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN6_DIR    PORT_LOW
          #define MPORT_PORTC_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN6_DIR    PORT_LOW
          #define MPORT_PORTC_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN6_PORT   PORT_LOW

        #endif     

        #if   MPORT_PORTC_PIN7   ==  MPORT_INPUT_PU
          #define MPORT_PORTC_PIN7_DIR    PORT_LOW
          #define MPORT_PORTC_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTC_PIN7_DIR    PORT_LOW
          #define MPORT_PORTC_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTC_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTC_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTC_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTC_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTC_PIN7_PORT   PORT_LOW

        #endif       
        
/******************************************************PORTD*************************************************************/
        #if   MPORT_PORTD_PIN0   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN0_DIR    PORT_LOW
          #define MPORT_PORTD_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN0    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN0_DIR    PORT_LOW
          #define MPORT_PORTD_PIN0_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN0    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN0_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN0    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN0_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN0_PORT   PORT_LOW

        #endif   

        #if   MPORT_PORTD_PIN1   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN1_DIR    PORT_LOW
          #define MPORT_PORTD_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN1    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN1_DIR    PORT_LOW
          #define MPORT_PORTD_PIN1_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN1    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN1_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN1    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN1_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN1_PORT   PORT_LOW

        #endif       

        #if   MPORT_PORTD_PIN2   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN2_DIR    PORT_LOW
          #define MPORT_PORTD_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN2    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN2_DIR    PORT_LOW
          #define MPORT_PORTD_PIN2_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN2    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN2_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN2    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN2_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN2_PORT   PORT_LOW

        #endif  

        #if   MPORT_PORTD_PIN3   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN3_DIR    PORT_LOW
          #define MPORT_PORTD_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN3    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN3_DIR    PORT_LOW
          #define MPORT_PORTD_PIN3_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN3    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN3_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN3    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN3_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN3_PORT   PORT_LOW

        #endif     

        #if   MPORT_PORTD_PIN4   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN4_DIR    PORT_LOW
          #define MPORT_PORTD_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN4    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN4_DIR    PORT_LOW
          #define MPORT_PORTD_PIN4_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN4    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN4_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN4    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN4_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN4_PORT   PORT_LOW

        #endif    

        #if   MPORT_PORTD_PIN5   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN5_DIR    PORT_LOW
          #define MPORT_PORTD_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN5    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN5_DIR    PORT_LOW
          #define MPORT_PORTD_PIN5_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN5    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN5_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN5    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN5_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN5_PORT   PORT_LOW

        #endif   

        #if   MPORT_PORTD_PIN6   ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN6_DIR    PORT_LOW
          #define MPORT_PORTD_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN6    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN6_DIR    PORT_LOW
          #define MPORT_PORTD_PIN6_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN6    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN6_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN6    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN6_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN6_PORT   PORT_LOW

        #endif

        #if   MPORT_PORTD_PIN7  ==  MPORT_INPUT_PU
          #define MPORT_PORTD_PIN7_DIR    PORT_LOW
          #define MPORT_PORTD_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN7    ==  MPORT_INPUT_PD
          #define MPORT_PORTD_PIN7_DIR    PORT_LOW
          #define MPORT_PORTD_PIN7_PORT   PORT_LOW

        #elif MPORT_PORTD_PIN7    ==  MPORT_OUTPUT_HIGH
          #define MPORT_PORTD_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN7_PORT   PORT_HIGH

        #elif MPORT_PORTD_PIN7    ==  MPORT_OUTPUT_LOW
          #define MPORT_PORTD_PIN7_DIR    PORT_HIGH
          #define MPORT_PORTD_PIN7_PORT   PORT_LOW

        #endif       

         DDRA = CONCAT_BITS (
         MPORT_PORTA_PIN7_DIR,
         MPORT_PORTA_PIN6_DIR,
         MPORT_PORTA_PIN5_DIR,
         MPORT_PORTA_PIN4_DIR,
         MPORT_PORTA_PIN3_DIR,
         MPORT_PORTA_PIN2_DIR,
         MPORT_PORTA_PIN1_DIR,
         MPORT_PORTA_PIN0_DIR);

         DDRB = CONCAT_BITS (
         MPORT_PORTB_PIN7_DIR,
         MPORT_PORTB_PIN6_DIR,
         MPORT_PORTB_PIN5_DIR,
         MPORT_PORTB_PIN4_DIR,
         MPORT_PORTB_PIN3_DIR,
         MPORT_PORTB_PIN2_DIR,
         MPORT_PORTB_PIN1_DIR,
         MPORT_PORTB_PIN0_DIR);

         DDRC = CONCAT_BITS(
         MPORT_PORTC_PIN7_DIR,
         MPORT_PORTC_PIN6_DIR,
         MPORT_PORTC_PIN5_DIR,
         MPORT_PORTC_PIN4_DIR,
         MPORT_PORTC_PIN3_DIR,
         MPORT_PORTC_PIN2_DIR,
         MPORT_PORTC_PIN1_DIR,
         MPORT_PORTC_PIN0_DIR);

         DDRD = CONCAT_BITS(
         MPORT_PORTD_PIN7_DIR,
         MPORT_PORTD_PIN6_DIR,
         MPORT_PORTD_PIN5_DIR,
         MPORT_PORTD_PIN4_DIR,
         MPORT_PORTD_PIN3_DIR,
         MPORT_PORTD_PIN2_DIR,
         MPORT_PORTD_PIN1_DIR,
         MPORT_PORTD_PIN0_DIR);

        PORTA = CONCAT_BITS (
        MPORT_PORTA_PIN7_PORT,
        MPORT_PORTA_PIN6_PORT,
        MPORT_PORTA_PIN5_PORT,
        MPORT_PORTA_PIN4_PORT,
        MPORT_PORTA_PIN3_PORT,
        MPORT_PORTA_PIN2_PORT,
        MPORT_PORTA_PIN1_PORT,
        MPORT_PORTA_PIN0_PORT);   


        PORTB = CONCAT_BITS (
        MPORT_PORTB_PIN7_PORT,
        MPORT_PORTB_PIN6_PORT,
        MPORT_PORTB_PIN5_PORT,
        MPORT_PORTB_PIN4_PORT,
        MPORT_PORTB_PIN3_PORT,
        MPORT_PORTB_PIN2_PORT,
        MPORT_PORTB_PIN1_PORT,
        MPORT_PORTB_PIN0_PORT);   

        PORTC = CONCAT_BITS (
        MPORT_PORTC_PIN7_PORT,
        MPORT_PORTC_PIN6_PORT,
        MPORT_PORTC_PIN5_PORT,
        MPORT_PORTC_PIN4_PORT,
        MPORT_PORTC_PIN3_PORT,
        MPORT_PORTC_PIN2_PORT,
        MPORT_PORTC_PIN1_PORT,
        MPORT_PORTC_PIN0_PORT);   

        PORTD = CONCAT_BITS (
        MPORT_PORTD_PIN7_PORT,
        MPORT_PORTD_PIN6_PORT,
        MPORT_PORTD_PIN5_PORT,
        MPORT_PORTD_PIN4_PORT,
        MPORT_PORTD_PIN3_PORT,
        MPORT_PORTD_PIN2_PORT,
        MPORT_PORTD_PIN1_PORT,
        MPORT_PORTD_PIN0_PORT);   

     
    #endif

 #elif  Configration_type   == Post_compile_configration
     MPORT_enuPORT_OPTS_t LOC_u8PortNum =  MPORT_enuPort_A ;
     MPORT_enuPIN_OPTS_t  LOC_u8PinNum =   MPORT_enuPin_0   ;
    u8 LOC_u8Counter ;
    for(LOC_u8Counter = 0;(LOC_u8Counter<=NUMBER_OF_USED_PINS); LOC_u8Counter++)
    {
      LOC_u8PortNum = LOC_u8Counter / NUMBER_OF_PINS_Per_Port  ;
      LOC_u8PinNum  = LOC_u8Counter % NUMBER_OF_PINS_Per_Port ;

     switch (LOC_u8PortNum)
     {
      case MPORT_enuPort_A :
        switch(MPORT_PINCFG[LOC_u8Counter])
        {
          case MPORT_enu_INPUT_PU :

          CLR_BIT(DDRA,LOC_u8PinNum);
          SET_BIT(PORTA,LOC_u8PinNum);

          break;

          case MPORT_enu_INPUT_PD:
           
           CLR_BIT(DDRA,LOC_u8PinNum);
           CLR_BIT(PORTA,LOC_u8PinNum);
          break;

          case MPORT_enu_OUTPUT_HIGH:

          SET_BIT(DDRA,LOC_u8PinNum);
          SET_BIT(PORTA,LOC_u8PinNum);

          break;

          case MPORT_enu_OUTPUT_LOW:

          SET_BIT(DDRA,LOC_u8PinNum);
          CLR_BIT(PORTA,LOC_u8PinNum);

          break;
          default:              break;
        }

      break;


      case MPORT_enuPort_B :
       switch(MPORT_PINCFG[LOC_u8Counter])
        {
          case MPORT_enu_INPUT_PU :

          CLR_BIT(DDRB,LOC_u8PinNum);
          SET_BIT(PORTB,LOC_u8PinNum);

          break;

          case MPORT_enu_INPUT_PD:
           
           CLR_BIT(DDRB,LOC_u8PinNum);
           CLR_BIT(PORTB,LOC_u8PinNum);
          break;

          case MPORT_enu_OUTPUT_HIGH:

          SET_BIT(DDRB,LOC_u8PinNum);
          SET_BIT(PORTB,LOC_u8PinNum);

          break;

          case MPORT_enu_OUTPUT_LOW:

          SET_BIT(DDRB,LOC_u8PinNum);
          CLR_BIT(PORTB,LOC_u8PinNum);

          break;
          default:              break;
        }

      break;
      case MPORT_enuPort_C :

     switch(MPORT_PINCFG[LOC_u8Counter])
        {
          case MPORT_enu_INPUT_PU :

          CLR_BIT(DDRC,LOC_u8PinNum);
          SET_BIT(PORTC,LOC_u8PinNum);

          break;

          case MPORT_enu_INPUT_PD:
           
           CLR_BIT(DDRC,LOC_u8PinNum);
           CLR_BIT(PORTC,LOC_u8PinNum);
          break;

          case MPORT_enu_OUTPUT_HIGH:

          SET_BIT(DDRC,LOC_u8PinNum);
          SET_BIT(PORTC,LOC_u8PinNum);

          break;

          case MPORT_enu_OUTPUT_LOW:

          SET_BIT(DDRC,LOC_u8PinNum);
          CLR_BIT(PORTC,LOC_u8PinNum);

          break;
          default:              break;
        }

      break;
      case MPORT_enuPort_D :
       switch(MPORT_PINCFG[LOC_u8Counter])
        {
          case MPORT_enu_INPUT_PU :

          CLR_BIT(DDRD,LOC_u8PinNum);
          SET_BIT(PORTD,LOC_u8PinNum);

          break;

          case MPORT_enu_INPUT_PD:
           
           CLR_BIT(DDRD,LOC_u8PinNum);
           CLR_BIT(PORTD,LOC_u8PinNum);
          break;

          case MPORT_enu_OUTPUT_HIGH:

          SET_BIT(DDRD,LOC_u8PinNum);
          SET_BIT(PORTD,LOC_u8PinNum);

          break;

          case MPORT_enu_OUTPUT_LOW:

          SET_BIT(DDRD,LOC_u8PinNum);
          CLR_BIT(PORTD,LOC_u8PinNum);

          break;
          default:              break;
        }
      
      break;
      default:              break;
     }
    }

#else 
   // #error "Invalid Configuration " 
 #endif








}