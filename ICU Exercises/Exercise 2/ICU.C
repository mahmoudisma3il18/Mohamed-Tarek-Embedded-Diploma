/*
 * ICU.C
 *
 * Created: 11/3/2022 1:15:41 AM
 *  Author: Mahmoud Ismail
 */ 

#include "ICU.h"

/************************************************************************/
/*                     ISR                                              */
/************************************************************************/

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != ((void*)0))
	{
		g_callBackPtr();
	}
}

void ICU_init(const ICU_ConfigType *Congig_ptr)
{
	DDRD &= ~(1<<PD6);
	
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B); // NON PWM Mode
	
	TCCR1B = (TCCR1B & 0xF8) | (Congig_ptr->Clock); // Set clock frequency
	
	TCCR1B = (TCCR1B & 0xBF) | ((Congig_ptr->Edge)<<6); // Set Edge type
	
	TIMSK |= (1<<TICIE1); // Enable ICU Interrupt
	
	TCNT1 = 0;
	
	ICR1=0;  
	
}

ICU_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}

ICU_setEdgeDetection(const ICU_EdgeType edgeType)
{
	TCCR1B = (TCCR1B & 0xBF) | (edgeType<<6); // Set Edge type
}

void ICU_clearTimer()
{
	TCNT1 = 0;
}

uint16_t ICU_getValue()
{
	return ICR1;
}

void ICU_deinit()
{
	TCCR1A = 0;

	TCCR1B = 0;
	
	TCNT1 = 0;
	
	ICR1=0;
	
	TIMSK &= ~(1<<TICIE1); // Disable ICU Interrupt
}
