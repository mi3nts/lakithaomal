/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * distortPoints.c
 *
 * Code generation for function 'distortPoints'
 *
 */

/* Include files */
#include "distortPoints.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "power.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo le_emlrtRSI = { 22, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 39, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 40, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 43, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtRSInfo pe_emlrtRSI = { 44, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtRSInfo qe_emlrtRSI = { 45, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtRSInfo re_emlrtRSI = { 53, /* lineNo */
  "distortPoints",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pathName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  22,                                  /* lineNo */
  6,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  24,                                  /* lineNo */
  6,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  38,                                  /* lineNo */
  13,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  47,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  16,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  24,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  16,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { 2,   /* nDims */
  44,                                  /* lineNo */
  48,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  44,                                  /* lineNo */
  29,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  48,                                  /* lineNo */
  20,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ae_emlrtRTEI = { 15,/* lineNo */
  18,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo be_emlrtRTEI = { 18,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo de_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = { 34,/* lineNo */
  21,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = { 34,/* lineNo */
  33,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo he_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = { 39,/* lineNo */
  16,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo je_emlrtRTEI = { 39,/* lineNo */
  39,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = { 43,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo le_emlrtRTEI = { 44,/* lineNo */
  68,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo me_emlrtRTEI = { 44,/* lineNo */
  48,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = { 45,/* lineNo */
  5,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = { 44,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = { 48,/* lineNo */
  20,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = { 49,/* lineNo */
  5,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo re_emlrtRTEI = { 50,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo se_emlrtRTEI = { 53,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo te_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = { 22,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = { 34,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo we_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = { 1,/* lineNo */
  28,                                  /* colNo */
  "distortPoints",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/distortPoints.m"/* pName */
};

/* Function Definitions */
void b_distortPoints(F_02_getImageDataStackData *SD, const real_T points[614400],
                     const real_T intrinsicMatrix[9], const real_T
                     radialDistortion[2], const real_T tangentialDistortion[2],
                     real_T distortedPoints[614400])
{
  real_T center[2];
  int32_T k;
  real_T a;
  int32_T b_k;
  real_T b_a;
  int32_T centeredPoints_tmp;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  center[0] = intrinsicMatrix[2];
  center[1] = intrinsicMatrix[5];
  for (k = 0; k < 2; k++) {
    for (b_k = 0; b_k < 307200; b_k++) {
      centeredPoints_tmp = b_k + 307200 * k;
      SD->u1.f1.centeredPoints[centeredPoints_tmp] = points[centeredPoints_tmp]
        - center[k];
    }
  }

  a = 2.0 * tangentialDistortion[0];
  b_a = 2.0 * tangentialDistortion[1];
  for (k = 0; k < 307200; k++) {
    d = SD->u1.f1.centeredPoints[k + 307200] / intrinsicMatrix[4];
    d1 = SD->u1.f1.centeredPoints[k] / intrinsicMatrix[0];
    d2 = d1 * d1;
    d3 = d * d;
    d4 = d2 + d3;
    d5 = d4 * d4;
    d5 = (radialDistortion[0] * d4 + radialDistortion[1] * d5) + 0.0 * (d4 * d5);
    d6 = d1 * d;
    SD->u1.f1.distortedNormalizedPoints[k] = d1 + d1 * d5;
    SD->u1.f1.distortedNormalizedPoints[k + 307200] = d + d * d5;
    SD->u1.f1.centeredPoints[k] = a * d6 + tangentialDistortion[1] * (d4 + 2.0 *
      d2);
    SD->u1.f1.centeredPoints[k + 307200] = tangentialDistortion[0] * (d4 + 2.0 *
      d3) + b_a * d6;
  }

  for (k = 0; k < 614400; k++) {
    SD->u1.f1.distortedNormalizedPoints[k] += SD->u1.f1.centeredPoints[k];
  }

  for (k = 0; k < 307200; k++) {
    a = SD->u1.f1.distortedNormalizedPoints[k + 307200];
    distortedPoints[k] = (SD->u1.f1.distortedNormalizedPoints[k] *
                          intrinsicMatrix[0] + intrinsicMatrix[2]) +
      intrinsicMatrix[1] * a;
    distortedPoints[k + 307200] = a * intrinsicMatrix[4] + intrinsicMatrix[5];
  }
}

void distortPoints(const emlrtStack *sp, const emxArray_real_T *points, const
                   real_T intrinsicMatrix[9], const real_T radialDistortion[2],
                   const real_T tangentialDistortion[2], emxArray_real_T
                   *distortedPoints)
{
  emxArray_real_T *centeredPoints;
  int32_T i;
  int32_T acoef;
  emxArray_real_T *yNorm;
  int32_T k;
  emxArray_real_T *xNorm;
  emxArray_real_T *r2;
  emxArray_real_T *dxTangential;
  emxArray_real_T *r4;
  emxArray_real_T *alpha;
  emxArray_real_T *xyProduct;
  real_T a;
  emxArray_real_T *r;
  emxArray_real_T *r1;
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
  emxInit_real_T(sp, &centeredPoints, 2, &te_emlrtRTEI, true);
  i = centeredPoints->size[0] * centeredPoints->size[1];
  centeredPoints->size[0] = points->size[0];
  centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, centeredPoints, i, &ae_emlrtRTEI);
  if (points->size[0] != 0) {
    acoef = (points->size[0] != 1);
    i = points->size[0] - 1;
    for (k = 0; k <= i; k++) {
      centeredPoints->data[k] = points->data[acoef * k] - intrinsicMatrix[2];
    }

    i = centeredPoints->size[0] - 1;
    for (k = 0; k <= i; k++) {
      centeredPoints->data[k + centeredPoints->size[0]] = points->data[acoef * k
        + points->size[0]] - intrinsicMatrix[5];
    }
  }

  emxInit_real_T(sp, &yNorm, 1, &be_emlrtRTEI, true);
  acoef = centeredPoints->size[0];
  i = yNorm->size[0];
  yNorm->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(sp, yNorm, i, &be_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    yNorm->data[i] = centeredPoints->data[i + centeredPoints->size[0]] /
      intrinsicMatrix[4];
  }

  emxInit_real_T(sp, &xNorm, 1, &ce_emlrtRTEI, true);
  acoef = centeredPoints->size[0];
  i = xNorm->size[0];
  xNorm->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(sp, xNorm, i, &ce_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    xNorm->data[i] = centeredPoints->data[i] / intrinsicMatrix[0];
  }

  emxInit_real_T(sp, &r2, 1, &ue_emlrtRTEI, true);
  emxInit_real_T(sp, &dxTangential, 1, &we_emlrtRTEI, true);
  st.site = &le_emlrtRSI;
  power(&st, xNorm, r2);
  st.site = &le_emlrtRSI;
  power(&st, yNorm, dxTangential);
  if (r2->size[0] != dxTangential->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], dxTangential->size[0], &g_emlrtECI, sp);
  }

  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r2->data[i] += dxTangential->data[i];
  }

  emxInit_real_T(sp, &r4, 1, &de_emlrtRTEI, true);
  i = r4->size[0];
  r4->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(sp, r4, i, &de_emlrtRTEI);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] = r2->data[i] * r2->data[i];
  }

  if (r2->size[0] != r4->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], r4->size[0], &h_emlrtECI, sp);
  }

  emxInit_real_T(sp, &alpha, 1, &ve_emlrtRTEI, true);
  i = alpha->size[0];
  alpha->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(sp, alpha, i, &ee_emlrtRTEI);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    alpha->data[i] = radialDistortion[0] * r2->data[i];
  }

  i = dxTangential->size[0];
  dxTangential->size[0] = r4->size[0];
  emxEnsureCapacity_real_T(sp, dxTangential, i, &fe_emlrtRTEI);
  acoef = r4->size[0];
  for (i = 0; i < acoef; i++) {
    dxTangential->data[i] = radialDistortion[1] * r4->data[i];
  }

  if (alpha->size[0] != dxTangential->size[0]) {
    emlrtSizeEqCheck1DR2012b(alpha->size[0], dxTangential->size[0], &i_emlrtECI,
      sp);
  }

  i = r4->size[0];
  r4->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(sp, r4, i, &ge_emlrtRTEI);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] = 0.0 * (r2->data[i] * r4->data[i]);
  }

  if (alpha->size[0] != r4->size[0]) {
    emlrtSizeEqCheck1DR2012b(alpha->size[0], r4->size[0], &i_emlrtECI, sp);
  }

  acoef = alpha->size[0];
  for (i = 0; i < acoef; i++) {
    alpha->data[i] = (alpha->data[i] + dxTangential->data[i]) + r4->data[i];
  }

  if (xNorm->size[0] != yNorm->size[0]) {
    emlrtSizeEqCheck1DR2012b(xNorm->size[0], yNorm->size[0], &j_emlrtECI, sp);
  }

  emxInit_real_T(sp, &xyProduct, 1, &he_emlrtRTEI, true);
  i = xyProduct->size[0];
  xyProduct->size[0] = xNorm->size[0];
  emxEnsureCapacity_real_T(sp, xyProduct, i, &he_emlrtRTEI);
  acoef = xNorm->size[0];
  for (i = 0; i < acoef; i++) {
    xyProduct->data[i] = xNorm->data[i] * yNorm->data[i];
  }

  st.site = &me_emlrtRSI;
  power(&st, xNorm, r4);
  acoef = r4->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] *= 2.0;
  }

  if (r2->size[0] != r4->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], r4->size[0], &k_emlrtECI, sp);
  }

  a = 2.0 * tangentialDistortion[0];
  i = dxTangential->size[0];
  dxTangential->size[0] = xyProduct->size[0];
  emxEnsureCapacity_real_T(sp, dxTangential, i, &ie_emlrtRTEI);
  acoef = xyProduct->size[0];
  for (i = 0; i < acoef; i++) {
    dxTangential->data[i] = a * xyProduct->data[i];
  }

  i = r4->size[0];
  r4->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(sp, r4, i, &je_emlrtRTEI);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] = tangentialDistortion[1] * (r2->data[i] + r4->data[i]);
  }

  if (dxTangential->size[0] != r4->size[0]) {
    emlrtSizeEqCheck1DR2012b(dxTangential->size[0], r4->size[0], &l_emlrtECI, sp);
  }

  acoef = dxTangential->size[0];
  for (i = 0; i < acoef; i++) {
    dxTangential->data[i] += r4->data[i];
  }

  st.site = &ne_emlrtRSI;
  power(&st, yNorm, r4);
  acoef = r4->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] *= 2.0;
  }

  if (r2->size[0] != r4->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], r4->size[0], &m_emlrtECI, sp);
  }

  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r2->data[i] = tangentialDistortion[0] * (r2->data[i] + r4->data[i]);
  }

  a = 2.0 * tangentialDistortion[1];
  acoef = xyProduct->size[0];
  for (i = 0; i < acoef; i++) {
    xyProduct->data[i] *= a;
  }

  if (r2->size[0] != xyProduct->size[0]) {
    emlrtSizeEqCheck1DR2012b(r2->size[0], xyProduct->size[0], &n_emlrtECI, sp);
  }

  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r2->data[i] += xyProduct->data[i];
  }

  st.site = &oe_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  c_st.site = &ke_emlrtRSI;
  if (yNorm->size[0] != xNorm->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = centeredPoints->size[0] * centeredPoints->size[1];
  centeredPoints->size[0] = xNorm->size[0];
  centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, centeredPoints, i, &ke_emlrtRTEI);
  acoef = xNorm->size[0];
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i] = xNorm->data[i];
  }

  emxFree_real_T(&xNorm);
  acoef = yNorm->size[0];
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i + centeredPoints->size[0]] = yNorm->data[i];
  }

  emxFree_real_T(&yNorm);
  emxInit_real_T(&b_st, &r, 2, &xe_emlrtRTEI, true);
  st.site = &pe_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  i = r->size[0] * r->size[1];
  r->size[0] = alpha->size[0];
  r->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, r, i, &le_emlrtRTEI);
  acoef = alpha->size[0];
  for (i = 0; i < acoef; i++) {
    r->data[i] = alpha->data[i];
  }

  acoef = alpha->size[0];
  for (i = 0; i < acoef; i++) {
    r->data[i + r->size[0]] = alpha->data[i];
  }

  emxFree_real_T(&alpha);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])centeredPoints->size, *(int32_T (*)
    [2])r->size, &o_emlrtECI, sp);
  acoef = centeredPoints->size[0] * centeredPoints->size[1];
  i = r->size[0] * r->size[1];
  r->size[0] = centeredPoints->size[0];
  r->size[1] = 2;
  emxEnsureCapacity_real_T(sp, r, i, &me_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    r->data[i] *= centeredPoints->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])centeredPoints->size, *(int32_T (*)
    [2])r->size, &p_emlrtECI, sp);
  st.site = &qe_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  c_st.site = &ke_emlrtRSI;
  if (r2->size[0] != dxTangential->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T(&c_st, &r1, 2, &xe_emlrtRTEI, true);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = dxTangential->size[0];
  r1->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, r1, i, &ne_emlrtRTEI);
  acoef = dxTangential->size[0];
  for (i = 0; i < acoef; i++) {
    r1->data[i] = dxTangential->data[i];
  }

  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r1->data[i + r1->size[0]] = r2->data[i];
  }

  emxFree_real_T(&r2);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])centeredPoints->size, *(int32_T (*)
    [2])r1->size, &p_emlrtECI, sp);
  acoef = centeredPoints->size[0] * centeredPoints->size[1];
  i = centeredPoints->size[0] * centeredPoints->size[1];
  centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(sp, centeredPoints, i, &oe_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i] = (centeredPoints->data[i] + r->data[i]) + r1->
      data[i];
  }

  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  acoef = centeredPoints->size[0];
  i = xyProduct->size[0];
  xyProduct->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(sp, xyProduct, i, &pe_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    xyProduct->data[i] = centeredPoints->data[i] * intrinsicMatrix[0];
  }

  acoef = centeredPoints->size[0];
  i = dxTangential->size[0];
  dxTangential->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(sp, dxTangential, i, &qe_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    dxTangential->data[i] = intrinsicMatrix[1] * centeredPoints->data[i +
      centeredPoints->size[0]];
  }

  if (xyProduct->size[0] != dxTangential->size[0]) {
    emlrtSizeEqCheck1DR2012b(xyProduct->size[0], dxTangential->size[0],
      &q_emlrtECI, sp);
  }

  acoef = xyProduct->size[0];
  for (i = 0; i < acoef; i++) {
    xyProduct->data[i] = (xyProduct->data[i] + intrinsicMatrix[2]) +
      dxTangential->data[i];
  }

  emxFree_real_T(&dxTangential);
  acoef = centeredPoints->size[0];
  i = r4->size[0];
  r4->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(sp, r4, i, &re_emlrtRTEI);
  for (i = 0; i < acoef; i++) {
    r4->data[i] = centeredPoints->data[i + centeredPoints->size[0]] *
      intrinsicMatrix[4] + intrinsicMatrix[5];
  }

  emxFree_real_T(&centeredPoints);
  st.site = &re_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  c_st.site = &ke_emlrtRSI;
  if (r4->size[0] != xyProduct->size[0]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = distortedPoints->size[0] * distortedPoints->size[1];
  distortedPoints->size[0] = xyProduct->size[0];
  distortedPoints->size[1] = 2;
  emxEnsureCapacity_real_T(&b_st, distortedPoints, i, &se_emlrtRTEI);
  acoef = xyProduct->size[0];
  for (i = 0; i < acoef; i++) {
    distortedPoints->data[i] = xyProduct->data[i];
  }

  emxFree_real_T(&xyProduct);
  acoef = r4->size[0];
  for (i = 0; i < acoef; i++) {
    distortedPoints->data[i + distortedPoints->size[0]] = r4->data[i];
  }

  emxFree_real_T(&r4);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (distortPoints.c) */
