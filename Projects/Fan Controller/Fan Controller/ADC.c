/*
 * ADC.c
 *
 * Created: 3/6/2023 11:07:07 PM
 *  Author: Mahmoud Ismail
 */ 


#include "ADC.h"

void ADC_init(const ADC_ConfigType *config_ptr ) {
	
	
	SET_BIT(ADCSRA,ADEN); // Enable ADC

	ADMUX  |= (config_ptr->ref_volt) & 0xC0; // Set Reference Voltage
	
	ADCSRA |= (config_ptr->prescaler) & 0x07; // Set Frequency Prescaler

}

uint16_t ADC_readChannel(ADC_Channel_ID channel_id) {

	uint16_t retValue = 0;
	
	ADMUX |= (channel_id) & 0x1F; // Select Channel;
	
	SET_BIT(ADCSRA,ADSC); // Start Conversation 
	
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); // Loop until conversation is done
	
	SET_BIT(ADCSRA,ADIF); // Clear Bit
	
	retValue = ADC;
	
	return retValue;
	
}
