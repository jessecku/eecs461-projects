/*
   worlds.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Virtual Worlds

   Revision History
     2011-12-01  Jay Patel
     2014-02-24  Scott Kenyon
 */

#include "worlds.h"
#include "gpio.h"
#include "typedefs.h"



//====================LAB 4================================
/***************************************************************************
 * Virtual Wall
 ***************************************************************************/
float virtualWall(float angle)
{
	float k = 650; // 500 N-m per degree of wheel displacement from reference
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
}

/***************************************************************************
 * Virtual Wall Damper
***************************************************************************/
float virtualWallDamper(float angle, float velocity)
{
}

/***************************************************************************
 * Virtual Spring Mass
***************************************************************************/
float virtualSpringMass(float angle)
{
}

/***************************************************************************
 * Virtual Spring Mass Damper
***************************************************************************/
float virtualSpringMassDamper(float angle, float velocity) {

}

/***************************************************************************
 * Virtual Knob
***************************************************************************/ 
float virtualKnob(float angle, float velocity) {
   //There are many ways this can be implemented

}

