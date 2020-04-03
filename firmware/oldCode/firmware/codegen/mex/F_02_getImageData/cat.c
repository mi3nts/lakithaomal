/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cat.c
 *
 * Code generation for function 'cat'
 *
 */

/* Include files */
#include "cat.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bq_emlrtRSI = { 65, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/cat.m"/* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 55,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/cat.m"/* pName */
};

static emlrtRTEInfo dl_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/cat.m"/* pName */
};

/* Function Definitions */
void cat(const emlrtStack *sp, const emxArray_real32_T *varargin_1, const
         emxArray_real32_T *varargin_2, const emxArray_real32_T *varargin_3,
         emxArray_real32_T *y)
{
  int32_T j;
  boolean_T exitg1;
  int32_T iy;
  int32_T b;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  j = y->size[0] * y->size[1] * y->size[2];
  y->size[0] = varargin_1->size[0];
  y->size[1] = varargin_1->size[1];
  y->size[2] = 3;
  emxEnsureCapacity_real32_T(sp, y, j, &dl_emlrtRTEI);
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if (y->size[j] != varargin_1->size[j]) {
      emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
        "Coder:MATLAB:catenate_dimensionMismatch",
        "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      j++;
    }
  }

  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if (y->size[j] != varargin_2->size[j]) {
      emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
        "Coder:MATLAB:catenate_dimensionMismatch",
        "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      j++;
    }
  }

  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if (y->size[j] != varargin_3->size[j]) {
      emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
        "Coder:MATLAB:catenate_dimensionMismatch",
        "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      j++;
    }
  }

  iy = -1;
  b = varargin_1->size[0] * varargin_1->size[1];
  st.site = &bq_emlrtRSI;
  overflow = ((1 <= b) && (b > 2147483646));
  if (overflow) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 0; j < b; j++) {
    iy++;
    y->data[iy] = varargin_1->data[j];
  }

  b = varargin_2->size[0] * varargin_2->size[1];
  st.site = &bq_emlrtRSI;
  overflow = ((1 <= b) && (b > 2147483646));
  if (overflow) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 0; j < b; j++) {
    iy++;
    y->data[iy] = varargin_2->data[j];
  }

  b = varargin_3->size[0] * varargin_3->size[1];
  st.site = &bq_emlrtRSI;
  overflow = ((1 <= b) && (b > 2147483646));
  if (overflow) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 0; j < b; j++) {
    iy++;
    y->data[iy] = varargin_3->data[j];
  }
}

/* End of code generation (cat.c) */
