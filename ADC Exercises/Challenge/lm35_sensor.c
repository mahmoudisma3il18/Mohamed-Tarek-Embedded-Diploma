/*
 * lm35_sensor.c
 *
 * Created: 10/19/2022 1:47:29 PM
 *  Author: modyb
 */ 

#include "lm35_sensor.h"

uint8_t LM35_getTempertaure()
{
	uint8_t temp;
	ADC_readChanel(SENSOR_CHANNEL_ID);
	extern  uint16_t adc_value;
	
	temp = (uint8_t)(((uint32_t)adc_value * SENSOR_MAX_TEMP * ADC_REF_VOLTAGE) / (SENSOR_MAX_VOLTAGE * ADC_MAX_VALUE));
	
	return temp;
}