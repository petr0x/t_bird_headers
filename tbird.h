#ifndef TBIRD_H_INCLUDED
#define TBIRD_H_INCLUDED

#include <stdint.h>

#ifdef TBIRD3

#define F_CPU 8000000UL

#else 

#define F_CPU 16000000UL

#endif

void init_tbird(void);
void showOnLed(uint8_t);
void showOnSeg(uint8_t*);
void turnOnRed(void);
void turnOffRed(void);
void turnOnBlue(void);
void turnOffBlue(void);
void turnOnGreen(void);
void turnOffGreen(void);
uint8_t matrixValue(void);
uint8_t oldMatrixValue(void);
uint8_t readButton(void);

#endif
