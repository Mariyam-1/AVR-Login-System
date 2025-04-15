/*
 * BitMath.h
 *
 * Created: 8/27/2024 11:39:28 PM
 *  Author: Mohamed
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_


#define Set_Bit(reg,pin) reg |=(1<<pin)

#define Clr_Bit(reg,pin) reg &=(~(1<<pin))

#define Get_Bit(reg,pin)  (reg>>pin) &1

#define Toggle_Bit(reg,pin)  reg ^=(1 << pin)

#endif /* BITMATH_H_ */