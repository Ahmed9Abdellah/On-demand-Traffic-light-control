/*
 * led.c
 *
 * Created: 12/7/2022 6:24:10 PM
 *  Author: Ahmed Abdallah
 */ 
#define F_CPU 1000000
#include<util/delay.h>
#include "led.h"
extern uint8_t RED_FLAG;
extern uint8_t GREEN_FLAG;
extern uint8_t  Yellow_FLAG;
uint8_t i;
void LED_init(uint8_t ledPort,uint8_t ledPin,uint8_t direction){
	DIO_SetPinDirection(ledPort,ledPin,DIO_OUTPUT);
}

void RED_CAR_ON(uint8_t ledPort,uint8_t ledPin){
	DIO_SetPinValue(ledPort,ledPin,DIO_HIGH);
	RED_FLAG=1;
}
void RED_CAR_OFF(uint8_t ledPort,uint8_t ledPin){
	DIO_SetPinValue(ledPort,ledPin,DIO_LOW);
RED_FLAG=0;
}
void GREEN_CAR_ON(uint8_t ledPort,uint8_t ledPin){
	DIO_SetPinValue(ledPort,ledPin,DIO_HIGH);
GREEN_FLAG=1;
}
void GREEN_CAR_OFF(uint8_t ledPort,uint8_t ledPin){
	DIO_SetPinValue(ledPort,ledPin,DIO_LOW);
GREEN_FLAG=0;
}
void LED_on(uint8_t ledPort,uint8_t ledPin){
	DIO_SetPinValue(ledPort,ledPin,DIO_HIGH);
}
void LED_off(uint8_t ledPort,uint8_t ledPin){
	DIO_SetPinValue(ledPort,ledPin,DIO_LOW);
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin){
	DIO_TogglePinValue(ledPort,ledPin);
}

void YellowCarBlink (void)
{
	 Yellow_FLAG=1;
	LED_on(LED_CAR_PORT,YellowLedCar);
	_delay_ms(1000);
		LED_off(LED_CAR_PORT,YellowLedCar);
		_delay_ms(1000);
		LED_on(LED_CAR_PORT,YellowLedCar);
		_delay_ms(1000);
		LED_off(LED_CAR_PORT,YellowLedCar);
		_delay_ms(1000);
		LED_on(LED_CAR_PORT,YellowLedCar);
		_delay_ms(1000);
		LED_off(LED_CAR_PORT,YellowLedCar);
 Yellow_FLAG=0;
}
void YellowPedBlink (void)
{
	
	LED_on(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_off(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_on(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_off(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_on(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_off(LED_PED_PORT,YellowLedPed);
}
void BlinkAll(void)
{
	LED_on(LED_CAR_PORT,YellowLedCar);
	LED_on(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_off(LED_CAR_PORT,YellowLedCar);
	LED_off(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_on(LED_CAR_PORT,YellowLedCar);
	LED_on(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_off(LED_CAR_PORT,YellowLedCar);
	LED_off(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_on(LED_CAR_PORT,YellowLedCar);
	LED_on(LED_PED_PORT,YellowLedPed);
	_delay_ms(1000);
	LED_off(LED_CAR_PORT,YellowLedCar);
	LED_off(LED_PED_PORT,YellowLedPed);
}