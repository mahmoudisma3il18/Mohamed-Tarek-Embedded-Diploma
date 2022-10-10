/*
 * Challenge 3.c
 *
 * Created: 10/10/2022 2:25:01 PM
 * Author : modyb
 */ 

#define  F_CPU 8000000

#include <avr/io.h>

void Timer0_PWM_Init(void){
	
	DDRB |= (1<<PB3);
	TCNT0 = 0X00;
	OCR0 = 128;
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS01);
}


int main(void)
{
    /* Replace with your application code */
	Timer0_PWM_Init();
    while (1) 
    {
    }
}

