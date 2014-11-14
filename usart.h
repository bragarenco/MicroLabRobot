#ifndef _USART_H_
#define _USART_H_


void USART_Init( unsigned int baud );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );

#endif
