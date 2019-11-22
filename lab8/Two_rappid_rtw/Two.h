/*
 * File: Two.h
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

#ifndef RTW_HEADER_Two_h_
#define RTW_HEADER_Two_h_
#ifndef Two_COMMON_INCLUDES_
# define Two_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* Two_COMMON_INCLUDES_ */

#include "Two_types.h"

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
  boolean_T DigitalInput;              /* '<S2>/Digital Input' */
  boolean_T DigitalInput1;             /* '<S2>/Digital Input1' */
  boolean_T DigitalInput2;             /* '<S2>/Digital Input2' */
  boolean_T DigitalInput3;             /* '<S2>/Digital Input3' */
  boolean_T DigitalInput_l;            /* '<S3>/Digital Input' */
  boolean_T DigitalInput1_h;           /* '<S3>/Digital Input1' */
  boolean_T DigitalInput2_d;           /* '<S3>/Digital Input2' */
  boolean_T DigitalInput3_d;           /* '<S3>/Digital Input3' */
  boolean_T DataTypeConversion;        /* '<S4>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S4>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S4>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S4>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S4>/Data Type Conversion4' */
} BlockIO_Two;

/* Block signals (auto storage) */
extern BlockIO_Two Two_B;

/* Model entry point functions */
extern void Two_initialize(boolean_T firstTime);
extern void Two_step(void);
extern void Two_terminate(void);

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
 * '<Root>' : 'Two'
 * '<S1>'   : 'Two/Adder Task'
 * '<S2>'   : 'Two/Adder Task/Read Lower 4 Bits'
 * '<S3>'   : 'Two/Adder Task/Read Upper 4 Bits'
 * '<S4>'   : 'Two/Adder Task/Write 5 Bits'
 */
#endif                                 /* RTW_HEADER_Two_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
