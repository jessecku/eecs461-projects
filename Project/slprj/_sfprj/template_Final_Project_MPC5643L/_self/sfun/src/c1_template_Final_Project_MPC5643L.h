#ifndef __c1_template_Final_Project_MPC5643L_h__
#define __c1_template_Final_Project_MPC5643L_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  const mxArray *c1_setSimStateSideEffectsInfo;
  int32_T c1_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_isStable;
  uint8_T c1_doSetSimStateSideEffects;
  uint8_T c1_is_active_c1_template_Final_Project_MPC5643L;
  uint8_T c1_is_c1_template_Final_Project_MPC5643L;
  uint8_T c1_tp_ManCTRL;
  uint8_T c1_tp_PosCTRL;
  uint8_T c1_tp_SpeedCTRL;
  ChartInfoStruct chartInfo;
} SFc1_template_Final_Project_MPC5643LInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_template_Final_Project_MPC5643L_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_template_Final_Project_MPC5643L_get_check_sum(mxArray *plhs[]);
extern void c1_template_Final_Project_MPC5643L_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
