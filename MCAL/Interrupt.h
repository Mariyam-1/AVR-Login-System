/*
 * Interrupt.h
 *
 * Created: 9/4/2024 9:57:02 PM
 *  Author: Mohamed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "DIO.h"

#define zero 0
 /*Interrupt numbers*/
 
#define INT_0   0
#define INT_1   1
#define INT_2   2

/*Define Registers */

#define SEREG	*((volatile u8 *)0X5F)	/*GIE register*/

#define SEREG_I		7

#define GICR	*((volatile u8 *)0X5B)	/*PIE register*/

#define GICR_INT0	6
#define GICR_INT1	7
#define GICR_INT2	5

#define GIFR	*((volatile u8 *)0X5A)	/*PIF register*/

#define GICF_INT0	6
#define GICF_INT1	7
#define GICF_INT2	5

#define MCUCR	*((volatile u8 *)0X55)	/*sense control for INT_0 and INT_1 register*/

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define MCUCSR	*((volatile u8 *)0X54)	/*sense control for INT_2 register*/

#define ISC2 6


/*Define Sense control states*/

#define Low_Level		 0  
#define Logical_Change	 1
#define Falling_Edge	 2
#define Rising_Edge		 3

#define sei()	__asm__ __volatile__ ("sei")		/*set GIE*/	

/*ISR*/
#define _VECTOR(N)		__vector_ ## N         /* ## -> concatinate     if N=1  ->  __vector_1 */

/* VECT_NO */
#define INT0_vect		    _VECTOR(1)
#define INT1_vect		    _VECTOR(2)
#define INT2_vect		    _VECTOR(3)
#define TIMER2_COMP_vect	_VECTOR(4)
#define TIMER2_OVF_vect		_VECTOR(5)
#define TIMER0_COMP_vect    _VECTOR(10)
#define TIMER0_OVF_vect	    _VECTOR(11)

#define  ISR(VECT_NO)		\
void VECT_NO(void) __attribute__((signal));\
void VECT_NO(void)

/*Functions*/

void INT_voidIntialization(u8 INT_NUM,u8 sense_control);
void INT_voidCallBack(void (*call_Back)(void),u8 INT_NUM);
void INT_voidClearINT(u8 INT_NUM);
	 

#endif /* INTERRUPT_H_ */