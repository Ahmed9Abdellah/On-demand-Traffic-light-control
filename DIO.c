/*
 * DIO.c
 *
 * Created: 12/7/2022 6:10:26 PM
 *  Author: Ahmed Abdallah
 */ 

#include"DIO.h"


void DIO_SetPinValue(uint8_t PortNo,uint8_t PinNo , uint8_t Value)
{
	if(Value==DIO_HIGH){
switch(PortNo){
case DIO_PORTA:
	SET_BIT(PORTA,PinNo);
break;
case DIO_PORTB:
	SET_BIT(PORTB,PinNo);
	break;
case DIO_PORTC:
	SET_BIT(PORTC,PinNo);
	break;
case DIO_PORTD:
	SET_BIT(PORTD,PinNo);
	break;
}
}
	else if (Value==DIO_LOW){
		switch(PortNo){
		case DIO_PORTA:
			CLR_BIT(PORTA,PinNo);
		break;
		case DIO_PORTB:
			CLR_BIT(PORTB,PinNo);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC,PinNo);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD,PinNo);
			break;
		}
	}
}
void DIO_SetPinDirection(uint8_t PortNo,uint8_t PinNo , uint8_t Direction){

if(Direction == DIO_OUTPUT){
	switch(PortNo){
	case DIO_PORTA:
		SET_BIT(DDRA,PinNo);
	break;
	case DIO_PORTB:
		SET_BIT(DDRB,PinNo);
		break;
	case DIO_PORTC:
		SET_BIT(DDRC,PinNo);
		break;
	case DIO_PORTD:
		SET_BIT(DDRD,PinNo);
		break;
	}
}
else if(Direction == DIO_INPUT){
	switch(PortNo){
	case DIO_PORTA:
		CLR_BIT(DDRA,PinNo);
	break;
	case DIO_PORTB:
		CLR_BIT(DDRB,PinNo);
		break;
	case DIO_PORTC:
		CLR_BIT(DDRC,PinNo);
		break;
	case DIO_PORTD:
		CLR_BIT(DDRD,PinNo);
		break;
	}
}
}
uint8_t DIO_GetPinValue(uint8_t PortNo,uint8_t PinNo){
	uint8_t pin_value=0;
	switch (PortNo){
	case DIO_PORTA:
	if(	BIT_IS_SET(PINA,PinNo) )
	{
		pin_value=1;
	}
	else
	{
		pin_value=0;
	}
	break;
		case DIO_PORTB:
		if(	BIT_IS_SET(PINB,PinNo) )
		{
			pin_value=1;
		}
			else
			{
				pin_value=0;
			}
		break;
		case DIO_PORTC:
		if(	BIT_IS_SET(PINC,PinNo) )
		{
			pin_value=1;
		}
			else
			{
				pin_value=0;
			}
		break;
	case DIO_PORTD:
	if(	BIT_IS_SET(PIND,PinNo) )
	{
		pin_value=1;
	}
		else
		{
			pin_value=0;
		}
		break;

	}
	return pin_value;
}
void DIO_SetPortValue(uint8_t PortNo,uint8_t Value){


switch (PortNo){
case DIO_PORTA:
	PORTA=Value;
	break;
case DIO_PORTB :
	PORTB=Value;
	break;
case DIO_PORTC:
	PORTC=Value;
	break;
case DIO_PORTD :
	PORTD=Value;
	break;
}
}
void DIO_SetPortDirection(uint8_t PortNo, uint8_t Direction){

	switch (PortNo){
	case DIO_PORTA:
	DDRA=Direction;
	break;
	case DIO_PORTB:
	DDRB=Direction;
     break;
	case DIO_PORTC:
		DDRC=Direction;
	break;
	case DIO_PORTD:
		DDRD=Direction;
	break;

	}
}

uint8_t DIO_GetPortValue (uint8_t PortNo){
uint8_t port_value=0;
switch  (PortNo){
case DIO_PORTA:
port_value=	PORTA ;
break;
case DIO_PORTB:
port_value=	PORTB ;
break;
case DIO_PORTC:
port_value=	PORTC ;
break;
case DIO_PORTD:
port_value=	PORTD ;
break;
}
return port_value;
}
void DIO_TogglePinValue(uint8_t PortNo, uint8_t PinNo)
{
switch(PortNo)
{
case DIO_PORTA :
	TOG_BIT(PORTA,PinNo);
	break;
case DIO_PORTB :
	TOG_BIT(PORTB,PinNo);
	break;
case DIO_PORTC :
	TOG_BIT(PORTC,PinNo);
	break;
case DIO_PORTD :
	TOG_BIT(PORTD,PinNo);
	break;


}
}
void DIO_read(uint8_t PortNo, uint8_t PinNo, uint8_t* value)
{
switch(PortNo)
{
	case DIO_PORTA : 
	*value =(PORTA &(1<<PinNo))>>PinNo;
break;
	case DIO_PORTB : 
	*value =(PORTB &(1<<PinNo))>>PinNo;
	break;
		case DIO_PORTC :
		*value =(PORTC &(1<<PinNo))>>PinNo;
		break;
			case DIO_PORTD :
			*value =(PORTD &(1<<PinNo))>>PinNo;
			break;
			default:
			//error handling 
			break;
			
}

}
