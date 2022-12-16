/*
 * button.c
 *
 * Created: 12/7/2022 6:30:11 PM
 *  Author: Ahmed Abdallah
 */  
#include "button.h"
//initialize
void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t Direction){
	DIO_SetPinDirection(ButtonPort,ButtonPin,DIO_INPUT);

}

// button read
void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin,uint8_t * value){
	DIO_read(ButtonPort,ButtonPin,value);
	
}