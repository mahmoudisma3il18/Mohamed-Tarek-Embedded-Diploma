/*
 * Exercise 2.c
 *
 * Created: 10/10/2022 7:11:09 PM
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
    DDRA &= ~(1<<PA0) & ~(1<<PA1) & ~(1<<PA2);
    DDRC |= (1<<PC0) | (1<<PC1);
	Timer0_PWM_Init(255);
    
    while (1)
    {
	    if (PINA & (1<<PA0))
	    {
		    DDRC |= (1<<PC0);
		    DDRC &= ~(1<<PC1);
	    }
	    else if (PINA & (1<<PA1))
	    {
		    DDRC |= (1<<PC1);
		    DDRC &= ~(1<<PC0);
	    }
	    else if(PINA & (1<<PA2))
	    {
		    DDRC &= ~(1<<PC0);
		    DDRC &= ~(1<<PC1);
	    }
    }

}

