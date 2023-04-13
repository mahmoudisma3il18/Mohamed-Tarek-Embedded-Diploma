/*
 * keypad.c
 *
 * Created: 10/16/2022 8:05:59 PM
 *  Author: Mahmoud Ismail
 */ 

#include "keypad.h"



uint8_t KEYPAD_getPressedKey()
{
	while(1) {
		
	for (int col = 0 ; col < NO_OF_COLS;col++)
	{
		KEYPAD_PORT_DIR = (0x10<<col); // set column as output
		
		KEYPAD_PORT_OUT = (~(0x10<<col)); // Enable PULL-UP resistor in all pins except for the column and write logic low on column
		
		for(int row = 0 ; row < NO_OF_ROWS ; row++)
		{
			
			if (BIT_IS_CLEAR(KEYPAD_PORT_IN,row))
				return keypad[row][col];	
		}
	}
}
}