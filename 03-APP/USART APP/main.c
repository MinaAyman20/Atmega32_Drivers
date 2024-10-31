///*
// * main.c
// *
// *  Created on: Dec 31, 2023
// *      Author: Mina
// */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/01-PORT/MPort_Interface.h"
#include "../MCAL/05-MADC/MADC_interface.h"
#include "../HAL/00-LED/HLED_init.h"
#include "../HAL/HLCD/HLCD_interface.h"
#include "../HAL/HTEMP_SENSOR/HTEMP_SENSOR_interface.h"
#include "../HAL/HLDR_SENSOR/HLDR_SENSOR_interface.h"
#include "../MCAL/06-MUSART/MUSART_interface.h" 
#include <util/delay.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define REFERENCE_VOLTAGE 5

u16 temperatureReading = 0;
u16 lightIntensityReading = 0;
u16 voltmeterReading = 0;

u16 Local_u16volt = 0;
u16 Local_u16Volt = 0;
u16 Local_u16Temp = 0;
u16 Local_u16Light = 0;
u16 Local_u16ADC_Temp = 0;
u16 Local_u16ADC_Light = 0;
u16 Local_u16ADC_Volt = 0;


u8 usernames[MAX_USERS][MAX_USERNAME_LENGTH + 1]; // Add space for null terminator
u8 passwords[MAX_USERS][MAX_PASSWORD_LENGTH + 1]; // Add space for null terminator
u8 num_users = 0;

//u8 static option =0 ;
u8 static cases = '0';
u8 option_size = 2;

void EndOfConversionNotification(void)
{
	static u8 current_state = HLED_enuOFF;

	    // Toggle the LED state
	    if (current_state == HLED_enuOFF) {
	        HLED_enuSetLedState(LED_ONE, HLED_enuON);
	        current_state = HLED_enuON;
	    } else {
	        HLED_enuSetLedState(LED_ONE, HLED_enuOFF);
	        current_state = HLED_enuOFF;
	    }


}

void MUSART_enuReceiveStringSync(u8 *string, u8 max_length) {
    u8 receivedChar;
    u8 charCount = 0;

    // Receive characters until enter key is pressed or maximum length is reached
    while (charCount < max_length) {
        // Receive a byte synchronously
        MUSART_enuRecieveByteSync(&receivedChar);

        // Check if received character is enter key
        if (receivedChar == '\r' || receivedChar == '\n') {
            // Terminate string with null character
            string[charCount] = '\0';
            break;
        } else {
            // Save character to string buffer
            string[charCount] = receivedChar;
            charCount++;
        }
    }
}

int main(void) {
    PORT_voidPortInit();
    HLED_enuInit();
    MUSART_enuInit();
    MADC_enuADCInit();
    HLCD_enuLCDPinConfigration();
    HLCD_voidLCDInit();

    HLCD_voidLCDCLR();
    HLCD_voidSendString("Hello", HLCD_enuFirstLine, HLCD_enuPosition5);
    _delay_ms(1500);

    while (1) {
        HLCD_voidSendString("1-Create NewUser", HLCD_enuFirstLine, HLCD_enuPosition0);
        HLCD_voidSendString("2-Login ", HLCD_enuSecondLine, HLCD_enuPosition0);

        u8 option;
        MUSART_enuRecieveByteSync(&option);
        HLCD_voidLCDCLR();

        switch (option) {
            case '1': {
                HLCD_voidLCDCLR();
                if (num_users < MAX_USERS) {
                    // Prompt user to enter username
                    HLCD_voidSendString("Enter Username: ", HLCD_enuFirstLine, HLCD_enuPosition0);
                    MUSART_enuReceiveStringSync(usernames[num_users], MAX_USERNAME_LENGTH);
                    _delay_ms(700);
                    HLCD_voidLCDCLR();
                    // Prompt user to enter password
                    HLCD_voidSendString("Enter Password: ", HLCD_enuFirstLine, HLCD_enuPosition0);
                    MUSART_enuReceiveStringSync(passwords[num_users], MAX_PASSWORD_LENGTH);
                    _delay_ms(700);
                    HLCD_voidLCDCLR();
                    num_users++;
                    HLCD_voidSendString("User created!", HLCD_enuFirstLine, HLCD_enuPosition0);
                    _delay_ms(700);
                } else {
                    HLCD_voidSendString("Max users reached!", HLCD_enuFirstLine, HLCD_enuPosition0);
                    _delay_ms(700);
                }
                break;
            }
            case '2': {
                HLCD_voidSendString("Enter Username: ", HLCD_enuFirstLine, HLCD_enuPosition0);
                u8 username[MAX_USERNAME_LENGTH + 1];
                MUSART_enuReceiveStringSync(username, MAX_USERNAME_LENGTH);
                HLCD_voidLCDCLR();
                HLCD_voidSendString("Enter Password: ", HLCD_enuFirstLine, HLCD_enuPosition0);
                u8 password[MAX_PASSWORD_LENGTH + 1];
                MUSART_enuReceiveStringSync(password, MAX_PASSWORD_LENGTH);
                HLCD_voidLCDCLR();

                // Check if username and password match
                u8 i;
                for (i = 0; i < num_users; i++) {
                    if (strcmp(usernames[i], username) == 0 && strcmp(passwords[i], password) == 0) {
                        HLCD_voidSendString("Hello, ", HLCD_enuFirstLine, HLCD_enuPosition0);
                        HLCD_voidSendString(username, HLCD_enuFirstLine, HLCD_enuPosition7); // Assuming the username is displayed starting from position 7
                        _delay_ms(1000);
                        HLCD_voidLCDCLR();

                        while (1)
                        {

                            HLCD_voidSendString("1-temp", HLCD_enuFirstLine, HLCD_enuPosition0);
                            HLCD_voidSendString("2-Light", HLCD_enuSecondLine, HLCD_enuPosition0);
                            HLCD_voidSendString("3-Volt", HLCD_enuFirstLine, HLCD_enuPosition9);
                            HLCD_voidSendString("4-Back", HLCD_enuSecondLine, HLCD_enuPosition9);
                            MUSART_enuRecieveByteSync(&cases);

                            switch (cases) {
                                case '1': {
                                	HLCD_voidLCDCLR();
                                	    HLCD_voidSendString("TEMP = ", HLCD_enuFirstLine, HLCD_enuPosition0);
                                	    MADC_u8StartConversionAsynch(MADC_ADC0_SINGLE_ENDEDD, &Local_u16ADC_Temp, EndOfConversionNotification);
                                	    _delay_ms(30);
                                	    Local_u16Temp = ((u32)(Local_u16ADC_Temp * (u32)(REFERENCE_VOLTAGE * 1000)) / 1024UL) / 100;
                                	    HLCD_enuWriteNumber(Local_u16Temp);
                                	    HLCD_voidSendString("C ", HLCD_enuFirstLine, HLCD_enuPosition11);
                                	    _delay_ms(1000);
                                	    HLCD_voidLCDCLR();
                                	    break;
                                }
                                case '2': {
                                    HLCD_voidLCDCLR();
                                    HLCD_voidSendString("LightInt = ", HLCD_enuFirstLine, HLCD_enuPosition0);
                                    MADC_u8StartConversionAsynch(MADC_ADC1_SINGLE_ENDEDD, &Local_u16ADC_Light, EndOfConversionNotification);
                                    _delay_ms(30);
                                    Local_u16Light =((u32)(Local_u16ADC_Light * (u32)(REFERENCE_VOLTAGE * 1000)) / 1024UL) ;
                                    HLCD_enuWriteNumber(Local_u16Light);
                                    _delay_ms(1000);
                                    HLCD_voidLCDCLR();
                                    break;
                                }
                                case '3': {
                                    HLCD_voidLCDCLR();
                                    HLCD_voidSendString("Voltage=", HLCD_enuFirstLine, HLCD_enuPosition0);
                                    MADC_u8StartConversionAsynch(MADC_ADC2_SINGLE_ENDEDD, &Local_u16ADC_Volt, EndOfConversionNotification);
                                    _delay_ms(30);
                                    Local_u16Volt = ((u32)(Local_u16ADC_Volt * (u32)(REFERENCE_VOLTAGE * 1000)) / 1024UL / 10);
                                    HLCD_enuWriteNumber(Local_u16Volt);
                                    HLCD_voidSendString("mv", HLCD_enuFirstLine, HLCD_enuPosition14);
                                    _delay_ms(1000);
                                    HLCD_voidLCDCLR();
                                    break;
                                }
                                case '4': {
                                    HLCD_voidLCDCLR();
                                    break;
                                }
                                default:
                                    break;
                            }

                            if (cases == '4') {
                                break;
                            }
                        }
                        // Exit the for loop since we found a match
                        break;
                    }
                }
                // Check if the loop ended without finding a match
                if (i == num_users) {
                    HLCD_voidSendString("Access Denied", HLCD_enuFirstLine, HLCD_enuPosition0);
                    _delay_ms(1000);
                }

                break;
            }
            // Add more cases for other options
            default:
                break;
        }
    }

    return 0;
}















// #define MAX_USERS 10
// #define MAX_USERNAME_LENGTH 20
// #define MAX_PASSWORD_LENGTH 20
// #define REFERENCE_VOLTAGE 5

// u16 temperatureReading = 0;
// u16 lightIntensityReading = 0;
// u16 voltmeterReading = 0;
// u16 Local_u16volt = 0;

// u8 usernames[MAX_USERS][MAX_USERNAME_LENGTH + 1];
// u8 passwords[MAX_USERS][MAX_PASSWORD_LENGTH + 1];
// u8 num_users = 0;

// u8 option = 0;
// u8 cases = '0';
// u8 option_size = 2;

// enum State {
//     MAIN_MENU,
//     CREATE_USER,
//     LOGIN,
//     USER_MENU,
//     DISPLAY_TEMP,
//     DISPLAY_LIGHT,
//     DISPLAY_VOLTAGE,
// };
 
// enum State currentState = MAIN_MENU;

// void MUSART_enuReceiveStringSync(u8* string,u8 max_length) {
//      u8 receivedChar;
//      u8 charCount = 0;

//      // Receive characters until enter key is pressed or maximum length is reached
//      while (charCount < max_length) {
//          // Receive a byte synchronously
//          MUSART_enuRecieveByteSync(&receivedChar);

//          // Check if received character is enter key
//          if (receivedChar == '\r' || receivedChar == '\n') {
//              // Terminate string with null character
//              string[charCount] = '\0';
//              break;
//          } else {
//              // Save character to string buffer
//              string[charCount] = receivedChar;
//              charCount++;
//          }
//      }
//  }


// void main_menu() {
//     HLCD_voidSendString("1-Create NewUser", HLCD_enuFirstLine, HLCD_enuPosition0);
//     HLCD_voidSendString("2-Login ", HLCD_enuSecondLine, HLCD_enuPosition0);
//      u8 option ;
//     MUSART_enuRecieveByteSync(&option);
//     switch (option)
//     {
//         case (1):
//         {
//             currentState = CREATE_USER;
//             break;
//         }
//         case (2):
//         {
//             currentState =LOGIN;
//             break;
//         }
//         default : break;

//     }
      
// }

// void create_user() {
//     if (num_users < MAX_USERS) {
//         // Prompt user to enter username
//         HLCD_voidSendString("Enter Username: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//         MUSART_enuReceiveStringSync(usernames[num_users], MAX_USERNAME_LENGTH);
//         _delay_ms(1000);
//         HLCD_voidLCDCLR();
//         // Prompt user to enter password
//         HLCD_voidSendString("Enter Password: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//         MUSART_enuReceiveStringSync(passwords[num_users], MAX_PASSWORD_LENGTH);
//         _delay_ms(1000);
//         HLCD_voidLCDCLR();
//         num_users++;
//         HLCD_voidSendString("User created!", HLCD_enuFirstLine, HLCD_enuPosition0);
//         _delay_ms(1000);
//     } else {
//         HLCD_voidSendString("Max users reached!", HLCD_enuFirstLine, HLCD_enuPosition0);
//         _delay_ms(1000);
//     }
//     currentState = MAIN_MENU;
// }

// void login() {
//     HLCD_voidSendString("Enter Username: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//     u8 username[MAX_USERNAME_LENGTH + 1];
//     MUSART_enuReceiveStringSync(username, MAX_USERNAME_LENGTH);
//     HLCD_voidLCDCLR();
//     HLCD_voidSendString("Enter Password: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//     u8 password[MAX_PASSWORD_LENGTH + 1];
//     MUSART_enuReceiveStringSync(password, MAX_PASSWORD_LENGTH);
//     HLCD_voidLCDCLR();

//     // Check if username and password match
//     u8 i;
//     for (i = 0; i < num_users; i++) {
//         if (strcmp(usernames[i], username) == 0 && strcmp(passwords[i], password) == 0) {
//             currentState = USER_MENU;
//             break;
//         }
//     }

//     // Check if the loop ended without finding a match
//     if (i == num_users) {
//         HLCD_voidSendString("Access Denied", HLCD_enuFirstLine, HLCD_enuPosition0);
//         _delay_ms(1000);
//         currentState = MAIN_MENU;
//     }
// }

// void user_menu() {
//     HLCD_voidSendString("1-temp", HLCD_enuFirstLine, HLCD_enuPosition0);
//     HLCD_voidSendString("2-Light", HLCD_enuSecondLine, HLCD_enuPosition0);
//     HLCD_voidSendString("3-Volt", HLCD_enuFirstLine, HLCD_enuPosition9);
//     HLCD_voidSendString("4-Back", HLCD_enuSecondLine, HLCD_enuPosition9);
// }

// void display_temp() {
//     HLCD_voidLCDCLR();
//     HLCD_voidSendString("TEMP = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//     temperatureReading = HTEMPSENSOR_u16TEMP_SENSOR_Init(MADC_ADC0_SINGLE_ENDEDD);
//     HLCD_enuWriteNumber(temperatureReading);
//     HLCD_voidSendString("C ", HLCD_enuFirstLine, HLCD_enuPosition11);
//     _delay_ms(1000);
//     currentState = USER_MENU;
// }

// void display_light() {
//     HLCD_voidLCDCLR();
//     HLCD_voidSendString("LightInt = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//     lightIntensityReading = HLDRSENSOR_GetValue(MADC_ADC1_SINGLE_ENDEDD);
//     HLCD_enuWriteNumber(lightIntensityReading);
//     _delay_ms(1000);
//     currentState = USER_MENU;
// }

// void display_voltage() {
//     HLCD_voidLCDCLR();
//     HLCD_voidSendString("Voltage = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//     MADC_u8StartConversionSync(MADC_ADC2_SINGLE_ENDEDD, &Local_u16volt);
//     voltmeterReading = ((u32)(Local_u16volt * (u32)(REFERENCE_VOLTAGE * 1000)) / 1024UL / 10);
//     HLCD_enuWriteNumber(voltmeterReading);
//     HLCD_voidSendString("mv", HLCD_enuFirstLine, HLCD_enuPosition14);
//     _delay_ms(1000);
//     currentState = USER_MENU;
// }

// int main(void) {
//     PORT_voidPortInit();
//     MADC_enuADCInit();
//     MUSART_enuInit();
//     HLCD_enuLCDPinConfigration();
//     HLCD_voidLCDInit();

//     HLCD_voidLCDCLR();
//     HLCD_voidSendString("Hello", HLCD_enuFirstLine, HLCD_enuPosition5);
//     _delay_ms(1000);

//     while (1) {
//         switch (currentState) {
//             case MAIN_MENU:
//                 main_menu();
//                 break;
//             case CREATE_USER:
//                 create_user();
//                 break;
//             case LOGIN:
//                 login();
//                 break;
//             case USER_MENU:
//                 user_menu();
//                 break;
//             case DISPLAY_TEMP:
//                 display_temp();
//                 break;
//             case DISPLAY_LIGHT:
//                 display_light();
//                 break;
//             case DISPLAY_VOLTAGE:
//                 display_voltage();
//                 break;
//             default:
//                 // Handle invalid state
//                 break;
//         }
//     }

//     return 0;
// }


















//#define MAX_USERS 10
// #define MAX_USERNAME_LENGTH 20
// #define MAX_PASSWORD_LENGTH 20
// #define REFERENCE_VOLTAGE 5
//
// u16 temperatureReading = 0;
// u16 lightIntensityReading = 0;
// u16 voltmeterReading = 0;
// u16 Local_u16volt=0;
//
// u8 usernames[MAX_USERS][MAX_USERNAME_LENGTH + 1]; // Add space for null terminator
// u8 passwords[MAX_USERS][MAX_PASSWORD_LENGTH + 1]; // Add space for null terminator
// u8 num_users = 0;
//
// //u8 static option =0 ;
// u8 static cases = '0' ;
// u8 option_size = 2;
//
// void MUSART_enuReceiveStringSync(u8* string,u8 max_length) {
//     u8 receivedChar;
//     u8 charCount = 0;
//
//     // Receive characters until enter key is pressed or maximum length is reached
//     while (charCount < max_length) {
//         // Receive a byte synchronously
//         MUSART_enuRecieveByteSync(&receivedChar);
//
//         // Check if received character is enter key
//         if (receivedChar == '\r' || receivedChar == '\n') {
//             // Terminate string with null character
//             string[charCount] = '\0';
//             break;
//         } else {
//             // Save character to string buffer
//             string[charCount] = receivedChar;
//             charCount++;
//         }
//     }
// }
//
//
// int main(void)
// {
//    PORT_voidPortInit();
//    MUSART_enuInit();
//    MADC_enuADCInit();
//    HLCD_enuLCDPinConfigration();
//    HLCD_voidLCDInit();
//
//    HLCD_voidLCDCLR();
//    HLCD_voidSendString("Hello", HLCD_enuFirstLine, HLCD_enuPosition5);
//    _delay_ms(1000);
//
//    while (1) {
//        HLCD_voidSendString("1-Create NewUser", HLCD_enuFirstLine, HLCD_enuPosition0);
//        HLCD_voidSendString("2-Login ", HLCD_enuSecondLine, HLCD_enuPosition0);
//
//        u8 option;
//        MUSART_enuRecieveByteSync(&option);
//        HLCD_voidLCDCLR();
//
//        switch (option) {
//            case '1': {
//                HLCD_voidLCDCLR();
//                if (num_users < MAX_USERS) {
//                    // Prompt user to enter username
//                    HLCD_voidSendString("Enter Username: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                    MUSART_enuReceiveStringSync(usernames[num_users], MAX_USERNAME_LENGTH);
//                    _delay_ms(1000);
//                    HLCD_voidLCDCLR();
//                    // Prompt user to enter password
//                    HLCD_voidSendString("Enter Password: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                    MUSART_enuReceiveStringSync(passwords[num_users], MAX_PASSWORD_LENGTH);
//                    _delay_ms(1000);
//                    HLCD_voidLCDCLR();
//                    num_users++;
//                    HLCD_voidSendString("User created!", HLCD_enuFirstLine, HLCD_enuPosition0);
//                    _delay_ms(1000);
//                } else {
//                    HLCD_voidSendString("Max users reached!", HLCD_enuFirstLine, HLCD_enuPosition0);
//                    _delay_ms(1000);
//                }
//                break;
//            }
//            case '2': {
//                HLCD_voidSendString("Enter Username: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                u8 username[MAX_USERNAME_LENGTH + 1];
//                MUSART_enuReceiveStringSync(username, MAX_USERNAME_LENGTH);
//                HLCD_voidLCDCLR();
//                HLCD_voidSendString("Enter Password: ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                u8 password[MAX_PASSWORD_LENGTH + 1];
//                MUSART_enuReceiveStringSync(password, MAX_PASSWORD_LENGTH);
//                HLCD_voidLCDCLR();
//
//                // Check if username and password match
//                u8 i;
//                for (i = 0; i < num_users; i++) {
//                    if (strcmp(usernames[i], username) == 0 && strcmp(passwords[i], password) == 0) {
//                        HLCD_voidSendString("Hello, ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                        HLCD_voidSendString(username, HLCD_enuFirstLine, HLCD_enuPosition7); // Assuming the username is displayed starting from position 7
//                        _delay_ms(1000);
//                        HLCD_voidLCDCLR();
//
//                       while (cases != '4') { // Adjusted while loop condition
//                            HLCD_voidSendString("1-temp", HLCD_enuFirstLine, HLCD_enuPosition0);
//                            HLCD_voidSendString("2-Light", HLCD_enuSecondLine, HLCD_enuPosition0);
//                            HLCD_voidSendString("3-Volt", HLCD_enuFirstLine, HLCD_enuPosition9);
//                            HLCD_voidSendString("4-Back", HLCD_enuSecondLine, HLCD_enuPosition9);
//                            MUSART_enuRecieveByteSync(&cases); // Update cases within the loop
//
//                            switch (cases) {
//                                case '1': {
//                                    HLCD_voidLCDCLR();
//                                    HLCD_voidSendString("TEMP = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                                    temperatureReading = HTEMPSENSOR_u16TEMP_SENSOR_Init(MADC_ADC0_SINGLE_ENDEDD);
//                                    HLCD_enuWriteNumber(temperatureReading);
//                                    HLCD_voidSendString("C ", HLCD_enuFirstLine, HLCD_enuPosition11);
//                                    _delay_ms(1000);
//                                    HLCD_voidLCDCLR();
//                                    break;
//                                }
//                                case '2': {
//                                    HLCD_voidLCDCLR();
//                                    HLCD_voidSendString("LightInt = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                                    lightIntensityReading = HLDRSENSOR_GetValue(MADC_ADC1_SINGLE_ENDEDD);
//                                    HLCD_enuWriteNumber(lightIntensityReading);
//                                    _delay_ms(1000);
//                                    break;
//                                }
//                                case '3': {
//                                    HLCD_voidLCDCLR();
//                                    HLCD_voidSendString("Voltage = ", HLCD_enuFirstLine, HLCD_enuPosition0);
//                                    MADC_u8StartConversionSync(MADC_ADC2_SINGLE_ENDEDD, &Local_u16volt);
//                                    voltmeterReading = ((u32)(Local_u16volt * (u32)(REFERENCE_VOLTAGE * 1000)) / 1024UL / 10);
//                                    HLCD_enuWriteNumber(voltmeterReading);
//                                    HLCD_voidSendString("mv", HLCD_enuFirstLine, HLCD_enuPosition14);
//                                    _delay_ms(1000);
//                                    break;
//                                }
//                                case '4': {
//                                    HLCD_voidLCDCLR();
//                                    break;
//                                }
//                                default:
//                                    break;
//                            }
//                        }
//                        // Exit the for loop since we found a match
//                        break;
//                    }
//                }
//                // Check if the loop ended without finding a match
//                if (i == num_users) {
//                    HLCD_voidSendString("Access Denied", HLCD_enuFirstLine, HLCD_enuPosition0);
//                    _delay_ms(1000);
//                }
//
//                break;
//            }
//            // Add more cases for other options
//            default:
//                break;
//        }
//    }
//
//    return 0;
//}
//
