/*
* Exercise 1.c
*
* Created: 10/7/2022 8:21:25 PM
* Author : modyb
*/

#define F_CPU 1000000

#include <avr/io.h>

void Timer0_Delay(void){
	
	
	TCNT0 = 0x00;
	TCCR0 |= (1<<CS02) | (1<<CS00) ;
	while(!(TIFR & (1<<TOV0)));
	TCCR0 = 0x00;
	TIFR |= (1<<TOV0);
	
	
}




int main(void)
{
	/* Replace with your application code */
	
	DDRC |= (1<<PC0);
	PORTC &= ~(1<<PC0);
	while (1)
	{
		PORTC ^= (1<<PC0);
		for(int i = 0 ; i<2;i++)
		Timer0_Delay();
	}
}

