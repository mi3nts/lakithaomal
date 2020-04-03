/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * undistortImage.c
 *
 * Code generation for function 'undistortImage'
 *
 */

/* Include files */
#include "undistortImage.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "ImageTransformer.h"
#include "checkImageSize.h"
#include "interp2d.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo od_emlrtRSI = { 94, /* lineNo */
  "undistortImage",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/undistortImage.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 108,/* lineNo */
  "undistortImage",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/undistortImage.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 727,/* lineNo */
  "CameraParametersImpl/undistortImageImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 731,/* lineNo */
  "CameraParametersImpl/undistortImageImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 736,/* lineNo */
  "CameraParametersImpl/undistortImageImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 107,/* lineNo */
  "ImageTransformer/transformImage",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  740,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/undistortImageImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  740,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/undistortImageImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo hd_emlrtRTEI = { 1,/* lineNo */
  27,                                  /* colNo */
  "undistortImage",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/undistortImage.m"/* pName */
};

/* Function Definitions */
void undistortImage(const emlrtStack *sp, const real_T b_I[307200],
                    c_vision_internal_calibration_C *intrinsics, real_T J[307200])
{
  emxArray_real_T *varargin_1;
  int32_T i;
  int32_T loop_ub;
  boolean_T p;
  boolean_T exitg1;
  boolean_T sameSize;
  emxArray_char_T *b;
  boolean_T sameClass;
  int32_T exitg2;
  static const char_T b_cv[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  boolean_T sameOutputView;
  static const char_T b_cv1[4] = { 's', 'a', 'm', 'e' };

  emxArray_real_T *b_J;
  real_T intrinsicMatrix[9];
  real_T radialDist[2];
  real_T tangentialDist[2];
  int32_T i1;
  int32_T i2;
  static const char_T a[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

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
  emxInit_real_T(sp, &varargin_1, 2, &bd_emlrtRTEI, true);
  st.site = &od_emlrtRSI;
  checkImageSize(&st, intrinsics->ImageSize);
  st.site = &pd_emlrtRSI;
  b_st.site = &qd_emlrtRSI;
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = intrinsics->UndistortMap.SizeOfImage->size[1];
  emxEnsureCapacity_real_T(&b_st, varargin_1, i, &bd_emlrtRTEI);
  loop_ub = intrinsics->UndistortMap.SizeOfImage->size[0] *
    intrinsics->UndistortMap.SizeOfImage->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_1->data[i] = intrinsics->UndistortMap.SizeOfImage->data[i];
  }

  p = (varargin_1->size[1] == 2);
  if (p && (varargin_1->size[1] != 0)) {
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if (!(varargin_1->data[loop_ub] == 160.0 * (real_T)loop_ub + 480.0)) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }

  emxFree_real_T(&varargin_1);
  sameSize = (int32_T)p;
  emxInit_char_T(&b_st, &b, 2, &cd_emlrtRTEI, true);
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = intrinsics->UndistortMap.ClassOfImage->size[1];
  emxEnsureCapacity_char_T(&b_st, b, i, &cd_emlrtRTEI);
  loop_ub = intrinsics->UndistortMap.ClassOfImage->size[0] *
    intrinsics->UndistortMap.ClassOfImage->size[1];
  for (i = 0; i < loop_ub; i++) {
    b->data[i] = intrinsics->UndistortMap.ClassOfImage->data[i];
  }

  sameClass = false;
  if (6 == b->size[1]) {
    loop_ub = 0;
    do {
      exitg2 = 0;
      if (loop_ub < 6) {
        if (b_cv[loop_ub] != b->data[loop_ub]) {
          exitg2 = 1;
        } else {
          loop_ub++;
        }
      } else {
        sameClass = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = intrinsics->UndistortMap.OutputView->size[1];
  emxEnsureCapacity_char_T(&b_st, b, i, &dd_emlrtRTEI);
  loop_ub = intrinsics->UndistortMap.OutputView->size[0] *
    intrinsics->UndistortMap.OutputView->size[1];
  for (i = 0; i < loop_ub; i++) {
    b->data[i] = intrinsics->UndistortMap.OutputView->data[i];
  }

  p = (b->size[1] == 4);
  if (p && (b->size[1] != 0)) {
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 4)) {
      if (!(b->data[loop_ub] == b_cv1[loop_ub])) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
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

  if (!sameSize) {
    b_st.site = &rd_emlrtRSI;
    for (i = 0; i < 3; i++) {
      intrinsicMatrix[3 * i] = intrinsics->IntrinsicMatrixInternal[i];
      intrinsicMatrix[3 * i + 1] = intrinsics->IntrinsicMatrixInternal[i + 3];
      intrinsicMatrix[3 * i + 2] = intrinsics->IntrinsicMatrixInternal[i + 6];
    }

    b_st.site = &rd_emlrtRSI;
    radialDist[0] = intrinsics->RadialDistortion[0];
    radialDist[1] = intrinsics->RadialDistortion[1];
    tangentialDist[0] = intrinsics->TangentialDistortion[0];
    tangentialDist[1] = intrinsics->TangentialDistortion[1];
    i = intrinsics->UndistortMap.SizeOfImage->size[0] *
      intrinsics->UndistortMap.SizeOfImage->size[1];
    intrinsics->UndistortMap.SizeOfImage->size[0] = 1;
    intrinsics->UndistortMap.SizeOfImage->size[1] = 2;
    emxEnsureCapacity_real_T(&b_st, intrinsics->UndistortMap.SizeOfImage, i,
      &ed_emlrtRTEI);
    intrinsics->UndistortMap.SizeOfImage->data[0] = 480.0;
    intrinsics->UndistortMap.SizeOfImage->data[1] = 640.0;
    i = intrinsics->UndistortMap.ClassOfImage->size[0] *
      intrinsics->UndistortMap.ClassOfImage->size[1];
    intrinsics->UndistortMap.ClassOfImage->size[0] = 1;
    intrinsics->UndistortMap.ClassOfImage->size[1] = 6;
    emxEnsureCapacity_char_T(&b_st, intrinsics->UndistortMap.ClassOfImage, i,
      &fd_emlrtRTEI);
    for (i = 0; i < 6; i++) {
      intrinsics->UndistortMap.ClassOfImage->data[i] = a[i];
    }

    i = intrinsics->UndistortMap.OutputView->size[0] *
      intrinsics->UndistortMap.OutputView->size[1];
    intrinsics->UndistortMap.OutputView->size[0] = 1;
    intrinsics->UndistortMap.OutputView->size[1] = 4;
    emxEnsureCapacity_char_T(&b_st, intrinsics->UndistortMap.OutputView, i,
      &gd_emlrtRTEI);
    intrinsics->UndistortMap.OutputView->data[0] = 's';
    intrinsics->UndistortMap.OutputView->data[1] = 'a';
    intrinsics->UndistortMap.OutputView->data[2] = 'm';
    intrinsics->UndistortMap.OutputView->data[3] = 'e';
    intrinsics->UndistortMap.XBounds[0] = 1.0;
    intrinsics->UndistortMap.XBounds[1] = 640.0;
    intrinsics->UndistortMap.YBounds[0] = 1.0;
    intrinsics->UndistortMap.YBounds[1] = 480.0;
    c_st.site = &td_emlrtRSI;
    ImageTransformer_computeMap(&c_st, &intrinsics->UndistortMap,
      intrinsicMatrix, radialDist, tangentialDist);
  }

  emxInit_real_T(&st, &b_J, 2, &hd_emlrtRTEI, true);
  b_st.site = &sd_emlrtRSI;
  c_st.site = &xe_emlrtRSI;
  interp2d(&c_st, b_I, intrinsics->UndistortMap.Xmap,
           intrinsics->UndistortMap.Ymap, b_J);
  for (i = 0; i < 640; i++) {
    loop_ub = i + 1;
    for (i1 = 0; i1 < 480; i1++) {
      i2 = i1 + 1;
      if (i2 > b_J->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, b_J->size[0], &emlrtBCI, &st);
      }

      if (loop_ub > b_J->size[1]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_J->size[1], &b_emlrtBCI, &st);
      }

      J[i1 + 480 * i] = b_J->data[(i2 + b_J->size[0] * (loop_ub - 1)) - 1];
    }
  }

  emxFree_real_T(&b_J);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (undistortImage.c) */
