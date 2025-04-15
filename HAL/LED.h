/*
 * LED.h
 *
 * Created: 8/28/2024 1:21:27 PM
 *  Author: Mohamed
 */ 


#ifndef LED_H_
#define LED_H_
#include "../MCAL/DIO.h"
#include "../LIB/STD.h"

void LED_VoidIntializeLed(u8 port,u8 pin, u8 direction);
void LED_VoidTurnOn(u8 port,u8 pin, u8 value);
void LED_VoidTurnOff(u8 port,u8 pin,u8 value);
void LED_VoidToggle(u8 port,u8 pin);




#endif /* LED_H_ */