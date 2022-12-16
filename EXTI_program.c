/*
 * EXTI.program.c
 *
 * Created on: 12/13/2022 2:27:11 PM
 *      Author: Ahmed Abdallah
 */
#include"../../Utilities/STD_TYPES.h"
#include"../../Utilities/BIT_MATH.h"
#include"../../MCAL/DIO_DRIVER/DIO.h"
#include"../../ECUAL/BUTTON_DRIVER/button.h"
#include"EXTI_interface.h"
#include"EXTI_privit.h"
#include"EXTI_config.h"



//global pointers
//pointer to function
void(*INT0_callback_function)(void);
void(*INT1_callback_function)(void);
void(*INT2_callback_function)(void);

// ISR OF INT0
 void __vector_1(void)  __attribute__((signal));
 void __vector_1(void)
 {
	 INT0_callback_function();
 }

//ISR OF INT1
 void __vector_2(void)  __attribute__((signal));
 void __vector_2(void)
 {
	 INT1_callback_function();
 }

 //ISR OF INT2
 void __vector_3(void)  __attribute__((signal));
 void __vector_3(void)
 {
	 INT2_callback_function();
 }


void EXIT_INT(void)
{
#if INT0==enable
//set interrupt pin as input at active pullup
DIO_SetPinDirection(DIO_PORTD, DIO_PIN2,DIO_INPUT);
DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
	BUTTON_FLAG=1;
// enable INT0 from GICR register register bit no.6
SET_BIT(GICR,6);

/* sense control of interrupt chose at MCUCR register
 INT0 is controlled by bit isc00 (0) and isc01(1)
 */
#if SIG_CRL_INT0==rasing_edge
SET_BIT(MCUCR,0);
SET_BIT(MCUCR,1);
#elif SIG_CRL_INT0==falling_edge
CLR_BIT(MCUCR,0);
SET_BIT(MCUCR,1);
#elif SIG_CRL_INT0==low_level
CLR_BIT(MCUCR,0);
CLR_BIT(MCUCR,1);
#elif SIG_CRL_INT0==any_change
SET_BIT(MCUCR,0);
CLR_BIT(MCUCR,1);
#endif
#endif

#if  INT1==enable
//set interrupt pin as input at active pullup
DIO_SetPinDirection(DIO_PORTD, DIO_PIN3,DIO_INPUT);
DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
// enable INT1 from GICR register register bit no.7
SET_BIT(GICR,7);

/* sense control of interrupt chose at MCUCR register
 INT1 is controlled by bit isc10 (2) and isc11(3)
 */
#if SIG_CRL_INT1==rasing_edge
SET_BIT(MCUCR,2);
SET_BIT(MCUCR,3);
#elif SIG_CRL_INT1==falling_edge
CLR_BIT(MCUCR,2);
SET_BIT(MCUCR,3);
#elif SIG_CRL_INT1==low_level
CLR_BIT(MCUCR,2);
CLR_BIT(MCUCR,3);
#elif SIG_CRL_INT1==any_change
SET_BIT(MCUCR,2);
CLR_BIT(MCUCR,3);
#endif
#endif

#if INT2==enable
//set interrupt pin as input at active pullup
DIO_SetPinDirection(DIO_PORTB, DIO_PIN2,DIO_INPUT);
DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
// enable INT2 from GICR register register bit no.5
SET_BIT(GICR,5);

/* sense control of interrupt chose at MCUCSR register
 INT2 is controlled by bit isc2 bit no.6
 */
#if SIG_CRL_INT2==rasing_edge
SET_BIT(MCUCSR,6);
#elif SIG_CRL_INT2==falling_edge
CLR_BIT(MCUCSR,6);
#endif
#endif
}
void INT0_set_callback(void(*fptr)(void))
{
	INT0_callback_function=fptr;
}

void INT1_set_callback(void(*fptr)(void))
{
	INT1_callback_function=fptr;
}

void INT2_set_callback(void(*fptr)(void))
{
	INT2_callback_function=fptr;
}

