/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imref2d.c
 *
 * Code generation for function 'imref2d'
 *
 */

/* Include files */
#include "imref2d.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo fq_emlrtRSI = { 354,/* lineNo */
  "imref2d/set.XWorldLimits",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pathName */
};

static emlrtRSInfo gq_emlrtRSI = { 376,/* lineNo */
  "imref2d/set.YWorldLimits",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pathName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 360,/* lineNo */
  17,                                  /* colNo */
  "imref2d/set.XWorldLimits",          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 382,/* lineNo */
  17,                                  /* colNo */
  "imref2d/set.YWorldLimits",          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pName */
};

/* Function Definitions */
void imref2d_set_XWorldLimits(const emlrtStack *sp,
  images_internal_coder_imref2d *obj, const real_T xLimWorld[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fq_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(xLimWorld[k])) && (!muDoubleScalarIsNaN
         (xLimWorld[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:imref2d:set:XworldLimits:expectedFinite", 3, 4, 12, "XWorldLimits");
  }

  if (xLimWorld[1] <= 0.5) {
    emlrtErrorWithMessageIdR2018a(sp, &bc_emlrtRTEI,
      "images:spatialref:expectedAscendingLimits",
      "images:spatialref:expectedAscendingLimits", 3, 4, 12, "XWorldLimits");
  }

  obj->XWorldLimits[0] = xLimWorld[0];
  obj->XWorldLimits[1] = xLimWorld[1];
  obj->ForcePixelExtentToOne = false;
}

void imref2d_set_YWorldLimits(const emlrtStack *sp,
  images_internal_coder_imref2d *obj, const real_T yLimWorld[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gq_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(yLimWorld[k])) && (!muDoubleScalarIsNaN
         (yLimWorld[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:imref2d:set:YworldLimits:expectedFinite", 3, 4, 12, "YWorldLimits");
  }

  if (yLimWorld[1] <= 0.5) {
    emlrtErrorWithMessageIdR2018a(sp, &cc_emlrtRTEI,
      "images:spatialref:expectedAscendingLimits",
      "images:spatialref:expectedAscendingLimits", 3, 4, 12, "YWorldLimits");
  }

  obj->YWorldLimits[0] = yLimWorld[0];
  obj->YWorldLimits[1] = yLimWorld[1];
  obj->ForcePixelExtentToOne = false;
}

/* End of code generation (imref2d.c) */
