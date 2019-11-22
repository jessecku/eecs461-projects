/*
   worlds.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Virtual Worlds

   Revision History
     2011-12-01  Jay Patel
     2014-02-24  Scott Kenyon
 */

 #include<eecs461.h>
#include<serial.h>
#include "qd.h"
#include "pwm.h"
#include "pit.h"
 
#include "worlds.h"
#include "gpio.h"
#include "typedefs.h"


//====================LAB 4================================
/***************************************************************************
 * Virtual Wall
 ***************************************************************************/
float virtualWall(float angle)
{
	float k = 500; // 500 N-mm per degree of wheel displacement from reference
	if(angle > 0) // puck pulled back to wall
		return -k*angle;
	else // puck moves freely
		return 0;
}

/***************************************************************************
 * Virtual Spring 
 ***************************************************************************/
float virtualSpring(float angle)
{
	float k = 10; // 10 N-mm per degree of wheel displacement from reference
	return -k*angle;
}

//====================LAB 6================================
/***************************************************************************
 * Virtual Spring Damper
***************************************************************************/
float virtualSpringDamper(float angle, float velocity)
{
  float k = 10; // N-mm/deg
  float b_m = 0.02094; // N-mm/(deg/sec)
  float j = 0.01117; // N-mm/(deg/sec^2)
  //float b_spring = 2*0.3342 - b_m; // b = 2*sqrt(kJ) - b_m. b_spring in N-mm/(deg/sec)
	float b_spring = 4.5;
	
	if(SIU.GPDI[5].R == 1) b_spring = 0;
	
  return -k*angle - b_spring*velocity;
}

/***************************************************************************
 * Virtual Wall Damper
***************************************************************************/
float virtualWallDamper(float angle, float velocity)
{
  float k = 650; // N-mm/deg from lab4
  float T = 0.001; // 1 ms
  float b_wall = k*T/2;
	
	if(SIU.GPDI[5].R == 1) b_wall = 0;
	
  if(angle > 0) // puck pulled back to wall
    return -k*angle - b_wall*velocity;
  else // puck moves freely
    return 0;
}

/***************************************************************************
 * Virtual Spring Mass
***************************************************************************/
float virtualSpringMass(float angle)
{
	static float x1old = 0;
	static float x1new = 0;
	static float x2old = 0;
	static float x2new = 0;
	
	float Jw = .45032;
	float k = 17.778; // N-mm/deg
	float T = 0.001; // 1 ms
	float b = 0;
	
	x1new = x1old + T*x2old;
	x2new = x2old - (k/Jw*x1old)*T - (b/Jw*x2old)*T + (k/Jw*angle)*T;
	
	x1old = x1new;
	x2old = x2new;
	
  return -k*(x1new-angle);
}

/***************************************************************************
 * Virtual Spring Mass Damper
***************************************************************************/
float virtualSpringMassDamper(float angle, float velocity) {
  float k = 17.778; // N-mm/deg
  float T = 0.001; // 1 ms
  float b = k*T;
	float Jw = .45032;
  static float x1old = 0;
	static float x1new = 0;
	static float x2old = 0;
	static float x2new = 0;
	
	x1new = x1old + T*x2old;
	x2new = x2old - (k/Jw*x1old)*T - (b/Jw*x2old)*T + (k/Jw*angle)*T;
	
	x1old = x1new;
	x2old = x2new;
	
  return -k*(x1new-angle) -b*(x2new-velocity);
}

/***************************************************************************
 * Virtual Knob
***************************************************************************/ 
float virtualKnob(float angle, float velocity) {
   //There are many ways this can be implemented
	//float k = 17.778; // N-mm/deg
	float k = 0;
  float T = 0.001; // 1 ms
  float b = 5;

  return -b*(-velocity)*angle/30;
}

