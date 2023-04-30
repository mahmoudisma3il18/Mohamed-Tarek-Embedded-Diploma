/*
 * MC2.c
 *
 * Created: 4/30/2023 7:19:33 PM
 * Author : modyb
 */ 

#include <avr/io.h>
#include "lcd.h"
#include "SPI.h"


int main(void)
{
    /* Replace with your application code */
	/* Handler For SPI Config */
	uint8_t str[20];
	
	SPI_Config spi_handler = {SPI_Device_Mode_SLAVE,
		SPI_Frame_Format_MSB_transmitted_first,
		SPI_CLKPolarity_LOW_when_idle,
		SPI_Clock_Phase_1EDGE_sample,
		fosc_4,
	    SPI_IRQ_Disable};
	SPI_init(&spi_handler);	
	
	LCD_init();
	
    /* Init SPI */
	LCD_displayCharacter('m');
	SPI_receiveString(str);
	LCD_displayString(str);
	while(1);
}

