/*
 * Exercise 4.c
 *
 * Created: 10/5/2022 3:22:51 PM
 * Author : Mahmoud Ismail
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	int flag = 1;
	
	DDRB &= ~(1<<0);
	PORTB |= (1<<0);
	DDRC |= (1<<0);
	
	PORTC = 0x00;
	
	
    while (1) 
    {
		if ((!(PINB & (1<<0))) )
		{
			_delay_ms(30); // De bouncing
			if ((!(PINB & (1<<0))) )
			{
				if(flag == 1){
				PORTC ^= (1<<0);
				flag = 0;
				}
			}
		}
		else
		flag = 1;
    }
}

