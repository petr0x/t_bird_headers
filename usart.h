#ifndef USART_H_INCLUDED
#define USART_H_INCLUDED

#include <stdint.h>

#ifdef TBIRD3
//-----------TBIRD3 RS485 IO ----------
#define DE_DDR DDRE
#define DE_PORT PORTE
#define DE_PIN PE2

#define RE_DDR DDRD
#define RE_PORT PORTD
#define RE_PIN PC7
//-------------------------------------
#else
//------------TBIRD2 RS485 IO ---------
#define DE_DDR DDRD
#define DE_PORT PORTD
#define DE_PIN PD1

#define RE_DDR DDRD
#define RE_PORT PORTD
#define RE_PIN PD0

#endif 

void USART_init(uint16_t);
void USART_transmit(uint8_t);
uint8_t USART_receive(void);
void RS485_init(void);
void RS485_busToTransmit(void);
void RS485_busToRecieve(void);

#endif
