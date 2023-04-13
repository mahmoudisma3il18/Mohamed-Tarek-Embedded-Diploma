/*
 * UART Driver.c
 *
 * Created: 4/13/2023 12:23:38 AM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include "UART.h"

int main(void)
{
    /* Replace with your application code */
	UART_init(BaudRate_9600); // Intialeze Uart and set baud rate to 9600
    while (1) 
    {
    }
}

