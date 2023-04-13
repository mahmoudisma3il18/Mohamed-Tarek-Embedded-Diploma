/*
 * MC 2.c
 *
 * Created: 4/13/2023 4:43:26 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "UART.h"

int main(void)
{
    /* Replace with your application code */
	
	uint8_t var_data;                        /*  Variable to hold data  */
	
	LCD_init();                              /*  Initialize LCD  */
	
	UART_init(BaudRate_2400);                /*  Initialize UART with Baud Rate  2400 */
	
	_delay_ms(2000);                         /*  Delay for 2 seconds  */ 
    while (1) 
    {
		var_data = UART_recieveByte();      /* Receive data from UART */
		
		LCD_displayCharacter(var_data);     /* Show data on LCD       */
    }
}

