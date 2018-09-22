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
uint8_t matrixValue();
uint8_t readButton();

#endif
