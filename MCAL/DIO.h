/*
 * DIO.h
 *
 * Created: 9/1/2024 5:41:52 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../LIB/STD.h"
#include "../LIB/BitMath.h"

/*PORTA Registers*/
#define PORTA	*((volatile u8 *)0X3B)
#define DDRA	*((volatile u8 *)0X3A)
#define PINA	*((volatile u8 *)0X39)
/*PORTB Registers*/

#define PORTB	*((volatile u8 *)0X38)
#define DDRB	*((volatile u8 *)0X37)
#define PINB	*((volatile u8 *)0X36)
/*PORTC Registers*/

#define PORTC	 *((volatile u8 *)0X35)
#define DDRC	 *((volatile u8 *)0X34)
#define PINC	 *((volatile u8 *)0X33)
/*PORTD Registers*/

#define PORTD	*((volatile u8 *)0X32)
#define DDRD	*((volatile u8 *)0X31)
#define PIND	*((volatile u8 *)0X30)

/*DEFINITIONS*/

/*Define 4 PORTS */
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

/*Define 8 PINS */

#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7

/*Define PIN is input OR output */

#define PIN_INPUT 0
#define PIN_OUTPUT 1

/*Define PinValue is LOW OR HIGH */

#define PIN_LOW  0
#define PIN_HIGH 1

#define PORT_INPUT 0
#define PORT_OUTPUT 0xFF

#define PORT_LOW 0
#define PORT_HIGH 0xFF

/*Functions*/

void DIO_voidSetPinDirection(u8 port,u8 pin, u8 direction);

void DIO_voidSetPinValue(u8 port,u8 pin, u8 value);

u8 DIO_u8GetPinValue(u8 port,u8 pin);

void DIO_voidSetPortDirection(u8 port,u8 direction);

void DIO_voidSetPortValue(u8 port,u8 value);

void DIO_VoidTogglePin(u8 port,u8 pin);

u8 DIO_u8GetPortValue(u8 port,u8 pin);




#endif /* DIO_H_ */