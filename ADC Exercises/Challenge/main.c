/*
 * Challenge.c
 *
 * Created: 10/22/2022 3:03:11 PM
 * Author : modyb
 */ 

#include <avr/io.h> /* To use SREG register */
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"

int main(void)
{
	uint16_t temp;

	SREG |= (1<<7);/* Enable Global Interrupts */

	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp =    C");
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


