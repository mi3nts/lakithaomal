/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.c
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "xdotc.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo sg_emlrtRSI = { 32, /* lineNo */
  "xdotc",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/xdotc.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 35, /* lineNo */
  "xdot",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/xdot.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 15, /* lineNo */
  "xdot",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+refblas/xdot.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 42, /* lineNo */
  "xdotx",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+refblas/xdotx.m"/* pathName */
};

/* Function Definitions */
real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
             const real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  ix = ix0;
  iy = iy0;
  b_st.site = &tg_emlrtRSI;
  c_st.site = &ug_emlrtRSI;
  d = 0.0;
  d_st.site = &vg_emlrtRSI;
  overflow = ((1 <= n) && (n > 2147483646));
  if (overflow) {
    e_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* End of code generation (xdotc.c) */
