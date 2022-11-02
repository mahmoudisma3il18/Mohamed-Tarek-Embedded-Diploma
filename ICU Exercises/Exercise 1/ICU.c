/*
 * ICU.c
 *
 * Created: 11/1/2022 10:10:58 PM
 *  Author: Mahmoud Ismail
 */ 

#include "ICU.h"

/************************************************************************/
/*                            ISR                                       */
/************************************************************************/

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != ((void*)0)) {
		g_callBackPtr();
	}
}


/************************************************************************/
/*                     Functions                                        */
/************************************************************************/

void ICU_init(const ICU_ConfigType *Congig_ptr)
{
	DDRD &= ~(1<<PD6); // Configure PD6 as input pin
	
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B); // Non PWM
	
	TCCR1B = (TCCR1B & 0xF8) | (Congig_ptr->Clock); // Set Clock Value;
	
	TCCR1B = (TCCR1B & 0xBF) | ((Congig_ptr->EdgeType)<<6); // Set Edge Event
	
	TCNT1 = 0;
	
	ICR1 = 0;
	
	TIMSK |= (1<<TICIE1); // Enable ICU Interrupts
}


void ICU_setCallBack(void(*callBack_ptr)(void))
{
	g_callBackPtr = callBack_ptr;
}

void ICU_setEdgeDetection(const ICU_EdgeType edgeType)
{
	TCCR1B = (TCCR1B & 0xBF) | (edgeType<<6);
}

uint16_t ICU_getValue()
{
	return ICR1;
}

void ICU_clearTimer()
{
	TCNT1 = 0;
}

void ICU_deinit()
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	ICR1   = 0;
	
	TIMSK &= ~(1<<TICIE1);
}


