/*
 * File: linflex_siu_init.c
 *
 * Code generated for Simulink model 'template_Final_Project_MPC5643L'.
 *
 * Model version                  : 1.141
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Tue Mar 29 17:51:25 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/********************  Dependent Include files here **********************/
#include "target.h"

/**********************  Initialization Function(s) *************************/
void linflex_siu_init(void)
{
  /* ----------------------------------------------------------------------- */
  /*      Pad Configuration Register PCR[18]  LIN_TXD */
  /* ----------------------------------------------------------------------- */
  SIU.PCR[18].R = 0x400;

  /*	Selected Function : LIN_TXD_0        */
  /*	Output Buffers : Enabled          */
  /*	Input Buffers : Disabled          */
  /*	Output Drain : Disabled           */
  /*	Slew Rate Control : Minimum       */
  /*	Weak Pull Up/Down : Disabled      */
  /*	Weak Pull Up/Down Select : Down   */
  /* ----------------------------------------------------------- */
  /*      Pad Configuration Register PCR[19]  LIN_RXD */
  /* ----------------------------------------------------------- */
  SIU.PCR[19].R = 0x0100;

  /*	Selected Function : PB[3] I        */
  /*	Output Buffers : Disabled         */
  /*	Input Buffers : Enabled           */
  /*	Output Drain : Disabled           */
  /*	Slew Rate Control : Minimum       */
  /*	Weak Pull Up/Down : Disabled      */
  /*	Weak Pull Up/Down Select : Down   */
  SIU.PSMI[31].B.PADSEL = 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
