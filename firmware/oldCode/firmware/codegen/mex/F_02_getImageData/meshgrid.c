/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meshgrid.c
 *
 * Code generation for function 'meshgrid'
 *
 */

/* Include files */
#include "meshgrid.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo he_emlrtRSI = { 31, /* lineNo */
  "meshgrid",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pathName */
};

static emlrtRSInfo ie_emlrtRSI = { 32, /* lineNo */
  "meshgrid",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pathName */
};

static emlrtRTEInfo yd_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "meshgrid",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/meshgrid.m"/* pName */
};

/* Function Definitions */
void b_meshgrid(const real_T x[640], const real_T y[480], real_T xx[307200],
                real_T yy[307200])
{
  int32_T j;
  int32_T i;
  int32_T xx_tmp;
  for (j = 0; j < 640; j++) {
    memcpy(&yy[j * 480], &y[0], 480U * sizeof(real_T));
    for (i = 0; i < 480; i++) {
      xx_tmp = i + 480 * j;
      xx[xx_tmp] = x[j];
    }
  }
}

void c_meshgrid(const emlrtStack *sp, const emxArray_real32_T *x, const
                emxArray_real32_T *y, emxArray_real32_T *xx, emxArray_real32_T
                *yy)
{
  int32_T nx;
  int32_T ny;
  int32_T j;
  boolean_T overflow;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nx = x->size[1];
  ny = y->size[1];
  j = xx->size[0] * xx->size[1];
  xx->size[0] = y->size[1];
  xx->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(sp, xx, j, &yd_emlrtRTEI);
  j = yy->size[0] * yy->size[1];
  yy->size[0] = y->size[1];
  yy->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(sp, yy, j, &yd_emlrtRTEI);
  if ((x->size[1] != 0) && (y->size[1] != 0)) {
    st.site = &he_emlrtRSI;
    if (x->size[1] > 2147483646) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    if (0 <= x->size[1] - 1) {
      overflow = ((1 <= y->size[1]) && (y->size[1] > 2147483646));
    }

    for (j = 0; j < nx; j++) {
      st.site = &ie_emlrtRSI;
      if (overflow) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i < ny; i++) {
        xx->data[i + xx->size[0] * j] = x->data[j];
        yy->data[i + yy->size[0] * j] = y->data[i];
      }
    }
  }
}

void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const
              emxArray_real_T *y, emxArray_real_T *xx, emxArray_real_T *yy)
{
  int32_T nx;
  int32_T ny;
  int32_T j;
  boolean_T overflow;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nx = x->size[1];
  ny = y->size[1];
  j = xx->size[0] * xx->size[1];
  xx->size[0] = y->size[1];
  xx->size[1] = x->size[1];
  emxEnsureCapacity_real_T(sp, xx, j, &yd_emlrtRTEI);
  j = yy->size[0] * yy->size[1];
  yy->size[0] = y->size[1];
  yy->size[1] = x->size[1];
  emxEnsureCapacity_real_T(sp, yy, j, &yd_emlrtRTEI);
  if ((x->size[1] != 0) && (y->size[1] != 0)) {
    st.site = &he_emlrtRSI;
    if (x->size[1] > 2147483646) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    if (0 <= x->size[1] - 1) {
      overflow = ((1 <= y->size[1]) && (y->size[1] > 2147483646));
    }

    for (j = 0; j < nx; j++) {
      st.site = &ie_emlrtRSI;
      if (overflow) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (i = 0; i < ny; i++) {
        xx->data[i + xx->size[0] * j] = x->data[j];
        yy->data[i + yy->size[0] * j] = y->data[i];
      }
    }
  }
}

/* End of code generation (meshgrid.c) */
