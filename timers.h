/*
 * timers.h
 *
 * Created: 2018. 09. 24. 22:23:40
 *  Author: pvarga
 */ 


#ifndef TIMERS_H_INCLUDED
#define TIMERS_H_INCLUDED

#include <stdint.h>


static uint8_t PWM0_VAL;
static uint8_t PWM1_VAL;
static uint8_t PWM2_VAL;
static uint8_t PWM3_VAL;
static uint8_t PWM4_VAL;

static uint8_t *PWM0_PORT;
static uint8_t *PWM1_PORT;
static uint8_t *PWM2_PORT;
static uint8_t *PWM3_PORT;
static uint8_t *PWM4_PORT;

static uint8_t PWM0_PIN;
static uint8_t PWM1_PIN;
static uint8_t PWM2_PIN;
static uint8_t PWM3_PIN;
static uint8_t PWM4_PIN;

static uint8_t TIMER0_PWM_COUNTER;

void init_PWM_TIMER1();
void init_timer0_virtual_pwm(void);
void virtualPWM0(uint8_t * port, uint8_t pin, uint8_t val);
void virtualPWM1(uint8_t * port, uint8_t pin, uint8_t val);
void virtualPWM2(uint8_t * port, uint8_t pin, uint8_t val);
void virtualPWM3(uint8_t * port, uint8_t pin, uint8_t val);
void virtualPWM4(uint8_t * port, uint8_t pin, uint8_t val);



#endif /* TIMERS_H_ */