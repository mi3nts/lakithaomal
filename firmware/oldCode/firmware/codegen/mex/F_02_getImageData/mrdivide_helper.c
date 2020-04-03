/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yh_emlrtRSI = { 42, /* lineNo */
  "mrdiv",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo ai_emlrtRSI = { 61, /* lineNo */
  "lusolve",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo bi_emlrtRSI = { 292,/* lineNo */
  "lusolve3x3",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

static emlrtRSInfo ci_emlrtRSI = { 90, /* lineNo */
  "warn_singular",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/lusolve.m"/* pathName */
};

/* Function Definitions */
void mrdiv(const emlrtStack *sp, const real_T A[9], const real_T B[9], real_T Y
           [9])
{
  real_T b_A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  real_T Y_tmp;
  real_T b_Y_tmp;
  real_T c_Y_tmp;
  real_T d_Y_tmp;
  int32_T e_Y_tmp;
  int32_T f_Y_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ai_emlrtRSI;
  memcpy(&b_A[0], &B[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(B[0]);
  a21 = muDoubleScalarAbs(B[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (muDoubleScalarAbs(B[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  b_A[r2] = B[r2] / B[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
  b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
  b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
  b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
  if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  if ((b_A[r1] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] == 0.0)) {
    c_st.site = &bi_emlrtRSI;
    d_st.site = &ci_emlrtRSI;
    b_warning(&d_st);
  }

  Y[3 * r1] = A[0] / b_A[r1];
  maxval = b_A[r1 + 3];
  Y[3 * r2] = A[3] - Y[3 * r1] * maxval;
  a21 = b_A[r1 + 6];
  Y[3 * r3] = A[6] - Y[3 * r1] * a21;
  Y_tmp = b_A[r2 + 3];
  Y[3 * r2] /= Y_tmp;
  b_Y_tmp = b_A[r2 + 6];
  Y[3 * r3] -= Y[3 * r2] * b_Y_tmp;
  c_Y_tmp = b_A[r3 + 6];
  Y[3 * r3] /= c_Y_tmp;
  d_Y_tmp = b_A[r3 + 3];
  Y[3 * r2] -= Y[3 * r3] * d_Y_tmp;
  Y[3 * r1] -= Y[3 * r3] * b_A[r3];
  Y[3 * r1] -= Y[3 * r2] * b_A[r2];
  rtemp = 3 * r1 + 1;
  Y[rtemp] = A[1] / b_A[r1];
  e_Y_tmp = 3 * r2 + 1;
  Y[e_Y_tmp] = A[4] - Y[rtemp] * maxval;
  f_Y_tmp = 3 * r3 + 1;
  Y[f_Y_tmp] = A[7] - Y[rtemp] * a21;
  Y[e_Y_tmp] /= Y_tmp;
  Y[f_Y_tmp] -= Y[e_Y_tmp] * b_Y_tmp;
  Y[f_Y_tmp] /= c_Y_tmp;
  Y[e_Y_tmp] -= Y[f_Y_tmp] * d_Y_tmp;
  Y[rtemp] -= Y[f_Y_tmp] * b_A[r3];
  Y[rtemp] -= Y[e_Y_tmp] * b_A[r2];
  rtemp = 3 * r1 + 2;
  Y[rtemp] = A[2] / b_A[r1];
  e_Y_tmp = 3 * r2 + 2;
  Y[e_Y_tmp] = A[5] - Y[rtemp] * maxval;
  f_Y_tmp = 3 * r3 + 2;
  Y[f_Y_tmp] = A[8] - Y[rtemp] * a21;
  Y[e_Y_tmp] /= Y_tmp;
  Y[f_Y_tmp] -= Y[e_Y_tmp] * b_Y_tmp;
  Y[f_Y_tmp] /= c_Y_tmp;
  Y[e_Y_tmp] -= Y[f_Y_tmp] * d_Y_tmp;
  Y[rtemp] -= Y[f_Y_tmp] * b_A[r3];
  Y[rtemp] -= Y[e_Y_tmp] * b_A[r2];
}

/* End of code generation (mrdivide_helper.c) */
