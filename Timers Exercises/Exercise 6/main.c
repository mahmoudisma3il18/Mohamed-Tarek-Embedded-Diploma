/*
 * Exercise 6.c
 *
 * Created: 10/10/2022 1:53:30 PM
 * Author : modyb
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

void Timer0_PWM_Init(unsigned char ticks){
	DDRB |= (1<<PB3);
	TCNT0 = 0x00;
	OCR0 = ticks;
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	
	
}
int main(void)
{
    /* Replace with your application code */
	Timer0_PWM_Init(64);
	_delay_ms(5000);
	Timer0_PWM_Init(128);
	_delay_ms(5000);
	Timer0_PWM_Init(192);
	_delay_ms(5000);
	
    while (1) 
    {
    }
}

