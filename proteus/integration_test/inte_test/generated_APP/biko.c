/*
 * File: biko.c
 *
 * Code generated for Simulink model 'biko'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug 31 01:49:18 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "biko.h"

/* External inputs (root inport signals with default storage) */
ExtU_biko_T biko_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_biko_T biko_Y;

/* Real-time model */
static RT_MODEL_biko_T biko_M_;
RT_MODEL_biko_T *const biko_M = &biko_M_;

/* Model step function */
void biko_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/Input'
   */
  biko_Y.Out1 = biko_U.Input;
}

/* Model initialize function */
void biko_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void biko_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
