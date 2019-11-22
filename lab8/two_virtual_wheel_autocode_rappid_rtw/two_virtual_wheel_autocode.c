/*
 * File: two_virtual_wheel_autocode.c
 *
 * Code generated for Simulink model 'two_virtual_wheel_autocode'.
 *
 * Model version                  : 1.85
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Tue Mar 22 17:23:24 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "two_virtual_wheel_autocode.h"
#include "two_virtual_wheel_autocode_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define two_virtual_whe_IN_greater_than (1U)
#define two_virtual_wheel__IN_less_than (2U)
#define two_virtual_wheel_autoc_IN_zero (3U)

/* Block signals (auto storage) */
BlockIO_two_virtual_wheel_autoc two_virtual_wheel_autocode_B;

/* Block states (auto storage) */
D_Work_two_virtual_wheel_autoco two_virtual_wheel_autocod_DWork;

/* Real-time model */
RT_MODEL_two_virtual_wheel_auto two_virtual_wheel_autocode_M_;
RT_MODEL_two_virtual_wheel_auto *const two_virtual_wheel_autocode_M =
  &two_virtual_wheel_autocode_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(two_virtual_wheel_autocode_M, 1));
}

/* rate_monotonic_scheduler */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1 =
    (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1])++;
  if ((two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.02s, 0.0s] */
    two_virtual_wheel_autocode_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void two_virtual_wheel_autocode_step0(void) /* Sample time: [0.002s, 0.0s] */
{
  int16_T rtb_DataTypeConversion16;
  real32_T rtb_Sum3;
  real32_T rtb_Sum1;
  real32_T rtb_DiscreteTimeIntegrator3;
  real32_T DiscreteTimeIntegrator;
  uint32_T elapseTime_idx;
  uint32_T prevT_idx;
  uint32_T prevT_idx_0;
  real_T u;

  {                                    /* Sample time: [0.002s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (Simple_PWM_564xL_output): '<Root>/Filter' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 1, 1000000U, 1, 0U, 50U);

  /* RateTransition: '<Root>/Rate Transition1' */
  if (two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1) {
    two_virtual_wheel_autocode_B.RateTransition1 =
      two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem Fast'
   */
  prevT_idx_0 = two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[0];
  prevT_idx = two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[1];
  elapseTime_idx = two_virtual_wheel_autocode_M->Timing.clockTick0 -
    two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[0];
  prevT_idx = two_virtual_wheel_autocode_M->Timing.clockTickH0 - prevT_idx;
  if (prevT_idx_0 > two_virtual_wheel_autocode_M->Timing.clockTick0) {
    prevT_idx--;
  }

  two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_ELAPS_T[0] =
    elapseTime_idx;
  two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_ELAPS_T[1] = prevT_idx;
  prevT_idx_0 = two_virtual_wheel_autocode_M->Timing.clockTick0;
  prevT_idx = two_virtual_wheel_autocode_M->Timing.clockTickH0;
  two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[0] = prevT_idx_0;
  two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[1] = prevT_idx;

  /* S-Function (eTimer_564xL_cntr): '<S1>/eTimer CNTR Register Read' */
  two_virtual_wheel_autocode_B.eTimerCNTRRegisterRead = mcTIMER0.CHANNEL[0].
    CNTR.R;

  /* DataTypeConversion: '<S3>/Data Type Conversion16' */
  rtb_DataTypeConversion16 = (int16_T)
    two_virtual_wheel_autocode_B.eTimerCNTRRegisterRead;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion_f = ((int16_T)
    (rtb_DataTypeConversion16 & 1) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output ' */

  /* Pin Data Output Signal Update PCR[43]. */
  gpo_pin_update_564xl_fnc(43, two_virtual_wheel_autocode_B.DataTypeConversion_f);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator1'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion1 = ((int16_T)
    (rtb_DataTypeConversion16 & 2) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[44]. */
  gpo_pin_update_564xl_fnc(44, two_virtual_wheel_autocode_B.DataTypeConversion1);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion10' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator10'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion10 = ((int16_T)
    (rtb_DataTypeConversion16 & 1024) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 10' */

  /* Pin Data Output Signal Update PCR[53]. */
  gpo_pin_update_564xl_fnc(53, two_virtual_wheel_autocode_B.DataTypeConversion10);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion11' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator11'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion11 = ((int16_T)
    (rtb_DataTypeConversion16 & 2048) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 11' */

  /* Pin Data Output Signal Update PCR[54]. */
  gpo_pin_update_564xl_fnc(54, two_virtual_wheel_autocode_B.DataTypeConversion11);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion12' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator12'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion12 = ((int16_T)
    (rtb_DataTypeConversion16 & 4096) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 12' */

  /* Pin Data Output Signal Update PCR[55]. */
  gpo_pin_update_564xl_fnc(55, two_virtual_wheel_autocode_B.DataTypeConversion12);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion13' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator13'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion13 = ((int16_T)
    (rtb_DataTypeConversion16 & 8192) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 13' */

  /* Pin Data Output Signal Update PCR[56]. */
  gpo_pin_update_564xl_fnc(56, two_virtual_wheel_autocode_B.DataTypeConversion13);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion14' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator14'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion14 = ((int16_T)
    (rtb_DataTypeConversion16 & 16384) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 14' */

  /* Pin Data Output Signal Update PCR[57]. */
  gpo_pin_update_564xl_fnc(57, two_virtual_wheel_autocode_B.DataTypeConversion14);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion15' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator15'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion15 = ((int16_T)
    (rtb_DataTypeConversion16 & MIN_int16_T) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 15' */

  /* Pin Data Output Signal Update PCR[58]. */
  gpo_pin_update_564xl_fnc(58, two_virtual_wheel_autocode_B.DataTypeConversion15);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator2'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion2 = ((int16_T)
    (rtb_DataTypeConversion16 & 4) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 2' */

  /* Pin Data Output Signal Update PCR[45]. */
  gpo_pin_update_564xl_fnc(45, two_virtual_wheel_autocode_B.DataTypeConversion2);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator3'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion3 = ((int16_T)
    (rtb_DataTypeConversion16 & 8) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 3' */

  /* Pin Data Output Signal Update PCR[46]. */
  gpo_pin_update_564xl_fnc(46, two_virtual_wheel_autocode_B.DataTypeConversion3);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator4'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion4 = ((int16_T)
    (rtb_DataTypeConversion16 & 16) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 4' */

  /* Pin Data Output Signal Update PCR[47]. */
  gpo_pin_update_564xl_fnc(47, two_virtual_wheel_autocode_B.DataTypeConversion4);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion5' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator5'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion5 = ((int16_T)
    (rtb_DataTypeConversion16 & 32) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 5' */

  /* Pin Data Output Signal Update PCR[48]. */
  gpo_pin_update_564xl_fnc(48, two_virtual_wheel_autocode_B.DataTypeConversion5);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion6' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator6'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion6 = ((int16_T)
    (rtb_DataTypeConversion16 & 64) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 6' */

  /* Pin Data Output Signal Update PCR[49]. */
  gpo_pin_update_564xl_fnc(49, two_virtual_wheel_autocode_B.DataTypeConversion6);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion7' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator7'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion7 = ((int16_T)
    (rtb_DataTypeConversion16 & 128) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 7' */

  /* Pin Data Output Signal Update PCR[50]. */
  gpo_pin_update_564xl_fnc(50, two_virtual_wheel_autocode_B.DataTypeConversion7);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion8' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator8'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion8 = ((int16_T)
    (rtb_DataTypeConversion16 & 256) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 8' */

  /* Pin Data Output Signal Update PCR[51]. */
  gpo_pin_update_564xl_fnc(51, two_virtual_wheel_autocode_B.DataTypeConversion8);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S3>/Data Type Conversion9' incorporates:
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator9'
   */
  two_virtual_wheel_autocode_B.DataTypeConversion9 = ((int16_T)
    (rtb_DataTypeConversion16 & 512) != 0);

  /* S-Function (gpio_564xl_output): '<S3>/Digital Output 9' */

  /* Pin Data Output Signal Update PCR[52]. */
  gpo_pin_update_564xl_fnc(52, two_virtual_wheel_autocode_B.DataTypeConversion9);/* GPO Pin Data Output Register Update */

  /* Sum: '<S6>/Sum1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Gain: '<S6>/Gain'
   *  Sum: '<S6>/Sum'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  rtb_Sum1 = (real32_T)(int16_T)(uint16_T)
    (two_virtual_wheel_autocode_B.eTimerCNTRRegisterRead -
     two_virtual_wheel_autocod_DWork.UnitDelay_DSTATE) * 0.09F +
    two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  DiscreteTimeIntegrator =
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' */
  rtb_DiscreteTimeIntegrator3 =
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Sum: '<S1>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator3'
   *  Gain: '<S1>/damping4'
   *  Gain: '<S1>/spring  constant2'
   *  Sum: '<S1>/Sum1'
   */
  rtb_Sum3 = (rtb_Sum1 -
              two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE) *
    0.0975F - 0.000195F *
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/offset'
   *  Gain: '<S5>/torque gain'
   *  Sum: '<S1>/Sum'
   */
  u = (real_T)(((0.0F - rtb_Sum3) - two_virtual_wheel_autocode_B.RateTransition1)
               * 0.0003162F) + 0.5;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Gain: '<S1>/Gain'
   *  Saturate: '<S1>/Saturation'
   */
  u = floor((u >= 0.76 ? 0.76 : u <= 0.24 ? 0.24 : u) * 100.0);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 4.294967296E+9);
  }

  two_virtual_wheel_autocode_B.DataTypeConversion = (uint32_T)u;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (Simple_PWM_564xL_output): '<S1>/Motor' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 0, 20000U, 1, 0U,
    two_virtual_wheel_autocode_B.DataTypeConversion);

  /* Chart: '<S1>/Chart' */
  /* Gateway: Triggered
     Subsystem
     Fast/Chart */
  /* During: Triggered
     Subsystem
     Fast/Chart */
  if (two_virtual_wheel_autocod_DWork.is_active_c1_two_virtual_wheel_ == 0U) {
    /* Entry: Triggered
       Subsystem
       Fast/Chart */
    two_virtual_wheel_autocod_DWork.is_active_c1_two_virtual_wheel_ = 1U;

    /* Transition: '<S4>:20' */
    two_virtual_wheel_autocod_DWork.is_c1_two_virtual_wheel_autocod =
      two_virtual_wheel_autoc_IN_zero;
  } else {
    switch (two_virtual_wheel_autocod_DWork.is_c1_two_virtual_wheel_autocod) {
     case two_virtual_whe_IN_greater_than:
      /* During 'greater_than': '<S4>:12' */
      /* Transition: '<S4>:18' */
      two_virtual_wheel_autocod_DWork.is_c1_two_virtual_wheel_autocod =
        two_virtual_wheel_autoc_IN_zero;
      break;

     case two_virtual_wheel__IN_less_than:
      /* During 'less_than': '<S4>:8' */
      /* Transition: '<S4>:14' */
      two_virtual_wheel_autocod_DWork.is_c1_two_virtual_wheel_autocod =
        two_virtual_wheel_autoc_IN_zero;
      break;

     case two_virtual_wheel_autoc_IN_zero:
      /* During 'zero': '<S4>:11' */
      two_virtual_wheel_autocode_B.Theta_out = 0.0;
      break;

     default:
      /* Transition: '<S4>:20' */
      two_virtual_wheel_autocod_DWork.is_c1_two_virtual_wheel_autocod =
        two_virtual_wheel_autoc_IN_zero;
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  two_virtual_wheel_autocod_DWork.UnitDelay_DSTATE =
    two_virtual_wheel_autocode_B.eTimerCNTRRegisterRead;

  /* Update for UnitDelay: '<S6>/Unit Delay1' */
  two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE = rtb_Sum1;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE = (real32_T)
    (0.0020000000949949026 * (real_T)
     two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_ELAPS_T[0]) *
    rtb_DiscreteTimeIntegrator3 +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator3' incorporates:
   *  Gain: '<S1>/1//virtual inertia2'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE = (real32_T)
    (0.0020000000949949026 * (real_T)
     two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_ELAPS_T[0]) *
    (533.333313F * rtb_Sum3) +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* RateTransition: '<Root>/Rate Transition' */
  if (two_virtual_wheel_autocode_M->Timing.RateInteraction.TID0_1) {
    two_virtual_wheel_autocode_B.RateTransition = DiscreteTimeIntegrator;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick0++;
  if (!two_virtual_wheel_autocode_M->Timing.clockTick0) {
    two_virtual_wheel_autocode_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void two_virtual_wheel_autocode_step1(void) /* Sample time: [0.02s, 0.0s] */
{
  real32_T Sum;
  uint32_T elapseTime_idx;
  uint32_T prevT_idx;
  uint32_T prevT_idx_0;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem Slow'
   */
  prevT_idx_0 = two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[0];
  prevT_idx = two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[1];
  elapseTime_idx = two_virtual_wheel_autocode_M->Timing.clockTick1 -
    two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[0];
  prevT_idx = two_virtual_wheel_autocode_M->Timing.clockTickH1 - prevT_idx;
  if (prevT_idx_0 > two_virtual_wheel_autocode_M->Timing.clockTick1) {
    prevT_idx--;
  }

  two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_ELAPS_T[0] =
    elapseTime_idx;
  two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_ELAPS_T[1] = prevT_idx;
  prevT_idx_0 = two_virtual_wheel_autocode_M->Timing.clockTick1;
  prevT_idx = two_virtual_wheel_autocode_M->Timing.clockTickH1;
  two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[0] = prevT_idx_0;
  two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[1] = prevT_idx;

  /* Sum: '<S2>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   *  Gain: '<S2>/damping1'
   *  Gain: '<S2>/spring  constant1'
   *  Sum: '<S2>/Sum'
   */
  Sum = (two_virtual_wheel_autocode_B.RateTransition -
         two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE) * 7.5F
    - 0.15F * two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE = (real32_T)
    (0.019999999552965164 * (real_T)
     two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_ELAPS_T[0]) *
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S2>/1//virtual inertia1'
   */
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE = (real32_T)
    (0.019999999552965164 * (real_T)
     two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_ELAPS_T[0]) *
    (5.33333349F * Sum) +
    two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for RateTransition: '<Root>/Rate Transition1' */
  two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0 = Sum;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  two_virtual_wheel_autocode_M->Timing.clockTick1++;
  if (!two_virtual_wheel_autocode_M->Timing.clockTick1) {
    two_virtual_wheel_autocode_M->Timing.clockTickH1++;
  }
}

void two_virtual_wheel_autocode_step(int_T tid)
{
  switch (tid) {
   case 0 :
    two_virtual_wheel_autocode_step0();
    break;

   case 1 :
    two_virtual_wheel_autocode_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void two_virtual_wheel_autocode_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)two_virtual_wheel_autocode_M, 0,
                sizeof(RT_MODEL_two_virtual_wheel_auto));

  /* block I/O */
  (void) memset(((void *) &two_virtual_wheel_autocode_B), 0,
                sizeof(BlockIO_two_virtual_wheel_autoc));

  {
    two_virtual_wheel_autocode_B.Theta_out = 0.0;
    two_virtual_wheel_autocode_B.RateTransition1 = 0.0F;
    two_virtual_wheel_autocode_B.RateTransition = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&two_virtual_wheel_autocod_DWork, 0,
                sizeof(D_Work_two_virtual_wheel_autoco));
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.UnitDelay1_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator2_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.DiscreteTimeIntegrator3_DSTATE = 0.0F;
  two_virtual_wheel_autocod_DWork.RateTransition1_Buffer0 = 0.0F;

  /* Start for S-Function (Simple_PWM_564xL_output): '<Root>/Filter' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,1,0,255);
  pwm_init_pcr_out_564xL(0,1,1,38);
  pwm_init_pcr_out_564xL(0,1,2,255);

  /* Initialize PWM Submodule 1 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,1, 1000000, 1, 0, 0, 0, 0, 0, 60, 0, 0, 0);

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<Root>/Triggered Subsystem Fast'
   */
  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output ' */

  /* Initialize Pad Configuration Register 43 as Output */
  gpo_init_pcr_out_564xl_fnc( 43 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 1' */

  /* Initialize Pad Configuration Register 44 as Output */
  gpo_init_pcr_out_564xl_fnc( 44 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 10' */

  /* Initialize Pad Configuration Register 53 as Output */
  gpo_init_pcr_out_564xl_fnc( 53 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 11' */

  /* Initialize Pad Configuration Register 54 as Output */
  gpo_init_pcr_out_564xl_fnc( 54 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 12' */

  /* Initialize Pad Configuration Register 55 as Output */
  gpo_init_pcr_out_564xl_fnc( 55 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 13' */

  /* Initialize Pad Configuration Register 56 as Output */
  gpo_init_pcr_out_564xl_fnc( 56 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 14' */

  /* Initialize Pad Configuration Register 57 as Output */
  gpo_init_pcr_out_564xl_fnc( 57 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 15' */

  /* Initialize Pad Configuration Register 58 as Output */
  gpo_init_pcr_out_564xl_fnc( 58 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 2' */

  /* Initialize Pad Configuration Register 45 as Output */
  gpo_init_pcr_out_564xl_fnc( 45 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 3' */

  /* Initialize Pad Configuration Register 46 as Output */
  gpo_init_pcr_out_564xl_fnc( 46 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 4' */

  /* Initialize Pad Configuration Register 47 as Output */
  gpo_init_pcr_out_564xl_fnc( 47 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 5' */

  /* Initialize Pad Configuration Register 48 as Output */
  gpo_init_pcr_out_564xl_fnc( 48 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 6' */

  /* Initialize Pad Configuration Register 49 as Output */
  gpo_init_pcr_out_564xl_fnc( 49 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 7' */

  /* Initialize Pad Configuration Register 50 as Output */
  gpo_init_pcr_out_564xl_fnc( 50 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 8' */

  /* Initialize Pad Configuration Register 51 as Output */
  gpo_init_pcr_out_564xl_fnc( 51 );

  /* Start for S-Function (gpio_564xl_output): '<S3>/Digital Output 9' */

  /* Initialize Pad Configuration Register 52 as Output */
  gpo_init_pcr_out_564xl_fnc( 52 );

  /* Start for S-Function (Simple_PWM_564xL_output): '<S1>/Motor' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,0,0,255);
  pwm_init_pcr_out_564xL(0,0,1,59);
  pwm_init_pcr_out_564xL(0,0,2,255);

  /* Initialize PWM Submodule 0 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,0, 20000, 1, 0, 0, 0, 0, 0, 60, 0, 0, 0);

  /* Start for S-Function (eTimer_564xL_config): '<Root>/eTimer configuration' */
  etimer_init_pcr_in_out_564xL(0,0,0);
  etimer_init_pcr_in_out_564xL(0,1,1);
  etimer_init_pcr_in_out_564xL(0,2,255);
  etimer_init_pcr_in_out_564xL(0,3,255);
  etimer_init_pcr_in_out_564xL(0,4,255);
  etimer_init_pcr_in_out_564xL(0,5,255);
  etimer_init_564xL (0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0);

  {
    uint32_T prevT_idx;
    uint32_T prevT_idx_0;

    /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
     *  InitializeConditions for SubSystem: '<Root>/Triggered Subsystem Fast'
     */
    prevT_idx = two_virtual_wheel_autocode_M->Timing.clockTick0;
    prevT_idx_0 = two_virtual_wheel_autocode_M->Timing.clockTickH0;
    two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[0] = prevT_idx;
    two_virtual_wheel_autocod_DWork.TriggeredSubsystemFast_PREV_T[1] =
      prevT_idx_0;

    /* InitializeConditions for Chart: '<S1>/Chart' */
    two_virtual_wheel_autocod_DWork.is_active_c1_two_virtual_wheel_ = 0U;
    two_virtual_wheel_autocod_DWork.is_c1_two_virtual_wheel_autocod = 0U;
    two_virtual_wheel_autocode_B.Theta_out = 0.0;

    /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
     *  InitializeConditions for SubSystem: '<Root>/Triggered Subsystem Slow'
     */
    prevT_idx = two_virtual_wheel_autocode_M->Timing.clockTick1;
    prevT_idx_0 = two_virtual_wheel_autocode_M->Timing.clockTickH1;
    two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[0] = prevT_idx;
    two_virtual_wheel_autocod_DWork.TriggeredSubsystemSlow_PREV_T[1] =
      prevT_idx_0;
  }
}

/* Model terminate function */
void two_virtual_wheel_autocode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
