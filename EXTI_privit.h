/*
 * EXTI.privit.h
 *
 * Created on: 12/13/2022 2:26:33 PM
 *      Author: Ahmed Abdallah
 */

#ifndef EXTI_EXTI_PRIVIT_H_
#define EXTI_EXTI_PRIVIT_H_

#define MCUCR       *((volatile uint8_t*)(0x55))
#define MCUCSR      *((volatile uint8_t*)(0x54))
#define GICR        *((volatile uint8_t*)(0x5B))
#define GIFR        *((volatile uint8_t*)(0x5A))



// external    interrupt   enable
#define   enable 							100
#define   disable 							1000
// logical signal
#define falling_edge					10
#define rasing_edge						20
#define any_change						30
#define low_level 						40






#endif /* EXTI_EXTI_PRIVIT_H_ */
