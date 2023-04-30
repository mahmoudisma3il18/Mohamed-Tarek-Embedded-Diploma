/*
 * MC2.c
 *
 * Created: 4/30/2023 10:24:53 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "lcd.h"


int main(void)
{
    /* Replace with your application code */
	
	/* SPI Handler */
	SPI_Config SPI_Hanler = {SPI_Device_Mode_SLAVE,
		                     SPI_Frame_Format_MSB_transmitted_first,
							 SPI_CLKPolarity_LOW_when_idle,
							 SPI_Clock_Phase_1EDGE_sample,
							 fosc_4,
							 SPI_IRQ_Disable};
							 
	uint8_t var;						 
							 
	SPI_init(&SPI_Hanler);        /* Init SPI  */
	LCD_init();					  /* Init LCD  */	 
    while (1) 
    {
		var = SPI_receiveByte();
		LCD_displayCharacter(var);
    }
}

