/*
  EECS461
  Lab 4
  Original version by Scott Kenyon
  Updated July 6, 2014 by GPCz
*/
#include "MPC5643L.h"

#include "qd.h"
#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "worlds.h"
#include "eecs461.h"

#define ADC0_NUMCHANNELS 1
static char channelArray[ADC0_NUMCHANNELS] = {0};

int main(void) 
{
	int i = 0;
  int analogInput;
  float scaled;
	float torque;
	float angle = 0;
	float fDutyCycle = .5;
	float mDutyCycle = .5;
	int motor = 0;
	int filter = 1;
	int mFrequency = 20000;
	int fFrequency = 1000000;
	
  initEECS461();
	
  initQD();
	initSIUADC0(ADC0_NUMCHANNELS, channelArray);
  initADC0_oneshot(ADC0_NUMCHANNELS, channelArray);
  initPCRs();
  
	//configure wheel input angle
	SIU.PCR[0].B.PA = 1; // ALT[1]
	SIU.PCR[0].B.IBE = 1;
	
	//configure LEDS
	for(i=43; i<59; i++) { 
		SIU.PCR[i].B.APC = 0; 
		SIU.PCR[i].B.PA = 0;
		SIU.PCR[i].B.OBE = 1;
	}
	
  //Fill in Lab 4 code here
  
  //Initialize PWMs
  initPWM(motor, mFrequency, .6374);
	initPWM(filter, fFrequency, fDutyCycle);
  
  while(1){
		SIU.GPDO[43].R = 0x1;
		angle = updateAngle();
		torque = virtualWall(angle);
		outputTorque(torque);
		SIU.GPDO[43].R = 0x0;
		//analogInput = readADC0_oneshot((int)channelArray[0]);
		//mDutyCycle = ((float)analogInput - 13)/7850 + .24;
		//setPWM(motor, mFrequency, mDutyCycle);
	}
	
}
