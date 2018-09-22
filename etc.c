#include <stdint.h>


void storeInArray(uint8_t* array, uint8_t x){   //hasznos 7szegmenses kijelzéshez számok tárolására (jobbról shiftel ballra a kiírás)
	uint8_t i;
	 for(i=3; i>0; i--){
		 array[i]=array[i-1];
	 }
	 array[0]=x;	
}