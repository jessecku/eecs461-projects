/*
 * File: Wall.h
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

#ifndef RTW_HEADER_Wall_h_
#define RTW_HEADER_Wall_h_
#ifndef Wall_COMMON_INCLUDES_
# define Wall_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* Wall_COMMON_INCLUDES_ */

#include "Wall_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Torque;                       /* '<S3>/Chart' */
  uint32_T DataTypeConversion;         /* '<S1>/Data Type Conversion' */
  uint16_T eTimerCNTRRegisterRead;     /* '<S1>/eTimer CNTR Register Read' */
  boolean_T DataTypeConversion_d;      /* '<S2>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S2>/Data Type Conversion1' */
  boolean_T DataTypeConversion10;      /* '<S2>/Data Type Conversion10' */
  boolean_T DataTypeConversion11;      /* '<S2>/Data Type Conversion11' */
  boolean_T DataTypeConversion12;      /* '<S2>/Data Type Conversion12' */
  boolean_T DataTypeConversion13;      /* '<S2>/Data Type Conversion13' */
  boolean_T DataTypeConversion14;      /* '<S2>/Data Type Conversion14' */
  boolean_T DataTypeConversion15;      /* '<S2>/Data Type Conversion15' */
  boolean_T DataTypeConversion2;       /* '<S2>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S2>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S2>/Data Type Conversion4' */
  boolean_T DataTypeConversion5;       /* '<S2>/Data Type Conversion5' */
  boolean_T DataTypeConversion6;       /* '<S2>/Data Type Conversion6' */
  boolean_T DataTypeConversion7;       /* '<S2>/Data Type Conversion7' */
  boolean_T DataTypeConversion8;       /* '<S2>/Data Type Conversion8' */
  boolean_T DataTypeConversion9;       /* '<S2>/Data Type Conversion9' */
} BlockIO_Wall;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay1_DSTATE;          /* '<S4>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE;           /* '<S4>/Unit Delay' */
  uint8_T is_active_c1_Wall;           /* '<S3>/Chart' */
  uint8_T is_c1_Wall;                  /* '<S3>/Chart' */
} D_Work_Wall;

/* Block signals (auto storage) */
extern BlockIO_Wall Wall_B;

/* Block states (auto storage) */
extern D_Work_Wall Wall_DWork;

/* Model entry point functions */
extern void Wall_initialize(boolean_T firstTime);
extern void Wall_step(void);
extern void Wall_terminate(void);

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
 * '<Root>' : 'Wall'
 * '<S1>'   : 'Wall/VirtualWall-Task'
 * '<S2>'   : 'Wall/VirtualWall-Task/16bit LED'
 * '<S3>'   : 'Wall/VirtualWall-Task/Simulate Virtual Wall'
 * '<S4>'   : 'Wall/VirtualWall-Task/Subsystem'
 * '<S5>'   : 'Wall/VirtualWall-Task/Subsystem1'
 * '<S6>'   : 'Wall/VirtualWall-Task/Simulate Virtual Wall/Chart'
 */
#endif                                 /* RTW_HEADER_Wall_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
