/*
 * Exercise 2.c
 *
 * Created: 10/5/2022 3:05:34 PM
 * Author : modyb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>




int main(void)
{
    /* Replace with your application code */
	
	DDRD |= (1<<6) ;
	PORTD = 0x00 ;
    while (1) 
    {
		
		PORTD ^= (1<<6);
		_delay_ms(1000);
		
    }
}

