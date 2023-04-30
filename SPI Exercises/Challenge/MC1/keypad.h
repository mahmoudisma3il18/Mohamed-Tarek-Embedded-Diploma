/*
 * keypad.h
 *
 * Created: 10/16/2022 8:06:15 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*-------------------------------------Includes ------------------------------------------*/

#include <stdint-gcc.h>
#include <avr/io.h>
#include "common_macros.h"
#include <util/delay.h>

/*------------------------------------- Defintions --------------------------------------*/

#define NO_OF_COLS    4
#define NO_OF_ROWS    4

#define KEYPAD_PORT_DIR  DDRA   
#define KEYPAD_PORT_IN   PINA
#define KEYPAD_PORT_OUT  PORTA


#if (NO_OF_COLS == 4)


const static uint8_t keypad [NO_OF_ROWS][NO_OF_COLS] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

#elif (NO_OF_COLS == 3)

const static uint8_t keypad [NO_OF_ROWS][NO_OF_COLS] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
};

#endif



uint8_t KEYPAD_getPressedKey();
/*--------------------------------------------------------------------
Description : its returns the value of button pressed
----------------------------------------------------------------------*/




#endif /* KEYPAD_H_ */