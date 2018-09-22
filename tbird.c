#include "tbird.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>




void init_tbird(){
	
	DDRB = DDRD = 0xF0; // Ledek kimenetbe állítása
	DDRA = 0xFF;		// 7 szegmens kiement
	DDRC = 0xF8;		// RED kimenet sorok kimenet, oszlopok bemenet
	DDRG = 0xE0;		// Gombok bemenet
	DDRE = 0xFC;

}

void showOnLed(uint8_t x){

	PORTD = x;
	PORTB = (x << 4);
}

uint8_t oldMatrixValue(){
	
	uint8_t row;
	uint8_t state = 0;
	uint8_t value = 0;

	for(row = 8; row < 128; row <<= 1){

		PORTC = (row&0b01111000);

		_delay_ms(10);

		switch((~PINC) & 0b111){
			case 1:
				if(!state){
					if(row == 8) value = '1';
					else if(row == 16) value = '4';
					else if(row == 32) value = '7';
					else if(row == 64) value = '*';
					
					state = 1;
					break;
	 
				}
			case 2:
				if(!state){
					if(row == 8) value = '2'; 
					else if(row == 16) value = '5';
					else if(row == 32) value = '8';
					else if(row == 64) value = '0';
				
					state = 1;
					break;
				}
			case 4:
				if(!state){
					if(row == 8) value = '3'; 
					else if(row == 16) value = '6';
					else if(row == 32) value = '9';
					else if(row == 64) value = '#';
				
					state = 1;
					break;
				}
			default:
				state = 0;
				break;
		}
		if(state && value) return value;
	}
	
	return 0;
}

uint8_t MatrixValue(){
	const uint8_t key_map[12] = {69,14,13,11,22,21,19,38,37,35,70,67};
//	const uint8_t key_val[12] = {'0','1','2','3','4','5','6','7','8','9','*','#'};
	const uint8_t key_val[12] = {0,1,2,3,4,5,6,7,8,9,10,11};

	uint8_t	i,row = 0x08;

	while(row < 0x80){
		PORTC = (PORTC & 0x80) | row;
		_delay_ms(10);

		i = 0;
		while(i < 12){
			if(PINC == key_map[i]) return key_val[i];
			i++;	
		}
		row <<= 1;
	}
//	return 0;
	return 255;
}


uint8_t readButton(){

	return (PING & 0x1F);

}

