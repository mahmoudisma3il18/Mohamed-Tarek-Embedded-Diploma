/*
 * Motor.c
 *
 * Created: 3/8/2023 6:29:55 PM
 *  Author: Mahmoud Ismail
 */ 

#include "Motor.h"


void DcMotor_init() {
	
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT); //Setup pin for motor as output
	GPIO_setupPinDirection(PORTB_ID,PIN2_ID,PIN_OUTPUT); //Setup pin for motor as output
	
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); //Turn off motor
	GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_LOW); // Turn off Motor
	
}

void DcMotor_rotate(DcMotor_State state,uint8_t speed)
{
	if (state == Motor_stop)
	{
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); //Turn off motor
		GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_LOW); // Turn off Motor
	}
	else if (state == Motor_clockwise)
	{
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH); //Rotate Clock Wise
		GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_LOW); // Rotate ClockWise
		PWM_Timer0_start(speed); // Set Motor speed
	}
	else if (state == Motor_anticlockwise)
	{
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); //Rotate AntiClockWise
		GPIO_writePin(PORTB_ID,PIN2_ID,LOGIC_HIGH); //Rotate AntiClockWise
		PWM_Timer0_start(speed);
	}
	else
	{
		// Do nothing
	}
}