/*
 * Challenge.c
 *
 * Created: 8/16/2023 6:55:11 PM
 * Author : Mahmoud Ismail
 */ 

#define        F_CPU      1000000

/*------------------------------ Includes ------------------------------*/
#include <avr/io.h>
#include "../Challenge/MCAL/ICU.h"
#include "../Challenge/HAL/lcd.h"

/*--------------------------- Global Variables -------------------------*/

uint8_t   g_edgeCounter ;
uint16_t  g_periodTime;
uint16_t  g_highTime;
uint16_t  g_periodAndhighTime;



void edgeProcessing(void) {
	
	g_edgeCounter++;
	
	if (g_edgeCounter == 1)
	{
		
		ICU_clearTimer();
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if (g_edgeCounter == 2)
	{
		g_highTime = ICU_getTimerValue();
		ICU_setEdgeDetectionType(RISING_EDGE);
	}
	else if (g_edgeCounter == 3)
	{
		g_periodTime = ICU_getTimerValue();
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if (g_edgeCounter == 4)
	{
		g_periodAndhighTime = ICU_getTimerValue();
		ICU_setEdgeDetectionType(RISING_EDGE);
		ICU_clearTimer();
	}
	
}

int main(void)
{
    /* Replace with your application code */
	
	/* 1. Enable interrupts */
	SREG |= (1<<7);
	
	/* 2. Init LCD  */
	LCD_init();
	
	/* 3. Configure ICU  */
	ICU_configType ICUptr = {F_CPU_CLOCK,RISING_EDGE};
	ICU_setCallBack(edgeProcessing);
	ICU_init(&ICUptr);
	
	/* 4. Variable to hold Frequency */
	uint16_t freq = 0;
	
	/* 5. Display String */
	LCD_displayString("Frequency ");
		
    while (1) 
    {
		if (g_edgeCounter == 4)
		{
			freq =   1000000 / (g_periodAndhighTime - g_highTime) ;
			LCD_goToRowColumn(1,0);      /* Go to second column */
			LCD_displayString("   ");    /* Delete old value */
			LCD_integrToString(freq);    /* Display freq */
			LCD_displayString("hZ");
			g_edgeCounter = 0;
		}
    }
}

