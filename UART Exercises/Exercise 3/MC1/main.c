/*
 * MC1.c
 *
 * Created: 4/13/2023 3:39:10 AM
 * Author : modyb
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

#define F_CPU  1000000UL




int main(void)
{
    /* Replace with your application code */
	
	_delay_ms(10000);
	
	UART_init(BaudRate_2400); /* Init Uart with baud rate 2400 */
    
	UART_sendString("I am Micro1 \n"); /* Send String */
	
	while(1);
}

