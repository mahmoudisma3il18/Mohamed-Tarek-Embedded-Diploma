/*
 * Exercise 3.c
 *
 * Created: 10/5/2022 3:11:13 PM
 * Author : modyb
 */ 

#define  F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRB &= ~(1<<0);
	DDRB &= !(1<<1);
	DDRC |=(1<<0);
	DDRC |=(1<<1);
	
    while (1) 
    {
		
		if(PINB & (1<<0)  &&  PINB & (1<<1))
		PORTC = 0x03;
		
		else if(PINB & (1<<0))
		PORTC =(1<<0);
		
		else if(PINB & (1<<1))
		PORTC = (1<<1);
		
		else
		PORTC = 0x00;
		
		
    }
}

