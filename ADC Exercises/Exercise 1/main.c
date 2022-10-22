 /*
 * Exercise 1.c
 *
 * Created: 10/17/2022 11:21:23 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
	LCD_init();
	
	ADC_init();
	
	uint16_t value;
	
	LCD_displayString("ADC Value : ");
	
	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF);
    while (1) 
    {
		value = ADC_readChanel(Channel0_ID);
		LCD_integrToString(value);
		LCD_goToRowColumn(0,12);
    }
}

