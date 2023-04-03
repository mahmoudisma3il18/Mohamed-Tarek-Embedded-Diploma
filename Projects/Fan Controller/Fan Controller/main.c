/*
 * Fan Controller.c
 *
 * Created: 3/6/2023 11:06:21 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Motor.h"
#include "lcd.h"
#include "Lm35.h"

#define F_CPU            1000000


int main(void)
{
    /* Replace with your application code */
	
	ADC_ConfigType Config = {Internal,F_CPU_8} ;
	LCD_init(); // Initialize LCD
	ADC_init(&Config); // Initialize ADC
	DcMotor_init(); // Initialize DcMotor
	
	uint8_t temp ;
	
	LCD_sendCommand(DISPLAY_ON_CURSOR_OFF); // TurnOff Cursor
	
    while (1) 
    {
		temp = LM35_getTemp(); // Gets Temp
		
		
		if (temp < 30)
		{
			DcMotor_rotate(Motor_stop,0); // Turn Off Motor
			LCD_goToRowColumn(0,2);
			LCD_displayString("Fan is OFF");
			LCD_goToRowColumn(1,2);
			LCD_displayString("Temp = ");
			LCD_goToRowColumn(1,10);
			LCD_integrToString(temp);
			LCD_displayCharacter(' ');
		}
		else if (temp < 60)
		{
			DcMotor_rotate(Motor_clockwise,25); // Turn ON Motor with 25%
			LCD_goToRowColumn(0,2);
			LCD_displayString("Fan is ON ");
			LCD_goToRowColumn(1,2);
			LCD_displayString("Temp = ");
			LCD_goToRowColumn(1,10);
			LCD_integrToString(temp);
			LCD_displayCharacter(' ');
		}
		else if (temp < 90)
		{
			DcMotor_rotate(Motor_clockwise,50); // Turn ON Motor with 50%
			LCD_goToRowColumn(0,2);
			LCD_displayString("Fan is ON");
			LCD_goToRowColumn(1,2);
			LCD_displayString("Temp = ");
			LCD_goToRowColumn(1,10);
			LCD_integrToString(temp);
			LCD_displayCharacter(' ');
		}
		else if (temp < 120)
		{
			DcMotor_rotate(Motor_clockwise,75); // Turn ON Motor with 75%
			LCD_goToRowColumn(0,2);
			LCD_displayString("Fan is ON");
			LCD_goToRowColumn(1,2);
			LCD_displayString("Temp = ");
			LCD_goToRowColumn(1,10);
			LCD_integrToString(temp);
			LCD_displayCharacter(' ');
		}
		else if (temp >= 120)
		{
			DcMotor_rotate(Motor_clockwise,100); // Turn ON Motor with 100%
			LCD_goToRowColumn(0,2);
			LCD_displayString("Fan is ON");
			LCD_goToRowColumn(1,2);
			LCD_displayString("Temp = ");
			LCD_goToRowColumn(1,10);
			LCD_integrToString(temp);
			LCD_displayCharacter(' ');
		}
		else
		{
			//Do nothing
		}
		
	
		
    }
}

