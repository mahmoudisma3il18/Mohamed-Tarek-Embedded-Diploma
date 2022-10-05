/*
 * Challenge 2.c
 *
 * Created: 10/5/2022 4:18:02 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRA &= ~(1<<PA3);
	DDRA &= ~(1<<PA4);
	DDRD = 0xFF;
	
    while (1) 
    {
		if((PINA & (1<<PA3)) && (PINA & (1<<PA4))){
		   PORTD = 0x55;
		   _delay_ms(500);
		}
		 else if(PINA & (1<<PA3)) {
			 PORTD = 0x55;
			 _delay_ms(500);
		 } 
		 else if(PINA & (1<<PA4)){
			  PORTD = 0xAA;
			  _delay_ms(500);
		 }
		 else
		    PORTD = 0x00;
		 
			
		
    }
}

