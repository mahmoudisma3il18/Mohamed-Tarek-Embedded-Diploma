/*
 * PWM.c
 *
 * Created: 3/8/2023 12:42:53 AM
 *  Author: Mahmoud Ismail
 */ 

#include "PWM.h"

void PWM_Timer0_start(uint8_t duty_cycle) {
	
	SET_BIT(DDRB,PB3) ; // Sets OC0 as output
	TCNT0 = 0x00; // Clears register to start from BOTTOM
	OCR0  = (uint8_t)(((float)(duty_cycle/100.0)) * 255);
	TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS01); // Fast PWM,Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode), Freq/8
}