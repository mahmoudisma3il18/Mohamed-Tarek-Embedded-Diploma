/*
* gpio.c
*
* Created: 10/16/2022 2:01:44 PM
*  Author: Mahmoud Ismail
*/

#include "gpio.h"


void GPIO_setupPinDirection(uint8_t port_num,uint8_t pin_num , GPIO_PinDirectionType direction)
{
	
	switch(port_num){
		
		case PORTA_ID :
		if (direction == PIN_INPUT)
		CLEAR_BIT(DDRA,pin_num);
		else if (direction == PIN_OUTPUT)
		SET_BIT(DDRA,pin_num);
		break;
		
		case PORTB_ID :
		if (direction == PIN_INPUT)
		CLEAR_BIT(DDRB,pin_num);
		else if (direction == PIN_OUTPUT)
		SET_BIT(DDRB,pin_num);
		break;
		
		case PORTC_ID :
		if (direction == PIN_INPUT)
		CLEAR_BIT(DDRC,pin_num);
		else if (direction == PIN_OUTPUT)
		SET_BIT(DDRC,pin_num);
		break;
		
		case PORTD_ID :
		if (direction == PIN_INPUT)
		CLEAR_BIT(DDRD,pin_num);
		else if (direction == PIN_OUTPUT)
		SET_BIT(DDRD,pin_num);
		break;
		
	}
}

void GPIO_writePin(uint8_t port_num,uint8_t pin_num,uint8_t value)
{
	
	switch(port_num) 
	{
		
		case PORTA_ID :
		if (value == LOGIC_HIGH)
		{
			SET_BIT(PORTA,pin_num);
		} 
		else
		{
			CLEAR_BIT(PORTA,pin_num);
		}
		break;
		
		
		case PORTB_ID :
		if (value == LOGIC_HIGH)
		{
			SET_BIT(PORTB,pin_num);
		} 
		else
		{
			CLEAR_BIT(PORTB,pin_num);
		}
		break;
		
		
		case PORTC_ID :
		if (value == LOGIC_HIGH)
		{
			SET_BIT(PORTC,pin_num);
		} 
		else
		{
			CLEAR_BIT(PORTC,pin_num);
		}
		break;
		
		
		case PORTD_ID :
		if (value == LOGIC_HIGH)
		{
			SET_BIT(PORTC,pin_num);
		} 
		else
		{
			CLEAR_BIT(PORTC,pin_num);
		}
		break;

	}
}


uint8_t GPIO_readPin(uint8_t port_num,uint8_t pin_num)
{
	uint8_t value = LOGIC_LOW;
	
	switch(port_num)
	{
		case PORTA_ID :
		if (BIT_IS_SET(PINA,pin_num))
		{
			value = LOGIC_HIGH;
		} 
		else
		{
			value = LOGIC_LOW;
		}
		break;
		
		case PORTB_ID :
		if (BIT_IS_SET(PINB,pin_num))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
		
		case PORTC_ID :
		if (BIT_IS_SET(PINC,pin_num))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
		
		case PORTD_ID :
		if (BIT_IS_SET(PIND,pin_num))
		{
			value = LOGIC_HIGH;
		}
		else
		{
			value = LOGIC_LOW;
		}
		break;
	
	}
	
	return value;
	
}

void GPIO_setupPortDirection(uint8_t port_number,GPIO_PortDirectionType direction)
{
	
	switch(port_number)
	{
		
		case PORTA_ID : 
		DDRA = direction;
		break;
		
		case PORTB_ID :
		DDRB = direction;
		break;
		
		case PORTC_ID :
		DDRC = direction;
		break;
		
		case PORTD_ID :
		DDRD = direction;
		break;
		
	}
	
}


void GPIO_writePort(uint8_t port_num,uint8_t value)
{
	
	switch(port_num)
	{
		
		case PORTA_ID:
		PORTA = value;
		break;
		
		case PORTB_ID:
		PORTB = value;
		break;
		
		case PORTC_ID:
		PORTC = value;
		break;
		
		case PORTD_ID:
		PORTD = value;
		break;
		
	}
}

uint8_t GPIO_readPort(uint8_t port_num)
{
	
	uint8_t value = LOGIC_LOW;
	
	switch(port_num)
	{
		
		case PORTA_ID : 
		value = (PINA & 0xFF);
		break;
		
		case PORTB_ID :
		value = (PINB & 0xFF);
		break;
		
		case PORTC_ID :
		value = (PINC & 0xFF);
		break;
		
		case PORTD_ID :
		value = (PIND & 0xFF);
		break;
	}
	
	return value;
}