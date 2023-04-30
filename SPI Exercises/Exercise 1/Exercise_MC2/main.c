/*
 * Exercise_MC2.c
 *
 * Created: 4/30/2023 5:36:45 PM
 * Author : Mahmoud Ismail
 */ 

#include <avr/io.h>
#include "SPI.h"


int main(void)
{
    /* Replace with your application code */
	SET_BIT(DDRC,PC3);     /* Set pin as Output for LED */
	
	/* Handler For SPI Config */
	SPI_Config spi_handler = {SPI_Device_Mode_SLAVE,   
		SPI_Frame_Format_MSB_transmitted_first,
		SPI_CLKPolarity_LOW_when_idle,
		SPI_Clock_Phase_1EDGE_sample,
		fosc_4,
		SPI_IRQ_Disable};
	
	SPI_init(&spi_handler);    /* Init SPI */	
	
	uint8_t recived_data ;   /* Var to hold received data from SPI */
		
    while (1) 
    {
		recived_data = SPI_receiveByte();
		if (recived_data == 1)
		{
			SET_BIT(PORTC,PC3);     /* Turn on LED  */
		}
		else
		{
			CLEAR_BIT(PORTC,PC3);   /* Turn Off LED */
		}
    }
}

