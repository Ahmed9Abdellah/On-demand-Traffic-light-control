/*
 * app.c
 *
 * Created: 12/7/2022 5:42:03 PM
 *  Author: Ahmed Abdallah
 */ 
#define F_CPU 1000000
#include<util/delay.h>
#include "../ECUAL/LED_DRIVER/led.h"
#include "../ECUAL/BUTTON_DRIVER/button.h"
#include "../MCAL/EXTI_Interrupt/EXTI_interface.h"
#include "../MCAL/GLOBAL_Interrupt/GIE_interface.h"
#include "App.h"


	


void action_green(void)
{
	LED_off(LED_CAR_PORT,GreenLedCar);
	BlinkAll();
	LED_on(LED_CAR_PORT,RedLedCar);
	LED_on(LED_PED_PORT,GreenLedPed);
	_delay_ms(5000);
	LED_off(LED_CAR_PORT,RedLedCar);
	LED_off(LED_PED_PORT,GreenLedPed);
}
void action_yellow(void)
{
	LED_off(LED_CAR_PORT,YellowLedCar);
	BlinkAll();
	LED_on(LED_CAR_PORT,RedLedCar);
	LED_on(LED_PED_PORT,GreenLedPed);
	_delay_ms(5000);
	LED_off(LED_CAR_PORT,RedLedCar);
	LED_off(LED_PED_PORT,GreenLedPed);

}
void select(void)
{
	if(RED_FLAG==1)
	{
		
	}
	if(GREEN_FLAG==1)
	{
		action_green();
	}
	if (Yellow_FLAG==1)
	{
		action_yellow();
	}
	
}
void APP_init(void)
{
	
	//Car LED initialization
	LED_init(LED_CAR_PORT,GreenLedCar,DIO_OUTPUT);
	LED_init(LED_CAR_PORT,YellowLedCar,DIO_OUTPUT);
	LED_init(LED_CAR_PORT,RedLedCar,DIO_OUTPUT);
	
	//Pedestrian LED initialization
	LED_init(LED_PED_PORT,GreenLedPed,DIO_OUTPUT);
	LED_init(LED_PED_PORT,YellowLedPed,DIO_OUTPUT);
	LED_init(LED_PED_PORT,RedLedPed,DIO_OUTPUT);
	
	
}
void ISR_CALLBACK(void)
{

	INT0_set_callback(&select);
}	


void APP_start(void)
{

while(1)
{
	
	RED_CAR_ON(LED_CAR_PORT,RedLedCar);
	LED_on(LED_PED_PORT,GreenLedPed);
	_delay_ms(5000);
	RED_CAR_OFF(LED_CAR_PORT,RedLedCar);
	LED_off(LED_PED_PORT,GreenLedPed);
   YellowCarBlink();
	GREEN_CAR_ON(LED_CAR_PORT,GreenLedCar);
	_delay_ms(5000);
  GREEN_CAR_OFF(LED_CAR_PORT,GreenLedCar);
  YellowCarBlink();
}



}
