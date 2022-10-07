/*
 * Challenge 1.c
 *
 * Created: 10/7/2022 5:28:08 PM
 * Author : modyb
 */ 

#define  F_CPU 1000000

#include <avr/io.h>
#include <avr/interrupt.h>

volatile int counter = 0;

ISR(INT2_vect){
	
	counter++;
	
}

void INT2_Init(void)
	{
		SREG &= ~(1<<7);
		DDRB &= ~(1<<2);
		GICR |= (1<<INT2);
		MCUCSR |= (1<<ISC2);
		SREG |= (1<<7);
		
	}

int main(void)
{
    /* Replace with your application code */
	
	DDRC |= 0x0F;
	PORTC = 0x00;
	
	INT2_Init();
	
    while (1) 
    {
		if(counter > 9)
		counter = 0;
		PORTC = 0x0F & counter;
    }
}

