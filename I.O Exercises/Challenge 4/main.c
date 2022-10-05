/*
 * Challenge 4.c
 *
 * Created: 10/5/2022 6:26:52 PM
 * Author : Mahmoud Ismail
 */ 

#define F_CPU 1000000


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRC &= ~(1<<PC0);
	DDRB |= (1<<PB0);
    while (1) 
    {
		if(PINC & (1<<PC0))
		  PORTB |= (1<<PB0);
		else
		  PORTB &= ~(1<<PB0);  
    }
}

