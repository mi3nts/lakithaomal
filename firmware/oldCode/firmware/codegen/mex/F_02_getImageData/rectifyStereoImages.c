/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rectifyStereoImages.c
 *
 * Code generation for function 'rectifyStereoImages'
 *
 */

/* Include files */
#include "rectifyStereoImages.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "ImageTransformer.h"
#include "StereoParametersImpl.h"
#include "checkImageSize.h"
#include "interp2d.h"
#include "rt_nonfinite.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo df_emlrtRSI = { 126,/* lineNo */
  "rectifyStereoImages",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/rectifyStereoImages.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 127,/* lineNo */
  "rectifyStereoImages",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/rectifyStereoImages.m"/* pathName */
};

static emlrtRSInfo ff_emlrtRSI = { 132,/* lineNo */
  "rectifyStereoImages",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/rectifyStereoImages.m"/* pathName */
};

static emlrtRSInfo di_emlrtRSI = { 168,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ei_emlrtRSI = { 169,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo fi_emlrtRSI = { 170,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo gi_emlrtRSI = { 173,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo hi_emlrtRSI = { 177,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ii_emlrtRSI = { 179,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ji_emlrtRSI = { 188,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ki_emlrtRSI = { 192,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo li_emlrtRSI = { 199,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo mi_emlrtRSI = { 206,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ni_emlrtRSI = { 209,/* lineNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo fo_emlrtRSI = { 87, /* lineNo */
  "ImageTransformer/update",           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRTEInfo y_emlrtRTEI = { 185,/* lineNo */
  21,                                  /* colNo */
  "StereoParametersImpl/rectifyStereoImagesImpl",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = { 96,/* lineNo */
  36,                                  /* colNo */
  "RectificationParameters",           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/RectificationParameters.m"/* pName */
};

/* Function Definitions */
void rectifyStereoImages(F_02_getImageDataStackData *SD, const emlrtStack *sp,
  const uint8_T I1[921600], const uint8_T I2[921600],
  c_vision_internal_calibration_S *stereoParams, emxArray_uint8_T
  *rectifiedImage1, emxArray_uint8_T *rectifiedImage2)
{
  real_T xBounds[2];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  boolean_T success;
  emxArray_char_T *b;
  int32_T loop_ub;
  projective2d H1;
  projective2d H2;
  real_T Q[16];
  real_T yBounds[2];
  emxArray_real32_T *b_stereoParams;
  int32_T exitg2;
  static const char_T b_cv[5] = { 'v', 'a', 'l', 'i', 'd' };

  emxArray_real32_T *c_stereoParams;
  static const char_T a[5] = { 'v', 'a', 'l', 'i', 'd' };

  d_vision_internal_calibration_C *params;
  real_T intrinsicMatrix[9];
  real_T radialDist[2];
  real_T tangentialDist[2];
  static const char_T b_cv1[5] = { 'u', 'i', 'n', 't', '8' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &st;
  c_st.tls = st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  xBounds[0] = stereoParams->CameraParameters1->ImageSize[0];
  xBounds[1] = stereoParams->CameraParameters1->ImageSize[1];
  st.site = &df_emlrtRSI;
  checkImageSize(&st, xBounds);
  xBounds[0] = stereoParams->CameraParameters1->ImageSize[0];
  xBounds[1] = stereoParams->CameraParameters1->ImageSize[1];
  st.site = &ef_emlrtRSI;
  checkImageSize(&st, xBounds);
  st.site = &ff_emlrtRSI;
  b_st.site = &di_emlrtRSI;
  xBounds[0] = stereoParams->RectificationParams.OriginalImageSize[0];
  xBounds[1] = stereoParams->RectificationParams.OriginalImageSize[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(160.0 * (real_T)k + 480.0 == xBounds[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  success = (int32_T)p;
  emxInit_char_T(&b_st, &b, 2, &ff_emlrtRTEI, true);
  if (success) {
    k = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = stereoParams->RectificationParams.OutputView->size[1];
    emxEnsureCapacity_char_T(&b_st, b, k, &ff_emlrtRTEI);
    loop_ub = stereoParams->RectificationParams.OutputView->size[0] *
      stereoParams->RectificationParams.OutputView->size[1];
    for (k = 0; k < loop_ub; k++) {
      b->data[k] = stereoParams->RectificationParams.OutputView->data[k];
    }

    success = false;
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
          success = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (success) {
      success = true;
    } else {
      success = false;
    }
  } else {
    success = false;
  }

  emxFree_char_T(&b);
  b_st.site = &ei_emlrtRSI;
  c_st.site = &fi_emlrtRSI;
  if ((!success) || ImageTransformer_needToUpdate(&b_st,
       &stereoParams->RectifyMap1) || ImageTransformer_needToUpdate(&c_st,
       &stereoParams->RectifyMap2)) {
    b_st.site = &gi_emlrtRSI;
    c_StereoParametersImpl_computeR(SD, &b_st, stereoParams, &H1, &H2, Q,
      xBounds, yBounds, &success);
    if (!success) {
      b_st.site = &hi_emlrtRSI;
      c_warning(&b_st);
      b_st.site = &ii_emlrtRSI;
      d_StereoParametersImpl_computeR(SD, &b_st, stereoParams, &H1, &H2, Q,
        xBounds, yBounds, &success);
    }

    if (!success) {
      emlrtErrorWithMessageIdR2018a(&st, &y_emlrtRTEI,
        "vision:calibrate:invalidBounds", "vision:calibrate:invalidBounds", 0);
    }

    b_st.site = &ji_emlrtRSI;
    stereoParams->RectificationParams.Initialized = true;
    stereoParams->RectificationParams.OriginalImageSize[0] = 480.0;
    stereoParams->RectificationParams.OriginalImageSize[1] = 640.0;
    stereoParams->RectificationParams.H1 = H1;
    stereoParams->RectificationParams.H2 = H2;
    for (k = 0; k < 16; k++) {
      stereoParams->RectificationParams.Q[k] = Q[k];
    }

    k = stereoParams->RectificationParams.OutputView->size[0] *
      stereoParams->RectificationParams.OutputView->size[1];
    stereoParams->RectificationParams.OutputView->size[0] = 1;
    stereoParams->RectificationParams.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(&b_st, stereoParams->RectificationParams.OutputView,
      k, &ad_emlrtRTEI);
    for (k = 0; k < 5; k++) {
      stereoParams->RectificationParams.OutputView->data[k] = a[k];
    }

    stereoParams->RectificationParams.XBounds[0] = xBounds[0];
    stereoParams->RectificationParams.XBounds[1] = xBounds[1];
    stereoParams->RectificationParams.YBounds[0] = yBounds[0];
    stereoParams->RectificationParams.YBounds[1] = yBounds[1];
    params = stereoParams->CameraParameters1;
    b_st.site = &ki_emlrtRSI;
    for (k = 0; k < 3; k++) {
      intrinsicMatrix[3 * k] = params->IntrinsicMatrixInternal[k];
      intrinsicMatrix[3 * k + 1] = params->IntrinsicMatrixInternal[k + 3];
      intrinsicMatrix[3 * k + 2] = params->IntrinsicMatrixInternal[k + 6];
    }

    b_st.site = &ki_emlrtRSI;
    radialDist[0] = params->RadialDistortion[0];
    radialDist[1] = params->RadialDistortion[1];
    tangentialDist[0] = params->TangentialDistortion[0];
    tangentialDist[1] = params->TangentialDistortion[1];
    xBounds[0] = stereoParams->RectificationParams.XBounds[0];
    xBounds[1] = stereoParams->RectificationParams.XBounds[1];
    yBounds[0] = stereoParams->RectificationParams.YBounds[0];
    yBounds[1] = stereoParams->RectificationParams.YBounds[1];
    H1 = stereoParams->RectificationParams.H1;
    k = stereoParams->RectifyMap1.SizeOfImage->size[0] *
      stereoParams->RectifyMap1.SizeOfImage->size[1];
    stereoParams->RectifyMap1.SizeOfImage->size[0] = 1;
    stereoParams->RectifyMap1.SizeOfImage->size[1] = 3;
    emxEnsureCapacity_real_T(&b_st, stereoParams->RectifyMap1.SizeOfImage, k,
      &ed_emlrtRTEI);
    stereoParams->RectifyMap1.SizeOfImage->data[0] = 480.0;
    stereoParams->RectifyMap1.SizeOfImage->data[1] = 640.0;
    stereoParams->RectifyMap1.SizeOfImage->data[2] = 3.0;
    k = stereoParams->RectifyMap1.ClassOfImage->size[0] *
      stereoParams->RectifyMap1.ClassOfImage->size[1];
    stereoParams->RectifyMap1.ClassOfImage->size[0] = 1;
    stereoParams->RectifyMap1.ClassOfImage->size[1] = 5;
    emxEnsureCapacity_char_T(&b_st, stereoParams->RectifyMap1.ClassOfImage, k,
      &fd_emlrtRTEI);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap1.ClassOfImage->data[k] = b_cv1[k];
    }

    k = stereoParams->RectifyMap1.OutputView->size[0] *
      stereoParams->RectifyMap1.OutputView->size[1];
    stereoParams->RectifyMap1.OutputView->size[0] = 1;
    stereoParams->RectifyMap1.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(&b_st, stereoParams->RectifyMap1.OutputView, k,
      &gd_emlrtRTEI);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap1.OutputView->data[k] = a[k];
    }

    stereoParams->RectifyMap1.XBounds[0] = xBounds[0];
    stereoParams->RectifyMap1.XBounds[1] = xBounds[1];
    stereoParams->RectifyMap1.YBounds[0] = yBounds[0];
    stereoParams->RectifyMap1.YBounds[1] = yBounds[1];
    d_st.site = &fo_emlrtRSI;
    b_ImageTransformer_computeMap(&d_st, &stereoParams->RectifyMap1,
      intrinsicMatrix, radialDist, tangentialDist, H1.T);
    params = stereoParams->CameraParameters2;
    b_st.site = &li_emlrtRSI;
    for (k = 0; k < 3; k++) {
      intrinsicMatrix[3 * k] = params->IntrinsicMatrixInternal[k];
      intrinsicMatrix[3 * k + 1] = params->IntrinsicMatrixInternal[k + 3];
      intrinsicMatrix[3 * k + 2] = params->IntrinsicMatrixInternal[k + 6];
    }

    b_st.site = &li_emlrtRSI;
    radialDist[0] = params->RadialDistortion[0];
    radialDist[1] = params->RadialDistortion[1];
    tangentialDist[0] = params->TangentialDistortion[0];
    tangentialDist[1] = params->TangentialDistortion[1];
    xBounds[0] = stereoParams->RectificationParams.XBounds[0];
    xBounds[1] = stereoParams->RectificationParams.XBounds[1];
    yBounds[0] = stereoParams->RectificationParams.YBounds[0];
    yBounds[1] = stereoParams->RectificationParams.YBounds[1];
    H1 = stereoParams->RectificationParams.H2;
    k = stereoParams->RectifyMap2.SizeOfImage->size[0] *
      stereoParams->RectifyMap2.SizeOfImage->size[1];
    stereoParams->RectifyMap2.SizeOfImage->size[0] = 1;
    stereoParams->RectifyMap2.SizeOfImage->size[1] = 3;
    emxEnsureCapacity_real_T(&b_st, stereoParams->RectifyMap2.SizeOfImage, k,
      &ed_emlrtRTEI);
    stereoParams->RectifyMap2.SizeOfImage->data[0] = 480.0;
    stereoParams->RectifyMap2.SizeOfImage->data[1] = 640.0;
    stereoParams->RectifyMap2.SizeOfImage->data[2] = 3.0;
    k = stereoParams->RectifyMap2.ClassOfImage->size[0] *
      stereoParams->RectifyMap2.ClassOfImage->size[1];
    stereoParams->RectifyMap2.ClassOfImage->size[0] = 1;
    stereoParams->RectifyMap2.ClassOfImage->size[1] = 5;
    emxEnsureCapacity_char_T(&b_st, stereoParams->RectifyMap2.ClassOfImage, k,
      &fd_emlrtRTEI);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap2.ClassOfImage->data[k] = b_cv1[k];
    }

    k = stereoParams->RectifyMap2.OutputView->size[0] *
      stereoParams->RectifyMap2.OutputView->size[1];
    stereoParams->RectifyMap2.OutputView->size[0] = 1;
    stereoParams->RectifyMap2.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(&b_st, stereoParams->RectifyMap2.OutputView, k,
      &gd_emlrtRTEI);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap2.OutputView->data[k] = a[k];
    }

    stereoParams->RectifyMap2.XBounds[0] = xBounds[0];
    stereoParams->RectifyMap2.XBounds[1] = xBounds[1];
    stereoParams->RectifyMap2.YBounds[0] = yBounds[0];
    stereoParams->RectifyMap2.YBounds[1] = yBounds[1];
    d_st.site = &fo_emlrtRSI;
    b_ImageTransformer_computeMap(&d_st, &stereoParams->RectifyMap2,
      intrinsicMatrix, radialDist, tangentialDist, H1.T);
  }

  emxInit_real32_T(&st, &b_stereoParams, 2, &gf_emlrtRTEI, true);
  b_st.site = &mi_emlrtRSI;
  k = b_stereoParams->size[0] * b_stereoParams->size[1];
  b_stereoParams->size[0] = stereoParams->RectifyMap1.XmapSingle->size[0];
  b_stereoParams->size[1] = stereoParams->RectifyMap1.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(&b_st, b_stereoParams, k, &gf_emlrtRTEI);
  loop_ub = stereoParams->RectifyMap1.XmapSingle->size[0] *
    stereoParams->RectifyMap1.XmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    b_stereoParams->data[k] = stereoParams->RectifyMap1.XmapSingle->data[k];
  }

  emxInit_real32_T(&b_st, &c_stereoParams, 2, &hf_emlrtRTEI, true);
  k = c_stereoParams->size[0] * c_stereoParams->size[1];
  c_stereoParams->size[0] = stereoParams->RectifyMap1.YmapSingle->size[0];
  c_stereoParams->size[1] = stereoParams->RectifyMap1.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(&b_st, c_stereoParams, k, &hf_emlrtRTEI);
  loop_ub = stereoParams->RectifyMap1.YmapSingle->size[0] *
    stereoParams->RectifyMap1.YmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    c_stereoParams->data[k] = stereoParams->RectifyMap1.YmapSingle->data[k];
  }

  d_st.site = &wj_emlrtRSI;
  c_interp2d(&d_st, I1, b_stereoParams, c_stereoParams, rectifiedImage1);
  b_st.site = &ni_emlrtRSI;
  k = b_stereoParams->size[0] * b_stereoParams->size[1];
  b_stereoParams->size[0] = stereoParams->RectifyMap2.XmapSingle->size[0];
  b_stereoParams->size[1] = stereoParams->RectifyMap2.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(&b_st, b_stereoParams, k, &gf_emlrtRTEI);
  loop_ub = stereoParams->RectifyMap2.XmapSingle->size[0] *
    stereoParams->RectifyMap2.XmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    b_stereoParams->data[k] = stereoParams->RectifyMap2.XmapSingle->data[k];
  }

  k = c_stereoParams->size[0] * c_stereoParams->size[1];
  c_stereoParams->size[0] = stereoParams->RectifyMap2.YmapSingle->size[0];
  c_stereoParams->size[1] = stereoParams->RectifyMap2.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(&b_st, c_stereoParams, k, &hf_emlrtRTEI);
  loop_ub = stereoParams->RectifyMap2.YmapSingle->size[0] *
    stereoParams->RectifyMap2.YmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    c_stereoParams->data[k] = stereoParams->RectifyMap2.YmapSingle->data[k];
  }

  d_st.site = &wj_emlrtRSI;
  c_interp2d(&d_st, I2, b_stereoParams, c_stereoParams, rectifiedImage2);
  emxFree_real32_T(&c_stereoParams);
  emxFree_real32_T(&b_stereoParams);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (rectifyStereoImages.c) */
