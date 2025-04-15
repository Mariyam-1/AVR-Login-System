/*
 * timer0_interface.h
 *
 * Created: 9/11/2024 1:21:52 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "../LIB/STD.h"

#define	Timer0_OVF_INT			0
#define	Timer0_COMP_Match_INT	1

#define	Timer2_OVF_INT			0
#define	Timer2_COMP_Match_INT	1 


void Timer0_vInit();
void Timer0_vStart();
void Timer0_vStop();
void Timer0_vEnableInt(u8 INt);
void Timer0_vDisableInt(u8 INt);
void Timer0_vSetTime(u32 Time_ms);
void Timer0_SetPhaseCorrect(f32 DutyCycle);
void Timer0_SetFastPWM(f32 DutyCycle);

void Timer2_vInit();
void Timer2_vStart();
void Timer2_vEnableInt(u8 INt);
void Timer2_vSetTime(u32 Time_ms);
#endif /* TIMER0_INTERFACE_H_ */