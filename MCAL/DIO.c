/*
 * DIO.c
 *
 * Created: 9/1/2024 5:41:40 PM
 *  Author: Mohamed
 */ 
#include "DIO.h"

void DIO_voidSetPinDirection(u8 port,u8 pin, u8 direction)
{
	if(direction==PIN_INPUT)
	{
		switch(port)
		{
			case PORTA_ID:
			Clr_Bit(DDRA,pin);
			break;
			case PORTB_ID:
			Clr_Bit(DDRB,pin);
			break;
			case PORTC_ID:
			Clr_Bit(DDRC,pin);
			break;
			case PORTD_ID:
			Clr_Bit(DDRD,pin);
			break;
		}
	}
	else if(direction==PIN_OUTPUT)
	{
		switch(port)
		{
			case PORTA_ID:
			Set_Bit(DDRA,pin);
			break;
			case PORTB_ID:
			Set_Bit(DDRB,pin);
			break;
			case PORTC_ID:
			Set_Bit(DDRC,pin);
			break;
			case PORTD_ID:
			Set_Bit(DDRD,pin);
			break;
		}
	}
}

void DIO_voidSetPinValue(u8 port,u8 pin, u8 value)
{
	if(value==PIN_LOW)
	{
		switch(port)
		{
			case PORTA_ID:
			Clr_Bit(PORTA,pin);
			break;
			case PORTB_ID:
			Clr_Bit(PORTB,pin);
			break;
			case PORTC_ID:
			Clr_Bit(PORTC,pin);
			break;
			case PORTD_ID:
			Clr_Bit(PORTD,pin);
			break;
		}
	}
	else if(value==PIN_HIGH)
	{
		switch(port)
		{
			case PORTA_ID:
			Set_Bit(PORTA,pin);
			break;
			case PORTB_ID:
			Set_Bit(PORTB,pin);
			break;
			case PORTC_ID:
			Set_Bit(PORTC,pin);
			break;
			case PORTD_ID:
			Set_Bit(PORTD,pin);
			break;
		}
	}
	
}

u8 DIO_u8GetPinValue(u8 port,u8 pin)
{
	switch(port)
	{
		case PORTA_ID:
		return Get_Bit(PINA,pin);
		break;
		case PORTB_ID:
		return Get_Bit(PINB,pin);
		break;
		case PORTC_ID:
		return Get_Bit(PINC,pin);
		break;
		case PORTD_ID:
		return Get_Bit(PIND,pin);
		break;
	}
}

void DIO_voidSetPortDirection(u8 port,u8 direction)
{
	
		switch(port)
		{
			case PORTA_ID:
			DDRA=direction;
			break;
			case PORTB_ID:
			DDRB=direction;
			break;
			case PORTC_ID:
			DDRC=direction;
			break;
			case PORTD_ID:
			DDRD=direction;
			break;
		}
	
	
}

void DIO_voidSetPortValue(u8 port,u8 value)
{
	switch(port)
	{
		case PORTA_ID:
		PORTA=value;
		break;
		case PORTB_ID:
		PORTB=value;
		break;
		case PORTC_ID:
		PORTC=value;
		break;
		case PORTD_ID:
		PORTD=value;
		break;
	}
}

u8 DIO_u8GetPortValue(u8 port,u8 pin)
{
	switch(port)
	{
		case PORTA_ID:
		return PINA;
		case PORTB_ID:
		return PINB;
		case PORTC_ID:
		return PINC;
		case PORTD_ID:
		return PIND;
	}
}
void DIO_VoidTogglePin(u8 port,u8 pin)
{
	switch(port)
	{
		case PORTA_ID:
		Toggle_Bit(PORTA,pin);
		break;
		case PORTB_ID:
		Toggle_Bit(PORTB,pin);
		break;
		case PORTC_ID:
		Toggle_Bit(PORTC,pin);
		break;
		case PORTD_ID:
		Toggle_Bit(PORTD,pin);
		break;
	}
	
}