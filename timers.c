/*
 * timers.c
 *
 * Created: 2018. 09. 24. 22:23:20
 *  Author: pvarga
 */
 
#include "tbird.h"
#include "timers.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void init_PWM_TIMER1(){
	
	TCCR1A = (1 << COM1A1) | (0 << COM1A0)
			| (1 << COM1B1) | (0 << COM1B0)
			| (1 << COM1C1) | (0 << COM1C0)
			| (1 << WGM11) | (0 << WGM10);
			
	TCCR1B =  (1 << WGM13) | (1 << WGM12)
			| (1 << CS11) | (1 << CS10);
			
	ICR1 = 1000;
}
