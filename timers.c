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

void init_timer0_virtual_pwm(void){
	#define TIMER0_PWM
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << CS00);
	TIMSK = (1 << TOIE0);
	sei();
}

void virtualPWM0(uint8_t * port, uint8_t pin, uint8_t val){
	#define PWM0
	*PWM0_PORT = port;
	PWM0_PIN = pin;
	PWM0_VAL = val;
}

void virtualPWM1(uint8_t * port, uint8_t pin, uint8_t val){
	#define PWM1
	*PWM1_PORT = port;
	PWM1_PIN = pin;
	PWM1_VAL = val;
}

void virtualPWM2(uint8_t * port, uint8_t pin, uint8_t val){
	#define PWM2
	*PWM2_PORT = port;
	PWM2_PIN = pin;
	PWM2_VAL = val;
}

void virtualPWM3(uint8_t * port, uint8_t pin, uint8_t val){
	#define PWM3
	*PWM3_PORT = port;
	PWM3_PIN = pin;
	PWM3_VAL = val;
}

void virtualPWM4(uint8_t * port, uint8_t pin, uint8_t val){
	#define PWM4
	*PWM4_PORT = port;
	PWM4_PIN = pin;
	PWM4_VAL = val;
}

#ifdef TIMER0_PWM

ISR(TIMER0_OVF_vect){
	TIMER0_PWM_COUNTER++;

	#ifdef PWM0

		if(TIMER0_PWM_COUNTER > PWM0_VAL){
			 *PWM0_PORT |= (1 << PWM0_PIN);
		}
		else{
			 *PWM0_PORT &= ~(1 << PWM0_PIN);
		}

	#endif

	#ifdef PWM1

		if(TIMER0_PWM_COUNTER > PWM1_VAL){
			 *PWM1_PORT |= (1 << PWM1_PIN);
		}
		else{
			 *PWM1_PORT &= ~(1 << PWM1_PIN);
		}

	#endif	

	#ifdef PWM2

		if(TIMER0_PWM_COUNTER > PWM2_VAL){
			 *PWM2_PORT |= (1 << PWM2_PIN);
		}
		else{
			 *PWM2_PORT &= ~(1 << PWM2_PIN);
		}

	#endif	

	#ifdef PWM3

		if(TIMER0_PWM_COUNTER > PWM3_VAL){
			 *PWM3_PORT |= (1 << PWM3_PIN);
		}
		else{
			 *PWM3_PORT &= ~(1 << PWM3_PIN);
		}

	#endif	

	#ifdef PWM4

		if(TIMER0_PWM_COUNTER > PWM4_VAL){
			 *PWM4_PORT |= (1 << PWM4_PIN);
		}
		else{
			 *PWM4_PORT &= ~(1 << PWM4_PIN);
		}

	#endif		
	if(TIMER0_PWM_COUNTER == 255) TIMER0_PWM_COUNTER=0;
}
#endif