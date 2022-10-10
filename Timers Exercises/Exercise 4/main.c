/*
 * Exercise 4.c
 *
 * Created: 10/7/2022 10:18:23 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_COMP_vect){
	
}


void Timer0_CMP_Mode(){
	
	TCNT0 = 0x00;
	OCR0 = 250;
	DDRB |= (1<<PB3);
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
	
}


int main(void)
{
    /* Replace with your application code */
	Timer0_CMP_Mode();
    while (1) 
    {
    }
}

