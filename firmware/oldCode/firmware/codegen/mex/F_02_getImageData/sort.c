/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pl_emlrtRSI = { 72, /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sort.m"/* pathName */
};

static emlrtRSInfo ql_emlrtRSI = { 105,/* lineNo */
  "sortIdx",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo rl_emlrtRSI = { 308,/* lineNo */
  "block_merge_sort",                  /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo sl_emlrtRSI = { 333,/* lineNo */
  "block_merge_sort",                  /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo tl_emlrtRSI = { 420,/* lineNo */
  "initialize_vector_sort",            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo ul_emlrtRSI = { 427,/* lineNo */
  "initialize_vector_sort",            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo vl_emlrtRSI = { 499,/* lineNo */
  "merge_block",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo wl_emlrtRSI = { 506,/* lineNo */
  "merge_block",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo xl_emlrtRSI = { 507,/* lineNo */
  "merge_block",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo yl_emlrtRSI = { 514,/* lineNo */
  "merge_block",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

/* Function Definitions */
void b_sort(const emlrtStack *sp, real_T x[8])
{
  int32_T i;
  int32_T idx[8];
  real_T x4[4];
  int8_T idx4[4];
  real_T xwork[8];
  int32_T nNaNs;
  int32_T k;
  int8_T perm[4];
  int32_T quartetOffset;
  int32_T i3;
  int32_T i2;
  int32_T i4;
  int32_T iwork[8];
  real_T d;
  real_T d1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pl_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  for (i = 0; i < 8; i++) {
    idx[i] = 0;
  }

  b_st.site = &ql_emlrtRSI;
  c_st.site = &rl_emlrtRSI;
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  memset(&xwork[0], 0, 8U * sizeof(real_T));
  nNaNs = 0;
  i = 0;
  for (k = 0; k < 8; k++) {
    if (muDoubleScalarIsNaN(x[k])) {
      idx[7 - nNaNs] = k + 1;
      xwork[7 - nNaNs] = x[k];
      nNaNs++;
    } else {
      i++;
      idx4[i - 1] = (int8_T)(k + 1);
      x4[i - 1] = x[k];
      if (i == 4) {
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i = 1;
          i2 = 2;
        } else {
          i = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        d = x4[i - 1];
        d1 = x4[i3 - 1];
        if (d <= d1) {
          d = x4[i2 - 1];
          if (d <= d1) {
            perm[0] = (int8_T)i;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (d <= x4[i4 - 1]) {
            perm[0] = (int8_T)i;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          d1 = x4[i4 - 1];
          if (d <= d1) {
            if (x4[i2 - 1] <= d1) {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)i3;
              perm[1] = (int8_T)i;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i;
            perm[3] = (int8_T)i2;
          }
        }

        i3 = perm[0] - 1;
        idx[quartetOffset - 3] = idx4[i3];
        i4 = perm[1] - 1;
        idx[quartetOffset - 2] = idx4[i4];
        i = perm[2] - 1;
        idx[quartetOffset - 1] = idx4[i];
        i2 = perm[3] - 1;
        idx[quartetOffset] = idx4[i2];
        x[quartetOffset - 3] = x4[i3];
        x[quartetOffset - 2] = x4[i4];
        x[quartetOffset - 1] = x4[i];
        x[quartetOffset] = x4[i2];
        i = 0;
      }
    }
  }

  if (i > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (i == 1) {
      perm[0] = 1;
    } else if (i == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &tl_emlrtRSI;
    if (i > 2147483646) {
      e_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 0; k < i; k++) {
      i3 = perm[k] - 1;
      i4 = ((k - nNaNs) - i) + 8;
      idx[i4] = idx4[i3];
      x[i4] = x4[i3];
    }
  }

  i = (nNaNs >> 1) + 8;
  d_st.site = &ul_emlrtRSI;
  for (k = 0; k <= i - 9; k++) {
    i3 = (k - nNaNs) + 8;
    i2 = idx[i3];
    idx[i3] = idx[7 - k];
    idx[7 - k] = i2;
    x[i3] = xwork[7 - k];
    x[7 - k] = xwork[i3];
  }

  if ((nNaNs & 1) != 0) {
    i -= nNaNs;
    x[i] = xwork[i];
  }

  if (8 - nNaNs > 1) {
    c_st.site = &sl_emlrtRSI;
    for (i = 0; i < 8; i++) {
      iwork[i] = 0;
    }

    i4 = (8 - nNaNs) >> 2;
    i2 = 4;
    while (i4 > 1) {
      if ((i4 & 1) != 0) {
        i4--;
        i = i2 * i4;
        i3 = 8 - (nNaNs + i);
        if (i3 > i2) {
          d_st.site = &vl_emlrtRSI;
          merge(&d_st, idx, x, i, i2, i3 - i2, iwork, xwork);
        }
      }

      i = i2 << 1;
      i4 >>= 1;
      d_st.site = &wl_emlrtRSI;
      for (k = 0; k < i4; k++) {
        d_st.site = &xl_emlrtRSI;
        merge(&d_st, idx, x, k * i, i2, i2, iwork, xwork);
      }

      i2 = i;
    }

    if (8 - nNaNs > i2) {
      d_st.site = &yl_emlrtRSI;
      merge(&d_st, idx, x, 0, i2, 8 - (nNaNs + i2), iwork, xwork);
    }
  }
}

void sort(real_T x[2])
{
  real_T tmp;
  if ((!(x[0] <= x[1])) && (!muDoubleScalarIsNaN(x[1]))) {
    tmp = x[0];
    x[0] = x[1];
    x[1] = tmp;
  }
}

/* End of code generation (sort.c) */
