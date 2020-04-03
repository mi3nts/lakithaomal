//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: undistortImage.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "undistortImage.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "ImageTransformer.h"
#include "interp2d.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const double b_I[307200]
//                c_vision_internal_calibration_C *intrinsics
//                double J[307200]
// Return Type  : void
//
void undistortImage(const double b_I[307200], c_vision_internal_calibration_C
                    *intrinsics, double J[307200])
{
  emxArray_real_T *varargin_1;
  int i;
  int loop_ub;
  boolean_T p;
  boolean_T exitg1;
  boolean_T sameSize;
  emxArray_char_T *b;
  boolean_T sameClass;
  int exitg2;
  static const char cv[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  boolean_T sameOutputView;
  static const char cv1[4] = { 's', 'a', 'm', 'e' };

  emxArray_real_T *b_J;
  double intrinsicMatrix[9];
  double radialDist[2];
  double tangentialDist[2];
  static const char a[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  emxInit_real_T(&varargin_1, 2);
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = intrinsics->UndistortMap.SizeOfImage->size[1];
  emxEnsureCapacity_real_T(varargin_1, i);
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
      if (!(varargin_1->data[loop_ub] == 160.0 * static_cast<double>(loop_ub) +
            480.0)) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }

  emxFree_real_T(&varargin_1);
  sameSize = p;
  emxInit_char_T(&b, 2);
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = intrinsics->UndistortMap.ClassOfImage->size[1];
  emxEnsureCapacity_char_T(b, i);
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
        if (cv[loop_ub] != b->data[loop_ub]) {
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
  emxEnsureCapacity_char_T(b, i);
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
      if (!(b->data[loop_ub] == cv1[loop_ub])) {
        p = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
  }

  emxFree_char_T(&b);
  sameOutputView = p;
  if ((!sameSize) || (!sameClass) || (!sameOutputView)) {
    for (i = 0; i < 3; i++) {
      intrinsicMatrix[3 * i] = intrinsics->IntrinsicMatrixInternal[i];
      intrinsicMatrix[3 * i + 1] = intrinsics->IntrinsicMatrixInternal[i + 3];
      intrinsicMatrix[3 * i + 2] = intrinsics->IntrinsicMatrixInternal[i + 6];
    }

    i = intrinsics->UndistortMap.SizeOfImage->size[0] *
      intrinsics->UndistortMap.SizeOfImage->size[1];
    intrinsics->UndistortMap.SizeOfImage->size[0] = 1;
    intrinsics->UndistortMap.SizeOfImage->size[1] = 2;
    emxEnsureCapacity_real_T(intrinsics->UndistortMap.SizeOfImage, i);
    radialDist[0] = intrinsics->RadialDistortion[0];
    tangentialDist[0] = intrinsics->TangentialDistortion[0];
    intrinsics->UndistortMap.SizeOfImage->data[0] = 480.0;
    radialDist[1] = intrinsics->RadialDistortion[1];
    tangentialDist[1] = intrinsics->TangentialDistortion[1];
    intrinsics->UndistortMap.SizeOfImage->data[1] = 640.0;
    i = intrinsics->UndistortMap.ClassOfImage->size[0] *
      intrinsics->UndistortMap.ClassOfImage->size[1];
    intrinsics->UndistortMap.ClassOfImage->size[0] = 1;
    intrinsics->UndistortMap.ClassOfImage->size[1] = 6;
    emxEnsureCapacity_char_T(intrinsics->UndistortMap.ClassOfImage, i);
    for (i = 0; i < 6; i++) {
      intrinsics->UndistortMap.ClassOfImage->data[i] = a[i];
    }

    i = intrinsics->UndistortMap.OutputView->size[0] *
      intrinsics->UndistortMap.OutputView->size[1];
    intrinsics->UndistortMap.OutputView->size[0] = 1;
    intrinsics->UndistortMap.OutputView->size[1] = 4;
    emxEnsureCapacity_char_T(intrinsics->UndistortMap.OutputView, i);
    intrinsics->UndistortMap.OutputView->data[0] = 's';
    intrinsics->UndistortMap.OutputView->data[1] = 'a';
    intrinsics->UndistortMap.OutputView->data[2] = 'm';
    intrinsics->UndistortMap.OutputView->data[3] = 'e';
    intrinsics->UndistortMap.XBounds[0] = 1.0;
    intrinsics->UndistortMap.YBounds[0] = 1.0;
    intrinsics->UndistortMap.XBounds[1] = 640.0;
    intrinsics->UndistortMap.YBounds[1] = 480.0;
    ImageTransformer_computeMap(&intrinsics->UndistortMap, intrinsicMatrix,
      radialDist, tangentialDist);
  }

  emxInit_real_T(&b_J, 2);
  interp2d(b_I, intrinsics->UndistortMap.Xmap, intrinsics->UndistortMap.Ymap,
           b_J);
  for (i = 0; i < 640; i++) {
    for (loop_ub = 0; loop_ub < 480; loop_ub++) {
      J[loop_ub + 480 * i] = b_J->data[loop_ub + b_J->size[0] * i];
    }
  }

  emxFree_real_T(&b_J);
}

//
// File trailer for undistortImage.cpp
//
// [EOF]
//
