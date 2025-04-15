/*
 * LCD.c
 *
 * Created: 8/28/2024 4:01:35 AM
 * Author : Batman
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../HAL/LCD.h"
#include "../HAL/LCD_TYPES.h"
#include "../HAL/KEYBAD.h"
#include "../HAL/LED.h"
#include "../MCAL/Interrupt.h"
#include "../MCAL/Timer0_confg.h"
#include "../MCAL/timer0_interface.h"
#include "../MCAL/Timer0_Private.h"
#include "../HAL/Buzzer.h"
#include "../HAL/Motor.h"

#define RED_LED			PIN_5
#define YELLOW_LED		PIN_6
#define GREEN_LED		PIN_7
#define INTERRUPT_LED	PIN_3
extern u32 Timer0_NumOfOV;
extern u32 Timer0_NumOfCOMP;

extern u32 Timer2_NumOfOV;
extern u32 Timer2_NumOfCOMP;

u8 mainPass[5] , tmpPass[5];
u8 str[10];
u8 PassSetFlag = 0;
u32 counter = 0;
u8  remaining = 0;
u8 i = 0;



/*****Functions_Declarations*****/
void Error();
void vDoorOperation();
void vGetPass();
u8 u8CheckPassword();
void vStartMain();
void vDoorOrNew();
void vNewPass();
void vThreeTrials();
/********************************/


int main(void)
{
	
	/**** ISR initialization ****/
    INT_voidIntialization(INT_0,Rising_Edge);
    sei();
	/**** LCD initialization ****/
    LCD_VoidIntialization();
    _delay_ms(30);
	/**** KPD initialization ****/
    KEYPAD_voidInit();
    _delay_ms(30);
	/****Using Timer 0 as Fast PWM****/
    Timer0_vInit();
    Timer0_vStart();
    /*********************************/
	/****Using Timer 2 as CTC MODE****/
    Timer2_vInit();
    Timer2_vSetTime(1000);
    Timer2_vStart();
    Timer2_vEnableInt(Timer2_COMP_Match_INT);
    /*********************************/
	/******BUZZER & MOTOR & LEDS******/
    BUZZER_VoidINT();
    Motor_init();
	LED_VoidIntializeLed(PORTD_ID,INTERRUPT_LED,PIN_OUTPUT);
	LED_VoidIntializeLed(PORTD_ID,RED_LED,PIN_OUTPUT);
	LED_VoidIntializeLed(PORTD_ID,YELLOW_LED,PIN_OUTPUT);
	LED_VoidIntializeLed(PORTD_ID,GREEN_LED,PIN_OUTPUT);
	LCD_VoidRemove_Cursor();
	/*********************************/
	
	
    vStartMain();
	
    while (1)
    {
        vDoorOrNew();
    }
}

void vStartMain()
{
    LCD_VoidSendString("****WELCOME****");
    _delay_ms(1000);
    LCD_VoidClear_Screen();
	
    vNewPass();
}

/* 
function to store the first pass 
	   entered by the user
*/
void vNewPass()
{

	LCD_VoidSendString("Plz Enter Pass:");
	LCD_VoidMove_Cursor(1,0);
	u8 KEYPAD_READ = KEYPAD_u8ReadButton();

	for (i = 0; i < 5; i++)
	{
		
		while(KEYPAD_READ == 0) // don't store until user presses any key
		{
			KEYPAD_READ = KEYPAD_u8ReadButton();
		}
		
		mainPass[i] = KEYPAD_READ; // store Keypad input into pass array
		KEYPAD_READ = 0;
		LCD_VoidData('*');
	}

	while(KEYPAD_READ != 'P') // We are using ON Button as Enter Button
	{
		KEYPAD_READ = KEYPAD_u8ReadButton();
	}
	PassSetFlag=1;	// flag to indicate that the user entered the first pass (For Interrupt)
	
	LCD_VoidClear_Screen();

	LCD_VoidSendString("Re-Enter Pass");
	LCD_VoidMove_Cursor(1,0);
	LCD_VoidSendString("Pass:");
	vGetPass();
	vThreeTrials();

}

/* 
function to store the confirmation pass 
	   Entered by the user
	   Same as NewPass function
*/

void vGetPass()
{
	u8 KEYPAD_READ = KEYPAD_u8ReadButton();

	for (u8 i = 0; i < 5; i++)
	{
		while(KEYPAD_READ == 0)
		KEYPAD_READ = KEYPAD_u8ReadButton();
		
		tmpPass[i] = KEYPAD_READ;
		KEYPAD_READ = 0;
		LCD_VoidData('*');
	}
	while(KEYPAD_READ != 'P')
	{
		KEYPAD_READ = KEYPAD_u8ReadButton();
	}

}

/* 
function to Handle Error caused by entered pass	
	   for 3 times and Handle it by				
			starting error fun					
*/

void vThreeTrials()
{
	u8 nWrong= 0;
	while (u8CheckPassword() != 0)
	{
		nWrong++;// flag to indicate when to enter the Error function
		if(nWrong==3)
		{
			Error();
			break;
		}
		LCD_VoidClear_Screen();
		LCD_VoidSendString("Try Again: ");
		LCD_VoidMove_Cursor(1,0);
		LCD_VoidSendString("Pass:");
		vGetPass();
	}
}
/* 
	function to compare 2 passwords
	  if they are equal return 0
			else return 1
*/
u8 u8CheckPassword()
{
	for (u8 i = 0; i < 5; i++)
	{
		if (tmpPass[i] != mainPass[i])
		return 1;
	}
	return 0;
}
/* 
Error Handling function to turn on a buzzer
	and set a counter for 10 seconds
	  which no inputs are accepted.
*/
void Error()
{
	do{
		counter = 0;
		remaining = 10;
		LCD_VoidClear_Screen();
		BUZZER_VoidTurnON();
		LCD_VoidSendString("Remaining Time:");
		
		while(remaining != 0){
			LCD_VoidMove_Cursor(1,0);
			int_to_str(remaining,str);
			LCD_VoidSendString(str);
			LCD_VoidData('\0');
			
		}
		
		BUZZER_VoidTurnOFF();
		
		LCD_VoidClear_Screen();
		LCD_VoidSendString("Please re-Enter");
		LCD_VoidMove_Cursor(1, 0);
		LCD_VoidSendString("Pass:");
		vGetPass();
	}while(u8CheckPassword == 1);// after 10 seconds if the entered pass is wrong do the function again
	
	 return;

}

/* 
	Main 2 operation function
	if pressed '+' then go to door operation fun
	if pressed '-' then set a new password 
*/

void vDoorOrNew()
{
    u8 KEYPAD_READ = 0;
    LCD_VoidClear_Screen();
    while (KEYPAD_READ == 0)
    {
        LCD_VoidMove_Cursor(0,0);
        LCD_VoidSendString("+ : Open Door");
        LCD_VoidMove_Cursor(1,0);
        LCD_VoidSendString("- : New  Pass");

        KEYPAD_READ = KEYPAD_u8ReadButton();
        if (KEYPAD_READ == '+')
        {  LCD_VoidClear_Screen();
            LCD_VoidSendString("Plz Enter Pass:");
            LCD_VoidMove_Cursor(1,0);
            vGetPass();
            vThreeTrials();
            vDoorOperation();
        }
        else if (KEYPAD_READ == '-')
        {
			LCD_VoidClear_Screen();
            vNewPass();
        }
        else
            KEYPAD_READ = 0;

    }
}
/* 
function to turn on the motor for
	15 seconds Clockwise then
	3  seconds hold then
	15 seconds counter clockwise
*/

void vDoorOperation() 
{

    counter = 0;
    remaining=15; //using remaining counter decreasing every second
    LCD_VoidClear_Screen();
	//Turn on the motor CW for 15 seconds
    while(remaining != 0)
    {
		LED_VoidTurnOn(PORTD_ID,RED_LED,PIN_HIGH);//RED High
		
        LCD_VoidMove_Cursor(0,0);
        LCD_VoidSendString("Door is ");
        LCD_VoidMove_Cursor(1,0);
        LCD_VoidSendString("Unlocking...");
		
        int_to_str(remaining, str);//convert remaining integer into string
        LCD_VoidSendString(str);   // and display it
        LCD_VoidData('\0');
		
        Motor_rotateClockwise(FULL_SPEED);
	}
	//Hold the motor for 3 seconds
	LED_VoidTurnOff(PORTD_ID,RED_LED,PIN_LOW);//RED LOW
    Motor_stop();
    LCD_VoidClear_Screen();
    
    counter = 0;
    remaining = 3;

    while(remaining != 0)
    {   
		LED_VoidTurnOn(PORTD_ID,YELLOW_LED,PIN_HIGH);//YELLOW HIGH
		LCD_VoidMove_Cursor(0,0);
        LCD_VoidSendString("Hold...");
    }
    LED_VoidTurnOff(PORTD_ID,YELLOW_LED,PIN_LOW);//YELLOW LOW
	
    counter = 0;
    remaining = 15;
    LCD_VoidClear_Screen();
	//Turn on the motor CCW for 15 seconds
    while(remaining != 0)
    {
		LED_VoidTurnOn(PORTD_ID,GREEN_LED,PIN_HIGH);//GREEN ON
        LCD_VoidMove_Cursor(0,0);
        LCD_VoidSendString("Door is ");
        LCD_VoidMove_Cursor(1,0);
        LCD_VoidSendString("locking...");

        int_to_str(remaining, str);
        LCD_VoidSendString(str);
        LCD_VoidData('\0');

        Motor_rotateCounterClockwise(HALF_SPEED);
    }
	LED_VoidTurnOff(PORTD_ID,GREEN_LED,PIN_LOW);//GREEN LOW

    Motor_stop();
    LCD_VoidClear_Screen();
	
}

/* 
		*ISR FUNCTIONS*
	- one for Timer 2
	- the other for interrupt
*/
ISR(TIMER2_COMP_vect) 
{
    counter++;
    if (counter == Timer2_NumOfCOMP) {
        counter = 0;
        remaining--; // decreasing counter
    }
}

ISR(INT0_vect)
{
		
	if (PassSetFlag != 0)
	{
		
		LED_VoidTurnOn(PORTD_ID,INTERRUPT_LED,PIN_HIGH);// turn on the interrupt led

		LED_VoidTurnOff(PORTD_ID,PIN_5,PIN_LOW);/*Turn Off*/
		LED_VoidTurnOff(PORTD_ID,PIN_6,PIN_LOW);/*Turn Off*/
		LED_VoidTurnOff(PORTD_ID,PIN_7,PIN_LOW);/*Turn Off*/
		Motor_stop();							/*Turn Off*/
		BUZZER_VoidTurnOFF();					/*Turn Off*/
		LCD_VoidClear_Screen();
		
		LCD_VoidSendString(" !!!Warning!!! ");
		LCD_VoidMove_Cursor(1,0);
		LCD_VoidSendString("Need Pass:");
		
		vGetPass();
		vThreeTrials();
		LCD_VoidClear_Screen();
		
		LED_VoidTurnOff(PORTD_ID,INTERRUPT_LED,PIN_LOW);// turn off the interrupt led
	}



}