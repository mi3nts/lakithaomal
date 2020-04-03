//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imwarp.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "imwarp.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "inv.h"
#include "libmwimterp2d.h"
#include "meshgrid.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : const double varargin_1[307200]
//                const double varargin_2_T[9]
//                const double varargin_4_ImageSizeAlias[2]
//                emxArray_real_T *outputImage
// Return Type  : void
//
void imwarp(const double varargin_1[307200], const double varargin_2_T[9], const
            double varargin_4_ImageSizeAlias[2], emxArray_real_T *outputImage)
{
  emxArray_real_T *y;
  int i;
  int loop_ub;
  emxArray_real_T *b_y;
  emxArray_real_T *dstYIntrinsic;
  emxArray_real_T *X_T;
  emxArray_real_T *w;
  double M[9];
  emxArray_real_T *Y_T;
  double fillValues;
  double b_outputImage[2];
  double b_dv[3];
  emxInit_real_T(&y, 2);
  if (rtIsNaN(varargin_4_ImageSizeAlias[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (varargin_4_ImageSizeAlias[1] < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (rtIsInf(varargin_4_ImageSizeAlias[1]) && (1.0 ==
              varargin_4_ImageSizeAlias[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(varargin_4_ImageSizeAlias[1] - 1.0));
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&b_y, 2);
  if (rtIsNaN(varargin_4_ImageSizeAlias[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (varargin_4_ImageSizeAlias[0] < 1.0) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if (rtIsInf(varargin_4_ImageSizeAlias[0]) && (1.0 ==
              varargin_4_ImageSizeAlias[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(varargin_4_ImageSizeAlias[0] - 1.0));
    b_y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_y, i);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&dstYIntrinsic, 2);
  emxInit_real_T(&X_T, 2);
  meshgrid(y, b_y, X_T, dstYIntrinsic);
  loop_ub = X_T->size[0] * X_T->size[1];
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  for (i = 0; i < loop_ub; i++) {
    X_T->data[i] = (X_T->data[i] - 0.5) + 0.5;
  }

  loop_ub = dstYIntrinsic->size[0] * dstYIntrinsic->size[1];
  for (i = 0; i < loop_ub; i++) {
    dstYIntrinsic->data[i] = (dstYIntrinsic->data[i] - 0.5) + 0.5;
  }

  emxInit_real_T(&w, 2);
  inv(varargin_2_T, M);
  i = w->size[0] * w->size[1];
  w->size[0] = X_T->size[0];
  w->size[1] = X_T->size[1];
  emxEnsureCapacity_real_T(w, i);
  loop_ub = X_T->size[0] * X_T->size[1];
  for (i = 0; i < loop_ub; i++) {
    w->data[i] = (M[6] * X_T->data[i] + M[7] * dstYIntrinsic->data[i]) + M[8];
  }

  emxInit_real_T(&Y_T, 2);
  i = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = X_T->size[0];
  Y_T->size[1] = X_T->size[1];
  emxEnsureCapacity_real_T(Y_T, i);
  loop_ub = X_T->size[0] * X_T->size[1];
  for (i = 0; i < loop_ub; i++) {
    Y_T->data[i] = (((M[0] * X_T->data[i] + M[1] * dstYIntrinsic->data[i]) + M[2])
                    / w->data[i] - 0.5) + 0.5;
  }

  loop_ub = X_T->size[0] * X_T->size[1];
  for (i = 0; i < loop_ub; i++) {
    X_T->data[i] = (((M[3] * X_T->data[i] + M[4] * dstYIntrinsic->data[i]) + M[5])
                    / w->data[i] - 0.5) + 0.5;
  }

  emxFree_real_T(&w);
  emxFree_real_T(&dstYIntrinsic);
  i = outputImage->size[0] * outputImage->size[1];
  outputImage->size[0] = Y_T->size[0];
  outputImage->size[1] = Y_T->size[1];
  emxEnsureCapacity_real_T(outputImage, i);
  fillValues = 0.0;
  b_outputImage[0] = Y_T->size[0];
  b_outputImage[1] = Y_T->size[1];
  b_dv[0] = dv1[0];
  b_dv[1] = dv1[1];
  b_dv[2] = dv1[2];
  imterp2d64f_real64(varargin_1, b_dv, &X_T->data[0], &Y_T->data[0],
                     b_outputImage, 2.0, true, &fillValues, &outputImage->data[0]);
  emxFree_real_T(&Y_T);
  emxFree_real_T(&X_T);
}

//
// File trailer for imwarp.cpp
//
// [EOF]
//
