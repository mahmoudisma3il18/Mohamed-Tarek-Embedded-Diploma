/*
 * Keypad_LCD_Challenge.c
 *
 * Created: 10/17/2022 9:09:12 PM
 * Author : modyb
 */ 

#include "lcd.h"
#include "keypad.h"


int main(void)
{
    /* Replace with your application code */
	
	uint8_t value;
	LCD_init();
	LCD_displayString("Challenge");
	LCD_displayStringRowColumn(1,0,"KEYPAD 4x4");
	LCD_displayStringRowColumn(2,0,"LCD");
	LCD_goToRowColumn(3,0);
    while (1) 
    {
		value = KEYPAD_getPressedKey();
		LCD_displayCharacter(value);
		_delay_ms(500);
    }
}

