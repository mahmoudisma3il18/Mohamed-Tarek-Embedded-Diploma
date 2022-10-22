/*
 * ADC.c
 *
 * Created: 10/17/2022 10:32:59 PM
 *  Author: Mahmoud Ismail
 */ 

#include "ADC.h"

void ADC_init()
{
	
	ADMUX = 0x00; 
	
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
	
}

uint16_t ADC_readChanel(ADC_Channel_ID channelId)
{
	channelId &= 0x07; // Must be form 0 to 7;
	ADMUX &= 0xE0;
	ADMUX |= channelId;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
	
}
