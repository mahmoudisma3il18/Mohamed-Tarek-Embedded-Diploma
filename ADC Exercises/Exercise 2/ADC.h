/*
 * ADC.h
 *
 * Created: 10/17/2022 10:33:28 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef ADC_H_
#define ADC_H_


/*--------------------------------------- Includes -------------------------------------*/
#include <avr/io.h>
#include "common_macros.h"
#include <stdint-gcc.h>

/*------------------------------------ Enums --------------------------------------------*/

typedef enum{
	Channel0_ID,
	Channel1_ID,
	Channel2_ID,
	Channel3_ID,
	Channel4_ID,
	Channel5_ID,
	Channel6_ID,
	Channel7_ID
	}ADC_Channel_ID;


/*---------------------------------- Functions Prototypes -------------------------------*/

void ADC_init(void);

uint16_t ADC_readChanel(ADC_Channel_ID channelId);



#endif /* ADC_H_ */