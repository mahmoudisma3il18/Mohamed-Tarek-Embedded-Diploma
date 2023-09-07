/*
 * external_eeprom.h
 *
 * Created: 9/6/2023 4:34:34 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

/*------------------------------ Includes -----------------------------*/
#include "I2C.h"

/*------------------------------ Defines ------------------------------*/
#define SUCCESS                0x01UL
#define ERROR                  0x00UL


/*---------------------------- Function Prototypes --------------------*/

/* Initializes EEPROM with Specified I2C SCL Frequency */
void EEPROM_init(void);

/* Write byte at given location , returns success if byte is written successfully 
and error if its not written */
uint8_t EEPROM_writeByte(uint16_t address , uint8_t data);

/* Reads data and store it in pointer and return Success if its done else it returns ERROR */
uint8_t EEPROM_readByte(uint16_t address , uint8_t *data);

/* Write Sequential of size 16 byte(page) */
uint8_t EEPPROM_writePage(uint16_t address , uint8_t *data , uint8_t size);


/* Read Page of EEPROM */
uint8_t EEPROM_readPage(uint16_t address , uint8_t *data , uint8_t size);







#endif /* EXTERNAL_EEPROM_H_ */