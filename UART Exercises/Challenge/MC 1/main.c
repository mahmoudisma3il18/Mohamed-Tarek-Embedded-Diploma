/*
 * MC 1.c
 *
 * Created: 4/13/2023 4:37:21 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "UART.h"



int main(void)
{
    /* Replace with your application code */
	
	uint8_t var_char;                        /* Var to hold data  */
	
	UART_init(BaudRate_2400);                /* Initialization UART with Baud Rate 2400  */
	
	_delay_ms(2000);                         /* Delay until Initialization is done  */
    while (1) 
    {
		var_char = KEYPAD_getPressedKey();
		UART_sendByte(var_char);
		_delay_ms(500);
    }
}

