/*
  EECS461
  Lab 6
  Original version by Scott Kenyon
  Updated July 6, 2014 by GPCz
*/

#include<eecs461.h>
#include<serial.h>
#include "qd.h"
#include "pwm.h"
#include "pit.h"
#include "IntcInterrupts.h"
#include "gpio.h"
#include "worlds.h"

#define T 0.001
#define ENTER_CRITICAL() asm (" wrteei 0"); /* disable all interrupts */
#define LEAVE_CRITICAL() asm (" wrteei 1"); /* enable all interrupts */

void wallDamper(void)
{
	/* ISR for the wall-damper system */
/* fill in */
	static float oldAng;
	static float newAng;
	float velocity;
	float torque;
	
	//update
	newAng = updateAngle();
	
	//velocity = (angle new - angle old)/T
	velocity = (newAng - oldAng)/T;
	
	torque = -virtualWallDamper(newAng, velocity);
	outputTorque(torque);
	oldAng = newAng;
	//Make sure to clear interrupt flag
	
	/* Clear interupt flag */
	PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF = 1;
}

void springDamper(void)
{
	/* ISR for the spring-damper system */
/* fill in */
	//Make sure to clear interrupt flag
	static float oldAng;
	static float newAng;
	float velocity;
	float torque;
	
	//update
	newAng = updateAngle();
	
	//velocity = (angle new - angle old)/T
	velocity = (newAng - oldAng)/T;
	
	torque = virtualSpringDamper(newAng, velocity);
	outputTorque(torque);
	oldAng = newAng;
	//Make sure to clear interrupt flag
	
	/* Clear interupt flag */
	PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF = 1;
}

void springMass(void)
{
	/* ISR for the spring-mass system */
/* fill in */
	static float newAng;
	float torque;
	
	//update
	newAng = updateAngle();
	
	torque = virtualSpringMass(newAng);
	outputTorque(torque);
	//Make sure to clear interrupt flag
	
	/* Clear interupt flag */
	PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF = 1;
}

void springMassDamper(void)
{
	/* ISR for the spring-mass-damper system */
/* fill in */
	static float oldAng;
	static float newAng;
	float velocity;
	float torque;
	
	//update
	newAng = updateAngle();
	
	//velocity = (angle new - angle old)/T
	velocity = (newAng - oldAng)/T;
	
	torque = -virtualSpringMassDamper(newAng, velocity);
	outputTorque(torque);
	oldAng = newAng;
	//Make sure to clear interrupt flag
	
	/* Clear interupt flag */
	PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF = 1;
}

void knobIndents(void)
{
	/* ISR for the virtual knob system */
/* fill in */
	static float oldAng;
	static float modAng;
	static float angle;
	float velocity;
	float torque;
	
	//update
	angle = updateAngle();
	//velocity = (angle new - angle old)/T
	velocity = (angle - oldAng)/T;
	modAng = (int)angle%30;
	
	torque = -virtualKnob(modAng, velocity);
	outputTorque(torque);
	oldAng = angle;
	//Make sure to clear interrupt flag
	
	/* Clear interupt flag */
	PIT.CH[WORLDISR_PIT_CHANNEL].TFLG.B.TIF = 1;
}

void main()
{
	
  
  
  initEECS461();
  initQD();
	
  initPCRs();
  initGPDI(5);
  initPWM(MOTOR_SUBMODULE,MOTOR_FREQUENCY, 0.50f);
  initPWM(FILTER_SUBMODULE,FILTER_FREQUENCY, 0.50f);
  SIUL.PCR[43].B.PA = 0;
  SIUL.PCR[43].B.OBE = 1;
  
  
  
  //Fill in the interrupt routine for the particular part of the lab
  initPIT(WORLDISR_PIT_CHANNEL, WORLDISR_FREQUENCY, &knobIndents	, 0xC);
  INTC.CPR.R = 0x0A;
  enable_interrupts();

		//setup dip switch 5 to control damping on/off
		SIU.PCR[5].B.APC = 0; /* GPIO */ 
		SIU.PCR[5].B.PA = 0; /* GPIO */ 
		SIU.PCR[5].B.IBE = 1; /* Input */  
	
  
  while(1){
		
	}
}