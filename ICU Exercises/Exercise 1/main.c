/*
 * Exercise 1.c
 *
 * Created: 8/15/2023 10:48:15 PM
 * Author : Mahmoud Ismail
 */ 

#define F_CPU      1000000

/*------------------------- Includes ----------------------------*/
#include <avr/io.h>
#include "D:\Embedded Systems\Mohamed Tarek Embedded Diploma AVR\My Solutions\Mohamed-Tarek-Embedded-Diploma\ICU Exercises\Exercise 1\MCAL\ICU.h"
#include "D:\Embedded Systems\Mohamed Tarek Embedded Diploma AVR\My Solutions\Mohamed-Tarek-Embedded-Diploma\ICU Exercises\Exercise 1\HAL\lcd.h"


/*---------------------- Global Variables ---------------------------*/
uint8_t     g_edgeCounter ;      
uint16_t    g_highTime;
uint16_t    g_periodTime;
uint16_t    g_periodAndhighTime;



void edgeProcescing(void) {
	
	g_edgeCounter++;
	
	if (g_edgeCounter == 1) /* First rising edge */
	{
		ICU_clearTimer();
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if (g_edgeCounter == 2)
	{
		g_highTime = ICU_getTimerValue();       /* Returns high time */
		ICU_setEdgeDetectionType(RISING_EDGE);
	}
	else if (g_edgeCounter == 3)
	{
		g_periodTime = ICU_getTimerValue();     /* Returns period time */
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if (g_edgeCounter == 4)
	{
		g_periodAndhighTime = ICU_getTimerValue();  /* Period time + High time */
		ICU_clearTimer();
		ICU_setEdgeDetectionType(RISING_EDGE);
		
	}
	
}


int main(void)
{
    /* Replace with your application code */
	
	
	/* 1. Enable Global interrupts */
	SREG |= (1<<7);
	
	/* 2. Initialize LCD */
	LCD_init();
	
	/* 3. Configure ICU  */
	ICU_configType configType_ICU = {F_CPU_CLOCK,RISING_EDGE};
	ICU_setCallBack(edgeProcescing);
	ICU_init(&configType_ICU);	
	
	/* 4. Display String */
	LCD_displayString("Duty");
	
	/* 5. Variable to hold duty cycle */
	uint16_t duty = 0;
    while (1) 
    {
		if (g_edgeCounter == 4)
		{
			duty = ((float)(g_periodAndhighTime - g_periodTime) / (g_periodAndhighTime - g_highTime)) * 100;
			LCD_goToRowColumn(0,6);
			
			/* Display duty cycle */
			LCD_integrToString(duty);
			LCD_displayCharacter('%');
			g_edgeCounter = 0;
		}
		
		
    }
}

