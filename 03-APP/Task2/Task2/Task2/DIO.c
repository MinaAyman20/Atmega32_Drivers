#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"

#define   PORTA       (*(unsigned volatile char*)0x3B)
#define   DDRA        (*(unsigned volatile char*)0x3A)
#define   PINA        (*(unsigned volatile char*)0x39)
#define   PORTB       (*(unsigned volatile char*)0x38)
#define   DDRB        (*(unsigned volatile char*)0x37)
#define   PINB        (*(unsigned volatile char*)0x36)
#define   PORTC       (*(unsigned volatile char*)0x35)
#define   DDRC        (*(unsigned volatile char*)0x34)
#define   PINC        (*(unsigned volatile char*)0x33)
#define   PORTD       (*(unsigned volatile char*)0x32)
#define   DDRD        (*(unsigned volatile char*)0x31)
#define   PIND        (*(unsigned volatile char*)0x30)


DIO_enuErrorState_t DIO_enuSetPinConfigration(DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuPIN_OPTS_t Copy_enuPinNum , DIO_enuCONFIGRATIONS_OPTS_t Copy_enuConfigration )
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;
	
	if(Copy_enuPortNum > DIO_enuPort_D)
	 Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;

	else if(Copy_enuPinNum > DIO_enuPin_7)
	 Ret_enuErrorStates = DIO_enu_INVALID_PIN_NUM ;
 
    else if(Copy_enuConfigration > DIO_enuInputExternalPulldown)
	 Ret_enuErrorStates = DIO_enu_INVALID_CONFIGRATION;
    
	else 
	{
	   switch (Copy_enuPortNum)
	   {
         case DIO_enuPort_A:
		 switch(Copy_enuConfigration)
		 {
			case DIO_enuOutput :                     SET_BIT(DDRA,Copy_enuPinNum) ;            break;

			case DIO_enuInputInternalPullup :        CLR_BIT(DDRA,Copy_enuPinNum) ;      
			                                         SET_BIT(PORTA,Copy_enuPinNum);            break;

			case DIO_enuInputExternalPulldown :      CLR_BIT(DDRA,Copy_enuPinNum) ;            
                                                     CLR_BIT(PORTA,Copy_enuPinNum);            break;  

			default :                                                                          break;										 
		 }
           break;

	    case DIO_enuPort_B:
		switch(Copy_enuConfigration)
		 {
			case DIO_enuOutput :                     SET_BIT(DDRB,Copy_enuPinNum) ;            break;

			case DIO_enuInputInternalPullup :        CLR_BIT(DDRB,Copy_enuPinNum) ;      
			                                         SET_BIT(PORTB,Copy_enuPinNum);            break;

			case DIO_enuInputExternalPulldown :      CLR_BIT(DDRB,Copy_enuPinNum) ;            
                                                     CLR_BIT(PORTB,Copy_enuPinNum);            break;  
													 
			default :                                                                          break;										 
		 }
           break;
 
		case DIO_enuPort_C:
		switch(Copy_enuConfigration)
		 {
			case DIO_enuOutput :                     SET_BIT(DDRC,Copy_enuPinNum) ;            break;

			case DIO_enuInputInternalPullup :        CLR_BIT(DDRC,Copy_enuPinNum) ;      
			                                         SET_BIT(PORTC,Copy_enuPinNum);            break;

			case DIO_enuInputExternalPulldown :      CLR_BIT(DDRC,Copy_enuPinNum) ;            
                                                     CLR_BIT(PORTC,Copy_enuPinNum);            break;  
													 
			default :                                                                          break;										 
		 }
           break;

        case DIO_enuPort_D:
		switch(Copy_enuConfigration)
		 {
			case DIO_enuOutput :                     SET_BIT(DDRD,Copy_enuPinNum) ;            break;

			case DIO_enuInputInternalPullup :        CLR_BIT(DDRD,Copy_enuPinNum) ;      
			                                         SET_BIT(PORTD,Copy_enuPinNum);            break;

			case DIO_enuInputExternalPulldown :      CLR_BIT(DDRD,Copy_enuPinNum) ;            
                                                     CLR_BIT(PORTD,Copy_enuPinNum);            break;  
													 
			default :                                                                          break;										 
		 }
           break;

		  default :                                                                          break;										 
 
	   }
	   
	   
	}
}




DIO_enuErrorState_t DIO_enuSetPortConfigration (DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuCONFIGRATIONS_OPTS_t Copy_enuConfigration )
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;
	
	if(Copy_enuPortNum > DIO_enuPort_D)
	 Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;
 
   else if(Copy_enuConfigration > DIO_enuInputExternalPulldown)
	 Ret_enuErrorStates = DIO_enu_INVALID_CONFIGRATION;
    
	else
	{
		Ret_enuErrorStates = DIO_enu_OK ;
		
		switch (Copy_enuPortNum)
		{
               case  DIO_enuPort_A:
			   switch(Copy_enuConfigration)
			   {
                 case DIO_enuOutput:
                   DDRA=0xFF;
				 break;

				 case DIO_enuInputInternalPullup:
				 DDRA=0x00;
				 PORTA=0xFF;
				 break;

				 case DIO_enuInputExternalPulldown:
				 DDRA=0x00;
				 PORTA=0x00;
				 break;	   
				  default:   break;
			   }
			   break; 	

			   case  DIO_enuPort_B:
			   switch(Copy_enuConfigration)
			   {
                 case DIO_enuOutput:
                   DDRB=0xFF;
				 break;

				 case DIO_enuInputInternalPullup:
				 DDRB=0x00;
				 PORTB=0xFF;
				 break;

				 case DIO_enuInputExternalPulldown:
				 DDRB=0x00;
				 PORTB=0x00;
				 break;	  
				  default:   break;
			   } 
			   break;
			   case  DIO_enuPort_C:
			   switch(Copy_enuConfigration)
			   {
                 case DIO_enuOutput:
                   DDRC=0xFF;
				 break;

				 case DIO_enuInputInternalPullup:
				 DDRC=0x00;
				 PORTC=0xFF;
				 break;

				 case DIO_enuInputExternalPulldown:
				 DDRC=0x00;
				 PORTC=0x00;
				 break;	
				  default:   break;  
			   } 
               break;

			   case  DIO_enuPort_D:
			   switch(Copy_enuConfigration)
			   {
                 case DIO_enuOutput:
                 DDRD=0xFF;
				 break;

				 case DIO_enuInputInternalPullup:
				 DDRD=0x00;
				 PORTD=0xFF;
				 break;

				 case DIO_enuInputExternalPulldown:
				 DDRD=0x00;
				 PORTD=0x00;
				 break;	
				 default:   break;

			   } 
			   break;
			   default:     break;
		}
	}	
}




DIO_enuErrorState_t DIO_enuSetPinValue(DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuPIN_OPTS_t Copy_enuPinNum , DIO_enuSTATE_OPTS_t Copy_enuState )
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;
    
    if(Copy_enuPortNum > DIO_enuPort_D)
     Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;

    else if(Copy_enuPinNum > DIO_enuPin_7)
     Ret_enuErrorStates = DIO_enu_INVALID_PIN_NUM ;
 
    else if(Copy_enuState > DIO_enuHigh)
     Ret_enuErrorStates = DIO_enu_INVALID_STATE;
    
    else 
    {
		DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_OK  ;
       switch (Copy_enuPortNum)
       {
         case DIO_enuPort_A:
         switch (Copy_enuState)
		 {
            case DIO_enuHigh :            SET_BIT(PORTA,Copy_enuPinNum) ;                  break;
            case DIO_enuLow:              CLR_BIT(PORTA,Copy_enuPinNum) ;                  break;   
			default:                                                                       break;
		 }

           case DIO_enuPort_B:
		   switch (Copy_enuState)
		 {
            case DIO_enuHigh :            SET_BIT(PORTB,Copy_enuPinNum) ;                  break;
            case DIO_enuLow:              CLR_BIT(PORTB,Copy_enuPinNum) ;                  break;  
			default:                                                                       break;
 
		 }

		   case DIO_enuPort_C:
		   switch (Copy_enuState)
		 {
            case DIO_enuHigh :            SET_BIT(PORTC,Copy_enuPinNum) ;                  break;
            case DIO_enuLow:              CLR_BIT(PORTC,Copy_enuPinNum) ;                  break;   
			default:                                                                       break;

		 }
		   case DIO_enuPort_D:
		   switch (Copy_enuState)
		 {
            case DIO_enuHigh :            SET_BIT(PORTD,Copy_enuPinNum) ;                  break;
            case DIO_enuLow:              CLR_BIT(PORTD,Copy_enuPinNum) ;                  break; 
			default:                                                                       break;
  
		 }
		default:                                                                           break;
       }
     }
}


DIO_enuErrorState_t DIO_enuSetPortValue(DIO_enuPORT_OPTS_t Copy_enuPortNum ,DIO_enuSTATE_OPTS_t Copy_enuState )
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;

	if(Copy_enuPortNum > DIO_enuPort_D)
     Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;
 
    else if(Copy_enuState > DIO_enuHigh)
     Ret_enuErrorStates = DIO_enu_INVALID_STATE;
     
	 else 
	 {
          DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_OK  ;

		  switch(Copy_enuPortNum)
		  {
            case DIO_enuPort_A :       PORTA = Copy_enuState ;             break;
            case DIO_enuPort_B :                                           break;
			case DIO_enuPort_C :                                           break;
			case DIO_enuPort_D :       PORTD = Copy_enuState ;             break;

            default:                                                       break;			
		  }
			
			
    }

}



DIO_enuErrorState_t DIO_enuGetPinValue(DIO_enuPORT_OPTS_t Copy_enuPortNum , DIO_enuPIN_OPTS_t Copy_enuPinNum , u8* Add_pu8PinValue)
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;

	if(Copy_enuPortNum > DIO_enuPort_D)
     Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;
 
    else if(Copy_enuPinNum > DIO_enuPin_7)
     Ret_enuErrorStates = DIO_enu_INVALID_PIN_NUM;

	else if(Add_pu8PinValue = NULL)
     Ret_enuErrorStates = DIO_enu_NULL_PTR;

	else
	{
		DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_OK  ;               
        switch (Copy_enuPortNum)
        {
            case DIO_enuPort_A: Add_pu8PinValue = GET_BIT(PORTA,Copy_enuPinNum);              break;
			case DIO_enuPort_B: Add_pu8PinValue = GET_BIT(PORTA,Copy_enuPinNum);              break;
            case DIO_enuPort_C: Add_pu8PinValue = GET_BIT(PORTB,Copy_enuPinNum);              break;
            case DIO_enuPort_D: Add_pu8PinValue = GET_BIT(PORTC,Copy_enuPinNum);              break;
            default:                                                                          break;
	   }  

   }
}

























