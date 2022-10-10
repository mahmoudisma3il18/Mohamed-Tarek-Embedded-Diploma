/*
 * Exercise 3.c
 *
 * Created: 10/7/2022 9:51:27 PM
 * Author : modyb
 */ 

#define  F_CPU 1000000


#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char tick = 0 ;

ISR(TIMER0_COMP_vect){
	tick++;
	if (tick == 2)
	{
		
		PORTC ^= (1<<PC0);
		tick = 0;
	}
	
}



void Timer0_CMP_Delay(unsigned char tick){
	
	SREG &= ~(1<<7);
	TCNT0 = 0x00;
	TIMSK |= (1<<OCIE0);
	TCCR0 = (1<<WGM01)  | (1<<CS02) | (1<<CS00) | (1<<FOC0);
	OCR0 = tick;
	SREG |= (1<<7);
	
}

int main(void)
{
    /* Replace with your application code */
	
	DDRC |= (1<<PC0);
	PORTC = 0x00;
	Timer0_CMP_Delay(250);
    while (1) 
    {
    }
}

