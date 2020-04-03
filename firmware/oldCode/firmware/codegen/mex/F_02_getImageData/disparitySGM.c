/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disparitySGM.c
 *
 * Code generation for function 'disparitySGM'
 *
 */

/* Include files */
#include "disparitySGM.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "cvstCG_disparitySGM.h"
#include "rt_nonfinite.h"
#include "sprintf.h"

/* Variable Definitions */
static emlrtRSInfo vo_emlrtRSI = { 92, /* lineNo */
  "disparitySGM",                      /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo wo_emlrtRSI = { 125,/* lineNo */
  "disparitySGM",                      /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo xo_emlrtRSI = { 145,/* lineNo */
  "parseInputs",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo yo_emlrtRSI = { 149,/* lineNo */
  "parseInputs",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo ap_emlrtRSI = { 18, /* lineNo */
  "validateImagePairForDisparity",     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/validateImagePairForDisparity.m"/* pathName */
};

static emlrtRSInfo bp_emlrtRSI = { 24, /* lineNo */
  "localValidate",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/validateImagePairForDisparity.m"/* pathName */
};

static emlrtRSInfo cp_emlrtRSI = { 25, /* lineNo */
  "localValidate",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/validateImagePairForDisparity.m"/* pathName */
};

static emlrtRSInfo dp_emlrtRSI = { 39, /* lineNo */
  "validateImageForDisparity",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/validateImageForDisparity.m"/* pathName */
};

static emlrtRSInfo ep_emlrtRSI = { 46, /* lineNo */
  "localValidate",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/validateImageForDisparity.m"/* pathName */
};

static emlrtRSInfo fp_emlrtRSI = { 160,/* lineNo */
  "parseOptionalInputs",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo gp_emlrtRSI = { 217,/* lineNo */
  "parseOptionalInputs_cg",            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo hp_emlrtRSI = { 276,/* lineNo */
  "checkDisparityRange",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo ip_emlrtRSI = { 278,/* lineNo */
  "checkDisparityRange",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo jp_emlrtRSI = { 280,/* lineNo */
  "checkDisparityRange",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo kp_emlrtRSI = { 279,/* lineNo */
  "checkDisparityRange",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pathName */
};

static emlrtRSInfo mp_emlrtRSI = { 66, /* lineNo */
  "disparitySGMBuildable/disparitySGMCompute",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pathName */
};

static emlrtRSInfo np_emlrtRSI = { 81, /* lineNo */
  "disparitySGMBuildable/disparitySGMCompute",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pathName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "localValidate",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+inputValidation/validateImagePairForDisparity.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 301,/* lineNo */
  35,                                  /* colNo */
  "errIf",                             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pName */
};

static emlrtRTEInfo rj_emlrtRTEI = { 125,/* lineNo */
  20,                                  /* colNo */
  "disparitySGM",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pName */
};

static emlrtRTEInfo sj_emlrtRTEI = { 100,/* lineNo */
  17,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo tj_emlrtRTEI = { 101,/* lineNo */
  17,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo uj_emlrtRTEI = { 125,/* lineNo */
  5,                                   /* colNo */
  "disparitySGM",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pName */
};

static emlrtRTEInfo vj_emlrtRTEI = { 47,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo wj_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo xj_emlrtRTEI = { 58,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo yj_emlrtRTEI = { 59,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo ak_emlrtRTEI = { 70,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo bk_emlrtRTEI = { 71,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo ck_emlrtRTEI = { 76,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo dk_emlrtRTEI = { 77,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo ek_emlrtRTEI = { 82,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo fk_emlrtRTEI = { 83,/* lineNo */
  13,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo gk_emlrtRTEI = { 103,/* lineNo */
  17,                                  /* colNo */
  "disparitySGMBuildable",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+buildable/disparitySGMBuildable.m"/* pName */
};

static emlrtRTEInfo hk_emlrtRTEI = { 280,/* lineNo */
  66,                                  /* colNo */
  "disparitySGM",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pName */
};

static emlrtRTEInfo ik_emlrtRTEI = { 1,/* lineNo */
  25,                                  /* colNo */
  "disparitySGM",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/disparitySGM.m"/* pName */
};

/* Function Definitions */
void disparitySGM(const emlrtStack *sp, const emxArray_uint8_T *I1, const
                  emxArray_uint8_T *I2, emxArray_real32_T *disparityMap)
{
  uint32_T imageSize[2];
  uint32_T varargin_2[2];
  boolean_T p;
  int32_T outSize_idx_1;
  boolean_T exitg1;
  boolean_T b_p;
  emxArray_char_T *varargin_1;
  emxArray_char_T *fr_emlrtRSI;
  emxArray_char_T *gr_emlrtRSI;
  emxArray_uint32_T *leftCT;
  emxArray_uint32_T *rightCT;
  int32_T i;
  int64_T i1;
  emxArray_int16_T *matchingCost;
  emxArray_int16_T *dirCostSum;
  emxArray_int16_T *oneRowMinDirCostBuf1;
  emxArray_int16_T *oneRowMinDirCostBuf2;
  emxArray_int16_T *oneRowDirCostBuf1;
  emxArray_int16_T *oneRowDirCostBuf2;
  emxArray_int16_T *tenRowDirCostBuf1;
  emxArray_int16_T *tenRowDirCostBuf2;
  emxArray_uint8_T *I1Transpose;
  cvstDisparitySGMStruct_T paramStruct;
  emxArray_uint8_T *I2Transpose;
  int32_T loop_ub;
  int32_T i2;
  emxArray_real32_T *outDispTranspose;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &vo_emlrtRSI;
  b_st.site = &xo_emlrtRSI;
  c_st.site = &ap_emlrtRSI;
  d_st.site = &bp_emlrtRSI;
  e_st.site = &dp_emlrtRSI;
  f_st.site = &ep_emlrtRSI;
  g_st.site = &yb_emlrtRSI;
  if ((I1->size[0] == 0) || (I1->size[1] == 0)) {
    emlrtErrorWithMessageIdR2018a(&g_st, &jb_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonempty",
      "MATLAB:validateImage:expectedNonempty", 3, 4, 2, "I1");
  }

  d_st.site = &cp_emlrtRSI;
  e_st.site = &dp_emlrtRSI;
  f_st.site = &ep_emlrtRSI;
  g_st.site = &yb_emlrtRSI;
  if ((I2->size[0] == 0) || (I2->size[1] == 0)) {
    emlrtErrorWithMessageIdR2018a(&g_st, &jb_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonempty",
      "MATLAB:validateImage:expectedNonempty", 3, 4, 2, "I2");
  }

  imageSize[0] = (uint32_T)I1->size[0];
  varargin_2[0] = (uint32_T)I2->size[0];
  imageSize[1] = (uint32_T)I1->size[1];
  varargin_2[1] = (uint32_T)I2->size[1];
  p = true;
  outSize_idx_1 = 0;
  exitg1 = false;
  while ((!exitg1) && (outSize_idx_1 < 2)) {
    if ((int32_T)imageSize[outSize_idx_1] != (int32_T)varargin_2[outSize_idx_1])
    {
      p = false;
      exitg1 = true;
    } else {
      outSize_idx_1++;
    }
  }

  b_p = (int32_T)p;
  if (!b_p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &rb_emlrtRTEI,
      "vision:dims:inputsMismatch", "vision:dims:inputsMismatch", 0);
  }

  emxInit_char_T(&c_st, &varargin_1, 2, &hk_emlrtRTEI, true);
  emxInit_char_T(&c_st, &fr_emlrtRSI, 2, &ik_emlrtRTEI, true);
  emxInit_char_T(&c_st, &gr_emlrtRSI, 2, &ik_emlrtRTEI, true);
  imageSize[1] = (uint32_T)I1->size[1];
  b_st.site = &yo_emlrtRSI;
  c_st.site = &fp_emlrtRSI;
  d_st.site = &gp_emlrtRSI;
  e_st.site = &hp_emlrtRSI;
  b_sprintf(&e_st, (int32_T)imageSize[1], fr_emlrtRSI);
  e_st.site = &ip_emlrtRSI;
  b_sprintf(&e_st, (int32_T)imageSize[1], gr_emlrtRSI);
  e_st.site = &kp_emlrtRSI;
  f_st.site = &jp_emlrtRSI;
  b_sprintf(&f_st, (int32_T)imageSize[1], varargin_1);
  emxFree_char_T(&gr_emlrtRSI);
  emxFree_char_T(&fr_emlrtRSI);
  if (128 >= I1->size[1]) {
    emlrtErrorWithMessageIdR2018a(&e_st, &sb_emlrtRTEI,
      "vision:disparity:maxDisparityRangeExceedImageWidthSGM",
      "vision:disparity:maxDisparityRangeExceedImageWidthSGM", 3, 4,
      varargin_1->size[1], &varargin_1->data[0]);
  }

  emxFree_char_T(&varargin_1);
  emxInit_uint32_T(&e_st, &leftCT, 2, &vj_emlrtRTEI, true);
  emxInit_uint32_T(&e_st, &rightCT, 2, &wj_emlrtRTEI, true);
  st.site = &wo_emlrtRSI;
  i = leftCT->size[0] * leftCT->size[1];
  leftCT->size[0] = I1->size[0];
  leftCT->size[1] = I1->size[1];
  emxEnsureCapacity_uint32_T(&st, leftCT, i, &rj_emlrtRTEI);
  i = rightCT->size[0] * rightCT->size[1];
  rightCT->size[0] = I1->size[0];
  rightCT->size[1] = I1->size[1];
  emxEnsureCapacity_uint32_T(&st, rightCT, i, &rj_emlrtRTEI);
  i1 = (I1->size[1] - 128) * 128L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  emxInit_int16_T(&st, &matchingCost, 2, &xj_emlrtRTEI, true);
  emxInit_int16_T(&st, &dirCostSum, 2, &yj_emlrtRTEI, true);
  outSize_idx_1 = (int32_T)i1;
  i = matchingCost->size[0] * matchingCost->size[1];
  matchingCost->size[0] = I1->size[0];
  matchingCost->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, matchingCost, i, &rj_emlrtRTEI);
  i = dirCostSum->size[0] * dirCostSum->size[1];
  dirCostSum->size[0] = I1->size[0];
  dirCostSum->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, dirCostSum, i, &rj_emlrtRTEI);
  b_st.site = &mp_emlrtRSI;
  i1 = (I1->size[1] - 126) * 3L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  emxInit_int16_T(&b_st, &oneRowMinDirCostBuf1, 2, &ak_emlrtRTEI, true);
  emxInit_int16_T(&b_st, &oneRowMinDirCostBuf2, 2, &bk_emlrtRTEI, true);
  outSize_idx_1 = (int32_T)i1;
  i = oneRowMinDirCostBuf1->size[0] * oneRowMinDirCostBuf1->size[1];
  oneRowMinDirCostBuf1->size[0] = 1;
  oneRowMinDirCostBuf1->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, oneRowMinDirCostBuf1, i, &rj_emlrtRTEI);
  i = oneRowMinDirCostBuf2->size[0] * oneRowMinDirCostBuf2->size[1];
  oneRowMinDirCostBuf2->size[0] = 1;
  oneRowMinDirCostBuf2->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, oneRowMinDirCostBuf2, i, &rj_emlrtRTEI);
  i1 = outSize_idx_1 * 144L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  outSize_idx_1 = (int32_T)i1;
  if (outSize_idx_1 > 2147483646) {
    outSize_idx_1 = MAX_int32_T;
  } else {
    outSize_idx_1++;
  }

  emxInit_int16_T(&st, &oneRowDirCostBuf1, 2, &ck_emlrtRTEI, true);
  emxInit_int16_T(&st, &oneRowDirCostBuf2, 2, &dk_emlrtRTEI, true);
  i = oneRowDirCostBuf1->size[0] * oneRowDirCostBuf1->size[1];
  oneRowDirCostBuf1->size[0] = 1;
  oneRowDirCostBuf1->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, oneRowDirCostBuf1, i, &rj_emlrtRTEI);
  i = oneRowDirCostBuf2->size[0] * oneRowDirCostBuf2->size[1];
  oneRowDirCostBuf2->size[0] = 1;
  oneRowDirCostBuf2->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, oneRowDirCostBuf2, i, &rj_emlrtRTEI);
  b_st.site = &np_emlrtRSI;
  i1 = outSize_idx_1 * 10L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  emxInit_int16_T(&st, &tenRowDirCostBuf1, 2, &ek_emlrtRTEI, true);
  emxInit_int16_T(&st, &tenRowDirCostBuf2, 2, &fk_emlrtRTEI, true);
  emxInit_uint8_T(&st, &I1Transpose, 2, &sj_emlrtRTEI, true);
  outSize_idx_1 = (int32_T)i1;
  i = tenRowDirCostBuf1->size[0] * tenRowDirCostBuf1->size[1];
  tenRowDirCostBuf1->size[0] = 1;
  tenRowDirCostBuf1->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, tenRowDirCostBuf1, i, &rj_emlrtRTEI);
  i = tenRowDirCostBuf2->size[0] * tenRowDirCostBuf2->size[1];
  tenRowDirCostBuf2->size[0] = 1;
  tenRowDirCostBuf2->size[1] = outSize_idx_1;
  emxEnsureCapacity_int16_T(&st, tenRowDirCostBuf2, i, &rj_emlrtRTEI);
  paramStruct.minDisparity = 0;
  paramStruct.numberOfDisparities = 128;
  paramStruct.UniquenessThreshold = 15;
  paramStruct.Directions = 5;
  paramStruct.Penalty1 = 15;
  paramStruct.Penalty2 = 200;
  i = I1Transpose->size[0] * I1Transpose->size[1];
  I1Transpose->size[0] = I1->size[1];
  I1Transpose->size[1] = I1->size[0];
  emxEnsureCapacity_uint8_T(&st, I1Transpose, i, &sj_emlrtRTEI);
  outSize_idx_1 = I1->size[0];
  for (i = 0; i < outSize_idx_1; i++) {
    loop_ub = I1->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      I1Transpose->data[i2 + I1Transpose->size[0] * i] = I1->data[i + I1->size[0]
        * i2];
    }
  }

  emxInit_uint8_T(&st, &I2Transpose, 2, &tj_emlrtRTEI, true);
  i = I2Transpose->size[0] * I2Transpose->size[1];
  I2Transpose->size[0] = I2->size[1];
  I2Transpose->size[1] = I2->size[0];
  emxEnsureCapacity_uint8_T(&st, I2Transpose, i, &tj_emlrtRTEI);
  outSize_idx_1 = I2->size[0];
  for (i = 0; i < outSize_idx_1; i++) {
    loop_ub = I2->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      I2Transpose->data[i2 + I2Transpose->size[0] * i] = I2->data[i + I2->size[0]
        * i2];
    }
  }

  emxInit_real32_T(&st, &outDispTranspose, 2, &gk_emlrtRTEI, true);
  i = outDispTranspose->size[0] * outDispTranspose->size[1];
  outDispTranspose->size[0] = I1->size[1];
  outDispTranspose->size[1] = I1->size[0];
  emxEnsureCapacity_real32_T(&st, outDispTranspose, i, &rj_emlrtRTEI);
  disparitySGMCompute(&I1Transpose->data[0], &I2Transpose->data[0],
                      &leftCT->data[0], &rightCT->data[0], &matchingCost->data[0],
                      &oneRowMinDirCostBuf1->data[0],
                      &oneRowMinDirCostBuf2->data[0], &oneRowDirCostBuf1->data[0],
                      &oneRowDirCostBuf2->data[0], &tenRowDirCostBuf1->data[0],
                      &tenRowDirCostBuf2->data[0], &dirCostSum->data[0],
                      I1->size[0], I1->size[1], &outDispTranspose->data[0],
                      &paramStruct);
  i = disparityMap->size[0] * disparityMap->size[1];
  disparityMap->size[0] = outDispTranspose->size[1];
  disparityMap->size[1] = outDispTranspose->size[0];
  emxEnsureCapacity_real32_T(&st, disparityMap, i, &uj_emlrtRTEI);
  outSize_idx_1 = outDispTranspose->size[0];
  emxFree_uint8_T(&I2Transpose);
  emxFree_uint8_T(&I1Transpose);
  emxFree_int16_T(&tenRowDirCostBuf2);
  emxFree_int16_T(&tenRowDirCostBuf1);
  emxFree_int16_T(&oneRowDirCostBuf2);
  emxFree_int16_T(&oneRowDirCostBuf1);
  emxFree_int16_T(&oneRowMinDirCostBuf2);
  emxFree_int16_T(&oneRowMinDirCostBuf1);
  emxFree_int16_T(&dirCostSum);
  emxFree_int16_T(&matchingCost);
  emxFree_uint32_T(&rightCT);
  emxFree_uint32_T(&leftCT);
  for (i = 0; i < outSize_idx_1; i++) {
    loop_ub = outDispTranspose->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      disparityMap->data[i2 + disparityMap->size[0] * i] =
        outDispTranspose->data[i + outDispTranspose->size[0] * i2];
    }
  }

  emxFree_real32_T(&outDispTranspose);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (disparitySGM.c) */
