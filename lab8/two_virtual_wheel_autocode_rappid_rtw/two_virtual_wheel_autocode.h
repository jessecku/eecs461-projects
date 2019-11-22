/*
 * File: two_virtual_wheel_autocode.h
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

#ifndef RTW_HEADER_two_virtual_wheel_autocode_h_
#define RTW_HEADER_two_virtual_wheel_autocode_h_
#ifndef two_virtual_wheel_autocode_COMMON_INCLUDES_
# define two_virtual_wheel_autocode_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* two_virtual_wheel_autocode_COMMON_INCLUDES_ */

#include "two_virtual_wheel_autocode_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Theta_out;                    /* '<S1>/Chart' */
  real32_T RateTransition1;            /* '<Root>/Rate Transition1' */
  real32_T RateTransition;             /* '<Root>/Rate Transition' */
  uint32_T DataTypeConversion;         /* '<S1>/Data Type Conversion' */
  uint16_T eTimerCNTRRegisterRead;     /* '<S1>/eTimer CNTR Register Read' */
  boolean_T DataTypeConversion_f;      /* '<S3>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S3>/Data Type Conversion1' */
  boolean_T DataTypeConversion10;      /* '<S3>/Data Type Conversion10' */
  boolean_T DataTypeConversion11;      /* '<S3>/Data Type Conversion11' */
  boolean_T DataTypeConversion12;      /* '<S3>/Data Type Conversion12' */
  boolean_T DataTypeConversion13;      /* '<S3>/Data Type Conversion13' */
  boolean_T DataTypeConversion14;      /* '<S3>/Data Type Conversion14' */
  boolean_T DataTypeConversion15;      /* '<S3>/Data Type Conversion15' */
  boolean_T DataTypeConversion2;       /* '<S3>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S3>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S3>/Data Type Conversion4' */
  boolean_T DataTypeConversion5;       /* '<S3>/Data Type Conversion5' */
  boolean_T DataTypeConversion6;       /* '<S3>/Data Type Conversion6' */
  boolean_T DataTypeConversion7;       /* '<S3>/Data Type Conversion7' */
  boolean_T DataTypeConversion8;       /* '<S3>/Data Type Conversion8' */
  boolean_T DataTypeConversion9;       /* '<S3>/Data Type Conversion9' */
} BlockIO_two_virtual_wheel_autoc;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real32_T UnitDelay1_DSTATE;          /* '<S6>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S1>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S1>/Discrete-Time Integrator3' */
  real32_T RateTransition1_Buffer0;    /* '<Root>/Rate Transition1' */
  uint32_T TriggeredSubsystemFast_ELAPS_T[2];/* '<Root>/Triggered Subsystem Fast' */
  uint32_T TriggeredSubsystemFast_PREV_T[2];/* '<Root>/Triggered Subsystem Fast' */
  uint32_T TriggeredSubsystemSlow_ELAPS_T[2];/* '<Root>/Triggered Subsystem Slow' */
  uint32_T TriggeredSubsystemSlow_PREV_T[2];/* '<Root>/Triggered Subsystem Slow' */
  uint16_T UnitDelay_DSTATE;           /* '<S6>/Unit Delay' */
  uint8_T is_active_c1_two_virtual_wheel_;/* '<S1>/Chart' */
  uint8_T is_c1_two_virtual_wheel_autocod;/* '<S1>/Chart' */
} D_Work_two_virtual_wheel_autoco;

/* Real-time Model Data Structure */
struct RT_MODEL_two_virtual_wheel_auto {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (auto storage) */
extern BlockIO_two_virtual_wheel_autoc two_virtual_wheel_autocode_B;

/* Block states (auto storage) */
extern D_Work_two_virtual_wheel_autoco two_virtual_wheel_autocod_DWork;

/* External function called from main */
extern void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void two_virtual_wheel_autocode_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void two_virtual_wheel_autocode_initialize(boolean_T firstTime);
extern void two_virtual_wheel_autocode_step(int_T tid);
extern void two_virtual_wheel_autocode_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_two_virtual_wheel_auto *const
  two_virtual_wheel_autocode_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'two_virtual_wheel_autocode'
 * '<S1>'   : 'two_virtual_wheel_autocode/Triggered Subsystem Fast'
 * '<S2>'   : 'two_virtual_wheel_autocode/Triggered Subsystem Slow'
 * '<S3>'   : 'two_virtual_wheel_autocode/Triggered Subsystem Fast/16bit LED'
 * '<S4>'   : 'two_virtual_wheel_autocode/Triggered Subsystem Fast/Chart'
 * '<S5>'   : 'two_virtual_wheel_autocode/Triggered Subsystem Fast/Scale'
 * '<S6>'   : 'two_virtual_wheel_autocode/Triggered Subsystem Fast/Scale1'
 */
#endif                                 /* RTW_HEADER_two_virtual_wheel_autocode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
