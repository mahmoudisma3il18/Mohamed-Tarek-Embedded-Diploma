/*
 * SPI.c
 *
 * Created: 4/29/2023 12:01:53 AM
 *  Author: Mahmoud Ismail
 */ 

#include "SPI.h"



/*------------------------------ Functions ---------------------------------*/

void SPI_init(SPI_Config *ptr_config) {
	
	if (ptr_config->Device_Mode == SPI_Device_Mode_MASTER)
	{
		/* Set MOSI and SCK output and SS, all others input */
		SET_BIT(DDRB,PB5);    /* MOSI Pin */
		SET_BIT(DDRB,PB7);    /* SCK Pin */
		SET_BIT(DDRB,PB4);    /* SS Pin */
		CLEAR_BIT(DDRB,PB6);  /* MISO Pin */
	}
	else
	{
		/* Set MISO output, all others input */
		CLEAR_BIT(DDRB,PB4);   /* SS Pin */
		CLEAR_BIT(DDRB,PB5);   /* MOSI Pin */
		SET_BIT(DDRB,PB6);     /* MISO Pin */
		CLEAR_BIT(DDRB,PB7);  /* SCK Pin */
	}
	
	
	/* Enable SPI , Set Frame format ,Device Mode , CLK Phase and Polarity , BuadRate , Intterupt Enable */
	 SPCR = (1<<SPE) | (ptr_config->Frame_Format) | (ptr_config->Device_Mode) | (ptr_config->CLKPhase) | (ptr_config->CLKPolarity) | (ptr_config->SPI_BAUDRATEPRESCALER) | (ptr_config->IRQ_Enable);
	 
}

void SPI_sendByte(uint8_t data) {
	
	/* Put Data in buffer register */
	SPDR = data;
	
	/* Wait for transmission complete */
	while(BIT_IS_CLEAR(SPSR,SPIF));
}

uint8_t SPI_receiveByte() {
	
	/* Var to hold returned data */
	uint8_t ret_data;
	
	/* Wait for reception complete */
	while(BIT_IS_CLEAR(SPSR,SPIF));

	/* Return data register */
	ret_data = SPDR;
	return ret_data;
}

/* Send array of uint8_t */
void SPI_sendString(uint8_t* p_data) {
	
	uint8_t i = 0 ; /* Counter */
	
	while(p_data[i] != '\0')   /* Loop until data is send */
	{
		SPI_sendByte(p_data[i]);
		i++;
	}
	SPI_sendByte('\0');       /* Send terminating char */
}

void SPI_receiveString(uint8_t* p_data) {
	
	uint8_t i = 0;  /* Counter */
	p_data[i] = SPI_receiveByte();
	
	while(p_data[i] != '\0')     /* Loop untill data is recived */
	{
		i++;
		p_data[i] = SPI_receiveByte();
	}
}


/* Select Slave */
void SPI_slaveSelect(uint8_t PORT_ID,uint8_t PIN_ID) {
	
	CLEAR_BIT(PORT_ID,PIN_ID);  /* Active low */
	
}

/* Unselect Slave */
void SPI_slaveUnselect(uint8_t PORT_ID,uint8_t PIN_ID) {
	
	SET_BIT(PORT_ID,PIN_ID);  /* Active Low */
}
