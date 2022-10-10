/*
 * Exercise.c
 *
 * Created: 10/10/2022 3:46:00 PM
 * Author : modyb
 */ 
#define  F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

void Watchdog_Timer_Init(void){
	WDTCR |= (1<<WDE) | (1<<WDP0) | (1<<WDP1) | (1<<WDP2);
}

int main(void)
{
    /* Replace with your application code */
	Watchdog_Timer_Init();
	DDRD |= (1<<PD6);
	PORTD |= (1<<PD6);
	_delay_ms(1000);
	PORTD &= ~(1<<PD6);
	
    while (1) 
    {
		
    }
}

