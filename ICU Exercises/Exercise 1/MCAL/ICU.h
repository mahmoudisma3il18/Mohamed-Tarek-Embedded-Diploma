/*
 * ICU.h
 *
 * Created: 8/12/2023 9:22:45 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef ICU_H_
#define ICU_H_


/*---------------------------------- Includes ------------------------------*/
#include <avr/io.h>
#include <stdint-gcc.h>
#include <stdio.h>
#include <util/delay.h>
#include "../Lib/common_macros.h"
#include <avr/interrupt.h>



/*-------------------------------- Global Variables ------------------------*/



typedef enum {
	FALLING_EDGE,
	RISING_EDGE
	}ICU_edgeType;
	
typedef enum {
	NO_CLOCK ,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024
	}ICU_clockPrescaler;	

typedef struct {
	ICU_clockPrescaler clockPrescaler;
	ICU_edgeType       edgeType;
    }ICU_configType;
	
	
/*--------------------------- Function Prototypes --------------------------*/


/*
Description : Initialize ICU
*/
void ICU_init(ICU_configType *configType);	

/*
Description : Set call back function
*/
void ICU_setCallBack(void (*a_ptr)(void));

/*
Description : DeInit ICU
*/
void ICU_deInit();


/*
Description : Change Edge detection of ICU
*/
void ICU_setEdgeDetectionType(ICU_edgeType edgeType);


/*
Description : Returns value of timer
*/
uint16_t ICU_getTimerValue();


/*
Description : Clear Timer Register
*/
void ICU_clearTimer();
	
	
	






#endif /* ICU_H_ */