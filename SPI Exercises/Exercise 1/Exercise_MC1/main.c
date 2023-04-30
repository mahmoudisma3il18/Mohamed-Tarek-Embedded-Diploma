/*
 * Exercise_MC1.c
 *
 * Created: 4/29/2023 8:40:46 PM
 * Author : modyb
 */ 

#include <avr/io.h>
#include "SPI.h"



int main(void)
{
    /* Replace with your application code */
	SET_BIT(DDRB,PB0);     /* PB0 as output to select Slave */
	CLEAR_BIT(DDRA,PA0);   /* PA0 as input to check switch */
	SPI_Config spi_handler = {SPI_Device_Mode_MASTER,
		SPI_Frame_Format_MSB_transmitted_first,
		SPI_CLKPolarity_LOW_when_idle,
		SPI_Clock_Phase_1EDGE_sample,
		fosc_4,
		SPI_IRQ_Disable};
	
	SPI_init(&spi_handler);	
		
    while (1) 
    {
		SPI_slaveSelect(PORTB,PB0);  /* Select Slave */
		if (BIT_IS_SET(PINA,PA0))
		{
			SPI_sendByte(1);        /* SPI Send Byte */
		} 
		else
		{
			SPI_sendByte(0);      /* SPI Send Byte  */
		}
		SPI_slaveUnselect(PORTB,PB0); /* Unselect slave */
    }
}

