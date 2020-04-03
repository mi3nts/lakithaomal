/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sub2ind.c
 *
 * Code generation for function 'sub2ind'
 *
 */

/* Include files */
#include "sub2ind.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo db_emlrtRTEI = { 41,/* lineNo */
  19,                                  /* colNo */
  "eml_sub2ind",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 31,/* lineNo */
  23,                                  /* colNo */
  "eml_sub2ind",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = { 48,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

/* Function Definitions */
void eml_sub2ind(const emlrtStack *sp, const emxArray_real_T *varargin_1, const
                 emxArray_real_T *varargin_2, emxArray_int32_T *idx)
{
  int32_T k;
  boolean_T exitg1;
  uint32_T b_varargin_1[2];
  uint32_T b_varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  int32_T loop_ub;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_1->size[0] - 1)) {
    if ((varargin_1->data[k] >= 1.0) && (varargin_1->data[k] <= 480.0)) {
      k++;
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &db_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", "MATLAB:sub2ind:IndexOutOfRange", 0);
    }
  }

  b_varargin_1[0] = (uint32_T)varargin_1->size[0];
  b_varargin_1[1] = 1U;
  b_varargin_2[0] = (uint32_T)varargin_2->size[0];
  b_varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)b_varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  b_p = (int32_T)p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(sp, &eb_emlrtRTEI,
      "MATLAB:sub2ind:SubscriptVectorSize", "MATLAB:sub2ind:SubscriptVectorSize",
      0);
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= varargin_2->size[0] - 1)) {
    if ((varargin_2->data[k] >= 1.0) && (varargin_2->data[k] <= 640.0)) {
      k++;
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &db_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", "MATLAB:sub2ind:IndexOutOfRange", 0);
    }
  }

  k = idx->size[0];
  idx->size[0] = varargin_1->size[0];
  emxEnsureCapacity_int32_T(sp, idx, k, &vg_emlrtRTEI);
  loop_ub = varargin_1->size[0];
  for (k = 0; k < loop_ub; k++) {
    idx->data[k] = (int32_T)varargin_1->data[k] + 480 * ((int32_T)
      varargin_2->data[k] - 1);
  }
}

/* End of code generation (sub2ind.c) */
