/*
 * KPD.h
 *
 * Created: 9/1/2024 1:36:39 AM
 *  Author: ELSOS
 */ 
#ifndef KPD_H_
#define KPD_H_
#include "LCD.h"

#define KPD_ROWS	4
#define KPD_COLUMNS	4

void KEYPAD_voidInit();
u8 KEYPAD_u8ReadButton();

#endif /* KPD_H_ */