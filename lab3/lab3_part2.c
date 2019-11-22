#include <eecs461.h>
#include <serial.h>
#include <adc.h>
#include <gpio.h>

void main(){
	//variables
	int i = 0;
	char numChannels = 8;
	char channelArray[8] = {0,1,2,3,4,5,6,7};
	uint16_t iAnalog[8];
	
	//inits
	initEECS461();
	initSIUADC0(numChannels, channelArray);
	initADC0_scan(numChannels, channelArray);

	while(1){
		for(i = 0; i < numChannels; i++){
			iAnalog[i] = (uint16_t)readADC0_scan((int)channelArray[i]);
		}
	}
}