/*
 * Challenge 4.c
 *
 * Created: 10/10/2022 2:30:37 PM
 * Author : modyb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char tick = 0;

ISR(TIMER1_COMPA_vect){
	tick++;
	if(tick == 3)
	PORTC |= (1<<PC0);
	else if (tick == 4)
	{
		PORTC &= ~(1<<PC0);
		tick = 0;
	}
	
}


void Timer1_CMP_Init(void){
	SREG |= (1<<7);
	DDRC |= (1<<PC0);
	TCNT1 = 0x00;
	OCR1A = 125;
	TIMSK |= (1<<OCIE1A);
	TCCR1A = (1<<FOC1A) ;
	TCCR1B = (1<<WGM12) | (1<<CS11);
	
	
}


int main(void)
{
    /* Replace with your application code */
	Timer1_CMP_Init();
    while (1) 
    {
    }
}

