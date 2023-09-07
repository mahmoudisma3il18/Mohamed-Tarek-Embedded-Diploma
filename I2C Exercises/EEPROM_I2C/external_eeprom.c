/*
 * external_eeprom.c
 *
 * Created: 9/6/2023 4:34:02 PM
 *  Author: Mahmoud Ismael
 */ 
#include "external_eeprom.h"

void EEPROM_init(void) {
	
	/* Initialize I2C with give Frequency */
	I2C_init(I2C_SCLK_FM_400k);
}

uint8_t EEPROM_writeByte(uint16_t address , uint8_t data) {
	
	/* Send Start Condition */
	I2C_generateStart();
	
	/* Error if Start condition is not send Successfully */
	if(I2C_getStatus() != I2C_START_SENT)
		return ERROR;
	
	/* R/W : 0 (Write)
	Send MSB (A10,A9,A8) of address
	Send 0b1010 Id of EEPROM
	*/	
	I2C_masterWrite((uint8_t)((0xA0) | ((address & 0x700) >> 7)));	
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_SLA_W_ACK)
		return ERROR;
		
	/* Send A0 to A7 of address */	
	I2C_masterWrite((uint8_t)address);
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_DATA_SENT_ACK )
		return ERROR;
		
	/* Send Data */
	I2C_masterWrite(data);
	
	/* Check if data send correctly */
	if(I2C_getStatus() != I2C_DATA_SENT_ACK )	
		return ERROR;
	
	/* Send Stop Condition */	
	I2C_generateStop();	
	
    return SUCCESS;
}

uint8_t EEPROM_readByte(uint16_t address , uint8_t *data) {
	
	/* Send Start Condition */
	I2C_generateStart();
	
	/* Error if Start condition is not send Successfully */
	if(I2C_getStatus() != I2C_START_SENT)
		return ERROR;
	
	/* R/W : 0 (Write)
	Send MSB (A10,A9,A8) of address
	Send 0b1010 Id of EEPROM
	*/	
	I2C_masterWrite((uint8_t)((0xA0) | ((address & 0x700) >> 7)));	
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_SLA_W_ACK)
		return ERROR;
		
	/* Send A0 to A7 of address */	
	I2C_masterWrite((uint8_t)address);
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_DATA_SENT_ACK )
		return ERROR;
		
	/* Send a Repeated Start */
	I2C_generateStart();
	
	/* Check if repeated start condition is successful */
	if (I2C_getStatus() != I2C_REP_START_SENT)
		return ERROR;
		
	/* R/W : 1 (Read)
	Send MSB (A10,A9,A8) of address
	Send 0b1010 Id of EEPROM
	*/	
	I2C_masterWrite((uint8_t)((0xA0) | ((address & 0x700) >> 7) | 0x01));	
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_SLA_R_ACK)
		return ERROR;	
		
	/* Read Data */	
	*data = I2C_masterReadWithNACK();	
	
	/* Check if data is read successfully */
	if (I2C_getStatus() != I2C_DATA_RECEIVED_NACK)
		return ERROR;

   /* Send Stop Condition */
   I2C_generateStop();
   
   return SUCCESS;
}


uint8_t EEPPROM_writePage(uint16_t address , uint8_t *data , uint8_t size) {
	
	/* Send Start Condition */
	I2C_generateStart();
	
	/* Error if Start condition is not send Successfully */
	if(I2C_getStatus() != I2C_START_SENT)
		return ERROR;
	
	/* R/W : 0 (Write)
	Send MSB (A10,A9,A8) of address
	Send 0b1010 Id of EEPROM */	
	I2C_masterWrite((uint8_t)((0xA0) | ((address & 0x700) >> 7)));
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_SLA_W_ACK)
		return ERROR;
		
	/* Send A0 to A7 of address */	
	I2C_masterWrite((uint8_t)address);
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_DATA_SENT_ACK )
		return ERROR;
		
	for (int i = 0 ; i < size ; i++)
	{
		/* Send Data */
		I2C_masterWrite(data[i]);
		
		/* Check if data send correctly */
		if(I2C_getStatus() != I2C_DATA_SENT_ACK )
		return ERROR;
	}
		
	/* Send Stop Condition */	
	I2C_generateStop();	
	
    return SUCCESS;
}

uint8_t EEPROM_readPage(uint16_t address , uint8_t *data , uint8_t size) {
	
	/* Send Start Condition */
	I2C_generateStart();
	
	/* Error if Start condition is not send Successfully */
	if(I2C_getStatus() != I2C_START_SENT)
		return ERROR;
	
	/* R/W : 0 (Write)
	Send MSB (A10,A9,A8) of address
	Send 0b1010 Id of EEPROM
	*/	
	I2C_masterWrite((uint8_t)((0xA0) | ((address & 0x700) >> 7)));	
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_SLA_W_ACK)
		return ERROR;
		
	/* Send A0 to A7 of address */	
	I2C_masterWrite((uint8_t)address);
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_DATA_SENT_ACK )
		return ERROR;
		
	/* Send a Repeated Start */
	I2C_generateStart();
	
	/* Check if repeated start condition is successful */
	if (I2C_getStatus() != I2C_REP_START_SENT)
		return ERROR;
		
	/* R/W : 1 (Read)
	Send MSB (A10,A9,A8) of address
	Send 0b1010 Id of EEPROM
	*/	
	I2C_masterWrite((uint8_t)((0xA0) | ((address & 0x700) >> 7) | 0x01));	
	
	/* Check if Slave address is sent successfully */
	if (I2C_getStatus() != I2C_SLA_R_ACK)
		return ERROR;	
		
	for (int i = 0 ; i < size - 1 ; i++)
	{
		/* Read Data */
		data[i] = I2C_masterReadWithACK();
		
		/* Check if data is read successfully */
		if(I2C_getStatus() != I2C_DATA_RECEIVED_ACK)
			return ERROR;
	}
	
	/* Read Data Last element and send NACK  */
	data[size-1] = I2C_masterReadWithNACK();
	
	/* Check if data is read successfully */
	if(I2C_getStatus() != I2C_DATA_RECEIVED_NACK)
		return ERROR;
	
   /* Send Stop Condition */
   I2C_generateStop();
   
   return SUCCESS;
}