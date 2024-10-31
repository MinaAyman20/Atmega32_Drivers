///*
// * main.c
// *
// *  Created on: Dec 31, 2023
// *      Author: Mina
// */
//
//#include "../HAL/HLCD/HLCD_interface.h"
//#include "../HAL/HKEYPAD/HKEYPAD_interface.h"
//#include <avr/delay.h>
//int main (void)
//{
//	HLCD_enuLCDPinConfigration();
//	HLCD_voidLCDInit();
//	HKEYPAD_enuInit();
//	//HLCD_enuWriteNumber(1234);
//	u8 key1;
//	u8 *key2;
//	u8 *op=0;
//
//	while(1)
//	{
//		//HKEYPAD_enuGetKey(&KeyStatus);
//		//HLCD_enuWriteNumber(KeyStatus);
//		//_delay_ms(30);
//
//		HLCD_voidSendString("EnteroperandOne",HLCD_enuFirstLine,HLCD_enuPosition0);
//		HKEYPAD_enuGetKey(&key1);
//
//		switch(key1)
//		{
//		case '+' :
//			HLCD_voidSendString("Addition Operation",HLCD_enuFirstLine,HLCD_enuPosition0);
//			break;
//
//		default:
//			HLCD_voidSendString("Entercorrectoperation",HLCD_enuFirstLine,HLCD_enuPosition0);
//			break;
//
//		}
//
//		return 0;
//	}
//}

#include "../LIB/STD_TYPES.h"
#include "../MCAL/01-PORT/MPort_Interface.h"
#include "../HAL/HLCD/HLCD_interface.h"
#include "../MCAL/05-MADC/MADC_interface.h"
#include "../HAL/HTEMP_SENSOR/HTEMP_SENSOR_interface.h"
#include "../HAL/HLDR_SENSOR/HLDR_SENSOR_interface.h"
#include "../HAL/HKEYPAD/HKEYPAD_interface.h"
#include <avr/delay.h>

#define REFRENCE_VOLTAGE 5

//int main(void) {
//
//    PORT_voidPortInit();
//    MADC_enuADCInit();
//    HLCD_voidLCDInit();
//    HKEYPAD_enuInit();
//
//
//    while(1) {
//    	u16 Local_u16Temp =0;
//        HLCD_voidLCDCLR();
//       // Local_u16Temp = HTEMPSENSOR_u16TEMP_SENSOR_Init(MADC_ADC0_SINGLE_ENDEDD);
//        MADC_u8StartConversionSync(MADC_ADC1_SINGLE_ENDEDD,&Local_u16Temp);
//       u16 Local_u16Light=((u32)(Local_u16Temp*(u32)(REFRENCE_VOLTAGE*1000))/1024UL);
//        HLCD_voidSendString("TEMP = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//        HLCD_enuWriteNumber(Local_u16Light);
//       // LCD_getanddisplayint(Local_u16Temp);
//        _delay_ms(500);
//
//
//    }
//    return 0;
//}


int main (void)
{
	    PORT_voidPortInit();
	    MADC_enuADCInit();
	    HLCD_enuLCDPinConfigration();
	    HLCD_voidLCDInit();
	    HKEYPAD_enuInit();

	       u8  static selectedOption ='0';
	       u16 temperatureReading = 0;
	       u16 lightIntensityReading = 0;
	       u16 voltmeterReading = 0;
	     //  u16 Local_u16light =0;
	       u16 Local_u16volt=0;
	       HLCD_voidLCDCLR();
	while(1)
	{           HKEYPAD_enuGetKey(&selectedOption);
		        /*Read if There is a Pressed Key*/
		        _delay_ms(500);

		        switch(selectedOption)
		        {
		        case '0':
		        	HLCD_voidLCDCLR();
//		            HLCD_voidSendString("1.temp", HLCD_enuFirstLine,HLCD_enuPosition0);
//		            HLCD_voidSendString("2.Light", HLCD_enuSecondLine,HLCD_enuPosition0);
//		            HLCD_voidSendString("3.Volt", HLCD_enuFirstLine,HLCD_enuPosition9);
//		            _delay_ms(10);
		            break;
		        case '1':
		        	HLCD_voidLCDCLR();
		        	HLCD_voidSendString("TEMP = ", HLCD_enuFirstLine, HLCD_enuPosition0);
		        	temperatureReading = HTEMPSENSOR_u16TEMP_SENSOR_Init(MADC_ADC0_SINGLE_ENDEDD);
		        	HLCD_enuWriteNumber(temperatureReading);
		        	HLCD_voidSendString("C ", HLCD_enuFirstLine, HLCD_enuPosition11);
		        //	 selectedOption = '1';
		            _delay_ms(1000);
		            break;
		        case '2':
		        	HLCD_voidLCDCLR();
		        	HLCD_voidSendString("LightInt = ", HLCD_enuFirstLine, HLCD_enuPosition0);
		        	lightIntensityReading=HLDRSENSOR_GetValue(MADC_ADC1_SINGLE_ENDEDD);
		        	HLCD_enuWriteNumber(lightIntensityReading);
		        	// selectedOption = '2';
		            _delay_ms(1000);
		            break;
		        case '3':
		        	HLCD_voidLCDCLR();
		        	HLCD_voidSendString("Voltage = ", HLCD_enuFirstLine, HLCD_enuPosition0);
		        	MADC_u8StartConversionSync(MADC_ADC2_SINGLE_ENDEDD,&Local_u16volt);
		            voltmeterReading = ((u32)(Local_u16volt * (u32)(REFRENCE_VOLTAGE * 1000)) / 1024UL/10);
		            HLCD_enuWriteNumber(voltmeterReading);
		           HLCD_voidSendString("mv", HLCD_enuFirstLine, HLCD_enuPosition14);
		          // selectedOption = '3';
		            _delay_ms(1000);
		            break;
		        default:
		        	HLCD_voidLCDCLR();
		        	//HLCD_voidSendString("Wrong Option", HLCD_enuFirstLine, HLCD_enuPosition0);
		        	HLCD_voidSendString("1-temp", HLCD_enuFirstLine,HLCD_enuPosition0);
		            HLCD_voidSendString("2-Light", HLCD_enuSecondLine,HLCD_enuPosition0);
		            HLCD_voidSendString("3-Volt", HLCD_enuFirstLine,HLCD_enuPosition9);
		            _delay_ms(50);

		        }
		    }

		    return 0;
		}


