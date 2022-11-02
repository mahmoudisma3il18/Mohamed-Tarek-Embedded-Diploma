/*
 * ICU.h
 *
 * Created: 11/1/2022 10:11:11 PM
 *  Author: Mahmoud Ismail
 */ 

#include "common_macros.h"
#include <avr/io.h>
#include <stdint-gcc.h>
#include <avr/interrupt.h>

#ifndef ICU_H_
#define ICU_H_

/************************************************************************/
/*                          Global Varaibles                            */
/************************************************************************/      
                           

static volatile void (*g_callBackPtr)(void) = ((void *)0) ;



/************************************************************************/
/*                              Enums                                   */
/************************************************************************/

typedef enum {
	NO_CLOCK,
	F_CPU_CLOCK_1,
	F_CPU_CLOCK_8,
	F_CPU_CLOCK_64,
	F_CPU_CLOCK_256,
	F_CPU_CLOCK_1024
	}ICU_Clock;
	
typedef enum {
	FALLING_EDGE,
	RISING_EDGE
	}ICU_EdgeType;	
	

/************************************************************************/
/*                                 Structs                              */
/************************************************************************/

typedef struct {
	ICU_Clock Clock;
	ICU_EdgeType EdgeType;
	}ICU_ConfigType;

/************************************************************************/
/*                    Functions Prototypes                              */
/************************************************************************/

/*
- Description : Initialize ICU with desired configurations 
- Parameters : Pointer to ICU_ConfigType Struct 
*/
void ICU_init(const ICU_ConfigType *Congig_ptr);

/*
- Description : Set ICU Interrupt call Back Function
- Parameters : Pointer to function;
*/
void ICU_setCallBack(void(*callBack_ptr)(void));

/*
- Description : Set Edge detection for event (Rising or Falling)
- Parameters : ICU_EdgeType Enum
*/
void ICU_setEdgeDetection(const ICU_EdgeType edgeType);

/* 
- Description : Return value of ICU Counter (ICR1)
- Parameters : Has no parameters
*/
uint16_t ICU_getValue(void);

/*
- Description : Clear Register Value
- Parameters  : Has no parameters
*/
void ICU_clearTimer(void);

/*
- Description : Disable ICU Timer 
- Parameters : Has no parameters 
*/
void ICU_deinit(void);



#endif /* ICU_H_ */