
/*
 * Motor.c
 *
 * Created: 17/09/2024 4:28:37 AM
 *  Author: Mariyam Mousa
 */ 
#include "Motor.h"
#include "../MCAL/timer0_interface.h"
#include "../LIB/STD.h"

// Initialize motor control pins
void Motor_init(void)
{
	
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN1, PIN_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN2, PIN_OUTPUT);
	
	// Ensure the motor is stopped initially
	Motor_stop();
}
// Rotate motor clockwise with given speed

void Motor_rotateClockwise(f32 speed) 
{
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_HIGH);
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_LOW);
	
    Timer0_SetFastPWM(speed); 
}

void Motor_rotateCounterClockwise(f32 speed)
{
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_LOW);
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_HIGH);
	
	// Set speed using PWM
	Timer0_SetFastPWM(speed); 
}
// Stop the motor
void Motor_stop(void) 
{
	
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN1, PIN_LOW);
	DIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN2, PIN_LOW);
}


