#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

/*
 *   Configration_type  Options
 *  1-Pre_compile_configration
 *  2-Post_compile_configration
 */
#define Configration_type     Pre_compile_configration

/*
 *   Num_Of_Ports  Options
 *  1-TWO_Ports
 *  2-THREE_Ports
 *  3-FOUR_Ports
 */

#define Num_Of_Ports          FOUR_Ports


/*
 *   PortA Pins Configuration  Options
 *  1-MPORT_INPUT_PU
 *  2-MPORT_INPUT_PD
 *  3-MPORT_OUTPUT_HIGH
 *  4-MPORT_OUTPUT_LOW
 */

#define MPORT_PORTA_PIN0              MPORT_INPUT_PU 
#define MPORT_PORTA_PIN1              MPORT_OUTPUT_HIGH     
#define MPORT_PORTA_PIN2              MPORT_INPUT_PU    
#define MPORT_PORTA_PIN3              MPORT_OUTPUT_HIGH     
#define MPORT_PORTA_PIN4              MPORT_INPUT_PU     
#define MPORT_PORTA_PIN5              MPORT_OUTPUT_HIGH     
#define MPORT_PORTA_PIN6              MPORT_OUTPUT_LOW    
#define MPORT_PORTA_PIN7              MPORT_OUTPUT_HIGH       




/*
 *   PortB Pins Configuration  Options
 *  1-MPORT_INPUT_PU
 *  2-MPORT_INPUT_PD
 *  3-MPORT_OUTPUT_HIGH
 *  4-MPORT_OUTPUT_LOW
 */
#define MPORT_PORTB_PIN0              MPORT_OUTPUT_HIGH        
#define MPORT_PORTB_PIN1              MPORT_OUTPUT_HIGH      
#define MPORT_PORTB_PIN2              MPORT_OUTPUT_HIGH     
#define MPORT_PORTB_PIN3              MPORT_OUTPUT_HIGH      
#define MPORT_PORTB_PIN4              MPORT_OUTPUT_HIGH      
#define MPORT_PORTB_PIN5              MPORT_OUTPUT_HIGH      
#define MPORT_PORTB_PIN6              MPORT_OUTPUT_HIGH      
#define MPORT_PORTB_PIN7              MPORT_OUTPUT_HIGH        




/*
 *   PortC Pins Configration  Options
 *  1-MPORT_INPUT_PU
 *  2-MPORT_INPUT_PD
 *  3-MPORT_OUTPUT_HIGH
 *  4-MPORT_OUTPUT_LOW
 */
#define MPORT_PORTC_PIN0              MPORT_OUTPUT_HIGH          
#define MPORT_PORTC_PIN1              MPORT_OUTPUT_HIGH      
#define MPORT_PORTC_PIN2              MPORT_OUTPUT_HIGH    
#define MPORT_PORTC_PIN3              MPORT_OUTPUT_HIGH        
#define MPORT_PORTC_PIN4              MPORT_OUTPUT_HIGH        
#define MPORT_PORTC_PIN5              MPORT_OUTPUT_HIGH        
#define MPORT_PORTC_PIN6              MPORT_OUTPUT_HIGH       
#define MPORT_PORTC_PIN7              MPORT_OUTPUT_HIGH        



/*
 *   PortD Pins Configuration  Options
 *  1-MPORT_INPUT_PU
 *  2-MPORT_INPUT_PD
 *  3-MPORT_OUTPUT_HIGH
 *  4-MPORT_OUTPUT_LOW
 */
#define MPORT_PORTD_PIN0              MPORT_OUTPUT_HIGH            
#define MPORT_PORTD_PIN1              MPORT_OUTPUT_HIGH       
#define MPORT_PORTD_PIN2              MPORT_OUTPUT_HIGH       
#define MPORT_PORTD_PIN3              MPORT_OUTPUT_HIGH        
#define MPORT_PORTD_PIN4              MPORT_OUTPUT_HIGH        
#define MPORT_PORTD_PIN5              MPORT_OUTPUT_HIGH       
#define MPORT_PORTD_PIN6              MPORT_OUTPUT_HIGH        
#define MPORT_PORTD_PIN7              MPORT_OUTPUT_HIGH        




#define   NUMBER_OF_USED_PINS         32
#define   NUMBER_OF_PINS_Per_Port     8


































#endif