/*
 * Exercise 2.c
 *
 * Created: 10/22/2022 2:27:08 PM
 * Author : modyb
 */ 

#include <avr/io.h>
#include "ADC.h"
#include "lm35_sensor.h"
#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
	ADC_init();
	LCD_init();
	LCD_displayString("Temp =    C");
	uint8_t temp;

	while(1)
	{

		temp = LM35_getTempertaure();

		/* Display the temperature value every time at same position */
		LCD_goToRowColumn(0,7);
		if(temp >= 100)
		{
			LCD_integrToString(temp);
		}
		else
		{
			LCD_integrToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}

