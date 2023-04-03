/*
 * Lm35.h
 *
 * Created: 3/10/2023 8:41:37 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef LM35_H_
#define LM35_H_

/*--------------------------------- Includes -----------------------------------------*/

#include "ADC.h"
#include <stdint-gcc.h>
#include "common_macros.h"
#include <avr/io.h>

/*--------------------------------------- Defines ------------------------------------------------------*/

#define SENSOR_CHANNEL_ID     Channel2_ID
#define SENSOR_MAX_TEMP       150
#define REF_VOLTAGE           2.56
#define ADC_MAX_VALUE         1023
#define SENSOR_MAX_VOLTAGE    1.5

/*---------------------------------- Function Prototypes -----------------------------------------*/

/*
Description : Returns Temp
*/
uint8_t LM35_getTemp();







#endif /* LM35_H_ */