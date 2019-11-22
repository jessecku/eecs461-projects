#include <eecs461.h>
#include <serial.h>
#include <qd.h>
#include <gpio.h>

//lab2 part1
void main(){
	int32_t counter = 0;
	int i; 
	unsigned char op1, op2;
	int result;
	int16_t temp = 0;
	
	initEECS461();
	initQD();
	
	SIU.PCR[0].B.PA = 1; // ALT[1]
	SIU.PCR[0].B.IBE = 1;
	
	/* configure output leds */ 
	for(i=43; i<59; i++) { 
		SIU.PCR[i].B.APC = 0; 
		SIU.PCR[i].B.PA = 0;
		SIU.PCR[i].B.OBE = 1;
	}
	
	while(1){
		counter = updateCounter();
		temp = counter >> 8;
		for(i = 43; i <59; i++){
			SIU.GPDO[i].R = temp & 0x1;
			temp = temp >>1;
		}
	}
}