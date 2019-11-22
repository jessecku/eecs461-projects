/*
 * File: template_Final_Project_MPC5643L_private.h
 *
 * Code generated for Simulink model 'template_Final_Project_MPC5643L'.
 *
 * Model version                  : 1.190
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Jul  9 2011)
 * C/C++ source code generated on : Tue Apr 12 16:44:21 2016
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Motorola PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_template_Final_Project_MPC5643L_private_h_
#define RTW_HEADER_template_Final_Project_MPC5643L_private_h_
#include "rtwtypes.h"
#include "MPC5643L.h"
#include "gpio_564xl_library.h"
#include "flexcan_564xl_library.h"
#include "adc_564xl_library.h"
#include "path_data.h"
#include "path_data.h"
#include "FlexPWM_564xL_library.h"
#include "flexpwm_init.h"
#include "adc0_config.h"
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

extern void PL_Outputs_wrapper(const real32_T *H,
  const real32_T *si,
  const real32_T *s,
  real32_T *lead_s,
  real32_T *lead_u);
extern void vmod_Outputs_wrapper(const real32_T *u,
  const real32_T *delta,
  const real32_T *psi,
  const real32_T *L1,
  const real32_T *L2,
  real32_T *xdot,
  real32_T *ydot,
  real32_T *psidot);
extern void SerialInit_Outputs_wrapper();
extern void template_Final_Project_MPC5643L_step0(void);
extern void template_Final_Project_MPC5643L_step1(void);

#endif                                 /* RTW_HEADER_template_Final_Project_MPC5643L_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
