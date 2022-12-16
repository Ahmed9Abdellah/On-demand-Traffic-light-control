/*
 * BIT_MATH_H 
 *
 * Created on: 12/8/2022 4:40:35 PM
 *      Author: Ahmed Abdallah
 */

#ifndef BIT_MATH_H
#define BIT_MATH_H 

#define SET_BIT(var, bit_no)      ((var) |=  (1 << (bit_no)))

#define CLR_BIT(var, bit_no)      ((var) &= ~(1 << (bit_no)))

#define TOG_BIT(var, bit_no)      ((var) ^=  (1 << (bit_no)))

#define GET_BIT(var,bit_no)       ((var&(1<<bit_no))>>bit_no)
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )	
#endif	/* BIT_MATH_H_ */		
     
