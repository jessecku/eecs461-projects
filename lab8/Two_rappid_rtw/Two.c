/*
 * File: Two.c
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

#include "Two.h"
#include "Two_private.h"

/* Block signals (auto storage) */
BlockIO_Two Two_B;

/* Model step function */
void Two_step(void)
{
  uint8_T rtb_BitwiseOperator4;
  uint8_T rtb_ShiftArithmetic1;
  uint8_T rtb_ShiftArithmetic2;
  uint8_T rtb_ShiftArithmetic2_b;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Adder Task'
   */

  /* S-Function (gpio_564xl_input): '<S2>/Digital Input' */
  Two_B.DigitalInput = gpi_pin_read_564xl_fnc(5);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  rtb_BitwiseOperator4 = Two_B.DigitalInput;

  /* S-Function (gpio_564xl_input): '<S2>/Digital Input1' */
  Two_B.DigitalInput1 = gpi_pin_read_564xl_fnc(6);/* GPI Pin Data Input Registers  */

  /* ArithShift: '<S2>/Shift Arithmetic1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_ShiftArithmetic1 = (uint8_T)(Two_B.DigitalInput1 << 1);

  /* S-Function (gpio_564xl_input): '<S2>/Digital Input2' */
  Two_B.DigitalInput2 = gpi_pin_read_564xl_fnc(7);/* GPI Pin Data Input Registers  */

  /* ArithShift: '<S2>/Shift Arithmetic2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   */
  rtb_ShiftArithmetic2 = (uint8_T)(Two_B.DigitalInput2 << 2);

  /* S-Function (gpio_564xl_input): '<S2>/Digital Input3' */
  Two_B.DigitalInput3 = gpi_pin_read_564xl_fnc(8);/* GPI Pin Data Input Registers  */

  /* Sum: '<S2>/Sum' incorporates:
   *  ArithShift: '<S2>/Shift Arithmetic3'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_BitwiseOperator4 = (uint8_T)((((uint32_T)rtb_BitwiseOperator4 + (uint32_T)
    rtb_ShiftArithmetic1) + (uint32_T)rtb_ShiftArithmetic2) + (uint32_T)
    (Two_B.DigitalInput3 << 3));

  /* S-Function (gpio_564xl_input): '<S3>/Digital Input' */
  Two_B.DigitalInput_l = gpi_pin_read_564xl_fnc(9);/* GPI Pin Data Input Registers  */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  rtb_ShiftArithmetic1 = Two_B.DigitalInput_l;

  /* S-Function (gpio_564xl_input): '<S3>/Digital Input1' */
  Two_B.DigitalInput1_h = gpi_pin_read_564xl_fnc(10);/* GPI Pin Data Input Registers  */

  /* ArithShift: '<S3>/Shift Arithmetic1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  rtb_ShiftArithmetic2 = (uint8_T)(Two_B.DigitalInput1_h << 1);

  /* S-Function (gpio_564xl_input): '<S3>/Digital Input2' */
  Two_B.DigitalInput2_d = gpi_pin_read_564xl_fnc(11);/* GPI Pin Data Input Registers  */

  /* ArithShift: '<S3>/Shift Arithmetic2' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  rtb_ShiftArithmetic2_b = (uint8_T)(Two_B.DigitalInput2_d << 2);

  /* S-Function (gpio_564xl_input): '<S3>/Digital Input3' */
  Two_B.DigitalInput3_d = gpi_pin_read_564xl_fnc(12);/* GPI Pin Data Input Registers  */

  /* Sum: '<S1>/Sum' incorporates:
   *  ArithShift: '<S3>/Shift Arithmetic3'
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   *  Sum: '<S3>/Sum'
   */
  rtb_ShiftArithmetic1 = (uint8_T)(((((uint32_T)rtb_ShiftArithmetic1 + (uint32_T)
    rtb_ShiftArithmetic2) + (uint32_T)rtb_ShiftArithmetic2_b) + (uint32_T)
    rtb_BitwiseOperator4) + (uint32_T)(Two_B.DigitalInput3_d << 3));

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator'
   */
  Two_B.DataTypeConversion = ((rtb_ShiftArithmetic1 & 1) != 0);

  /* S-Function (gpio_564xl_output): '<S4>/Digital Output ' */

  /* Pin Data Output Signal Update PCR[43]. */
  gpo_pin_update_564xl_fnc(43, Two_B.DataTypeConversion);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator1'
   */
  Two_B.DataTypeConversion1 = ((rtb_ShiftArithmetic1 & 2) != 0);

  /* S-Function (gpio_564xl_output): '<S4>/Digital Output 1' */

  /* Pin Data Output Signal Update PCR[44]. */
  gpo_pin_update_564xl_fnc(44, Two_B.DataTypeConversion1);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator2'
   */
  Two_B.DataTypeConversion2 = ((rtb_ShiftArithmetic1 & 4) != 0);

  /* S-Function (gpio_564xl_output): '<S4>/Digital Output 2' */

  /* Pin Data Output Signal Update PCR[45]. */
  gpo_pin_update_564xl_fnc(45, Two_B.DataTypeConversion2);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator3'
   */
  Two_B.DataTypeConversion3 = ((rtb_ShiftArithmetic1 & 8) != 0);

  /* S-Function (gpio_564xl_output): '<S4>/Digital Output 3' */

  /* Pin Data Output Signal Update PCR[46]. */
  gpo_pin_update_564xl_fnc(46, Two_B.DataTypeConversion3);/* GPO Pin Data Output Register Update */

  /* DataTypeConversion: '<S4>/Data Type Conversion4' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator4'
   */
  Two_B.DataTypeConversion4 = ((rtb_ShiftArithmetic1 & 16) != 0);

  /* S-Function (gpio_564xl_output): '<S4>/Digital Output 4' */

  /* Pin Data Output Signal Update PCR[47]. */
  gpo_pin_update_564xl_fnc(47, Two_B.DataTypeConversion4);/* GPO Pin Data Output Register Update */
}

/* Model initialize function */
void Two_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &Two_B), 0,
                sizeof(BlockIO_Two));

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<Root>/Adder Task'
   */
  /* Start for S-Function (gpio_564xl_input): '<S2>/Digital Input' */

  /* Initialize Pad Configuration Register 5 as Input */
  gpi_init_pcr_in_564xl_fnc( 5 );

  /* Start for S-Function (gpio_564xl_input): '<S2>/Digital Input1' */

  /* Initialize Pad Configuration Register 6 as Input */
  gpi_init_pcr_in_564xl_fnc( 6 );

  /* Start for S-Function (gpio_564xl_input): '<S2>/Digital Input2' */

  /* Initialize Pad Configuration Register 7 as Input */
  gpi_init_pcr_in_564xl_fnc( 7 );

  /* Start for S-Function (gpio_564xl_input): '<S2>/Digital Input3' */

  /* Initialize Pad Configuration Register 8 as Input */
  gpi_init_pcr_in_564xl_fnc( 8 );

  /* Start for S-Function (gpio_564xl_input): '<S3>/Digital Input' */

  /* Initialize Pad Configuration Register 9 as Input */
  gpi_init_pcr_in_564xl_fnc( 9 );

  /* Start for S-Function (gpio_564xl_input): '<S3>/Digital Input1' */

  /* Initialize Pad Configuration Register 10 as Input */
  gpi_init_pcr_in_564xl_fnc( 10 );

  /* Start for S-Function (gpio_564xl_input): '<S3>/Digital Input2' */

  /* Initialize Pad Configuration Register 11 as Input */
  gpi_init_pcr_in_564xl_fnc( 11 );

  /* Start for S-Function (gpio_564xl_input): '<S3>/Digital Input3' */

  /* Initialize Pad Configuration Register 12 as Input */
  gpi_init_pcr_in_564xl_fnc( 12 );

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output ' */

  /* Initialize Pad Configuration Register 43 as Output */
  gpo_init_pcr_out_564xl_fnc( 43 );

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output 1' */

  /* Initialize Pad Configuration Register 44 as Output */
  gpo_init_pcr_out_564xl_fnc( 44 );

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output 2' */

  /* Initialize Pad Configuration Register 45 as Output */
  gpo_init_pcr_out_564xl_fnc( 45 );

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output 3' */

  /* Initialize Pad Configuration Register 46 as Output */
  gpo_init_pcr_out_564xl_fnc( 46 );

  /* Start for S-Function (gpio_564xl_output): '<S4>/Digital Output 4' */

  /* Initialize Pad Configuration Register 47 as Output */
  gpo_init_pcr_out_564xl_fnc( 47 );
}

/* Model terminate function */
void Two_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
