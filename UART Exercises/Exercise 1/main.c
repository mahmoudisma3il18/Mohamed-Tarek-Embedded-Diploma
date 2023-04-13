/*
 * Exercise 1.c
 *
 * Created: 4/13/2023 1:34:11 AM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#define  F_CPU 1000000

int main(void)
{
    /* Replace with your application code */
	
	uint8_t data ;  /*  Var to hold Data  */
	
	UART_init(BaudRate_2400); /* Intialize UART and set Baud Rate to 9600 */
	UART_sendByte('M');
    while (1) 
    {
		data = UART_recieveByte();
		UART_sendByte(data);
    }
}

