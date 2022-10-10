/*
 * Exercise 3.c
 *
 * Created: 10/10/2022 7:34:42 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRA &= ~(1<<PA2);
	DDRC |= (1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3);
	
	unsigned char steps[] = {12,6,3,9};	
	unsigned char steps_counter = 0;
	
    while (1) 
    {
		if(PINA & (1<<PA2)){
			_delay_ms(30);
			if (PINA & (1<<PA2))
			{
				PORTC = 0x0F & steps[steps_counter];
				steps_counter++;
				
				if(steps_counter == 4)
				steps_counter = 0;
			}
		}while(PINA & (1<<PA2));
		
    }
}

