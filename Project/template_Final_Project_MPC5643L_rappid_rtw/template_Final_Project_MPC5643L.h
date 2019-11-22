/*
 * File: template_Final_Project_MPC5643L.h
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
  real32_T BytestoSingle;              /* '<S22>/Bytes to Single' */
  real32_T BytestoSingle1;             /* '<S22>/Bytes to Single1' */
  real32_T BytestoSingle2;             /* '<S22>/Bytes to Single2' */
  real32_T BytestoSingle3;             /* '<S22>/Bytes to Single3' */
  real32_T BytestoSingle_d;            /* '<S23>/Bytes to Single' */
  real32_T BytestoSingle1_d;           /* '<S23>/Bytes to Single1' */
  real32_T BytestoSingle2_d;           /* '<S23>/Bytes to Single2' */
  real32_T BytestoSingle3_i;           /* '<S23>/Bytes to Single3' */
  real32_T BytestoSingle_c;            /* '<S24>/Bytes to Single' */
  real32_T BytestoSingle1_c;           /* '<S24>/Bytes to Single1' */
  real32_T BytestoSingle2_p;           /* '<S24>/Bytes to Single2' */
  real32_T BytestoSingle3_n;           /* '<S24>/Bytes to Single3' */
  real32_T BytestoSingle_h;            /* '<S25>/Bytes to Single' */
  real32_T BytestoSingle1_h;           /* '<S25>/Bytes to Single1' */
  real32_T BytestoSingle2_e;           /* '<S25>/Bytes to Single2' */
  real32_T BytestoSingle3_ny;          /* '<S25>/Bytes to Single3' */
  real32_T BytestoSingle_l;            /* '<S26>/Bytes to Single' */
  real32_T BytestoSingle1_n;           /* '<S26>/Bytes to Single1' */
  real32_T BytestoSingle2_g;           /* '<S26>/Bytes to Single2' */
  real32_T BytestoSingle3_l;           /* '<S26>/Bytes to Single3' */
  real32_T BytestoSingle_f;            /* '<S27>/Bytes to Single' */
  real32_T BytestoSingle1_hp;          /* '<S27>/Bytes to Single1' */
  real32_T BytestoSingle2_l;           /* '<S27>/Bytes to Single2' */
  real32_T BytestoSingle3_it;          /* '<S27>/Bytes to Single3' */
  real32_T BytestoSingle_cu;           /* '<S28>/Bytes to Single' */
  real32_T BytestoSingle1_j;           /* '<S28>/Bytes to Single1' */
  real32_T BytestoSingle2_ey;          /* '<S28>/Bytes to Single2' */
  real32_T BytestoSingle3_h;           /* '<S28>/Bytes to Single3' */
  real32_T Switch[24];                 /* '<S19>/Switch' */
  real32_T Gain1;                      /* '<S20>/Gain1' */
  real32_T UnitDelay;                  /* '<S53>/Unit Delay' */
  real32_T SFunctionBuilder_o1;        /* '<S15>/S-Function Builder' */
  real32_T SFunctionBuilder_o2;        /* '<S15>/S-Function Builder' */
  real32_T LookupRightVector_o1;       /* '<S50>/Look up Right Vector' */
  real32_T LookupRightVector_o2;       /* '<S50>/Look up Right Vector' */
  real32_T DiscreteTimeIntegrator2;    /* '<S47>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3;    /* '<S47>/Discrete-Time Integrator3' */
  real32_T Product2;                   /* '<S48>/Product2' */
  real32_T LookupP_o1;                 /* '<S49>/Look up P' */
  real32_T LookupP_o2;                 /* '<S49>/Look up P' */
  real32_T LookupRightVector_o1_d;     /* '<S49>/Look up Right Vector' */
  real32_T LookupRightVector_o2_m;     /* '<S49>/Look up Right Vector' */
  real32_T Sum1;                       /* '<S55>/Sum1' */
  real32_T LookupP_o1_c;               /* '<S34>/Look up P' */
  real32_T LookupP_o2_b;               /* '<S34>/Look up P' */
  real32_T LookupRightVector_o1_b;     /* '<S34>/Look up Right Vector' */
  real32_T LookupRightVector_o2_h;     /* '<S34>/Look up Right Vector' */
  real32_T LookupP_o1_k;               /* '<S41>/Look up P' */
  real32_T LookupP_o2_c;               /* '<S41>/Look up P' */
  real32_T LookupRightVector_o1_l;     /* '<S41>/Look up Right Vector' */
  real32_T LookupRightVector_o2_c;     /* '<S41>/Look up Right Vector' */
  real32_T LookupP_o1_e;               /* '<S42>/Look up P' */
  real32_T LookupP_o2_g;               /* '<S42>/Look up P' */
  real32_T LookupRightVector_o1_o;     /* '<S42>/Look up Right Vector' */
  real32_T LookupRightVector_o2_hm;    /* '<S42>/Look up Right Vector' */
  real32_T LookupP_o1_g;               /* '<S43>/Look up P' */
  real32_T LookupP_o2_j;               /* '<S43>/Look up P' */
  real32_T LookupRightVector_o1_a;     /* '<S43>/Look up Right Vector' */
  real32_T LookupRightVector_o2_i;     /* '<S43>/Look up Right Vector' */
  real32_T LookupP_o1_i;               /* '<S44>/Look up P' */
  real32_T LookupP_o2_a;               /* '<S44>/Look up P' */
  real32_T LookupRightVector_o1_am;    /* '<S44>/Look up Right Vector' */
  real32_T LookupRightVector_o2_l;     /* '<S44>/Look up Right Vector' */
  real32_T LookupP_o1_o;               /* '<S45>/Look up P' */
  real32_T LookupP_o2_k;               /* '<S45>/Look up P' */
  real32_T LookupRightVector_o1_j;     /* '<S45>/Look up Right Vector' */
  real32_T LookupRightVector_o2_o;     /* '<S45>/Look up Right Vector' */
  real32_T LookupP_o1_k0;              /* '<S46>/Look up P' */
  real32_T LookupP_o2_h;               /* '<S46>/Look up P' */
  real32_T LookupRightVector_o1_jm;    /* '<S46>/Look up Right Vector' */
  real32_T LookupRightVector_o2_b;     /* '<S46>/Look up Right Vector' */
  real32_T SFunctionBuilder_o1_j;      /* '<S47>/S-Function Builder' */
  real32_T SFunctionBuilder_o2_f;      /* '<S47>/S-Function Builder' */
  real32_T SFunctionBuilder_o3;        /* '<S47>/S-Function Builder' */
  real32_T Merge;                      /* '<S5>/Merge' */
  real32_T LookupRightVector_o1_c;     /* '<S52>/Look up Right Vector' */
  real32_T LookupRightVector_o2_hx;    /* '<S52>/Look up Right Vector' */
  real32_T Sum4;                       /* '<S13>/Sum4' */
  real32_T state;                      /* '<S9>/Chart' */
  uint32_T DataTypeConversion;         /* '<S7>/Data Type Conversion' */
  uint16_T eTimerCNTRRegisterRead;     /* '<S6>/eTimer CNTR Register Read' */
  uint16_T CAN_Receive_data_o4;        /* '<S22>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4;       /* '<S22>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data_o4_j;      /* '<S23>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4_o;     /* '<S23>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data_o4_i;      /* '<S24>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4_m;     /* '<S24>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data_o4_d;      /* '<S25>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4_d;     /* '<S25>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data_o4_p;      /* '<S26>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4_mp;    /* '<S26>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data_o4_ie;     /* '<S27>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4_dc;    /* '<S27>/CAN_Receive_data1' */
  uint16_T CAN_Receive_data_o4_h;      /* '<S28>/CAN_Receive_data' */
  uint16_T CAN_Receive_data1_o4_f;     /* '<S28>/CAN_Receive_data1' */
  uint16_T ADCChannel;                 /* '<S6>/ADC Channel' */
  uint8_T CAN_Receive_data_o1;         /* '<S22>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2;         /* '<S22>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3[8];      /* '<S22>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1;        /* '<S22>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2;        /* '<S22>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3[8];     /* '<S22>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data_o1_b;       /* '<S23>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2_c;       /* '<S23>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3_l[8];    /* '<S23>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1_c;      /* '<S23>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2_d;      /* '<S23>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3_c[8];   /* '<S23>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data_o1_p;       /* '<S24>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2_ci;      /* '<S24>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3_f[8];    /* '<S24>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1_g;      /* '<S24>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2_k;      /* '<S24>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3_a[8];   /* '<S24>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data_o1_c;       /* '<S25>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2_m;       /* '<S25>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3_p[8];    /* '<S25>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1_ci;     /* '<S25>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2_c;      /* '<S25>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3_aw[8];  /* '<S25>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data_o1_n;       /* '<S26>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2_h;       /* '<S26>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3_m[8];    /* '<S26>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1_p;      /* '<S26>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2_i;      /* '<S26>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3_p[8];   /* '<S26>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data_o1_o;       /* '<S27>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2_cj;      /* '<S27>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3_c[8];    /* '<S27>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1_d;      /* '<S27>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2_e;      /* '<S27>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3_n[8];   /* '<S27>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data_o1_e;       /* '<S28>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o2_p;       /* '<S28>/CAN_Receive_data' */
  uint8_T CAN_Receive_data_o3_p2[8];   /* '<S28>/CAN_Receive_data' */
  uint8_T CAN_Receive_data1_o1_pw;     /* '<S28>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o2_n;      /* '<S28>/CAN_Receive_data1' */
  uint8_T CAN_Receive_data1_o3_cc[8];  /* '<S28>/CAN_Receive_data1' */
  uint8_T SingletoBytes[4];            /* '<S33>/Single to Bytes' */
  uint8_T SingletoBytes1[4];           /* '<S33>/Single to Bytes1' */
  uint8_T TmpSignalConversionAtCANTransmi[8];
  uint8_T SingletoBytes2[4];           /* '<S33>/Single to Bytes2' */
  uint8_T SingletoBytes3[4];           /* '<S33>/Single to Bytes3' */
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
  uint8_T IndexVector;                 /* '<S56>/Index Vector' */
  boolean_T DigitalInput;              /* '<S6>/Digital Input' */
  boolean_T DigitalInput_h;            /* '<S21>/Digital Input' */
  boolean_T DigitalInput1;             /* '<S21>/Digital Input1' */
  boolean_T DigitalInput2;             /* '<S21>/Digital Input2' */
  boolean_T DigitalInput3;             /* '<S21>/Digital Input3' */
  boolean_T DigitalInput4;             /* '<S21>/Digital Input4' */
  boolean_T DigitalInput6;             /* '<S21>/Digital Input6' */
  boolean_T DigitalInput7;             /* '<S21>/Digital Input7' */
  boolean_T DigitalInput5;             /* '<S21>/Digital Input5' */
  boolean_T DigitalInput1_i;           /* '<S6>/Digital Input1' */
  boolean_T DataTypeConversion_d;      /* '<S18>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S18>/Data Type Conversion1' */
  boolean_T DataTypeConversion10;      /* '<S18>/Data Type Conversion10' */
  boolean_T DataTypeConversion11;      /* '<S18>/Data Type Conversion11' */
  boolean_T DataTypeConversion12;      /* '<S18>/Data Type Conversion12' */
  boolean_T DataTypeConversion13;      /* '<S18>/Data Type Conversion13' */
  boolean_T DataTypeConversion14;      /* '<S18>/Data Type Conversion14' */
  boolean_T DataTypeConversion15;      /* '<S18>/Data Type Conversion15' */
  boolean_T DataTypeConversion2;       /* '<S18>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S18>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S18>/Data Type Conversion4' */
  boolean_T DataTypeConversion5;       /* '<S18>/Data Type Conversion5' */
  boolean_T DataTypeConversion6;       /* '<S18>/Data Type Conversion6' */
  boolean_T DataTypeConversion7;       /* '<S18>/Data Type Conversion7' */
  boolean_T DataTypeConversion8;       /* '<S18>/Data Type Conversion8' */
  boolean_T DataTypeConversion9;       /* '<S18>/Data Type Conversion9' */
  boolean_T speed_en;                  /* '<S9>/Chart' */
  boolean_T pos_en;                    /* '<S9>/Chart' */
  boolean_T man_en;                    /* '<S9>/Chart' */
} BlockIO_template_Final_Project_;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Controller_DSTATE;            /* '<S49>/Controller' */
  real32_T UnitDelay1_DSTATE;          /* '<S20>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S53>/Unit Delay' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S47>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S47>/Discrete-Time Integrator3' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S47>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S47>/Discrete-Time Integrator1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S13>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_o;        /* '<S13>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S13>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_j;         /* '<S17>/Unit Delay' */
  uint32_T HighLevelDesign_ELAPS_T;    /* '<Root>/High-Level Design' */
  uint32_T HighLevelDesign_PREV_T;     /* '<Root>/High-Level Design' */
  uint32_T autosteering_ELAPS_T;       /* '<S5>/auto steering' */
  uint32_T autosteering_PREV_T;        /* '<S5>/auto steering' */
  uint16_T UnitDelay_DSTATE_e;         /* '<S20>/Unit Delay' */
  uint8_T is_active_c1_template_Final_Pro;/* '<S9>/Chart' */
  uint8_T is_c1_template_Final_Project_MP;/* '<S9>/Chart' */
} D_Work_template_Final_Project_M;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: H)
   * Referenced by:
   *   '<S5>/Constant1'
   *   '<S9>/Constant'
   */
  real32_T pooled11;

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S47>/Constant'
   */
  real32_T Constant_Value;

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S47>/Constant1'
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
 * '<S9>'   : 'template_Final_Project_MPC5643L/High-Level Design/ACC/ACC State Logic'
 * '<S10>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/Enabled Subsystem'
 * '<S11>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/Position Ctrl'
 * '<S12>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/Speed Ctrl'
 * '<S13>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/auto steering'
 * '<S14>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/ACC State Logic/Chart'
 * '<S15>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/ACC State Logic/Pick_Lead'
 * '<S16>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/Speed Ctrl/PI'
 * '<S17>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/Speed Ctrl/PI/My Discrete Integrator'
 * '<S18>'  : 'template_Final_Project_MPC5643L/High-Level Design/ACC/auto steering/16bit LED'
 * '<S19>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars'
 * '<S20>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Scale1'
 * '<S21>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Speed_input'
 * '<S22>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Car1'
 * '<S23>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Car2'
 * '<S24>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Car3'
 * '<S25>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Car4'
 * '<S26>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Car5'
 * '<S27>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Car6'
 * '<S28>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/GSI Car'
 * '<S29>'  : 'template_Final_Project_MPC5643L/High-Level Design/Inputs/Other Cars/Zeros (20)'
 * '<S30>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi'
 * '<S31>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)'
 * '<S32>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Scale'
 * '<S33>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Tx CAN'
 * '<S34>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi/s,n to x,y'
 * '<S35>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi'
 * '<S36>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1'
 * '<S37>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2'
 * '<S38>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3'
 * '<S39>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4'
 * '<S40>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5'
 * '<S41>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi/s,n to x,y'
 * '<S42>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1/s,n to x,y'
 * '<S43>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2/s,n to x,y'
 * '<S44>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3/s,n to x,y'
 * '<S45>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4/s,n to x,y'
 * '<S46>'  : 'template_Final_Project_MPC5643L/High-Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5/s,n to x,y'
 * '<S47>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/Subsystem'
 * '<S48>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/u to us'
 * '<S49>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n'
 * '<S50>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/u to us/Look up the Forward Vector'
 * '<S51>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/Data Type Conversion Inherited'
 * '<S52>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/Look up the Forward Vector'
 * '<S53>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/My Discrete Integrator'
 * '<S54>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/My Dot Product1'
 * '<S55>'  : 'template_Final_Project_MPC5643L/High-Level Design/Vehicle_Model/x,y to s,n/My Dot Product2'
 * '<S56>'  : 'template_Final_Project_MPC5643L/Serial/For Iterator Subsystem'
 */
#endif                                 /* RTW_HEADER_template_Final_Project_MPC5643L_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
