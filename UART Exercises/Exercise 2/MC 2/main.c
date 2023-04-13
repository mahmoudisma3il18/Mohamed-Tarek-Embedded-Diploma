/*
 * MC 2.c
 *
 * Created: 4/13/2023 3:22:07 AM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

#define  F_CPU  1000000UL


int main(void)
{
    /* Replace with your application code */
	
	uint8_t var_data;
	
	DDRC = 0xFF; /* Set PortC as output */ 
	
	UART_init(BaudRate_2400); /* Initialize Uart with 2400 Baud Rate */
	
    while (1) 
    {
		var_data = UART_recieveByte(); /* Receive Data from UART */
		
		var_data = var_data - 48 ; /* Convert from char to number */
		
		PORTC = (1<<var_data);     /* Turn on led */
		
    }
}

