/*
 * File: pi_discrete.h
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

#ifndef pi_discrete_h_
#define pi_discrete_h_
#ifndef pi_discrete_COMMON_INCLUDES_
#define pi_discrete_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* pi_discrete_COMMON_INCLUDES_ */

#include "pi_discrete_types.h"
#include <math.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Filter_DSTATE;                /* '<S30>/Filter' */
  real_T Integrator_DSTATE;            /* '<S35>/Integrator' */
} DW_pi_discrete_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T duty_cyle;                    /* '<Root>/duty_cyle' */
} ExtY_pi_discrete_T;

/* Real-time Model Data Structure */
struct tag_RTM_pi_discrete_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_pi_discrete_T pi_discrete_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_pi_discrete_T pi_discrete_Y;

/* Model entry point functions */
extern void pi_discrete_initialize(void);
extern void pi_discrete_step(void);
extern void pi_discrete_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pi_discrete_T *const pi_discrete_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S32>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S40>/Proportional Gain' : Eliminated nontunable gain of 1
 */

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
 * '<Root>' : 'pi_discrete'
 * '<S1>'   : 'pi_discrete/PID Controller'
 * '<S2>'   : 'pi_discrete/PID Controller/Anti-windup'
 * '<S3>'   : 'pi_discrete/PID Controller/D Gain'
 * '<S4>'   : 'pi_discrete/PID Controller/External Derivative'
 * '<S5>'   : 'pi_discrete/PID Controller/Filter'
 * '<S6>'   : 'pi_discrete/PID Controller/Filter ICs'
 * '<S7>'   : 'pi_discrete/PID Controller/I Gain'
 * '<S8>'   : 'pi_discrete/PID Controller/Ideal P Gain'
 * '<S9>'   : 'pi_discrete/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'pi_discrete/PID Controller/Integrator'
 * '<S11>'  : 'pi_discrete/PID Controller/Integrator ICs'
 * '<S12>'  : 'pi_discrete/PID Controller/N Copy'
 * '<S13>'  : 'pi_discrete/PID Controller/N Gain'
 * '<S14>'  : 'pi_discrete/PID Controller/P Copy'
 * '<S15>'  : 'pi_discrete/PID Controller/Parallel P Gain'
 * '<S16>'  : 'pi_discrete/PID Controller/Reset Signal'
 * '<S17>'  : 'pi_discrete/PID Controller/Saturation'
 * '<S18>'  : 'pi_discrete/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'pi_discrete/PID Controller/Sum'
 * '<S20>'  : 'pi_discrete/PID Controller/Sum Fdbk'
 * '<S21>'  : 'pi_discrete/PID Controller/Tracking Mode'
 * '<S22>'  : 'pi_discrete/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'pi_discrete/PID Controller/Tsamp - Integral'
 * '<S24>'  : 'pi_discrete/PID Controller/Tsamp - Ngain'
 * '<S25>'  : 'pi_discrete/PID Controller/postSat Signal'
 * '<S26>'  : 'pi_discrete/PID Controller/preSat Signal'
 * '<S27>'  : 'pi_discrete/PID Controller/Anti-windup/Passthrough'
 * '<S28>'  : 'pi_discrete/PID Controller/D Gain/Internal Parameters'
 * '<S29>'  : 'pi_discrete/PID Controller/External Derivative/Error'
 * '<S30>'  : 'pi_discrete/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S31>'  : 'pi_discrete/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S32>'  : 'pi_discrete/PID Controller/I Gain/Internal Parameters'
 * '<S33>'  : 'pi_discrete/PID Controller/Ideal P Gain/Passthrough'
 * '<S34>'  : 'pi_discrete/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S35>'  : 'pi_discrete/PID Controller/Integrator/Discrete'
 * '<S36>'  : 'pi_discrete/PID Controller/Integrator ICs/Internal IC'
 * '<S37>'  : 'pi_discrete/PID Controller/N Copy/Disabled'
 * '<S38>'  : 'pi_discrete/PID Controller/N Gain/Internal Parameters'
 * '<S39>'  : 'pi_discrete/PID Controller/P Copy/Disabled'
 * '<S40>'  : 'pi_discrete/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S41>'  : 'pi_discrete/PID Controller/Reset Signal/Disabled'
 * '<S42>'  : 'pi_discrete/PID Controller/Saturation/Passthrough'
 * '<S43>'  : 'pi_discrete/PID Controller/Saturation Fdbk/Disabled'
 * '<S44>'  : 'pi_discrete/PID Controller/Sum/Sum_PID'
 * '<S45>'  : 'pi_discrete/PID Controller/Sum Fdbk/Disabled'
 * '<S46>'  : 'pi_discrete/PID Controller/Tracking Mode/Disabled'
 * '<S47>'  : 'pi_discrete/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S48>'  : 'pi_discrete/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S49>'  : 'pi_discrete/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S50>'  : 'pi_discrete/PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'pi_discrete/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* pi_discrete_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
