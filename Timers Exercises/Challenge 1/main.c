/*
* Challenge 1.c
*
* Created: 10/7/2022 9:16:59 PM
* Author : modyb
*/

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char interruptcounter = 0; //123
volatile unsigned char sevensegmentcounter = 0;


ISR(TIMER0_OVF_vect){
	interruptcounter++;
	if (interruptcounter == 123)
	{
		sevensegmentcounter++;
		if(sevensegmentcounter > 9)
		sevensegmentcounter = 0;
		PORTC = sevensegmentcounter & 0x0F;
		
		
		interruptcounter = 0;
	}
	
}

void Timer0_Init(void){
	
	SREG&= ~(1<<7);
	TCNT0 = 0x00;
	TIMSK |= (1<<TOIE0);
	TCCR0 = (1<<FOC0) | (1<<CS02);
	SREG |= (1<<7);
	
	
}

int main(void)
{
	/* Replace with your application code */
	DDRC |= 0x0F;
	PORTC = sevensegmentcounter & 0x0F;
	Timer0_Init();
	while (1)
	{
	}
}

