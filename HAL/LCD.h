/*
 * LCD.h
 *
 * Created: 9/1/2024 6:13:47 PM
 *  Author: Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_TYPES.h"
#define F_CP	8000000UL
#include <util/delay.h>

void LCD_VoidIntialization();
void LCD_VoidCommand(u8 command);
void LCD_VoidData(u8 data);
void LCD_VoidSendString(const u8 *str);
void LCD_VoidMove_Cursor(u8 row, u8 col);
void LCD_VoidClear_Screen();
void LCD_VoidEnable();
void int_to_str(u32 num,u8 *str);
void LCD_VoidRemove_Cursor();








#endif /* LCD_H_ */