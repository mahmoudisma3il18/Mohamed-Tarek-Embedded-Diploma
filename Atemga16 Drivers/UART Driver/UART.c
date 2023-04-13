/*
 * UART.c
 *
 * Created: 4/13/2023 12:24:36 AM
 *  Author: Mahmoud Ismail
 */ 


/*-------------------------------- Includes -----------------------------------*/

#include "UART.h"

/*
Description : Initialize UART driver
*/
void UART_init(UART_BaudRate br) {
	
	/*  Set Baud Rate  */
	uint16_t br_value = (((F_CPU / (br * 16UL))) - 1) ; // Calculates value to be put in baud rate register
	UBRRH = br_value>>8;
	UBRRL = br_value;
	
	/*  Enable Receiver and Transmitter */
	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	/*  Set Frame Format and Mode :
	    1. Asynchronous Mode
		2. No Parity Bit
		3. 1 Stop Bit
		4. 8-bit Data 
	*/
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}


/*
Description : Send One Byte
*/
void UART_sendByte(uint8_t data) {
	
	/* Wait for empty Transmit buffer */
	while(BIT_IS_CLEAR(UCSRA,UDRE));
	
	/* Put data into buffer and send data */
	UDR = data;
}

/*
Description : Receive One Byte of Data
*/
uint8_t UART_recieveByte(void) {
	
	uint8_t recieved_data ;  /* Var to hold received data */
	
	/* Wait for data to be received */
	while(BIT_IS_CLEAR(UCSRA,RXC));
	
	recieved_data = UDR;  /* Get  received data from buffer */
	
	return recieved_data;
}

/*
Description : Send array of bytes (String)
*/
void UART_sendString(uint8_t *p_data) {
	
	while(*p_data != '\0')
	{
		UART_sendByte(*p_data);  /* Send Byte of data */
		p_data++;                /* Increment Pointer */
	}
}

/*
Description : Receive array of chars (String)
*/
void UART_recieveString(uint8_t *String) {
	
	
	uint8_t i = 0;                          /*  Counter */
	
	String[i] = UART_recieveByte();         /*  Receive Data from UART  */
	 
	while(String[i] != '\n')                /*  Check for end of String  */
	{
		i++;                                /*  Increment Counter */
		String[i] = UART_recieveByte();
	}
	String[i] = '\0';                      /*    Termnating Char  */
	
}
