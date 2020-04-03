/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ImageTransformer.c
 *
 * Code generation for function 'ImageTransformer'
 *
 */

/* Include files */
#include "ImageTransformer.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "distortPoints.h"
#include "inv.h"
#include "meshgrid.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "repmat.h"
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"
#include "scalexpCompatible.h"
#include "strcmp.h"

/* Variable Definitions */
static emlrtRSInfo ud_emlrtRSI = { 125,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 126,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 127,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 137,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 157,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 158,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 160,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 162,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo go_emlrtRSI = { 130,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo ho_emlrtRSI = { 228,/* lineNo */
  "projective2d/transformPointsInverse",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo io_emlrtRSI = { 230,/* lineNo */
  "projective2d/transformPointsInverse",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo jo_emlrtRSI = { 240,/* lineNo */
  "projective2d/transformPointsInverse",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo ko_emlrtRSI = { 27, /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo qo_emlrtRSI = { 56, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 141, /* lineNo */
  13,                                  /* colNo */
  "ImageTransformer/computeMap",       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 57,/* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"/* pName */
};

static emlrtECInfo u_emlrtECI = { -1,  /* nDims */
  240,                                 /* lineNo */
  25,                                  /* colNo */
  "projective2d/transformPointsInverse",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 158,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 153,/* lineNo */
  23,                                  /* colNo */
  "dynamic_size_checks",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = { 156,/* lineNo */
  23,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 160,/* lineNo */
  48,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 157,/* lineNo */
  37,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = { 160,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo od_emlrtRTEI = { 157,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = { 162,/* lineNo */
  48,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = { 158,/* lineNo */
  37,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = { 162,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = { 158,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo td_emlrtRTEI = { 134,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = { 123,/* lineNo */
  18,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = { 125,/* lineNo */
  31,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = { 126,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo gj_emlrtRTEI = { 127,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo hj_emlrtRTEI = { 228,/* lineNo */
  17,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo ij_emlrtRTEI = { 230,/* lineNo */
  17,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo jj_emlrtRTEI = { 240,/* lineNo */
  53,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo kj_emlrtRTEI = { 240,/* lineNo */
  36,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo lj_emlrtRTEI = { 130,/* lineNo */
  17,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo mj_emlrtRTEI = { 219,/* lineNo */
  17,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo pl_emlrtRTEI = { 45,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo ql_emlrtRTEI = { 46,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo rl_emlrtRTEI = { 47,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo sl_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo tl_emlrtRTEI = { 49,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo ul_emlrtRTEI = { 50,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo vl_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo wl_emlrtRTEI = { 53,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo xl_emlrtRTEI = { 55,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static emlrtRTEInfo yl_emlrtRTEI = { 56,/* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

static const char_T cv1[11] = { 'c', 'l', 'e', 'a', 'r', ' ', 'p', 't', 's', 'I',
  'n' };

static emlrtRSInfo wq_emlrtRSI = { 141,/* lineNo */
  "ImageTransformer/computeMap",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [11]);
static void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *a,
  int32_T innerDimA);
static void eval(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [11])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 11 };

  y = NULL;
  m = emlrtCreateCharArray(2, iv);
  emlrtInitCharArrayR2013a(sp, 11, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void dynamic_size_checks(const emlrtStack *sp, const emxArray_real_T *a,
  int32_T innerDimA)
{
  if (innerDimA != 3) {
    if ((a->size[0] == 1) && (a->size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(sp, &qb_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion",
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(sp, &pb_emlrtRTEI, "MATLAB:innerdim",
        "MATLAB:innerdim", 0);
    }
  }
}

static void eval(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "eval", true, location);
}

void ImageTransformer_computeMap(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2])
{
  emxArray_real_T *y;
  real_T m;
  real_T n;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *b_y;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *b_X;
  int32_T maxdimlen;
  emxArray_real_T *ptsOut;
  emxArray_char_T *a;
  const mxArray *c_y;
  const mxArray *b_m;
  static const int32_T iv[2] = { 1, 11 };

  boolean_T b_bool;
  emxArray_real_T *b_ptsOut;
  int32_T exitg1;
  static const char_T b_cv[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  real_T varargin_1_tmp[2];
  int32_T num_idx_0_tmp;
  int32_T num_idx_1_tmp;
  int32_T loop_ub_tmp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &y, 2, &vd_emlrtRTEI, true);
  st.site = &ud_emlrtRSI;
  m = this->XBounds[0];
  n = this->XBounds[1];
  b_st.site = &de_emlrtRSI;
  if (muDoubleScalarIsNaN(m) || muDoubleScalarIsNaN(n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    y->data[0] = rtNaN;
  } else if (n < m) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if ((muDoubleScalarIsInf(m) || muDoubleScalarIsInf(n)) && (m == n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    y->data[0] = rtNaN;
  } else if (muDoubleScalarFloor(m) == m) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(n - m);
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = m + (real_T)i;
    }
  } else {
    c_st.site = &ee_emlrtRSI;
    eml_float_colon(&c_st, m, n, y);
  }

  emxInit_real_T(&b_st, &b_y, 2, &wd_emlrtRTEI, true);
  st.site = &vd_emlrtRSI;
  m = this->YBounds[0];
  n = this->YBounds[1];
  b_st.site = &de_emlrtRSI;
  if (muDoubleScalarIsNaN(m) || muDoubleScalarIsNaN(n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    b_y->data[0] = rtNaN;
  } else if (n < m) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if ((muDoubleScalarIsInf(m) || muDoubleScalarIsInf(n)) && (m == n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    b_y->data[0] = rtNaN;
  } else if (muDoubleScalarFloor(m) == m) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(n - m);
    b_y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = m + (real_T)i;
    }
  } else {
    c_st.site = &ee_emlrtRSI;
    eml_float_colon(&c_st, m, n, b_y);
  }

  emxInit_real_T(&b_st, &X, 2, &ud_emlrtRTEI, true);
  emxInit_real_T(&b_st, &Y, 2, &ud_emlrtRTEI, true);
  st.site = &ud_emlrtRSI;
  meshgrid(&st, y, b_y, X, Y);
  st.site = &wd_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  c_st.site = &ke_emlrtRSI;
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  if (Y->size[0] * Y->size[1] != X->size[0] * X->size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &b_X, 2, &jd_emlrtRTEI, true);
  maxdimlen = X->size[0] * X->size[1];
  loop_ub = Y->size[0] * Y->size[1];
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = maxdimlen;
  b_X->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_X, i, &jd_emlrtRTEI);
  for (i = 0; i < maxdimlen; i++) {
    b_X->data[i] = X->data[i];
  }

  emxFree_real_T(&X);
  for (i = 0; i < loop_ub; i++) {
    b_X->data[i + b_X->size[0]] = Y->data[i];
  }

  emxFree_real_T(&Y);
  emxInit_real_T(sp, &ptsOut, 2, &td_emlrtRTEI, true);
  emxInit_char_T(sp, &a, 2, &kd_emlrtRTEI, true);
  st.site = &xd_emlrtRSI;
  distortPoints(&st, b_X, intrinsicMatrix, radialDist, tangentialDist, ptsOut);
  c_y = NULL;
  b_m = emlrtCreateCharArray(2, iv);
  emlrtInitCharArrayR2013a(sp, 11, b_m, &cv1[0]);
  emlrtAssign(&c_y, b_m);
  st.site = &wq_emlrtRSI;
  eval(&st, c_y, &c_emlrtMCI);
  m = (this->YBounds[1] - this->YBounds[0]) + 1.0;
  n = (this->XBounds[1] - this->XBounds[0]) + 1.0;
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = this->ClassOfImage->size[1];
  emxEnsureCapacity_char_T(sp, a, i, &kd_emlrtRTEI);
  loop_ub = this->ClassOfImage->size[0] * this->ClassOfImage->size[1];
  emxFree_real_T(&b_X);
  for (i = 0; i < loop_ub; i++) {
    a->data[i] = this->ClassOfImage->data[i];
  }

  b_bool = false;
  if (a->size[1] == 6) {
    maxdimlen = 0;
    do {
      exitg1 = 0;
      if (maxdimlen < 6) {
        if (a->data[maxdimlen] != b_cv[maxdimlen]) {
          exitg1 = 1;
        } else {
          maxdimlen++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emxFree_char_T(&a);
  emxInit_real_T(sp, &b_ptsOut, 1, &ld_emlrtRTEI, true);
  if (b_bool) {
    st.site = &yd_emlrtRSI;
    varargin_1_tmp[0] = m;
    varargin_1_tmp[1] = n;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    num_idx_0_tmp = (int32_T)m;
    num_idx_1_tmp = (int32_T)n;
    maxdimlen = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      maxdimlen = 1;
    }

    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (num_idx_0_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (num_idx_1_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if ((num_idx_0_tmp < 0) || (num_idx_1_tmp < 0)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    loop_ub_tmp = num_idx_0_tmp * num_idx_1_tmp;
    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_ptsOut, i, &md_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i];
    }

    i = this->Xmap->size[0] * this->Xmap->size[1];
    this->Xmap->size[0] = num_idx_0_tmp;
    this->Xmap->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real_T(sp, this->Xmap, i, &od_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->Xmap->data[i] = b_ptsOut->data[i];
    }

    st.site = &ae_emlrtRSI;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    maxdimlen = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      maxdimlen = 1;
    }

    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (num_idx_0_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (num_idx_1_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if ((num_idx_0_tmp < 0) || (num_idx_1_tmp < 0)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_ptsOut, i, &qd_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = this->Ymap->size[0] * this->Ymap->size[1];
    this->Ymap->size[0] = num_idx_0_tmp;
    this->Ymap->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real_T(sp, this->Ymap, i, &sd_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->Ymap->data[i] = b_ptsOut->data[i];
    }
  } else {
    st.site = &be_emlrtRSI;
    varargin_1_tmp[0] = m;
    varargin_1_tmp[1] = n;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    num_idx_0_tmp = (int32_T)m;
    num_idx_1_tmp = (int32_T)n;
    maxdimlen = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      maxdimlen = 1;
    }

    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (num_idx_0_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (num_idx_1_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if ((num_idx_0_tmp < 0) || (num_idx_1_tmp < 0)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    loop_ub_tmp = num_idx_0_tmp * num_idx_1_tmp;
    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_ptsOut, i, &ld_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i];
    }

    i = this->XmapSingle->size[0] * this->XmapSingle->size[1];
    this->XmapSingle->size[0] = num_idx_0_tmp;
    this->XmapSingle->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real32_T(sp, this->XmapSingle, i, &nd_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->XmapSingle->data[i] = (real32_T)b_ptsOut->data[i];
    }

    st.site = &ce_emlrtRSI;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    maxdimlen = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      maxdimlen = 1;
    }

    maxdimlen = muIntScalarMax_sint32(i, maxdimlen);
    if (num_idx_0_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (num_idx_1_tmp > maxdimlen) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if ((num_idx_0_tmp < 0) || (num_idx_1_tmp < 0)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_ptsOut, i, &pd_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = this->YmapSingle->size[0] * this->YmapSingle->size[1];
    this->YmapSingle->size[0] = num_idx_0_tmp;
    this->YmapSingle->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real32_T(sp, this->YmapSingle, i, &rd_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->YmapSingle->data[i] = (real32_T)b_ptsOut->data[i];
    }
  }

  emxFree_real_T(&b_ptsOut);
  emxFree_real_T(&ptsOut);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

boolean_T ImageTransformer_needToUpdate(const emlrtStack *sp, const
  c_vision_internal_calibration_I *this)
{
  boolean_T tf;
  emxArray_real_T *varargin_1;
  int32_T k;
  int32_T loop_ub;
  boolean_T p;
  boolean_T exitg1;
  boolean_T sameSize;
  emxArray_char_T *b;
  static const int16_T iv[3] = { 480, 640, 3 };

  boolean_T sameClass;
  int32_T exitg2;
  static const char_T b_cv[5] = { 'u', 'i', 'n', 't', '8' };

  boolean_T sameOutputView;
  static const char_T b_cv1[5] = { 'v', 'a', 'l', 'i', 'd' };

  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &varargin_1, 2, &bd_emlrtRTEI, true);
  k = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = this->SizeOfImage->size[1];
  emxEnsureCapacity_real_T(sp, varargin_1, k, &bd_emlrtRTEI);
  loop_ub = this->SizeOfImage->size[0] * this->SizeOfImage->size[1];
  for (k = 0; k < loop_ub; k++) {
    varargin_1->data[k] = this->SizeOfImage->data[k];
  }

  p = (varargin_1->size[1] == 3);
  if (p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == iv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  emxFree_real_T(&varargin_1);
  sameSize = (int32_T)p;
  emxInit_char_T(sp, &b, 2, &cd_emlrtRTEI, true);
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = this->ClassOfImage->size[1];
  emxEnsureCapacity_char_T(sp, b, k, &cd_emlrtRTEI);
  loop_ub = this->ClassOfImage->size[0] * this->ClassOfImage->size[1];
  for (k = 0; k < loop_ub; k++) {
    b->data[k] = this->ClassOfImage->data[k];
  }

  sameClass = false;
  if (5 == b->size[1]) {
    k = 0;
    do {
      exitg2 = 0;
      if (k < 5) {
        if (b_cv[k] != b->data[k]) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        sameClass = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = this->OutputView->size[1];
  emxEnsureCapacity_char_T(sp, b, k, &dd_emlrtRTEI);
  loop_ub = this->OutputView->size[0] * this->OutputView->size[1];
  for (k = 0; k < loop_ub; k++) {
    b->data[k] = this->OutputView->data[k];
  }

  p = (b->size[1] == 5);
  if (p && (b->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(b->data[k] == b_cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  emxFree_char_T(&b);
  sameOutputView = (int32_T)p;
  if (sameSize && sameClass && sameOutputView) {
    sameSize = true;
  } else {
    sameSize = false;
  }

  tf = !sameSize;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return tf;
}

void ImageTransformer_update(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2], const real_T xBounds[2],
  const real_T yBounds[2])
{
  int32_T i;
  static const char_T b_cv[5] = { 'u', 'i', 'n', 't', '8' };

  static const char_T outputView[5] = { 'v', 'a', 'l', 'i', 'd' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i = this->SizeOfImage->size[0] * this->SizeOfImage->size[1];
  this->SizeOfImage->size[0] = 1;
  this->SizeOfImage->size[1] = 2;
  emxEnsureCapacity_real_T(sp, this->SizeOfImage, i, &ed_emlrtRTEI);
  this->SizeOfImage->data[0] = 480.0;
  this->SizeOfImage->data[1] = 640.0;
  i = this->ClassOfImage->size[0] * this->ClassOfImage->size[1];
  this->ClassOfImage->size[0] = 1;
  this->ClassOfImage->size[1] = 5;
  emxEnsureCapacity_char_T(sp, this->ClassOfImage, i, &fd_emlrtRTEI);
  i = this->OutputView->size[0] * this->OutputView->size[1];
  this->OutputView->size[0] = 1;
  this->OutputView->size[1] = 5;
  emxEnsureCapacity_char_T(sp, this->OutputView, i, &gd_emlrtRTEI);
  for (i = 0; i < 5; i++) {
    this->ClassOfImage->data[i] = b_cv[i];
    this->OutputView->data[i] = outputView[i];
  }

  this->XBounds[0] = xBounds[0];
  this->YBounds[0] = yBounds[0];
  this->XBounds[1] = xBounds[1];
  this->YBounds[1] = yBounds[1];
  st.site = &td_emlrtRSI;
  ImageTransformer_computeMap(&st, this, intrinsicMatrix, radialDist,
    tangentialDist);
}

void b_ImageTransformer_computeMap(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2], const real_T H_T[9])
{
  emxArray_real_T *y;
  real_T m;
  real_T n;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *b_y;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *ptsIn;
  int32_T input_sizes_idx_1;
  int32_T Y_idx_0;
  boolean_T empty_non_axis_sizes;
  int8_T sizes_idx_1;
  emxArray_real_T *b_X;
  int32_T input_sizes_idx_0_tmp;
  real_T Tinv[9];
  emxArray_real_T *U;
  emxArray_real_T *ptsOut;
  emxArray_real_T *b_U;
  real_T varargin_1_tmp[2];
  int32_T input_sizes_idx_1_tmp;
  int32_T loop_ub_tmp;
  int32_T result[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &y, 2, &vd_emlrtRTEI, true);
  st.site = &ud_emlrtRSI;
  m = this->XBounds[0];
  n = this->XBounds[1];
  b_st.site = &de_emlrtRSI;
  if (muDoubleScalarIsNaN(m) || muDoubleScalarIsNaN(n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    y->data[0] = rtNaN;
  } else if (n < m) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if ((muDoubleScalarIsInf(m) || muDoubleScalarIsInf(n)) && (m == n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    y->data[0] = rtNaN;
  } else if (muDoubleScalarFloor(m) == m) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(n - m);
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = m + (real_T)i;
    }
  } else {
    c_st.site = &ee_emlrtRSI;
    eml_float_colon(&c_st, m, n, y);
  }

  emxInit_real_T(&b_st, &b_y, 2, &wd_emlrtRTEI, true);
  st.site = &vd_emlrtRSI;
  m = this->YBounds[0];
  n = this->YBounds[1];
  b_st.site = &de_emlrtRSI;
  if (muDoubleScalarIsNaN(m) || muDoubleScalarIsNaN(n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    b_y->data[0] = rtNaN;
  } else if (n < m) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if ((muDoubleScalarIsInf(m) || muDoubleScalarIsInf(n)) && (m == n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    b_y->data[0] = rtNaN;
  } else if (muDoubleScalarFloor(m) == m) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = (int32_T)muDoubleScalarFloor(n - m);
    b_y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = m + (real_T)i;
    }
  } else {
    c_st.site = &ee_emlrtRSI;
    eml_float_colon(&c_st, m, n, b_y);
  }

  emxInit_real_T(&b_st, &X, 2, &ud_emlrtRTEI, true);
  emxInit_real_T(&b_st, &Y, 2, &ud_emlrtRTEI, true);
  st.site = &ud_emlrtRSI;
  meshgrid(&st, y, b_y, X, Y);
  st.site = &wd_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  c_st.site = &ke_emlrtRSI;
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  if (Y->size[0] * Y->size[1] != X->size[0] * X->size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &ptsIn, 2, &gj_emlrtRTEI, true);
  input_sizes_idx_1 = X->size[0] * X->size[1];
  Y_idx_0 = Y->size[0] * Y->size[1];
  i = ptsIn->size[0] * ptsIn->size[1];
  ptsIn->size[0] = input_sizes_idx_1;
  ptsIn->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, ptsIn, i, &gj_emlrtRTEI);
  for (i = 0; i < input_sizes_idx_1; i++) {
    ptsIn->data[i] = X->data[i];
  }

  emxFree_real_T(&X);
  for (i = 0; i < Y_idx_0; i++) {
    ptsIn->data[i + ptsIn->size[0]] = Y->data[i];
  }

  emxFree_real_T(&Y);
  st.site = &go_emlrtRSI;
  b_st.site = &ho_emlrtRSI;
  c_st.site = &ko_emlrtRSI;
  if (ptsIn->size[0] != 0) {
    Y_idx_0 = ptsIn->size[0];
  } else {
    Y_idx_0 = 0;
  }

  d_st.site = &ke_emlrtRSI;
  if ((ptsIn->size[0] != Y_idx_0) && (ptsIn->size[0] != 0)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((ptsIn->size[0] != Y_idx_0) && (ptsIn->size[0] != 0)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if (Y_idx_0 == 0) {
    empty_non_axis_sizes = true;
    input_sizes_idx_1 = 2;
  } else {
    empty_non_axis_sizes = false;
    if (ptsIn->size[0] != 0) {
      input_sizes_idx_1 = 2;
    } else {
      input_sizes_idx_1 = 0;
    }
  }

  if (empty_non_axis_sizes || (ptsIn->size[0] != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }

  emxInit_real_T(&c_st, &b_X, 2, &mj_emlrtRTEI, true);
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = Y_idx_0;
  b_X->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_real_T(&c_st, b_X, i, &hj_emlrtRTEI);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (input_sizes_idx_0_tmp = 0; input_sizes_idx_0_tmp < Y_idx_0;
         input_sizes_idx_0_tmp++) {
      b_X->data[input_sizes_idx_0_tmp + b_X->size[0] * i] = ptsIn->
        data[input_sizes_idx_0_tmp + ptsIn->size[0] * i];
    }
  }

  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (input_sizes_idx_0_tmp = 0; input_sizes_idx_0_tmp < Y_idx_0;
         input_sizes_idx_0_tmp++) {
      b_X->data[input_sizes_idx_0_tmp + b_X->size[0] * input_sizes_idx_1] = 1.0;
    }
  }

  b_st.site = &io_emlrtRSI;
  c_st.site = &lo_emlrtRSI;
  inv(&c_st, H_T, Tinv);
  b_st.site = &io_emlrtRSI;
  c_st.site = &qo_emlrtRSI;
  dynamic_size_checks(&c_st, b_X, b_X->size[1]);
  emxInit_real_T(&b_st, &U, 2, &ij_emlrtRTEI, true);
  if (b_X->size[1] == 1) {
    i = U->size[0] * U->size[1];
    U->size[0] = b_X->size[0];
    U->size[1] = 3;
    emxEnsureCapacity_real_T(&b_st, U, i, &ij_emlrtRTEI);
    loop_ub = b_X->size[0];
    for (i = 0; i < loop_ub; i++) {
      Y_idx_0 = b_X->size[1];
      for (input_sizes_idx_0_tmp = 0; input_sizes_idx_0_tmp < 3;
           input_sizes_idx_0_tmp++) {
        U->data[i + U->size[0] * input_sizes_idx_0_tmp] = 0.0;
        for (input_sizes_idx_1 = 0; input_sizes_idx_1 < Y_idx_0;
             input_sizes_idx_1++) {
          U->data[i + U->size[0] * input_sizes_idx_0_tmp] += b_X->data[i +
            b_X->size[0] * input_sizes_idx_1] * Tinv[input_sizes_idx_1 + 3 *
            input_sizes_idx_0_tmp];
        }
      }
    }
  } else {
    c_st.site = &po_emlrtRSI;
    mtimes(&c_st, b_X, Tinv, U);
  }

  emxFree_real_T(&b_X);
  emxInit_real_T(&st, &ptsOut, 2, &td_emlrtRTEI, true);
  emxInit_real_T(&st, &b_U, 1, &jj_emlrtRTEI, true);
  if (U->size[0] == 0) {
    ptsIn->size[0] = 0;
    ptsIn->size[1] = 2;
  } else {
    b_st.site = &jo_emlrtRSI;
    loop_ub = U->size[0];
    i = b_U->size[0];
    b_U->size[0] = U->size[0];
    emxEnsureCapacity_real_T(&b_st, b_U, i, &jj_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_U->data[i] = U->data[i + U->size[0] * 2];
    }

    c_st.site = &jo_emlrtRSI;
    repmat(&c_st, b_U, ptsIn);
    loop_ub = U->size[0];
    i = ptsOut->size[0] * ptsOut->size[1];
    ptsOut->size[0] = U->size[0];
    ptsOut->size[1] = 2;
    emxEnsureCapacity_real_T(&b_st, ptsOut, i, &kj_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      ptsOut->data[i] = U->data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      ptsOut->data[i + ptsOut->size[0]] = U->data[i + U->size[0]];
    }

    if (!scalexpCompatible(ptsOut, ptsIn)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ob_emlrtRTEI, "MATLAB:dimagree",
        "MATLAB:dimagree", 0);
    }

    loop_ub = U->size[0];
    i = ptsIn->size[0] * ptsIn->size[1];
    ptsIn->size[0] = U->size[0];
    ptsIn->size[1] = 2;
    emxEnsureCapacity_real_T(&b_st, ptsIn, i, &kj_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      ptsIn->data[i] = U->data[i] / ptsIn->data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      ptsIn->data[i + ptsIn->size[0]] = U->data[i + U->size[0]] / ptsIn->data[i
        + ptsIn->size[0]];
    }

    result[0] = U->size[0];
    result[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&result[0], 2, &ptsIn->size[0], 2, &u_emlrtECI,
      &st);
    loop_ub = ptsIn->size[0];
    for (i = 0; i < loop_ub; i++) {
      U->data[i] = ptsIn->data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      U->data[i + U->size[0]] = ptsIn->data[i + ptsIn->size[0]];
    }

    loop_ub = U->size[0];
    i = ptsIn->size[0] * ptsIn->size[1];
    ptsIn->size[0] = U->size[0];
    ptsIn->size[1] = 2;
    emxEnsureCapacity_real_T(&st, ptsIn, i, &lj_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      ptsIn->data[i] = U->data[i];
    }

    for (i = 0; i < loop_ub; i++) {
      ptsIn->data[i + ptsIn->size[0]] = U->data[i + U->size[0]];
    }
  }

  emxFree_real_T(&U);
  st.site = &xd_emlrtRSI;
  distortPoints(&st, ptsIn, intrinsicMatrix, radialDist, tangentialDist, ptsOut);
  st.site = &wq_emlrtRSI;
  eval(&st, b_emlrt_marshallOut(&st, cv1), &c_emlrtMCI);
  m = (this->YBounds[1] - this->YBounds[0]) + 1.0;
  n = (this->XBounds[1] - this->XBounds[0]) + 1.0;
  emxFree_real_T(&ptsIn);
  if (b_strcmp(this->ClassOfImage)) {
    st.site = &yd_emlrtRSI;
    varargin_1_tmp[0] = m;
    varargin_1_tmp[1] = n;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    input_sizes_idx_0_tmp = (int32_T)m;
    input_sizes_idx_1_tmp = (int32_T)n;
    Y_idx_0 = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      Y_idx_0 = 1;
    }

    input_sizes_idx_1 = muIntScalarMax_sint32(i, Y_idx_0);
    if (input_sizes_idx_0_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (input_sizes_idx_1_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (!allNonNegative(input_sizes_idx_0_tmp, input_sizes_idx_1_tmp)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    loop_ub_tmp = input_sizes_idx_0_tmp * input_sizes_idx_1_tmp;
    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_U->size[0];
    b_U->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_U, i, &md_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_U->data[i] = ptsOut->data[i];
    }

    i = this->Xmap->size[0] * this->Xmap->size[1];
    this->Xmap->size[0] = input_sizes_idx_0_tmp;
    this->Xmap->size[1] = input_sizes_idx_1_tmp;
    emxEnsureCapacity_real_T(sp, this->Xmap, i, &od_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->Xmap->data[i] = b_U->data[i];
    }

    st.site = &ae_emlrtRSI;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    Y_idx_0 = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      Y_idx_0 = 1;
    }

    input_sizes_idx_1 = muIntScalarMax_sint32(i, Y_idx_0);
    if (input_sizes_idx_0_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (input_sizes_idx_1_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (!allNonNegative(input_sizes_idx_0_tmp, input_sizes_idx_1_tmp)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_U->size[0];
    b_U->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_U, i, &qd_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_U->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = this->Ymap->size[0] * this->Ymap->size[1];
    this->Ymap->size[0] = input_sizes_idx_0_tmp;
    this->Ymap->size[1] = input_sizes_idx_1_tmp;
    emxEnsureCapacity_real_T(sp, this->Ymap, i, &sd_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->Ymap->data[i] = b_U->data[i];
    }
  } else {
    st.site = &be_emlrtRSI;
    varargin_1_tmp[0] = m;
    varargin_1_tmp[1] = n;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    input_sizes_idx_0_tmp = (int32_T)m;
    input_sizes_idx_1_tmp = (int32_T)n;
    Y_idx_0 = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      Y_idx_0 = 1;
    }

    input_sizes_idx_1 = muIntScalarMax_sint32(i, Y_idx_0);
    if (input_sizes_idx_0_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (input_sizes_idx_1_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (!allNonNegative(input_sizes_idx_0_tmp, input_sizes_idx_1_tmp)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    loop_ub_tmp = input_sizes_idx_0_tmp * input_sizes_idx_1_tmp;
    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_U->size[0];
    b_U->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_U, i, &ld_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_U->data[i] = ptsOut->data[i];
    }

    i = this->XmapSingle->size[0] * this->XmapSingle->size[1];
    this->XmapSingle->size[0] = input_sizes_idx_0_tmp;
    this->XmapSingle->size[1] = input_sizes_idx_1_tmp;
    emxEnsureCapacity_real32_T(sp, this->XmapSingle, i, &nd_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->XmapSingle->data[i] = (real32_T)b_U->data[i];
    }

    st.site = &ce_emlrtRSI;
    i = ptsOut->size[0];
    b_st.site = &we_emlrtRSI;
    assertValidSizeArg(&b_st, varargin_1_tmp);
    Y_idx_0 = ptsOut->size[0];
    if (1 > ptsOut->size[0]) {
      Y_idx_0 = 1;
    }

    input_sizes_idx_1 = muIntScalarMax_sint32(i, Y_idx_0);
    if (input_sizes_idx_0_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (input_sizes_idx_1_tmp > input_sizes_idx_1) {
      emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
        "Coder:toolbox:reshape_emptyReshapeLimit",
        "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }

    if (!allNonNegative(input_sizes_idx_0_tmp, input_sizes_idx_1_tmp)) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
        "MATLAB:checkDimCommon:nonnegativeSize",
        "MATLAB:checkDimCommon:nonnegativeSize", 0);
    }

    if (loop_ub_tmp != ptsOut->size[0]) {
      emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
        "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }

    loop_ub = ptsOut->size[0];
    i = b_U->size[0];
    b_U->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(sp, b_U, i, &pd_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_U->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = this->YmapSingle->size[0] * this->YmapSingle->size[1];
    this->YmapSingle->size[0] = input_sizes_idx_0_tmp;
    this->YmapSingle->size[1] = input_sizes_idx_1_tmp;
    emxEnsureCapacity_real32_T(sp, this->YmapSingle, i, &rd_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      this->YmapSingle->data[i] = (real32_T)b_U->data[i];
    }
  }

  emxFree_real_T(&b_U);
  emxFree_real_T(&ptsOut);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_ImageTransformer_update(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2], const real_T xBounds[2],
  const real_T yBounds[2])
{
  int32_T i;
  static const char_T b_cv[5] = { 'u', 'i', 'n', 't', '8' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  i = this->SizeOfImage->size[0] * this->SizeOfImage->size[1];
  this->SizeOfImage->size[0] = 1;
  this->SizeOfImage->size[1] = 2;
  emxEnsureCapacity_real_T(sp, this->SizeOfImage, i, &ed_emlrtRTEI);
  this->SizeOfImage->data[0] = 480.0;
  this->SizeOfImage->data[1] = 640.0;
  i = this->ClassOfImage->size[0] * this->ClassOfImage->size[1];
  this->ClassOfImage->size[0] = 1;
  this->ClassOfImage->size[1] = 5;
  emxEnsureCapacity_char_T(sp, this->ClassOfImage, i, &fd_emlrtRTEI);
  for (i = 0; i < 5; i++) {
    this->ClassOfImage->data[i] = b_cv[i];
  }

  i = this->OutputView->size[0] * this->OutputView->size[1];
  this->OutputView->size[0] = 1;
  this->OutputView->size[1] = 4;
  emxEnsureCapacity_char_T(sp, this->OutputView, i, &gd_emlrtRTEI);
  this->OutputView->data[0] = 'f';
  this->OutputView->data[1] = 'u';
  this->OutputView->data[2] = 'l';
  this->OutputView->data[3] = 'l';
  this->XBounds[0] = xBounds[0];
  this->YBounds[0] = yBounds[0];
  this->XBounds[1] = xBounds[1];
  this->YBounds[1] = yBounds[1];
  st.site = &td_emlrtRSI;
  ImageTransformer_computeMap(&st, this, intrinsicMatrix, radialDist,
    tangentialDist);
}

c_vision_internal_calibration_I *c_ImageTransformer_ImageTransfo(const
  emlrtStack *sp, c_vision_internal_calibration_I *this)
{
  c_vision_internal_calibration_I *b_this;
  int32_T i;
  static const char_T b_cv[5] = { 'u', 'i', 'n', 't', '8' };

  b_this = this;
  b_this->XBounds[0] = -1.0;
  b_this->XBounds[1] = -1.0;
  b_this->YBounds[0] = -1.0;
  b_this->YBounds[1] = -1.0;
  i = b_this->SizeOfImage->size[0] * b_this->SizeOfImage->size[1];
  b_this->SizeOfImage->size[0] = 1;
  b_this->SizeOfImage->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_this->SizeOfImage, i, &pl_emlrtRTEI);
  b_this->SizeOfImage->data[0] = 0.0;
  b_this->SizeOfImage->data[1] = 0.0;
  i = b_this->SizeOfImage->size[0] * b_this->SizeOfImage->size[1];
  b_this->SizeOfImage->size[0] = 1;
  b_this->SizeOfImage->size[1] = 3;
  emxEnsureCapacity_real_T(sp, b_this->SizeOfImage, i, &ql_emlrtRTEI);
  b_this->SizeOfImage->data[0] = 0.0;
  b_this->SizeOfImage->data[1] = 0.0;
  b_this->SizeOfImage->data[2] = 0.0;
  i = b_this->ClassOfImage->size[0] * b_this->ClassOfImage->size[1];
  b_this->ClassOfImage->size[0] = 1;
  b_this->ClassOfImage->size[1] = 1;
  emxEnsureCapacity_char_T(sp, b_this->ClassOfImage, i, &rl_emlrtRTEI);
  b_this->ClassOfImage->data[0] = 'a';
  i = b_this->ClassOfImage->size[0] * b_this->ClassOfImage->size[1];
  b_this->ClassOfImage->size[0] = 1;
  b_this->ClassOfImage->size[1] = 5;
  emxEnsureCapacity_char_T(sp, b_this->ClassOfImage, i, &sl_emlrtRTEI);
  for (i = 0; i < 5; i++) {
    b_this->ClassOfImage->data[i] = b_cv[i];
  }

  i = b_this->OutputView->size[0] * b_this->OutputView->size[1];
  b_this->OutputView->size[0] = 1;
  b_this->OutputView->size[1] = 1;
  emxEnsureCapacity_char_T(sp, b_this->OutputView, i, &tl_emlrtRTEI);
  b_this->OutputView->data[0] = 'a';
  i = b_this->OutputView->size[0] * b_this->OutputView->size[1];
  b_this->OutputView->size[0] = 1;
  b_this->OutputView->size[1] = 4;
  emxEnsureCapacity_char_T(sp, b_this->OutputView, i, &ul_emlrtRTEI);
  b_this->OutputView->data[0] = 's';
  b_this->OutputView->data[1] = 'a';
  b_this->OutputView->data[2] = 'm';
  b_this->OutputView->data[3] = 'e';
  i = b_this->Xmap->size[0] * b_this->Xmap->size[1];
  b_this->Xmap->size[0] = 2;
  b_this->Xmap->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_this->Xmap, i, &vl_emlrtRTEI);
  b_this->Xmap->data[0] = 0.0;
  b_this->Xmap->data[1] = 0.0;
  b_this->Xmap->data[2] = 0.0;
  b_this->Xmap->data[3] = 0.0;
  i = b_this->Ymap->size[0] * b_this->Ymap->size[1];
  b_this->Ymap->size[0] = 2;
  b_this->Ymap->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_this->Ymap, i, &wl_emlrtRTEI);
  b_this->Ymap->data[0] = 0.0;
  b_this->Ymap->data[1] = 0.0;
  b_this->Ymap->data[2] = 0.0;
  b_this->Ymap->data[3] = 0.0;
  i = b_this->XmapSingle->size[0] * b_this->XmapSingle->size[1];
  b_this->XmapSingle->size[0] = 2;
  b_this->XmapSingle->size[1] = 2;
  emxEnsureCapacity_real32_T(sp, b_this->XmapSingle, i, &xl_emlrtRTEI);
  b_this->XmapSingle->data[0] = 0.0F;
  b_this->XmapSingle->data[1] = 0.0F;
  b_this->XmapSingle->data[2] = 0.0F;
  b_this->XmapSingle->data[3] = 0.0F;
  i = b_this->YmapSingle->size[0] * b_this->YmapSingle->size[1];
  b_this->YmapSingle->size[0] = 2;
  b_this->YmapSingle->size[1] = 2;
  emxEnsureCapacity_real32_T(sp, b_this->YmapSingle, i, &yl_emlrtRTEI);
  b_this->YmapSingle->data[0] = 0.0F;
  b_this->YmapSingle->data[1] = 0.0F;
  b_this->YmapSingle->data[2] = 0.0F;
  b_this->YmapSingle->data[3] = 0.0F;
  return b_this;
}

/* End of code generation (ImageTransformer.c) */
