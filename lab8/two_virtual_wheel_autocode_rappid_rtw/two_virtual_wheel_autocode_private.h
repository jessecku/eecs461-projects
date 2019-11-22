/*
 * File: two_virtual_wheel_autocode_private.h
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

#ifndef RTW_HEADER_two_virtual_wheel_autocode_private_h_
#define RTW_HEADER_two_virtual_wheel_autocode_private_h_
#include "rtwtypes.h"
#include "gpio_564xl_library.h"
#include "FlexPWM_564xL_library.h"
#include "flexpwm_init.h"
#include "eTimer_564xL_library.h"
#define CALL_EVENT                     (-1)
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void two_virtual_wheel_autocode_step0(void);
extern void two_virtual_wheel_autocode_step1(void);

#endif                                 /* RTW_HEADER_two_virtual_wheel_autocode_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
