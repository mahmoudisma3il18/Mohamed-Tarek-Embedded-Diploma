/*
 * Exercise 1.c
 *
 * Created: 10/6/2022 7:27:49 PM
 * Author : modyb
 */ 
#define F_CPU 1000000

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
	
	PORTC ^= (1<<PC0);
	
}


int main(void)
{
    /* Replace with your application code */
	DDRC |=(1<<PC0);
	PORTC |= (1<<PC0);
	
	SREG &= ~(1<<7);
	DDRD &= ~(1<<PD2);
	
	GICR |= (1<<INT0);
	
	MCUCR |= (1<<ISC11) | (1<<ISC10);
	
	SREG |= (1<<7);
    while (1) 
    {
    }
}

