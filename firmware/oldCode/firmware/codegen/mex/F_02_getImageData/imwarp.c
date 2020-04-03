/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imwarp.c
 *
 * Code generation for function 'imwarp'
 *
 */

/* Include files */
#include "imwarp.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "inv.h"
#include "libmwimterp2d.h"
#include "meshgrid.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo hq_emlrtRSI = { 13, /* lineNo */
  "imwarp",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo iq_emlrtRSI = { 136,/* lineNo */
  "imwarp",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo jq_emlrtRSI = { 397,/* lineNo */
  "validateInputImage",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo kq_emlrtRSI = { 166,/* lineNo */
  "remapPointsAndResample",            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo lq_emlrtRSI = { 200,/* lineNo */
  "remapAndResampleGeneric2d",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo mq_emlrtRSI = { 204,/* lineNo */
  "remapAndResampleGeneric2d",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo nq_emlrtRSI = { 208,/* lineNo */
  "remapAndResampleGeneric2d",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo oq_emlrtRSI = { 213,/* lineNo */
  "remapAndResampleGeneric2d",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo pq_emlrtRSI = { 216,/* lineNo */
  "remapAndResampleGeneric2d",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pathName */
};

static emlrtRSInfo qq_emlrtRSI = { 231,/* lineNo */
  "imref2d/intrinsicToWorld",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pathName */
};

static emlrtRSInfo rq_emlrtRSI = { 259,/* lineNo */
  "projective2d/transformPointsInverse",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo sq_emlrtRSI = { 272,/* lineNo */
  "projective2d/transformPointsInverse",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo tq_emlrtRSI = { 273,/* lineNo */
  "projective2d/transformPointsInverse",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo uq_emlrtRSI = { 254,/* lineNo */
  "imref2d/worldToIntrinsic",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pathName */
};

static emlrtRSInfo vq_emlrtRSI = { 54, /* lineNo */
  "interp2d",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/interp2d.m"/* pathName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 492,/* lineNo */
  52,                                  /* colNo */
  "validateXYPoints",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/imref2d.m"/* pName */
};

static emlrtECInfo v_emlrtECI = { 2,   /* nDims */
  269,                                 /* lineNo */
  25,                                  /* colNo */
  "projective2d/transformPointsInverse",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtECInfo w_emlrtECI = { 2,   /* nDims */
  268,                                 /* lineNo */
  25,                                  /* colNo */
  "projective2d/transformPointsInverse",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtECInfo x_emlrtECI = { 2,   /* nDims */
  267,                                 /* lineNo */
  25,                                  /* colNo */
  "projective2d/transformPointsInverse",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 254,/* lineNo */
  46,                                  /* colNo */
  "projective2d/transformPointsInverse",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo el_emlrtRTEI = { 267,/* lineNo */
  25,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo fl_emlrtRTEI = { 267,/* lineNo */
  37,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo gl_emlrtRTEI = { 268,/* lineNo */
  25,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo hl_emlrtRTEI = { 268,/* lineNo */
  37,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo il_emlrtRTEI = { 200,/* lineNo */
  16,                                  /* colNo */
  "imwarp",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pName */
};

static emlrtRTEInfo jl_emlrtRTEI = { 200,/* lineNo */
  42,                                  /* colNo */
  "imwarp",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pName */
};

static emlrtRTEInfo kl_emlrtRTEI = { 200,/* lineNo */
  67,                                  /* colNo */
  "imwarp",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pName */
};

static emlrtRTEInfo ll_emlrtRTEI = { 263,/* lineNo */
  21,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo ml_emlrtRTEI = { 264,/* lineNo */
  21,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo nl_emlrtRTEI = { 265,/* lineNo */
  21,                                  /* colNo */
  "projective2d",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo ol_emlrtRTEI = { 1,/* lineNo */
  36,                                  /* colNo */
  "imwarp",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/imwarp.m"/* pName */
};

/* Function Definitions */
void imwarp(const emlrtStack *sp, const real_T varargin_1[307200], const real_T
            varargin_2_T[9], const real_T varargin_4_ImageSizeAlias[2],
            emxArray_real_T *outputImage)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emxArray_real_T *y;
  int32_T i;
  emxArray_real_T *b_y;
  emxArray_real_T *dstYIntrinsic;
  emxArray_real_T *w;
  uint32_T b_varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T b_p;
  emxArray_real_T *u;
  real_T M[9];
  emxArray_real_T *r;
  emxArray_real_T *v;
  real_T fillValues;
  real_T b_outputImage[2];
  real_T b_dv[3];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &hq_emlrtRSI;
  b_st.site = &jq_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 307200)) {
    if ((!muDoubleScalarIsInf(varargin_1[k])) && (!muDoubleScalarIsNaN
         (varargin_1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:imwarp:expectedFinite", 3, 4, 18, "input number 1, A,");
  }

  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 307200)) {
    if (!muDoubleScalarIsNaN(varargin_1[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:imwarp:expectedNonNaN", 3, 4, 18, "input number 1, A,");
  }

  emxInit_real_T(&c_st, &y, 2, &jl_emlrtRTEI, true);
  st.site = &iq_emlrtRSI;
  b_st.site = &kq_emlrtRSI;
  if (muDoubleScalarIsNaN(varargin_4_ImageSizeAlias[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    y->data[0] = rtNaN;
  } else if (varargin_4_ImageSizeAlias[1] < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (muDoubleScalarIsInf(varargin_4_ImageSizeAlias[1]) && (1.0 ==
              varargin_4_ImageSizeAlias[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    y->data[0] = rtNaN;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    k = (int32_T)muDoubleScalarFloor(varargin_4_ImageSizeAlias[1] - 1.0);
    y->size[1] = k + 1;
    emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
    for (i = 0; i <= k; i++) {
      y->data[i] = (real_T)i + 1.0;
    }
  }

  emxInit_real_T(&b_st, &b_y, 2, &kl_emlrtRTEI, true);
  if (muDoubleScalarIsNaN(varargin_4_ImageSizeAlias[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    b_y->data[0] = rtNaN;
  } else if (varargin_4_ImageSizeAlias[0] < 1.0) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if (muDoubleScalarIsInf(varargin_4_ImageSizeAlias[0]) && (1.0 ==
              varargin_4_ImageSizeAlias[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    b_y->data[0] = rtNaN;
  } else {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    k = (int32_T)muDoubleScalarFloor(varargin_4_ImageSizeAlias[0] - 1.0);
    b_y->size[1] = k + 1;
    emxEnsureCapacity_real_T(&b_st, b_y, i, &id_emlrtRTEI);
    for (i = 0; i <= k; i++) {
      b_y->data[i] = (real_T)i + 1.0;
    }
  }

  emxInit_real_T(&b_st, &dstYIntrinsic, 2, &il_emlrtRTEI, true);
  emxInit_real_T(&b_st, &w, 2, &nl_emlrtRTEI, true);
  c_st.site = &lq_emlrtRSI;
  meshgrid(&c_st, y, b_y, w, dstYIntrinsic);
  c_st.site = &mq_emlrtRSI;
  d_st.site = &qq_emlrtRSI;
  b_varargin_1[0] = (uint32_T)w->size[0];
  varargin_2[0] = (uint32_T)dstYIntrinsic->size[0];
  b_varargin_1[1] = (uint32_T)w->size[1];
  varargin_2[1] = (uint32_T)dstYIntrinsic->size[1];
  b_p = true;
  k = 0;
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &xb_emlrtRTEI,
      "images:spatialref:invalidXYPoint", "images:spatialref:invalidXYPoint", 6,
      4, 10, "xIntrinsic", 4, 10, "yIntrinsic");
  }

  k = w->size[0] * w->size[1];
  for (i = 0; i < k; i++) {
    w->data[i] = (w->data[i] - 0.5) + 0.5;
  }

  k = dstYIntrinsic->size[0] * dstYIntrinsic->size[1];
  for (i = 0; i < k; i++) {
    dstYIntrinsic->data[i] = (dstYIntrinsic->data[i] - 0.5) + 0.5;
  }

  c_st.site = &nq_emlrtRSI;
  b_varargin_1[0] = (uint32_T)w->size[0];
  varargin_2[0] = (uint32_T)dstYIntrinsic->size[0];
  b_varargin_1[1] = (uint32_T)w->size[1];
  varargin_2[1] = (uint32_T)dstYIntrinsic->size[1];
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &yb_emlrtRTEI,
      "images:geotrans:transformPointsSizeMismatch",
      "images:geotrans:transformPointsSizeMismatch", 9, 4, 22,
      "transformPointsInverse", 4, 1, "X", 4, 1, "Y");
  }

  emxInit_real_T(&c_st, &u, 2, &ll_emlrtRTEI, true);
  d_st.site = &rq_emlrtRSI;
  e_st.site = &lo_emlrtRSI;
  inv(&e_st, varargin_2_T, M);
  i = u->size[0] * u->size[1];
  u->size[0] = w->size[0];
  u->size[1] = w->size[1];
  emxEnsureCapacity_real_T(&c_st, u, i, &el_emlrtRTEI);
  k = w->size[0] * w->size[1];
  for (i = 0; i < k; i++) {
    u->data[i] = M[0] * w->data[i];
  }

  emxInit_real_T(&c_st, &r, 2, &ol_emlrtRTEI, true);
  i = r->size[0] * r->size[1];
  r->size[0] = dstYIntrinsic->size[0];
  r->size[1] = dstYIntrinsic->size[1];
  emxEnsureCapacity_real_T(&c_st, r, i, &fl_emlrtRTEI);
  k = dstYIntrinsic->size[0] * dstYIntrinsic->size[1];
  for (i = 0; i < k; i++) {
    r->data[i] = M[1] * dstYIntrinsic->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])u->size, *(int32_T (*)[2])r->size,
    &x_emlrtECI, &c_st);
  k = u->size[0] * u->size[1];
  for (i = 0; i < k; i++) {
    u->data[i] = (u->data[i] + r->data[i]) + M[2];
  }

  emxInit_real_T(&c_st, &v, 2, &ml_emlrtRTEI, true);
  i = v->size[0] * v->size[1];
  v->size[0] = w->size[0];
  v->size[1] = w->size[1];
  emxEnsureCapacity_real_T(&c_st, v, i, &gl_emlrtRTEI);
  k = w->size[0] * w->size[1];
  for (i = 0; i < k; i++) {
    v->data[i] = M[3] * w->data[i];
  }

  i = r->size[0] * r->size[1];
  r->size[0] = dstYIntrinsic->size[0];
  r->size[1] = dstYIntrinsic->size[1];
  emxEnsureCapacity_real_T(&c_st, r, i, &hl_emlrtRTEI);
  k = dstYIntrinsic->size[0] * dstYIntrinsic->size[1];
  for (i = 0; i < k; i++) {
    r->data[i] = M[4] * dstYIntrinsic->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])v->size, *(int32_T (*)[2])r->size,
    &w_emlrtECI, &c_st);
  k = v->size[0] * v->size[1];
  for (i = 0; i < k; i++) {
    v->data[i] = (v->data[i] + r->data[i]) + M[5];
  }

  emxFree_real_T(&r);
  k = w->size[0] * w->size[1];
  for (i = 0; i < k; i++) {
    w->data[i] *= M[6];
  }

  k = dstYIntrinsic->size[0] * dstYIntrinsic->size[1];
  for (i = 0; i < k; i++) {
    dstYIntrinsic->data[i] *= M[7];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])w->size, *(int32_T (*)[2])
    dstYIntrinsic->size, &v_emlrtECI, &c_st);
  k = w->size[0] * w->size[1];
  for (i = 0; i < k; i++) {
    w->data[i] = (w->data[i] + dstYIntrinsic->data[i]) + M[8];
  }

  emxFree_real_T(&dstYIntrinsic);
  d_st.site = &sq_emlrtRSI;
  b_varargin_1[0] = (uint32_T)u->size[0];
  varargin_2[0] = (uint32_T)w->size[0];
  b_varargin_1[1] = (uint32_T)u->size[1];
  varargin_2[1] = (uint32_T)w->size[1];
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ob_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  k = u->size[0] * u->size[1];
  for (i = 0; i < k; i++) {
    u->data[i] /= w->data[i];
  }

  d_st.site = &tq_emlrtRSI;
  b_varargin_1[0] = (uint32_T)v->size[0];
  varargin_2[0] = (uint32_T)w->size[0];
  b_varargin_1[1] = (uint32_T)v->size[1];
  varargin_2[1] = (uint32_T)w->size[1];
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ob_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  k = v->size[0] * v->size[1];
  for (i = 0; i < k; i++) {
    v->data[i] /= w->data[i];
  }

  emxFree_real_T(&w);
  c_st.site = &oq_emlrtRSI;
  d_st.site = &uq_emlrtRSI;
  b_varargin_1[0] = (uint32_T)u->size[0];
  varargin_2[0] = (uint32_T)v->size[0];
  b_varargin_1[1] = (uint32_T)u->size[1];
  varargin_2[1] = (uint32_T)v->size[1];
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &xb_emlrtRTEI,
      "images:spatialref:invalidXYPoint", "images:spatialref:invalidXYPoint", 6,
      4, 6, "xWorld", 4, 6, "yWorld");
  }

  k = u->size[0] * u->size[1];
  for (i = 0; i < k; i++) {
    u->data[i] = (u->data[i] - 0.5) + 0.5;
  }

  k = v->size[0] * v->size[1];
  for (i = 0; i < k; i++) {
    v->data[i] = (v->data[i] - 0.5) + 0.5;
  }

  c_st.site = &pq_emlrtRSI;
  d_st.site = &vq_emlrtRSI;
  e_st.site = &ye_emlrtRSI;
  f_st.site = &yb_emlrtRSI;
  p = true;
  i = u->size[0] * u->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if (!muDoubleScalarIsNaN(u->data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "X");
  }

  e_st.site = &af_emlrtRSI;
  f_st.site = &yb_emlrtRSI;
  p = true;
  i = v->size[0] * v->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if (!muDoubleScalarIsNaN(v->data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:interp2d:expectedNonNaN", 3, 4, 1, "Y");
  }

  b_varargin_1[0] = (uint32_T)u->size[0];
  varargin_2[0] = (uint32_T)v->size[0];
  b_varargin_1[1] = (uint32_T)u->size[1];
  varargin_2[1] = (uint32_T)v->size[1];
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((int32_T)b_varargin_1[k] != (int32_T)varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  p = (int32_T)b_p;
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &x_emlrtRTEI,
      "images:interp2d:inconsistentXYSize", "images:interp2d:inconsistentXYSize",
      0);
  }

  e_st.site = &bf_emlrtRSI;
  i = outputImage->size[0] * outputImage->size[1];
  outputImage->size[0] = u->size[0];
  outputImage->size[1] = u->size[1];
  emxEnsureCapacity_real_T(&e_st, outputImage, i, &af_emlrtRTEI);
  fillValues = 0.0;
  b_outputImage[0] = u->size[0];
  b_outputImage[1] = u->size[1];
  b_dv[0] = dv1[0];
  b_dv[1] = dv1[1];
  b_dv[2] = dv1[2];
  imterp2d64f_real64(varargin_1, b_dv, &v->data[0], &u->data[0], b_outputImage,
                     2.0, true, &fillValues, &outputImage->data[0]);
  emxFree_real_T(&v);
  emxFree_real_T(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (imwarp.c) */
