#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "MPort_Interface.h"
#include "Mport_Priv.h"




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
	return Ret_enuErrorStates ;
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
	return Ret_enuErrorStates ;	
}




DIO_enuErrorState_t DIO_enuSetPinValue(MPORT_enuPORT_OPTS_t Copy_enuPortNum , MPORT_enuPIN_OPTS_t Copy_enuPinNum , PORT_enuSTATE_OPTS_t Copy_enuState )
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;
    
    if(Copy_enuPortNum > MPORT_enuPort_D)
     Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;

    else if(Copy_enuPinNum > MPORT_enuPin_7)
     Ret_enuErrorStates = DIO_enu_INVALID_PIN_NUM ;
 
    else if(Copy_enuState > MPORT_enuHIGH)
     Ret_enuErrorStates = DIO_enu_INVALID_STATE;
    
    else 
    {
		 Ret_enuErrorStates = DIO_enu_OK  ;
       switch (Copy_enuPortNum)
       {
         case MPORT_enuPort_A:
         switch (Copy_enuState)
		 {
            case MPORT_enuHIGH :              SET_BIT(PORTA,Copy_enuPinNum) ;                  break;
            case MPORT_enuLOW  :              CLR_BIT(PORTA,Copy_enuPinNum) ;                  break;   
			default:                                                                           break;
		 }
          break;
           case MPORT_enuPort_B:
		   switch (Copy_enuState)
		 {
            case MPORT_enuHIGH :              SET_BIT(PORTB,Copy_enuPinNum) ;                  break;
            case MPORT_enuLOW  :              CLR_BIT(PORTB,Copy_enuPinNum) ;                  break;  
			default:                                                                           break;
 
		 }
          break;
		   case MPORT_enuPort_C:
		   switch (Copy_enuState)
		 {
            case MPORT_enuHIGH :              SET_BIT(PORTC,Copy_enuPinNum) ;                  break;
            case MPORT_enuLOW  :              CLR_BIT(PORTC,Copy_enuPinNum) ;                  break;   
			default:                                                                           break;

		 }
		  break;
		   case MPORT_enuPort_D:
		   switch (Copy_enuState)
		 {
            case MPORT_enuHIGH :            SET_BIT(PORTD,Copy_enuPinNum) ;                  break;
            case MPORT_enuLOW:              CLR_BIT(PORTD,Copy_enuPinNum) ;                  break; 
			default:                                                                         break;
  
		 }
		 break;
		default:                                                                           break;
       }
     }
	 return Ret_enuErrorStates ;
}


DIO_enuErrorState_t DIO_enuSetPortValue(DIO_enuPORT_OPTS_t Copy_enuPortNum ,DIO_enuPORTSTATE_OPTS_t Copy_enuPortState )
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;

	if(Copy_enuPortNum > DIO_enuPort_D)
     Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;
 
    else if(Copy_enuPortState > DIO_enuPortHigh)
     Ret_enuErrorStates = DIO_enu_INVALID_STATE;
     
	 else 
	 {
           Ret_enuErrorStates = DIO_enu_OK  ;

		  switch(Copy_enuPortNum)
		  {
            case DIO_enuPort_A :       PORTA = Copy_enuPortState ;             break;
            case DIO_enuPort_B :       PORTB = Copy_enuPortState ;             break;
			case DIO_enuPort_C :       PORTC = Copy_enuPortState ;             break;
			case DIO_enuPort_D :       PORTD = Copy_enuPortState ;             break;

            default:                                                           break;			
		  }
			
			
     }
   return Ret_enuErrorStates ;
}



DIO_enuErrorState_t DIO_enuGetPinValue(MPORT_enuPORT_OPTS_t Copy_enuPortNum , MPORT_enuPIN_OPTS_t Copy_enuPinNum , u8* Add_pu8PinValue)
{
	DIO_enuErrorState_t Ret_enuErrorStates = DIO_enu_NOK  ;

	if(Copy_enuPortNum > MPORT_enuPort_D)
     Ret_enuErrorStates = DIO_enu_INVALID_PORT_NUM ;

    else if(Copy_enuPinNum > MPORT_enuPin_7)
     Ret_enuErrorStates = DIO_enu_INVALID_PIN_NUM ;
    
	else if(Add_pu8PinValue == NULL)
     Ret_enuErrorStates = DIO_enu_NULL_PTR;

	else
	{
		 Ret_enuErrorStates = DIO_enu_OK  ;               
        switch (Copy_enuPortNum)
        {
            case MPORT_enuPort_A: *Add_pu8PinValue = GET_BIT(PINA,Copy_enuPinNum);              break;
			case MPORT_enuPort_B: *Add_pu8PinValue = GET_BIT(PINB,Copy_enuPinNum);              break;
            case MPORT_enuPort_C: *Add_pu8PinValue = GET_BIT(PINC,Copy_enuPinNum);              break;
            case MPORT_enuPort_D: *Add_pu8PinValue = GET_BIT(PIND,Copy_enuPinNum);              break;
            default:                                                                            break;
	   }  

   }
   return Ret_enuErrorStates ;
}

























