/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rgb2gray.c
 *
 * Code generation for function 'rgb2gray'
 *
 */

/* Include files */
#include "rgb2gray.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "libmwrgb2gray_tbb.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo qj_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "rgb2gray",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/images/rgb2gray.m"/* pName */
};

/* Function Definitions */
void rgb2gray(const emlrtStack *sp, const emxArray_uint8_T *X, emxArray_uint8_T *
              b_I)
{
  int32_T i;
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = X->size[0];
  b_I->size[1] = X->size[1];
  emxEnsureCapacity_uint8_T(sp, b_I, i, &qj_emlrtRTEI);
  rgb2gray_tbb_uint8(&X->data[0], (real_T)X->size[0] * (real_T)X->size[1],
                     &b_I->data[0], true);
}

/* End of code generation (rgb2gray.c) */
