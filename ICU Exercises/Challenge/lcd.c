/*
 * lcd.c
 *
 * Created: 10/17/2022 5:16:24 PM
 *  Author: Mahmoud Ismail
 */ 
#include "lcd.h"

void LCD_init()
{
	
	LCD_CTRL_PORT_DIR |= (1<<RS) | (1<<RW) | (1<<E);
	
	#if (LCD_DATA_BITS_MODE == 4)
	  #ifdef MOST_SIGNIFICANT_BITS
	    LCD_DATA_PORT_DIR |= 0xF0;
	  #else
	    LCD_DATA_PORT_DIR |= 0x0F;
      #endif
	  LCD_sendCommand(FOUR_BITS_DATA_MODE);
	  LCD_sendCommand(SET_LCD_TWO_LINE_FOUR_BIT_MODE);
	#elif (LCD_DATA_BITS_MODE == 8)
      LCD_DATA_PORT_DIR = 0xFF;
	  LCD_sendCommand(SET_LCD_TWO_LINE_EIGHT_BIT_MODE);
    #endif
	
	LCD_sendCommand(DISPLAY_ON_CURSOR_BLINKING);
	LCD_sendCommand(CLEAR_DISPLAY);
	
}

void LCD_sendCommand(uint8_t command)
{
	CLEAR_BIT(LCD_CTRL_PORT_OUT,RS);
	CLEAR_BIT(LCD_CTRL_PORT_OUT,RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT_OUT,E);
	_delay_ms(1);
	
	#if (LCD_DATA_BITS_MODE == 4)
	
      #ifdef MOST_SIGNIFICANT_BITS
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0x0F) | (command & 0xF0);
	  #else
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0xF0) | (command & 0x0F);
      #endif    
	  _delay_ms(1);
	  CLEAR_BIT(LCD_CTRL_PORT_OUT,E);
	  _delay_ms(1);
	  SET_BIT(LCD_CTRL_PORT_OUT,E);
	  _delay_ms(1);
	  #ifdef MOST_SIGNIFICANT_BITS
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0x0F) | ((command & 0x0F)<<4);
	  #else
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0xF0) | ((command & 0xF0)>>4);
	  #endif
    #elif (LCD_DATA_BITS_MODE == 8)
	  LCD_DATA_PORT_OUT = command;
    #endif
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT_OUT,E);
	_delay_ms(1);
}

void LCD_displayCharacter(uint8_t data)
{
	SET_BIT(LCD_CTRL_PORT_OUT,RS);
	CLEAR_BIT(LCD_CTRL_PORT_OUT,RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT_OUT,E);
	_delay_ms(1);
	
	#if (LCD_DATA_BITS_MODE == 4)
	  #ifdef MOST_SIGNIFICANT_BITS
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0x0F) | (data & 0xF0);
	  #else
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0xF0) | (data & 0x0F);
	  #endif
	  _delay_ms(1);
	  CLEAR_BIT(LCD_CTRL_PORT_OUT,E);
	  _delay_ms(1);
	  SET_BIT(LCD_CTRL_PORT_OUT,E);
	  _delay_ms(1);
	  #ifdef MOST_SIGNIFICANT_BITS
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0x0F) | ((data & 0x0F)<<4);
	  #else
	    LCD_DATA_PORT_OUT = (LCD_DATA_PORT_OUT & 0xF0) | ((data & 0xF0)>>4);
	  #endif
	#elif (LCD_DATA_BITS_MODE == 8)
	  LCD_DATA_PORT_OUT = data;
	#endif
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT_OUT,E);
	_delay_ms(1);
}

void LCD_displayString(const uint8_t *String)
{
	
	while((*String) != '\0')
	{
		LCD_displayCharacter(*String);
		String++;
		
	}
	
}

void LCD_goToRowColumn(uint8_t row,uint8_t col)
{
	uint8_t Adrreses = 0x00;
	
	switch(row)
	{
		case 0 :
		Adrreses = col;
		break;
		
		case 1:
		Adrreses = (0x40) + col;
		break;
	}
	
	LCD_sendCommand(Adrreses | SET_CURSOR_POSITION);
	

}

void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *String)
{
	LCD_goToRowColumn(row,col);
	LCD_displayString(String);
}

void LCD_clearScreen()
{
	LCD_sendCommand(CLEAR_DISPLAY);
}

void LCD_integrToString(uint32_t data)
{
	uint8_t buffer[4]={0};
	sprintf(buffer,"%d",data);
	LCD_displayString(buffer);
}
