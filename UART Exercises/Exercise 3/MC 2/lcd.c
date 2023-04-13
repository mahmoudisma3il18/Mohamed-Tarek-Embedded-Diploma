/*
 * lcd.c
 *
 * Created: 10/17/2022 2:28:35 PM
 *  Author: Mahmoud Ismail
 */ 

/*------------------------------------ Includes------------------------------------*/

#include "lcd.h"

/*--------------------------------- Functions --------------------------------------*/

void LCD_init()
{
	
	LCD_DATA_PORT_DIR = 0xFF ; 
	LCD_CTRL_PORT_DIR |= (1<<RS) | (1<<RW) | (1<<E);
	
	LCD_sendCommand(SET_LCD_TWO_LINE_EIGHT_BIT_MODE);
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
	LCD_DATA_PORT_OUT = command;
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
	LCD_DATA_PORT_OUT = data;
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
