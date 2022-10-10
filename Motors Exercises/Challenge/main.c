/*
 * Challenge.c
 *
 * Created: 10/10/2022 7:53:39 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	
	DDRC = 0x0F;
	unsigned char steps_counter = 0;
	unsigned char steps[] = {12,4,6,2,3,1,9,8}; 
    while (1) 
    {
		PORTC = 0x0F & steps[steps_counter];
		_delay_ms(500);
		steps_counter++;
		if(steps_counter ==8)
		steps_counter = 0;
    }
}

