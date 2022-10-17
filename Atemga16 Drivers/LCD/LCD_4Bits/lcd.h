/*
 * lcd.h
 *
 * Created: 10/17/2022 5:16:15 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef LCD_H_
#define LCD_H_

/*------------------------------------ Includes --------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include <stdint-gcc.h>
#include "common_macros.h"
#include <stdio.h>
/*---------------------------------------- Definitions ------------------------------------------*/

#define LCD_DATA_BITS_MODE          4     //8-bits or 4-bits


#if (LCD_DATA_BITS_MODE == 4)
// You have to define just one of them and undef the other
#define MOST_SIGNIFICANT_BITS
#undef  LEAST_SIGNIFICANT_BITS
#endif


#define LCD_DATA_PORT_DIR           DDRC
#define LCD_DATA_PORT_OUT           PORTC

#define LCD_CTRL_PORT_DIR           DDRD
#define LCD_CTRL_PORT_OUT           PORTD

#define RS                          PD4
#define RW                          PD5
#define E                           PD6


#define SET_LCD_ONE_LINE_EIGHT_BIT_MODE         0x30
#define SET_LCD_TWO_LINE_EIGHT_BIT_MODE         0x38
#define SET_LCD_ONE_LINE_FOUR_BIT_MODE          0x20
#define SET_LCD_TWO_LINE_FOUR_BIT_MODE          0x28
#define CLEAR_DISPLAY                           0x01
#define SET_CURSOR_POSITION                     0x80
#define DISPLAY_ON_CURSOR_OFF                   0x0C
#define DISPLAY_ON_CURSOR_ON                    0x0E
#define DISPLAY_ON_CURSOR_BLINKING              0x0F
#define FOUR_BITS_DATA_MODE                     0x02


/*----------------------------------------- Functions ------------------------------------*/
void LCD_init(void);

void LCD_sendCommand(uint8_t command);

void LCD_displayCharacter(uint8_t data);

void LCD_displayString(const uint8_t *String);

void LCD_goToRowColumn(uint8_t row,uint8_t col);

void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *String);

void LCD_clearScreen(void);

void LCD_integrToString(uint32_t data);






#endif /* LCD_H_ */