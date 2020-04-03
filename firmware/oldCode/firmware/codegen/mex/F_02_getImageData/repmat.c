/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo to_emlrtRSI = { 71, /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRTEInfo pj_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *b)
{
  int32_T nrows;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nrows = b->size[0] * b->size[1];
  b->size[0] = a->size[0];
  b->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b, nrows, &pj_emlrtRTEI);
  nrows = a->size[0];
  overflow = ((1 <= a->size[0]) && (a->size[0] > 2147483646));
  st.site = &to_emlrtRSI;
  if (overflow) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (k = 0; k < nrows; k++) {
    b->data[k] = a->data[k];
  }

  st.site = &to_emlrtRSI;
  for (k = 0; k < nrows; k++) {
    b->data[nrows + k] = a->data[k];
  }
}

/* End of code generation (repmat.c) */
