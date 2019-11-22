/*
 * File: rappid_main.c
 *
 * Code generated for Simulink model 'Two'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Tue Mar 22 15:26:27 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/* Model's headers */
#include "Two.h"
#include "target.h"
#include "sys_init.h"

extern const vuint32_t ISRVectorTable[];
void SYSTEM_INIT_TASK(void)
{
  /* Initialize model */
  Two_initialize(1);
}

void SYSTEM_TASK(void)
{
  Two_step();

  /* Get model outputs here */
}

void pit_init_fnc(void)
{
  //PIT.PITMCR.R = 0x00000001;
  /* ----------------------------------------------------------- */
  /*               Configure Load Value Registers                */
  /* ----------------------------------------------------------- */
  //    PIT.CH[1].LDVAL.R  =  0x00B71AFF;    /* The model's base sample time is 0.1 seconds. */
  /* ----------------------------------------------------------- */
  /*                     Enable Interrupts                       */
  /* ----------------------------------------------------------- */
  //    PIT.CH[1].TCTRL.R  = 0x00000003;
  PIT.PITMCR.B.MDIS = 1 ;

  /*Disable PIT for initialization         */
  /* ----------------------------------------------------------- */
  /*                     Configure Load Value Registers                */
  /* ----------------------------------------------------------- */
  PIT.CH[0].LDVAL.R = 0x00B71AFF;      /* The model's base sample time is 0.1 seconds. */

  /* ----------------------------------------------------------- */
  /*                     Enable Interrupts                  */
  /* ----------------------------------------------------------- */
  PIT.CH[0].TCTRL.B.TIE = 0x1 ;

  /* ----------------------------------------------------------- */
  /*                   Start Timers                 */
  /* ----------------------------------------------------------- */
  PIT.CH[0].TCTRL.B.TEN = 0x1 ;

  /*Start Timer 0 is : Enabled    */
  PIT.PITMCR.B.MDIS = 0 ;

  /*PIT Module : Enabled        */
}

void PIT_Ch0_ISR(void)
{
  /* Attach SYSTEM_TASK to a timer or interrupt service routine with
   * period 0.1 seconds (the model's base sample time) here.  The
   * call syntax for SYSTEM_TASK is  SYSTEM_TASK();
   */
  PIT.CH[0].TFLG.B.TIF = 1 ;
  SYSTEM_TASK();
}

void main(void)
{
  /* Shut Down Software Watchdog Timer */
  /* remove the SWT Soft lock  */
  SWT.SR.R = 0x0000C520;
  SWT.SR.R = 0x0000D928;

  /* Disable SWT  */
  SWT.CR.B.WEN = 0x0;
  sys_init_fnc();                      /* Disable Watchdog */
  SYSTEM_INIT_TASK();                  /* Initialize the processor. */
  pit_init_fnc();                      /* Initialize PIT Timer Module */
  INTC.CPR.B.PRI = 0;                  /* Ensure INTC's current priority is 0 */
  intc_init_fnc();
  asm(" wrteei 1");                    /* Enable IRQ */
  INTC.CPR.R = 0x0B;                   /* Global Minimum Interrupt Priority */
  while (1) {
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
