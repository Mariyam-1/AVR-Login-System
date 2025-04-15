/*
 * Timer0_programe.c
 *
 * Created: 9/11/2024 1:22:39 PM
 *  Author: Mohamed
 */ 
#include "Timer0_Private.h"
#include "timer0_interface.h"
#include "../LIB/STD.h"
#include "../LIB/BitMath.h"
#include "Interrupt.h"
#include "Timer0_confg.h"
#include "DIO.h"
#include <stdlib.h>

u32 Timer0_NumOfOV=0;
u32 Timer0_NumOfCOMP=0;

u32 Timer2_NumOfOV=0;
u32 Timer2_NumOfCOMP=0;

void Timer0_vStart()
{
	Clr_Bit(TCCR0,CS00);
	Clr_Bit(TCCR0,CS01);
	Clr_Bit(TCCR0,CS02);
	
	#if (TIMER0_PRESCALER == No_clock)
	{
		Clr_Bit(TCCR0,CS00);
		Clr_Bit(TCCR0,CS01);
		Clr_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_1)
	{
		Set_Bit(TCCR0,CS00);
		Clr_Bit(TCCR0,CS01);
		Clr_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_8)
	{
		Clr_Bit(TCCR0,CS00);
		Set_Bit(TCCR0,CS01);
		Clr_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_64)
	{
		Set_Bit(TCCR0,CS00);
		Set_Bit(TCCR0,CS01);
		Clr_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_256)
	{
		Clr_Bit(TCCR0,CS00);
		Clr_Bit(TCCR0,CS01);
		Set_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_1024)
	{
		Set_Bit(TCCR0,CS00);
		Clr_Bit(TCCR0,CS01);
		Set_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_FallingEdge)
	{
		Clr_Bit(TCCR0,CS00);
		Set_Bit(TCCR0,CS01);
		Set_Bit(TCCR0,CS02);
	}
	#elif (TIMER0_PRESCALER == Prescaler_RisingEdge)
	{
		Set_Bit(TCCR0,CS00);
		Set_Bit(TCCR0,CS01);
		Set_Bit(TCCR0,CS02);
	}

#endif
}
void Timer0_vInit()
{
	#if (TIMER0_MODE == Normal_Mode)
	{
		Clr_Bit(TCCR0,WGM00);
		Clr_Bit(TCCR0,WGM01);
	}
	#elif (TIMER0_MODE == PWMAndPhaseCorrect_Mode)
	{
		Set_Bit(TCCR0,WGM00);
		Clr_Bit(TCCR0,WGM01);
	}
	#elif (TIMER0_MODE == CTC_Mode)
	{
		Clr_Bit(TCCR0,WGM00);
		Set_Bit(TCCR0,WGM01);
	}
	#elif (TIMER0_MODE == FastPWM_Mode)
	{
		Set_Bit(TCCR0,WGM00);
		Set_Bit(TCCR0,WGM01);
	}

#endif
}
void Timer0_vStop()
{
	Set_Bit(TCCR0,CS00);
	Set_Bit(TCCR0,CS01);
	Set_Bit(TCCR0,CS02);
}
void Timer0_vEnableInt(u8 INt)
{
	switch(INt)
	{
		case Timer0_OVF_INT:
		Set_Bit(TIMSK,TOIE0);
		sei();
		break;
		case Timer0_COMP_Match_INT:
		Set_Bit(TIMSK,OCIE0);
		sei();
		break;
	}
}
void Timer0_vDisableInt(u8 INt)
{
	switch(INt)
	{
		case Timer0_OVF_INT:
		Clr_Bit(TIMSK,TOIE0);
		break;
		case Timer0_COMP_Match_INT:
		Clr_Bit(TIMSK,OCIE0);
		break;
	}
}
void Timer0_vSetTime(u32 Time_ms)
{
	u32 prescaler_array[]={0,1,8,64,256,1024};

	u32 Tick_Time = prescaler_array[TIMER0_PRESCALER]/F_OSC;
		u32 Total_Number_of_ticks =(Time_ms * 1000 )/Tick_Time;
	#if (TIMER0_MODE == Normal_Mode)
	
	Timer0_NumOfOV=Total_Number_of_ticks/256;

	#elif (TIMER0_MODE ==  CTC_Mode)
	
 u16 limit = 0 ;
 for(u16 i = 256; i>0; i--)
 {
	 if(Total_Number_of_ticks%i==0)
	 {
		 limit = i;
		 break;
	 }
 }
 if(limit==0)
 limit = 256;
 OCR0=limit;
 Timer0_NumOfCOMP = Total_Number_of_ticks/limit;
 
	#endif
}
void Timer0_SetPhaseCorrect(f32 DutyCycle)
{
	DIO_voidSetPinDirection(PORTB_ID, PIN_3, PIN_OUTPUT); 
	
	#if (TIMER0_MODE == PWMAndPhaseCorrect_Mode)
	
	#if ( TIMER0_OC0_MODE  == TIMER_OC0_PWM_NON_INVERTING)
	Set_Bit(TCCR0,COM01);
	Clr_Bit(TCCR0, COM00);
	OCR0= abs(((256*DutyCycle)/100)-1);
	
	#elif (TIMER0_OC0_MODE  == TIMER_OC0_PWM_INVERTING)
	Set_Bit(TCCR0 ,COM01);
	Set_Bit(TCCR0, COM00);
	OCR0= 255-abs(((256*DutyCycle)/100)-1);
	#endif
	
	#endif
}
void Timer0_SetFastPWM(f32 DutyCycle)
{
	DIO_voidSetPinDirection(PORTB_ID, PIN_3, PIN_OUTPUT); //OC3
	
	#if (TIMER0_MODE == FastPWM_Mode)
	
	#if ( TIMER0_OC0_MODE  == TIMER_OC0_PWM_NON_INVERTING)
	Set_Bit(TCCR0,COM01);
	Clr_Bit(TCCR0, COM00);
	OCR0= abs(((256*DutyCycle)/100)-1);
	
	#elif (TIMER0_OC0_MODE  == TIMER_OC0_PWM_INVERTING)
	Set_Bit(TCCR0 ,COM01);
	Set_Bit(TCCR0, COM00);
	OCR0= 255-abs(((256*DutyCycle)/100)-1);
	#endif
	
	#endif
}



void Timer2_vInit()
{
	#if (TIMER2_MODE == Normal_Mode)
	{
		Clr_Bit(TCCR2,WGM20);
		Clr_Bit(TCCR2,WGM21);

	}
	#elif (TIMER0_MODE == PWMAndPhaseCorrect_Mode)
	{
		Set_Bit(TCCR2,TCCR2_WGM20);
		Clr_Bit(TCCR2,TCCR2_WGM21);
	}
	#elif (TIMER0_MODE == CTC_Mode)
	{
		Clr_Bit(TCCR2,WGM20);
		Set_Bit(TCCR2,WGM21);
	}
	#elif (TIMER0_MODE == FastPWM_Mode)
	{
		Set_Bit(TCCR2,WGM20);
		Set_Bit(TCCR2,WGM21);
	}
	#endif
}
void Timer2_vStart()
{
	Clr_Bit(TCCR2,CS20);
	Clr_Bit(TCCR2,CS21);
	Clr_Bit(TCCR2,CS22);

	
	#if (TIMER0_PRESCALER == Prescaler_8)
	{
		Clr_Bit(TCCR2,CS20);
		Set_Bit(TCCR2,CS21);
		Clr_Bit(TCCR2,CS22);
	}
	#elif (TIMER0_PRESCALER == Prescaler_64)
	{
		Clr_Bit(TCCR2,CS20);
		Clr_Bit(TCCR2,CS21);
		Set_Bit(TCCR2,CS22);
	}
	#elif (TIMER0_PRESCALER == Prescaler_256)
	{
		Clr_Bit(TCCR2,CS20);
		Clr_Bit(TCCR2,CS21);
		Set_Bit(TCCR2,CS22);
	}
	#elif (TIMER0_PRESCALER == Prescaler_1024)
	{
		Set_Bit(TCCR2,CS20);
		Clr_Bit(TCCR2,CS21);
		Set_Bit(TCCR2,CS22);
	}


	#endif
}
void Timer2_vEnableInt(u8 INt) 
{
	switch(INt) {
		case Timer2_OVF_INT:
		Set_Bit(TIMSK,TOIE2);
		sei();
		break;
		case Timer2_COMP_Match_INT:
		Set_Bit(TIMSK, OCIE2);
		sei();
		break;
	}
}

void Timer2_vSetTime(u32 Time_ms)
 {
	u32 prescaler_array[] = {0,1,8,64,256,1024};
	u32 Tick_Time = prescaler_array[TIMER2_PRESCALER] / F_OSC;
	u32 Total_Number_of_ticks = (Time_ms * 1000) / Tick_Time;
	#if (TIMER2_MODE == Normal_Mode)
	Timer2_NumOfOV = Total_Number_of_ticks / 256;
	#elif (TIMER2_MODE == CTC_Mode)
	u16 limit = 0 ;
	for(u16 i = 256; i>0; i--)
	{
		if(Total_Number_of_ticks%i==0)
		{
			limit = i;
			break;
		}
	}
	if(limit==0)
	limit = 256;
	OCR0=limit;
	Timer2_NumOfCOMP = Total_Number_of_ticks/limit;
	#endif
}
void Timer2_vStop()
{
	Clr_Bit(TCCR2,CS20);
	Clr_Bit(TCCR2,CS21);
	Clr_Bit(TCCR2,CS22);
}