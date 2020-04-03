/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "sortIdx.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo am_emlrtRSI = { 561,/* lineNo */
  "merge",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

static emlrtRSInfo bm_emlrtRSI = { 530,/* lineNo */
  "merge",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/sortIdx.m"/* pathName */
};

/* Function Definitions */
void merge(const emlrtStack *sp, int32_T idx[8], real_T x[8], int32_T offset,
           int32_T np, int32_T nq, int32_T iwork[8], real_T xwork[8])
{
  int32_T n_tmp;
  boolean_T overflow;
  int32_T iout;
  int32_T p;
  int32_T i;
  int32_T q;
  int32_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    n_tmp = np + nq;
    st.site = &bm_emlrtRSI;
    overflow = ((1 <= n_tmp) && (n_tmp > 2147483646));
    if (overflow) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (iout = 0; iout < n_tmp; iout++) {
      i = offset + iout;
      iwork[iout] = idx[i];
      xwork[iout] = x[i];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          st.site = &am_emlrtRSI;
          overflow = ((p + 1 <= np) && (np > 2147483646));
          if (overflow) {
            b_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          for (iout = p + 1; iout <= np; iout++) {
            i = q + iout;
            idx[i] = iwork[iout - 1];
            x[i] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (sortIdx.c) */
