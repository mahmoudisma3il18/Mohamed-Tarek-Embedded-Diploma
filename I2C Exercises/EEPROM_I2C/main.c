/*
 * EEPROM_I2C.c
 *
 * Created: 9/6/2023 4:23:08 PM
 * Author : modyb
 */ 


#define F_CPU   8000000


#include <avr/io.h>
#include <util/delay.h>
#include "external_eeprom.h"

uint8_t y[5];


int main(void)
{
   uint8_t val = 0;
   uint8_t x[] = {0xAA,0xBB,0xCC,0xDD,0xEE};
	   
   
   DDRD  = 0xFF;
   PORTD = 0x00;

   /* Init EEPROM */
   EEPROM_init();
   EEPROM_writeByte(0x0000, 0xF0); /* Write 0x0F in the external EEPROM */
   _delay_ms(10);
   EEPROM_readByte(0x0000, &val);  /* Read 0x0F from the external EEPROM */
   _delay_ms(10);
   EEPPROM_writePage(0x0000,x,5);
   _delay_ms(10);
   EEPROM_readPage(0x0000,y,5);
   while(1)
   {
	   PORTD = val; /* out the read value from the external EEPROM */
   }
   return 0;
}

