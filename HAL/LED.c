/*
 * LED.c
 *
 * Created: 8/28/2024 1:21:17 PM
 *  Author: Mohamed
 */ 
#include "LED.h"

void LED_VoidIntializeLed(u8 port,u8 pin, u8 direction)
{
	DIO_voidSetPinDirection (port,pin,PIN_OUTPUT);
}
void LED_VoidTurnOn(u8 port,u8 pin, u8 value)
{
	DIO_voidSetPinValue (port,pin,PIN_HIGH);
}
void LED_VoidTurnOff(u8 port,u8 pin,u8 value)
{
	DIO_voidSetPinValue (port,pin,PIN_LOW);
	
}
void LED_VoidToggle(u8 port,u8 pin)
{
	DIO_VoidTogglePin(port,pin);
}

