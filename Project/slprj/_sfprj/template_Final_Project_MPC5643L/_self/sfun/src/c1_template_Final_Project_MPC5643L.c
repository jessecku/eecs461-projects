/* Include files */

#include "blascompat32.h"
#include "template_Final_Project_MPC5643L_sfun.h"
#include "c1_template_Final_Project_MPC5643L.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "template_Final_Project_MPC5643L_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD          (0U)
#define c1_IN_PosCTRL                  (2U)
#define c1_IN_SpeedCTRL                (3U)
#define c1_IN_ManCTRL                  (1U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void initialize_params_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void enable_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void disable_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void set_sim_state_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void finalize_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void sf_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void initSimStructsc1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_b_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_PosCTRL, const char_T *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_d_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_speed_en, const char_T *c1_identifier);
static boolean_T c1_e_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static real32_T c1_f_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_state, const char_T *c1_identifier);
static real32_T c1_g_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_i_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  boolean_T *c1_speed_en;
  boolean_T *c1_pos_en;
  boolean_T *c1_man_en;
  real32_T *c1_state;
  c1_state = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_man_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_pos_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_speed_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_ManCTRL = 0U;
  chartInstance->c1_tp_PosCTRL = 0U;
  chartInstance->c1_tp_SpeedCTRL = 0U;
  chartInstance->c1_is_active_c1_template_Final_Project_MPC5643L = 0U;
  chartInstance->c1_is_c1_template_Final_Project_MPC5643L = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_speed_en = FALSE;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c1_pos_en = FALSE;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    *c1_man_en = FALSE;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 4) != 0)) {
    *c1_state = 0.0F;
  }
}

static void initialize_params_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
}

static void enable_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((uint32_T)chartInstance->c1_is_active_c1_template_Final_Project_MPC5643L ==
      1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_template_Final_Project_MPC5643L == c1_IN_PosCTRL)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_template_Final_Project_MPC5643L == c1_IN_SpeedCTRL)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_template_Final_Project_MPC5643L == c1_IN_ManCTRL)
  {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  boolean_T c1_u;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b_hoistedGlobal;
  boolean_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  boolean_T c1_c_hoistedGlobal;
  boolean_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real32_T c1_d_hoistedGlobal;
  real32_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  boolean_T *c1_man_en;
  boolean_T *c1_pos_en;
  boolean_T *c1_speed_en;
  real32_T *c1_state;
  c1_state = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_man_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_pos_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_speed_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6), FALSE);
  c1_hoistedGlobal = *c1_man_en;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_pos_en;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_speed_en;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_state;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal =
    chartInstance->c1_is_active_c1_template_Final_Project_MPC5643L;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_c1_template_Final_Project_MPC5643L;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_man_en;
  boolean_T *c1_pos_en;
  boolean_T *c1_speed_en;
  real32_T *c1_state;
  c1_state = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_man_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_pos_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_speed_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_man_en = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "man_en");
  *c1_pos_en = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "pos_en");
  *c1_speed_en = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 2)), "speed_en");
  *c1_state = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "state");
  chartInstance->c1_is_active_c1_template_Final_Project_MPC5643L =
    c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "is_active_c1_template_Final_Project_MPC5643L");
  chartInstance->c1_is_c1_template_Final_Project_MPC5643L =
    c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
    "is_c1_template_Final_Project_MPC5643L");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 6)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_template_Final_Project_MPC5643L(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_template_Final_Project_MPC5643L == c1_IN_ManCTRL)
    {
      chartInstance->c1_tp_ManCTRL = 1U;
    } else {
      chartInstance->c1_tp_ManCTRL = 0U;
    }

    if (chartInstance->c1_is_c1_template_Final_Project_MPC5643L == c1_IN_PosCTRL)
    {
      chartInstance->c1_tp_PosCTRL = 1U;
    } else {
      chartInstance->c1_tp_PosCTRL = 0U;
    }

    if (chartInstance->c1_is_c1_template_Final_Project_MPC5643L ==
        c1_IN_SpeedCTRL) {
      chartInstance->c1_tp_SpeedCTRL = 1U;
    } else {
      chartInstance->c1_tp_SpeedCTRL = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_temp;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_d_out;
  boolean_T c1_b_temp;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  boolean_T c1_g_out;
  boolean_T *c1_enable;
  boolean_T *c1_speed_en;
  boolean_T *c1_pos_en;
  boolean_T *c1_man_en;
  real32_T *c1_state;
  real32_T *c1_usi;
  real32_T *c1_us;
  real32_T *c1_si;
  real32_T *c1_s;
  real32_T *c1_H;
  c1_state = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_man_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_pos_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_speed_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_H = (real32_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_s = (real32_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_us = (real32_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_si = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_usi = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_enable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_template_Final_Project_MPC5643L(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if ((uint32_T)chartInstance->c1_is_active_c1_template_Final_Project_MPC5643L ==
      0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_template_Final_Project_MPC5643L = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_template_Final_Project_MPC5643L = c1_IN_ManCTRL;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_ManCTRL = 1U;
  } else {
    switch (chartInstance->c1_is_c1_template_Final_Project_MPC5643L) {
     case c1_IN_ManCTRL:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c1_sfEvent);
      c1_out = (boolean_T)CV_TRANSITION_EVAL(3U, !(_SFD_CCP_CALL(3U, 0,
        *c1_enable != 0U, chartInstance->c1_sfEvent) != 0));
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_ManCTRL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_template_Final_Project_MPC5643L =
          c1_IN_SpeedCTRL;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SpeedCTRL = 1U;
      } else {
        *c1_speed_en = FALSE;
        *c1_pos_en = FALSE;
        *c1_man_en = TRUE;
        *c1_state = 1.0F;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_PosCTRL:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c1_sfEvent);
      c1_temp = (_SFD_CCP_CALL(0U, 0, *c1_usi > *c1_us != 0U,
                  chartInstance->c1_sfEvent) != 0);
      if (!c1_temp) {
        c1_temp = (_SFD_CCP_CALL(0U, 1, *c1_si - *c1_s > *c1_H != 0U,
                    chartInstance->c1_sfEvent) != 0);
      }

      c1_b_out = (boolean_T)CV_TRANSITION_EVAL(0U, (int32_T)c1_temp);
      if (c1_b_out) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 0;
          sf_debug_transition_conflict_check_begin();
          c1_c_out = *c1_enable;
          if (c1_c_out) {
            transitionList[numTransitions] = 4;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_PosCTRL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_template_Final_Project_MPC5643L =
          c1_IN_SpeedCTRL;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SpeedCTRL = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c1_sfEvent);
        c1_d_out = (boolean_T)CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U,
          0, *c1_enable != 0U, chartInstance->c1_sfEvent));
        if (c1_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_PosCTRL = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_template_Final_Project_MPC5643L =
            c1_IN_ManCTRL;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_ManCTRL = 1U;
        } else {
          *c1_speed_en = FALSE;
          *c1_pos_en = TRUE;
          *c1_man_en = FALSE;
          *c1_state = 4.0F;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     case c1_IN_SpeedCTRL:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      c1_b_temp = (_SFD_CCP_CALL(1U, 0, *c1_usi <= *c1_us != 0U,
        chartInstance->c1_sfEvent) != 0);
      if (c1_b_temp) {
        c1_b_temp = (_SFD_CCP_CALL(1U, 1, *c1_si - *c1_s <= *c1_H != 0U,
          chartInstance->c1_sfEvent) != 0);
      }

      c1_e_out = (boolean_T)CV_TRANSITION_EVAL(1U, (int32_T)c1_b_temp);
      if (c1_e_out) {
        if (sf_debug_transition_conflict_check_enabled()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 1;
          sf_debug_transition_conflict_check_begin();
          c1_f_out = *c1_enable;
          if (c1_f_out) {
            transitionList[numTransitions] = 2;
            numTransitions++;
          }

          sf_debug_transition_conflict_check_end();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_SpeedCTRL = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_c1_template_Final_Project_MPC5643L = c1_IN_PosCTRL;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_PosCTRL = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c1_sfEvent);
        c1_g_out = (boolean_T)CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U,
          0, *c1_enable != 0U, chartInstance->c1_sfEvent));
        if (c1_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_SpeedCTRL = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
          chartInstance->c1_is_c1_template_Final_Project_MPC5643L =
            c1_IN_ManCTRL;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
          chartInstance->c1_tp_ManCTRL = 1U;
        } else {
          *c1_speed_en = TRUE;
          *c1_pos_en = FALSE;
          *c1_man_en = FALSE;
          *c1_state = 2.0F;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c1_is_c1_template_Final_Project_MPC5643L =
        c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_template_Final_Project_MPC5643LMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_template_Final_Project_MPC5643L
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray
  *sf_c1_template_Final_Project_MPC5643L_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_b_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_b_tp_PosCTRL, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_PosCTRL),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_PosCTRL);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_PosCTRL;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_b_tp_PosCTRL = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_PosCTRL),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_PosCTRL);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_d_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_speed_en, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_speed_en),
    &c1_thisId);
  sf_mex_destroy(&c1_speed_en);
  return c1_y;
}

static boolean_T c1_e_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_speed_en;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_speed_en = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_speed_en),
    &c1_thisId);
  sf_mex_destroy(&c1_speed_en);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static real32_T c1_f_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_state, const char_T *c1_identifier)
{
  real32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_state), &c1_thisId);
  sf_mex_destroy(&c1_state);
  return c1_y;
}

static real32_T c1_g_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real32_T c1_y;
  real32_T c1_f0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_f0, 1, 1, 0U, 0, 0U, 0);
  c1_y = c1_f0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_state;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real32_T c1_y;
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
    chartInstanceVoid;
  c1_state = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_state), &c1_thisId);
  sf_mex_destroy(&c1_state);
  *(real32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_i_emlrt_marshallIn
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_template_Final_Project_MPC5643L_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4043756181U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(50976760U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2306063673U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(285479115U);
}

mxArray *sf_c1_template_Final_Project_MPC5643L_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("b7yWZlfk1NOq5buwjk2aXB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_template_Final_Project_MPC5643L
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[20],T\"man_en\",},{M[1],M[19],T\"pos_en\",},{M[1],M[18],T\"speed_en\",},{M[1],M[21],T\"state\",},{M[8],M[0],T\"is_active_c1_template_Final_Project_MPC5643L\",},{M[9],M[0],T\"is_c1_template_Final_Project_MPC5643L\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_template_Final_Project_MPC5643L_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
    chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_template_Final_Project_MPC5643LMachineNumber_,
           1,
           3,
           6,
           10,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_template_Final_Project_MPC5643LMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_template_Final_Project_MPC5643LMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_template_Final_Project_MPC5643LMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"enable");
          _SFD_SET_DATA_PROPS(1,1,1,0,"usi");
          _SFD_SET_DATA_PROPS(2,1,1,0,"si");
          _SFD_SET_DATA_PROPS(3,1,1,0,"us");
          _SFD_SET_DATA_PROPS(4,1,1,0,"s");
          _SFD_SET_DATA_PROPS(5,1,1,0,"H");
          _SFD_SET_DATA_PROPS(6,2,0,1,"speed_en");
          _SFD_SET_DATA_PROPS(7,2,0,1,"pos_en");
          _SFD_SET_DATA_PROPS(8,2,0,1,"man_en");
          _SFD_SET_DATA_PROPS(9,2,0,1,"state");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 15 };

          static unsigned int sEndGuardMap[] = { 9, 21 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(0,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3, 16 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(1,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_TRANS_COV_WTS(0,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 3, 15 };

          static unsigned int sEndGuardMap[] = { 9, 21 };

          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 3, 16 };

          static unsigned int sEndGuardMap[] = { 10, 23 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);

        {
          boolean_T *c1_enable;
          real32_T *c1_usi;
          real32_T *c1_si;
          real32_T *c1_us;
          real32_T *c1_s;
          real32_T *c1_H;
          boolean_T *c1_speed_en;
          boolean_T *c1_pos_en;
          boolean_T *c1_man_en;
          real32_T *c1_state;
          c1_state = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_man_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_pos_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_speed_en = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_H = (real32_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_s = (real32_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_us = (real32_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_si = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_usi = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_enable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_enable);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_usi);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_si);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_us);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_s);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_H);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_speed_en);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_pos_en);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_man_en);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_state);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_template_Final_Project_MPC5643LMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_template_Final_Project_MPC5643L(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
  initialize_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_template_Final_Project_MPC5643L(void
  *chartInstanceVar)
{
  enable_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_template_Final_Project_MPC5643L(void
  *chartInstanceVar)
{
  disable_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_template_Final_Project_MPC5643L(void
  *chartInstanceVar)
{
  sf_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_template_Final_Project_MPC5643L(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_template_Final_Project_MPC5643L();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_template_Final_Project_MPC5643L
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_template_Final_Project_MPC5643L();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_template_Final_Project_MPC5643L
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_template_Final_Project_MPC5643L(S);
}

static void sf_opaque_set_sim_state_c1_template_Final_Project_MPC5643L(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_template_Final_Project_MPC5643L(S, st);
}

static void sf_opaque_terminate_c1_template_Final_Project_MPC5643L(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_template_Final_Project_MPC5643LInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_template_Final_Project_MPC5643L
      ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_template_Final_Project_MPC5643L_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_template_Final_Project_MPC5643L
    ((SFc1_template_Final_Project_MPC5643LInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_template_Final_Project_MPC5643L(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_template_Final_Project_MPC5643L
      ((SFc1_template_Final_Project_MPC5643LInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_template_Final_Project_MPC5643L(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_template_Final_Project_MPC5643L_optimization_info
      ();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,1,4);
    }

    sf_set_rtw_dwork_info(S,infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1445254836U));
  ssSetChecksum1(S,(1428307631U));
  ssSetChecksum2(S,(1339892685U));
  ssSetChecksum3(S,(2659568431U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_template_Final_Project_MPC5643L(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_template_Final_Project_MPC5643L(SimStruct *S)
{
  SFc1_template_Final_Project_MPC5643LInstanceStruct *chartInstance;
  chartInstance = (SFc1_template_Final_Project_MPC5643LInstanceStruct *)malloc
    (sizeof(SFc1_template_Final_Project_MPC5643LInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_template_Final_Project_MPC5643LInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_template_Final_Project_MPC5643L;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_template_Final_Project_MPC5643L_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_template_Final_Project_MPC5643L(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_template_Final_Project_MPC5643L(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_template_Final_Project_MPC5643L(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_template_Final_Project_MPC5643L_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
