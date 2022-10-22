/*
 * ADC.c
 *
 * Created: 10/17/2022 10:32:59 PM
 *  Author: Mahmoud Ismail
 */ 

#include "ADC.h"

volatile uint16_t adc_value;

ISR(ADC_vect)
{
	adc_value = ADC;
}

void ADC_init()
{
	
	ADMUX = 0x00; 
	
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0)|(1<<ADIE);
	
}

void ADC_readChanel(ADC_Channel_ID channelId)
{
	channelId &= 0x07; // Must be form 0 to 7;
	ADMUX &= 0xE0;
	ADMUX |= channelId;
	SET_BIT(ADCSRA,ADSC);
	
	
}
