/*
 * Motor.h
 *
 * Created: 17/09/2024 4:29:08 AM
 *  Author: Mariyam Mousa
 */ 
#ifndef MOTOR_H_
#define MOTOR_H_

#include "../MCAL/DIO.h"
#include "../MCAL/Timer0_confg.h"
#include "../MCAL/Timer0_interface.h"
#include "../MCAL/Timer0_Private.h"

// Motor control definitions
#define MOTOR_PORT PORTB_ID
#define MOTOR_PIN1 PIN_6
#define MOTOR_PIN2 PIN_7
#define Motor_enable PIN_3


// Motor speed definitions
#define FULL_SPEED 256
#define HALF_SPEED 128
#define STOP 0

// Motor control functions
void Motor_init(void);
void Motor_rotateClockwise(f32 speed);
void Motor_rotateCounterClockwise(f32 speed);
void Motor_stop(void);


#endif /* MOTOR_H_ */
