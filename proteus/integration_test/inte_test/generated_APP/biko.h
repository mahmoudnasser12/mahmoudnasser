/*
 * File: biko.h
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

#ifndef biko_h_
#define biko_h_
#ifndef biko_COMMON_INCLUDES_
#define biko_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* biko_COMMON_INCLUDES_ */

#include "biko_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Input;                        /* '<Root>/Input' */
} ExtU_biko_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_biko_T;

/* Real-time Model Data Structure */
struct tag_RTM_biko_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_biko_T biko_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_biko_T biko_Y;

/* Model entry point functions */
extern void biko_initialize(void);
extern void biko_step(void);
extern void biko_terminate(void);

/* Real-time Model object */
extern RT_MODEL_biko_T *const biko_M;

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
 * '<Root>' : 'biko'
 * '<S1>'   : 'biko/Subsystem'
 */
#endif                                 /* biko_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
