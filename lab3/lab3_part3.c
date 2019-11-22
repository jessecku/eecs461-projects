#include <eecs461.h>
#include <serial.h>
#include <adc.h>
#include <gpio.h>

void main(){
	//variables
	int i = 0;
	char numChannels = 1;
	char channelArray[1] = {0};
	uint16_t iAnalog = 0;
	
	//inits
	initEECS461();
	initSIUADC0(numChannels, channelArray);
	initADC0_oneshot(numChannels, channelArray);

	/* configure output leds */ 
	for(i=43; i<59; i++) { 
		SIU.PCR[i].B.APC = 0; 
		SIU.PCR[i].B.PA = 0;
		SIU.PCR[i].B.OBE = 1;
	}
	
	while(1){
		SIU.GPDO[43].R = 0x1;
		iAnalog = (uint16_t)readADC0_oneshot((int)channelArray[0]);
		SIU.GPDO[43].R = 0x0;
	}
}