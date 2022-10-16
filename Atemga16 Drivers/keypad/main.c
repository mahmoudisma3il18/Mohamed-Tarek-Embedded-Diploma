/*
 * keypad.c
 *
 * Created: 10/16/2022 8:05:44 PM
 * Author : Mahmoud Ismail
 */ 

#include "keypad.h"



int main(void)
{
	uint8_t key;
	DDRC  |= 0x0F; /* 7-segment pins as output pins */
	PORTC &= 0xF0; /* 7-segment displays Zero at the beginning */
	while(1)
	{
		key = KEYPAD_getPressedKey() - '0'; /* get the pressed button from keypad */
		if((key >= 0) && (key <= 9))
		{
			PORTC = key;
		}
	}
}
