/*
 * LCD_4Bits.c
 *
 * Created: 10/17/2022 5:10:35 PM
 * Author : Mahmoud Ismail
 */ 

#include "lcd.h"

int main(void)
{
	LCD_init(); /* initialize LCD */
	LCD_displayString("Welcome To LCD");
	LCD_displayStringRowColumn(1,0,"4 Bits Data Mode");
	
	while(1)
	{
		/* Note: we write the code before while(1) because we want to execute it only once */
	}
	
}