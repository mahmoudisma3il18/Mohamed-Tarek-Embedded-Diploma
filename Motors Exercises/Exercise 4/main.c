/*
 * Exercise 4.c
 *
 * Created: 10/10/2022 8:04:03 PM
 * Author : modyb
 */ 

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

void Timer1_PWM_Init(unsigned char ticks){
	TCNT1 = 0x0000;
	ICR1 = 2499;
	OCR1A = ticks;
	TCCR1A = (1<<COM1A1)  | (1<<WGM11);
	TCCR1B = (1<<WGM12) | (1<<WGM13)| (1<<CS11) | (1<<CS10);
}

int main(void)
{
    /* Replace with your application code */
	Timer1_PWM_Init()
    while (1) 
    {
    }
}

