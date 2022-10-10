/*
 * Challenge 2.c
 *
 * Created: 10/9/2022 9:07:58 PM
 * Author : modyb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char twofiveCounter = 0;
volatile unsigned char fiveCounter = 0;

ISR(TIMER0_COMP_vect){
	
	PORTC ^= (1<<PC0); // Toggle pin for 10 khz
	twofiveCounter++;
	fiveCounter++;
	
	if (fiveCounter == 2)
	{
		PORTC ^= (1<<PC1); // Toggle 5 khz pin
		fiveCounter = 0 ; 
	}
	
	if (twofiveCounter == 4)
	{
		PORTC ^= (1<<PC2); // Toggle 2.5 khz pin
		twofiveCounter = 0;
	}
	
	
	
	
}



void Timer0_CMP_Init(void){
	
	SREG |= (1<<7); // Enable Global Interrupt
	TCNT0 = 0x00;
	TIMSK |= (1<<OCIE0); // Enable Interrupt
	OCR0 = 0x32; // 50 Ticks;
	DDRC |= (1<<0) | (1<<1) | (1<<2);
	TCCR0 |= (1<<FOC0) | (1<<WGM01) | (1<<CS01);
}


int main(void)
{
    /* Replace with your application code */
	Timer0_CMP_Init();
    while (1) 
    {
    }
}

