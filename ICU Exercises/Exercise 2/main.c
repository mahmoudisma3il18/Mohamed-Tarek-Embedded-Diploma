/*
 * Exercise 2.c
 *
 * Created: 11/3/2022 1:14:13 AM
 * Author : modyb
 */ 

#include <avr/io.h>
#include "ICU.h"
#include "lcd.h"

volatile uint8_t g_edgeCounter;
volatile uint16_t g_timeHigh;
volatile uint16_t g_timePeriodAndHigh;

void edgeProscessing(void)
{
	g_edgeCounter++;
	if (g_edgeCounter == 1)
	{
		ICU_clearTimer();
		ICU_setEdgeDetection(FALLING_EDGE);
	}
	else if (g_edgeCounter == 2)
	{
		g_timeHigh = ICU_getValue();
		ICU_setEdgeDetection(RISING_EDGE);
	}
	else if (g_edgeCounter == 3)
	{
		ICU_setEdgeDetection(FALLING_EDGE);
	}
	else if (g_edgeCounter == 4)
	{
		g_timePeriodAndHigh = ICU_getValue();
		ICU_setEdgeDetection(RISING_EDGE);
	}
}

int main(void)
{
    /* Replace with your application code */
	
	SREG |= (1<<7); // Enable Golabl interrupts
	
	LCD_init();
	
	ICU_ConfigType configType = {F_CPU_CLOCK_1,RISING_EDGE};
		
	ICU_setCallBack(edgeProscessing);	
		
	ICU_init(&configType);
	
	LCD_displayString("Period :");
	
	uint16_t period;
	
		
    while (1) 
    {
		if (g_edgeCounter == 4)
		{
			g_edgeCounter = 0;
			ICU_deinit();
			period = (g_timePeriodAndHigh - g_timeHigh) /1000;
			LCD_integrToString(period);
		}
    }
}

