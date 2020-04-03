/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkImageSize.c
 *
 * Code generation for function 'checkImageSize'
 *
 */

/* Include files */
#include "checkImageSize.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo p_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "checkImageSize",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/checkImageSize.m"/* pName */
};

/* Function Definitions */
void checkImageSize(const emlrtStack *sp, const real_T expectedImageSize[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T b_p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(160.0 * (real_T)k + 480.0 == expectedImageSize[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  b_p = (int32_T)p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI,
      "vision:calibrate:inconsistentImageSize",
      "vision:calibrate:inconsistentImageSize", 0);
  }
}

/* End of code generation (checkImageSize.c) */
