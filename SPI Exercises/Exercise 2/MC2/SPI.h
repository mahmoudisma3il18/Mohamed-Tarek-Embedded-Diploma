/*
 * SPI.h
 *
 * Created: 4/29/2023 12:02:05 AM
 *  Author: Mahmoud Ismail
 */ 


#ifndef SPI_H_
#define SPI_H_


/*----------------------------------------------- Includes ---------------------------------------------------*/
#include <avr/io.h>
#include "common_macros.h"

/*----------------------------------------------- Defines ----------------------------------------------------*/

/* Specifies the SPI operating mode */
#define SPI_Device_Mode_SLAVE                                (uint8_t)0x00
#define SPI_Device_Mode_MASTER                               (uint8_t)(1<<MSTR)

/* Specifies LSB or MSB */
#define SPI_Frame_Format_MSB_transmitted_first               (uint8_t)0x00
#define SPI_Frame_Format_LSB_transmitted_first               (uint8_t)(1<<DORD)

/* Specifies the clock polarity */
#define SPI_CLKPolarity_LOW_when_idle                        (uint8_t)0x00
#define SPI_CLKPolarity_HIGH_when_idle                       (uint8_t)(1<<CPOL)

/* Specifies the clock phase */
#define SPI_Clock_Phase_1EDGE_sample                         (uint8_t)0x00
#define SPI_Clock_Phase_1EDGE_setup                          (uint8_t)(1<<CPHA)


#define SPI_IRQ_Enable                                       (uint8_t)(1<<SPIE)
#define SPI_IRQ_Disable                                      (uint8_t)0x00



/*----------------------------------- Enums -------------------------------------*/
typedef enum {
	
	fosc_4   = 0x00,
	fosc_16  = 0x01,
	fosc_64  = 0x02,
	fosc_128 = 0x03
	} SPI_BaudRatePrescaler;
	
	
/*---------------------------- Structs -----------------------------------------*/

/* Configuration structure */
typedef struct
{

	uint8_t        			  	Device_Mode;     		  //  Specifies the SPI operating mode  @ref SPI_Device_Mode

	uint8_t 				  	Frame_Format;			  // Specifies LSB or MSB   @ref SPI_Frame_Format

	uint8_t 				  	CLKPolarity ;			  // @ref SPI_CLKPolarity

	uint8_t 				  	CLKPhase ;				  //@ref SPI_CLKPhase

	SPI_BaudRatePrescaler 	    SPI_BAUDRATEPRESCALER;  	/*Specifies the Baud Rate prescaler value which will be
															used to configure the transmit and receive SCK clock.
															This parameter can be a value of @ref SPI_BAUDRATEPRESCALER
															@note The communication clock is derived from the master
															clock. The slave clock does not need to be set.*/
															// Take Care you have to Conigure RCC to enter the correct clock to APB2 >>> to SPI

	uint8_t				 IRQ_Enable;			//@ref SPI_IRQ_Enable

}SPI_Config;


/*--------------------------------------------- Function Pro types ----------------------------------*/


/* Intialiaze SPI */
void SPI_init(SPI_Config *ptr_config);


/* Send  Data */
void SPI_sendByte(uint8_t data);

/* Recieve Data */
uint8_t SPI_receiveByte(void);


/* Send array of uint8_t */
void SPI_sendString(uint8_t* p_data);


/* Receive array of uint8_t */
void SPI_receiveString(uint8_t* p_data);

/* Select Slave */
void SPI_slaveSelect(uint8_t PORT_ID,uint8_t PIN_ID);



/* Unselect Slave */
void SPI_slaveUnselect(uint8_t PORT_ID,uint8_t PIN_ID);
	





#endif /* SPI_H_ */