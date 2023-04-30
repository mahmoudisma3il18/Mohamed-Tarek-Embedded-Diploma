/*
 * MC1.c
 *
 * Created: 4/30/2023 7:14:53 PM
 * Author : modyb
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"


int main(void)
{
    /* Replace with your application code */
	SET_BIT(DDRB,PB0);            /* Set pin as output to select slave */
	
	/* Handler to SPI Config*/
	SPI_Config spi_handler = {SPI_Device_Mode_MASTER,
		SPI_Frame_Format_MSB_transmitted_first,
		SPI_CLKPolarity_LOW_when_idle,
		SPI_Clock_Phase_1EDGE_sample,
		fosc_4,
		SPI_IRQ_Disable};
	
	SPI_init(&spi_handler);	    /* Init SPI */
	
	_delay_ms(5000);           /* Delay until MC2 is Initialized */
	
	SPI_sendString("Kill");        /* SPI Send String */
	
		
    while (1) ;
  
}

