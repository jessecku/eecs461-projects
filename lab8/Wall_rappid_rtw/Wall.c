/*
 * File: Wall.c
 *
 * Code generated for Simulink model 'Wall'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Tue Mar 22 16:18:04 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wall.h"
#include "Wall_private.h"

/* Named constants for Chart: '<S3>/Chart' */
#define Wall_IN_In_Wall                (1U)
#define Wall_IN_Outside_Wall           (2U)

/* Block signals (auto storage) */
BlockIO_Wall Wall_B;

/* Block states (auto storage) */
D_Work_Wall Wall_DWork;

/* Model step function */
void Wall_step(void)
{
  int16_T rtb_DataTypeConversion16;
  real32_T rtb_Sum1;
  real_T u;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/VirtualWall-Task'
   */

  /* S-Function (eTimer_564xL_cntr): '<S1>/eTimer CNTR Register Read' */
  Wall_B.eTimerCNTRRegisterRead = mcTIMER0.CHANNEL[0].CNTR.R;

  /* DataTypeConversion: '<S2>/Data Type Conversion16' */
  rtb_DataTypeConversion16 = (int16_T)Wall_B.eTimerCNTRRegisterRead;

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator'
   */
  Wall_B.DataTypeConversion_d = ((int16_T)(rtb_DataTypeConversion16 & 1) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output ' */

  /* Pin Data Output Signal Update PCR[43]. */
  gpo_pin_update_564xl_fnc(43, Wall_B.DataTypeConversion_d);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator1'
   */
  Wall_B.DataTypeConversion1 = ((int16_T)(rtb_DataTypeConversion16 & 2) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[44]. */
  gpo_pin_update_564xl_fnc(44, Wall_B.DataTypeConversion1);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion10' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator10'
   */
  Wall_B.DataTypeConversion10 = ((int16_T)(rtb_DataTypeConversion16 & 1024) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 10' */

  /* Pin Data Output Signal Update PCR[53]. */
  gpo_pin_update_564xl_fnc(53, Wall_B.DataTypeConversion10);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator11'
   */
  Wall_B.DataTypeConversion11 = ((int16_T)(rtb_DataTypeConversion16 & 2048) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 11' */

  /* Pin Data Output Signal Update PCR[54]. */
  gpo_pin_update_564xl_fnc(54, Wall_B.DataTypeConversion11);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion12' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator12'
   */
  Wall_B.DataTypeConversion12 = ((int16_T)(rtb_DataTypeConversion16 & 4096) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 12' */

  /* Pin Data Output Signal Update PCR[55]. */
  gpo_pin_update_564xl_fnc(55, Wall_B.DataTypeConversion12);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion13' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator13'
   */
  Wall_B.DataTypeConversion13 = ((int16_T)(rtb_DataTypeConversion16 & 8192) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 13' */

  /* Pin Data Output Signal Update PCR[56]. */
  gpo_pin_update_564xl_fnc(56, Wall_B.DataTypeConversion13);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator14'
   */
  Wall_B.DataTypeConversion14 = ((int16_T)(rtb_DataTypeConversion16 & 16384) !=
    0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 14' */

  /* Pin Data Output Signal Update PCR[57]. */
  gpo_pin_update_564xl_fnc(57, Wall_B.DataTypeConversion14);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator15'
   */
  Wall_B.DataTypeConversion15 = ((int16_T)(rtb_DataTypeConversion16 &
    MIN_int16_T) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 15' */

  /* Pin Data Output Signal Update PCR[58]. */
  gpo_pin_update_564xl_fnc(58, Wall_B.DataTypeConversion15);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator2'
   */
  Wall_B.DataTypeConversion2 = ((int16_T)(rtb_DataTypeConversion16 & 4) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 2' */

  /* Pin Data Output Signal Update PCR[45]. */
  gpo_pin_update_564xl_fnc(45, Wall_B.DataTypeConversion2);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator3'
   */
  Wall_B.DataTypeConversion3 = ((int16_T)(rtb_DataTypeConversion16 & 8) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 3' */

  /* Pin Data Output Signal Update PCR[46]. */
  gpo_pin_update_564xl_fnc(46, Wall_B.DataTypeConversion3);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator4'
   */
  Wall_B.DataTypeConversion4 = ((int16_T)(rtb_DataTypeConversion16 & 16) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 4' */

  /* Pin Data Output Signal Update PCR[47]. */
  gpo_pin_update_564xl_fnc(47, Wall_B.DataTypeConversion4);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator5'
   */
  Wall_B.DataTypeConversion5 = ((int16_T)(rtb_DataTypeConversion16 & 32) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 5' */

  /* Pin Data Output Signal Update PCR[48]. */
  gpo_pin_update_564xl_fnc(48, Wall_B.DataTypeConversion5);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion6' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator6'
   */
  Wall_B.DataTypeConversion6 = ((int16_T)(rtb_DataTypeConversion16 & 64) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 6' */

  /* Pin Data Output Signal Update PCR[49]. */
  gpo_pin_update_564xl_fnc(49, Wall_B.DataTypeConversion6);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion7' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator7'
   */
  Wall_B.DataTypeConversion7 = ((int16_T)(rtb_DataTypeConversion16 & 128) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 7' */

  /* Pin Data Output Signal Update PCR[50]. */
  gpo_pin_update_564xl_fnc(50, Wall_B.DataTypeConversion7);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion8' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator8'
   */
  Wall_B.DataTypeConversion8 = ((int16_T)(rtb_DataTypeConversion16 & 256) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 8' */

  /* Pin Data Output Signal Update PCR[51]. */
  gpo_pin_update_564xl_fnc(51, Wall_B.DataTypeConversion8);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S2>/Data Type Conversion9' incorporates:
   *  S-Function (sfix_bitop): '<S2>/Bitwise Operator9'
   */
  Wall_B.DataTypeConversion9 = ((int16_T)(rtb_DataTypeConversion16 & 512) != 0);

  /* S-Function (gpio_564xl_output): '<S2>/Digital Output 9' */

  /* Pin Data Output Signal Update PCR[52]. */
  gpo_pin_update_564xl_fnc(52, Wall_B.DataTypeConversion9);/* GPO Pin Data Output Register Update */

  /* Sum: '<S4>/Sum1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  Gain: '<S4>/Gain'
   *  Sum: '<S4>/Sum'
   *  UnitDelay: '<S4>/Unit Delay'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_Sum1 = (real32_T)(int16_T)(uint16_T)(Wall_B.eTimerCNTRRegisterRead -
    Wall_DWork.UnitDelay_DSTATE) * 0.09F + Wall_DWork.UnitDelay1_DSTATE;

  /* Chart: '<S3>/Chart' */
  /* Gateway: VirtualWall-Task/Simulate Virtual Wall/Chart */
  /* During: VirtualWall-Task/Simulate Virtual Wall/Chart */
  if (Wall_DWork.is_active_c1_Wall == 0U) {
    /* Entry: VirtualWall-Task/Simulate Virtual Wall/Chart */
    Wall_DWork.is_active_c1_Wall = 1U;

    /* Transition: '<S6>:5' */
    Wall_DWork.is_c1_Wall = Wall_IN_Outside_Wall;
  } else {
    switch (Wall_DWork.is_c1_Wall) {
     case Wall_IN_In_Wall:
      /* During 'In_Wall': '<S6>:4' */
      if (rtb_Sum1 < 0.0F) {
        /* Transition: '<S6>:7' */
        Wall_DWork.is_c1_Wall = Wall_IN_Outside_Wall;
      } else {
        Wall_B.Torque = -500.0 * (real_T)rtb_Sum1;
      }
      break;

     case Wall_IN_Outside_Wall:
      /* During 'Outside_Wall': '<S6>:3' */
      if (rtb_Sum1 > 0.0F) {
        /* Transition: '<S6>:6' */
        Wall_DWork.is_c1_Wall = Wall_IN_In_Wall;
      } else {
        Wall_B.Torque = 0.0;
      }
      break;

     default:
      /* Transition: '<S6>:5' */
      Wall_DWork.is_c1_Wall = Wall_IN_Outside_Wall;
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S5>/offset'
   *  Gain: '<S5>/torque gain'
   */
  u = 0.0003162 * Wall_B.Torque + 0.5;

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

  Wall_B.DataTypeConversion = (uint32_T)u;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (Simple_PWM_564xL_output): '<S1>/Simple PWM Output' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 0, 20000U, 1, 0U,
    Wall_B.DataTypeConversion);

  /* S-Function (Simple_PWM_564xL_output): '<S1>/Simple PWM Output1' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 1, 1000000U, 1, 0U, 50U);

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  Wall_DWork.UnitDelay_DSTATE = Wall_B.eTimerCNTRRegisterRead;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  Wall_DWork.UnitDelay1_DSTATE = rtb_Sum1;
}

/* Model initialize function */
void Wall_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &Wall_B), 0,
                sizeof(BlockIO_Wall));

  /* states (dwork) */
  (void) memset((void *)&Wall_DWork, 0,
                sizeof(D_Work_Wall));

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<Root>/VirtualWall-Task'
   */
  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output ' */

  /* Initialize Pad Configuration Register 43 as Output */
  gpo_init_pcr_out_564xl_fnc( 43 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 1' */

  /* Initialize Pad Configuration Register 44 as Output */
  gpo_init_pcr_out_564xl_fnc( 44 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 10' */

  /* Initialize Pad Configuration Register 53 as Output */
  gpo_init_pcr_out_564xl_fnc( 53 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 11' */

  /* Initialize Pad Configuration Register 54 as Output */
  gpo_init_pcr_out_564xl_fnc( 54 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 12' */

  /* Initialize Pad Configuration Register 55 as Output */
  gpo_init_pcr_out_564xl_fnc( 55 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 13' */

  /* Initialize Pad Configuration Register 56 as Output */
  gpo_init_pcr_out_564xl_fnc( 56 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 14' */

  /* Initialize Pad Configuration Register 57 as Output */
  gpo_init_pcr_out_564xl_fnc( 57 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 15' */

  /* Initialize Pad Configuration Register 58 as Output */
  gpo_init_pcr_out_564xl_fnc( 58 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 2' */

  /* Initialize Pad Configuration Register 45 as Output */
  gpo_init_pcr_out_564xl_fnc( 45 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 3' */

  /* Initialize Pad Configuration Register 46 as Output */
  gpo_init_pcr_out_564xl_fnc( 46 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 4' */

  /* Initialize Pad Configuration Register 47 as Output */
  gpo_init_pcr_out_564xl_fnc( 47 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 5' */

  /* Initialize Pad Configuration Register 48 as Output */
  gpo_init_pcr_out_564xl_fnc( 48 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 6' */

  /* Initialize Pad Configuration Register 49 as Output */
  gpo_init_pcr_out_564xl_fnc( 49 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 7' */

  /* Initialize Pad Configuration Register 50 as Output */
  gpo_init_pcr_out_564xl_fnc( 50 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 8' */

  /* Initialize Pad Configuration Register 51 as Output */
  gpo_init_pcr_out_564xl_fnc( 51 );

  /* Start for S-Function (gpio_564xl_output): '<S2>/Digital Output 9' */

  /* Initialize Pad Configuration Register 52 as Output */
  gpo_init_pcr_out_564xl_fnc( 52 );

  /* Start for S-Function (Simple_PWM_564xL_output): '<S1>/Simple PWM Output' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,0,0,255);
  pwm_init_pcr_out_564xL(0,0,1,59);
  pwm_init_pcr_out_564xL(0,0,2,255);

  /* Initialize PWM Submodule 0 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,0, 20000, 1, 0, 0, 0, 0, 0, 60, 0, 0, 0);

  /* Start for S-Function (Simple_PWM_564xL_output): '<S1>/Simple PWM Output1' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,1,0,255);
  pwm_init_pcr_out_564xL(0,1,1,38);
  pwm_init_pcr_out_564xL(0,1,2,255);

  /* Initialize PWM Submodule 1 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,1, 1000000, 1, 0, 0, 0, 0, 0, 60, 0, 0, 0);

  /* Start for S-Function (eTimer_564xL_config): '<Root>/eTimer configuration' */
  etimer_init_pcr_in_out_564xL(0,0,0);
  etimer_init_pcr_in_out_564xL(0,1,1);
  etimer_init_pcr_in_out_564xL(0,2,255);
  etimer_init_pcr_in_out_564xL(0,3,255);
  etimer_init_pcr_in_out_564xL(0,4,255);
  etimer_init_pcr_in_out_564xL(0,5,255);
  etimer_init_564xL (0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0);

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/VirtualWall-Task'
   */
  /* InitializeConditions for Chart: '<S3>/Chart' */
  Wall_DWork.is_active_c1_Wall = 0U;
  Wall_DWork.is_c1_Wall = 0U;
  Wall_B.Torque = 0.0;
}

/* Model terminate function */
void Wall_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
