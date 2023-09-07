/*
 * I2C.c
 *
 * Created: 9/2/2023 2:15:14 AM
 *  Author: Mahmoud Ismail
 */ 

#include "I2C.h"

/* Initialize I2C */
void I2C_init(I2C_SCL_Freq scl_freq) {
	
	/* 1. Set Frequency */
	uint32_t twbrValue;
	uint8_t twpsBits;

	// Calculate the TWBR value
	twbrValue = (F_CPU / (2 * scl_freq)) - 8;

	// Determine the appropriate prescaler (TWPS) value
	
	if (twbrValue <= 10) 
	{
		twpsBits = 0;  // Prescaler = 1
	} 
	else if (twbrValue <= 40) 
	{
		twpsBits = 1;  // Prescaler = 4
		twbrValue /= 4;
	} 
	else if (twbrValue <= 160)
    {
		twpsBits = 2;  // Prescaler = 16
		twbrValue /= 16;
	} 
	else 
	{
		twpsBits = 3;  // Prescaler = 64
		twbrValue /= 64;
	}
	// Set the TWBR and TWPS bits
	TWBR = (uint8_t)twbrValue;
	TWSR = (TWSR & 0xFC) | twpsBits;
	
	/* 2. Set Slave Address */
	TWAR |= ((I2C_MASTER_Slave_Address & 0x7F) << 1);
	
	/* 3. General Call Address Detection */
	TWAR |= (I2C_ENGC_Enable & 0x1);
	
	/* 4. Enable I2C */
	TWCR |= (1<<TWEN);

}

void I2C_deinit(void) {
	
	/*  Disable I2C */
	TWCR &= ~(1<<TWEN);
	
}


void I2C_generateStart(void) {
	
	/* Send START condition , clear TWINT flag  */
	TWCR |= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	/* Wait for TWINT Flag set. This indicates
	that the START condition has been
	transmitted */
	while (BIT_IS_CLEAR(TWCR,TWINT));

}

void I2C_generateStop(void) {
	
	/* Transmit STOP condition, Clear TWINT flag  */
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
}

void I2C_masterWrite(uint8_t data) {
	
	/* Load data into TWDR Register. Clear
	TWINT bit in TWCR to start transmission */ 
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	/* Wait for TWINT Flag set. This indicates
	that the data has been transmitted,
	and ACK/NACK has been received. */
	while (BIT_IS_CLEAR(TWCR,TWINT));

}

uint8_t I2C_masterReadWithACK(void) {
	
	uint8_t ret_value = 0;
	
	/* Clear TWINT Flag , Enable ACK */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	/* Received data can be read from the TWDR Register when the TWINT Flag
	is set high by hardware */
	while (BIT_IS_CLEAR(TWCR,TWINT));
	ret_value = TWDR;
	
	/* return data */
	return ret_value;
}

uint8_t I2C_masterReadWithNACK(void) {
	
	uint8_t ret_value = 0;
	
	/* Clear TWINT Flag , Enable NACK */
	TWCR = (1<<TWINT) | (1<<TWEN) ;
	/* Received data can be read from the TWDR Register when the TWINT Flag
	is set high by hardware */
	while (BIT_IS_CLEAR(TWCR,TWINT));
	ret_value = TWDR;
	
	/* return data */
	return ret_value;
	
}

uint8_t I2C_getStatus(void) {
	
	uint8_t status = 0;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = (TWSR & 0xF8) ;
	return status;
}
