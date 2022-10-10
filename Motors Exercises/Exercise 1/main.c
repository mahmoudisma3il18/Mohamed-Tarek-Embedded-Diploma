/*
 * Exercise 1.c
 *
 * Created: 10/10/2022 7:03:17 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	DDRA &= ~(1<<PA0) & ~(1<<PA1) & ~(1<<PA2);
	DDRC |= (1<<PC0) | (1<<PC1);
	 
    while (1) 
    {
		if (PINA & (1<<PA0))
		{
			DDRC |= (1<<PC0);
			DDRC &= ~(1<<PC1);
		}
		else if (PINA & (1<<PA1))
		{
			DDRC |= (1<<PC1);
			DDRC &= ~(1<<PC0);
		}
		else if(PINA & (1<<PA2))
		{
			DDRC &= ~(1<<PC0);
			DDRC &= ~(1<<PC1);
		}
    }
}

