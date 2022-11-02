/*
 * Exercise 1.c
 *
 * Created: 11/1/2022 10:02:20 PM
 * Author : Mahmoud Ismail
 */ 

/************************************************************************/
/*                     Definitions                                      */
/************************************************************************/

#define F_CPU 1000000

/************************************************************************/
/*                           Includes                                   */
/************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "ICU.h"
#include "lcd.h"

/************************************************************************/
/*                     Global Variables                                 */
/************************************************************************/

volatile uint8_t g_ICUedgeCounter ;
volatile uint16_t g_timeHigh;
volatile uint16_t g_timePeriod;
volatile uint16_t g_timePeriodAndHigh;


/************************************************************************/
/*                     Functions                                        */
/************************************************************************/

void edgeProcessing(void)
{
	g_ICUedgeCounter++;
	
	if (g_ICUedgeCounter == 1)
	{
		
		ICU_clearTimer();
		ICU_setEdgeDetection(FALLING_EDGE);
	}
	else if (g_ICUedgeCounter == 2)
	{
		g_timeHigh = ICU_getValue();
		ICU_setEdgeDetection(RISING_EDGE);
	}
	else if (g_ICUedgeCounter == 3)
	{
		g_timePeriod = ICU_getValue();
		ICU_setEdgeDetection(FALLING_EDGE);
	}
	else if (g_ICUedgeCounter == 4)
	{
		g_timePeriodAndHigh = ICU_getValue();
		ICU_setEdgeDetection(RISING_EDGE);
	}
}



int main(void)
{
    /* Replace with your application code */
	
	SREG |= (1<<7); // Enable Global Interrupts
	
	ICU_ConfigType ICU_Config = {F_CPU_CLOCK_1,RISING_EDGE}; // Struct for ICU Configurations 
		
	ICU_setCallBack(edgeProcessing);	
		
	LCD_init();
	
	ICU_init(&ICU_Config);
	
	uint16_t dutyCycle;
	
	LCD_displayString("Duty:");
	
	
    while (1) 
    {
		if (g_ICUedgeCounter == 4)
		{
			ICU_deinit();
			g_ICUedgeCounter = 0;
			dutyCycle = ((float)(g_timePeriodAndHigh - g_timePeriod) / (g_timePeriodAndHigh - g_timeHigh)) * 100;
			LCD_integrToString(dutyCycle);
			LCD_displayCharacter('%');
			
		}
		
    }
}

