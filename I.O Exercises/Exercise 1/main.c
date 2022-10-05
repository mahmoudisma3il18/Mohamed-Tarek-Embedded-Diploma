/*
 * Exercise 1.c
 *
 * Created: 10/5/2022 2:24:46 AM
 * Author : modyb
 */ 

#include <avr/io.h>

#define F_CPU  8000000


int main(void)
{
	
	DDRA &= ~(1<<3);
	DDRC |= (1<<5);
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		if(PINA & (1<<3))
		PORTC = (1<<5);
		else
		PORTC = 0x00;
		
    }
}

