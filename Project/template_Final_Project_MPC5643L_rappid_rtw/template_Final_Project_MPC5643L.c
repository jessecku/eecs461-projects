/*
 * File: template_Final_Project_MPC5643L.c
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

#include "template_Final_Project_MPC5643L.h"
#include "template_Final_Project_MPC5643L_private.h"

/* Named constants for Chart: '<S9>/Chart' */
#define template_Final_Pro_IN_SpeedCTRL (3U)
#define template_Final_Proje_IN_ManCTRL (1U)
#define template_Final_Proje_IN_PosCTRL (2U)

/* Block signals (auto storage) */
BlockIO_template_Final_Project_ template_Final_Project_MPC564_B;

/* Block states (auto storage) */
D_Work_template_Final_Project_M template_Final_Project_MP_DWork;

/* Real-time model */
RT_MODEL_template_Final_Project template_Final_Project_MPC56_M_;
RT_MODEL_template_Final_Project *const template_Final_Project_MPC56_M =
  &template_Final_Project_MPC56_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void template_Final_Project_MPC5643L_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(template_Final_Project_MPC56_M, 1));
}

/* rate_monotonic_scheduler */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  template_Final_Project_MPC56_M->Timing.RateInteraction.TID0_1 =
    (template_Final_Project_MPC56_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (template_Final_Project_MPC56_M->Timing.TaskCounters.TID[1])++;
  if ((template_Final_Project_MPC56_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.05s, 0.0s] */
    template_Final_Project_MPC56_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void template_Final_Project_MPC5643L_step0(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion;
  real_T rtb_dsdt;
  uint8_T rtb_Sum_d;
  uint8_T rtb_DataTypeConversion1_a;
  uint8_T rtb_DataTypeConversion2;
  uint8_T rtb_DataTypeConversion3;
  uint8_T rtb_DataTypeConversion4;
  uint8_T rtb_DataTypeConversion5;
  uint8_T rtb_DataTypeConversion6;
  real32_T rtb_DiscreteTimeIntegrator_f;
  real32_T rtb_Sum1;
  real32_T rtb_DataTypeConversion_m;
  boolean_T rtb_LogicalOperator;
  real32_T rtb_Product_h;
  int16_T rtb_DataTypeConversion16;
  real32_T C_e_idx;
  real32_T C_e_idx_0;
  real32_T C_b_idx;
  real32_T C_b_idx_0;
  real32_T C_d_idx;
  real32_T C_d_idx_0;
  real32_T C_o_idx;
  real32_T C_o_idx_0;
  real32_T C_f_idx;
  real32_T C_f_idx_0;
  real32_T C_h_idx;
  real32_T C_h_idx_0;
  real32_T rtb_Product_c_idx;
  real32_T rtb_Product_c_idx_0;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  SubSystem: '<Root>/High-Level Design'
   */
  template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T =
    template_Final_Project_MPC56_M->Timing.clockTick0 -
    template_Final_Project_MP_DWork.HighLevelDesign_PREV_T;
  template_Final_Project_MP_DWork.HighLevelDesign_PREV_T =
    template_Final_Project_MPC56_M->Timing.clockTick0;

  /* S-Function (eTimer_564xL_cntr): '<S6>/eTimer CNTR Register Read' */
  template_Final_Project_MPC564_B.eTimerCNTRRegisterRead = mcTIMER0.CHANNEL[0].
    CNTR.R;

  /* S-Function (can_564xl_receive_data): '<S22>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 2)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1 = flexcan_564xl_get_id
        (0, 2);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 2);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2 =
        flexcan_564xl_get_idtype(0, 2);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4 = flexcan_564xl_get_ts
        (0, 2);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 2);
    }
  }

  /* S-Function (bytes2single): '<S22>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle) );

  /* S-Function (bytes2single): '<S22>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1) );

  /* S-Function (can_564xl_receive_data): '<S22>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 3)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1 =
        flexcan_564xl_get_id(0, 3);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 3);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2 =
        flexcan_564xl_get_idtype(0, 3);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4 =
        flexcan_564xl_get_ts(0, 3);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 3);
    }
  }

  /* S-Function (bytes2single): '<S22>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2) );

  /* S-Function (bytes2single): '<S22>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3) );

  /* S-Function (can_564xl_receive_data): '<S23>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 4)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1_b =
        flexcan_564xl_get_id(0, 4);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 4);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3_l)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2_c =
        flexcan_564xl_get_idtype(0, 4);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4_j =
        flexcan_564xl_get_ts(0, 4);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 4);
    }
  }

  /* S-Function (bytes2single): '<S23>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle_d), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_l[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle_d) );

  /* S-Function (bytes2single): '<S23>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1_d), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_l[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1_d) );

  /* S-Function (can_564xl_receive_data): '<S23>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 5)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1_c =
        flexcan_564xl_get_id(0, 5);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 5);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3_c)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2_d =
        flexcan_564xl_get_idtype(0, 5);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4_o =
        flexcan_564xl_get_ts(0, 5);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 5);
    }
  }

  /* S-Function (bytes2single): '<S23>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2_d), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_c[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2_d) );

  /* S-Function (bytes2single): '<S23>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3_i), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_c[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3_i) );

  /* S-Function (can_564xl_receive_data): '<S24>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 6)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1_p =
        flexcan_564xl_get_id(0, 6);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 6);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3_f)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2_ci =
        flexcan_564xl_get_idtype(0, 6);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4_i =
        flexcan_564xl_get_ts(0, 6);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 6);
    }
  }

  /* S-Function (bytes2single): '<S24>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle_c), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_f[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle_c) );

  /* S-Function (bytes2single): '<S24>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1_c), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_f[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1_c) );

  /* S-Function (can_564xl_receive_data): '<S24>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 7)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1_g =
        flexcan_564xl_get_id(0, 7);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 7);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3_a)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2_k =
        flexcan_564xl_get_idtype(0, 7);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4_m =
        flexcan_564xl_get_ts(0, 7);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 7);
    }
  }

  /* S-Function (bytes2single): '<S24>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2_p), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_a[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2_p) );

  /* S-Function (bytes2single): '<S24>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3_n), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_a[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3_n) );

  /* S-Function (can_564xl_receive_data): '<S25>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 8)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1_c =
        flexcan_564xl_get_id(0, 8);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 8);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3_p)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2_m =
        flexcan_564xl_get_idtype(0, 8);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4_d =
        flexcan_564xl_get_ts(0, 8);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 8);
    }
  }

  /* S-Function (bytes2single): '<S25>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle_h), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_p[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle_h) );

  /* S-Function (bytes2single): '<S25>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1_h), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_p[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1_h) );

  /* S-Function (can_564xl_receive_data): '<S25>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 9)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1_ci =
        flexcan_564xl_get_id(0, 9);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 9);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3_aw)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2_c =
        flexcan_564xl_get_idtype(0, 9);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4_d =
        flexcan_564xl_get_ts(0, 9);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 9);
    }
  }

  /* S-Function (bytes2single): '<S25>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2_e), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_aw[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2_e) );

  /* S-Function (bytes2single): '<S25>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3_ny), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_aw[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3_ny) );

  /* S-Function (can_564xl_receive_data): '<S26>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 10)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1_n =
        flexcan_564xl_get_id(0, 10);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 10);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3_m)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2_h =
        flexcan_564xl_get_idtype(0, 10);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4_p =
        flexcan_564xl_get_ts(0, 10);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 10);
    }
  }

  /* S-Function (bytes2single): '<S26>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle_l), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_m[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle_l) );

  /* S-Function (bytes2single): '<S26>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1_n), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_m[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1_n) );

  /* S-Function (can_564xl_receive_data): '<S26>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 11)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1_p =
        flexcan_564xl_get_id(0, 11);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 11);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3_p)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2_i =
        flexcan_564xl_get_idtype(0, 11);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4_mp =
        flexcan_564xl_get_ts(0, 11);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 11);
    }
  }

  /* S-Function (bytes2single): '<S26>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2_g), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_p[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2_g) );

  /* S-Function (bytes2single): '<S26>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3_l), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_p[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3_l) );

  /* S-Function (can_564xl_receive_data): '<S27>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 12)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1_o =
        flexcan_564xl_get_id(0, 12);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 12);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3_c)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2_cj =
        flexcan_564xl_get_idtype(0, 12);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4_ie =
        flexcan_564xl_get_ts(0, 12);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 12);
    }
  }

  /* S-Function (bytes2single): '<S27>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle_f), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_c[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle_f) );

  /* S-Function (bytes2single): '<S27>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1_hp), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_c[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1_hp) );

  /* S-Function (can_564xl_receive_data): '<S27>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 13)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1_d =
        flexcan_564xl_get_id(0, 13);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 13);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3_n)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2_e =
        flexcan_564xl_get_idtype(0, 13);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4_dc =
        flexcan_564xl_get_ts(0, 13);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 13);
    }
  }

  /* S-Function (bytes2single): '<S27>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2_l), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_n[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2_l) );

  /* S-Function (bytes2single): '<S27>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3_it), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_n[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3_it) );

  /* S-Function (can_564xl_receive_data): '<S28>/CAN_Receive_data' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 0)) {
      template_Final_Project_MPC564_B.CAN_Receive_data_o1_e =
        flexcan_564xl_get_id(0, 0);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 0);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data_o3_p2)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data_o2_p =
        flexcan_564xl_get_idtype(0, 0);
      template_Final_Project_MPC564_B.CAN_Receive_data_o4_h =
        flexcan_564xl_get_ts(0, 0);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 0);
    }
  }

  /* S-Function (bytes2single): '<S28>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle_cu), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_p2[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle_cu) );

  /* S-Function (bytes2single): '<S28>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1_j), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3_p2[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1_j) );

  /* S-Function (can_564xl_receive_data): '<S28>/CAN_Receive_data1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    if (flexcan_564xl_rxbuffull( 0, 1)) {
      template_Final_Project_MPC564_B.CAN_Receive_data1_o1_pw =
        flexcan_564xl_get_id(0, 1);
      flexcan_564xl_get_mb(ptr_FLEXCAN_MsgBufferStructure, 0, 1);
      for (i=0;i<ptr_FLEXCAN_MsgBufferStructure->length;i++) {
        (template_Final_Project_MPC564_B.CAN_Receive_data1_o3_cc)[i] =
          ptr_FLEXCAN_MsgBufferStructure->data[i];
      }

      template_Final_Project_MPC564_B.CAN_Receive_data1_o2_n =
        flexcan_564xl_get_idtype(0, 1);
      template_Final_Project_MPC564_B.CAN_Receive_data1_o4_f =
        flexcan_564xl_get_ts(0, 1);
      flexcan_564xl_release_mb_lock(0);
      flexcan_564xl_clear_mask(0, 1);
    }
  }

  /* S-Function (bytes2single): '<S28>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2_ey), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_cc[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2_ey) );

  /* S-Function (bytes2single): '<S28>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3_h), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3_cc[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3_h) );

  /* Switch: '<S19>/Switch' */
  template_Final_Project_MPC564_B.Switch[0] =
    template_Final_Project_MPC564_B.BytestoSingle;
  template_Final_Project_MPC564_B.Switch[1] =
    template_Final_Project_MPC564_B.BytestoSingle1;
  template_Final_Project_MPC564_B.Switch[2] =
    template_Final_Project_MPC564_B.BytestoSingle3;
  template_Final_Project_MPC564_B.Switch[3] =
    template_Final_Project_MPC564_B.BytestoSingle2;
  template_Final_Project_MPC564_B.Switch[4] =
    template_Final_Project_MPC564_B.BytestoSingle_d;
  template_Final_Project_MPC564_B.Switch[5] =
    template_Final_Project_MPC564_B.BytestoSingle1_d;
  template_Final_Project_MPC564_B.Switch[6] =
    template_Final_Project_MPC564_B.BytestoSingle3_i;
  template_Final_Project_MPC564_B.Switch[7] =
    template_Final_Project_MPC564_B.BytestoSingle2_d;
  template_Final_Project_MPC564_B.Switch[8] =
    template_Final_Project_MPC564_B.BytestoSingle_c;
  template_Final_Project_MPC564_B.Switch[9] =
    template_Final_Project_MPC564_B.BytestoSingle1_c;
  template_Final_Project_MPC564_B.Switch[10] =
    template_Final_Project_MPC564_B.BytestoSingle3_n;
  template_Final_Project_MPC564_B.Switch[11] =
    template_Final_Project_MPC564_B.BytestoSingle2_p;
  template_Final_Project_MPC564_B.Switch[12] =
    template_Final_Project_MPC564_B.BytestoSingle_h;
  template_Final_Project_MPC564_B.Switch[13] =
    template_Final_Project_MPC564_B.BytestoSingle1_h;
  template_Final_Project_MPC564_B.Switch[14] =
    template_Final_Project_MPC564_B.BytestoSingle3_ny;
  template_Final_Project_MPC564_B.Switch[15] =
    template_Final_Project_MPC564_B.BytestoSingle2_e;
  template_Final_Project_MPC564_B.Switch[16] =
    template_Final_Project_MPC564_B.BytestoSingle_l;
  template_Final_Project_MPC564_B.Switch[17] =
    template_Final_Project_MPC564_B.BytestoSingle1_n;
  template_Final_Project_MPC564_B.Switch[18] =
    template_Final_Project_MPC564_B.BytestoSingle3_l;
  template_Final_Project_MPC564_B.Switch[19] =
    template_Final_Project_MPC564_B.BytestoSingle2_g;
  template_Final_Project_MPC564_B.Switch[20] =
    template_Final_Project_MPC564_B.BytestoSingle_f;
  template_Final_Project_MPC564_B.Switch[21] =
    template_Final_Project_MPC564_B.BytestoSingle1_hp;
  template_Final_Project_MPC564_B.Switch[22] =
    template_Final_Project_MPC564_B.BytestoSingle3_it;
  template_Final_Project_MPC564_B.Switch[23] =
    template_Final_Project_MPC564_B.BytestoSingle2_l;

  /* S-Function (gpio_564xl_input): '<S6>/Digital Input' */
  template_Final_Project_MPC564_B.DigitalInput = gpi_pin_read_564xl_fnc(13);/* GPI Pin Data Input Registers  */

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input' */
  template_Final_Project_MPC564_B.DigitalInput_h = gpi_pin_read_564xl_fnc(5);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  rtb_Sum_d = template_Final_Project_MPC564_B.DigitalInput_h;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input1' */
  template_Final_Project_MPC564_B.DigitalInput1 = gpi_pin_read_564xl_fnc(6);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion1' */
  rtb_DataTypeConversion1_a = template_Final_Project_MPC564_B.DigitalInput1;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input2' */
  template_Final_Project_MPC564_B.DigitalInput2 = gpi_pin_read_564xl_fnc(7);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = template_Final_Project_MPC564_B.DigitalInput2;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input3' */
  template_Final_Project_MPC564_B.DigitalInput3 = gpi_pin_read_564xl_fnc(8);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion3' */
  rtb_DataTypeConversion3 = template_Final_Project_MPC564_B.DigitalInput3;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input4' */
  template_Final_Project_MPC564_B.DigitalInput4 = gpi_pin_read_564xl_fnc(9);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = template_Final_Project_MPC564_B.DigitalInput4;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input6' */
  template_Final_Project_MPC564_B.DigitalInput6 = gpi_pin_read_564xl_fnc(11);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion5' */
  rtb_DataTypeConversion5 = template_Final_Project_MPC564_B.DigitalInput6;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input7' */
  template_Final_Project_MPC564_B.DigitalInput7 = gpi_pin_read_564xl_fnc(12);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S21>/Data Type Conversion6' */
  rtb_DataTypeConversion6 = template_Final_Project_MPC564_B.DigitalInput7;

  /* S-Function (gpio_564xl_input): '<S21>/Digital Input5' */
  template_Final_Project_MPC564_B.DigitalInput5 = gpi_pin_read_564xl_fnc(10);/* GPI Pin Data Input Registers  */

  /* Sum: '<S21>/Sum' incorporates:
   *  ArithShift: '<S21>/Shift Arithmetic'
   *  ArithShift: '<S21>/Shift Arithmetic1'
   *  ArithShift: '<S21>/Shift Arithmetic2'
   *  ArithShift: '<S21>/Shift Arithmetic3'
   *  ArithShift: '<S21>/Shift Arithmetic5'
   *  ArithShift: '<S21>/Shift Arithmetic6'
   *  ArithShift: '<S21>/Shift Arithmetic7'
   *  DataTypeConversion: '<S21>/Data Type Conversion7'
   */
  rtb_Sum_d = (uint8_T)((((((((uint32_T)(rtb_DataTypeConversion1_a << 1) +
    (uint32_T)rtb_Sum_d) + (uint32_T)(rtb_DataTypeConversion2 << 2)) + (uint32_T)
                            (rtb_DataTypeConversion3 << 3)) + (uint32_T)
    (rtb_DataTypeConversion4 << 4)) + (uint32_T)
    (template_Final_Project_MPC564_B.DigitalInput5 << 5)) + (uint32_T)
    (rtb_DataTypeConversion5 << 6)) + (uint32_T)(rtb_DataTypeConversion6 << 7));

  /* Sum: '<S20>/Sum1' incorporates:
   *  DataTypeConversion: '<S20>/Data Type Conversion1'
   *  DataTypeConversion: '<S20>/Data Type Conversion2'
   *  Gain: '<S20>/Gain'
   *  Sum: '<S20>/Sum'
   *  UnitDelay: '<S20>/Unit Delay'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  rtb_Sum1 = (real32_T)(int16_T)(uint16_T)
    (template_Final_Project_MPC564_B.eTimerCNTRRegisterRead -
     template_Final_Project_MP_DWork.UnitDelay_DSTATE_e) * 0.09F +
    template_Final_Project_MP_DWork.UnitDelay1_DSTATE;

  /* Gain: '<S20>/Gain1' */
  template_Final_Project_MPC564_B.Gain1 = 0.00174532924F * rtb_Sum1;

  /* S-Function (adc_564xl_input): '<S6>/ADC Channel' */

  /* ADC Data Input ADC_0 Channel 0  */
  template_Final_Project_MPC564_B.ADCChannel = adc_read_chan( 0, 0 );

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  rtb_DataTypeConversion_m = (real32_T)
    template_Final_Project_MPC564_B.ADCChannel;

  /* S-Function (gpio_564xl_input): '<S6>/Digital Input1' */
  template_Final_Project_MPC564_B.DigitalInput1_i = gpi_pin_read_564xl_fnc(14);/* GPI Pin Data Input Registers  */

  /* Logic: '<S5>/Logical Operator' */
  rtb_LogicalOperator = !template_Final_Project_MPC564_B.DigitalInput;

  /* UnitDelay: '<S53>/Unit Delay' */
  template_Final_Project_MPC564_B.UnitDelay =
    template_Final_Project_MP_DWork.UnitDelay_DSTATE;

  /* S-Function (PL): '<S15>/S-Function Builder' */
  PL_Outputs_wrapper(&template_Final_Project_M_ConstP.pooled11,
                     template_Final_Project_MPC564_B.Switch,
                     &template_Final_Project_MPC564_B.UnitDelay,
                     &template_Final_Project_MPC564_B.SFunctionBuilder_o1,
                     &template_Final_Project_MPC564_B.SFunctionBuilder_o2 );

  /* S-Function (get_rvec1): '<S50>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1 = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2 = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1 = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2 = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator2' */
  template_Final_Project_MPC564_B.DiscreteTimeIntegrator2 =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Sum: '<S48>/Sum' */
  rtb_DiscreteTimeIntegrator_f =
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator2 +
    template_Final_Project_MPC564_B.Gain1;

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator3' */
  template_Final_Project_MPC564_B.DiscreteTimeIntegrator3 =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Product: '<S48>/Product2' incorporates:
   *  Gain: '<S50>/Gain'
   *  Product: '<S48>/Product'
   *  Product: '<S48>/Product1'
   *  Sum: '<S48>/Sum1'
   *  Trigonometry: '<S48>/Trigonometric Function'
   *  Trigonometry: '<S48>/Trigonometric Function1'
   */
  template_Final_Project_MPC564_B.Product2 =
    (template_Final_Project_MPC564_B.LookupRightVector_o1 * (real32_T)sin
     (rtb_DiscreteTimeIntegrator_f) +
     -template_Final_Project_MPC564_B.LookupRightVector_o2 * (real32_T)cos
     (rtb_DiscreteTimeIntegrator_f)) *
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator3;

  /* Chart: '<S9>/Chart' incorporates:
   *  Constant: '<S9>/Constant'
   */
  /* Gateway: High-Level Design/ACC/ACC State Logic/Chart */
  /* During: High-Level Design/ACC/ACC State Logic/Chart */
  if (template_Final_Project_MP_DWork.is_active_c1_template_Final_Pro == 0U) {
    /* Entry: High-Level Design/ACC/ACC State Logic/Chart */
    template_Final_Project_MP_DWork.is_active_c1_template_Final_Pro = 1U;

    /* Transition: '<S14>:17' */
    template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
      template_Final_Proje_IN_ManCTRL;
  } else {
    switch (template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP) {
     case template_Final_Proje_IN_ManCTRL:
      /* During 'ManCTRL': '<S14>:3' */
      if (!rtb_LogicalOperator) {
        /* Transition: '<S14>:7' */
        template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
          template_Final_Pro_IN_SpeedCTRL;
      } else {
        template_Final_Project_MPC564_B.speed_en = FALSE;
        template_Final_Project_MPC564_B.pos_en = FALSE;
        template_Final_Project_MPC564_B.man_en = TRUE;
        template_Final_Project_MPC564_B.state = 1.0F;
      }
      break;

     case template_Final_Proje_IN_PosCTRL:
      /* During 'PosCTRL': '<S14>:1' */
      if ((template_Final_Project_MPC564_B.SFunctionBuilder_o2 >
           template_Final_Project_MPC564_B.Product2) ||
          (template_Final_Project_MPC564_B.SFunctionBuilder_o1 -
           template_Final_Project_MPC564_B.UnitDelay > 10.0F)) {
        /* Transition: '<S14>:4' */
        template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
          template_Final_Pro_IN_SpeedCTRL;
      } else if (rtb_LogicalOperator) {
        /* Transition: '<S14>:8' */
        template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
          template_Final_Proje_IN_ManCTRL;
      } else {
        template_Final_Project_MPC564_B.speed_en = FALSE;
        template_Final_Project_MPC564_B.pos_en = TRUE;
        template_Final_Project_MPC564_B.man_en = FALSE;
        template_Final_Project_MPC564_B.state = 4.0F;
      }
      break;

     case template_Final_Pro_IN_SpeedCTRL:
      /* During 'SpeedCTRL': '<S14>:2' */
      if ((template_Final_Project_MPC564_B.SFunctionBuilder_o2 <=
           template_Final_Project_MPC564_B.Product2) &&
          (template_Final_Project_MPC564_B.SFunctionBuilder_o1 -
           template_Final_Project_MPC564_B.UnitDelay <= 10.0F)) {
        /* Transition: '<S14>:5' */
        template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
          template_Final_Proje_IN_PosCTRL;
      } else if (rtb_LogicalOperator) {
        /* Transition: '<S14>:6' */
        template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
          template_Final_Proje_IN_ManCTRL;
      } else {
        template_Final_Project_MPC564_B.speed_en = TRUE;
        template_Final_Project_MPC564_B.pos_en = FALSE;
        template_Final_Project_MPC564_B.man_en = FALSE;
        template_Final_Project_MPC564_B.state = 2.0F;
      }
      break;

     default:
      /* Transition: '<S14>:17' */
      template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP =
        template_Final_Proje_IN_ManCTRL;
      break;
    }
  }

  /* End of Chart: '<S9>/Chart' */

  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (template_Final_Project_MPC564_B.man_en) {
    /* Inport: '<S10>/Fd' */
    template_Final_Project_MPC564_B.Merge = rtb_DataTypeConversion_m;
  }

  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */

  /* Outputs for Enabled SubSystem: '<S5>/Position Ctrl' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (template_Final_Project_MPC564_B.pos_en) {
    /* Sum: '<S11>/Sum5' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Gain: '<S11>/D-gain'
     *  Gain: '<S11>/Feed-forward'
     *  Gain: '<S11>/P-gain'
     *  Sum: '<S11>/Sum1'
     *  Sum: '<S11>/Sum2'
     *  Sum: '<S11>/Sum3'
     *  Sum: '<S11>/Sum4'
     */
    template_Final_Project_MPC564_B.Merge = ((10.0F -
      (template_Final_Project_MPC564_B.SFunctionBuilder_o1 -
       template_Final_Project_MPC564_B.UnitDelay)) * -3000.0F +
      (template_Final_Project_MPC564_B.SFunctionBuilder_o2 -
       template_Final_Project_MPC564_B.Product2) * 4900.0F) + 100.0F *
      template_Final_Project_MPC564_B.SFunctionBuilder_o2;
  }

  /* End of Outputs for SubSystem: '<S5>/Position Ctrl' */

  /* Product: '<S5>/Product' incorporates:
   *  Gain: '<S5>/Gain'
   */
  rtb_Product_h = 100.0F *
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator3 *
    template_Final_Project_MPC564_B.Gain1;

  /* Outputs for Enabled SubSystem: '<S5>/Speed Ctrl' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (template_Final_Project_MPC564_B.speed_en) {
    /* Sum: '<S12>/Sum1' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion8'
     */
    rtb_DataTypeConversion_m = (real32_T)rtb_Sum_d -
      template_Final_Project_MPC564_B.DiscreteTimeIntegrator3;

    /* Sum: '<S12>/Sum' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion8'
     *  Gain: '<S12>/Gain'
     *  Gain: '<S16>/Gain1'
     *  Sum: '<S16>/Sum'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    template_Final_Project_MPC564_B.Merge = (5000.0F * rtb_DataTypeConversion_m
      + template_Final_Project_MP_DWork.UnitDelay_DSTATE_j) + 100.0F * (real32_T)
      rtb_Sum_d;

    /* Update for UnitDelay: '<S17>/Unit Delay' incorporates:
     *  Gain: '<S16>/Gain'
     *  Gain: '<S17>/Gain'
     *  Sum: '<S17>/Sum'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    template_Final_Project_MP_DWork.UnitDelay_DSTATE_j = 50.0F *
      rtb_DataTypeConversion_m * 0.01F +
      template_Final_Project_MP_DWork.UnitDelay_DSTATE_j;
  }

  /* End of Outputs for SubSystem: '<S5>/Speed Ctrl' */

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_f =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator1' */
  rtb_DataTypeConversion_m =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* S-Function (get_path1): '<S49>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1 = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2 = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1 = rs[i]
        .data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2 = rs[i]
        .data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S49>/Sum' */
  rtb_Product_c_idx_0 = rtb_DiscreteTimeIntegrator_f -
    template_Final_Project_MPC564_B.LookupP_o1;
  rtb_Product_c_idx = rtb_DataTypeConversion_m -
    template_Final_Project_MPC564_B.LookupP_o2;

  /* S-Function (get_rvec1): '<S49>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_d = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_m = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_d = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_m = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S55>/Sum1' incorporates:
   *  Product: '<S55>/Product'
   */
  template_Final_Project_MPC564_B.Sum1 = rtb_Product_c_idx_0 *
    template_Final_Project_MPC564_B.LookupRightVector_o1_d + rtb_Product_c_idx *
    template_Final_Project_MPC564_B.LookupRightVector_o2_m;

  /* Outputs for Enabled SubSystem: '<S5>/auto steering' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (template_Final_Project_MPC564_B.DigitalInput1_i) {
    template_Final_Project_MP_DWork.autosteering_ELAPS_T =
      template_Final_Project_MPC56_M->Timing.clockTick0 -
      template_Final_Project_MP_DWork.autosteering_PREV_T;
    template_Final_Project_MP_DWork.autosteering_PREV_T =
      template_Final_Project_MPC56_M->Timing.clockTick0;

    /* Sum: '<S13>/Sum' */
    rtb_DataTypeConversion_m = template_Final_Project_MPC564_B.Sum1;

    /* Sum: '<S13>/Sum3' incorporates:
     *  Gain: '<S13>/Gain'
     *  Gain: '<S13>/Kd_PD'
     *  Gain: '<S13>/Kp_PD'
     *  Sum: '<S13>/Sum'
     *  Sum: '<S13>/Sum1'
     *  Sum: '<S13>/Sum2'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    rtb_DiscreteTimeIntegrator_f = ((template_Final_Project_MPC564_B.Sum1 -
      template_Final_Project_MP_DWork.UnitDelay_DSTATE_p) * 100.0F * 0.04F +
      0.4F * template_Final_Project_MPC564_B.Sum1) +
      template_Final_Project_MPC564_B.Gain1;

    /* Sum: '<S13>/Sum4' incorporates:
     *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
     *  Gain: '<S13>/Gain1'
     *  Gain: '<S13>/Kd_PID'
     *  Gain: '<S13>/Ki_PID'
     *  Gain: '<S13>/Kp_PID'
     *  Sum: '<S13>/Sum5'
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    template_Final_Project_MPC564_B.Sum4 = ((rtb_DiscreteTimeIntegrator_f -
      template_Final_Project_MP_DWork.UnitDelay1_DSTATE_o) * 100.0F * 40.0F +
      0.0F * template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE_f) +
      500.0F * rtb_DiscreteTimeIntegrator_f;

    /* DataTypeConversion: '<S18>/Data Type Conversion16' */
    C_h_idx_0 = (real32_T)floor(template_Final_Project_MPC564_B.Sum4);
    if (rtIsNaNF(C_h_idx_0) || rtIsInfF(C_h_idx_0)) {
      C_h_idx_0 = 0.0F;
    } else {
      C_h_idx_0 = (real32_T)fmod(C_h_idx_0, 65536.0F);
    }

    rtb_DataTypeConversion16 = (int16_T)(C_h_idx_0 < 0.0F ? (int16_T)-(int16_T)
      (uint16_T)-C_h_idx_0 : (int16_T)(uint16_T)C_h_idx_0);

    /* End of DataTypeConversion: '<S18>/Data Type Conversion16' */

    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator'
     */
    template_Final_Project_MPC564_B.DataTypeConversion_d = ((int16_T)
      (rtb_DataTypeConversion16 & 1) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output ' */

    /* Pin Data Output Signal Update PCR[43]. */
    gpo_pin_update_564xl_fnc(43,
      template_Final_Project_MPC564_B.DataTypeConversion_d);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion1' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator1'
     */
    template_Final_Project_MPC564_B.DataTypeConversion1 = ((int16_T)
      (rtb_DataTypeConversion16 & 2) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 1' */

    /* Pin Data Output Signal Update PCR[44]. */
    gpo_pin_update_564xl_fnc(44,
      template_Final_Project_MPC564_B.DataTypeConversion1);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion10' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator10'
     */
    template_Final_Project_MPC564_B.DataTypeConversion10 = ((int16_T)
      (rtb_DataTypeConversion16 & 1024) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 10' */

    /* Pin Data Output Signal Update PCR[53]. */
    gpo_pin_update_564xl_fnc(53,
      template_Final_Project_MPC564_B.DataTypeConversion10);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion11' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator11'
     */
    template_Final_Project_MPC564_B.DataTypeConversion11 = ((int16_T)
      (rtb_DataTypeConversion16 & 2048) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 11' */

    /* Pin Data Output Signal Update PCR[54]. */
    gpo_pin_update_564xl_fnc(54,
      template_Final_Project_MPC564_B.DataTypeConversion11);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion12' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator12'
     */
    template_Final_Project_MPC564_B.DataTypeConversion12 = ((int16_T)
      (rtb_DataTypeConversion16 & 4096) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 12' */

    /* Pin Data Output Signal Update PCR[55]. */
    gpo_pin_update_564xl_fnc(55,
      template_Final_Project_MPC564_B.DataTypeConversion12);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion13' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator13'
     */
    template_Final_Project_MPC564_B.DataTypeConversion13 = ((int16_T)
      (rtb_DataTypeConversion16 & 8192) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 13' */

    /* Pin Data Output Signal Update PCR[56]. */
    gpo_pin_update_564xl_fnc(56,
      template_Final_Project_MPC564_B.DataTypeConversion13);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion14' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator14'
     */
    template_Final_Project_MPC564_B.DataTypeConversion14 = ((int16_T)
      (rtb_DataTypeConversion16 & 16384) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 14' */

    /* Pin Data Output Signal Update PCR[57]. */
    gpo_pin_update_564xl_fnc(57,
      template_Final_Project_MPC564_B.DataTypeConversion14);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion15' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator15'
     */
    template_Final_Project_MPC564_B.DataTypeConversion15 = ((int16_T)
      (rtb_DataTypeConversion16 & MIN_int16_T) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 15' */

    /* Pin Data Output Signal Update PCR[58]. */
    gpo_pin_update_564xl_fnc(58,
      template_Final_Project_MPC564_B.DataTypeConversion15);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion2' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator2'
     */
    template_Final_Project_MPC564_B.DataTypeConversion2 = ((int16_T)
      (rtb_DataTypeConversion16 & 4) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 2' */

    /* Pin Data Output Signal Update PCR[45]. */
    gpo_pin_update_564xl_fnc(45,
      template_Final_Project_MPC564_B.DataTypeConversion2);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion3' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator3'
     */
    template_Final_Project_MPC564_B.DataTypeConversion3 = ((int16_T)
      (rtb_DataTypeConversion16 & 8) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 3' */

    /* Pin Data Output Signal Update PCR[46]. */
    gpo_pin_update_564xl_fnc(46,
      template_Final_Project_MPC564_B.DataTypeConversion3);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion4' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator4'
     */
    template_Final_Project_MPC564_B.DataTypeConversion4 = ((int16_T)
      (rtb_DataTypeConversion16 & 16) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 4' */

    /* Pin Data Output Signal Update PCR[47]. */
    gpo_pin_update_564xl_fnc(47,
      template_Final_Project_MPC564_B.DataTypeConversion4);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion5' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator5'
     */
    template_Final_Project_MPC564_B.DataTypeConversion5 = ((int16_T)
      (rtb_DataTypeConversion16 & 32) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 5' */

    /* Pin Data Output Signal Update PCR[48]. */
    gpo_pin_update_564xl_fnc(48,
      template_Final_Project_MPC564_B.DataTypeConversion5);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion6' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator6'
     */
    template_Final_Project_MPC564_B.DataTypeConversion6 = ((int16_T)
      (rtb_DataTypeConversion16 & 64) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 6' */

    /* Pin Data Output Signal Update PCR[49]. */
    gpo_pin_update_564xl_fnc(49,
      template_Final_Project_MPC564_B.DataTypeConversion6);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion7' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator7'
     */
    template_Final_Project_MPC564_B.DataTypeConversion7 = ((int16_T)
      (rtb_DataTypeConversion16 & 128) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 7' */

    /* Pin Data Output Signal Update PCR[50]. */
    gpo_pin_update_564xl_fnc(50,
      template_Final_Project_MPC564_B.DataTypeConversion7);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion8' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator8'
     */
    template_Final_Project_MPC564_B.DataTypeConversion8 = ((int16_T)
      (rtb_DataTypeConversion16 & 256) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 8' */

    /* Pin Data Output Signal Update PCR[51]. */
    gpo_pin_update_564xl_fnc(51,
      template_Final_Project_MPC564_B.DataTypeConversion8);/* GPO Pin Data Output Register Update */

    /* DataTypeConversion: '<S18>/Data Type Conversion9' incorporates:
     *  S-Function (sfix_bitop): '<S18>/Bitwise Operator9'
     */
    template_Final_Project_MPC564_B.DataTypeConversion9 = ((int16_T)
      (rtb_DataTypeConversion16 & 512) != 0);

    /* S-Function (gpio_564xl_output): '<S18>/Digital Output 9' */

    /* Pin Data Output Signal Update PCR[52]. */
    gpo_pin_update_564xl_fnc(52,
      template_Final_Project_MPC564_B.DataTypeConversion9);/* GPO Pin Data Output Register Update */

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    template_Final_Project_MP_DWork.UnitDelay_DSTATE_p =
      rtb_DataTypeConversion_m;

    /* Update for UnitDelay: '<S13>/Unit Delay1' */
    template_Final_Project_MP_DWork.UnitDelay1_DSTATE_o =
      rtb_DiscreteTimeIntegrator_f;

    /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE_f = (real32_T)
      (0.0099999997764825821 * (real_T)
       template_Final_Project_MP_DWork.autosteering_ELAPS_T)
      * rtb_DiscreteTimeIntegrator_f +
      template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE_f;
  }

  /* End of Outputs for SubSystem: '<S5>/auto steering' */

  /* Sum: '<S32>/Sum' incorporates:
   *  Constant: '<S32>/offset'
   *  Gain: '<S32>/torque gain'
   *  Sum: '<S7>/Sum'
   */
  rtb_DiscreteTimeIntegrator_f = ((0.0F - rtb_Product_h) -
    template_Final_Project_MPC564_B.Sum4) * 0.0003162F + 0.5F;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  Saturate: '<S7>/Saturation'
   */
  C_h_idx_0 = (real32_T)floor((rtb_DiscreteTimeIntegrator_f >= 0.76F ? 0.76F :
    rtb_DiscreteTimeIntegrator_f <= 0.24F ? 0.24F : rtb_DiscreteTimeIntegrator_f)
    * 100.0F);
  if (rtIsNaNF(C_h_idx_0) || rtIsInfF(C_h_idx_0)) {
    C_h_idx_0 = 0.0F;
  } else {
    C_h_idx_0 = (real32_T)fmod(C_h_idx_0, 4.2949673E+9F);
  }

  template_Final_Project_MPC564_B.DataTypeConversion = (uint32_T)C_h_idx_0;

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (Simple_PWM_564xL_output): '<S7>/Motor' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 0, 20000U, 1, 0U,
    template_Final_Project_MPC564_B.DataTypeConversion);

  /* S-Function (single2bytes): '<S33>/Single to Bytes' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.UnitDelay)[0];
  template_Final_Project_MPC564_B.SingletoBytes[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.UnitDelay)[1];
  template_Final_Project_MPC564_B.SingletoBytes[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.UnitDelay)[2];
  template_Final_Project_MPC564_B.SingletoBytes[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.UnitDelay)[3];

  /* S-Function (single2bytes): '<S33>/Single to Bytes1' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes1[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1)[0];
  template_Final_Project_MPC564_B.SingletoBytes1[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1)[1];
  template_Final_Project_MPC564_B.SingletoBytes1[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1)[2];
  template_Final_Project_MPC564_B.SingletoBytes1[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1)[3];

  /* SignalConversion: '<S33>/TmpSignal ConversionAtCAN TransmitInport1' */
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[0] =
    template_Final_Project_MPC564_B.SingletoBytes[0];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[1] =
    template_Final_Project_MPC564_B.SingletoBytes[1];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[2] =
    template_Final_Project_MPC564_B.SingletoBytes[2];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[3] =
    template_Final_Project_MPC564_B.SingletoBytes[3];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[4] =
    template_Final_Project_MPC564_B.SingletoBytes1[0];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[5] =
    template_Final_Project_MPC564_B.SingletoBytes1[1];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[6] =
    template_Final_Project_MPC564_B.SingletoBytes1[2];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi[7] =
    template_Final_Project_MPC564_B.SingletoBytes1[3];

  /* S-Function (can_564xl_transmit): '<S33>/CAN Transmit' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data =
      template_Final_Project_MPC564_B.TmpSignalConversionAtCANTransmi;
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (45&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 45;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,0,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 0);
  }

  /* S-Function (single2bytes): '<S33>/Single to Bytes2' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes2[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Product2)[0];
  template_Final_Project_MPC564_B.SingletoBytes2[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Product2)[1];
  template_Final_Project_MPC564_B.SingletoBytes2[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Product2)[2];
  template_Final_Project_MPC564_B.SingletoBytes2[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Product2)[3];

  /* S-Function (single2bytes): '<S33>/Single to Bytes3' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes3[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.DiscreteTimeIntegrator2)[0];
  template_Final_Project_MPC564_B.SingletoBytes3[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.DiscreteTimeIntegrator2)[1];
  template_Final_Project_MPC564_B.SingletoBytes3[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.DiscreteTimeIntegrator2)[2];
  template_Final_Project_MPC564_B.SingletoBytes3[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.DiscreteTimeIntegrator2)[3];

  /* SignalConversion: '<S33>/TmpSignal ConversionAtCAN Transmit1Inport1' */
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[0] =
    template_Final_Project_MPC564_B.SingletoBytes2[0];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[1] =
    template_Final_Project_MPC564_B.SingletoBytes2[1];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[2] =
    template_Final_Project_MPC564_B.SingletoBytes2[2];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[3] =
    template_Final_Project_MPC564_B.SingletoBytes2[3];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[4] =
    template_Final_Project_MPC564_B.SingletoBytes3[0];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[5] =
    template_Final_Project_MPC564_B.SingletoBytes3[1];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[6] =
    template_Final_Project_MPC564_B.SingletoBytes3[2];
  template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g[7] =
    template_Final_Project_MPC564_B.SingletoBytes3[3];

  /* S-Function (can_564xl_transmit): '<S33>/CAN Transmit1' */
  {
    FLEXCAN_MsgBufferStructure *ptr_FLEXCAN_MsgBufferStructure;
    FLEXCAN_MsgBufferStructure str_FLEXCAN_MsgBufferStructure;
    uint8_t i = 0U;
    uint8_t* data =
      template_Final_Project_MPC564_B.TmpSignalConversionAtCANTrans_g;
    uint8_t datalen = ((uint8_T)8U);
    ptr_FLEXCAN_MsgBufferStructure = &(str_FLEXCAN_MsgBufferStructure);
    memset(ptr_FLEXCAN_MsgBufferStructure,0,sizeof
           (*ptr_FLEXCAN_MsgBufferStructure));
    ptr_FLEXCAN_MsgBufferStructure->length = datalen;
    if (46&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 46;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,1,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 1);
  }

  /* S-Function (get_path1): '<S34>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_c = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_b = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_c = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_b = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S34>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_b = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_h = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_b = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_h = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S34>/Sum' incorporates:
   *  Product: '<S34>/Product'
   */
  rtb_DiscreteTimeIntegrator_f = template_Final_Project_MPC564_B.Sum1 *
    template_Final_Project_MPC564_B.LookupRightVector_o1_b +
    template_Final_Project_MPC564_B.LookupP_o1_c;
  rtb_Product_h = template_Final_Project_MPC564_B.Sum1 *
    template_Final_Project_MPC564_B.LookupRightVector_o2_h +
    template_Final_Project_MPC564_B.LookupP_o2_b;

  /* S-Function (get_path1): '<S41>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[0]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_k = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_c = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_k = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_c = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S41>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[0]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_l = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_c = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_l = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_c = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S41>/Sum' incorporates:
   *  Product: '<S41>/Product'
   */
  C_h_idx_0 = template_Final_Project_MPC564_B.Switch[1] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_l +
    template_Final_Project_MPC564_B.LookupP_o1_k;
  C_h_idx = template_Final_Project_MPC564_B.Switch[1] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_c +
    template_Final_Project_MPC564_B.LookupP_o2_c;

  /* S-Function (get_path1): '<S42>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[4]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_e = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_g = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_e = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_g = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S42>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[4]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_o = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_hm = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_o = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_hm = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S42>/Sum' incorporates:
   *  Product: '<S42>/Product'
   */
  C_f_idx_0 = template_Final_Project_MPC564_B.Switch[5] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_o +
    template_Final_Project_MPC564_B.LookupP_o1_e;
  C_f_idx = template_Final_Project_MPC564_B.Switch[5] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_hm +
    template_Final_Project_MPC564_B.LookupP_o2_g;

  /* S-Function (get_path1): '<S43>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[8]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_g = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_j = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_g = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_j = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S43>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[8]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_a = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_i = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_a = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_i = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S43>/Sum' incorporates:
   *  Product: '<S43>/Product'
   */
  C_o_idx_0 = template_Final_Project_MPC564_B.Switch[9] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_a +
    template_Final_Project_MPC564_B.LookupP_o1_g;
  C_o_idx = template_Final_Project_MPC564_B.Switch[9] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_i +
    template_Final_Project_MPC564_B.LookupP_o2_j;

  /* S-Function (get_path1): '<S44>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[12]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_i = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_a = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_i = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_a = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S44>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[12]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_am = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_l = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_am = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_l = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S44>/Sum' incorporates:
   *  Product: '<S44>/Product'
   */
  C_d_idx_0 = template_Final_Project_MPC564_B.Switch[13] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_am +
    template_Final_Project_MPC564_B.LookupP_o1_i;
  C_d_idx = template_Final_Project_MPC564_B.Switch[13] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_l +
    template_Final_Project_MPC564_B.LookupP_o2_a;

  /* S-Function (get_path1): '<S45>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[16]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_o = rs[i].data.straight.start[0]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_k = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_o = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_k = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S45>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[16]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_j = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_o = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_j = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_o = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S45>/Sum' incorporates:
   *  Product: '<S45>/Product'
   */
  C_b_idx_0 = template_Final_Project_MPC564_B.Switch[17] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_j +
    template_Final_Project_MPC564_B.LookupP_o1_o;
  C_b_idx = template_Final_Project_MPC564_B.Switch[17] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_o +
    template_Final_Project_MPC564_B.LookupP_o2_k;

  /* S-Function (get_path1): '<S46>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[20]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      template_Final_Project_MPC564_B.LookupP_o1_k0 = rs[i].data.straight.start
        [0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      template_Final_Project_MPC564_B.LookupP_o2_h = rs[i].data.straight.start[1]
        +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      template_Final_Project_MPC564_B.LookupP_o1_k0 = rs[i].
        data.const_curve.center[0] + rs[i].data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      template_Final_Project_MPC564_B.LookupP_o2_h = rs[i].
        data.const_curve.center[1] + rs[i].data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S46>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.Switch[20]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_jm = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_b = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_jm = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_b = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S46>/Sum' incorporates:
   *  Product: '<S46>/Product'
   */
  C_e_idx_0 = template_Final_Project_MPC564_B.Switch[21] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_jm +
    template_Final_Project_MPC564_B.LookupP_o1_k0;
  C_e_idx = template_Final_Project_MPC564_B.Switch[21] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_b +
    template_Final_Project_MPC564_B.LookupP_o2_h;

  /* S-Function (vmod): '<S47>/S-Function Builder' */
  vmod_Outputs_wrapper(&template_Final_Project_MPC564_B.DiscreteTimeIntegrator3,
                       &template_Final_Project_MPC564_B.Gain1,
                       &template_Final_Project_MPC564_B.DiscreteTimeIntegrator2,
                       &template_Final_Project_M_ConstP.Constant_Value,
                       &template_Final_Project_M_ConstP.Constant1_Value,
                       &template_Final_Project_MPC564_B.SFunctionBuilder_o1_j,
                       &template_Final_Project_MPC564_B.SFunctionBuilder_o2_f,
                       &template_Final_Project_MPC564_B.SFunctionBuilder_o3 );

  /* Gain: '<S47>/divide by mass' incorporates:
   *  Gain: '<S47>/subtract drag'
   *  Sum: '<S47>/Sum'
   */
  rtb_DataTypeConversion_m = (template_Final_Project_MPC564_B.Merge - 100.0F *
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator3) * 0.0005F;

  /* S-Function (get_rvec1): '<S52>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (template_Final_Project_MPC564_B.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        template_Final_Project_MPC564_B.LookupRightVector_o1_c = fy;
        template_Final_Project_MPC564_B.LookupRightVector_o2_hx = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        template_Final_Project_MPC564_B.LookupRightVector_o1_c = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_hx = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S54>/Product' incorporates:
   *  Gain: '<S52>/Gain'
   */
  rtb_Product_c_idx_0 *=
    -template_Final_Project_MPC564_B.LookupRightVector_o2_hx;

  /* DataTypeConversion: '<S49>/Data  Type  Conversion' incorporates:
   *  Product: '<S54>/Product'
   *  Sum: '<S54>/Sum1'
   */
  rtb_DataTypeConversion = rtb_Product_c_idx *
    template_Final_Project_MPC564_B.LookupRightVector_o1_c + rtb_Product_c_idx_0;

  /* DiscreteStateSpace: '<S49>/Controller' */
  {
    rtb_dsdt = 0.38289220218870362*
      template_Final_Project_MP_DWork.Controller_DSTATE;
    rtb_dsdt += 150.12501387153085*rtb_DataTypeConversion;
  }

  /* Update for UnitDelay: '<S20>/Unit Delay' */
  template_Final_Project_MP_DWork.UnitDelay_DSTATE_e =
    template_Final_Project_MPC564_B.eTimerCNTRRegisterRead;

  /* Update for UnitDelay: '<S20>/Unit Delay1' */
  template_Final_Project_MP_DWork.UnitDelay1_DSTATE = rtb_Sum1;

  /* Update for UnitDelay: '<S53>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S51>/Conversion'
   *  Gain: '<S53>/Gain'
   *  Sum: '<S53>/Sum'
   */
  template_Final_Project_MP_DWork.UnitDelay_DSTATE = 0.01F * (real32_T)rtb_dsdt
    + template_Final_Project_MPC564_B.UnitDelay;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator2' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator2_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * template_Final_Project_MPC564_B.SFunctionBuilder_o3 +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator3' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator3_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * rtb_DataTypeConversion_m +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * template_Final_Project_MPC564_B.SFunctionBuilder_o1_j +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator1' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator1_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * template_Final_Project_MPC564_B.SFunctionBuilder_o2_f +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteStateSpace: '<S49>/Controller' */
  {
    real_T xnew[1];
    xnew[0] = 1.0*template_Final_Project_MP_DWork.Controller_DSTATE;
    xnew[0] += 0.65292519369349644*rtb_DataTypeConversion;
    (void) memcpy(&template_Final_Project_MP_DWork.Controller_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (template_Final_Project_MPC56_M->Timing.RateInteraction.TID0_1) {
    template_Final_Project_MPC564_B.RateTransition[0] =
      rtb_DiscreteTimeIntegrator_f;
    template_Final_Project_MPC564_B.RateTransition[1] = rtb_Product_h;
    template_Final_Project_MPC564_B.RateTransition[2] =
      template_Final_Project_MPC564_B.DiscreteTimeIntegrator2;
    template_Final_Project_MPC564_B.RateTransition[3] =
      template_Final_Project_MPC564_B.DiscreteTimeIntegrator3;
    template_Final_Project_MPC564_B.RateTransition[4] = C_h_idx_0;
    template_Final_Project_MPC564_B.RateTransition[5] = C_h_idx;
    template_Final_Project_MPC564_B.RateTransition[6] =
      template_Final_Project_MPC564_B.Switch[2];
    template_Final_Project_MPC564_B.RateTransition[7] = C_f_idx_0;
    template_Final_Project_MPC564_B.RateTransition[8] = C_f_idx;
    template_Final_Project_MPC564_B.RateTransition[9] =
      template_Final_Project_MPC564_B.Switch[6];
    template_Final_Project_MPC564_B.RateTransition[10] = C_o_idx_0;
    template_Final_Project_MPC564_B.RateTransition[11] = C_o_idx;
    template_Final_Project_MPC564_B.RateTransition[12] =
      template_Final_Project_MPC564_B.Switch[10];
    template_Final_Project_MPC564_B.RateTransition[13] = C_d_idx_0;
    template_Final_Project_MPC564_B.RateTransition[14] = C_d_idx;
    template_Final_Project_MPC564_B.RateTransition[15] =
      template_Final_Project_MPC564_B.Switch[14];
    template_Final_Project_MPC564_B.RateTransition[16] = C_b_idx_0;
    template_Final_Project_MPC564_B.RateTransition[17] = C_b_idx;
    template_Final_Project_MPC564_B.RateTransition[18] =
      template_Final_Project_MPC564_B.Switch[18];
    template_Final_Project_MPC564_B.RateTransition[19] = C_e_idx_0;
    template_Final_Project_MPC564_B.RateTransition[20] = C_e_idx;
    template_Final_Project_MPC564_B.RateTransition[21] =
      template_Final_Project_MPC564_B.Switch[22];
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (Simple_PWM_564xL_output): '<S3>/Simple PWM Output' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 1, 1000000U, 1, 0U, 50U);

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  template_Final_Project_MPC56_M->Timing.clockTick0++;
}

/* Model step function for TID1 */
void template_Final_Project_MPC5643L_step1(void) /* Sample time: [0.05s, 0.0s] */
{
  int8_T s56_iter;

  /* S-Function (fcncallgen): '<Root>/Function-Call Serial' incorporates:
   *  SubSystem: '<Root>/Serial'
   */

  /* S-Function (single2bytes): '<S4>/Single to Bytes' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes_a[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[0])[0];
  template_Final_Project_MPC564_B.SingletoBytes_a[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[0])[1];
  template_Final_Project_MPC564_B.SingletoBytes_a[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[0])[2];
  template_Final_Project_MPC564_B.SingletoBytes_a[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[0])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes1' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes1_g[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[1])[0];
  template_Final_Project_MPC564_B.SingletoBytes1_g[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[1])[1];
  template_Final_Project_MPC564_B.SingletoBytes1_g[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[1])[2];
  template_Final_Project_MPC564_B.SingletoBytes1_g[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[1])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes2' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes2_h[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[2])[0];
  template_Final_Project_MPC564_B.SingletoBytes2_h[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[2])[1];
  template_Final_Project_MPC564_B.SingletoBytes2_h[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[2])[2];
  template_Final_Project_MPC564_B.SingletoBytes2_h[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[2])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes3' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes3_g[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[3])[0];
  template_Final_Project_MPC564_B.SingletoBytes3_g[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[3])[1];
  template_Final_Project_MPC564_B.SingletoBytes3_g[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[3])[2];
  template_Final_Project_MPC564_B.SingletoBytes3_g[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[3])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes4' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes4[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[4])[0];
  template_Final_Project_MPC564_B.SingletoBytes4[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[4])[1];
  template_Final_Project_MPC564_B.SingletoBytes4[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[4])[2];
  template_Final_Project_MPC564_B.SingletoBytes4[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[4])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes5' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes5[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[5])[0];
  template_Final_Project_MPC564_B.SingletoBytes5[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[5])[1];
  template_Final_Project_MPC564_B.SingletoBytes5[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[5])[2];
  template_Final_Project_MPC564_B.SingletoBytes5[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[5])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes6' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes6[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[6])[0];
  template_Final_Project_MPC564_B.SingletoBytes6[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[6])[1];
  template_Final_Project_MPC564_B.SingletoBytes6[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[6])[2];
  template_Final_Project_MPC564_B.SingletoBytes6[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[6])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes7' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes7[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[7])[0];
  template_Final_Project_MPC564_B.SingletoBytes7[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[7])[1];
  template_Final_Project_MPC564_B.SingletoBytes7[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[7])[2];
  template_Final_Project_MPC564_B.SingletoBytes7[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[7])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes8' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes8[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[8])[0];
  template_Final_Project_MPC564_B.SingletoBytes8[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[8])[1];
  template_Final_Project_MPC564_B.SingletoBytes8[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[8])[2];
  template_Final_Project_MPC564_B.SingletoBytes8[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[8])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes9' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes9[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[9])[0];
  template_Final_Project_MPC564_B.SingletoBytes9[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[9])[1];
  template_Final_Project_MPC564_B.SingletoBytes9[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[9])[2];
  template_Final_Project_MPC564_B.SingletoBytes9[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[9])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes10' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes10[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[10])[0];
  template_Final_Project_MPC564_B.SingletoBytes10[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[10])[1];
  template_Final_Project_MPC564_B.SingletoBytes10[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[10])[2];
  template_Final_Project_MPC564_B.SingletoBytes10[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[10])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes11' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes11[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[11])[0];
  template_Final_Project_MPC564_B.SingletoBytes11[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[11])[1];
  template_Final_Project_MPC564_B.SingletoBytes11[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[11])[2];
  template_Final_Project_MPC564_B.SingletoBytes11[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[11])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes12' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes12[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[12])[0];
  template_Final_Project_MPC564_B.SingletoBytes12[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[12])[1];
  template_Final_Project_MPC564_B.SingletoBytes12[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[12])[2];
  template_Final_Project_MPC564_B.SingletoBytes12[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[12])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes13' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes13[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[13])[0];
  template_Final_Project_MPC564_B.SingletoBytes13[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[13])[1];
  template_Final_Project_MPC564_B.SingletoBytes13[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[13])[2];
  template_Final_Project_MPC564_B.SingletoBytes13[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[13])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes14' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes14[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[14])[0];
  template_Final_Project_MPC564_B.SingletoBytes14[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[14])[1];
  template_Final_Project_MPC564_B.SingletoBytes14[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[14])[2];
  template_Final_Project_MPC564_B.SingletoBytes14[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[14])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes15' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes15[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[15])[0];
  template_Final_Project_MPC564_B.SingletoBytes15[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[15])[1];
  template_Final_Project_MPC564_B.SingletoBytes15[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[15])[2];
  template_Final_Project_MPC564_B.SingletoBytes15[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[15])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes16' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes16[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[16])[0];
  template_Final_Project_MPC564_B.SingletoBytes16[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[16])[1];
  template_Final_Project_MPC564_B.SingletoBytes16[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[16])[2];
  template_Final_Project_MPC564_B.SingletoBytes16[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[16])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes17' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes17[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[17])[0];
  template_Final_Project_MPC564_B.SingletoBytes17[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[17])[1];
  template_Final_Project_MPC564_B.SingletoBytes17[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[17])[2];
  template_Final_Project_MPC564_B.SingletoBytes17[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[17])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes18' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes18[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[18])[0];
  template_Final_Project_MPC564_B.SingletoBytes18[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[18])[1];
  template_Final_Project_MPC564_B.SingletoBytes18[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[18])[2];
  template_Final_Project_MPC564_B.SingletoBytes18[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[18])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes19' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes19[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[19])[0];
  template_Final_Project_MPC564_B.SingletoBytes19[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[19])[1];
  template_Final_Project_MPC564_B.SingletoBytes19[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[19])[2];
  template_Final_Project_MPC564_B.SingletoBytes19[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[19])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes20' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes20[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[20])[0];
  template_Final_Project_MPC564_B.SingletoBytes20[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[20])[1];
  template_Final_Project_MPC564_B.SingletoBytes20[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[20])[2];
  template_Final_Project_MPC564_B.SingletoBytes20[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[20])[3];

  /* S-Function (single2bytes): '<S4>/Single to Bytes21' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes21[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[21])[0];
  template_Final_Project_MPC564_B.SingletoBytes21[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[21])[1];
  template_Final_Project_MPC564_B.SingletoBytes21[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[21])[2];
  template_Final_Project_MPC564_B.SingletoBytes21[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.RateTransition[21])[3];

  /* Outputs for Iterator SubSystem: '<S4>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S56>/For Iterator'
   */
  for (s56_iter = 0; s56_iter < 91; s56_iter++) {
    /* MultiPortSwitch: '<S56>/Index Vector' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    switch (s56_iter) {
     case 0:
      template_Final_Project_MPC564_B.IndexVector = 115U;
      break;

     case 1:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes_a[0];
      break;

     case 2:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes_a[1];
      break;

     case 3:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes_a[2];
      break;

     case 4:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes_a[3];
      break;

     case 5:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes1_g[0];
      break;

     case 6:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes1_g[1];
      break;

     case 7:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes1_g[2];
      break;

     case 8:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes1_g[3];
      break;

     case 9:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes2_h[0];
      break;

     case 10:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes2_h[1];
      break;

     case 11:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes2_h[2];
      break;

     case 12:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes2_h[3];
      break;

     case 13:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes3_g[0];
      break;

     case 14:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes3_g[1];
      break;

     case 15:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes3_g[2];
      break;

     case 16:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes3_g[3];
      break;

     case 17:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes4[0];
      break;

     case 18:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes4[1];
      break;

     case 19:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes4[2];
      break;

     case 20:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes4[3];
      break;

     case 21:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes5[0];
      break;

     case 22:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes5[1];
      break;

     case 23:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes5[2];
      break;

     case 24:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes5[3];
      break;

     case 25:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes6[0];
      break;

     case 26:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes6[1];
      break;

     case 27:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes6[2];
      break;

     case 28:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes6[3];
      break;

     case 29:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes7[0];
      break;

     case 30:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes7[1];
      break;

     case 31:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes7[2];
      break;

     case 32:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes7[3];
      break;

     case 33:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes8[0];
      break;

     case 34:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes8[1];
      break;

     case 35:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes8[2];
      break;

     case 36:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes8[3];
      break;

     case 37:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes9[0];
      break;

     case 38:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes9[1];
      break;

     case 39:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes9[2];
      break;

     case 40:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes9[3];
      break;

     case 41:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes10[0];
      break;

     case 42:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes10[1];
      break;

     case 43:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes10[2];
      break;

     case 44:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes10[3];
      break;

     case 45:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes11[0];
      break;

     case 46:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes11[1];
      break;

     case 47:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes11[2];
      break;

     case 48:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes11[3];
      break;

     case 49:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes12[0];
      break;

     case 50:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes12[1];
      break;

     case 51:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes12[2];
      break;

     case 52:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes12[3];
      break;

     case 53:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes13[0];
      break;

     case 54:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes13[1];
      break;

     case 55:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes13[2];
      break;

     case 56:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes13[3];
      break;

     case 57:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes14[0];
      break;

     case 58:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes14[1];
      break;

     case 59:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes14[2];
      break;

     case 60:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes14[3];
      break;

     case 61:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes15[0];
      break;

     case 62:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes15[1];
      break;

     case 63:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes15[2];
      break;

     case 64:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes15[3];
      break;

     case 65:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes16[0];
      break;

     case 66:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes16[1];
      break;

     case 67:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes16[2];
      break;

     case 68:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes16[3];
      break;

     case 69:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes17[0];
      break;

     case 70:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes17[1];
      break;

     case 71:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes17[2];
      break;

     case 72:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes17[3];
      break;

     case 73:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes18[0];
      break;

     case 74:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes18[1];
      break;

     case 75:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes18[2];
      break;

     case 76:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes18[3];
      break;

     case 77:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes19[0];
      break;

     case 78:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes19[1];
      break;

     case 79:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes19[2];
      break;

     case 80:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes19[3];
      break;

     case 81:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes20[0];
      break;

     case 82:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes20[1];
      break;

     case 83:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes20[2];
      break;

     case 84:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes20[3];
      break;

     case 85:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes21[0];
      break;

     case 86:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes21[1];
      break;

     case 87:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes21[2];
      break;

     case 88:
      template_Final_Project_MPC564_B.IndexVector =
        template_Final_Project_MPC564_B.SingletoBytes21[3];
      break;

     case 89:
      template_Final_Project_MPC564_B.IndexVector = 101U;
      break;
    }

    /* End of MultiPortSwitch: '<S56>/Index Vector' */

    /* S-Function (SerialSend): '<S56>/S-Function' */
    {
      LINFLEX_0.BDRL.B.DATA0 = template_Final_Project_MPC564_B.IndexVector;
      while (!LINFLEX_0.UARTSR.B.DTF_TFF) ;//wait untill completing transmission
      LINFLEX_0.UARTSR.R = 0x2;        //Clear DTF after completing transmission
    }
  }

  /* End of Outputs for SubSystem: '<S4>/For Iterator Subsystem' */
}

void template_Final_Project_MPC5643L_step(int_T tid)
{
  switch (tid) {
   case 0 :
    template_Final_Project_MPC5643L_step0();
    break;

   case 1 :
    template_Final_Project_MPC5643L_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void template_Final_Project_MPC5643L_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)template_Final_Project_MPC56_M, 0,
                sizeof(RT_MODEL_template_Final_Project));

  /* block I/O */
  (void) memset(((void *) &template_Final_Project_MPC564_B), 0,
                sizeof(BlockIO_template_Final_Project_));

  /* states (dwork) */
  (void) memset((void *)&template_Final_Project_MP_DWork, 0,
                sizeof(D_Work_template_Final_Project_M));

  /* Start for S-Function (can_564xl_config): '<Root>/CAN Config' */
  flexcan_564xl_init( 0, 1342177343, 82640898);
  flexcan_564xl_pin_init( 0);

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  Start for SubSystem: '<Root>/High-Level Design'
   */
  /* Start for S-Function (can_564xl_receive_data): '<S22>/CAN_Receive_data' */
  {
    if ((15U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 2, 15U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 2, 15U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S22>/CAN_Receive_data1' */
  {
    if ((16U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 3, 16U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 3, 16U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S23>/CAN_Receive_data' */
  {
    if ((25U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 4, 25U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 4, 25U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S23>/CAN_Receive_data1' */
  {
    if ((26U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 5, 26U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 5, 26U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S24>/CAN_Receive_data' */
  {
    if ((35U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 6, 35U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 6, 35U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S24>/CAN_Receive_data1' */
  {
    if ((36U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 7, 36U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 7, 36U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S25>/CAN_Receive_data' */
  {
    if ((75U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 8, 75U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 8, 75U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S25>/CAN_Receive_data1' */
  {
    if ((76U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 9, 76U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 9, 76U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S26>/CAN_Receive_data' */
  {
    if ((65U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 10, 65U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 10, 65U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S26>/CAN_Receive_data1' */
  {
    if ((66U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 11, 66U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 11, 66U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S27>/CAN_Receive_data' */
  {
    if ((55U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 12, 55U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 12, 55U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S27>/CAN_Receive_data1' */
  {
    if ((56U & 0x1FFFF800) != 0x0) {   //extended tag
      flexcan_564xl_set_filter_id(0, 13, 56U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 13, 56U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S28>/CAN_Receive_data' */
  {
    if ((0U & 0x1FFFF800) != 0x0) {    //extended tag
      flexcan_564xl_set_filter_id(0, 0, 0U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 0, 0U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S28>/CAN_Receive_data1' */
  {
    if ((0U & 0x1FFFF800) != 0x0) {    //extended tag
      flexcan_564xl_set_filter_id(0, 1, 0U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 1, 0U, 0);
    }
  }

  /* Start for S-Function (gpio_564xl_input): '<S6>/Digital Input' */

  /* Initialize Pad Configuration Register 13 as Input */
  gpi_init_pcr_in_564xl_fnc( 13 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input' */

  /* Initialize Pad Configuration Register 5 as Input */
  gpi_init_pcr_in_564xl_fnc( 5 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input1' */

  /* Initialize Pad Configuration Register 6 as Input */
  gpi_init_pcr_in_564xl_fnc( 6 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input2' */

  /* Initialize Pad Configuration Register 7 as Input */
  gpi_init_pcr_in_564xl_fnc( 7 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input3' */

  /* Initialize Pad Configuration Register 8 as Input */
  gpi_init_pcr_in_564xl_fnc( 8 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input4' */

  /* Initialize Pad Configuration Register 9 as Input */
  gpi_init_pcr_in_564xl_fnc( 9 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input6' */

  /* Initialize Pad Configuration Register 11 as Input */
  gpi_init_pcr_in_564xl_fnc( 11 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input7' */

  /* Initialize Pad Configuration Register 12 as Input */
  gpi_init_pcr_in_564xl_fnc( 12 );

  /* Start for S-Function (gpio_564xl_input): '<S21>/Digital Input5' */

  /* Initialize Pad Configuration Register 10 as Input */
  gpi_init_pcr_in_564xl_fnc( 10 );

  /* Start for S-Function (adc_564xl_input): '<S6>/ADC Channel' */
  adc_pin_init( 0, 0);
  adc_channelmode_setup( 0, 0, 1);
  adc_presample( 0, 0, 0);

  /* Start for S-Function (gpio_564xl_input): '<S6>/Digital Input1' */

  /* Initialize Pad Configuration Register 14 as Input */
  gpi_init_pcr_in_564xl_fnc( 14 );

  /* Start for Enabled SubSystem: '<S5>/auto steering' */

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output ' */

  /* Initialize Pad Configuration Register 43 as Output */
  gpo_init_pcr_out_564xl_fnc( 43 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 1' */

  /* Initialize Pad Configuration Register 44 as Output */
  gpo_init_pcr_out_564xl_fnc( 44 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 10' */

  /* Initialize Pad Configuration Register 53 as Output */
  gpo_init_pcr_out_564xl_fnc( 53 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 11' */

  /* Initialize Pad Configuration Register 54 as Output */
  gpo_init_pcr_out_564xl_fnc( 54 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 12' */

  /* Initialize Pad Configuration Register 55 as Output */
  gpo_init_pcr_out_564xl_fnc( 55 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 13' */

  /* Initialize Pad Configuration Register 56 as Output */
  gpo_init_pcr_out_564xl_fnc( 56 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 14' */

  /* Initialize Pad Configuration Register 57 as Output */
  gpo_init_pcr_out_564xl_fnc( 57 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 15' */

  /* Initialize Pad Configuration Register 58 as Output */
  gpo_init_pcr_out_564xl_fnc( 58 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 2' */

  /* Initialize Pad Configuration Register 45 as Output */
  gpo_init_pcr_out_564xl_fnc( 45 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 3' */

  /* Initialize Pad Configuration Register 46 as Output */
  gpo_init_pcr_out_564xl_fnc( 46 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 4' */

  /* Initialize Pad Configuration Register 47 as Output */
  gpo_init_pcr_out_564xl_fnc( 47 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 5' */

  /* Initialize Pad Configuration Register 48 as Output */
  gpo_init_pcr_out_564xl_fnc( 48 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 6' */

  /* Initialize Pad Configuration Register 49 as Output */
  gpo_init_pcr_out_564xl_fnc( 49 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 7' */

  /* Initialize Pad Configuration Register 50 as Output */
  gpo_init_pcr_out_564xl_fnc( 50 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 8' */

  /* Initialize Pad Configuration Register 51 as Output */
  gpo_init_pcr_out_564xl_fnc( 51 );

  /* Start for S-Function (gpio_564xl_output): '<S18>/Digital Output 9' */

  /* Initialize Pad Configuration Register 52 as Output */
  gpo_init_pcr_out_564xl_fnc( 52 );

  /* End of Start for SubSystem: '<S5>/auto steering' */

  /* Start for S-Function (Simple_PWM_564xL_output): '<S7>/Motor' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,0,0,255);
  pwm_init_pcr_out_564xL(0,0,1,59);
  pwm_init_pcr_out_564xL(0,0,2,255);

  /* Initialize PWM Submodule 0 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,0, 20000, 1, 0, 0, 0, 0, 0, 60, 0, 0, 0);

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Serial' incorporates:
   *  Start for SubSystem: '<Root>/Serial'
   */

  /* Start for S-Function (Simple_PWM_564xL_output): '<S3>/Simple PWM Output' */

  /* Initialize Pad Configuration Registers PAn & PBn as Output */
  pwm_init_pcr_out_564xL(0,1,0,255);
  pwm_init_pcr_out_564xL(0,1,1,38);
  pwm_init_pcr_out_564xL(0,1,2,255);

  /* Initialize PWM Submodule 1 to correct dutycycle and frequency */
  pwm_init_564xL_simple(0,1, 1000000, 1, 0, 50, 0, 0, 0, 48, 0, 0, 0);

  /* Start for S-Function (SerialInit): '<Root>/Serial Initialization' */
  {
    unsigned long SYSTEM_FREQUENCY = 120000000;
    int baudrate = 115200;

    /* Configure LINFlex 0 pins */
    SIU.PCR[19].B.PA = 1;              // Pin asigned to LINFlex0 Rx
    SIU.PCR[19].B.IBE = 1;             // Input buffer enable
    SIU.PCR[18].B.PA = 1;              // Pin asigned to LINFlex0 Tx
    SIU.PCR[18].B.OBE = 1;             // Output buffer enable

    /* configure linflex0 */
    LINFLEX_0.LINCR1.B.SLEEP = 0x0;    // disable sleep mode
    LINFLEX_0.LINCR1.B.INIT = 0x1;     // init mode
    LINFLEX_0.UARTCR.B.UART = 0x1;     // UART mode
    LINFLEX_0.UARTCR.B.TDFL_TFC = 0x0; // buffer size = 1 byte
    LINFLEX_0.UARTCR.B.RDFL_RFC0 = 0x0;// buffer size = 1 byte
    LINFLEX_0.UARTCR.B.RFBM = 0;       // UART buffer mode
    LINFLEX_0.UARTCR.B.TFBM = 0;       // UART buffer mode
    LINFLEX_0.UARTCR.B.RXEN = 0x1;     // receiver enable
    LINFLEX_0.UARTCR.B.TXEN = 0x1;     // transmitter enable
    LINFLEX_0.UARTCR.B.PCE = 0x0;      // parity control disable
    LINFLEX_0.UARTCR.B.WL0 = 0x1;      // word length 8-bit data
    LINFLEX_0.LINIBRR.B.IBR = (int)(SYSTEM_FREQUENCY/16/baudrate);

    // Baud rate calculation
    LINFLEX_0.LINFBRR.B.FBR = (SYSTEM_FREQUENCY/16/baudrate-
                               (int)(SYSTEM_FREQUENCY/16/baudrate))*16;
    LINFLEX_0.LINCR1.B.INIT = 0x0;     // normal mode
  }

  /* Start for S-Function (eTimer_564xL_config): '<Root>/eTimer configuration' */
  etimer_init_pcr_in_out_564xL(0,0,0);
  etimer_init_pcr_in_out_564xL(0,1,1);
  etimer_init_pcr_in_out_564xL(0,2,255);
  etimer_init_pcr_in_out_564xL(0,3,255);
  etimer_init_pcr_in_out_564xL(0,4,255);
  etimer_init_pcr_in_out_564xL(0,5,255);
  etimer_init_564xL (0,0,4,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                     0);

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/High-Level Design'
   */
  template_Final_Project_MP_DWork.HighLevelDesign_PREV_T =
    template_Final_Project_MPC56_M->Timing.clockTick0;

  /* InitializeConditions for Chart: '<S9>/Chart' */
  template_Final_Project_MP_DWork.is_active_c1_template_Final_Pro = 0U;
  template_Final_Project_MP_DWork.is_c1_template_Final_Project_MP = 0U;
  template_Final_Project_MPC564_B.speed_en = FALSE;
  template_Final_Project_MPC564_B.pos_en = FALSE;
  template_Final_Project_MPC564_B.man_en = FALSE;
  template_Final_Project_MPC564_B.state = 0.0F;
}

/* Model terminate function */
void template_Final_Project_MPC5643L_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
