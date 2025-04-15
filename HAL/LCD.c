/*
 * LCD.c
 *
 * Created: 9/1/2024 6:13:29 PM
 *  Author: Mohamed
 */ 

#include "LCD.h"

void LCD_VoidEnable()
{
	DIO_voidSetPinValue(Control_PORT,E_pin,PIN_HIGH);	 /*make enable on*/
	_delay_ms(2);
	DIO_voidSetPinValue(Control_PORT,E_pin,PIN_LOW);	 /*make enable on*/
}
void LCD_VoidIntialization()
{
	DIO_voidSetPortDirection(Control_PORT,PORT_OUTPUT);
	DIO_voidSetPortDirection(DATA_PORT,PORT_OUTPUT);
	_delay_ms(30);
	LCD_VoidCommand(LCD_FUN_SET_TWOLINE_5x7);
	_delay_us(39);
	LCD_VoidCommand(LCD_Display_ON);
	_delay_us(39);	
	LCD_VoidCommand(LCD_CLR);
	_delay_ms(1.53);
	LCD_VoidCommand(LCD_Incrment);
	LCD_VoidEnable();
	
}
void LCD_VoidClear_Screen()
{
	LCD_VoidCommand(LCD_CLR);
	_delay_ms(30);
	LCD_VoidCommand(LCD_Return_home);
	_delay_ms(30);
}
void LCD_VoidCommand(u8 command)
{
	DIO_voidSetPinValue(Control_PORT,RS_pin,PIN_LOW);
	//DIO_voidSetPinValue(Control_PORT,RW_pin,PIN_LOW);
	DIO_voidSetPortValue(DATA_PORT,command);
	LCD_VoidEnable();
	
}
void LCD_VoidData(u8 data)
{
	DIO_voidSetPinValue(Control_PORT,RS_pin,PIN_HIGH);
	//DIO_voidSetPinValue(Control_PORT,RW_pin,PIN_LOW);
	DIO_voidSetPortValue(DATA_PORT,data);
	LCD_VoidEnable();
	
}
void LCD_VoidMove_Cursor(u8 row, u8 col)
{
	u8 address;
	if(row<=1 && col<=15)
	{
		address=(row*0x40)+col;
		address=Set_Bit(address,PIN_7);
		LCD_VoidCommand(address);
	}
	
}
void LCD_VoidSendString(const u8 *str)
{
	for(u8 i=0;str[i]!='\0';i++)
	{
		LCD_VoidData(str[i]);
	}
}

void LCD_VoidRemove_Cursor(){
	
	LCD_VoidCommand(LCD_Remove_Cursor);
	
	
}

void int_to_str(u32 num,u8 *str)
{
	u8 i = 0;
	if (num == 0) {
		str[i++] = '0';
		} else {
		u8 temp[50];
		u32 j = 0;
		while (num > 0) {
			temp[j++] = (num % 10) + '0';
			num /= 10;
		}
		
		for (u32 k = 0; k < j; k++) {
			str[k] = temp[j - k - 1];
		}
		i = j;
	}
	str[i] = '\0';
}


