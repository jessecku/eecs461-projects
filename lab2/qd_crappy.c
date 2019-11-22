/*
   qd.c
   University of Michigan
   EECS 461, Embedded Control Systems
   Enhanced Motor Control Timer (eTimer) module
   Read Chapter 20 in MPC5643 User's Manual
 */
#include "qd.h"

/* Quadrature Decoding Parameters */
#define INITIAL_POSITION 0x8000     
#define ETIMER0_CHANNEL 0
#define ENCODER_COUNT 0b100

/******************************************************************************
 * Function:    init_QD
 * Description: Initializes Quadrature Decoding
 ******************************************************************************/
void initQD()
{
  // Counter #0 PCR 0
  
  SIU.PCR[0].B.PA = 1; // ALT[1]
  SIU.PCR[0].B.IBE = 1;
  
  SIU.PSMI[35].B.PADSEL = 0;

  // Counter #1 PCR 1
  
  SIU.PCR[1].B.PA = 1; // ALT[1]
  SIU.PCR[1].B.IBE = 1;
  
  SIU.PSMI[36].B.PADSEL = 0;

  ETIMER_0.ENBL.R = 0; // Disable all Timers

  // Quadrature count mode, uses primary and secondary sources
  ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CTRL1.B.CNTMODE = ENCODER_COUNT;
  ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CTRL1.B.PRISRC = 0; // Counter #0 input pin
  ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CTRL1.B.SECSRC = 1; // Counter #1 input pin

  ETIMER_0.ENBL.R = 1; // Enable all Timers

  ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CNTR.R = INITIAL_POSITION;

  return;
}

/******************************************************************************
 * Function:    updateCounter
 * Description: Returns an updated counter value that keeps track of wheel 
 *              position
 ******************************************************************************/
int32_t updateCounter()
{
	static uint16_t prev = INITIAL_POSITION;
	static int32_t	total_count = 0;
	uint16_t current;
	current = ETIMER_0.CHANNEL[ETIMER0_CHANNEL].CNTR.R;
	total_count = total_count + (current - prev);
	prev = current;
  return (total_count);
}


/******************************************************************************
 * Function:    updateAngle
 * Description: Returns the angle of the wheel 
 ******************************************************************************/
float updateAngle()
{
  return ((float)updateCounter())*.09;
}
