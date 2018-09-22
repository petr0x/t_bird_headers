#include "tbird.h"
#include "lcd.h"

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>



void LCD_init(void){

	_delay_ms(20);

	DDRF |= 0x0E;
	DDRE |= 0xF0;

	_delay_ms(20);
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(0x28);		// Init 4 bit
	LCD_sendCommand(0x0C);
	LCD_sendCommand(0x01);

	_delay_ms(100);


}	

void LCD_sendEnable(void){
	//_delay_ms(1);					// lejebb kell venni
	CTRL |= (1 << ENABLE);
	//_delay_ms(1);
	CTRL &= ~(1 << ENABLE);
}

void LCD_sendCommand(uint8_t command){

	LCD_waitBusy();

	CTRL &= ~(1 << RS);
	CTRL &= ~(1 << RW);

	DATA = (command&0xF0);
	LCD_sendEnable();
	DATA = ((command<<4)&0xF0);
	LCD_sendEnable();

}

void LCD_sendData(uint8_t data){

	LCD_waitBusy();

	CTRL |= (1 << RS);
	CTRL &= ~(1 << RW);

	DATA = (data&0xF0);
	LCD_sendEnable();
	DATA = ((data<<4)&0xF0);
	LCD_sendEnable();
}

void LCD_sendString(uint8_t *str){
	uint8_t i;
	for(i = 0; str[i] != 0; i++){
		LCD_sendData(str[i]);
	}
}

void LCD_setCursor(uint8_t row, uint8_t pos){
	if(row < 4 && pos < 16){
		switch(row){
			case 0: LCD_sendCommand(0x80+pos); break;
			case 1: LCD_sendCommand(0xC0+pos); break;
			case 2: LCD_sendCommand(0x90+pos); break;
			case 3: LCD_sendCommand(0xD0+pos); break;
		}
	}
}

void LCD_clearScreen(void){
	LCD_sendCommand(0x01);
	LCD_setCursor(0,0);
}

void LCD_waitBusy(void){
	
	DDRE &= 0x0F;

	CTRL &= ~(1 << RS);
	CTRL |= (1 << RW);
	CTRL |= (1 << ENABLE);

	while((PINE >> 7)){

		CTRL &= ~(1 << ENABLE);
		CTRL |= (1 << ENABLE);
		_delay_ms(1);

	}

	CTRL &= ~(1 << ENABLE);
	DDRE |= 0xF0;
}
