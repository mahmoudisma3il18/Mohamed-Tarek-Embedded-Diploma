/*
 * PWM.h
 *
 * Created: 3/8/2023 12:43:09 AM
 *  Author: Mahmoud Ismail
 */ 


#ifndef PWM_H_
#define PWM_H_

/*--------------------------------- Includes -----------------------------------------*/
#include <stdint-gcc.h>
#include <avr/io.h>
#include "common_macros.h"


/*------------------------------ Function Prototypes --------------------------------*/

void PWM_Timer0_start(uint8_t duty_cycle);



#endif /* PWM_H_ */