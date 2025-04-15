/*
 * Interrupt.c
 *
 * Created: 9/4/2024 9:56:44 PM
 *  Author: Mohamed
 */ 
#include "Interrupt.h"

void (*Call_Back[3])()={zero};		/*pointer to a function that will be used at call back function*/
	
void INT_voidIntialization(u8 INT_NUM,u8 sense_control)
{
	switch(INT_NUM)
	{
		case INT_0:
		Set_Bit(GICR,GICR_INT0);
		switch(sense_control)
		{
			case Low_Level:
			
			Clr_Bit(MCUCR,ISC00);
			Clr_Bit(MCUCR,ISC01);
			break;	
			case Logical_Change:
			Set_Bit(MCUCR,ISC00);
			Clr_Bit(MCUCR,ISC01);
			break;
			case Falling_Edge:
			Clr_Bit(MCUCR,ISC00);
			Set_Bit(MCUCR,ISC01);
			break;
			case Rising_Edge:
			Set_Bit(MCUCR,ISC00);
			Set_Bit(MCUCR,ISC01);
			break;
		}
		break;
		
		case INT_1:
		Set_Bit(GICR,GICR_INT1);
		switch(sense_control)
		{
			case Low_Level:
			
			Clr_Bit(MCUCR,ISC10);
			Clr_Bit(MCUCR,ISC11);
			break;
			case Logical_Change:
			Set_Bit(MCUCR,ISC10);
			Clr_Bit(MCUCR,ISC11);
			break;
			case Falling_Edge:
			Clr_Bit(MCUCR,ISC10);
			Set_Bit(MCUCR,ISC11);
			break;
			case Rising_Edge:
			Set_Bit(MCUCR,ISC10);
			Set_Bit(MCUCR,ISC11);
			break;
		}
		break;
		case INT_2:
		Set_Bit(GICR,GICR_INT2);
		switch(sense_control)
		{
			case Falling_Edge:
			Clr_Bit(MCUCSR,ISC2);
			break;
			case Rising_Edge:
			Set_Bit(MCUCSR,ISC2);
			break;
		}
		break;
	}
}
void INT_voidClearINT(u8 INT_NUM)
{
	switch(INT_NUM)
	{
		case INT_0:
		Clr_Bit(GICR,GICR_INT0);
		break;
		case INT_1:
		Clr_Bit(GICR,GICR_INT1);
		break;
		case INT_2:
		Clr_Bit(GICR,GICR_INT2);
		break;
	}
}
void INT_voidCallBack(void (*call_Back)(void),u8 INT_NUM)
{
	switch(INT_NUM)
	{
		case INT_0:
		Call_Back[0]=call_Back;
		break;
		case INT_1:
		Call_Back[1]=call_Back;
		break;
		case INT_2:
		Call_Back[2]=call_Back;
		break;
	}
}
/*ISR*/

/*void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	Call_Back[0]();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	Call_Back[1]();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	Call_Back[2]();
}*/

