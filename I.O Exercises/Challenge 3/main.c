/*
* Challenge 3.c
*
* Created: 10/5/2022 5:48:49 PM
* Author : modyb
*/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	
	DDRA &= ~(1<<PA0);
	DDRA &= ~(1<<PA1);
	
	DDRD = 0x0F;
	
	int counter = 0;
	
	while (1)
	{
		if (PINA & (1<<PA0))
		{
			_delay_ms(30);
			if (PINA & (1<<PA0))
			{
				counter++;
				if(counter > 9)
				counter = 9;
				PORTD = counter & 0x0F;
				while(PINA & (1<<PA0));
			}
		}
		
		if (PINA & (1<<PA1))
		{
			_delay_ms(30);
			if (PINA & (1<<PA1))
			{
				counter--;
				if(counter < 0)
				counter = 0;
				PORTD = counter & 0x0F;
				while(PINA & (1<<PA1));
			}
		}
	}
}

