/*
 * MC1.c
 *
 * Created: 4/30/2023 10:18:04 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "keypad.h"
#include "SPI.h"


int main(void)
{
    /* Replace with your application code */
	
	/* Handler to SPI Configs */
	SPI_Config SPI_Handler = {SPI_Device_Mode_MASTER,
		                      SPI_Frame_Format_MSB_transmitted_first,
							  SPI_CLKPolarity_LOW_when_idle,
							  SPI_Clock_Phase_1EDGE_sample,
							  fosc_4,
							  SPI_IRQ_Disable};
							
	uint8_t var;     						  
							  
	SPI_init(&SPI_Handler);				/* Init SPI */
	
	_delay_ms(3000);                /* Delay until MC2 is Initialized */
			  
    while (1) 
    {
		var = KEYPAD_getPressedKey();    /* Read data from keypad */
		SPI_sendByte(var);               /* Send data over SPI    */
		_delay_ms(500);
    }
}

