/*
 * UART.h
 *
 * Created: 4/13/2023 12:24:49 AM
 *  Author: Mahmoud Ismail
 */ 


#ifndef UART_H_
#define UART_H_

/*--------------------------------------------------- Includes ------------------------------------------------*/

#include <avr/io.h>
#include <stdint-gcc.h>
#include <util/delay.h>
#include "common_macros.h"

/*------------------------------------------------ Enums ------------------------------------------------------*/

/* Only valid for 1MHz and Asynchronous Normal Mode */
typedef enum {
	BaudRate_2400  =  2400  ,
	BaudRate_4800  =  4800  ,
	BaudRate_9600  =  9600  ,
	BaudRate_14400 =  14400 ,
	BaudRate_19200 =  19200 ,
	BaudRate_28800 =  28800 ,
	BaudRate_38400 =  38400 ,
	}UART_BaudRate;


/*----------------------------------------------- Functions --------------------------------------------------*/

/*
Description : Initialize UART driver
*/
void UART_init(UART_BaudRate br);

/*
Description : Send One Byte
*/
void UART_sendByte(uint8_t data);

/*
Description : Receive One Byte of Data
*/
uint8_t UART_recieveByte(void);

/*
Description : Send array of bytes (String)
*/
void UART_sendString(uint8_t *p_data);

/*
Description : Receive array of chars (String)
*/
void UART_recieveString(uint8_t *String);






#endif /* UART_H_ */