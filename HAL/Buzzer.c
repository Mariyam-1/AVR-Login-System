/*
 * Buzzer.c
 *
 * Created: 9/18/2024 11:56:59 AM
 *  Author: Mohamed
 */ 
#include "Buzzer.h"

void BUZZER_VoidINT()
{
	DIO_voidSetPinDirection(PORTD_ID,PIN_4,PIN_OUTPUT);
}
void BUZZER_VoidTurnON()
{
	DIO_voidSetPinValue(PORTD_ID,PIN_4,PIN_HIGH);
}
void BUZZER_VoidTurnOFF()
{
	DIO_voidSetPinValue(PORTD_ID,PIN_4,PIN_LOW);
}
