/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * reshapeSizeChecks.c
 *
 * Code generation for function 'reshapeSizeChecks'
 *
 */

/* Include files */
#include "reshapeSizeChecks.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T allNonNegative(int32_T varargin_1, int32_T varargin_2)
{
  boolean_T out;
  if ((varargin_1 >= 0) && (varargin_2 >= 0)) {
    out = true;
  } else {
    out = false;
  }

  return out;
}

/* End of code generation (reshapeSizeChecks.c) */
