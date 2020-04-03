//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rectifyStereoImages.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "rectifyStereoImages.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "ImageTransformer.h"
#include "StereoParametersImpl.h"
#include "interp2d.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const emxArray_uint8_T *I1
//                const emxArray_uint8_T *I2
//                c_vision_internal_calibration_S *stereoParams
//                emxArray_uint8_T *rectifiedImage1
//                emxArray_uint8_T *rectifiedImage2
// Return Type  : void
//
void rectifyStereoImages(const emxArray_uint8_T *I1, const emxArray_uint8_T *I2,
  c_vision_internal_calibration_S *stereoParams, emxArray_uint8_T
  *rectifiedImage1, emxArray_uint8_T *rectifiedImage2)
{
  int fillValues_size[3];
  unsigned char fillValues_data[3];
  double imageSize[2];
  double varargin_2[2];
  boolean_T p;
  int k;
  boolean_T exitg1;
  boolean_T b_p;
  emxArray_char_T *b;
  projective2d H1;
  projective2d H2;
  double Q[16];
  double xBounds[2];
  double yBounds[2];
  int loop_ub;
  emxArray_real32_T *b_stereoParams;
  int exitg2;
  emxArray_real32_T *c_stereoParams;
  static const char cv[5] = { 'v', 'a', 'l', 'i', 'd' };

  static const char a[5] = { 'v', 'a', 'l', 'i', 'd' };

  d_vision_internal_calibration_C *params;
  double intrinsicMatrix[9];
  static const char cv1[5] = { 'u', 'i', 'n', 't', '8' };

  if (I1->size[2] > 1) {
    fillValues_size[0] = 1;
    fillValues_size[1] = 1;
    fillValues_size[2] = 3;
    fillValues_data[0] = 0U;
    fillValues_data[1] = 0U;
    fillValues_data[2] = 0U;
  } else {
    fillValues_size[0] = 1;
    fillValues_size[1] = 1;
    fillValues_size[2] = 1;
    fillValues_data[0] = 0U;
  }

  imageSize[0] = static_cast<short>(I1->size[0]);
  imageSize[1] = static_cast<short>(I1->size[1]);
  varargin_2[0] = stereoParams->RectificationParams.OriginalImageSize[0];
  varargin_2[1] = stereoParams->RectificationParams.OriginalImageSize[1];
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(imageSize[k] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  b_p = p;
  emxInit_char_T(&b, 2);
  if (b_p) {
    k = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = stereoParams->RectificationParams.OutputView->size[1];
    emxEnsureCapacity_char_T(b, k);
    loop_ub = stereoParams->RectificationParams.OutputView->size[0] *
      stereoParams->RectificationParams.OutputView->size[1];
    for (k = 0; k < loop_ub; k++) {
      b->data[k] = stereoParams->RectificationParams.OutputView->data[k];
    }

    b_p = false;
    if (5 == b->size[1]) {
      k = 0;
      do {
        exitg2 = 0;
        if (k < 5) {
          if (cv[k] != b->data[k]) {
            exitg2 = 1;
          } else {
            k++;
          }
        } else {
          b_p = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_p) {
      b_p = true;
    } else {
      b_p = false;
    }
  } else {
    b_p = false;
  }

  emxFree_char_T(&b);
  if ((!b_p) || ImageTransformer_needToUpdate(&stereoParams->RectifyMap1, I1) ||
      ImageTransformer_needToUpdate(&stereoParams->RectifyMap2, I2)) {
    c_StereoParametersImpl_computeR(stereoParams, imageSize, &H1, &H2, Q,
      xBounds, yBounds, &b_p);
    if (!b_p) {
      d_StereoParametersImpl_computeR(stereoParams, imageSize, &H1, &H2, Q,
        xBounds, yBounds, &b_p);
    }

    stereoParams->RectificationParams.Initialized = true;
    stereoParams->RectificationParams.OriginalImageSize[0] = imageSize[0];
    stereoParams->RectificationParams.OriginalImageSize[1] = imageSize[1];
    stereoParams->RectificationParams.H1 = H1;
    stereoParams->RectificationParams.H2 = H2;
    for (k = 0; k < 16; k++) {
      stereoParams->RectificationParams.Q[k] = Q[k];
    }

    k = stereoParams->RectificationParams.OutputView->size[0] *
      stereoParams->RectificationParams.OutputView->size[1];
    stereoParams->RectificationParams.OutputView->size[0] = 1;
    stereoParams->RectificationParams.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(stereoParams->RectificationParams.OutputView, k);
    for (k = 0; k < 5; k++) {
      stereoParams->RectificationParams.OutputView->data[k] = a[k];
    }

    stereoParams->RectificationParams.XBounds[0] = xBounds[0];
    stereoParams->RectificationParams.XBounds[1] = xBounds[1];
    stereoParams->RectificationParams.YBounds[0] = yBounds[0];
    stereoParams->RectificationParams.YBounds[1] = yBounds[1];
    params = stereoParams->CameraParameters1;
    for (k = 0; k < 3; k++) {
      intrinsicMatrix[3 * k] = params->IntrinsicMatrixInternal[k];
      intrinsicMatrix[3 * k + 1] = params->IntrinsicMatrixInternal[k + 3];
      intrinsicMatrix[3 * k + 2] = params->IntrinsicMatrixInternal[k + 6];
    }

    varargin_2[0] = params->RadialDistortion[0];
    varargin_2[1] = params->RadialDistortion[1];
    imageSize[0] = params->TangentialDistortion[0];
    imageSize[1] = params->TangentialDistortion[1];
    xBounds[0] = stereoParams->RectificationParams.XBounds[0];
    xBounds[1] = stereoParams->RectificationParams.XBounds[1];
    yBounds[0] = stereoParams->RectificationParams.YBounds[0];
    yBounds[1] = stereoParams->RectificationParams.YBounds[1];
    H1 = stereoParams->RectificationParams.H1;
    k = stereoParams->RectifyMap1.SizeOfImage->size[0] *
      stereoParams->RectifyMap1.SizeOfImage->size[1];
    stereoParams->RectifyMap1.SizeOfImage->size[0] = 1;
    stereoParams->RectifyMap1.SizeOfImage->size[1] = 3;
    emxEnsureCapacity_real_T(stereoParams->RectifyMap1.SizeOfImage, k);
    stereoParams->RectifyMap1.SizeOfImage->data[0] = I1->size[0];
    stereoParams->RectifyMap1.SizeOfImage->data[1] = I1->size[1];
    stereoParams->RectifyMap1.SizeOfImage->data[2] = I1->size[2];
    k = stereoParams->RectifyMap1.ClassOfImage->size[0] *
      stereoParams->RectifyMap1.ClassOfImage->size[1];
    stereoParams->RectifyMap1.ClassOfImage->size[0] = 1;
    stereoParams->RectifyMap1.ClassOfImage->size[1] = 5;
    emxEnsureCapacity_char_T(stereoParams->RectifyMap1.ClassOfImage, k);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap1.ClassOfImage->data[k] = cv1[k];
    }

    k = stereoParams->RectifyMap1.OutputView->size[0] *
      stereoParams->RectifyMap1.OutputView->size[1];
    stereoParams->RectifyMap1.OutputView->size[0] = 1;
    stereoParams->RectifyMap1.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(stereoParams->RectifyMap1.OutputView, k);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap1.OutputView->data[k] = a[k];
    }

    stereoParams->RectifyMap1.XBounds[0] = xBounds[0];
    stereoParams->RectifyMap1.XBounds[1] = xBounds[1];
    stereoParams->RectifyMap1.YBounds[0] = yBounds[0];
    stereoParams->RectifyMap1.YBounds[1] = yBounds[1];
    b_ImageTransformer_computeMap(&stereoParams->RectifyMap1, intrinsicMatrix,
      varargin_2, imageSize, H1.T);
    params = stereoParams->CameraParameters2;
    for (k = 0; k < 3; k++) {
      intrinsicMatrix[3 * k] = params->IntrinsicMatrixInternal[k];
      intrinsicMatrix[3 * k + 1] = params->IntrinsicMatrixInternal[k + 3];
      intrinsicMatrix[3 * k + 2] = params->IntrinsicMatrixInternal[k + 6];
    }

    varargin_2[0] = params->RadialDistortion[0];
    varargin_2[1] = params->RadialDistortion[1];
    imageSize[0] = params->TangentialDistortion[0];
    imageSize[1] = params->TangentialDistortion[1];
    xBounds[0] = stereoParams->RectificationParams.XBounds[0];
    xBounds[1] = stereoParams->RectificationParams.XBounds[1];
    yBounds[0] = stereoParams->RectificationParams.YBounds[0];
    yBounds[1] = stereoParams->RectificationParams.YBounds[1];
    H1 = stereoParams->RectificationParams.H2;
    k = stereoParams->RectifyMap2.SizeOfImage->size[0] *
      stereoParams->RectifyMap2.SizeOfImage->size[1];
    stereoParams->RectifyMap2.SizeOfImage->size[0] = 1;
    stereoParams->RectifyMap2.SizeOfImage->size[1] = 3;
    emxEnsureCapacity_real_T(stereoParams->RectifyMap2.SizeOfImage, k);
    stereoParams->RectifyMap2.SizeOfImage->data[0] = I2->size[0];
    stereoParams->RectifyMap2.SizeOfImage->data[1] = I2->size[1];
    stereoParams->RectifyMap2.SizeOfImage->data[2] = I2->size[2];
    k = stereoParams->RectifyMap2.ClassOfImage->size[0] *
      stereoParams->RectifyMap2.ClassOfImage->size[1];
    stereoParams->RectifyMap2.ClassOfImage->size[0] = 1;
    stereoParams->RectifyMap2.ClassOfImage->size[1] = 5;
    emxEnsureCapacity_char_T(stereoParams->RectifyMap2.ClassOfImage, k);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap2.ClassOfImage->data[k] = cv1[k];
    }

    k = stereoParams->RectifyMap2.OutputView->size[0] *
      stereoParams->RectifyMap2.OutputView->size[1];
    stereoParams->RectifyMap2.OutputView->size[0] = 1;
    stereoParams->RectifyMap2.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(stereoParams->RectifyMap2.OutputView, k);
    for (k = 0; k < 5; k++) {
      stereoParams->RectifyMap2.OutputView->data[k] = a[k];
    }

    stereoParams->RectifyMap2.XBounds[0] = xBounds[0];
    stereoParams->RectifyMap2.XBounds[1] = xBounds[1];
    stereoParams->RectifyMap2.YBounds[0] = yBounds[0];
    stereoParams->RectifyMap2.YBounds[1] = yBounds[1];
    b_ImageTransformer_computeMap(&stereoParams->RectifyMap2, intrinsicMatrix,
      varargin_2, imageSize, H1.T);
  }

  emxInit_real32_T(&b_stereoParams, 2);
  k = b_stereoParams->size[0] * b_stereoParams->size[1];
  b_stereoParams->size[0] = stereoParams->RectifyMap1.XmapSingle->size[0];
  b_stereoParams->size[1] = stereoParams->RectifyMap1.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(b_stereoParams, k);
  loop_ub = stereoParams->RectifyMap1.XmapSingle->size[0] *
    stereoParams->RectifyMap1.XmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    b_stereoParams->data[k] = stereoParams->RectifyMap1.XmapSingle->data[k];
  }

  emxInit_real32_T(&c_stereoParams, 2);
  k = c_stereoParams->size[0] * c_stereoParams->size[1];
  c_stereoParams->size[0] = stereoParams->RectifyMap1.YmapSingle->size[0];
  c_stereoParams->size[1] = stereoParams->RectifyMap1.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(c_stereoParams, k);
  loop_ub = stereoParams->RectifyMap1.YmapSingle->size[0] *
    stereoParams->RectifyMap1.YmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    c_stereoParams->data[k] = stereoParams->RectifyMap1.YmapSingle->data[k];
  }

  c_interp2d(I1, b_stereoParams, c_stereoParams, fillValues_data,
             fillValues_size, rectifiedImage1);
  k = b_stereoParams->size[0] * b_stereoParams->size[1];
  b_stereoParams->size[0] = stereoParams->RectifyMap2.XmapSingle->size[0];
  b_stereoParams->size[1] = stereoParams->RectifyMap2.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(b_stereoParams, k);
  loop_ub = stereoParams->RectifyMap2.XmapSingle->size[0] *
    stereoParams->RectifyMap2.XmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    b_stereoParams->data[k] = stereoParams->RectifyMap2.XmapSingle->data[k];
  }

  k = c_stereoParams->size[0] * c_stereoParams->size[1];
  c_stereoParams->size[0] = stereoParams->RectifyMap2.YmapSingle->size[0];
  c_stereoParams->size[1] = stereoParams->RectifyMap2.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(c_stereoParams, k);
  loop_ub = stereoParams->RectifyMap2.YmapSingle->size[0] *
    stereoParams->RectifyMap2.YmapSingle->size[1] - 1;
  for (k = 0; k <= loop_ub; k++) {
    c_stereoParams->data[k] = stereoParams->RectifyMap2.YmapSingle->data[k];
  }

  c_interp2d(I2, b_stereoParams, c_stereoParams, fillValues_data,
             fillValues_size, rectifiedImage2);
  emxFree_real32_T(&c_stereoParams);
  emxFree_real32_T(&b_stereoParams);
}

//
// File trailer for rectifyStereoImages.cpp
//
// [EOF]
//
