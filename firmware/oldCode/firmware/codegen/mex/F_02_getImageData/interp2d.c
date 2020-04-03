/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp2d.c
 *
 * Code generation for function 'interp2d'
 *
 */

/* Include files */
#include "interp2d.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "libmwimterp2d.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "validateattributes.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo cf_emlrtRSI = { 138,/* lineNo */
  "interpolate_imterp2",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/interp2d.m"/* pathName */
};

static emlrtRTEInfo bf_emlrtRTEI = { 106,/* lineNo */
  17,                                  /* colNo */
  "Imterp2DBuildable",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/+buildable/Imterp2DBuildable.m"/* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = { 107,/* lineNo */
  17,                                  /* colNo */
  "Imterp2DBuildable",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/+buildable/Imterp2DBuildable.m"/* pName */
};

static emlrtRTEInfo df_emlrtRTEI = { 103,/* lineNo */
  17,                                  /* colNo */
  "Imterp2DBuildable",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/+buildable/Imterp2DBuildable.m"/* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = { 104,/* lineNo */
  17,                                  /* colNo */
  "Imterp2DBuildable",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/+buildable/Imterp2DBuildable.m"/* pName */
};

/* Function Definitions */
void b_interp2d(F_02_getImageDataStackData *SD, const emlrtStack *sp, const
                emxArray_real32_T *Xin, const emxArray_real32_T *Yin,
                emxArray_uint8_T *outputImage_)
{
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T b_p;
  emxArray_real32_T *X_T;
  uint8_T fillValues;
  int32_T loop_ub;
  emxArray_real32_T *Y_T;
  real_T b_outputImage_[2];
  real_T b_dv[3];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ye_emlrtRSI;
  validateattributes(&st, Xin);
  st.site = &af_emlrtRSI;
  b_validateattributes(&st, Yin);
  varargin_1[0] = (uint32_T)Xin->size[0];
  varargin_2[0] = (uint32_T)Yin->size[0];
  varargin_1[1] = (uint32_T)Xin->size[1];
  varargin_2[1] = (uint32_T)Yin->size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  b_p = (int32_T)p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(sp, &x_emlrtRTEI,
      "images:interp2d:inconsistentXYSize", "images:interp2d:inconsistentXYSize",
      0);
  }

  st.site = &bf_emlrtRSI;
  k = outputImage_->size[0] * outputImage_->size[1];
  outputImage_->size[0] = Xin->size[0];
  outputImage_->size[1] = Xin->size[1];
  emxEnsureCapacity_uint8_T(&st, outputImage_, k, &af_emlrtRTEI);
  b_st.site = &cf_emlrtRSI;
  memset(&SD->u1.f0.inputImage[0], 1, 307200U * sizeof(uint8_T));
  emxInit_real32_T(&b_st, &X_T, 2, &df_emlrtRTEI, true);
  fillValues = 0U;
  k = X_T->size[0] * X_T->size[1];
  X_T->size[0] = Yin->size[0];
  X_T->size[1] = Yin->size[1];
  emxEnsureCapacity_real32_T(&b_st, X_T, k, &bf_emlrtRTEI);
  loop_ub = Yin->size[0] * Yin->size[1];
  for (k = 0; k < loop_ub; k++) {
    X_T->data[k] = Yin->data[k];
  }

  emxInit_real32_T(&b_st, &Y_T, 2, &ef_emlrtRTEI, true);
  k = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = Xin->size[0];
  Y_T->size[1] = Xin->size[1];
  emxEnsureCapacity_real32_T(&b_st, Y_T, k, &cf_emlrtRTEI);
  loop_ub = Xin->size[0] * Xin->size[1];
  for (k = 0; k < loop_ub; k++) {
    Y_T->data[k] = Xin->data[k];
  }

  b_outputImage_[0] = Xin->size[0];
  b_outputImage_[1] = Xin->size[1];
  b_dv[0] = dv1[0];
  b_dv[1] = dv1[1];
  b_dv[2] = dv1[2];
  imterp2d32f_uint8(SD->u1.f0.inputImage, b_dv, &X_T->data[0], &Y_T->data[0],
                    b_outputImage_, 1.0, true, &fillValues, &outputImage_->data
                    [0]);
  emxFree_real32_T(&Y_T);
  emxFree_real32_T(&X_T);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_interp2d(const emlrtStack *sp, const uint8_T inputImage__[921600], const
                emxArray_real32_T *Xin, const emxArray_real32_T *Yin,
                emxArray_uint8_T *outputImage_)
{
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T b_p;
  emxArray_real32_T *X_T;
  uint8_T fillValues[3];
  int32_T loop_ub;
  emxArray_real32_T *Y_T;
  real_T b_outputImage_[3];
  real_T b_dv[3];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ye_emlrtRSI;
  validateattributes(&st, Xin);
  st.site = &af_emlrtRSI;
  b_validateattributes(&st, Yin);
  varargin_1[0] = (uint32_T)Xin->size[0];
  varargin_2[0] = (uint32_T)Yin->size[0];
  varargin_1[1] = (uint32_T)Xin->size[1];
  varargin_2[1] = (uint32_T)Yin->size[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)varargin_1[k] != (int32_T)varargin_2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  b_p = (int32_T)p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(sp, &x_emlrtRTEI,
      "images:interp2d:inconsistentXYSize", "images:interp2d:inconsistentXYSize",
      0);
  }

  emxInit_real32_T(sp, &X_T, 2, &df_emlrtRTEI, true);
  st.site = &bf_emlrtRSI;
  k = outputImage_->size[0] * outputImage_->size[1] * outputImage_->size[2];
  outputImage_->size[0] = Xin->size[0];
  outputImage_->size[1] = Xin->size[1];
  outputImage_->size[2] = 3;
  emxEnsureCapacity_uint8_T(&st, outputImage_, k, &af_emlrtRTEI);
  b_st.site = &cf_emlrtRSI;
  fillValues[0] = 0U;
  fillValues[1] = 0U;
  fillValues[2] = 0U;
  k = X_T->size[0] * X_T->size[1];
  X_T->size[0] = Yin->size[0];
  X_T->size[1] = Yin->size[1];
  emxEnsureCapacity_real32_T(&b_st, X_T, k, &bf_emlrtRTEI);
  loop_ub = Yin->size[0] * Yin->size[1];
  for (k = 0; k < loop_ub; k++) {
    X_T->data[k] = Yin->data[k];
  }

  emxInit_real32_T(&b_st, &Y_T, 2, &ef_emlrtRTEI, true);
  k = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = Xin->size[0];
  Y_T->size[1] = Xin->size[1];
  emxEnsureCapacity_real32_T(&b_st, Y_T, k, &cf_emlrtRTEI);
  loop_ub = Xin->size[0] * Xin->size[1];
  for (k = 0; k < loop_ub; k++) {
    Y_T->data[k] = Xin->data[k];
  }

  b_outputImage_[0] = Xin->size[0];
  b_outputImage_[1] = Xin->size[1];
  b_outputImage_[2] = 3.0;
  b_dv[0] = dv[0];
  b_dv[1] = dv[1];
  b_dv[2] = dv[2];
  imterp2d32f_uint8(inputImage__, b_dv, &X_T->data[0], &Y_T->data[0],
                    b_outputImage_, 2.0, false, fillValues, &outputImage_->data
                    [0]);
  emxFree_real32_T(&Y_T);
  emxFree_real32_T(&X_T);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void interp2d(const emlrtStack *sp, const real_T inputImage__[307200], const
              emxArray_real_T *Xin, const emxArray_real_T *Yin, emxArray_real_T *
              outputImage_)
{
  boolean_T p;
  int32_T i;
  int32_T k;
  boolean_T exitg1;
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T b_p;
  emxArray_real_T *X_T;
  real_T fillValues;
  emxArray_real_T *Y_T;
  real_T b_outputImage_[2];
  real_T b_dv[3];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ye_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  i = Xin->size[0] * Xin->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if (!muDoubleScalarIsNaN(Xin->data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "X");
  }

  st.site = &af_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  i = Yin->size[0] * Yin->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if (!muDoubleScalarIsNaN(Yin->data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "Y");
  }

  varargin_1[0] = (uint32_T)Xin->size[0];
  varargin_2[0] = (uint32_T)Yin->size[0];
  varargin_1[1] = (uint32_T)Xin->size[1];
  varargin_2[1] = (uint32_T)Yin->size[1];
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

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(sp, &x_emlrtRTEI,
      "images:interp2d:inconsistentXYSize", "images:interp2d:inconsistentXYSize",
      0);
  }

  emxInit_real_T(sp, &X_T, 2, &df_emlrtRTEI, true);
  st.site = &bf_emlrtRSI;
  i = outputImage_->size[0] * outputImage_->size[1];
  outputImage_->size[0] = Xin->size[0];
  outputImage_->size[1] = Xin->size[1];
  emxEnsureCapacity_real_T(&st, outputImage_, i, &af_emlrtRTEI);
  b_st.site = &cf_emlrtRSI;
  fillValues = 0.0;
  i = X_T->size[0] * X_T->size[1];
  X_T->size[0] = Yin->size[0];
  X_T->size[1] = Yin->size[1];
  emxEnsureCapacity_real_T(&b_st, X_T, i, &bf_emlrtRTEI);
  k = Yin->size[0] * Yin->size[1];
  for (i = 0; i < k; i++) {
    X_T->data[i] = Yin->data[i];
  }

  emxInit_real_T(&b_st, &Y_T, 2, &ef_emlrtRTEI, true);
  i = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = Xin->size[0];
  Y_T->size[1] = Xin->size[1];
  emxEnsureCapacity_real_T(&b_st, Y_T, i, &cf_emlrtRTEI);
  k = Xin->size[0] * Xin->size[1];
  for (i = 0; i < k; i++) {
    Y_T->data[i] = Xin->data[i];
  }

  b_outputImage_[0] = Xin->size[0];
  b_outputImage_[1] = Xin->size[1];
  b_dv[0] = dv1[0];
  b_dv[1] = dv1[1];
  b_dv[2] = dv1[2];
  imterp2d64f_real64(inputImage__, b_dv, &X_T->data[0], &Y_T->data[0],
                     b_outputImage_, 2.0, true, &fillValues, &outputImage_->
                     data[0]);
  emxFree_real_T(&Y_T);
  emxFree_real_T(&X_T);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (interp2d.c) */
