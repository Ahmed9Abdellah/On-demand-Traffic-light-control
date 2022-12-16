/*
 * button.h
 *
 * Created: 12/7/2022 6:31:18 PM
 *  Author: Ahmed Abdallah
 */  


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO_DRIVER/dio.h"

//Button port and pin
#define BUTTON_1_PORT DIO_PORTD
#define BUTTON_1_PIN  DIO_PIN2
#define  DEBOUNCE_MILLISEC 20
uint8_t BUTTON_FLAG;

//initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin,uint8_t Direction);

// button read
void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t * value);


#endif /* BUTTON_H_ */