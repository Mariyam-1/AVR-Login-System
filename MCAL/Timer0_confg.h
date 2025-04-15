/*
 * Timer0_confg.h
 *
 * Created: 9/11/2024 1:21:26 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER0_CONFG_H_
#define TIMER0_CONFG_H_
/*
 * choose from:
 *   TIMER0_PRESCALER_1
 *   TIMER0_PRESCALER_8
 *   TIMER0_PRESCALER_64
 *   TIMER0_PRESCALER_256
 *   TIMER0_PRESCALER_1024
 *   TIMER0_PRESCALER_EXTCLK_FALLEDGE
 *   TIMER0_PRESCALER_EXTCLK_RAISEDGE
 */
#define TIMER0_PRESCALER     Prescaler_64

#define TIMER2_PRESCALER	Prescaler_64

/*
 *   choose from :
 *   TIMER0_NORMAL_MODE
 *   TIMER0_CTC_MODE
 *   TIMER0_PHASECORRECT_MODE
 *   TIMER0_FASTPWM_MODE
 *
 */
#define TIMER0_MODE  FastPWM_Mode

#define TIMER2_MODE	CTC_Mode
/*
 * choose from :
 *  Non PWM:
 *   TIMER0_OC0_DISCONNECTED
 *   TIMER0_OC0_TOG
 *   TIMER0_OC0_CLEAR
 *   TIMER0_OC0_SET
 *   TIMER_OC0_PWM_NON_INVERTING
 *   TIMER_OC0_PWM_INVERTING
 */
#define TIMER0_OC0_MODE  TIMER_OC0_PWM_NON_INVERTING



/*
 * select F_OSC
 */
#define F_OSC	8


#endif /* TIMER0_CONFG_H_ */