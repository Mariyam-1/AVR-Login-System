/*
 * KPD.c
 *
 * Created: 9/1/2024 1:36:52 AM
 *  Author: ELSOS
 */ 
#include "KEYBAD.h"
u8 KPD_arr[KPD_ROWS][KPD_COLUMNS] = { '7','8','9','/' ,
									  '4','5','6','*' ,
									  '1','2','3','-' ,
									  'P','0','=','+' };


void KEYPAD_voidInit(){
	
	DIO_voidSetPortDirection (PORTC_ID , 0x0F);
}


u8 KEYPAD_u8ReadButton(){

	u8 state;
	for (u32 row = 0 ; row<KPD_ROWS;row++){
		
		DIO_voidSetPinValue (PORTC_ID , row , PIN_HIGH);
		
		for (u32 col=0 ; col<KPD_COLUMNS ; col++){
			if (Get_Bit(PINC,(4+col))==1){
				_delay_ms(30);
				state = Get_Bit(PINC,(4+col));
				while (state==1){
					state=Get_Bit(PINC,(4+col));
					
				}
				if (KPD_arr[row][col]=='P'){
					return 'P';
				}
				else return KPD_arr[row][col];
				
				
				
			}
		}
		DIO_voidSetPinValue (PORTC_ID , (row) , PIN_LOW);
		
	}
	return 0;

}
