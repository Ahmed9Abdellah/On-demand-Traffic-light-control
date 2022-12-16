/*
 * EXTI.interface.h
 *
 * Created on: 12/13/2022 2:25:55 PM
 *      Author: Ahmed Abdallah
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

void EXIT_INT(void);
void INT0_set_callback(void(*fptr)(void));
void INT1_set_callback(void(*fptr)(void));
void INT2_set_callback(void(*fptr)(void));


#endif /* EXTI_EXTI_INTERFACE_H_ */
