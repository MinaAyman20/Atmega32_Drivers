#ifndef PORT_INTERFACE_H
#define PORT_INTERFACE_H



/* Configuration Type Defines */
#define  Pre_compile_configration   0
#define  Post_compile_configration  1


/* Port Number Defines */
#define  TWO_Ports                  0
#define  THREE_Ports                1
#define  FOUR_Ports                 2

/* Port Defines */
#define MPORT_PORTA                   0
#define MPORT_PORTB                   1
#define MPORT_PORTC                   2
#define MPORT_PORTD                   3


/* Input Output Defines */
#define MPORT_INPUT_PU                0
#define MPORT_INPUT_PD                1
#define MPORT_OUTPUT_HIGH             2
#define MPORT_OUTPUT_LOW              3


/* Port status Defines */
#define  PORT_LOW                  0
#define  PORT_HIGH                 1

#define CONCAT_BITS_HELPER(bit7, bit6, bit5,bit4, bit3, bit2,bit1,bit0)  0b##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0
#define CONCAT_BITS(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)         CONCAT_BITS_HELPER(bit7, bit6, bit5,bit4, bit3, bit2,bit1,bit0)

typedef enum
{
	MPORT_enu_INPUT_PU,
	MPORT_enu_INPUT_PD,
	MPORT_enu_OUTPUT_HIGH,
	MPORT_enu_OUTPUT_LOW

}MPORT_ENU_PIN_CONFIGRATIONS_t;


typedef enum
{
	MPORT_enuPort_A,
	MPORT_enuPort_B,
	MPORT_enuPort_C,
	MPORT_enuPort_D
	
}MPORT_enuPORT_OPTS_t ;

typedef enum
{
	MPORT_enuPin_0,
	MPORT_enuPin_1,
	MPORT_enuPin_2,
	MPORT_enuPin_3,
	MPORT_enuPin_4,
	MPORT_enuPin_5,
	MPORT_enuPin_6,
	MPORT_enuPin_7
	
}MPORT_enuPIN_OPTS_t;



void PORT_voidPortInit(void);


#endif