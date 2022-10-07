/*
 * Exercise 2.c
 *
 * Created: 10/7/2022 2:31:04 AM
 * Author : modyb
 */ 

#define F_CPU  1000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char Flag = 0;

ISR(INT1_vect){
	
	Flag = 1;
	
}


void INT1_Init(void){
	SREG &= ~(1<<7);
	
	DDRD &= (1<<PD3);
	PORTD |= (1<<PD3);
	
	GICR |= (1<<INT1);
	
	MCUCR |= (1<<ISC11) & ~(1<<ISC10);
	
	SREG |= (1<<7);
}


int main(void)
{
    /* Replace with your application code */
	
	DDRC = 0xFF;
	PORTC= 0x01;
	
	INT1_Init();
	
	
    while (1) 
    {
		
		if (Flag == 0)
		{
			_delay_ms(500);
			PORTC <<= 1;
			if(PORTC == 0x00)
			PORTC = 0x01; 
		}
		else if (Flag == 1){
			
			for (int i = 0 ; i<5 ;i++)
			{
				PORTC = 0xFF;
				_delay_ms(500);
				PORTC = 0x00;
				_delay_ms(500);
			}
			
			Flag = 0;
		}
		
    }
}

