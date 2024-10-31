#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "MPort_Interface.h"



typedef enum 
{

DIO_enu_OK                   ,
DIO_enu_NOK                  ,
DIO_enu_INVALID_PORT_NUM     ,
DIO_enu_INVALID_PIN_NUM      ,
DIO_enu_INVALID_CONFIGRATION ,
DIO_enu_NULL_PTR             ,
DIO_enu_INVALID_STATE        

}DIO_enuErrorState_t ;


typedef enum 
{
	DIO_enuPort_A,
	DIO_enuPort_B,
	DIO_enuPort_C,
	DIO_enuPort_D
	
}DIO_enuPORT_OPTS_t ;

typedef enum 
{
	DIO_enuPin_0,
	DIO_enuPin_1,
	DIO_enuPin_2,
	DIO_enuPin_3,
	DIO_enuPin_4,
	DIO_enuPin_5,
	DIO_enuPin_6,
	DIO_enuPin_7
	
}DIO_enuPIN_OPTS_t;


typedef enum
{
	DIO_enuOutput,
	DIO_enuInputInternalPullup,
	DIO_enuInputExternalPulldown
	
}DIO_enuCONFIGRATIONS_OPTS_t;

typedef enum 
{
	DIO_enuLow ,
	DIO_enuHigh 

}DIO_enuSTATE_OPTS_t;

typedef enum 
{
	DIO_enuPortLow = 0x00 ,
	DIO_enuPortHigh = 0xFF 

}DIO_enuPORTSTATE_OPTS_t;



DIO_enuErrorState_t DIO_enuSetPinConfigration(DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuPIN_OPTS_t Copy_enuPinNum , DIO_enuCONFIGRATIONS_OPTS_t Copy_enuConfigration );

DIO_enuErrorState_t DIO_enuSetPortConfigration (DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuCONFIGRATIONS_OPTS_t Copy_enuConfigration );
 
DIO_enuErrorState_t DIO_enuSetPinValue(MPORT_enuPORT_OPTS_t Copy_enuPortNum , MPORT_enuPIN_OPTS_t Copy_enuPinNum , PORT_enuSTATE_OPTS_t Copy_enuState );
 
DIO_enuErrorState_t DIO_enuSetPortValue(DIO_enuPORT_OPTS_t Copy_enuPortNum ,DIO_enuPORTSTATE_OPTS_t Copy_enuPortState ); 
 
DIO_enuErrorState_t DIO_enuGetPinValue(MPORT_enuPORT_OPTS_t Copy_enuPortNum , MPORT_enuPIN_OPTS_t Copy_enuPinNum , u8* Add_pu8PinValue);




#endif   