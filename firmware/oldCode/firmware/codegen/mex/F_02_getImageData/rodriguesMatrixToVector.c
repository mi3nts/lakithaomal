/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rodriguesMatrixToVector.c
 *
 * Code generation for function 'rodriguesMatrixToVector'
 *
 */

/* Include files */
#include "rodriguesMatrixToVector.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hf_emlrtRSI = { 32, /* lineNo */
  "rodriguesMatrixToVector",           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 41, /* lineNo */
  "rodriguesMatrixToVector",           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 98, /* lineNo */
  "rodriguesMatrixToVector",           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 12, /* lineNo */
  "svd",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo lf_emlrtRSI = { 25, /* lineNo */
  "svd",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 33, /* lineNo */
  "svd",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 29, /* lineNo */
  "anyNonFinite",                      /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/anyNonFinite.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 44, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 101,/* lineNo */
  "callLAPACK",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 34, /* lineNo */
  "xgesvd",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRSInfo yg_emlrtRSI = { 113,/* lineNo */
  "computeRotationVectorForAnglesCloseToPi",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m"/* pathName */
};

static emlrtRSInfo ah_emlrtRSI = { 119,/* lineNo */
  "computeRotationVectorForAnglesCloseToPi",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 16, /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  119,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "computeRotationVectorForAnglesCloseToPi",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  119,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "computeRotationVectorForAnglesCloseToPi",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/rodriguesMatrixToVector.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void rodriguesMatrixToVector(const emlrtStack *sp, real_T rotationMatrix[9],
  real_T rotationVector[3])
{
  boolean_T p;
  int32_T k;
  real_T b_rotationMatrix[9];
  real_T At[9];
  real_T S[3];
  real_T V[9];
  int32_T i;
  real_T t;
  real_T absxk;
  real_T theta;
  real_T s;
  int32_T idx;
  boolean_T exitg1;
  int32_T iidx;
  int32_T r;
  int32_T i1;
  int32_T i2;
  real_T y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &kf_emlrtRSI;
  c_st.site = &nf_emlrtRSI;
  d_st.site = &of_emlrtRSI;
  p = true;
  for (k = 0; k < 9; k++) {
    if ((!p) || (muDoubleScalarIsInf(rotationMatrix[k]) || muDoubleScalarIsNaN
                 (rotationMatrix[k]))) {
      p = false;
    }
  }

  if (p) {
    b_st.site = &lf_emlrtRSI;
    c_st.site = &qf_emlrtRSI;
    d_st.site = &rf_emlrtRSI;
    memcpy(&b_rotationMatrix[0], &rotationMatrix[0], 9U * sizeof(real_T));
    e_st.site = &sf_emlrtRSI;
    xzsvdc(&e_st, b_rotationMatrix, At, S, V);
  } else {
    b_st.site = &mf_emlrtRSI;
    c_st.site = &qf_emlrtRSI;
    d_st.site = &rf_emlrtRSI;
    memset(&b_rotationMatrix[0], 0, 9U * sizeof(real_T));
    e_st.site = &sf_emlrtRSI;
    xzsvdc(&e_st, b_rotationMatrix, At, S, V);
    for (i = 0; i < 9; i++) {
      At[i] = rtNaN;
      V[i] = rtNaN;
    }
  }

  for (i = 0; i < 3; i++) {
    absxk = At[i + 3];
    s = At[i + 6];
    for (idx = 0; idx < 3; idx++) {
      rotationMatrix[i + 3 * idx] = (At[i] * V[idx] + absxk * V[idx + 3]) + s *
        V[idx + 6];
    }
  }

  t = (rotationMatrix[0] + rotationMatrix[4]) + rotationMatrix[8];
  theta = (t - 1.0) / 2.0;
  st.site = &if_emlrtRSI;
  if ((theta < -1.0) || (theta > 1.0)) {
    emlrtErrorWithMessageIdR2018a(&st, &bb_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "acos");
  }

  theta = muDoubleScalarAcos(theta);
  rotationVector[0] = rotationMatrix[5] - rotationMatrix[7];
  rotationVector[1] = rotationMatrix[6] - rotationMatrix[2];
  rotationVector[2] = rotationMatrix[1] - rotationMatrix[3];
  absxk = muDoubleScalarSin(theta);
  if (absxk >= 0.0001) {
    s = 1.0 / (2.0 * absxk);
    rotationVector[0] = theta * (rotationVector[0] * s);
    rotationVector[1] = theta * (rotationVector[1] * s);
    rotationVector[2] = theta * (rotationVector[2] * s);
  } else if (t - 1.0 > 0.0) {
    s = 0.5 - (t - 3.0) / 12.0;
    rotationVector[0] *= s;
    rotationVector[1] *= s;
    rotationVector[2] *= s;
  } else {
    st.site = &jf_emlrtRSI;
    b_st.site = &yg_emlrtRSI;
    S[0] = rotationMatrix[0];
    S[1] = rotationMatrix[4];
    S[2] = rotationMatrix[8];
    c_st.site = &bh_emlrtRSI;
    d_st.site = &ch_emlrtRSI;
    if (!muDoubleScalarIsNaN(rotationMatrix[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(S[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      iidx = 0;
    } else {
      s = S[idx - 1];
      iidx = idx - 1;
      i = idx + 1;
      for (k = i; k < 4; k++) {
        absxk = S[k - 1];
        if (s < absxk) {
          s = absxk;
          iidx = k - 1;
        }
      }
    }

    idx = iidx + 1;
    r = (int32_T)muDoubleScalarRem(idx, 3.0);
    k = (int32_T)muDoubleScalarRem((real_T)idx + 1.0, 3.0);
    b_st.site = &ah_emlrtRSI;
    i = k + 1;
    if (i > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &c_emlrtBCI, &b_st);
    }

    idx = k + 1;
    if (idx > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &c_emlrtBCI, &b_st);
    }

    i1 = r + 1;
    if (i1 > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &d_emlrtBCI, &b_st);
    }

    i2 = r + 1;
    if (i2 > 3) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &d_emlrtBCI, &b_st);
    }

    s = ((rotationMatrix[iidx + 3 * iidx] - rotationMatrix[(i2 + 3 * (i1 - 1)) -
          1]) - rotationMatrix[(idx + 3 * (i - 1)) - 1]) + 1.0;
    if (s < 0.0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &ab_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    s = muDoubleScalarSqrt(s);
    rotationVector[0] = 0.0;
    rotationVector[1] = 0.0;
    rotationVector[2] = 0.0;
    rotationVector[iidx] = s / 2.0;
    rotationVector[r] = (rotationMatrix[r + 3 * iidx] + rotationMatrix[iidx + 3 *
                         r]) / (2.0 * s);
    rotationVector[k] = (rotationMatrix[k + 3 * iidx] + rotationMatrix[iidx + 3 *
                         k]) / (2.0 * s);
    s = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(rotationVector[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      s = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    absxk = muDoubleScalarAbs(rotationVector[1]);
    if (absxk > s) {
      t = s / absxk;
      y = y * t * t + 1.0;
      s = absxk;
    } else {
      t = absxk / s;
      y += t * t;
    }

    absxk = muDoubleScalarAbs(rotationVector[2]);
    if (absxk > s) {
      t = s / absxk;
      y = y * t * t + 1.0;
      s = absxk;
    } else {
      t = absxk / s;
      y += t * t;
    }

    y = s * muDoubleScalarSqrt(y);
    rotationVector[0] = theta * rotationVector[0] / y;
    rotationVector[1] = theta * rotationVector[1] / y;
    rotationVector[2] = theta * rotationVector[2] / y;
  }
}

/* End of code generation (rodriguesMatrixToVector.c) */
