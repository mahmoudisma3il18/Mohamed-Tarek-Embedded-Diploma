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
	uint16_t adc_value;
	
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	
	temp = (uint8_t)((uint32_t)(adc_value * SENSOR_MAX_TEMP * ADC_REF_VOLTAGE)/(ADC_MAX_VALUE * SENSOR_MAX_VOLTAGE));
	
	return temp;
}