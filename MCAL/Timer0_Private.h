/*
 * Timer0_Private.h
 *
 * Created: 9/11/2024 1:22:11 PM
 *  Author: Mohamed
 */ 

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCNT0	 (*((volatile u8*)0x52))	/* counting register*/

#define TCCR0	 (*((volatile u8*)0x53))	/*Control Register*/

#define TIFR	(*((volatile u8 *)0X58))	/*Flag Register*/

#define TIMSK	 (*((volatile u8*)0x59))	/*use it for interrupts*/

#define OCR0	 (*((volatile u8*)0x5C))	/* Register used for compare match*/

#define TCCR2	(*((volatile u8*)0x45))		/*Timer/Counter2 Control Register A*/

#define TCNT2	(*((volatile u8*)0x44))		/*Timer/Counter2 Control Register*/

#define OCR2	(*((volatile u8*)0x43))		/* Output compare register */

/*TCCRO Bits*/

#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

/*TIFR	 Bits*/

#define TOV0	0
#define OCF0	1
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5
#define TOV2	6
#define OCF2	7

/*TIMSK Bits*/

#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCI1B	3
#define OCI1A	4
#define TCICE1	5
#define TOIE2	6
#define OCIE2	7

/*Timer Modes*/

#define Normal_Mode					0
#define PWMAndPhaseCorrect_Mode  	1
#define CTC_Mode					2
#define FastPWM_Mode				3

/* Prescaler options*/

#define No_clock					0
#define Prescaler_1					1
#define Prescaler_8					2
#define Prescaler_64				3
#define Prescaler_256				4
#define Prescaler_1024				5
#define Prescaler_FallingEdge		6
#define Prescaler_RisingEdge		7

/*OCR0_Modes*/

#define   TIMER0_OC0_DISCONNECTED        0
#define   TIMER0_OC0_TOG                 1
#define   TIMER0_OC0_CLEAR               2
#define   TIMER0_OC0_SET                 3
#define	  TIMER_OC0_PWM_NON_INVERTING    4
#define	  TIMER_OC0_PWM_INVERTING	 	 5

/*Timer_2 registers*/


#define CS20		0                               /* Prescaler bit 0 */
#define CS21		1                               /* Prescaler bit 1 */
#define CS22		2                               /* Prescaler bit 2 */
#define WGM21		3                               /* Waveform generation mode 1 */
#define COM20		4                               /* Compare Output Mode, Phase Correct, fast and non-PWM Mod0 */
#define COM21		5                               /* Compare Output Mode, Phase Correct, fast and non-PWM Mod1 */
#define WGM20		6                               /* Waveform generation mode 0 */
#define FOC2		7                               /*Force Output Compare, must be set to 0 at PWM mode*/


#endif /* TIMER0_PRIVATE_H_ */