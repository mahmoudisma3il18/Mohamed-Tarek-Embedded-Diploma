/*
 * ADC.h
 *
 * Created: 3/6/2023 11:07:21 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef ADC_H_
#define ADC_H_

/*------------------------- Includes ---------------------------*/
#include <stdint-gcc.h>
#include <avr/io.h>
#include "common_macros.h"


/*----------------------- Typedefs -----------------------------*/

typedef enum{
	AREF        , // AREF, Internal Vref turned off
	AVCC = 0x40 , // AVCC with external capacitor at AREF pin
	Revrsed     ,
	Internal = 0xC0// Internal 2.56V Voltage Reference with external capacitor at AREF pin
	}ADC_ReferenceVolatge;

typedef enum {
	F_CPU_1    ,
	F_CPU_2    , // F_CPU/2
	F_CPU_4    , // F_CPU/4
	F_CPU_8    , // F_CPU/8
	F_CPU_16   , // F_CPU/16
	F_CPU_32   , // F_CPU_32
	F_CPU_64   , // F_CPU_64
	F_CPU_128 
	}ADC_Prescaler;
	
typedef enum {
	Channel0_ID,
	Channel1_ID,
	Channel2_ID,
	Channel3_ID,
	Channel4_ID,
	Channel5_ID,
	Channel6_ID,
	Channel7_ID
	}ADC_Channel_ID;
	
	
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;	
	
/*-------------------------------------- Function Prototypes ---------------------------------------*/

/*
Description : Initializes ADC
*/

void ADC_init(const ADC_ConfigType *config_ptr );

/*
Description : Reads value from chosen channel
*/

uint16_t ADC_readChannel(ADC_Channel_ID channel_id);

		



#endif /* ADC_H_ */