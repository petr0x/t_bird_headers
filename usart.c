#include "tbird.h"
#include "usart.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

void UART0_init(uint16_t baud){

	baud = (F_CPU / 16 / baud - 1);

	UBRR0H = (baud>>8); //Set baud Rate
	UBRR0L = baud;
	
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);   //RX enable // TX enable // RX interrupt enable
	UCSR0C = (1 << USBS0) | (1 << UCSZ01) | (1 << UCSZ00);  // 1 start 1 stop 8 data bit

}

void UART1_init(uint16_t baud){

	baud = (F_CPU / 16 / baud - 1);

	UBRR1H = (baud>>8); //Set baud Rate
	UBRR1L = baud;
	
	UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1);   //RX enable // TX enable // RX interrupt enable
	UCSR1C = (1 << USBS1) | (1 << UCSZ11) | (1 << UCSZ10);  // 1 start 1 stop 8 data bit

}

void UART0_transmit(uint8_t data){

	if(!data) return;
	while (! (UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

uint8_t UART0_receive(void){

	while (! (UCSR0A & (1 << RXC)));
	return UDR0;
}

void UART0_print(uint8_t *str){
	unsigned char i;
	for(i = 0; str[i] != 0; i++){
		UART0_transmit(str[i]);
	}
}

void UART0_println(uint8_t *str){
	unsigned char i;
	for(i = 0; str[i] != 0; i++){
		UART0_transmit(str[i]);
	}
	UART0_transmit('\n');
	UART0_transmit('\r');
}

void UART1_transmit(uint8_t data){

	if(!data) return;
	while (! (UCSR1A & (1 << UDRE1)));
	UDR1 = data;
}

uint8_t UART1_receive(void){

	while (! (UCSR1A & (1 << RXC)));
	return UDR1;
}

void UART1_print(uint8_t *str){
	unsigned char i;
	for(i = 0; str[i] != 0; i++){
		UART1_transmit(str[i]);
	}
}

void UART1_println(uint8_t *str){
	unsigned char i;
	for(i = 0; str[i] != 0; i++){
		UART1_transmit(str[i]);
	}
	UART1_transmit('\n');
	UART1_transmit('\r');
}

// void RS485_init(void){

// 	DE_DDR |= (1 << DE_PIN);
// 	RE_DDR |= (1 << RE_PIN); 
// }

// void RS485_busToTransmit(void){

// 	DE_PORT |= (1 << DE_PIN);
// 	RE_PORT |= (1 << RE_PIN);
// }

// void RS485_busToRecieve(void){

// 	DE_PORT &= ~(1 << DE_PIN);
// 	RE_PORT &= ~(1 << RE_PIN);
// }