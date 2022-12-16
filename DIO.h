/*
 * DIO.h
 *
 * Created: 12/7/2022 6:9:10 PM
 *  Author: Ahmed Abdallah
 */ 

#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
#include "../../Utilities/STD_TYPES.h"
#include "../../Utilities/BIT_MATH.h"

// ports definitions
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

// pins definitions
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

// direction definitions
#define DIO_INPUT   0
#define DIO_OUTPUT 0xFF
// value definitions
#define DIO_LOW   0
#define DIO_HIGH  1


void DIO_SetPinValue(uint8_t  PortNo,uint8_t  PinNo,uint8_t  Value);
void DIO_SetPortValue(uint8_t  PortNo,uint8_t  value);
void DIO_SetPinDirection(uint8_t  PortNo,uint8_t  PinValue,uint8_t  Direction);
void DIO_SetPortDirection(uint8_t  PortNo ,uint8_t  Direction);
uint8_t DIO_GetPortValue(uint8_t  PortNo);
uint8_t  DIO_GetPinValue(uint8_t  PortNo,uint8_t  PinNo);

void DIO_TogglePinValue(uint8_t  PortNo,uint8_t  PinNo);
void DIO_read(uint8_t PortNo, uint8_t PinNo, uint8_t* value);
#endif /* DIO_H_ */
