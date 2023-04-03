/*
 * Motor.h
 *
 * Created: 3/8/2023 6:29:43 PM
 *  Author: Mahmoud Ismail
 */ 




#ifndef MOTOR_H_
#define MOTOR_H_

/*---------------------------------------- Includes --------------------------------------------------*/
#include <stdint-gcc.h>
#include "common_macros.h"
#include <avr/io.h>
#include "PWM.h"
#include "gpio.h"

/*---------------------------------------- Typedefs -------------------------------------------------*/

typedef enum {
	Motor_stop,
	Motor_clockwise,
	Motor_anticlockwise
	}DcMotor_State;
	
	
/*------------------------------------ Function Prototypes ----------------------------------------------*/

/*
Description : Intialzie Motor
*/

void DcMotor_init(void);

/*
Description : 	The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value.
 Send the required duty cycle to the PWM driver based on the
required speed value.
*/
void DcMotor_rotate(DcMotor_State state,uint8_t speed);




#endif /* MOTOR_H_ */