/*
 * Lm35.c
 *
 * Created: 3/10/2023 8:41:23 PM
 *  Author: Mahmoud Ismail
 */ 

#include "Lm35.h"

uint8_t LM35_getTemp() {
	
	uint8_t temp ; // Var for temp
	
	uint16_t adc_value = ADC_readChannel(2); // Read ADC
	
	temp = (uint8_t)(((uint32_t)adc_value*SENSOR_MAX_TEMP*REF_VOLTAGE)/(ADC_MAX_VALUE*SENSOR_MAX_VOLTAGE));
	
	return temp;
	
}
