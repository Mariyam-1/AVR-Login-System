/*
 * LCD_TYPES.h
 *
 * Created: 9/1/2024 6:17:04 PM
 *  Author: Mohamed
 */ 


#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

#include "../MCAL/DIO.h"

/*dEFINE PORTS*/
#define DATA_PORT PORTA_ID

#define Control_PORT PORTB_ID

/*Define Control pins*/

#define RS_pin PIN_0

//#define RW_pin PIN_2

#define E_pin PIN_1

/*Define Control pins*/

#define DO_PIN  PIN_0
#define D1_PIN  PIN_1
#define D2_PIN  PIN_2
#define D3_PIN  PIN_3
#define D4_PIN  PIN_4
#define D5_PIN  PIN_5
#define D6_PIN  PIN_6
#define D7_PIN  PIN_7

/*Commands*/

#define LCD_CLR                      0x01          
#define LCD_Return_home				 0x02 
#define LCD_Incrment				 0x06 
#define LCD_Display_ON				 0x0F
#define LCD_Shift_Left			     0x18 
#define LCD_Shift_Right				 0x1C 
#define LCD_FUN_SET_TWOLINE_5x7		 0x38 
#define LCD_Remove_Cursor  		 0x0C



#endif /* LCD_TYPES_H_ */