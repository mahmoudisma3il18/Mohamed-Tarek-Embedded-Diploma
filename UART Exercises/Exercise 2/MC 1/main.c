/*
 * MC 1.c
 *
 * Created: 4/13/2023 3:16:18 AM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "UART.h"

#define F_CPU 1000000UL


int main(void)
{
    /* Replace with your application code */
	
	uint8_t data_var ; /* Variable to hold data */
	
	UART_init(BaudRate_2400);
    while (1) 
    {
		data_var = KEYPAD_getPressedKey(); /* Read Data from keypad */
		UART_sendByte(data_var);           /* Send Data over UART */
    }
}

