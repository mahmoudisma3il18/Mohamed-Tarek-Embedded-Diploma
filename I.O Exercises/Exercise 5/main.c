/*
* Exercise 5.c
*
* Created: 10/5/2022 5:16:26 PM
* Author : modyb
*/

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	/* Replace with your application code */
	
	DDRD &= ~(1<<PD4);
	DDRC |= 0x0F;
	
	int counter = 0,flag = 1;
	
	while (1)
	{
		if(PIND & (1<<PD4)){
			_delay_ms(5);
			if (PIND & (1<<PD4))
			{
				if(flag == 1) {
					PORTC = counter & 0x0F;
					counter++;
					if(counter > 9)
					counter = 0;
					flag = 0;
				}
			}
			
			else
			flag = 1;
			
			
		}
	}
}

