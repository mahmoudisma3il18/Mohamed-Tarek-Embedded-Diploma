/*
 * lm35_sensor.h
 *
 * Created: 10/19/2022 1:47:47 PM
 *  Author: modyb
 */ 


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

/*-------------------------- Includes ----------------------------------------*/

#include <stdint-gcc.h>


/*------------------------------ Definitions ----------------------------------*/

#define SENSOR_MAX_TEMP       150
#define ADC_REF_VOLTAGE       5
#define ADC_MAX_VALUE         1023
#define SENSOR_MAX_VOLTAGE    1.5
#define SENSOR_CHANNEL_ID     2

uint8_t LM35_getTempertaure(void);



#endif /* LM35_SENSOR_H_ */