//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CameraParametersImpl.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "CameraParametersImpl.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "F_02_getImageData_rtwutil.h"
#include "ImageTransformer.h"
#include "StereoParametersImpl.h"
#include "bwtraceboundary.h"
#include "colon.h"
#include "distortPoints.h"
#include "interp2d.h"
#include "meshgrid.h"
#include "regionprops.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <cmath>

// Function Declarations
static void c_CameraParametersImpl_createUn(const
  d_vision_internal_calibration_C *b_this, const double imageSize[2],
  emxArray_uint8_T *undistortedMask, double xBoundsBig[2], double yBoundsBig[2]);
static void d_CameraParametersImpl_createUn(const
  d_vision_internal_calibration_C *b_this, const double imageSize[2],
  emxArray_uint8_T *undistortedMask, double xBoundsBig[2], double yBoundsBig[2]);
static void getInitialBoundaryPixel(const emxArray_uint8_T *undistortedMask,
  double boundaryPixel[2]);

// Function Definitions

//
// Arguments    : const d_vision_internal_calibration_C *b_this
//                const double imageSize[2]
//                emxArray_uint8_T *undistortedMask
//                double xBoundsBig[2]
//                double yBoundsBig[2]
// Return Type  : void
//
static void c_CameraParametersImpl_createUn(const
  d_vision_internal_calibration_C *b_this, const double imageSize[2],
  emxArray_uint8_T *undistortedMask, double xBoundsBig[2], double yBoundsBig[2])
{
  c_vision_internal_calibration_I myMap;
  emxArray_real_T *y;
  int i;
  int loop_ub;
  emxArray_real_T *b_y;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *b_X;
  int nx;
  emxArray_real_T *ptsOut;
  double c_this[9];
  emxArray_uint8_T *mask;
  int indices_tmp_idx_0;
  int i1;
  int loop_ub_tmp;
  emxArray_real_T *x;
  int k;
  emxArray_real_T *b_x;
  emxArray_real_T *c_x;
  emxArray_real_T *d_x;
  emxArray_real_T *e_x;
  emxArray_real_T *allPts;
  emxArray_boolean_T *insideImage;
  double numUnmapped;
  double b_tmp;
  emxArray_int32_T *r;
  emxArray_real_T *b_allPts;
  double numUnmapped_tmp;
  emxArray_uint8_T b_mask;
  int c_X[1];
  double p1_idx_0;
  double p1_idx_1;
  double p2_idx_0;
  double p2_idx_1;
  int numTrials;
  emxArray_real_T *newPts;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  cell_wrap_26 reshapes[2];
  cell_wrap_26 b_reshapes[2];
  cell_wrap_26 c_reshapes[2];
  cell_wrap_26 d_reshapes[2];
  double w;
  double h;
  double lastNumUnmapped;
  static const char cv[5] = { 'u', 'i', 'n', 't', '8' };

  static const char outputView[5] = { 'v', 'a', 'l', 'i', 'd' };

  emxArray_real32_T *b_myMap;
  emxArray_real32_T *c_myMap;
  int d_X[1];
  d_emxInitStruct_vision_internal(&myMap);
  emxInit_real_T(&y, 2);
  xBoundsBig[0] = 1.0;
  xBoundsBig[1] = imageSize[1];
  yBoundsBig[0] = 1.0;
  yBoundsBig[1] = imageSize[0];
  if (rtIsNaN(imageSize[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (imageSize[1] < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (rtIsInf(imageSize[1]) && (1.0 == imageSize[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(imageSize[1] - 1.0));
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&b_y, 2);
  if (rtIsNaN(imageSize[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (imageSize[0] < 1.0) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if (rtIsInf(imageSize[0]) && (1.0 == imageSize[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(imageSize[0] - 1.0));
    b_y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_y, i);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&X, 2);
  emxInit_real_T(&Y, 2);
  emxInit_real_T(&b_X, 2);
  meshgrid(y, b_y, X, Y);
  loop_ub = X->size[0] * X->size[1];
  nx = Y->size[0] * Y->size[1];
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = loop_ub;
  b_X->size[1] = 2;
  emxEnsureCapacity_real_T(b_X, i);
  emxFree_real_T(&b_y);
  for (i = 0; i < loop_ub; i++) {
    b_X->data[i] = X->data[i];
  }

  emxFree_real_T(&X);
  for (i = 0; i < nx; i++) {
    b_X->data[i + b_X->size[0]] = Y->data[i];
  }

  emxFree_real_T(&Y);
  for (i = 0; i < 3; i++) {
    c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
    c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  emxInit_real_T(&ptsOut, 2);
  emxInit_uint8_T(&mask, 2);
  distortPoints(b_X, c_this, b_this->RadialDistortion,
                b_this->TangentialDistortion, ptsOut);
  indices_tmp_idx_0 = static_cast<int>(imageSize[0]);
  i = mask->size[0] * mask->size[1];
  mask->size[0] = indices_tmp_idx_0;
  i1 = static_cast<int>(imageSize[1]);
  mask->size[1] = i1;
  emxEnsureCapacity_uint8_T(mask, i);
  loop_ub_tmp = indices_tmp_idx_0 * i1;
  for (i = 0; i < loop_ub_tmp; i++) {
    mask->data[i] = 0U;
  }

  emxInit_real_T(&x, 1);
  loop_ub = ptsOut->size[0];
  i = x->size[0];
  x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(x, i);
  for (i = 0; i < loop_ub; i++) {
    x->data[i] = ptsOut->data[i];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    x->data[k] = std::floor(x->data[k]);
  }

  emxInit_real_T(&b_x, 1);
  loop_ub = ptsOut->size[0];
  i = b_x->size[0];
  b_x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(b_x, i);
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = ptsOut->data[i + ptsOut->size[0]];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    b_x->data[k] = std::ceil(b_x->data[k]);
  }

  emxInit_real_T(&c_x, 1);
  loop_ub = ptsOut->size[0];
  i = c_x->size[0];
  c_x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(c_x, i);
  for (i = 0; i < loop_ub; i++) {
    c_x->data[i] = ptsOut->data[i];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    c_x->data[k] = std::ceil(c_x->data[k]);
  }

  emxInit_real_T(&d_x, 1);
  loop_ub = ptsOut->size[0];
  i = d_x->size[0];
  d_x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(d_x, i);
  for (i = 0; i < loop_ub; i++) {
    d_x->data[i] = ptsOut->data[i + ptsOut->size[0]];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    d_x->data[k] = std::floor(d_x->data[k]);
  }

  emxInit_real_T(&e_x, 2);
  i = e_x->size[0] * e_x->size[1];
  e_x->size[0] = ptsOut->size[0];
  e_x->size[1] = 2;
  emxEnsureCapacity_real_T(e_x, i);
  loop_ub = ptsOut->size[0] * ptsOut->size[1];
  for (i = 0; i < loop_ub; i++) {
    e_x->data[i] = ptsOut->data[i];
  }

  nx = ptsOut->size[0] << 1;
  for (k = 0; k < nx; k++) {
    e_x->data[k] = std::floor(e_x->data[k]);
  }

  nx = ptsOut->size[0] << 1;
  for (k = 0; k < nx; k++) {
    ptsOut->data[k] = std::ceil(ptsOut->data[k]);
  }

  emxInit_real_T(&allPts, 2);
  i = allPts->size[0] * allPts->size[1];
  allPts->size[0] = ((e_x->size[0] + x->size[0]) + c_x->size[0]) + ptsOut->size
    [0];
  allPts->size[1] = 2;
  emxEnsureCapacity_real_T(allPts, i);
  loop_ub = e_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[i] = e_x->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    allPts->data[i + allPts->size[0]] = e_x->data[i + e_x->size[0]];
  }

  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[i + e_x->size[0]] = x->data[i];
  }

  loop_ub = b_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[(i + e_x->size[0]) + allPts->size[0]] = b_x->data[i];
  }

  loop_ub = c_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[(i + e_x->size[0]) + x->size[0]] = c_x->data[i];
  }

  loop_ub = d_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[((i + e_x->size[0]) + x->size[0]) + allPts->size[0]] =
      d_x->data[i];
  }

  loop_ub = ptsOut->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[((i + e_x->size[0]) + x->size[0]) + c_x->size[0]] =
      ptsOut->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    allPts->data[(((i + e_x->size[0]) + x->size[0]) + c_x->size[0]) +
      allPts->size[0]] = ptsOut->data[i + ptsOut->size[0]];
  }

  emxInit_boolean_T(&insideImage, 1);
  loop_ub = allPts->size[0];
  i = insideImage->size[0];
  insideImage->size[0] = allPts->size[0];
  emxEnsureCapacity_boolean_T(insideImage, i);
  for (i = 0; i < loop_ub; i++) {
    numUnmapped = allPts->data[i];
    b_tmp = allPts->data[i + allPts->size[0]];
    insideImage->data[i] = ((numUnmapped >= 1.0) && (b_tmp >= 1.0) &&
      (numUnmapped <= imageSize[1]) && (b_tmp <= imageSize[0]));
  }

  k = insideImage->size[0] - 1;
  nx = 0;
  for (loop_ub = 0; loop_ub <= k; loop_ub++) {
    if (insideImage->data[loop_ub]) {
      nx++;
    }
  }

  emxInit_int32_T(&r, 1);
  i = r->size[0];
  r->size[0] = nx;
  emxEnsureCapacity_int32_T(r, i);
  nx = 0;
  for (loop_ub = 0; loop_ub <= k; loop_ub++) {
    if (insideImage->data[loop_ub]) {
      r->data[nx] = loop_ub + 1;
      nx++;
    }
  }

  emxInit_real_T(&b_allPts, 2);
  i = b_allPts->size[0] * b_allPts->size[1];
  b_allPts->size[0] = r->size[0];
  b_allPts->size[1] = 2;
  emxEnsureCapacity_real_T(b_allPts, i);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_allPts->data[i] = allPts->data[r->data[i] - 1];
  }

  for (i = 0; i < loop_ub; i++) {
    b_allPts->data[i + b_allPts->size[0]] = allPts->data[(r->data[i] +
      allPts->size[0]) - 1];
  }

  i = allPts->size[0] * allPts->size[1];
  allPts->size[0] = b_allPts->size[0];
  allPts->size[1] = 2;
  emxEnsureCapacity_real_T(allPts, i);
  loop_ub = b_allPts->size[0] * b_allPts->size[1];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[i] = b_allPts->data[i];
  }

  emxFree_real_T(&b_allPts);
  loop_ub = allPts->size[0];
  i = r->size[0];
  r->size[0] = allPts->size[0];
  emxEnsureCapacity_int32_T(r, i);
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = static_cast<int>(allPts->data[i + allPts->size[0]]) +
      indices_tmp_idx_0 * (static_cast<int>(allPts->data[i]) - 1);
  }

  emxFree_real_T(&allPts);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    mask->data[r->data[i] - 1] = 1U;
  }

  emxFree_int32_T(&r);
  numUnmapped_tmp = imageSize[0] * imageSize[1];
  loop_ub = mask->size[0] * mask->size[1];
  b_mask = *mask;
  c_X[0] = loop_ub;
  b_mask.size = &c_X[0];
  nx = b_mask.size[0];
  if (b_mask.size[0] == 0) {
    numUnmapped = 0.0;
  } else {
    numUnmapped = b_mask.data[0];
    for (k = 2; k <= nx; k++) {
      numUnmapped += static_cast<double>(b_mask.data[k - 1]);
    }
  }

  numUnmapped = numUnmapped_tmp - numUnmapped;
  if (numUnmapped > 0.0) {
    p1_idx_0 = 1.0;
    p1_idx_1 = 1.0;
    p2_idx_0 = imageSize[1];
    p2_idx_1 = imageSize[0];
    numTrials = 0;
    emxInit_real_T(&newPts, 2);
    emxInit_int32_T(&r1, 1);
    emxInit_int32_T(&r2, 1);
    emxInitMatrix_cell_wrap_26(reshapes);
    emxInitMatrix_cell_wrap_26(b_reshapes);
    emxInitMatrix_cell_wrap_26(c_reshapes);
    emxInitMatrix_cell_wrap_26(d_reshapes);
    while ((numTrials < 5) && (numUnmapped > 0.0)) {
      p1_idx_0--;
      p2_idx_0++;
      p1_idx_1--;
      p2_idx_1++;
      w = (p2_idx_0 - p1_idx_0) + 1.0;
      h = (p2_idx_1 - p1_idx_1) + 1.0;
      lastNumUnmapped = numUnmapped;
      b_tmp = (p1_idx_0 + w) - 1.0;
      if (rtIsNaN(b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (b_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_0) || rtIsInf(b_tmp)) && (p1_idx_0 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = static_cast<int>(std::floor(b_tmp - p1_idx_0));
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= loop_ub; i++) {
          y->data[i] = p1_idx_0 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_0, b_tmp, y);
      }

      i = reshapes[0].f1->size[0];
      reshapes[0].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(reshapes[0].f1, i);
      loop_ub = y->size[1];
      for (i = 0; i < loop_ub; i++) {
        reshapes[0].f1->data[i] = y->data[i];
      }

      loop_ub = static_cast<int>(w);
      i = reshapes[1].f1->size[0];
      reshapes[1].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(reshapes[1].f1, i);
      for (i = 0; i < loop_ub; i++) {
        reshapes[1].f1->data[i] = p1_idx_1;
      }

      if (b_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_0) || rtIsInf(b_tmp)) && (p1_idx_0 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        nx = static_cast<int>(std::floor(b_tmp - p1_idx_0));
        y->size[1] = nx + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= nx; i++) {
          y->data[i] = p1_idx_0 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_0, b_tmp, y);
      }

      i = b_reshapes[0].f1->size[0];
      b_reshapes[0].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(b_reshapes[0].f1, i);
      nx = y->size[1];
      for (i = 0; i < nx; i++) {
        b_reshapes[0].f1->data[i] = y->data[i];
      }

      i = b_reshapes[1].f1->size[0];
      b_reshapes[1].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(b_reshapes[1].f1, i);
      for (i = 0; i < loop_ub; i++) {
        b_reshapes[1].f1->data[i] = p2_idx_1;
      }

      b_tmp = (p1_idx_1 + h) - 1.0;
      if (b_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_1) || rtIsInf(b_tmp)) && (p1_idx_1 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = static_cast<int>(std::floor(b_tmp - p1_idx_1));
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= loop_ub; i++) {
          y->data[i] = p1_idx_1 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_1, b_tmp, y);
      }

      loop_ub = static_cast<int>(h);
      i = c_reshapes[0].f1->size[0];
      c_reshapes[0].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(c_reshapes[0].f1, i);
      for (i = 0; i < loop_ub; i++) {
        c_reshapes[0].f1->data[i] = p1_idx_0;
      }

      i = c_reshapes[1].f1->size[0];
      c_reshapes[1].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(c_reshapes[1].f1, i);
      nx = y->size[1];
      for (i = 0; i < nx; i++) {
        c_reshapes[1].f1->data[i] = y->data[i];
      }

      if (b_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_1) || rtIsInf(b_tmp)) && (p1_idx_1 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        nx = static_cast<int>(std::floor(b_tmp - p1_idx_1));
        y->size[1] = nx + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= nx; i++) {
          y->data[i] = p1_idx_1 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_1, b_tmp, y);
      }

      i = d_reshapes[0].f1->size[0];
      d_reshapes[0].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(d_reshapes[0].f1, i);
      for (i = 0; i < loop_ub; i++) {
        d_reshapes[0].f1->data[i] = p2_idx_0;
      }

      i = d_reshapes[1].f1->size[0];
      d_reshapes[1].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(d_reshapes[1].f1, i);
      loop_ub = y->size[1];
      for (i = 0; i < loop_ub; i++) {
        d_reshapes[1].f1->data[i] = y->data[i];
      }

      i = b_X->size[0] * b_X->size[1];
      b_X->size[0] = ((reshapes[0].f1->size[0] + b_reshapes[0].f1->size[0]) +
                      c_reshapes[0].f1->size[0]) + d_reshapes[0].f1->size[0];
      b_X->size[1] = 2;
      emxEnsureCapacity_real_T(b_X, i);
      loop_ub = reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i] = reshapes[0].f1->data[i];
      }

      loop_ub = reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i + b_X->size[0]] = reshapes[1].f1->data[i];
      }

      loop_ub = b_reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i + reshapes[0].f1->size[0]] = b_reshapes[0].f1->data[i];
      }

      loop_ub = b_reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[(i + reshapes[0].f1->size[0]) + b_X->size[0]] = b_reshapes[1].
          f1->data[i];
      }

      loop_ub = c_reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[(i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]] =
          c_reshapes[0].f1->data[i];
      }

      loop_ub = c_reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[((i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]) +
          b_X->size[0]] = c_reshapes[1].f1->data[i];
      }

      loop_ub = d_reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[((i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]) +
          c_reshapes[0].f1->size[0]] = d_reshapes[0].f1->data[i];
      }

      loop_ub = d_reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[(((i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]) +
                   c_reshapes[0].f1->size[0]) + b_X->size[0]] = d_reshapes[1].
          f1->data[i];
      }

      for (i = 0; i < 3; i++) {
        c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
        c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
        c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
      }

      distortPoints(b_X, c_this, b_this->RadialDistortion,
                    b_this->TangentialDistortion, ptsOut);
      loop_ub = ptsOut->size[0];
      i = x->size[0];
      x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(x, i);
      i = b_x->size[0];
      b_x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(b_x, i);
      i = c_x->size[0];
      c_x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(c_x, i);
      i = d_x->size[0];
      d_x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(d_x, i);
      for (k = 0; k < loop_ub; k++) {
        numUnmapped = ptsOut->data[k];
        x->data[k] = std::floor(numUnmapped);
        b_tmp = ptsOut->data[k + ptsOut->size[0]];
        b_x->data[k] = std::ceil(b_tmp);
        c_x->data[k] = std::ceil(numUnmapped);
        d_x->data[k] = std::floor(b_tmp);
      }

      i = e_x->size[0] * e_x->size[1];
      e_x->size[0] = ptsOut->size[0];
      e_x->size[1] = 2;
      emxEnsureCapacity_real_T(e_x, i);
      loop_ub = ptsOut->size[0] * ptsOut->size[1];
      for (i = 0; i < loop_ub; i++) {
        e_x->data[i] = ptsOut->data[i];
      }

      nx = ptsOut->size[0] << 1;
      for (k = 0; k < nx; k++) {
        e_x->data[k] = std::floor(e_x->data[k]);
        ptsOut->data[k] = std::ceil(ptsOut->data[k]);
      }

      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = ((e_x->size[0] + x->size[0]) + c_x->size[0]) +
        ptsOut->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(newPts, i);
      loop_ub = e_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[i] = e_x->data[i];
      }

      for (i = 0; i < loop_ub; i++) {
        newPts->data[i + newPts->size[0]] = e_x->data[i + e_x->size[0]];
      }

      loop_ub = x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[i + e_x->size[0]] = x->data[i];
      }

      loop_ub = b_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[(i + e_x->size[0]) + newPts->size[0]] = b_x->data[i];
      }

      loop_ub = c_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[(i + e_x->size[0]) + x->size[0]] = c_x->data[i];
      }

      loop_ub = d_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[((i + e_x->size[0]) + x->size[0]) + newPts->size[0]] =
          d_x->data[i];
      }

      loop_ub = ptsOut->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[((i + e_x->size[0]) + x->size[0]) + c_x->size[0]] =
          ptsOut->data[i];
      }

      for (i = 0; i < loop_ub; i++) {
        newPts->data[(((i + e_x->size[0]) + x->size[0]) + c_x->size[0]) +
          newPts->size[0]] = ptsOut->data[i + ptsOut->size[0]];
      }

      loop_ub = newPts->size[0];
      i = insideImage->size[0];
      insideImage->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(insideImage, i);
      for (i = 0; i < loop_ub; i++) {
        numUnmapped = newPts->data[i];
        b_tmp = newPts->data[i + newPts->size[0]];
        insideImage->data[i] = ((numUnmapped >= 1.0) && (b_tmp >= 1.0) &&
          (numUnmapped <= imageSize[1]) && (b_tmp <= imageSize[0]));
      }

      k = insideImage->size[0] - 1;
      nx = 0;
      for (loop_ub = 0; loop_ub <= k; loop_ub++) {
        if (insideImage->data[loop_ub]) {
          nx++;
        }
      }

      i = r2->size[0];
      r2->size[0] = nx;
      emxEnsureCapacity_int32_T(r2, i);
      nx = 0;
      for (loop_ub = 0; loop_ub <= k; loop_ub++) {
        if (insideImage->data[loop_ub]) {
          r2->data[nx] = loop_ub + 1;
          nx++;
        }
      }

      i = b_X->size[0] * b_X->size[1];
      b_X->size[0] = r2->size[0];
      b_X->size[1] = 2;
      emxEnsureCapacity_real_T(b_X, i);
      loop_ub = r2->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i] = newPts->data[r2->data[i] - 1];
      }

      for (i = 0; i < loop_ub; i++) {
        b_X->data[i + b_X->size[0]] = newPts->data[(r2->data[i] + newPts->size[0])
          - 1];
      }

      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = b_X->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(newPts, i);
      loop_ub = b_X->size[0] * b_X->size[1];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[i] = b_X->data[i];
      }

      loop_ub = newPts->size[0];
      i = r1->size[0];
      r1->size[0] = newPts->size[0];
      emxEnsureCapacity_int32_T(r1, i);
      for (i = 0; i < loop_ub; i++) {
        r1->data[i] = static_cast<int>(newPts->data[i + newPts->size[0]]) +
          indices_tmp_idx_0 * (static_cast<int>(newPts->data[i]) - 1);
      }

      loop_ub = r1->size[0] - 1;
      for (i = 0; i <= loop_ub; i++) {
        mask->data[r1->data[i] - 1] = 1U;
      }

      loop_ub = mask->size[0] * mask->size[1];
      b_mask = *mask;
      d_X[0] = loop_ub;
      b_mask.size = &d_X[0];
      nx = b_mask.size[0];
      if (b_mask.size[0] == 0) {
        numUnmapped = 0.0;
      } else {
        numUnmapped = b_mask.data[0];
        for (k = 2; k <= nx; k++) {
          numUnmapped += static_cast<double>(b_mask.data[k - 1]);
        }
      }

      numUnmapped = numUnmapped_tmp - numUnmapped;
      if (lastNumUnmapped == numUnmapped) {
        numTrials++;
      } else {
        numTrials = 0;
      }

      xBoundsBig[0] = p1_idx_0;
      xBoundsBig[1] = p2_idx_0;
      yBoundsBig[0] = p1_idx_1;
      yBoundsBig[1] = p2_idx_1;
    }

    emxFreeMatrix_cell_wrap_26(d_reshapes);
    emxFreeMatrix_cell_wrap_26(c_reshapes);
    emxFreeMatrix_cell_wrap_26(b_reshapes);
    emxFreeMatrix_cell_wrap_26(reshapes);
    emxFree_int32_T(&r2);
    emxFree_int32_T(&r1);
    emxFree_real_T(&newPts);
  }

  emxFree_real_T(&b_X);
  emxFree_real_T(&e_x);
  emxFree_real_T(&d_x);
  emxFree_real_T(&c_x);
  emxFree_real_T(&b_x);
  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emxFree_boolean_T(&insideImage);
  emxFree_real_T(&ptsOut);
  c_ImageTransformer_ImageTransfo(&myMap);
  i = myMap.SizeOfImage->size[0] * myMap.SizeOfImage->size[1];
  myMap.SizeOfImage->size[0] = 1;
  myMap.SizeOfImage->size[1] = 2;
  emxEnsureCapacity_real_T(myMap.SizeOfImage, i);
  myMap.SizeOfImage->data[0] = indices_tmp_idx_0;
  myMap.SizeOfImage->data[1] = i1;
  i = myMap.ClassOfImage->size[0] * myMap.ClassOfImage->size[1];
  myMap.ClassOfImage->size[0] = 1;
  myMap.ClassOfImage->size[1] = 5;
  emxEnsureCapacity_char_T(myMap.ClassOfImage, i);
  for (i = 0; i < 5; i++) {
    myMap.ClassOfImage->data[i] = cv[i];
  }

  i = myMap.OutputView->size[0] * myMap.OutputView->size[1];
  myMap.OutputView->size[0] = 1;
  myMap.OutputView->size[1] = 5;
  emxEnsureCapacity_char_T(myMap.OutputView, i);
  for (i = 0; i < 5; i++) {
    myMap.OutputView->data[i] = outputView[i];
  }

  myMap.XBounds[0] = xBoundsBig[0];
  myMap.XBounds[1] = xBoundsBig[1];
  myMap.YBounds[0] = yBoundsBig[0];
  myMap.YBounds[1] = yBoundsBig[1];
  for (i = 0; i < 3; i++) {
    c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
    c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  ImageTransformer_computeMap(&myMap, c_this, b_this->RadialDistortion,
    b_this->TangentialDistortion);
  i = mask->size[0] * mask->size[1];
  mask->size[0] = indices_tmp_idx_0;
  mask->size[1] = i1;
  emxEnsureCapacity_uint8_T(mask, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mask->data[i] = 1U;
  }

  emxInit_real32_T(&b_myMap, 2);
  i = b_myMap->size[0] * b_myMap->size[1];
  b_myMap->size[0] = myMap.XmapSingle->size[0];
  b_myMap->size[1] = myMap.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(b_myMap, i);
  loop_ub = myMap.XmapSingle->size[0] * myMap.XmapSingle->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_myMap->data[i] = myMap.XmapSingle->data[i];
  }

  emxInit_real32_T(&c_myMap, 2);
  i = c_myMap->size[0] * c_myMap->size[1];
  c_myMap->size[0] = myMap.YmapSingle->size[0];
  c_myMap->size[1] = myMap.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(c_myMap, i);
  loop_ub = myMap.YmapSingle->size[0] * myMap.YmapSingle->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    c_myMap->data[i] = myMap.YmapSingle->data[i];
  }

  b_interp2d(mask, b_myMap, c_myMap, undistortedMask);
  emxFree_real32_T(&c_myMap);
  emxFree_real32_T(&b_myMap);
  emxFree_uint8_T(&mask);
  c_emxFreeStruct_vision_internal(&myMap);
}

//
// Arguments    : const d_vision_internal_calibration_C *b_this
//                const double imageSize[2]
//                emxArray_uint8_T *undistortedMask
//                double xBoundsBig[2]
//                double yBoundsBig[2]
// Return Type  : void
//
static void d_CameraParametersImpl_createUn(const
  d_vision_internal_calibration_C *b_this, const double imageSize[2],
  emxArray_uint8_T *undistortedMask, double xBoundsBig[2], double yBoundsBig[2])
{
  c_vision_internal_calibration_I myMap;
  emxArray_real_T *y;
  int i;
  int loop_ub;
  emxArray_real_T *b_y;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *b_X;
  int nx;
  emxArray_real_T *ptsOut;
  double c_this[9];
  emxArray_uint8_T *mask;
  int indices_tmp_idx_0;
  int i1;
  int loop_ub_tmp;
  emxArray_real_T *x;
  int k;
  emxArray_real_T *b_x;
  emxArray_real_T *c_x;
  emxArray_real_T *d_x;
  emxArray_real_T *e_x;
  emxArray_real_T *allPts;
  emxArray_boolean_T *insideImage;
  double numUnmapped;
  double b_tmp;
  emxArray_int32_T *r;
  emxArray_real_T *b_allPts;
  double numUnmapped_tmp;
  emxArray_uint8_T b_mask;
  int c_X[1];
  double p1_idx_0;
  double p1_idx_1;
  double p2_idx_0;
  double p2_idx_1;
  int numTrials;
  emxArray_real_T *newPts;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  cell_wrap_26 reshapes[2];
  cell_wrap_26 b_reshapes[2];
  cell_wrap_26 c_reshapes[2];
  cell_wrap_26 d_reshapes[2];
  double w;
  double h;
  double lastNumUnmapped;
  static const char cv[5] = { 'u', 'i', 'n', 't', '8' };

  emxArray_real32_T *b_myMap;
  emxArray_real32_T *c_myMap;
  int d_X[1];
  d_emxInitStruct_vision_internal(&myMap);
  emxInit_real_T(&y, 2);
  xBoundsBig[0] = 1.0;
  xBoundsBig[1] = imageSize[1];
  yBoundsBig[0] = 1.0;
  yBoundsBig[1] = imageSize[0];
  if (rtIsNaN(imageSize[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (imageSize[1] < 1.0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if (rtIsInf(imageSize[1]) && (1.0 == imageSize[1])) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(imageSize[1] - 1.0));
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&b_y, 2);
  if (rtIsNaN(imageSize[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (imageSize[0] < 1.0) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if (rtIsInf(imageSize[0]) && (1.0 == imageSize[0])) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(imageSize[0] - 1.0));
    b_y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_y, i);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&X, 2);
  emxInit_real_T(&Y, 2);
  emxInit_real_T(&b_X, 2);
  meshgrid(y, b_y, X, Y);
  loop_ub = X->size[0] * X->size[1];
  nx = Y->size[0] * Y->size[1];
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = loop_ub;
  b_X->size[1] = 2;
  emxEnsureCapacity_real_T(b_X, i);
  emxFree_real_T(&b_y);
  for (i = 0; i < loop_ub; i++) {
    b_X->data[i] = X->data[i];
  }

  emxFree_real_T(&X);
  for (i = 0; i < nx; i++) {
    b_X->data[i + b_X->size[0]] = Y->data[i];
  }

  emxFree_real_T(&Y);
  for (i = 0; i < 3; i++) {
    c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
    c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  emxInit_real_T(&ptsOut, 2);
  emxInit_uint8_T(&mask, 2);
  distortPoints(b_X, c_this, b_this->RadialDistortion,
                b_this->TangentialDistortion, ptsOut);
  indices_tmp_idx_0 = static_cast<int>(imageSize[0]);
  i = mask->size[0] * mask->size[1];
  mask->size[0] = indices_tmp_idx_0;
  i1 = static_cast<int>(imageSize[1]);
  mask->size[1] = i1;
  emxEnsureCapacity_uint8_T(mask, i);
  loop_ub_tmp = indices_tmp_idx_0 * i1;
  for (i = 0; i < loop_ub_tmp; i++) {
    mask->data[i] = 0U;
  }

  emxInit_real_T(&x, 1);
  loop_ub = ptsOut->size[0];
  i = x->size[0];
  x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(x, i);
  for (i = 0; i < loop_ub; i++) {
    x->data[i] = ptsOut->data[i];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    x->data[k] = std::floor(x->data[k]);
  }

  emxInit_real_T(&b_x, 1);
  loop_ub = ptsOut->size[0];
  i = b_x->size[0];
  b_x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(b_x, i);
  for (i = 0; i < loop_ub; i++) {
    b_x->data[i] = ptsOut->data[i + ptsOut->size[0]];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    b_x->data[k] = std::ceil(b_x->data[k]);
  }

  emxInit_real_T(&c_x, 1);
  loop_ub = ptsOut->size[0];
  i = c_x->size[0];
  c_x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(c_x, i);
  for (i = 0; i < loop_ub; i++) {
    c_x->data[i] = ptsOut->data[i];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    c_x->data[k] = std::ceil(c_x->data[k]);
  }

  emxInit_real_T(&d_x, 1);
  loop_ub = ptsOut->size[0];
  i = d_x->size[0];
  d_x->size[0] = ptsOut->size[0];
  emxEnsureCapacity_real_T(d_x, i);
  for (i = 0; i < loop_ub; i++) {
    d_x->data[i] = ptsOut->data[i + ptsOut->size[0]];
  }

  i = ptsOut->size[0] - 1;
  for (k = 0; k <= i; k++) {
    d_x->data[k] = std::floor(d_x->data[k]);
  }

  emxInit_real_T(&e_x, 2);
  i = e_x->size[0] * e_x->size[1];
  e_x->size[0] = ptsOut->size[0];
  e_x->size[1] = 2;
  emxEnsureCapacity_real_T(e_x, i);
  loop_ub = ptsOut->size[0] * ptsOut->size[1];
  for (i = 0; i < loop_ub; i++) {
    e_x->data[i] = ptsOut->data[i];
  }

  nx = ptsOut->size[0] << 1;
  for (k = 0; k < nx; k++) {
    e_x->data[k] = std::floor(e_x->data[k]);
  }

  nx = ptsOut->size[0] << 1;
  for (k = 0; k < nx; k++) {
    ptsOut->data[k] = std::ceil(ptsOut->data[k]);
  }

  emxInit_real_T(&allPts, 2);
  i = allPts->size[0] * allPts->size[1];
  allPts->size[0] = ((e_x->size[0] + x->size[0]) + c_x->size[0]) + ptsOut->size
    [0];
  allPts->size[1] = 2;
  emxEnsureCapacity_real_T(allPts, i);
  loop_ub = e_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[i] = e_x->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    allPts->data[i + allPts->size[0]] = e_x->data[i + e_x->size[0]];
  }

  loop_ub = x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[i + e_x->size[0]] = x->data[i];
  }

  loop_ub = b_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[(i + e_x->size[0]) + allPts->size[0]] = b_x->data[i];
  }

  loop_ub = c_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[(i + e_x->size[0]) + x->size[0]] = c_x->data[i];
  }

  loop_ub = d_x->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[((i + e_x->size[0]) + x->size[0]) + allPts->size[0]] =
      d_x->data[i];
  }

  loop_ub = ptsOut->size[0];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[((i + e_x->size[0]) + x->size[0]) + c_x->size[0]] =
      ptsOut->data[i];
  }

  for (i = 0; i < loop_ub; i++) {
    allPts->data[(((i + e_x->size[0]) + x->size[0]) + c_x->size[0]) +
      allPts->size[0]] = ptsOut->data[i + ptsOut->size[0]];
  }

  emxInit_boolean_T(&insideImage, 1);
  loop_ub = allPts->size[0];
  i = insideImage->size[0];
  insideImage->size[0] = allPts->size[0];
  emxEnsureCapacity_boolean_T(insideImage, i);
  for (i = 0; i < loop_ub; i++) {
    numUnmapped = allPts->data[i];
    b_tmp = allPts->data[i + allPts->size[0]];
    insideImage->data[i] = ((numUnmapped >= 1.0) && (b_tmp >= 1.0) &&
      (numUnmapped <= imageSize[1]) && (b_tmp <= imageSize[0]));
  }

  k = insideImage->size[0] - 1;
  nx = 0;
  for (loop_ub = 0; loop_ub <= k; loop_ub++) {
    if (insideImage->data[loop_ub]) {
      nx++;
    }
  }

  emxInit_int32_T(&r, 1);
  i = r->size[0];
  r->size[0] = nx;
  emxEnsureCapacity_int32_T(r, i);
  nx = 0;
  for (loop_ub = 0; loop_ub <= k; loop_ub++) {
    if (insideImage->data[loop_ub]) {
      r->data[nx] = loop_ub + 1;
      nx++;
    }
  }

  emxInit_real_T(&b_allPts, 2);
  i = b_allPts->size[0] * b_allPts->size[1];
  b_allPts->size[0] = r->size[0];
  b_allPts->size[1] = 2;
  emxEnsureCapacity_real_T(b_allPts, i);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_allPts->data[i] = allPts->data[r->data[i] - 1];
  }

  for (i = 0; i < loop_ub; i++) {
    b_allPts->data[i + b_allPts->size[0]] = allPts->data[(r->data[i] +
      allPts->size[0]) - 1];
  }

  i = allPts->size[0] * allPts->size[1];
  allPts->size[0] = b_allPts->size[0];
  allPts->size[1] = 2;
  emxEnsureCapacity_real_T(allPts, i);
  loop_ub = b_allPts->size[0] * b_allPts->size[1];
  for (i = 0; i < loop_ub; i++) {
    allPts->data[i] = b_allPts->data[i];
  }

  emxFree_real_T(&b_allPts);
  loop_ub = allPts->size[0];
  i = r->size[0];
  r->size[0] = allPts->size[0];
  emxEnsureCapacity_int32_T(r, i);
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = static_cast<int>(allPts->data[i + allPts->size[0]]) +
      indices_tmp_idx_0 * (static_cast<int>(allPts->data[i]) - 1);
  }

  emxFree_real_T(&allPts);
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    mask->data[r->data[i] - 1] = 1U;
  }

  emxFree_int32_T(&r);
  numUnmapped_tmp = imageSize[0] * imageSize[1];
  loop_ub = mask->size[0] * mask->size[1];
  b_mask = *mask;
  c_X[0] = loop_ub;
  b_mask.size = &c_X[0];
  nx = b_mask.size[0];
  if (b_mask.size[0] == 0) {
    numUnmapped = 0.0;
  } else {
    numUnmapped = b_mask.data[0];
    for (k = 2; k <= nx; k++) {
      numUnmapped += static_cast<double>(b_mask.data[k - 1]);
    }
  }

  numUnmapped = numUnmapped_tmp - numUnmapped;
  if (numUnmapped > 0.0) {
    p1_idx_0 = 1.0;
    p1_idx_1 = 1.0;
    p2_idx_0 = imageSize[1];
    p2_idx_1 = imageSize[0];
    numTrials = 0;
    emxInit_real_T(&newPts, 2);
    emxInit_int32_T(&r1, 1);
    emxInit_int32_T(&r2, 1);
    emxInitMatrix_cell_wrap_26(reshapes);
    emxInitMatrix_cell_wrap_26(b_reshapes);
    emxInitMatrix_cell_wrap_26(c_reshapes);
    emxInitMatrix_cell_wrap_26(d_reshapes);
    while ((numTrials < 5) && (numUnmapped > 0.0)) {
      p1_idx_0--;
      p2_idx_0++;
      p1_idx_1--;
      p2_idx_1++;
      w = (p2_idx_0 - p1_idx_0) + 1.0;
      h = (p2_idx_1 - p1_idx_1) + 1.0;
      lastNumUnmapped = numUnmapped;
      b_tmp = (p1_idx_0 + w) - 1.0;
      if (rtIsNaN(b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (b_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_0) || rtIsInf(b_tmp)) && (p1_idx_0 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = static_cast<int>(std::floor(b_tmp - p1_idx_0));
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= loop_ub; i++) {
          y->data[i] = p1_idx_0 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_0, b_tmp, y);
      }

      i = reshapes[0].f1->size[0];
      reshapes[0].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(reshapes[0].f1, i);
      loop_ub = y->size[1];
      for (i = 0; i < loop_ub; i++) {
        reshapes[0].f1->data[i] = y->data[i];
      }

      loop_ub = static_cast<int>(w);
      i = reshapes[1].f1->size[0];
      reshapes[1].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(reshapes[1].f1, i);
      for (i = 0; i < loop_ub; i++) {
        reshapes[1].f1->data[i] = p1_idx_1;
      }

      if (b_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_0) || rtIsInf(b_tmp)) && (p1_idx_0 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        nx = static_cast<int>(std::floor(b_tmp - p1_idx_0));
        y->size[1] = nx + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= nx; i++) {
          y->data[i] = p1_idx_0 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_0, b_tmp, y);
      }

      i = b_reshapes[0].f1->size[0];
      b_reshapes[0].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(b_reshapes[0].f1, i);
      nx = y->size[1];
      for (i = 0; i < nx; i++) {
        b_reshapes[0].f1->data[i] = y->data[i];
      }

      i = b_reshapes[1].f1->size[0];
      b_reshapes[1].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(b_reshapes[1].f1, i);
      for (i = 0; i < loop_ub; i++) {
        b_reshapes[1].f1->data[i] = p2_idx_1;
      }

      b_tmp = (p1_idx_1 + h) - 1.0;
      if (b_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_1) || rtIsInf(b_tmp)) && (p1_idx_1 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = static_cast<int>(std::floor(b_tmp - p1_idx_1));
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= loop_ub; i++) {
          y->data[i] = p1_idx_1 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_1, b_tmp, y);
      }

      loop_ub = static_cast<int>(h);
      i = c_reshapes[0].f1->size[0];
      c_reshapes[0].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(c_reshapes[0].f1, i);
      for (i = 0; i < loop_ub; i++) {
        c_reshapes[0].f1->data[i] = p1_idx_0;
      }

      i = c_reshapes[1].f1->size[0];
      c_reshapes[1].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(c_reshapes[1].f1, i);
      nx = y->size[1];
      for (i = 0; i < nx; i++) {
        c_reshapes[1].f1->data[i] = y->data[i];
      }

      if (b_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(p1_idx_1) || rtIsInf(b_tmp)) && (p1_idx_1 == b_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, i);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        nx = static_cast<int>(std::floor(b_tmp - p1_idx_1));
        y->size[1] = nx + 1;
        emxEnsureCapacity_real_T(y, i);
        for (i = 0; i <= nx; i++) {
          y->data[i] = p1_idx_1 + static_cast<double>(i);
        }
      } else {
        eml_float_colon(p1_idx_1, b_tmp, y);
      }

      i = d_reshapes[0].f1->size[0];
      d_reshapes[0].f1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(d_reshapes[0].f1, i);
      for (i = 0; i < loop_ub; i++) {
        d_reshapes[0].f1->data[i] = p2_idx_0;
      }

      i = d_reshapes[1].f1->size[0];
      d_reshapes[1].f1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(d_reshapes[1].f1, i);
      loop_ub = y->size[1];
      for (i = 0; i < loop_ub; i++) {
        d_reshapes[1].f1->data[i] = y->data[i];
      }

      i = b_X->size[0] * b_X->size[1];
      b_X->size[0] = ((reshapes[0].f1->size[0] + b_reshapes[0].f1->size[0]) +
                      c_reshapes[0].f1->size[0]) + d_reshapes[0].f1->size[0];
      b_X->size[1] = 2;
      emxEnsureCapacity_real_T(b_X, i);
      loop_ub = reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i] = reshapes[0].f1->data[i];
      }

      loop_ub = reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i + b_X->size[0]] = reshapes[1].f1->data[i];
      }

      loop_ub = b_reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i + reshapes[0].f1->size[0]] = b_reshapes[0].f1->data[i];
      }

      loop_ub = b_reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[(i + reshapes[0].f1->size[0]) + b_X->size[0]] = b_reshapes[1].
          f1->data[i];
      }

      loop_ub = c_reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[(i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]] =
          c_reshapes[0].f1->data[i];
      }

      loop_ub = c_reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[((i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]) +
          b_X->size[0]] = c_reshapes[1].f1->data[i];
      }

      loop_ub = d_reshapes[0].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[((i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]) +
          c_reshapes[0].f1->size[0]] = d_reshapes[0].f1->data[i];
      }

      loop_ub = d_reshapes[1].f1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[(((i + reshapes[0].f1->size[0]) + b_reshapes[0].f1->size[0]) +
                   c_reshapes[0].f1->size[0]) + b_X->size[0]] = d_reshapes[1].
          f1->data[i];
      }

      for (i = 0; i < 3; i++) {
        c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
        c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
        c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
      }

      distortPoints(b_X, c_this, b_this->RadialDistortion,
                    b_this->TangentialDistortion, ptsOut);
      loop_ub = ptsOut->size[0];
      i = x->size[0];
      x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(x, i);
      i = b_x->size[0];
      b_x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(b_x, i);
      i = c_x->size[0];
      c_x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(c_x, i);
      i = d_x->size[0];
      d_x->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(d_x, i);
      for (k = 0; k < loop_ub; k++) {
        numUnmapped = ptsOut->data[k];
        x->data[k] = std::floor(numUnmapped);
        b_tmp = ptsOut->data[k + ptsOut->size[0]];
        b_x->data[k] = std::ceil(b_tmp);
        c_x->data[k] = std::ceil(numUnmapped);
        d_x->data[k] = std::floor(b_tmp);
      }

      i = e_x->size[0] * e_x->size[1];
      e_x->size[0] = ptsOut->size[0];
      e_x->size[1] = 2;
      emxEnsureCapacity_real_T(e_x, i);
      loop_ub = ptsOut->size[0] * ptsOut->size[1];
      for (i = 0; i < loop_ub; i++) {
        e_x->data[i] = ptsOut->data[i];
      }

      nx = ptsOut->size[0] << 1;
      for (k = 0; k < nx; k++) {
        e_x->data[k] = std::floor(e_x->data[k]);
        ptsOut->data[k] = std::ceil(ptsOut->data[k]);
      }

      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = ((e_x->size[0] + x->size[0]) + c_x->size[0]) +
        ptsOut->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(newPts, i);
      loop_ub = e_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[i] = e_x->data[i];
      }

      for (i = 0; i < loop_ub; i++) {
        newPts->data[i + newPts->size[0]] = e_x->data[i + e_x->size[0]];
      }

      loop_ub = x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[i + e_x->size[0]] = x->data[i];
      }

      loop_ub = b_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[(i + e_x->size[0]) + newPts->size[0]] = b_x->data[i];
      }

      loop_ub = c_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[(i + e_x->size[0]) + x->size[0]] = c_x->data[i];
      }

      loop_ub = d_x->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[((i + e_x->size[0]) + x->size[0]) + newPts->size[0]] =
          d_x->data[i];
      }

      loop_ub = ptsOut->size[0];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[((i + e_x->size[0]) + x->size[0]) + c_x->size[0]] =
          ptsOut->data[i];
      }

      for (i = 0; i < loop_ub; i++) {
        newPts->data[(((i + e_x->size[0]) + x->size[0]) + c_x->size[0]) +
          newPts->size[0]] = ptsOut->data[i + ptsOut->size[0]];
      }

      loop_ub = newPts->size[0];
      i = insideImage->size[0];
      insideImage->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(insideImage, i);
      for (i = 0; i < loop_ub; i++) {
        numUnmapped = newPts->data[i];
        b_tmp = newPts->data[i + newPts->size[0]];
        insideImage->data[i] = ((numUnmapped >= 1.0) && (b_tmp >= 1.0) &&
          (numUnmapped <= imageSize[1]) && (b_tmp <= imageSize[0]));
      }

      k = insideImage->size[0] - 1;
      nx = 0;
      for (loop_ub = 0; loop_ub <= k; loop_ub++) {
        if (insideImage->data[loop_ub]) {
          nx++;
        }
      }

      i = r2->size[0];
      r2->size[0] = nx;
      emxEnsureCapacity_int32_T(r2, i);
      nx = 0;
      for (loop_ub = 0; loop_ub <= k; loop_ub++) {
        if (insideImage->data[loop_ub]) {
          r2->data[nx] = loop_ub + 1;
          nx++;
        }
      }

      i = b_X->size[0] * b_X->size[1];
      b_X->size[0] = r2->size[0];
      b_X->size[1] = 2;
      emxEnsureCapacity_real_T(b_X, i);
      loop_ub = r2->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_X->data[i] = newPts->data[r2->data[i] - 1];
      }

      for (i = 0; i < loop_ub; i++) {
        b_X->data[i + b_X->size[0]] = newPts->data[(r2->data[i] + newPts->size[0])
          - 1];
      }

      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = b_X->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(newPts, i);
      loop_ub = b_X->size[0] * b_X->size[1];
      for (i = 0; i < loop_ub; i++) {
        newPts->data[i] = b_X->data[i];
      }

      loop_ub = newPts->size[0];
      i = r1->size[0];
      r1->size[0] = newPts->size[0];
      emxEnsureCapacity_int32_T(r1, i);
      for (i = 0; i < loop_ub; i++) {
        r1->data[i] = static_cast<int>(newPts->data[i + newPts->size[0]]) +
          indices_tmp_idx_0 * (static_cast<int>(newPts->data[i]) - 1);
      }

      loop_ub = r1->size[0] - 1;
      for (i = 0; i <= loop_ub; i++) {
        mask->data[r1->data[i] - 1] = 1U;
      }

      loop_ub = mask->size[0] * mask->size[1];
      b_mask = *mask;
      d_X[0] = loop_ub;
      b_mask.size = &d_X[0];
      nx = b_mask.size[0];
      if (b_mask.size[0] == 0) {
        numUnmapped = 0.0;
      } else {
        numUnmapped = b_mask.data[0];
        for (k = 2; k <= nx; k++) {
          numUnmapped += static_cast<double>(b_mask.data[k - 1]);
        }
      }

      numUnmapped = numUnmapped_tmp - numUnmapped;
      if (lastNumUnmapped == numUnmapped) {
        numTrials++;
      } else {
        numTrials = 0;
      }

      xBoundsBig[0] = p1_idx_0;
      xBoundsBig[1] = p2_idx_0;
      yBoundsBig[0] = p1_idx_1;
      yBoundsBig[1] = p2_idx_1;
    }

    emxFreeMatrix_cell_wrap_26(d_reshapes);
    emxFreeMatrix_cell_wrap_26(c_reshapes);
    emxFreeMatrix_cell_wrap_26(b_reshapes);
    emxFreeMatrix_cell_wrap_26(reshapes);
    emxFree_int32_T(&r2);
    emxFree_int32_T(&r1);
    emxFree_real_T(&newPts);
  }

  emxFree_real_T(&b_X);
  emxFree_real_T(&e_x);
  emxFree_real_T(&d_x);
  emxFree_real_T(&c_x);
  emxFree_real_T(&b_x);
  emxFree_real_T(&x);
  emxFree_real_T(&y);
  emxFree_boolean_T(&insideImage);
  emxFree_real_T(&ptsOut);
  c_ImageTransformer_ImageTransfo(&myMap);
  i = myMap.SizeOfImage->size[0] * myMap.SizeOfImage->size[1];
  myMap.SizeOfImage->size[0] = 1;
  myMap.SizeOfImage->size[1] = 2;
  emxEnsureCapacity_real_T(myMap.SizeOfImage, i);
  myMap.SizeOfImage->data[0] = indices_tmp_idx_0;
  myMap.SizeOfImage->data[1] = i1;
  i = myMap.ClassOfImage->size[0] * myMap.ClassOfImage->size[1];
  myMap.ClassOfImage->size[0] = 1;
  myMap.ClassOfImage->size[1] = 5;
  emxEnsureCapacity_char_T(myMap.ClassOfImage, i);
  for (i = 0; i < 5; i++) {
    myMap.ClassOfImage->data[i] = cv[i];
  }

  i = myMap.OutputView->size[0] * myMap.OutputView->size[1];
  myMap.OutputView->size[0] = 1;
  myMap.OutputView->size[1] = 4;
  emxEnsureCapacity_char_T(myMap.OutputView, i);
  myMap.OutputView->data[0] = 'f';
  myMap.OutputView->data[1] = 'u';
  myMap.OutputView->data[2] = 'l';
  myMap.OutputView->data[3] = 'l';
  myMap.XBounds[0] = xBoundsBig[0];
  myMap.XBounds[1] = xBoundsBig[1];
  myMap.YBounds[0] = yBoundsBig[0];
  myMap.YBounds[1] = yBoundsBig[1];
  for (i = 0; i < 3; i++) {
    c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
    c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  ImageTransformer_computeMap(&myMap, c_this, b_this->RadialDistortion,
    b_this->TangentialDistortion);
  i = mask->size[0] * mask->size[1];
  mask->size[0] = indices_tmp_idx_0;
  mask->size[1] = i1;
  emxEnsureCapacity_uint8_T(mask, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    mask->data[i] = 1U;
  }

  emxInit_real32_T(&b_myMap, 2);
  i = b_myMap->size[0] * b_myMap->size[1];
  b_myMap->size[0] = myMap.XmapSingle->size[0];
  b_myMap->size[1] = myMap.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(b_myMap, i);
  loop_ub = myMap.XmapSingle->size[0] * myMap.XmapSingle->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_myMap->data[i] = myMap.XmapSingle->data[i];
  }

  emxInit_real32_T(&c_myMap, 2);
  i = c_myMap->size[0] * c_myMap->size[1];
  c_myMap->size[0] = myMap.YmapSingle->size[0];
  c_myMap->size[1] = myMap.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(c_myMap, i);
  loop_ub = myMap.YmapSingle->size[0] * myMap.YmapSingle->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    c_myMap->data[i] = myMap.YmapSingle->data[i];
  }

  b_interp2d(mask, b_myMap, c_myMap, undistortedMask);
  emxFree_real32_T(&c_myMap);
  emxFree_real32_T(&b_myMap);
  emxFree_uint8_T(&mask);
  c_emxFreeStruct_vision_internal(&myMap);
}

//
// Arguments    : const emxArray_uint8_T *undistortedMask
//                double boundaryPixel[2]
// Return Type  : void
//
static void getInitialBoundaryPixel(const emxArray_uint8_T *undistortedMask,
  double boundaryPixel[2])
{
  int sRow;
  int sCol;
  int cx;
  int i;
  int i1;
  int b_i;
  boolean_T exitg1;
  int i2;
  sRow = -1;
  sCol = -1;
  cx = static_cast<int>(std::floor(static_cast<double>(undistortedMask->size[1])
    / 2.0));
  i = static_cast<int>(std::floor(static_cast<double>(undistortedMask->size[0]) /
    2.0));
  i1 = undistortedMask->size[0] - i;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= i1)) {
    i2 = (i + b_i) - 1;
    if (undistortedMask->data[i2 + undistortedMask->size[0] * (cx - 1)] == 0) {
      sRow = i2;
      sCol = cx;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (sRow == -1) {
    sRow = undistortedMask->size[0];
    sCol = cx;
  }

  boundaryPixel[0] = sRow;
  boundaryPixel[1] = sCol;
}

//
// Arguments    : const d_vision_internal_calibration_C *b_this
//                const double imageSize[2]
//                double xBounds[2]
//                double yBounds[2]
// Return Type  : void
//
void c_CameraParametersImpl_computeU(const d_vision_internal_calibration_C
  *b_this, const double imageSize[2], double xBounds[2], double yBounds[2])
{
  emxArray_uint8_T *undistortedMask;
  emxArray_real_T *boundaryPixelsUndistorted;
  emxArray_real_T *boundaryPixelsDistorted;
  double xBoundsBig[2];
  double yBoundsBig[2];
  double b_dv[2];
  int idx;
  int i;
  emxArray_real_T *b_boundaryPixelsUndistorted;
  double c_this[9];
  double ex;
  int k;
  boolean_T exitg1;
  double minX;
  double d;
  double maxX;
  double minY;
  double maxY;
  emxArray_real_T *y;
  emxArray_boolean_T *topIdx;
  emxArray_boolean_T *botIdx;
  emxArray_boolean_T *leftIdx;
  emxArray_boolean_T *rightIdx;
  int n;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxInit_uint8_T(&undistortedMask, 2);
  emxInit_real_T(&boundaryPixelsUndistorted, 2);
  emxInit_real_T(&boundaryPixelsDistorted, 2);
  c_CameraParametersImpl_createUn(b_this, imageSize, undistortedMask, xBoundsBig,
    yBoundsBig);
  getInitialBoundaryPixel(undistortedMask, b_dv);
  bwtraceboundary(undistortedMask, b_dv, boundaryPixelsUndistorted);
  idx = boundaryPixelsUndistorted->size[0] - 1;
  i = boundaryPixelsDistorted->size[0] * boundaryPixelsDistorted->size[1];
  boundaryPixelsDistorted->size[0] = boundaryPixelsUndistorted->size[0];
  boundaryPixelsDistorted->size[1] = 2;
  emxEnsureCapacity_real_T(boundaryPixelsDistorted, i);
  emxFree_uint8_T(&undistortedMask);
  for (i = 0; i <= idx; i++) {
    boundaryPixelsDistorted->data[i] = boundaryPixelsUndistorted->data[i +
      boundaryPixelsUndistorted->size[0]];
  }

  for (i = 0; i <= idx; i++) {
    boundaryPixelsDistorted->data[i + boundaryPixelsDistorted->size[0]] =
      boundaryPixelsUndistorted->data[i];
  }

  i = boundaryPixelsUndistorted->size[0] * boundaryPixelsUndistorted->size[1];
  boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  boundaryPixelsUndistorted->size[1] = 2;
  emxEnsureCapacity_real_T(boundaryPixelsUndistorted, i);
  idx = boundaryPixelsDistorted->size[0] * boundaryPixelsDistorted->size[1];
  for (i = 0; i < idx; i++) {
    boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i];
  }

  emxInit_real_T(&b_boundaryPixelsUndistorted, 1);
  idx = boundaryPixelsUndistorted->size[0] - 1;
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(b_boundaryPixelsUndistorted, i);
  for (i = 0; i <= idx; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsUndistorted->data[i] +
      xBoundsBig[0];
  }

  idx = b_boundaryPixelsUndistorted->size[0];
  for (i = 0; i < idx; i++) {
    boundaryPixelsUndistorted->data[i] = b_boundaryPixelsUndistorted->data[i];
  }

  idx = boundaryPixelsUndistorted->size[0] - 1;
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(b_boundaryPixelsUndistorted, i);
  for (i = 0; i <= idx; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsUndistorted->data[i +
      boundaryPixelsUndistorted->size[0]] + yBoundsBig[0];
  }

  idx = b_boundaryPixelsUndistorted->size[0];
  for (i = 0; i < idx; i++) {
    boundaryPixelsUndistorted->data[i + boundaryPixelsUndistorted->size[0]] =
      b_boundaryPixelsUndistorted->data[i];
  }

  for (i = 0; i < 3; i++) {
    c_this[3 * i] = b_this->IntrinsicMatrixInternal[i];
    c_this[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    c_this[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  distortPoints(boundaryPixelsUndistorted, c_this, b_this->RadialDistortion,
                b_this->TangentialDistortion, boundaryPixelsDistorted);
  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[0];
    } else if ((boundaryPixelsDistorted->data[0] > boundaryPixelsDistorted->
                data[1]) || (rtIsNaN(boundaryPixelsDistorted->data[0]) &&
                (!rtIsNaN(boundaryPixelsDistorted->data[1])))) {
      ex = boundaryPixelsDistorted->data[1];
    } else {
      ex = boundaryPixelsDistorted->data[0];
    }
  } else {
    if (!rtIsNaN(boundaryPixelsDistorted->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!rtIsNaN(boundaryPixelsDistorted->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[0];
    } else {
      ex = boundaryPixelsDistorted->data[idx - 1];
      idx++;
      for (k = idx; k <= i; k++) {
        d = boundaryPixelsDistorted->data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }

  if ((1.0 > ex) || rtIsNaN(ex)) {
    minX = 1.0;
  } else {
    minX = ex;
  }

  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[0];
    } else if ((boundaryPixelsDistorted->data[0] < boundaryPixelsDistorted->
                data[1]) || (rtIsNaN(boundaryPixelsDistorted->data[0]) &&
                (!rtIsNaN(boundaryPixelsDistorted->data[1])))) {
      ex = boundaryPixelsDistorted->data[1];
    } else {
      ex = boundaryPixelsDistorted->data[0];
    }
  } else {
    if (!rtIsNaN(boundaryPixelsDistorted->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!rtIsNaN(boundaryPixelsDistorted->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[0];
    } else {
      ex = boundaryPixelsDistorted->data[idx - 1];
      idx++;
      for (k = idx; k <= i; k++) {
        d = boundaryPixelsDistorted->data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }

  if ((imageSize[1] < ex) || rtIsNaN(ex)) {
    maxX = imageSize[1];
  } else {
    maxX = ex;
  }

  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else if ((boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]] >
                boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] +
                1]) || (rtIsNaN(boundaryPixelsDistorted->
                 data[boundaryPixelsDistorted->size[0]]) && (!rtIsNaN
                 (boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]
                  + 1])))) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] + 1];
    } else {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    }
  } else {
    if (!rtIsNaN(boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]]))
    {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!rtIsNaN(boundaryPixelsDistorted->data[(k +
              boundaryPixelsDistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else {
      ex = boundaryPixelsDistorted->data[(idx + boundaryPixelsDistorted->size[0])
        - 1];
      idx++;
      for (k = idx; k <= i; k++) {
        d = boundaryPixelsDistorted->data[(k + boundaryPixelsDistorted->size[0])
          - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }

  if ((1.0 > ex) || rtIsNaN(ex)) {
    minY = 1.0;
  } else {
    minY = ex;
  }

  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else if ((boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]] <
                boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] +
                1]) || (rtIsNaN(boundaryPixelsDistorted->
                 data[boundaryPixelsDistorted->size[0]]) && (!rtIsNaN
                 (boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]
                  + 1])))) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] + 1];
    } else {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    }
  } else {
    if (!rtIsNaN(boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]]))
    {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!rtIsNaN(boundaryPixelsDistorted->data[(k +
              boundaryPixelsDistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else {
      ex = boundaryPixelsDistorted->data[(idx + boundaryPixelsDistorted->size[0])
        - 1];
      idx++;
      for (k = idx; k <= i; k++) {
        d = boundaryPixelsDistorted->data[(k + boundaryPixelsDistorted->size[0])
          - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }

  if ((imageSize[0] < ex) || rtIsNaN(ex)) {
    maxY = imageSize[0];
  } else {
    maxY = ex;
  }

  idx = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(b_boundaryPixelsUndistorted, i);
  for (i = 0; i < idx; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i +
      boundaryPixelsDistorted->size[0]] - minY;
  }

  emxInit_real_T(&y, 1);
  idx = b_boundaryPixelsUndistorted->size[0];
  i = y->size[0];
  y->size[0] = b_boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(y, i);
  for (k = 0; k < idx; k++) {
    y->data[k] = std::abs(b_boundaryPixelsUndistorted->data[k]);
  }

  emxInit_boolean_T(&topIdx, 1);
  i = topIdx->size[0];
  topIdx->size[0] = y->size[0];
  emxEnsureCapacity_boolean_T(topIdx, i);
  idx = y->size[0];
  for (i = 0; i < idx; i++) {
    topIdx->data[i] = (y->data[i] < 7.0);
  }

  idx = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(b_boundaryPixelsUndistorted, i);
  for (i = 0; i < idx; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i +
      boundaryPixelsDistorted->size[0]] - maxY;
  }

  idx = b_boundaryPixelsUndistorted->size[0];
  i = y->size[0];
  y->size[0] = b_boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(y, i);
  for (k = 0; k < idx; k++) {
    y->data[k] = std::abs(b_boundaryPixelsUndistorted->data[k]);
  }

  emxInit_boolean_T(&botIdx, 1);
  i = botIdx->size[0];
  botIdx->size[0] = y->size[0];
  emxEnsureCapacity_boolean_T(botIdx, i);
  idx = y->size[0];
  for (i = 0; i < idx; i++) {
    botIdx->data[i] = (y->data[i] < 7.0);
  }

  idx = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(b_boundaryPixelsUndistorted, i);
  for (i = 0; i < idx; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i] -
      minX;
  }

  idx = b_boundaryPixelsUndistorted->size[0];
  i = y->size[0];
  y->size[0] = b_boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(y, i);
  for (k = 0; k < idx; k++) {
    y->data[k] = std::abs(b_boundaryPixelsUndistorted->data[k]);
  }

  emxInit_boolean_T(&leftIdx, 1);
  i = leftIdx->size[0];
  leftIdx->size[0] = y->size[0];
  emxEnsureCapacity_boolean_T(leftIdx, i);
  idx = y->size[0];
  for (i = 0; i < idx; i++) {
    leftIdx->data[i] = (y->data[i] < 7.0);
  }

  idx = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(b_boundaryPixelsUndistorted, i);
  for (i = 0; i < idx; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i] -
      maxX;
  }

  emxFree_real_T(&boundaryPixelsDistorted);
  idx = b_boundaryPixelsUndistorted->size[0];
  i = y->size[0];
  y->size[0] = b_boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(y, i);
  for (k = 0; k < idx; k++) {
    y->data[k] = std::abs(b_boundaryPixelsUndistorted->data[k]);
  }

  emxFree_real_T(&b_boundaryPixelsUndistorted);
  emxInit_boolean_T(&rightIdx, 1);
  i = rightIdx->size[0];
  rightIdx->size[0] = y->size[0];
  emxEnsureCapacity_boolean_T(rightIdx, i);
  idx = y->size[0];
  for (i = 0; i < idx; i++) {
    rightIdx->data[i] = (y->data[i] < 7.0);
  }

  emxFree_real_T(&y);
  k = topIdx->size[0] - 1;
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (topIdx->data[n]) {
      idx++;
    }
  }

  emxInit_int32_T(&r, 1);
  i = r->size[0];
  r->size[0] = idx;
  emxEnsureCapacity_int32_T(r, i);
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (topIdx->data[n]) {
      r->data[idx] = n + 1;
      idx++;
    }
  }

  emxFree_boolean_T(&topIdx);
  n = r->size[0];
  if (r->size[0] <= 2) {
    if (r->size[0] == 1) {
      ex = boundaryPixelsUndistorted->data[(r->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
    } else {
      d = boundaryPixelsUndistorted->data[(r->data[1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      ex = boundaryPixelsUndistorted->data[(r->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
      if ((ex < d) || (rtIsNaN(boundaryPixelsUndistorted->data[(r->data[0] +
             boundaryPixelsUndistorted->size[0]) - 1]) && (!rtIsNaN(d)))) {
        ex = d;
      }
    }
  } else {
    ex = boundaryPixelsUndistorted->data[(r->data[0] +
      boundaryPixelsUndistorted->size[0]) - 1];
    if (!rtIsNaN(ex)) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r->size[0])) {
        if (!rtIsNaN(boundaryPixelsUndistorted->data[(r->data[k - 1] +
              boundaryPixelsUndistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      ex = boundaryPixelsUndistorted->data[(r->data[idx - 1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      i = idx + 1;
      for (k = i; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[(r->data[k - 1] +
          boundaryPixelsUndistorted->size[0]) - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }

  emxFree_int32_T(&r);
  k = botIdx->size[0] - 1;
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (botIdx->data[n]) {
      idx++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = idx;
  emxEnsureCapacity_int32_T(r1, i);
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (botIdx->data[n]) {
      r1->data[idx] = n + 1;
      idx++;
    }
  }

  emxFree_boolean_T(&botIdx);
  n = r1->size[0];
  if (r1->size[0] <= 2) {
    if (r1->size[0] == 1) {
      maxY = boundaryPixelsUndistorted->data[(r1->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
    } else {
      d = boundaryPixelsUndistorted->data[(r1->data[1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      maxY = boundaryPixelsUndistorted->data[(r1->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
      if ((maxY > d) || (rtIsNaN(boundaryPixelsUndistorted->data[(r1->data[0] +
             boundaryPixelsUndistorted->size[0]) - 1]) && (!rtIsNaN(d)))) {
        maxY = d;
      }
    }
  } else {
    maxY = boundaryPixelsUndistorted->data[(r1->data[0] +
      boundaryPixelsUndistorted->size[0]) - 1];
    if (!rtIsNaN(maxY)) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r1->size[0])) {
        if (!rtIsNaN(boundaryPixelsUndistorted->data[(r1->data[k - 1] +
              boundaryPixelsUndistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      maxY = boundaryPixelsUndistorted->data[(r1->data[idx - 1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      i = idx + 1;
      for (k = i; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[(r1->data[k - 1] +
          boundaryPixelsUndistorted->size[0]) - 1];
        if (maxY > d) {
          maxY = d;
        }
      }
    }
  }

  emxFree_int32_T(&r1);
  k = leftIdx->size[0] - 1;
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (leftIdx->data[n]) {
      idx++;
    }
  }

  emxInit_int32_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = idx;
  emxEnsureCapacity_int32_T(r2, i);
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (leftIdx->data[n]) {
      r2->data[idx] = n + 1;
      idx++;
    }
  }

  emxFree_boolean_T(&leftIdx);
  n = r2->size[0];
  if (r2->size[0] <= 2) {
    if (r2->size[0] == 1) {
      minX = boundaryPixelsUndistorted->data[r2->data[0] - 1];
    } else {
      d = boundaryPixelsUndistorted->data[r2->data[1] - 1];
      minX = boundaryPixelsUndistorted->data[r2->data[0] - 1];
      if ((minX < d) || (rtIsNaN(boundaryPixelsUndistorted->data[r2->data[0] - 1])
                         && (!rtIsNaN(d)))) {
        minX = d;
      }
    }
  } else {
    minX = boundaryPixelsUndistorted->data[r2->data[0] - 1];
    if (!rtIsNaN(minX)) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r2->size[0])) {
        if (!rtIsNaN(boundaryPixelsUndistorted->data[r2->data[k - 1] - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      minX = boundaryPixelsUndistorted->data[r2->data[idx - 1] - 1];
      i = idx + 1;
      for (k = i; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[r2->data[k - 1] - 1];
        if (minX < d) {
          minX = d;
        }
      }
    }
  }

  emxFree_int32_T(&r2);
  k = rightIdx->size[0] - 1;
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (rightIdx->data[n]) {
      idx++;
    }
  }

  emxInit_int32_T(&r3, 1);
  i = r3->size[0];
  r3->size[0] = idx;
  emxEnsureCapacity_int32_T(r3, i);
  idx = 0;
  for (n = 0; n <= k; n++) {
    if (rightIdx->data[n]) {
      r3->data[idx] = n + 1;
      idx++;
    }
  }

  emxFree_boolean_T(&rightIdx);
  n = r3->size[0];
  if (r3->size[0] <= 2) {
    if (r3->size[0] == 1) {
      maxX = boundaryPixelsUndistorted->data[r3->data[0] - 1];
    } else {
      d = boundaryPixelsUndistorted->data[r3->data[1] - 1];
      maxX = boundaryPixelsUndistorted->data[r3->data[0] - 1];
      if ((maxX > d) || (rtIsNaN(boundaryPixelsUndistorted->data[r3->data[0] - 1])
                         && (!rtIsNaN(d)))) {
        maxX = d;
      }
    }
  } else {
    maxX = boundaryPixelsUndistorted->data[r3->data[0] - 1];
    if (!rtIsNaN(maxX)) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r3->size[0])) {
        if (!rtIsNaN(boundaryPixelsUndistorted->data[r3->data[k - 1] - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      maxX = boundaryPixelsUndistorted->data[r3->data[idx - 1] - 1];
      i = idx + 1;
      for (k = i; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[r3->data[k - 1] - 1];
        if (maxX > d) {
          maxX = d;
        }
      }
    }
  }

  emxFree_int32_T(&r3);
  emxFree_real_T(&boundaryPixelsUndistorted);
  minX = std::ceil(minX);
  maxX = std::floor(maxX);
  xBounds[0] = minX;
  xBounds[1] = maxX;
  sort(xBounds);
  ex = std::ceil(ex);
  maxY = std::floor(maxY);
  yBounds[0] = ex;
  yBounds[1] = maxY;
  sort(yBounds);
}

//
// Arguments    : const d_vision_internal_calibration_C *b_this
//                const double imageSize[2]
//                double xBounds[2]
//                double yBounds[2]
// Return Type  : void
//
void d_CameraParametersImpl_computeU(const d_vision_internal_calibration_C
  *b_this, const double imageSize[2], double xBounds[2], double yBounds[2])
{
  emxArray_uint8_T *undistortedMask;
  emxArray_boolean_T *b_undistortedMask;
  double xBoundsBig[2];
  double yBoundsBig[2];
  int i;
  int loop_ub;
  emxArray_struct_T *props;
  emxArray_real_T *dists;
  int center_idx_0;
  int center_idx_1;
  double a;
  double b_a;
  int iidx;
  boolean_T exitg1;
  emxInit_uint8_T(&undistortedMask, 2);
  emxInit_boolean_T(&b_undistortedMask, 2);
  d_CameraParametersImpl_createUn(b_this, imageSize, undistortedMask, xBoundsBig,
    yBoundsBig);
  i = b_undistortedMask->size[0] * b_undistortedMask->size[1];
  b_undistortedMask->size[0] = undistortedMask->size[0];
  b_undistortedMask->size[1] = undistortedMask->size[1];
  emxEnsureCapacity_boolean_T(b_undistortedMask, i);
  loop_ub = undistortedMask->size[0] * undistortedMask->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_undistortedMask->data[i] = (undistortedMask->data[i] != 0);
  }

  emxInit_struct_T(&props, 1);
  emxInit_real_T(&dists, 2);
  regionprops(b_undistortedMask, props);
  center_idx_0 = static_cast<int>(rt_roundd_snf(static_cast<double>
    (undistortedMask->size[0]) / 2.0));
  center_idx_1 = static_cast<int>(rt_roundd_snf(static_cast<double>
    (undistortedMask->size[1]) / 2.0));
  i = dists->size[0] * dists->size[1];
  dists->size[0] = 1;
  dists->size[1] = props->size[0];
  emxEnsureCapacity_real_T(dists, i);
  loop_ub = props->size[0];
  emxFree_boolean_T(&b_undistortedMask);
  emxFree_uint8_T(&undistortedMask);
  for (i = 0; i < loop_ub; i++) {
    dists->data[i] = 0.0;
  }

  i = props->size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    a = props->data[loop_ub].Centroid[0] - static_cast<double>(center_idx_1);
    b_a = props->data[loop_ub].Centroid[1] - static_cast<double>(center_idx_0);
    dists->data[loop_ub] = a * a + b_a * b_a;
  }

  center_idx_0 = dists->size[1];
  if (dists->size[1] <= 2) {
    if (dists->size[1] == 1) {
      iidx = 0;
    } else if ((dists->data[0] > dists->data[1]) || (rtIsNaN(dists->data[0]) &&
                (!rtIsNaN(dists->data[1])))) {
      iidx = 1;
    } else {
      iidx = 0;
    }
  } else {
    if (!rtIsNaN(dists->data[0])) {
      loop_ub = 1;
    } else {
      loop_ub = 0;
      center_idx_1 = 2;
      exitg1 = false;
      while ((!exitg1) && (center_idx_1 <= dists->size[1])) {
        if (!rtIsNaN(dists->data[center_idx_1 - 1])) {
          loop_ub = center_idx_1;
          exitg1 = true;
        } else {
          center_idx_1++;
        }
      }
    }

    if (loop_ub == 0) {
      iidx = 0;
    } else {
      a = dists->data[loop_ub - 1];
      iidx = loop_ub - 1;
      i = loop_ub + 1;
      for (center_idx_1 = i; center_idx_1 <= center_idx_0; center_idx_1++) {
        b_a = dists->data[center_idx_1 - 1];
        if (a > b_a) {
          a = b_a;
          iidx = center_idx_1 - 1;
        }
      }
    }
  }

  emxFree_real_T(&dists);
  xBounds[0] = std::ceil((xBoundsBig[0] + props->data[iidx].BoundingBox[0]) -
    1.0);
  xBounds[1] = std::floor(xBounds[0] + props->data[iidx].BoundingBox[2]);
  yBounds[0] = std::ceil((yBoundsBig[0] + props->data[iidx].BoundingBox[1]) -
    1.0);
  yBounds[1] = std::floor(yBounds[0] + props->data[iidx].BoundingBox[3]);
  emxFree_struct_T(&props);
}

//
// File trailer for CameraParametersImpl.cpp
//
// [EOF]
//
