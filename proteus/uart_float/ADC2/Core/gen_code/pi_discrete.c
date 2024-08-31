/*
 * File: pi_discrete.c
 *
 * Code generated for Simulink model 'pi_discrete'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Aug 31 15:23:27 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pi_discrete.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "pi_discrete_private.h"

/* Block states (default storage) */
DW_pi_discrete_T pi_discrete_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_pi_discrete_T pi_discrete_Y;

/* Real-time model */
static RT_MODEL_pi_discrete_T pi_discrete_M_;
RT_MODEL_pi_discrete_T *const pi_discrete_M = &pi_discrete_M_;
real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    int32_T ni;
    uint32_T a0;
    uint32_T a1;
    uint32_T cb;
    uint32_T u1i;
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      uint32_T b1;
      uint32_T w01;
      uint32_T w10;
      uint32_T yk;
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/* Model step function */
void pi_discrete_step(void)
{
  uint64m_T tmp;
  real_T rtb_FilterCoefficient;
  real_T rtb_Subtract;
  uint32_T tmp_0;
  uint32_T tmp_1;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/v_meas'
   */
  tmp_0 = 2442762650U;
  tmp_1 = 54080U * get_v_test();
  uMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Subtract = 3.3 - uMultiWord2Double(&tmp.chunks[0U], 2, 0) *
    2.7755575615628914E-17;

  /* Gain: '<S38>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S30>/Filter'
   *  Gain: '<S28>/Derivative Gain'
   *  Sum: '<S30>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * rtb_Subtract - pi_discrete_DW.Filter_DSTATE) *
    100.0;

  /* Outport: '<Root>/duty_cyle' incorporates:
   *  DiscreteIntegrator: '<S35>/Integrator'
   *  Sum: '<S44>/Sum'
   */
  pi_discrete_Y.duty_cyle = (rtb_Subtract + pi_discrete_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S30>/Filter' */
  pi_discrete_DW.Filter_DSTATE += 0.2 * rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S35>/Integrator' */
  pi_discrete_DW.Integrator_DSTATE += 0.2 * rtb_Subtract;
}

/* Model initialize function */
void pi_discrete_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void pi_discrete_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
