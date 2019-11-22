/*
 * File: template_Final_Project_MPC5643L.c
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

#include "template_Final_Project_MPC5643L.h"
#include "template_Final_Project_MPC5643L_private.h"

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
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_Conversion;
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
  real32_T rtb_Product_a_idx;
  real32_T rtb_Product_a_idx_0;
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

  /* S-Function (can_564xl_receive_data): '<S11>/CAN_Receive_data' */
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

  /* S-Function (bytes2single): '<S11>/Bytes to Single' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle) );

  /* S-Function (bytes2single): '<S11>/Bytes to Single1' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle1), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data_o3[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle1) );

  /* S-Function (can_564xl_receive_data): '<S11>/CAN_Receive_data1' */
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

  /* S-Function (bytes2single): '<S11>/Bytes to Single2' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle2), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3[0])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle2) );

  /* S-Function (bytes2single): '<S11>/Bytes to Single3' */

  /* Interpret the array of inputs as 4 bytes that make up a single-precision
   * floating-point output. */
  memcpy( &(template_Final_Project_MPC564_B.BytestoSingle3), (void*)
         (&(template_Final_Project_MPC564_B.CAN_Receive_data1_o3[4])), sizeof
         (template_Final_Project_MPC564_B.BytestoSingle3) );

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S9>/0 for GSI vehicle only, 1 for ALL student vehicles1'
   */
  template_Final_Project_MPC564_B.Switch[0] =
    template_Final_Project_MPC564_B.BytestoSingle;
  template_Final_Project_MPC564_B.Switch[1] =
    template_Final_Project_MPC564_B.BytestoSingle1;
  template_Final_Project_MPC564_B.Switch[2] =
    template_Final_Project_MPC564_B.BytestoSingle3;
  template_Final_Project_MPC564_B.Switch[3] =
    template_Final_Project_MPC564_B.BytestoSingle2;
  template_Final_Project_MPC564_B.Switch[4] = 0.0F;
  template_Final_Project_MPC564_B.Switch[5] = 0.0F;
  template_Final_Project_MPC564_B.Switch[6] = 0.0F;
  template_Final_Project_MPC564_B.Switch[7] = 0.0F;
  template_Final_Project_MPC564_B.Switch[8] = 0.0F;
  template_Final_Project_MPC564_B.Switch[9] = 0.0F;
  template_Final_Project_MPC564_B.Switch[10] = 0.0F;
  template_Final_Project_MPC564_B.Switch[11] = 0.0F;
  template_Final_Project_MPC564_B.Switch[12] = 0.0F;
  template_Final_Project_MPC564_B.Switch[13] = 0.0F;
  template_Final_Project_MPC564_B.Switch[14] = 0.0F;
  template_Final_Project_MPC564_B.Switch[15] = 0.0F;
  template_Final_Project_MPC564_B.Switch[16] = 0.0F;
  template_Final_Project_MPC564_B.Switch[17] = 0.0F;
  template_Final_Project_MPC564_B.Switch[18] = 0.0F;
  template_Final_Project_MPC564_B.Switch[19] = 0.0F;
  template_Final_Project_MPC564_B.Switch[20] = 0.0F;
  template_Final_Project_MPC564_B.Switch[21] = 0.0F;
  template_Final_Project_MPC564_B.Switch[22] = 0.0F;
  template_Final_Project_MPC564_B.Switch[23] = 0.0F;

  /* S-Function (gpio_564xl_input): '<S6>/Digital Input' */
  template_Final_Project_MPC564_B.DigitalInput = gpi_pin_read_564xl_fnc(13);/* GPI Pin Data Input Registers  */

  /* Sum: '<S10>/Sum1' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion1'
   *  DataTypeConversion: '<S10>/Data Type Conversion2'
   *  Gain: '<S10>/Gain'
   *  Sum: '<S10>/Sum'
   *  UnitDelay: '<S10>/Unit Delay'
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  template_Final_Project_MPC564_B.Sum1 = (real32_T)(int16_T)(uint16_T)
    (template_Final_Project_MPC564_B.eTimerCNTRRegisterRead -
     template_Final_Project_MP_DWork.UnitDelay_DSTATE_e) * 0.09F +
    template_Final_Project_MP_DWork.UnitDelay1_DSTATE;

  /* S-Function (adc_564xl_input): '<S6>/ADC Channel' */

  /* ADC Data Input ADC_0 Channel 0  */
  template_Final_Project_MPC564_B.ADCChannel = adc_read_chan( 0, 0 );

  /* S-Function (gpio_564xl_input): '<S6>/Digital Input1' */
  template_Final_Project_MPC564_B.DigitalInput1 = gpi_pin_read_564xl_fnc(14);/* GPI Pin Data Input Registers  */

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator3' */
  template_Final_Project_MPC564_B.DiscreteTimeIntegrator3 =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Sum: '<S15>/Sum' incorporates:
   *  Constant: '<S15>/offset'
   *  Gain: '<S15>/torque gain'
   *  Gain: '<S5>/Gain'
   *  Product: '<S5>/Product'
   *  Sum: '<S7>/Sum'
   */
  rtb_DiscreteTimeIntegrator = (0.0F - 100.0F *
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator3 *
    template_Final_Project_MPC564_B.Sum1) * 0.0003162F + 0.5F;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Gain: '<S7>/Gain'
   *  Saturate: '<S7>/Saturation'
   */
  rtb_DiscreteTimeIntegrator = (real32_T)floor((rtb_DiscreteTimeIntegrator >=
    0.76F ? 0.76F : rtb_DiscreteTimeIntegrator <= 0.24F ? 0.24F :
    rtb_DiscreteTimeIntegrator) * 100.0F);
  if (rtIsNaNF(rtb_DiscreteTimeIntegrator) || rtIsInfF
      (rtb_DiscreteTimeIntegrator)) {
    rtb_DiscreteTimeIntegrator = 0.0F;
  } else {
    rtb_DiscreteTimeIntegrator = (real32_T)fmod(rtb_DiscreteTimeIntegrator,
      4.2949673E+9F);
  }

  template_Final_Project_MPC564_B.DataTypeConversion = (uint32_T)
    rtb_DiscreteTimeIntegrator;

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (Simple_PWM_564xL_output): '<S7>/Motor' */

  /* Simple PWM Outputs with Deadtime update: Module, Sub Module, Frequency, Resolution, DutyCycle, PWMH Dead time, PWML Dead time */
  pwm_update_564xL_simple_edge_align(0, 0, 20000U, 1, 0U,
    template_Final_Project_MPC564_B.DataTypeConversion);

  /* UnitDelay: '<S36>/Unit Delay' */
  template_Final_Project_MPC564_B.UnitDelay =
    template_Final_Project_MP_DWork.UnitDelay_DSTATE;

  /* S-Function (single2bytes): '<S16>/Single to Bytes' */

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

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  rtb_Conversion =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* S-Function (get_path1): '<S32>/Look up P' */
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

  /* Sum: '<S32>/Sum' */
  rtb_Product_c_idx_0 = rtb_DiscreteTimeIntegrator -
    template_Final_Project_MPC564_B.LookupP_o1;
  rtb_Product_c_idx = rtb_Conversion -
    template_Final_Project_MPC564_B.LookupP_o2;

  /* S-Function (get_rvec1): '<S32>/Look up Right Vector' */
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

  /* Sum: '<S38>/Sum1' incorporates:
   *  Product: '<S38>/Product'
   */
  template_Final_Project_MPC564_B.Sum1_g = rtb_Product_c_idx_0 *
    template_Final_Project_MPC564_B.LookupRightVector_o1 + rtb_Product_c_idx *
    template_Final_Project_MPC564_B.LookupRightVector_o2;

  /* S-Function (single2bytes): '<S16>/Single to Bytes1' */

  /* write the 4 bytes that make up the single-precision floating-point
   * input to the 4 outputs. */
  template_Final_Project_MPC564_B.SingletoBytes1[0] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1_g)[0];
  template_Final_Project_MPC564_B.SingletoBytes1[1] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1_g)[1];
  template_Final_Project_MPC564_B.SingletoBytes1[2] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1_g)[2];
  template_Final_Project_MPC564_B.SingletoBytes1[3] = ((uint8_T*)
    &template_Final_Project_MPC564_B.Sum1_g)[3];

  /* SignalConversion: '<S16>/TmpSignal ConversionAtCAN TransmitInport1' */
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

  /* S-Function (can_564xl_transmit): '<S16>/CAN Transmit' */
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
    if (105&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 105;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,0,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 0);
  }

  /* S-Function (get_rvec1): '<S33>/Look up Right Vector' */
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
        template_Final_Project_MPC564_B.LookupRightVector_o1_o = fy;
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

        template_Final_Project_MPC564_B.LookupRightVector_o1_o = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_b = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* DiscreteIntegrator: '<S30>/Discrete-Time Integrator2' */
  template_Final_Project_MPC564_B.DiscreteTimeIntegrator2 =
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Sum: '<S31>/Sum' */
  rtb_Conversion = template_Final_Project_MPC564_B.DiscreteTimeIntegrator2 +
    template_Final_Project_MPC564_B.Sum1;

  /* Product: '<S31>/Product2' incorporates:
   *  Gain: '<S33>/Gain'
   *  Product: '<S31>/Product'
   *  Product: '<S31>/Product1'
   *  Sum: '<S31>/Sum1'
   *  Trigonometry: '<S31>/Trigonometric Function'
   *  Trigonometry: '<S31>/Trigonometric Function1'
   */
  template_Final_Project_MPC564_B.Product2 =
    (template_Final_Project_MPC564_B.LookupRightVector_o1_o * (real32_T)sin
     (rtb_Conversion) + -template_Final_Project_MPC564_B.LookupRightVector_o2_b *
     (real32_T)cos(rtb_Conversion)) *
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator3;

  /* S-Function (single2bytes): '<S16>/Single to Bytes2' */

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

  /* S-Function (single2bytes): '<S16>/Single to Bytes3' */

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

  /* SignalConversion: '<S16>/TmpSignal ConversionAtCAN Transmit1Inport1' */
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

  /* S-Function (can_564xl_transmit): '<S16>/CAN Transmit1' */
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
    if (106&0xFFFF800)
      ptr_FLEXCAN_MsgBufferStructure->ext = 1;
    ptr_FLEXCAN_MsgBufferStructure->id = 106;
    for (i=0;i<datalen;i++) {
      ptr_FLEXCAN_MsgBufferStructure->data[i] = *(data++);
    }

    ptr_FLEXCAN_MsgBufferStructure->code = CAN_TX_MSG;
    flexcan_564xl_buffer_transmit(ptr_FLEXCAN_MsgBufferStructure,1,0);
    flexcan_564xl_release_mb_lock(0);
    flexcan_564xl_clear_mask(0, 1);
  }

  /* S-Function (get_path1): '<S17>/Look up P' */
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

  /* S-Function (get_rvec1): '<S17>/Look up Right Vector' */
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

  /* Sum: '<S17>/Sum' incorporates:
   *  Product: '<S17>/Product'
   */
  rtb_Product_a_idx_0 = template_Final_Project_MPC564_B.Sum1_g *
    template_Final_Project_MPC564_B.LookupRightVector_o1_b +
    template_Final_Project_MPC564_B.LookupP_o1_c;
  rtb_Product_a_idx = template_Final_Project_MPC564_B.Sum1_g *
    template_Final_Project_MPC564_B.LookupRightVector_o2_h +
    template_Final_Project_MPC564_B.LookupP_o2_b;

  /* S-Function (get_path1): '<S24>/Look up P' */
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

  /* S-Function (get_rvec1): '<S24>/Look up Right Vector' */
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

  /* Sum: '<S24>/Sum' incorporates:
   *  Product: '<S24>/Product'
   */
  C_h_idx_0 = template_Final_Project_MPC564_B.Switch[1] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_l +
    template_Final_Project_MPC564_B.LookupP_o1_k;
  C_h_idx = template_Final_Project_MPC564_B.Switch[1] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_c +
    template_Final_Project_MPC564_B.LookupP_o2_c;

  /* S-Function (get_path1): '<S25>/Look up P' */
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

  /* S-Function (get_rvec1): '<S25>/Look up Right Vector' */
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
        template_Final_Project_MPC564_B.LookupRightVector_o1_om = fy;
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

        template_Final_Project_MPC564_B.LookupRightVector_o1_om = cos(r);
        template_Final_Project_MPC564_B.LookupRightVector_o2_hm = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S25>/Sum' incorporates:
   *  Product: '<S25>/Product'
   */
  C_f_idx_0 = template_Final_Project_MPC564_B.Switch[5] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_om +
    template_Final_Project_MPC564_B.LookupP_o1_e;
  C_f_idx = template_Final_Project_MPC564_B.Switch[5] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_hm +
    template_Final_Project_MPC564_B.LookupP_o2_g;

  /* S-Function (get_path1): '<S26>/Look up P' */
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

  /* S-Function (get_rvec1): '<S26>/Look up Right Vector' */
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

  /* Sum: '<S26>/Sum' incorporates:
   *  Product: '<S26>/Product'
   */
  C_o_idx_0 = template_Final_Project_MPC564_B.Switch[9] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_a +
    template_Final_Project_MPC564_B.LookupP_o1_g;
  C_o_idx = template_Final_Project_MPC564_B.Switch[9] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_i +
    template_Final_Project_MPC564_B.LookupP_o2_j;

  /* S-Function (get_path1): '<S27>/Look up P' */
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

  /* S-Function (get_rvec1): '<S27>/Look up Right Vector' */
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

  /* Sum: '<S27>/Sum' incorporates:
   *  Product: '<S27>/Product'
   */
  C_d_idx_0 = template_Final_Project_MPC564_B.Switch[13] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_am +
    template_Final_Project_MPC564_B.LookupP_o1_i;
  C_d_idx = template_Final_Project_MPC564_B.Switch[13] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_l +
    template_Final_Project_MPC564_B.LookupP_o2_a;

  /* S-Function (get_path1): '<S28>/Look up P' */
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

  /* S-Function (get_rvec1): '<S28>/Look up Right Vector' */
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

  /* Sum: '<S28>/Sum' incorporates:
   *  Product: '<S28>/Product'
   */
  C_b_idx_0 = template_Final_Project_MPC564_B.Switch[17] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_j +
    template_Final_Project_MPC564_B.LookupP_o1_o;
  C_b_idx = template_Final_Project_MPC564_B.Switch[17] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_o +
    template_Final_Project_MPC564_B.LookupP_o2_k;

  /* S-Function (get_path1): '<S29>/Look up P' */
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

  /* S-Function (get_rvec1): '<S29>/Look up Right Vector' */
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
        template_Final_Project_MPC564_B.LookupRightVector_o2_bf = -fx;
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
        template_Final_Project_MPC564_B.LookupRightVector_o2_bf = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S29>/Sum' incorporates:
   *  Product: '<S29>/Product'
   */
  C_e_idx_0 = template_Final_Project_MPC564_B.Switch[21] *
    template_Final_Project_MPC564_B.LookupRightVector_o1_jm +
    template_Final_Project_MPC564_B.LookupP_o1_k0;
  C_e_idx = template_Final_Project_MPC564_B.Switch[21] *
    template_Final_Project_MPC564_B.LookupRightVector_o2_bf +
    template_Final_Project_MPC564_B.LookupP_o2_h;

  /* DataTypeConversion: '<S8>/DTC1' */
  rtb_Conversion = (real32_T)template_Final_Project_MPC564_B.ADCChannel;

  /* S-Function (vmod): '<S30>/S-Function Builder' */
  vmod_Outputs_wrapper(&template_Final_Project_MPC564_B.DiscreteTimeIntegrator3,
                       &template_Final_Project_MPC564_B.Sum1,
                       &template_Final_Project_MPC564_B.DiscreteTimeIntegrator2,
                       &template_Final_Project_M_ConstP.Constant_Value,
                       &template_Final_Project_M_ConstP.Constant1_Value,
                       &template_Final_Project_MPC564_B.SFunctionBuilder_o1,
                       &template_Final_Project_MPC564_B.SFunctionBuilder_o2,
                       &template_Final_Project_MPC564_B.SFunctionBuilder_o3 );

  /* Gain: '<S30>/divide by mass' incorporates:
   *  Gain: '<S30>/subtract drag'
   *  Sum: '<S30>/Sum'
   */
  rtb_DiscreteTimeIntegrator = (rtb_Conversion - 100.0F *
    template_Final_Project_MPC564_B.DiscreteTimeIntegrator3) * 0.0005F;

  /* S-Function (get_rvec1): '<S35>/Look up Right Vector' */
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

  /* Product: '<S37>/Product' incorporates:
   *  Gain: '<S35>/Gain'
   */
  rtb_Product_c_idx_0 *=
    -template_Final_Project_MPC564_B.LookupRightVector_o2_hx;

  /* DataTypeConversion: '<S32>/Data  Type  Conversion' incorporates:
   *  Product: '<S37>/Product'
   *  Sum: '<S37>/Sum1'
   */
  rtb_DataTypeConversion = rtb_Product_c_idx *
    template_Final_Project_MPC564_B.LookupRightVector_o1_c + rtb_Product_c_idx_0;

  /* DiscreteStateSpace: '<S32>/Controller' */
  {
    rtb_dsdt = 0.38289220218870362*
      template_Final_Project_MP_DWork.Controller_DSTATE;
    rtb_dsdt += 150.12501387153085*rtb_DataTypeConversion;
  }

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  template_Final_Project_MP_DWork.UnitDelay_DSTATE_e =
    template_Final_Project_MPC564_B.eTimerCNTRRegisterRead;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  template_Final_Project_MP_DWork.UnitDelay1_DSTATE =
    template_Final_Project_MPC564_B.Sum1;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator3' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator3_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * rtb_DiscreteTimeIntegrator +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator3_DSTATE;

  /* Update for UnitDelay: '<S36>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S34>/Conversion'
   *  Gain: '<S36>/Gain'
   *  Sum: '<S36>/Sum'
   */
  template_Final_Project_MP_DWork.UnitDelay_DSTATE = 0.01F * (real32_T)rtb_dsdt
    + template_Final_Project_MPC564_B.UnitDelay;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * template_Final_Project_MPC564_B.SFunctionBuilder_o1 +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator1' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator1_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * template_Final_Project_MPC564_B.SFunctionBuilder_o2 +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator2' */
  template_Final_Project_MP_DWork.DiscreteTimeIntegrator2_DSTATE = (real32_T)
    (0.0099999997764825821 * (real_T)
     template_Final_Project_MP_DWork.HighLevelDesign_ELAPS_T)
    * template_Final_Project_MPC564_B.SFunctionBuilder_o3 +
    template_Final_Project_MP_DWork.DiscreteTimeIntegrator2_DSTATE;

  /* Update for DiscreteStateSpace: '<S32>/Controller' */
  {
    real_T xnew[1];
    xnew[0] = 1.0*template_Final_Project_MP_DWork.Controller_DSTATE;
    xnew[0] += 0.65292519369349644*rtb_DataTypeConversion;
    (void) memcpy(&template_Final_Project_MP_DWork.Controller_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (template_Final_Project_MPC56_M->Timing.RateInteraction.TID0_1) {
    template_Final_Project_MPC564_B.RateTransition[0] = rtb_Product_a_idx_0;
    template_Final_Project_MPC564_B.RateTransition[1] = rtb_Product_a_idx;
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
  int8_T s39_iter;

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
   *  ForIterator: '<S39>/For Iterator'
   */
  for (s39_iter = 0; s39_iter < 91; s39_iter++) {
    /* MultiPortSwitch: '<S39>/Index Vector' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    switch (s39_iter) {
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

    /* End of MultiPortSwitch: '<S39>/Index Vector' */

    /* S-Function (SerialSend): '<S39>/S-Function' */
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
  /* Start for S-Function (can_564xl_receive_data): '<S11>/CAN_Receive_data' */
  {
    if ((0U & 0x1FFFF800) != 0x0) {    //extended tag
      flexcan_564xl_set_filter_id(0, 2, 0U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 2, 0U, 0);
    }
  }

  /* Start for S-Function (can_564xl_receive_data): '<S11>/CAN_Receive_data1' */
  {
    if ((0U & 0x1FFFF800) != 0x0) {    //extended tag
      flexcan_564xl_set_filter_id(0, 3, 0U, 1);
    } else {                           //standart tag
      flexcan_564xl_set_filter_id(0, 3, 0U, 0);
    }
  }

  /* Start for S-Function (gpio_564xl_input): '<S6>/Digital Input' */

  /* Initialize Pad Configuration Register 13 as Input */
  gpi_init_pcr_in_564xl_fnc( 13 );

  /* Start for S-Function (adc_564xl_input): '<S6>/ADC Channel' */
  adc_pin_init( 0, 0);
  adc_channelmode_setup( 0, 0, 1);
  adc_presample( 0, 0, 0);

  /* Start for S-Function (gpio_564xl_input): '<S6>/Digital Input1' */

  /* Initialize Pad Configuration Register 14 as Input */
  gpi_init_pcr_in_564xl_fnc( 14 );

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
