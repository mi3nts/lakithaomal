/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "bsxfun.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo vb_emlrtRTEI = { 51,/* lineNo */
  15,                                  /* colNo */
  "bsxfun",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/bsxfun.m"/* pName */
};

static emlrtRTEInfo cl_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "bsxfun",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/bsxfun.m"/* pName */
};

/* Function Definitions */
void bsxfun(const emlrtStack *sp, const emxArray_real32_T *a, const
            emxArray_real32_T *b, emxArray_real32_T *c)
{
  int32_T csz_idx_0;
  int32_T i;
  int32_T bcoef;
  int32_T k;
  int32_T b_k;
  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else if (a->size[0] == b->size[0]) {
    csz_idx_0 = a->size[0];
  } else {
    emlrtErrorWithMessageIdR2018a(sp, &vb_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch",
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  i = c->size[0] * c->size[1];
  c->size[0] = csz_idx_0;
  c->size[1] = 3;
  emxEnsureCapacity_real32_T(sp, c, i, &cl_emlrtRTEI);
  if (csz_idx_0 != 0) {
    csz_idx_0 = (a->size[0] != 1);
    bcoef = (b->size[0] != 1);
    for (k = 0; k < 3; k++) {
      i = c->size[0] - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        c->data[b_k + c->size[0] * k] = a->data[csz_idx_0 * b_k + a->size[0] * k]
          * b->data[bcoef * b_k];
      }
    }
  }
}

/* End of code generation (bsxfun.c) */
