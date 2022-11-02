/*
 * ICU.h
 *
 * Created: 11/3/2022 1:15:30 AM
 *  Author: Mahmoud Ismail
 */ 

/************************************************************************/
/*                 Includes                                             */
/************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint-gcc.h>

#ifndef ICU_H_
#define ICU_H_

/************************************************************************/
/*                      Global Variables                                */
/************************************************************************/

static volatile void(*g_callBackPtr)(void) = ((void*)0);

/************************************************************************/
/*                               Enums                                  */
/************************************************************************/

typedef enum {
	NO_CLOCK,
	F_CPU_CLOCK_1,
	F_CPU_CLOCK_8,
	F_CPU_CLOCK_64,
	F_CPU_CLOCK_256,
	F_CPU_CLOCK_1024
	}ICU_ClockSource;
	
typedef enum {
	
	FALLING_EDGE,
	RISING_EDGE
	}ICU_EdgeType;	
	
/************************************************************************/
/*                           Structs                                    */
/************************************************************************/	

typedef struct {
	ICU_ClockSource Clock;
	ICU_EdgeType Edge;
	}ICU_ConfigType;
	
/************************************************************************/
/*                     Functions                                        */
/************************************************************************/	

void ICU_init(const ICU_ConfigType *Congig_ptr);

void ICU_setCallBack(void(*a_ptr)(void));

void ICU_setEdgeDetection(const ICU_EdgeType edgeType);

void ICU_clearTimer();

uint16_t ICU_getValue();

void ICU_deinit();



#endif /* ICU_H_ */