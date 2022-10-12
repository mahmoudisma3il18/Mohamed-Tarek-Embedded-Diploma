/*
 * Project 2.c
 *
 * Created: 10/11/2022 12:21:54 AM
 * Author : modyb
 */ 

#define  F_CPU 1000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned int g_ticks; // Every tick equals 1 second

ISR(TIMER1_COMPA_vect) {
	g_ticks++;
}


ISR(INT0_vect){
	g_ticks = 0; // Reset counter
}

ISR(INT1_vect){
	TCCR1B &= ~(1<<CS10) & ~(1<<CS11); // Stop Counter or clock
}

ISR(INT2_vect){
	TCCR1B |= (1<<CS11) | (1<<CS10); // Resume clock
}

void INT0_Init(void){
	DDRD &= ~(1<<PD2); // Configure External Interrupt INT0
	PORTD |= (1<<PD2); //Enable Internal Pull-up resistor
	MCUCR |= (ISC01); // Falling edge
	MCUCR &= ~(1<<ISC00); // Falling Edge
	GICR |= (1<<INT0); // Enable module Interrupt
	
}

void INT1_Init(void){
	DDRD &= ~(1<<PD3); // Configure External Interrupt INT1
	MCUCR |= (1<<ISC11) | (1<<ISC10); //Rising Edge
	GICR |= (1<<INT1); // Enable module Interrupt
	
	
}


void INT2_Init(void){
	DDRB &= ~(1<<PB2); // Configure External Interrupt INT2
	PORTB |= (1<<PB2);// Configure internal pull-up resistor
	MCUCSR &= ~(1<<ISC2); //Falling edge
	GICR |= (1<<INT2);// Enable module Interrupt
}

void Timer1_CTC_Init(void){
	TCNT1 = 0x0000; // Counter is zero now
	OCR1A = 15625; // We need 15625 ticks to get interrupt every 1 second
	TCCR1A = (1<<FOC1A);// Non - PWM Mode
	TIMSK |= (1<<OCIE1A) ; // Enable Channel A interrupt
	TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10) ;
	//Enable CTC Mode
	//Frequency / 64 
	
}



int main(void)
{
    /* Replace with your application code */
	SREG |= (1<<7); //Enable Global Interrupts
	DDRC |= 0x0F; // Configure for 7447 decoder 4-pins to the first 4-pins in PORTC
	DDRA |= 0x3F; // Configure first 6-pins in PORTA as the enable/disable pins for the six 7-segments
	
	PORTA |= 0x3F; // Enable all seven segments
	PORTC &= 0xF0; // Zero the counter
	
	Timer1_CTC_Init();
	INT0_Init();
	INT1_Init();
	INT2_Init();
	
	unsigned int seconds_0 ,seconds_1 ,minutes_0 , minutes_1 , hours_0 , hours_1 , seconds , minutes , hours ; 
	
	
	
    while (1) 
    {
		
		hours = g_ticks / 3600; // Get hours in from HH:MM:SS
		minutes = (g_ticks - (3600 * hours)) / 60; // Get minutes in form HH:MM:SS
		seconds = g_ticks - (hours*3600) - (minutes*60); // Get seconds in from of HH:MM:SS
		
		seconds_0 = seconds % 10; 
		seconds_1 = seconds / 10;
		
		minutes_0 = minutes % 10;
		minutes_1 = minutes / 10;
		
		hours_0 = hours % 10;
		hours_1 = hours / 10;
		
		PORTA = (1<<PA0);             //Enable First Seven segment
		PORTC = (0x0F) & seconds_0;	 // Show seconds 0
		
		_delay_us(100);
		
		PORTA = (1<<PA1);            //Enable Second seven segment
		PORTC = (0x0F) & seconds_1;  // Show seconds 1
		
		_delay_us(100);
		 
		PORTA = (1<<PA2);           // Enable Third seven segment
		PORTC = (0x0F) & minutes_0; // Show minutes 0
		
		_delay_us(100);
		
		PORTA = (1<<PA3);          // Enable Fourth seven segment
		PORTC = (0x0F) & minutes_1;// Show minutes 1
		
		_delay_us(100);
		
		PORTA = (1<<PA4);         // Enable fifth segment
		PORTC = (0x0F) & hours_0; // Show hours 0
		
		_delay_us(100);
		
		PORTA = (1<<PA5);        // Enable Sixth segment
		PORTC = (0x0F) & hours_1;// Show hours 1
		
		_delay_us(100);
		
		
    }
}

