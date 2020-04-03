/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwtraceboundary.c
 *
 * Code generation for function 'bwtraceboundary'
 *
 */

/* Include files */
#include "bwtraceboundary.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "mwmathutil.h"
#include "padarray.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo nk_emlrtRSI = { 8,  /* lineNo */
  "bwtraceboundary",                   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo ok_emlrtRSI = { 10, /* lineNo */
  "bwtraceboundary",                   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo pk_emlrtRSI = { 347,/* lineNo */
  "parseInputs",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo qk_emlrtRSI = { 359,/* lineNo */
  "parseInputs",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo rk_emlrtRSI = { 29, /* lineNo */
  "traceBoundary",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo sk_emlrtRSI = { 105,/* lineNo */
  "traceBoundary",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo tk_emlrtRSI = { 111,/* lineNo */
  "traceBoundary",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtRSInfo uk_emlrtRSI = { 112,/* lineNo */
  "traceBoundary",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

static emlrtMCInfo d_emlrtMCI = { 231, /* lineNo */
  1,                                   /* colNo */
  "setNextSearchDirection",            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  295,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  294,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  317,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  271,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  264,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  8,                                   /* iLast */
  262,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 315, /* lineNo */
  33,                                  /* colNo */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  198,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "setNextSearchDirection",            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  249,                                 /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  138,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "isBoundaryPixel",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  4,                                   /* colNo */
  "",                                  /* aName */
  "isBoundaryPixel",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo kb_emlrtRTEI = { 26,/* lineNo */
  1,                                   /* colNo */
  "traceBoundary",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 119,/* lineNo */
  1,                                   /* colNo */
  "traceBoundary",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 316,/* lineNo */
  11,                                  /* colNo */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  317,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  318,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "traceBoundaryImage",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo rh_emlrtRTEI = { 352,/* lineNo */
  10,                                  /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo sh_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo th_emlrtRTEI = { 248,/* lineNo */
  1,                                   /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = { 112,/* lineNo */
  9,                                   /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = { 309,/* lineNo */
  20,                                  /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = { 309,/* lineNo */
  9,                                   /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = { 12,/* lineNo */
  14,                                  /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = { 244,/* lineNo */
  1,                                   /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = { 29,/* lineNo */
  20,                                  /* colNo */
  "bwtraceboundary",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pName */
};

static emlrtRSInfo yq_emlrtRSI = { 231,/* lineNo */
  "setNextSearchDirection",            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwtraceboundary.m"/* pathName */
};

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static void traceBoundary(const emlrtStack *sp, const emxArray_boolean_T *bw,
  const real_T P[2], emxArray_real_T *B);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

static void traceBoundary(const emlrtStack *sp, const emxArray_boolean_T *bw,
  const real_T P[2], emxArray_real_T *B)
{
  int32_T numRows;
  real_T maxNumPoints;
  emxArray_uint8_T *bwPadImage;
  emxArray_boolean_T *r;
  int32_T i;
  int32_T checkDir;
  real_T idx;
  real_T fOffsets[8];
  real_T fVOffsets[8];
  boolean_T tf;
  int32_T i1;
  boolean_T exitg1;
  int32_T nextSearchDir;
  int32_T i2;
  int32_T direction;
  int32_T currentCircIdx;
  emxArray_real_T *fScratch;
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 42 };

  static const char_T u[42] = { 'U', 'n', 'a', 'b', 'l', 'e', ' ', 't', 'o', ' ',
    'd', 'e', 't', 'e', 'r', 'm', 'i', 'n', 'e', ' ', 'v', 'a', 'l', 'i', 'd',
    ' ', 's', 'e', 'a', 'r', 'c', 'h', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n' };

  real_T numPixels;
  emxArray_real_T *b_fScratch;
  boolean_T foundNextPixel;
  boolean_T guard1 = false;
  static const int8_T iv1[8] = { 8, 8, 2, 2, 4, 4, 6, 6 };

  real_T neighbor;
  static const int8_T iv2[8] = { 2, 3, 4, 5, 6, 7, 8, 1 };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  numRows = bw->size[0];
  maxNumPoints = 2.0 * (real_T)bw->size[0] * (real_T)bw->size[1] + 2.0;
  if ((P[0] > bw->size[0]) || (P[1] > bw->size[1])) {
    emlrtErrorWithMessageIdR2018a(sp, &kb_emlrtRTEI,
      "images:bwtraceboundary:codegenStartingOutsideBW",
      "images:bwtraceboundary:codegenStartingOutsideBW", 0);
  }

  emxInit_uint8_T(sp, &bwPadImage, 2, &sh_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r, 2, &ai_emlrtRTEI, true);
  st.site = &rk_emlrtRSI;
  padarray(&st, bw, r);
  i = bwPadImage->size[0] * bwPadImage->size[1];
  bwPadImage->size[0] = r->size[0];
  bwPadImage->size[1] = r->size[1];
  emxEnsureCapacity_uint8_T(sp, bwPadImage, i, &sh_emlrtRTEI);
  checkDir = r->size[0] * r->size[1];
  for (i = 0; i < checkDir; i++) {
    bwPadImage->data[i] = r->data[i];
  }

  emxFree_boolean_T(&r);
  idx = (P[1] * ((real_T)bw->size[0] + 2.0) + P[0]) + 1.0;
  fOffsets[0] = -1.0;
  fOffsets[1] = ((real_T)bw->size[0] + 2.0) - 1.0;
  fOffsets[2] = (real_T)bw->size[0] + 2.0;
  fOffsets[3] = ((real_T)bw->size[0] + 2.0) + 1.0;
  fOffsets[4] = 1.0;
  fOffsets[5] = -((real_T)bw->size[0] + 2.0) + 1.0;
  fOffsets[6] = -((real_T)bw->size[0] + 2.0);
  fOffsets[7] = -((real_T)bw->size[0] + 2.0) - 1.0;
  fVOffsets[0] = -1.0;
  fVOffsets[1] = (real_T)bw->size[0] + 2.0;
  fVOffsets[2] = 1.0;
  fVOffsets[3] = -((real_T)bw->size[0] + 2.0);
  st.site = &sk_emlrtRSI;
  tf = false;
  i = bwPadImage->size[0] * bwPadImage->size[1];
  i1 = (int32_T)idx;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &x_emlrtBCI, &st);
  }

  if ((int8_T)bwPadImage->data[i1 - 1] != 0) {
    checkDir = 0;
    exitg1 = false;
    while ((!exitg1) && (checkDir < 4)) {
      i = bwPadImage->size[0] * bwPadImage->size[1];
      i2 = (int32_T)(idx + fVOffsets[checkDir]);
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &w_emlrtBCI, &st);
      }

      if ((int8_T)bwPadImage->data[i2 - 1] == 0) {
        tf = true;
        exitg1 = true;
      } else {
        checkDir++;
      }
    }
  }

  if (tf) {
    st.site = &tk_emlrtRSI;
    tf = false;
    nextSearchDir = 0;
    direction = 0;
    exitg1 = false;
    while ((!exitg1) && (direction < 8)) {
      currentCircIdx = (int32_T)muDoubleScalarRem((real_T)direction + 6.0, 8.0);
      checkDir = currentCircIdx + -1;
      if (currentCircIdx + -1 < 0) {
        checkDir = 7;
      }

      if (checkDir == 0) {
        checkDir = 0;
      } else {
        checkDir = (int32_T)muDoubleScalarRem(checkDir, 8.0);
        if (checkDir == 0) {
          checkDir = 0;
        }
      }

      i = bwPadImage->size[0] * bwPadImage->size[1];
      i2 = (int32_T)(idx + fOffsets[checkDir]);
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &u_emlrtBCI, &st);
      }

      if ((int8_T)bwPadImage->data[i2 - 1] == 0) {
        tf = true;
        nextSearchDir = currentCircIdx + 1;
        exitg1 = true;
      } else {
        direction++;
      }
    }

    if (!tf) {
      y = NULL;
      m = emlrtCreateCharArray(2, iv);
      emlrtInitCharArrayR2013a(&st, 42, m, &u[0]);
      emlrtAssign(&y, m);
      b_st.site = &yq_emlrtRSI;
      error(&b_st, y, &d_emlrtMCI);
    }

    emxInit_real_T(&st, &fScratch, 1, &yh_emlrtRTEI, true);
    st.site = &uk_emlrtRSI;
    numPixels = 1.0;
    i = fScratch->size[0];
    fScratch->size[0] = 1;
    emxEnsureCapacity_real_T(&st, fScratch, i, &th_emlrtRTEI);
    fScratch->data[0] = idx;
    i = bwPadImage->size[0] * bwPadImage->size[1];
    if (i1 > i) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &v_emlrtBCI, &st);
    }

    bwPadImage->data[i1 - 1] = 2U;
    tf = false;
    currentCircIdx = -1;
    emxInit_real_T(&st, &b_fScratch, 1, &vh_emlrtRTEI, true);
    while (!tf) {
      direction = nextSearchDir;
      foundNextPixel = false;
      checkDir = 0;
      guard1 = false;
      exitg1 = false;
      while ((!exitg1) && (checkDir < 8)) {
        if ((direction < 1) || (direction > 8)) {
          emlrtDynamicBoundsCheckR2012b(direction, 1, 8, &t_emlrtBCI, &st);
        }

        neighbor = idx + fOffsets[direction - 1];
        i = bwPadImage->size[0] * bwPadImage->size[1];
        i1 = (int32_T)neighbor;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &s_emlrtBCI, &st);
        }

        if ((int8_T)bwPadImage->data[i1 - 1] != 0) {
          i = bwPadImage->size[0] * bwPadImage->size[1];
          i2 = (int32_T)idx;
          if ((i2 < 1) || (i2 > i)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i, &r_emlrtBCI, &st);
          }

          if (((int8_T)bwPadImage->data[i2 - 1] == 2) && (currentCircIdx == -1))
          {
            currentCircIdx = direction;
            guard1 = true;
          } else {
            i = bwPadImage->size[0] * bwPadImage->size[1];
            if (i2 > i) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, i, &q_emlrtBCI, &st);
            }

            if (((int8_T)bwPadImage->data[i2 - 1] == 2) && (currentCircIdx ==
                 direction)) {
              tf = true;
              foundNextPixel = true;
            } else {
              guard1 = true;
            }
          }

          exitg1 = true;
        } else {
          direction = iv2[direction - 1];
          checkDir++;
          guard1 = false;
        }
      }

      if (guard1) {
        nextSearchDir = iv1[direction - 1];
        foundNextPixel = true;
        numPixels++;
        i = fScratch->size[0];
        i2 = fScratch->size[0];
        fScratch->size[0]++;
        emxEnsureCapacity_real_T(&st, fScratch, i2, &xh_emlrtRTEI);
        fScratch->data[i] = neighbor;
        if (numPixels == maxNumPoints) {
          tf = true;
        } else {
          i = bwPadImage->size[0] * bwPadImage->size[1];
          if (i1 > i) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &n_emlrtBCI, &st);
          }

          if ((int8_T)bwPadImage->data[i1 - 1] != 2) {
            i = bwPadImage->size[0] * bwPadImage->size[1];
            if (i1 > i) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &m_emlrtBCI, &st);
            }

            bwPadImage->data[i1 - 1] = 3U;
          }

          idx = neighbor;
        }
      }

      if (!foundNextPixel) {
        numPixels = 2.0;
        i = b_fScratch->size[0];
        b_fScratch->size[0] = fScratch->size[0] + fScratch->size[0];
        emxEnsureCapacity_real_T(&st, b_fScratch, i, &vh_emlrtRTEI);
        checkDir = fScratch->size[0];
        for (i = 0; i < checkDir; i++) {
          b_fScratch->data[i] = fScratch->data[i];
        }

        checkDir = fScratch->size[0];
        for (i = 0; i < checkDir; i++) {
          b_fScratch->data[i + fScratch->size[0]] = fScratch->data[i];
        }

        i = fScratch->size[0];
        fScratch->size[0] = b_fScratch->size[0];
        emxEnsureCapacity_real_T(&st, fScratch, i, &wh_emlrtRTEI);
        checkDir = b_fScratch->size[0];
        for (i = 0; i < checkDir; i++) {
          fScratch->data[i] = b_fScratch->data[i];
        }

        tf = true;
      }
    }

    emxFree_real_T(&b_fScratch);
    i = (int32_T)numPixels;
    if (numPixels != i) {
      emlrtIntegerCheckR2012b(numPixels, &e_emlrtDCI, &st);
    }

    i1 = B->size[0] * B->size[1];
    B->size[0] = i;
    B->size[1] = 2;
    emxEnsureCapacity_real_T(&st, B, i1, &uh_emlrtRTEI);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, numPixels, mxDOUBLE_CLASS, (int32_T)
      numPixels, &mb_emlrtRTEI, &st);
    for (checkDir = 0; checkDir < i; checkDir++) {
      i1 = checkDir + 1;
      if ((i1 < 1) || (i1 > fScratch->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, fScratch->size[0], &y_emlrtBCI, &st);
      }

      if (muDoubleScalarIsNaN(fScratch->data[checkDir] - 1.0)) {
        maxNumPoints = rtNaN;
      } else if (fScratch->data[checkDir] - 1.0 == 0.0) {
        maxNumPoints = 0.0;
      } else {
        maxNumPoints = muDoubleScalarRem(fScratch->data[checkDir] - 1.0, (real_T)
          numRows + 2.0);
      }

      i1 = B->size[0] << 1;
      i2 = (int32_T)(checkDir + 1U);
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &p_emlrtBCI, &st);
      }

      B->data[i2 - 1] = maxNumPoints;
      i1 = checkDir + 1;
      if ((i1 < 1) || (i1 > fScratch->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, fScratch->size[0], &ab_emlrtBCI,
          &st);
      }

      i1 = B->size[0] << 1;
      i2 = (int32_T)(numPixels + ((real_T)checkDir + 1.0));
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &o_emlrtBCI, &st);
      }

      B->data[i2 - 1] = muDoubleScalarFloor((fScratch->data[checkDir] - 1.0) /
        ((real_T)numRows + 2.0));
    }

    emxFree_real_T(&fScratch);
  } else {
    B->size[0] = 0;
    B->size[1] = 2;
  }

  emxFree_uint8_T(&bwPadImage);
  if (B->size[0] > 2.0 * (real_T)bw->size[0] * (real_T)bw->size[1] + 1.0) {
    emlrtErrorWithMessageIdR2018a(sp, &lb_emlrtRTEI,
      "images:bwtraceboundary:failedTrace", "images:bwtraceboundary:failedTrace",
      0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void bwtraceboundary(const emlrtStack *sp, const emxArray_uint8_T *varargin_1,
                     const real_T varargin_2[2], emxArray_real_T *B)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emxArray_boolean_T *b_varargin_1;
  int32_T loop_ub;
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
  st.site = &nk_emlrtRSI;
  b_st.site = &pk_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonempty",
      "MATLAB:bwtraceboundary:expectedNonempty", 3, 4, 19, "input number 1, BW,");
  }

  b_st.site = &qk_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(varargin_2[k])) && (!muDoubleScalarIsNaN
         (varargin_2[k])) && (muDoubleScalarFloor(varargin_2[k]) == varargin_2[k]))
    {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedInteger",
      "MATLAB:bwtraceboundary:expectedInteger", 3, 4, 18, "input number 2, P,");
  }

  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_2[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedPositive",
      "MATLAB:bwtraceboundary:expectedPositive", 3, 4, 18, "input number 2, P,");
  }

  emxInit_boolean_T(&c_st, &b_varargin_1, 2, &rh_emlrtRTEI, true);
  k = b_varargin_1->size[0] * b_varargin_1->size[1];
  b_varargin_1->size[0] = varargin_1->size[0];
  b_varargin_1->size[1] = varargin_1->size[1];
  emxEnsureCapacity_boolean_T(sp, b_varargin_1, k, &rh_emlrtRTEI);
  loop_ub = varargin_1->size[0] * varargin_1->size[1];
  for (k = 0; k < loop_ub; k++) {
    b_varargin_1->data[k] = (varargin_1->data[k] != 0);
  }

  st.site = &ok_emlrtRSI;
  traceBoundary(&st, b_varargin_1, varargin_2, B);
  emxFree_boolean_T(&b_varargin_1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bwtraceboundary.c) */
