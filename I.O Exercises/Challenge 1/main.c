/*
 * Challenge 1.c
 *
 * Created: 10/5/2022 3:34:56 PM
 * Author : Mahmoud Ismail
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	DDRC = 0xFF;
	PORTC = 0x00;
	
    while (1) 
    {
		for(int i = 0 ; i < 8 ;i++ ){
			PORTC = (1<<i);
			_delay_ms(500);
			PORTC = 0x00;
		}
    }
}

