#include <eecs461.h>
#include <serial.h>
#include <adc.h>
#include <gpio.h>

void main(){
	//variables
	char numChannels = 1;
	char channelArray[1] = {0};
	uint16_t iAnalog = 0;
	
	//inits
	initEECS461();
	initSIUADC0(numChannels, channelArray);
	initADC0_oneshot(numChannels, channelArray);

	while(1)
		iAnalog = (uint16_t)readADC0_oneshot((int)channelArray[0]);
}