/*
 * ICU.c
 *
 * Created: 8/12/2023 9:22:33 PM
 *  Author: Mahmoud Ismail
 */ 


/*----------------------------- Includes ------------------------------*/
#include "ICU.h"


/*-------------------------------- Global Variables ------------------------*/

static volatile void (*g_callBackPtr)(void) = NULL;


/*----------------------------- Functions -----------------------------*/


ISR(TIMER1_CAPT_vect) {
	if(g_callBackPtr != NULL)
	   g_callBackPtr();
}

/*
Description : Initialize ICU
*/
void ICU_init(ICU_configType *configType) {
	
	
	/* 1. Configure ICP1/PD6 as Input */
	DDRD &= ~(1<<PD6);
	
	/* 2. Timer in Normal Mode,The FOC1A/FOC1B bits are only active when the WGM13:0 bits specifies a non-PWM mode */
	
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
	
	/* 3. Set Edge Detection */
	TCCR1B  = (TCCR1B & 0xBF) | ((configType->edgeType) << ICES1); 
	
	/* 4. Input Capture Interrupt Enable */  
	TIMSK  |= (1<<TICIE1);    
	
	/* 5. Initial Values for Timers */
	TCNT1 = 0x0000;
	ICR1  = 0x0000;
	
	/* 5. Clock Select */                       
	TCCR1B = (TCCR1B & 0xF8) | (configType->clockPrescaler);      
	
}

/*
Description : Set call back function
*/
void ICU_setCallBack(void (*a_ptr)(void)) {
	
	/* 1. Set pointer of callback function to function in App layer */
	g_callBackPtr = a_ptr;
}

/*
Description : DeInit ICU
*/
void ICU_deInit() {
	
	/* 1. Set all Registers to zero */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	ICR1   = 0;
	
	/* 2. Disable ICU Interrupt */
	TIMSK &= ~(1<<TICIE1);
	
}

/*
Description : Change Edge detection of ICU
*/
void ICU_setEdgeDetectionType(ICU_edgeType edgeType) {
	
	/* 1. Change Edge type  */
	TCCR1B  = (TCCR1B & 0xBF) | (edgeType << ICES1);
}


/*
Description : Returns value of timer
*/
uint16_t ICU_getTimerValue() {
	
	/* 1. Declare variable to store value */
	uint16_t ret_var = 0;
	
	/* 2. Store timer value in variable */
	ret_var = ICR1; 
	
	/* 3. Return timer value */
	return ret_var;
	
}

/*
Description : Clear Timer Register
*/
void ICU_clearTimer() {
	
	/* 1. Clear Timer value */
	TCNT1 = 0;
}
	
