#include "tbird.h"
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>



void storeInArray(uint8_t* array, uint8_t x){   
	 uint8_t i;									// [0][0][0][0] <-1
	 for(i=3; i>0; i--){						// [0][0][0][1] <-2
		 array[i]=array[i-1];					// [0][0][1][2]
	 }											// [1][2][3][4] <-5
	 array[0]=x;								// [2][3][4][5]
}

void storeInArray2(uint8_t* array, uint8_t x){	//[0][0][0][0] <-1
	static uint8_t j = 4;						//[1][0][0][0] <-2
	j--;										//[1][2][0][0]
	array[j]=x;									//[1][2][3][4] <-5
	if(j==0)j=4;								//[5][2][3][4]
}	

void init_interrupt(void){	//timer comparátorral (128), 8 as előosztás
	TCCR0 = 0b011;  // 1024 as előosztás
	TIMSK = 3;		// enable compare and ovf interrupt
	OCR0 = 128;		// compare regiszter feltöltése
	sei();
}

//ISR(TIMER0_COMP_vect){
	//
//}
//ISR(TIMER0_OVF_vect){
//
//}