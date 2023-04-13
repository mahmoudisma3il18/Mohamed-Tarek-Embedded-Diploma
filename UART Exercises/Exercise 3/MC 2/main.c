/*
 * MC 2.c
 *
 * Created: 4/13/2023 3:42:30 AM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "UART.h"

#define F_CPU  1000000UL


int main(void)
{
    /* Replace with your application code */
	
	
	uint8_t data[20];
	
	LCD_init();  /* Init LCD */
	
	UART_init(BaudRate_2400);  /*  Init UART with Baud Rate 2400  */
	
	UART_recieveString(data);     /*  Receive string  */
	
	LCD_displayString(data);      /* Display Data on LCD */
	
    while (1) ;

}

