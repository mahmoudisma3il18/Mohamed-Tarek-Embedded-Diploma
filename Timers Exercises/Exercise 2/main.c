/*
 * Exercise 2.c
 *
 * Created: 10/7/2022 8:39:05 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char counter = 0;

ISR(TIMER0_OVF_vect){
	
	counter++;
	if (counter == 2)
	{
		PORTC ^= (1<<PC0);
		counter = 0;
	}
	
}

void Timer0_Init(void){
	
	SREG &= ~(1<<7);
	TCNT0 = 0x00;
	TIMSK |= (1<<TOIE0);
	TCCR0 =(1<<CS02) | (1<<CS00) | (1<<FOC0);
	SREG |=(1<<7);
	
	

}


int main(void)
{
    /* Replace with your application code */
	
	DDRC |= (1<<PC0);
	PORTC &= ~(1<<PC0);
	Timer0_Init();
    while (1) 
    {
    }
}

