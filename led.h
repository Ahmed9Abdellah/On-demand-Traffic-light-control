/*
 * led.h
 *
 * Created: 12/7/2022 6:23:40 PM
 *  Author: Ahmed Abdallah
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO_DRIVER/DIO.h"

// Car port and pins
#define LED_CAR_PORT DIO_PORTA
#define GreenLedCar DIO_PIN0
#define YellowLedCar DIO_PIN1
#define RedLedCar DIO_PIN2

// Pedestrian port and pins
#define LED_PED_PORT DIO_PORTB
#define GreenLedPed DIO_PIN0
#define YellowLedPed DIO_PIN1
#define  RedLedPed DIO_PIN2
uint8_t RED_FLAG ;
uint8_t GREEN_FLAG ;
uint8_t Yellow_FLAG;
void LED_init(uint8_t LedPort,uint8_t LedPin,uint8_t Direction);
void LED_on(uint8_t LedPort,uint8_t LedPin);
void LED_off(uint8_t LedPort,uint8_t LedPin);
void LED_toggle(uint8_t LedPort,uint8_t LedPin);
void GREEN_CAR_OFF(uint8_t ledPort,uint8_t ledPin);
void GREEN_CAR_ON(uint8_t ledPort,uint8_t ledPin);
void RED_CAR_OFF(uint8_t ledPort,uint8_t ledPin);
void RED_CAR_ON(uint8_t ledPort,uint8_t ledPin);
void YellowCarBlink (void);
void YellowPedBlink (void);
void BlinkAll(void);
#endif /* LED_H_ */