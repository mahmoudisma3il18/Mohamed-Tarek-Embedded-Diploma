/*
 * gpio.h
 *
 * Created: 10/16/2022 2:03:00 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint-gcc.h>
#include "common_macros.h"
#include <avr/io.h>


/*--------------------------------------------Definitions ---------------------------*/

#define PIN0_ID    0x00
#define PIN1_ID    0x01
#define PIN2_ID    0x02
#define PIN3_ID    0x03
#define PIN4_ID    0x04
#define PIN5_ID    0x05
#define PIN6_ID    0x06
#define PIN7_ID    0x07

#define PORTA_ID  0x00
#define PORTB_ID  0x01
#define PORTC_ID  0x02
#define PORTD_ID  0x03  


#define LOGIC_HIGH   0x01
#define LOGIC_LOW    0x00



/*--------------------------------- Enums---------------------------------*/

typedef enum{
	PIN_INPUT,
	PIN_OUTPUT
	}GPIO_PinDirectionType;
	
typedef enum{
	PORT_INPUT,
	PORT_OUTPUT = 0xFF
    }GPIO_PortDirectionType;
	
	
/*------------------------------------Functions Prototypes---------------------------------*/

void GPIO_setupPinDirection(uint8_t port_num,uint8_t pin_num , GPIO_PinDirectionType direction); 

void GPIO_writePin(uint8_t port_num,uint8_t pin_num,uint8_t value);

uint8_t GPIO_readPin(uint8_t port_num,uint8_t pin_num);

void GPIO_setupPortDirection(uint8_t port_number,GPIO_PortDirectionType direction);

void GPIO_writePort(uint8_t port_num,uint8_t value);

uint8_t GPIO_readPort(uint8_t port_num)	;




#endif /* GPIO_H_ */