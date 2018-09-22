#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

#include <stdint.h>

#define DATA PORTE
#define CTRL PORTF
#define ENABLE PORTF3
#define RW PORTF2
#define RS PORTF1

void LCD_init(void);
void LCD_sendEnable(void);
void LCD_sendCommand(uint8_t);
void LCD_sendData(uint8_t);
void LCD_sendString(uint8_t*);
void LCD_setCursor(uint8_t, uint8_t);
void LCD_clearScreen(void);
void LCD_waitBusy(void);
#endif
