/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * reconstructScene.c
 *
 * Code generation for function 'reconstructScene'
 *
 */

/* Include files */
#include "reconstructScene.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "assertValidSizeArg.h"
#include "bsxfun.h"
#include "cat.h"
#include "meshgrid.h"
#include "mtimes.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo op_emlrtRSI = { 77, /* lineNo */
  "reconstructScene",                  /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/reconstructScene.m"/* pathName */
};

static emlrtRSInfo pp_emlrtRSI = { 289,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo qp_emlrtRSI = { 292,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo rp_emlrtRSI = { 293,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo sp_emlrtRSI = { 305,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo tp_emlrtRSI = { 308,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo up_emlrtRSI = { 310,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo vp_emlrtRSI = { 311,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo wp_emlrtRSI = { 314,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo xp_emlrtRSI = { 315,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo yp_emlrtRSI = { 316,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo aq_emlrtRSI = { 323,/* lineNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 288,/* lineNo */
  13,                                  /* colNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 285,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl/reconstructSceneImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  319,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "StereoParametersImpl/reconstructSceneImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  320,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "StereoParametersImpl/reconstructSceneImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  321,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "StereoParametersImpl/reconstructSceneImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo jk_emlrtRTEI = { 306,/* lineNo */
  21,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo kk_emlrtRTEI = { 307,/* lineNo */
  21,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo lk_emlrtRTEI = { 311,/* lineNo */
  43,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo mk_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "div",                               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/div.m"/* pName */
};

static emlrtRTEInfo nk_emlrtRTEI = { 314,/* lineNo */
  29,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo ok_emlrtRTEI = { 314,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo pk_emlrtRTEI = { 315,/* lineNo */
  29,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo qk_emlrtRTEI = { 315,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo rk_emlrtRTEI = { 316,/* lineNo */
  29,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo sk_emlrtRTEI = { 316,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo tk_emlrtRTEI = { 77,/* lineNo */
  13,                                  /* colNo */
  "reconstructScene",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/reconstructScene.m"/* pName */
};

static emlrtRTEInfo uk_emlrtRTEI = { 310,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo vk_emlrtRTEI = { 311,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo wk_emlrtRTEI = { 319,/* lineNo */
  19,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo xk_emlrtRTEI = { 320,/* lineNo */
  19,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo yk_emlrtRTEI = { 321,/* lineNo */
  19,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo al_emlrtRTEI = { 306,/* lineNo */
  26,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo bl_emlrtRTEI = { 307,/* lineNo */
  26,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

/* Function Definitions */
void reconstructScene(const emlrtStack *sp, const emxArray_real32_T
                      *disparityMap, const c_vision_internal_calibration_S
                      *stereoParams, emxArray_real32_T *xyzPoints)
{
  real_T imageSize[2];
  real_T varargin_1[2];
  boolean_T p;
  int32_T maxdimlen;
  boolean_T exitg1;
  boolean_T b_p;
  int32_T i;
  emxArray_real_T *y;
  real32_T Q[16];
  int32_T numPoints;
  emxArray_real_T *b_y;
  int32_T loop_ub;
  emxArray_real32_T *c_y;
  emxArray_real32_T *d_y;
  emxArray_real32_T *X;
  emxArray_real32_T *Y;
  boolean_T b;
  emxArray_real32_T *b_X;
  int32_T Y_idx_0;
  int32_T disparityMap_idx_0;
  emxArray_real32_T *points3dHomog;
  emxArray_real32_T *b_points3dHomog;
  emxArray_real32_T *points3d;
  emxArray_real32_T *b_points3d;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  emxArray_real32_T *Z;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
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
  st.site = &op_emlrtRSI;
  if (!stereoParams->RectificationParams.Initialized) {
    emlrtErrorWithMessageIdR2018a(&st, &ub_emlrtRTEI,
      "vision:calibrate:callRectifyFirst", "vision:calibrate:callRectifyFirst",
      3, 4, 12, "stereoParams");
  }

  b_st.site = &pp_emlrtRSI;
  imageSize[0] = (stereoParams->RectificationParams.YBounds[1] -
                  stereoParams->RectificationParams.YBounds[0]) + 1.0;
  imageSize[1] = (stereoParams->RectificationParams.XBounds[1] -
                  stereoParams->RectificationParams.XBounds[0]) + 1.0;
  varargin_1[0] = disparityMap->size[0];
  varargin_1[1] = disparityMap->size[1];
  p = true;
  maxdimlen = 0;
  exitg1 = false;
  while ((!exitg1) && (maxdimlen < 2)) {
    if (!((uint32_T)varargin_1[maxdimlen] == imageSize[maxdimlen])) {
      p = false;
      exitg1 = true;
    } else {
      maxdimlen++;
    }
  }

  b_p = (int32_T)p;
  if (!b_p) {
    b_st.site = &qp_emlrtRSI;
    imageSize[0] = (stereoParams->RectificationParams.YBounds[1] -
                    stereoParams->RectificationParams.YBounds[0]) + 1.0;
    b_st.site = &rp_emlrtRSI;
    varargin_1[1] = (stereoParams->RectificationParams.XBounds[1] -
                     stereoParams->RectificationParams.XBounds[0]) + 1.0;
    emlrtErrorWithMessageIdR2018a(&st, &tb_emlrtRTEI,
      "vision:calibrate:disparitySizeMismatch",
      "vision:calibrate:disparitySizeMismatch", 10, 4, 12, "disparityMap", 6,
      imageSize[0], 6, varargin_1[1], 4, 12, "disparityMap");
  }

  for (i = 0; i < 16; i++) {
    Q[i] = (real32_T)stereoParams->RectificationParams.Q[i];
  }

  emxInit_real_T(&st, &y, 2, &al_emlrtRTEI, true);
  numPoints = disparityMap->size[0] * disparityMap->size[1];
  if (disparityMap->size[1] < 1) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)((real_T)disparityMap->size[1] - 1.0) + 1;
    emxEnsureCapacity_real_T(&st, y, i, &id_emlrtRTEI);
    loop_ub = (int32_T)((real_T)disparityMap->size[1] - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = (real_T)i + 1.0;
    }
  }

  emxInit_real_T(&st, &b_y, 2, &bl_emlrtRTEI, true);
  if (disparityMap->size[0] < 1) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = (int32_T)((real_T)disparityMap->size[0] - 1.0) + 1;
    emxEnsureCapacity_real_T(&st, b_y, i, &id_emlrtRTEI);
    loop_ub = (int32_T)((real_T)disparityMap->size[0] - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = (real_T)i + 1.0;
    }
  }

  emxInit_real32_T(&st, &c_y, 2, &jk_emlrtRTEI, true);
  i = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = y->size[1];
  emxEnsureCapacity_real32_T(&st, c_y, i, &jk_emlrtRTEI);
  loop_ub = y->size[0] * y->size[1];
  for (i = 0; i < loop_ub; i++) {
    c_y->data[i] = (real32_T)y->data[i];
  }

  emxFree_real_T(&y);
  emxInit_real32_T(&st, &d_y, 2, &kk_emlrtRTEI, true);
  i = d_y->size[0] * d_y->size[1];
  d_y->size[0] = 1;
  d_y->size[1] = b_y->size[1];
  emxEnsureCapacity_real32_T(&st, d_y, i, &kk_emlrtRTEI);
  loop_ub = b_y->size[0] * b_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_y->data[i] = (real32_T)b_y->data[i];
  }

  emxFree_real_T(&b_y);
  emxInit_real32_T(&st, &X, 2, &ok_emlrtRTEI, true);
  emxInit_real32_T(&st, &Y, 2, &qk_emlrtRTEI, true);
  b_st.site = &sp_emlrtRSI;
  c_meshgrid(&b_st, c_y, d_y, X, Y);
  b_st.site = &tp_emlrtRSI;
  c_st.site = &je_emlrtRSI;
  d_st.site = &ke_emlrtRSI;
  emxFree_real32_T(&d_y);
  emxFree_real32_T(&c_y);
  if (Y->size[0] * Y->size[1] != X->size[0] * X->size[1]) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  b = (disparityMap->size[0] * disparityMap->size[1] == X->size[0] * X->size[1]);
  if (!b) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  b = ((numPoints == X->size[0] * X->size[1]) && b);
  if (!b) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real32_T(&d_st, &b_X, 2, &jd_emlrtRTEI, true);
  b_st.site = &up_emlrtRSI;
  maxdimlen = X->size[0] * X->size[1];
  Y_idx_0 = Y->size[0] * Y->size[1];
  disparityMap_idx_0 = disparityMap->size[0] * disparityMap->size[1];
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = maxdimlen;
  b_X->size[1] = 4;
  emxEnsureCapacity_real32_T(&b_st, b_X, i, &jd_emlrtRTEI);
  for (i = 0; i < maxdimlen; i++) {
    b_X->data[i] = X->data[i];
  }

  for (i = 0; i < Y_idx_0; i++) {
    b_X->data[i + b_X->size[0]] = Y->data[i];
  }

  for (i = 0; i < disparityMap_idx_0; i++) {
    b_X->data[i + b_X->size[0] * 2] = disparityMap->data[i];
  }

  for (i = 0; i < numPoints; i++) {
    b_X->data[i + b_X->size[0] * 3] = 1.0F;
  }

  emxInit_real32_T(&b_st, &points3dHomog, 2, &uk_emlrtRTEI, true);
  emxInit_real32_T(&b_st, &b_points3dHomog, 2, &lk_emlrtRTEI, true);
  c_st.site = &po_emlrtRSI;
  b_mtimes(&c_st, b_X, Q, points3dHomog);
  loop_ub = points3dHomog->size[0];
  i = b_points3dHomog->size[0] * b_points3dHomog->size[1];
  b_points3dHomog->size[0] = points3dHomog->size[0];
  b_points3dHomog->size[1] = 3;
  emxEnsureCapacity_real32_T(&st, b_points3dHomog, i, &lk_emlrtRTEI);
  emxFree_real32_T(&b_X);
  for (i = 0; i < 3; i++) {
    for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
      b_points3dHomog->data[maxdimlen + b_points3dHomog->size[0] * i] =
        points3dHomog->data[maxdimlen + points3dHomog->size[0] * i];
    }
  }

  emxInit_real32_T(&st, &points3d, 1, &nk_emlrtRTEI, true);
  loop_ub = points3dHomog->size[0];
  i = points3d->size[0];
  points3d->size[0] = points3dHomog->size[0];
  emxEnsureCapacity_real32_T(&st, points3d, i, &mk_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    points3d->data[i] = 1.0F / points3dHomog->data[i + points3dHomog->size[0] *
      3];
  }

  emxFree_real32_T(&points3dHomog);
  emxInit_real32_T(&st, &b_points3d, 2, &vk_emlrtRTEI, true);
  b_st.site = &vp_emlrtRSI;
  bsxfun(&b_st, b_points3dHomog, points3d, b_points3d);
  b_st.site = &wp_emlrtRSI;
  varargin_1[0] = disparityMap->size[0];
  varargin_1[1] = disparityMap->size[1];
  i = b_points3d->size[0];
  c_st.site = &we_emlrtRSI;
  assertValidSizeArg(&c_st, varargin_1);
  disparityMap_idx_0 = disparityMap->size[0];
  numPoints = disparityMap->size[1];
  Y_idx_0 = b_points3d->size[0];
  emxFree_real32_T(&b_points3dHomog);
  if (1 > b_points3d->size[0]) {
    Y_idx_0 = 1;
  }

  maxdimlen = muIntScalarMax_sint32(i, Y_idx_0);
  if (disparityMap_idx_0 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (numPoints > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  loop_ub = disparityMap_idx_0 * numPoints;
  if (loop_ub != b_points3d->size[0]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &r_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  b_loop_ub = b_points3d->size[0];
  i = points3d->size[0];
  points3d->size[0] = b_points3d->size[0];
  emxEnsureCapacity_real32_T(&st, points3d, i, &nk_emlrtRTEI);
  for (i = 0; i < b_loop_ub; i++) {
    points3d->data[i] = b_points3d->data[i];
  }

  i = X->size[0] * X->size[1];
  X->size[0] = disparityMap_idx_0;
  X->size[1] = numPoints;
  emxEnsureCapacity_real32_T(&st, X, i, &ok_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    X->data[i] = points3d->data[i];
  }

  b_st.site = &xp_emlrtRSI;
  varargin_1[0] = disparityMap->size[0];
  varargin_1[1] = disparityMap->size[1];
  i = b_points3d->size[0];
  c_st.site = &we_emlrtRSI;
  assertValidSizeArg(&c_st, varargin_1);
  disparityMap_idx_0 = disparityMap->size[0];
  numPoints = disparityMap->size[1];
  Y_idx_0 = b_points3d->size[0];
  if (1 > b_points3d->size[0]) {
    Y_idx_0 = 1;
  }

  maxdimlen = muIntScalarMax_sint32(i, Y_idx_0);
  if (disparityMap_idx_0 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (numPoints > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  b_loop_ub = disparityMap_idx_0 * numPoints;
  if (b_loop_ub != b_points3d->size[0]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &r_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  c_loop_ub = b_points3d->size[0];
  i = points3d->size[0];
  points3d->size[0] = b_points3d->size[0];
  emxEnsureCapacity_real32_T(&st, points3d, i, &pk_emlrtRTEI);
  for (i = 0; i < c_loop_ub; i++) {
    points3d->data[i] = b_points3d->data[i + b_points3d->size[0]];
  }

  i = Y->size[0] * Y->size[1];
  Y->size[0] = disparityMap_idx_0;
  Y->size[1] = numPoints;
  emxEnsureCapacity_real32_T(&st, Y, i, &qk_emlrtRTEI);
  for (i = 0; i < b_loop_ub; i++) {
    Y->data[i] = points3d->data[i];
  }

  b_st.site = &yp_emlrtRSI;
  varargin_1[0] = disparityMap->size[0];
  varargin_1[1] = disparityMap->size[1];
  i = b_points3d->size[0];
  c_st.site = &we_emlrtRSI;
  assertValidSizeArg(&c_st, varargin_1);
  disparityMap_idx_0 = disparityMap->size[0];
  numPoints = disparityMap->size[1];
  Y_idx_0 = b_points3d->size[0];
  if (1 > b_points3d->size[0]) {
    Y_idx_0 = 1;
  }

  maxdimlen = muIntScalarMax_sint32(i, Y_idx_0);
  if (disparityMap_idx_0 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  if (numPoints > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &t_emlrtRTEI,
      "Coder:toolbox:reshape_emptyReshapeLimit",
      "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }

  c_loop_ub = disparityMap_idx_0 * numPoints;
  if (c_loop_ub != b_points3d->size[0]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &r_emlrtRTEI,
      "Coder:MATLAB:getReshapeDims_notSameNumel",
      "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }

  Y_idx_0 = b_points3d->size[0];
  i = points3d->size[0];
  points3d->size[0] = b_points3d->size[0];
  emxEnsureCapacity_real32_T(&st, points3d, i, &rk_emlrtRTEI);
  for (i = 0; i < Y_idx_0; i++) {
    points3d->data[i] = b_points3d->data[i + b_points3d->size[0] * 2];
  }

  emxFree_real32_T(&b_points3d);
  emxInit_real32_T(&st, &Z, 2, &sk_emlrtRTEI, true);
  i = Z->size[0] * Z->size[1];
  Z->size[0] = disparityMap_idx_0;
  Z->size[1] = numPoints;
  emxEnsureCapacity_real32_T(&st, Z, i, &sk_emlrtRTEI);
  for (i = 0; i < c_loop_ub; i++) {
    Z->data[i] = points3d->data[i];
  }

  emxFree_real32_T(&points3d);
  maxdimlen = disparityMap->size[0] * disparityMap->size[1] - 1;
  Y_idx_0 = 0;
  for (disparityMap_idx_0 = 0; disparityMap_idx_0 <= maxdimlen;
       disparityMap_idx_0++) {
    if (disparityMap->data[disparityMap_idx_0] == -3.402823466E+38F) {
      Y_idx_0++;
    }
  }

  emxInit_int32_T(&st, &r, 1, &wk_emlrtRTEI, true);
  i = r->size[0];
  r->size[0] = Y_idx_0;
  emxEnsureCapacity_int32_T(&st, r, i, &tk_emlrtRTEI);
  Y_idx_0 = 0;
  for (disparityMap_idx_0 = 0; disparityMap_idx_0 <= maxdimlen;
       disparityMap_idx_0++) {
    if (disparityMap->data[disparityMap_idx_0] == -3.402823466E+38F) {
      r->data[Y_idx_0] = disparityMap_idx_0 + 1;
      Y_idx_0++;
    }
  }

  Y_idx_0 = r->size[0];
  for (i = 0; i < Y_idx_0; i++) {
    if ((r->data[i] < 1) || (r->data[i] > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(r->data[i], 1, loop_ub, &xd_emlrtBCI, &st);
    }

    X->data[r->data[i] - 1] = rtNaNF;
  }

  emxFree_int32_T(&r);
  maxdimlen = disparityMap->size[0] * disparityMap->size[1] - 1;
  Y_idx_0 = 0;
  for (disparityMap_idx_0 = 0; disparityMap_idx_0 <= maxdimlen;
       disparityMap_idx_0++) {
    if (disparityMap->data[disparityMap_idx_0] == -3.402823466E+38F) {
      Y_idx_0++;
    }
  }

  emxInit_int32_T(&st, &r1, 1, &xk_emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = Y_idx_0;
  emxEnsureCapacity_int32_T(&st, r1, i, &tk_emlrtRTEI);
  Y_idx_0 = 0;
  for (disparityMap_idx_0 = 0; disparityMap_idx_0 <= maxdimlen;
       disparityMap_idx_0++) {
    if (disparityMap->data[disparityMap_idx_0] == -3.402823466E+38F) {
      r1->data[Y_idx_0] = disparityMap_idx_0 + 1;
      Y_idx_0++;
    }
  }

  loop_ub = r1->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((r1->data[i] < 1) || (r1->data[i] > b_loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(r1->data[i], 1, b_loop_ub, &yd_emlrtBCI, &st);
    }

    Y->data[r1->data[i] - 1] = rtNaNF;
  }

  emxFree_int32_T(&r1);
  maxdimlen = disparityMap->size[0] * disparityMap->size[1] - 1;
  Y_idx_0 = 0;
  for (disparityMap_idx_0 = 0; disparityMap_idx_0 <= maxdimlen;
       disparityMap_idx_0++) {
    if (disparityMap->data[disparityMap_idx_0] == -3.402823466E+38F) {
      Y_idx_0++;
    }
  }

  emxInit_int32_T(&st, &r2, 1, &yk_emlrtRTEI, true);
  i = r2->size[0];
  r2->size[0] = Y_idx_0;
  emxEnsureCapacity_int32_T(&st, r2, i, &tk_emlrtRTEI);
  Y_idx_0 = 0;
  for (disparityMap_idx_0 = 0; disparityMap_idx_0 <= maxdimlen;
       disparityMap_idx_0++) {
    if (disparityMap->data[disparityMap_idx_0] == -3.402823466E+38F) {
      r2->data[Y_idx_0] = disparityMap_idx_0 + 1;
      Y_idx_0++;
    }
  }

  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((r2->data[i] < 1) || (r2->data[i] > c_loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(r2->data[i], 1, c_loop_ub, &ae_emlrtBCI, &st);
    }

    Z->data[r2->data[i] - 1] = rtNaNF;
  }

  emxFree_int32_T(&r2);
  b_st.site = &aq_emlrtRSI;
  cat(&b_st, X, Y, Z, xyzPoints);
  emxFree_real32_T(&Z);
  emxFree_real32_T(&Y);
  emxFree_real32_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (reconstructScene.c) */
