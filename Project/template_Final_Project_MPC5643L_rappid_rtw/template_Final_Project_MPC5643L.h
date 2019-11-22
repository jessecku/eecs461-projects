/*
 * File: template_Final_Project_MPC5643L.h
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

#ifndef RTW_HEADER_template_Final_Project_MPC5643L_h_
#define RTW_HEADER_template_Final_Project_MPC5643L_h_
#ifndef template_Final_Project_MPC5643L_COMMON_INCLUDES_
# define template_Final_Project_MPC5643L_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* template_Final_Project_MPC5643L_COMMON_INCLUDES_ */

#include "template_Final_Project_MPC5643L_types.h"

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

#define template_Final_Project_MPC5643L_M (template_Final_Project_MPC56_M)

/* Block signals (auto storage) */
typedef struct {
  real32_T RateTransition[22];         /* '<Root>/Rate Transition' */
  real32_T BytestoSingle;              /* '<S11>/Bytes to Single' */
  real32_T BytestoSingle1;             /* '<S11>/Bytes to Single1' */
  real32_T BytestoSingle2;             /* '<S11>/Bytes to Single2' */
  real32_T BytestoSingle3;             /* '<S11>/Bytes to Single3' */
  real32_T Switch[24];                 /* '<S9>/Switch' */
  real32_T Sum1;                       /* '<S10>/Sum1' */
  real32_T DiscreteTimeIntegrator3;    /* '<S30>/Discrete-Time Integrator3' */
  real32_T UnitDelay;                  /* '<S36>/Unit Delay' */
  real32_T LookupP_o1;                 /* '<S32>/Look up P' */
  real32_T LookupP_o2;                 /* '<S32>/Look up P' */
  real32_T LookupRightVector_o1;       /* '<S32>/Look up Right Vector' */
  real32_T LookupRightVector_o2;       /* '<S32>/Look up Right Vector' */
  real32_T Sum1_g;                     /* '<S38>/Sum1' */
  real32_T LookupRightVector_o1_o;     /* '<S33>/Look up Right Vector' */
  real32_T LookupRightVector_o2_b;     /* '<S33>/Look up Right Vector' */
  real32_T DiscreteTimeIntegrator2;    /* '<S30>/Discrete-Time Integrator2' */
  real32_T Product2;                   /* '<S31>/Product2' */
  real32_T LookupP_o1_c;               /* '<S17>/Look up P' */
  real32_T LookupP_o2_b;               /* '<S17>/Look up P' */
  real32_T LookupRightVector_o1_b;     /* '<S17>/Look up Right Vector' */
  real32_T LookupRightVector_o2_h;     /* '<S17>/Look up Right Vector' */
  real32_T LookupP_o1_k;               /* '<S24>/Look up P' */
  real32_T LookupP_o2_c;               /* '<S24>/Look up P' */
  real32_T LookupRightVector_o1_l;     /* '<S24>/Look up Right Vector' */
  real32_T LookupRightVector_o2_c;     /* '<S24>/Look up Right Vector' */
  real32_T LookupP_o1_e;               /* '<S25>/Look up P' */
  real32_T LookupP_o2_g;               /* '<S25>/Look up P' */
  real32_T LookupRightVector_o1_om;    /* '<S25>/Look up Right Vector' */
  real32_T LookupRightVector_o2_hm;    /* '<S25>/Look up Right Vector' */
  real32_T LookupP_o1_g;               /* '<S26>/Look up P' */
  real32_T LookupP_o2_j;               /* '<S26>/Look up P' */
  real32_T LookupRightVector_o1_a;     /* '<S26>/Look up Right Vector' */
  real32_T LookupRightVector_o2_i;     /* '<S26>/Look up Right Vector' */
  real32_T LookupP_o1_i;               /* '<S27>/Look up P' */
  real32_T LookupP_o2_a;               /* '<S27>/Look up P' */
  real32_T LookupRightVector_o1_am;    /* '<S27>/Look up Right Vector' */
  real32_T LookupRightVector_o2_l;     /* '<S27>/Look up Right Vector' */
  real32_T LookupP_o1_o;               /* '<S28>/Look up P' */
  real32_T LookupP_o2_k;               /* '<S28>/Look up P' */
  real32_T LookupRightVector_o1_j;     /* '<S28>/Look up Right Vector' */
  real32_T LookupRightVector_o2_o;     /* '<S28>/Look up Right Vector' */
  real32_T LookupP_o1_k0;              /* '<S29>/Look up P' */
  real32_T LookupP_o2_h;               /* '<S29>/Look up P' */
  real32_T LookupRightVector_o1_jm;    /* '<S29>/Look up Right Vector' */
  real32_T LookupRightVector_o2_bf;    /* '<S29>/Look up Right Vector' */
  real32_T SFunctionBuilder_o1;        /* '<S30>/S-Function Builder' */
  real32_T SFunctionBuilder_o2;        /* '<S30>/S-Function Builder' */
  real32_T SFunctionBuilder_o3;        /* '<S30>/S-Function Builder' */
  real32_T LookupRightVector_o1_c;     /* '<S35>/Look up Right Vector' */
  real32_T LookupRightVector_o2_hx;    /* '<S35>/Look up Right Vector' */
  uint32_T DataTypeConversion;         /* '<S7>/Data Type Conversion' */
  uint16_T eTimerCNTRRegisterRead;     /* '<S6>/eTimer CNTR Register Read' */
  uint16_T CAN_Receive_data_o4;        /* '<S11>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4;       /* '<S11>/CAN_Receive_data1' */
  uint16_T ADCChannel;                 /* '<S6>/ADC Channel' */
  uint8_T CAN_Receive_data_o1;         /* '<S11>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2;         /* '<S11>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3[8];      /* '<S11>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1;        /* '<S11>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2;        /* '<S11>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3[8];     /* '<S11>/CAN_Receive_data1' */
  uint8_T SingletoBytes[4];            /* '<S16>/Single to Bytes' */
  uint8_T SingletoBytes1[4];           /* '<S16>/Single to Bytes1' */
  uint8_T TmpSignalConversionAtCANTransmi[8];
  uint8_T SingletoBytes2[4];           /* '<S16>/Single to Bytes2' */
  uint8_T SingletoBytes3[4];           /* '<S16>/Single to Bytes3' */
  uint8_T TmpSignalConversionAtCANTrans_g[8];
  uint8_T SingletoBytes_a[4];          /* '<S4>/Single to Bytes' */
  uint8_T SingletoBytes1_g[4];         /* '<S4>/Single to Bytes1' */
  uint8_T SingletoBytes2_h[4];         /* '<S4>/Single to Bytes2' */
  uint8_T SingletoBytes3_g[4];         /* '<S4>/Single to Bytes3' */
  uint8_T SingletoBytes4[4];           /* '<S4>/Single to Bytes4' */
  uint8_T SingletoBytes5[4];           /* '<S4>/Single to Bytes5' */
  uint8_T SingletoBytes6[4];           /* '<S4>/Single to Bytes6' */
  uint8_T SingletoBytes7[4];           /* '<S4>/Single to Bytes7' */
  uint8_T SingletoBytes8[4];           /* '<S4>/Single to Bytes8' */
  uint8_T SingletoBytes9[4];           /* '<S4>/Single to Bytes9' */
  uint8_T SingletoBytes10[4];          /* '<S4>/Single to Bytes10' */
  uint8_T SingletoBytes11[4];          /* '<S4>/Single to Bytes11' */
  uint8_T SingletoBytes12[4];          /* '<S4>/Single to Bytes12' */
  uint8_T SingletoBytes13[4];          /* '<S4>/Single to Bytes13' */
  uint8_T SingletoBytes14[4];          /* '<S4>/Single to Bytes14' */
  uint8_T SingletoBytes15[4];          /* '<S4>/Single to Bytes15' */
  uint8_T SingletoBytes16[4];          /* '<S4>/Single to Bytes16' */
  uint8_T SingletoBytes17[4];          /* '<S4>/Single to Bytes17' */
  uint8_T SingletoBytes18[4];          /* '<S4>/Single to Bytes18' */
  uint8_T SingletoBytes19[4];          /* '<S4>/Single to Bytes19' */
  uint8_T SingletoBytes20[4];          /* '<S4>/Single to Bytes20' */
  uint8_T SingletoBytes21[4];          /* '<S4>/Single to Bytes21' */
  uint8_T IndexVector;                 /* '<S39>/Index Vector' */
  boolean_T DigitalInput;              /* '<S6>/Digital Input' */
  boolean_T DigitalInput1;             /* '<S6>/Digital Input1' */
} BlockIO_template_Final_Project_;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Controller_DSTATE;            /* '<S32>/Controller' */
  real32_T UnitDelay1_DSTATE;          /* '<S10>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S30>/Discrete-Time Integrator3' */
  real32_T UnitDelay_DSTATE;           /* '<S36>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S30>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S30>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S30>/Discrete-Time Integrator2' */
  uint32_T HighLevelDesign_ELAPS_T;    /* '<Root>/High-Level Design' */
  uint32_T HighLevelDesign_PREV_T;     /* '<Root>/High-Level Design' */
  uint16_T UnitDelay_DSTATE_e;         /* '<S10>/Unit Delay' */
} D_Work_template_Final_Project_M;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S30>/Constant'
   */
  real32_T Constant_Value;

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S30>/Constant1'
   */
  real32_T Constant1_Value;
} ConstParam_template_Final_Proje;

/* Real-time Model Data Structure */
struct RT_MODEL_template_Final_Project {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (auto storage) */
extern BlockIO_template_Final_Project_ template_Final_Project_MPC564_B;

/* Block states (auto storage) */
extern D_Work_template_Final_Project_M template_Final_Project_MP_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_template_Final_Proje template_Final_Project_M_ConstP;

/* External function called from main */
extern void template_Final_Project_MPC5643L_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void template_Final_Project_MPC5643L_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void template_Final_Project_MPC5643L_initialize(boolean_T firstTime);
extern void template_Final_Project_MPC5643L_step(int_T tid);
extern void template_Final_Project_MPC5643L_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_template_Final_Project *const
  template_Final_Project_MPC56_M;

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
 * '<Root>' : 'template_Final_Project_MPC5643L'
 * '<S1>'   : 'template_Final_Project_MPC5643L/High-Level Design'
 * '<S2>'   : 'template_Final_Project_MPC5643L/Model Info'
 * '<S3>'   : 'template_Final_Project_MPC5643L/SC Filter'
 * '<S4>'   : 'template_Final_Project_MPC5643L/Serial'
 * '<S5>'   : 'template_Final_Project_MPC5643L/High-Level Design/ACC'
 * '<S6>'   : 'template_Final_Project_MPC5643L/High-Level Design/Inputs'
 * '<S7>'   : 'template_Final_Project_MPC5643L/High-Level Design/Outputs'
 * '<S8>'   : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model'
 * '<S9>'   : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars'
 * '<S10>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Scale1'
 * '<S11>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/GSI Car'
 * '<S12>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Zeros (16)'
 * '<S13>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi'
 * '<S14>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)'
 * '<S15>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Scale'
 * '<S16>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Tx CAN'
 * '<S17>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi/s,n to x,y'
 * '<S18>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi'
 * '<S19>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1'
 * '<S20>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2'
 * '<S21>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3'
 * '<S22>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4'
 * '<S23>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5'
 * '<S24>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi/s,n to x,y'
 * '<S25>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1/s,n to x,y'
 * '<S26>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2/s,n to x,y'
 * '<S27>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3/s,n to x,y'
 * '<S28>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4/s,n to x,y'
 * '<S29>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5/s,n to x,y'
 * '<S30>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/Subsystem'
 * '<S31>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/u to us'
 * '<S32>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n'
 * '<S33>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/u to us/Look up the Forward Vector'
 * '<S34>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/Data Type Conversion Inherited'
 * '<S35>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/Look up the Forward Vector'
 * '<S36>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/My Discrete Integrator'
 * '<S37>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/My Dot Product1'
 * '<S38>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/My Dot Product2'
 * '<S39>'  : 'template_Final_Project_MPC5643L/Serial/For Iterator Subsystem'
 */
#endif                                 /* RTW_HEADER_template_Final_Project_MPC5643L_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
