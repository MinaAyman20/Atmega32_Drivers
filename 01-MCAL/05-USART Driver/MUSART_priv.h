#ifndef D__ITI_WORKSPACE_MUSART_DRIVER_MCAL_06_MUSART_MUSART_PRIV_H_
#define D__ITI_WORKSPACE_MUSART_DRIVER_MCAL_06_MUSART_MUSART_PRIV_H_

#include "MUSART_config.h"


#define   UDR         (*(unsigned volatile char*)0x2C)  
#define   UCSRA       (*(unsigned volatile char*)0x2B)  
#define   UCSRB       (*(unsigned volatile char*)0x2A)  
#define   UCSRC       (*(unsigned volatile char*)0x40)  
#define   UBRRL		  (*(unsigned volatile char*)(0x29))
#define   UBRRH		  (*(unsigned volatile char*)(0x40))

#define   SREG        (*(unsigned volatile char*)0x5F)  


typedef void(*TxCB)(void);
typedef void(*RxCB)(void);

#endif