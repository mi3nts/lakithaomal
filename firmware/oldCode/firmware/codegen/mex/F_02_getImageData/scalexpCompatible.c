/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalexpCompatible.c
 *
 * Code generation for function 'scalexpCompatible'
 *
 */

/* Include files */
#include "scalexpCompatible.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T scalexpCompatible(const emxArray_real_T *a, const emxArray_real_T *b)
{
  boolean_T p;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  varargin_1[0] = (uint32_T)a->size[0];
  varargin_2[0] = (uint32_T)b->size[0];
  varargin_1[1] = (uint32_T)a->size[1];
  varargin_2[1] = (uint32_T)b->size[1];
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return b_p || p;
}

/* End of code generation (scalexpCompatible.c) */
