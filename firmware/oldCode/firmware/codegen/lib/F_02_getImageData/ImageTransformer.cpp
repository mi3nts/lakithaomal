//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "ImageTransformer.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "colon.h"
#include "distortPoints.h"
#include "inv.h"
#include "meshgrid.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : c_vision_internal_calibration_I *b_this
//                const double intrinsicMatrix[9]
//                const double radialDist[2]
//                const double tangentialDist[2]
// Return Type  : void
//
void ImageTransformer_computeMap(c_vision_internal_calibration_I *b_this, const
  double intrinsicMatrix[9], const double radialDist[2], const double
  tangentialDist[2])
{
  emxArray_real_T *y;
  double m;
  double n;
  int i;
  int loop_ub;
  emxArray_real_T *b_y;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  emxArray_real_T *b_X;
  int Y_idx_0;
  emxArray_real_T *ptsOut;
  emxArray_char_T *a;
  boolean_T b_bool;
  emxArray_real_T *b_ptsOut;
  int exitg1;
  static const char cv[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  int num_idx_1_tmp;
  int loop_ub_tmp;
  emxInit_real_T(&y, 2);
  m = b_this->XBounds[0];
  n = b_this->XBounds[1];
  if (rtIsNaN(m) || rtIsNaN(n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (n < m) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if ((rtIsInf(m) || rtIsInf(n)) && (m == n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (std::floor(m) == m) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(n - m));
    y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(y, i);
    for (i = 0; i <= loop_ub; i++) {
      y->data[i] = m + static_cast<double>(i);
    }
  } else {
    eml_float_colon(m, n, y);
  }

  emxInit_real_T(&b_y, 2);
  m = b_this->YBounds[0];
  n = b_this->YBounds[1];
  if (rtIsNaN(m) || rtIsNaN(n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (n < m) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if ((rtIsInf(m) || rtIsInf(n)) && (m == n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (std::floor(m) == m) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    loop_ub = static_cast<int>(std::floor(n - m));
    b_y->size[1] = loop_ub + 1;
    emxEnsureCapacity_real_T(b_y, i);
    for (i = 0; i <= loop_ub; i++) {
      b_y->data[i] = m + static_cast<double>(i);
    }
  } else {
    eml_float_colon(m, n, b_y);
  }

  emxInit_real_T(&X, 2);
  emxInit_real_T(&Y, 2);
  emxInit_real_T(&b_X, 2);
  meshgrid(y, b_y, X, Y);
  loop_ub = X->size[0] * X->size[1];
  Y_idx_0 = Y->size[0] * Y->size[1];
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = loop_ub;
  b_X->size[1] = 2;
  emxEnsureCapacity_real_T(b_X, i);
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  for (i = 0; i < loop_ub; i++) {
    b_X->data[i] = X->data[i];
  }

  emxFree_real_T(&X);
  for (i = 0; i < Y_idx_0; i++) {
    b_X->data[i + b_X->size[0]] = Y->data[i];
  }

  emxFree_real_T(&Y);
  emxInit_real_T(&ptsOut, 2);
  emxInit_char_T(&a, 2);
  distortPoints(b_X, intrinsicMatrix, radialDist, tangentialDist, ptsOut);
  m = (b_this->YBounds[1] - b_this->YBounds[0]) + 1.0;
  n = (b_this->XBounds[1] - b_this->XBounds[0]) + 1.0;
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = b_this->ClassOfImage->size[1];
  emxEnsureCapacity_char_T(a, i);
  loop_ub = b_this->ClassOfImage->size[0] * b_this->ClassOfImage->size[1];
  emxFree_real_T(&b_X);
  for (i = 0; i < loop_ub; i++) {
    a->data[i] = b_this->ClassOfImage->data[i];
  }

  b_bool = false;
  if (a->size[1] == 6) {
    loop_ub = 0;
    do {
      exitg1 = 0;
      if (loop_ub < 6) {
        if (a->data[loop_ub] != cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emxFree_char_T(&a);
  emxInit_real_T(&b_ptsOut, 1);
  if (b_bool) {
    Y_idx_0 = static_cast<int>(m);
    num_idx_1_tmp = static_cast<int>(n);
    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i];
    }

    i = b_this->Xmap->size[0] * b_this->Xmap->size[1];
    b_this->Xmap->size[0] = Y_idx_0;
    b_this->Xmap->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real_T(b_this->Xmap, i);
    loop_ub_tmp = Y_idx_0 * num_idx_1_tmp;
    for (i = 0; i < loop_ub_tmp; i++) {
      b_this->Xmap->data[i] = b_ptsOut->data[i];
    }

    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = b_this->Ymap->size[0] * b_this->Ymap->size[1];
    b_this->Ymap->size[0] = Y_idx_0;
    b_this->Ymap->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real_T(b_this->Ymap, i);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_this->Ymap->data[i] = b_ptsOut->data[i];
    }
  } else {
    Y_idx_0 = static_cast<int>(m);
    num_idx_1_tmp = static_cast<int>(n);
    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i];
    }

    i = b_this->XmapSingle->size[0] * b_this->XmapSingle->size[1];
    b_this->XmapSingle->size[0] = Y_idx_0;
    b_this->XmapSingle->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real32_T(b_this->XmapSingle, i);
    loop_ub_tmp = Y_idx_0 * num_idx_1_tmp;
    for (i = 0; i < loop_ub_tmp; i++) {
      b_this->XmapSingle->data[i] = static_cast<float>(b_ptsOut->data[i]);
    }

    loop_ub = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < loop_ub; i++) {
      b_ptsOut->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = b_this->YmapSingle->size[0] * b_this->YmapSingle->size[1];
    b_this->YmapSingle->size[0] = Y_idx_0;
    b_this->YmapSingle->size[1] = num_idx_1_tmp;
    emxEnsureCapacity_real32_T(b_this->YmapSingle, i);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_this->YmapSingle->data[i] = static_cast<float>(b_ptsOut->data[i]);
    }
  }

  emxFree_real_T(&b_ptsOut);
  emxFree_real_T(&ptsOut);
}

//
// Arguments    : const c_vision_internal_calibration_I *b_this
//                const emxArray_uint8_T *b_I
// Return Type  : boolean_T
//
boolean_T ImageTransformer_needToUpdate(const c_vision_internal_calibration_I
  *b_this, const emxArray_uint8_T *b_I)
{
  emxArray_real_T *varargin_1;
  int k;
  int loop_ub;
  short varargin_2[3];
  boolean_T p;
  boolean_T exitg1;
  boolean_T sameSize;
  emxArray_char_T *b;
  boolean_T sameClass;
  int exitg2;
  static const char cv[5] = { 'u', 'i', 'n', 't', '8' };

  boolean_T sameOutputView;
  static const char cv1[5] = { 'v', 'a', 'l', 'i', 'd' };

  emxInit_real_T(&varargin_1, 2);
  k = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = b_this->SizeOfImage->size[1];
  emxEnsureCapacity_real_T(varargin_1, k);
  loop_ub = b_this->SizeOfImage->size[0] * b_this->SizeOfImage->size[1];
  for (k = 0; k < loop_ub; k++) {
    varargin_1->data[k] = b_this->SizeOfImage->data[k];
  }

  varargin_2[0] = static_cast<short>(b_I->size[0]);
  varargin_2[1] = static_cast<short>(b_I->size[1]);
  varargin_2[2] = static_cast<short>(b_I->size[2]);
  p = (varargin_1->size[1] == 3);
  if (p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == varargin_2[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  emxFree_real_T(&varargin_1);
  sameSize = p;
  emxInit_char_T(&b, 2);
  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = b_this->ClassOfImage->size[1];
  emxEnsureCapacity_char_T(b, k);
  loop_ub = b_this->ClassOfImage->size[0] * b_this->ClassOfImage->size[1];
  for (k = 0; k < loop_ub; k++) {
    b->data[k] = b_this->ClassOfImage->data[k];
  }

  sameClass = false;
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
        sameClass = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  k = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = b_this->OutputView->size[1];
  emxEnsureCapacity_char_T(b, k);
  loop_ub = b_this->OutputView->size[0] * b_this->OutputView->size[1];
  for (k = 0; k < loop_ub; k++) {
    b->data[k] = b_this->OutputView->data[k];
  }

  p = (b->size[1] == 5);
  if (p && (b->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(b->data[k] == cv1[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  emxFree_char_T(&b);
  sameOutputView = p;
  if (sameSize && sameClass && sameOutputView) {
    sameSize = true;
  } else {
    sameSize = false;
  }

  return !sameSize;
}

//
// Arguments    : c_vision_internal_calibration_I *b_this
//                const double intrinsicMatrix[9]
//                const double radialDist[2]
//                const double tangentialDist[2]
//                const double H_T[9]
// Return Type  : void
//
void b_ImageTransformer_computeMap(c_vision_internal_calibration_I *b_this,
  const double intrinsicMatrix[9], const double radialDist[2], const double
  tangentialDist[2], const double H_T[9])
{
  emxArray_real_T *y;
  double temp;
  double n;
  int i;
  int coffset;
  emxArray_real_T *b_y;
  emxArray_real_T *ptsIn;
  emxArray_real_T *X;
  emxArray_real_T *Y;
  int m;
  int input_sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  signed char sizes_idx_1;
  emxArray_real_T *b_X;
  int j;
  double Tinv[9];
  emxArray_real_T *U;
  int boffset;
  int b_i;
  int k;
  int aoffset;
  emxArray_real_T *ptsOut;
  emxArray_char_T *a;
  emxArray_real_T *b_ptsOut;
  int exitg1;
  static const char cv[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  emxInit_real_T(&y, 2);
  temp = b_this->XBounds[0];
  n = b_this->XBounds[1];
  if (rtIsNaN(temp) || rtIsNaN(n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (n < temp) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else if ((rtIsInf(temp) || rtIsInf(n)) && (temp == n)) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, i);
    y->data[0] = rtNaN;
  } else if (std::floor(temp) == temp) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    coffset = static_cast<int>(std::floor(n - temp));
    y->size[1] = coffset + 1;
    emxEnsureCapacity_real_T(y, i);
    for (i = 0; i <= coffset; i++) {
      y->data[i] = temp + static_cast<double>(i);
    }
  } else {
    eml_float_colon(temp, n, y);
  }

  emxInit_real_T(&b_y, 2);
  temp = b_this->YBounds[0];
  n = b_this->YBounds[1];
  if (rtIsNaN(temp) || rtIsNaN(n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (n < temp) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else if ((rtIsInf(temp) || rtIsInf(n)) && (temp == n)) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = 1;
    emxEnsureCapacity_real_T(b_y, i);
    b_y->data[0] = rtNaN;
  } else if (std::floor(temp) == temp) {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    coffset = static_cast<int>(std::floor(n - temp));
    b_y->size[1] = coffset + 1;
    emxEnsureCapacity_real_T(b_y, i);
    for (i = 0; i <= coffset; i++) {
      b_y->data[i] = temp + static_cast<double>(i);
    }
  } else {
    eml_float_colon(temp, n, b_y);
  }

  emxInit_real_T(&ptsIn, 2);
  emxInit_real_T(&X, 2);
  emxInit_real_T(&Y, 2);
  meshgrid(y, b_y, X, Y);
  m = X->size[0] * X->size[1];
  input_sizes_idx_1 = Y->size[0] * Y->size[1];
  i = ptsIn->size[0] * ptsIn->size[1];
  ptsIn->size[0] = m;
  ptsIn->size[1] = 2;
  emxEnsureCapacity_real_T(ptsIn, i);
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  for (i = 0; i < m; i++) {
    ptsIn->data[i] = X->data[i];
  }

  emxFree_real_T(&X);
  for (i = 0; i < input_sizes_idx_1; i++) {
    ptsIn->data[i + ptsIn->size[0]] = Y->data[i];
  }

  emxFree_real_T(&Y);
  if (ptsIn->size[0] != 0) {
    m = ptsIn->size[0];
  } else {
    m = 0;
  }

  empty_non_axis_sizes = (m == 0);
  if (empty_non_axis_sizes || (ptsIn->size[0] != 0)) {
    input_sizes_idx_1 = 2;
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes || (ptsIn->size[0] != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }

  emxInit_real_T(&b_X, 2);
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = m;
  b_X->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_real_T(b_X, i);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (j = 0; j < m; j++) {
      b_X->data[j + b_X->size[0] * i] = ptsIn->data[j + ptsIn->size[0] * i];
    }
  }

  coffset = sizes_idx_1;
  for (i = 0; i < coffset; i++) {
    for (j = 0; j < m; j++) {
      b_X->data[j + b_X->size[0] * input_sizes_idx_1] = 1.0;
    }
  }

  inv(H_T, Tinv);
  emxInit_real_T(&U, 2);
  if (b_X->size[1] == 1) {
    i = U->size[0] * U->size[1];
    U->size[0] = b_X->size[0];
    U->size[1] = 3;
    emxEnsureCapacity_real_T(U, i);
    coffset = b_X->size[0];
    for (i = 0; i < coffset; i++) {
      m = b_X->size[1];
      for (j = 0; j < 3; j++) {
        U->data[i + U->size[0] * j] = 0.0;
        for (input_sizes_idx_1 = 0; input_sizes_idx_1 < m; input_sizes_idx_1++)
        {
          U->data[i + U->size[0] * j] += b_X->data[i + b_X->size[0] *
            input_sizes_idx_1] * Tinv[input_sizes_idx_1 + 3 * j];
        }
      }
    }
  } else {
    m = b_X->size[0];
    input_sizes_idx_1 = b_X->size[1];
    i = U->size[0] * U->size[1];
    U->size[0] = b_X->size[0];
    U->size[1] = 3;
    emxEnsureCapacity_real_T(U, i);
    for (j = 0; j < 3; j++) {
      coffset = j * m;
      boffset = j * input_sizes_idx_1;
      for (b_i = 0; b_i < m; b_i++) {
        U->data[coffset + b_i] = 0.0;
      }

      for (k = 0; k < input_sizes_idx_1; k++) {
        aoffset = k * m;
        temp = Tinv[boffset + k];
        for (b_i = 0; b_i < m; b_i++) {
          i = coffset + b_i;
          U->data[i] += temp * b_X->data[aoffset + b_i];
        }
      }
    }
  }

  emxFree_real_T(&b_X);
  if (U->size[0] == 0) {
    ptsIn->size[0] = 0;
    ptsIn->size[1] = 2;
  } else {
    i = ptsIn->size[0] * ptsIn->size[1];
    ptsIn->size[0] = U->size[0];
    ptsIn->size[1] = 2;
    emxEnsureCapacity_real_T(ptsIn, i);
    i = U->size[0];
    for (k = 0; k < i; k++) {
      ptsIn->data[k] = U->data[k + U->size[0] * 2];
      ptsIn->data[i + k] = U->data[k + U->size[0] * 2];
    }

    coffset = U->size[0] - 1;
    i = ptsIn->size[0] * ptsIn->size[1];
    ptsIn->size[0] = U->size[0];
    ptsIn->size[1] = 2;
    emxEnsureCapacity_real_T(ptsIn, i);
    for (i = 0; i <= coffset; i++) {
      ptsIn->data[i] = U->data[i] / ptsIn->data[i];
    }

    for (i = 0; i <= coffset; i++) {
      ptsIn->data[i + ptsIn->size[0]] = U->data[i + U->size[0]] / ptsIn->data[i
        + ptsIn->size[0]];
    }

    coffset = ptsIn->size[0];
    for (i = 0; i < coffset; i++) {
      U->data[i] = ptsIn->data[i];
    }

    for (i = 0; i < coffset; i++) {
      U->data[i + U->size[0]] = ptsIn->data[i + ptsIn->size[0]];
    }

    coffset = U->size[0];
    i = ptsIn->size[0] * ptsIn->size[1];
    ptsIn->size[0] = U->size[0];
    ptsIn->size[1] = 2;
    emxEnsureCapacity_real_T(ptsIn, i);
    for (i = 0; i < coffset; i++) {
      ptsIn->data[i] = U->data[i];
    }

    for (i = 0; i < coffset; i++) {
      ptsIn->data[i + ptsIn->size[0]] = U->data[i + U->size[0]];
    }
  }

  emxFree_real_T(&U);
  emxInit_real_T(&ptsOut, 2);
  emxInit_char_T(&a, 2);
  distortPoints(ptsIn, intrinsicMatrix, radialDist, tangentialDist, ptsOut);
  temp = (b_this->YBounds[1] - b_this->YBounds[0]) + 1.0;
  n = (b_this->XBounds[1] - b_this->XBounds[0]) + 1.0;
  i = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = b_this->ClassOfImage->size[1];
  emxEnsureCapacity_char_T(a, i);
  coffset = b_this->ClassOfImage->size[0] * b_this->ClassOfImage->size[1];
  emxFree_real_T(&ptsIn);
  for (i = 0; i < coffset; i++) {
    a->data[i] = b_this->ClassOfImage->data[i];
  }

  empty_non_axis_sizes = false;
  if (a->size[1] == 6) {
    m = 0;
    do {
      exitg1 = 0;
      if (m < 6) {
        if (a->data[m] != cv[m]) {
          exitg1 = 1;
        } else {
          m++;
        }
      } else {
        empty_non_axis_sizes = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  emxFree_char_T(&a);
  emxInit_real_T(&b_ptsOut, 1);
  if (empty_non_axis_sizes) {
    m = static_cast<int>(temp);
    input_sizes_idx_1 = static_cast<int>(n);
    coffset = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < coffset; i++) {
      b_ptsOut->data[i] = ptsOut->data[i];
    }

    i = b_this->Xmap->size[0] * b_this->Xmap->size[1];
    b_this->Xmap->size[0] = m;
    b_this->Xmap->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(b_this->Xmap, i);
    j = m * input_sizes_idx_1;
    for (i = 0; i < j; i++) {
      b_this->Xmap->data[i] = b_ptsOut->data[i];
    }

    coffset = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < coffset; i++) {
      b_ptsOut->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = b_this->Ymap->size[0] * b_this->Ymap->size[1];
    b_this->Ymap->size[0] = m;
    b_this->Ymap->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real_T(b_this->Ymap, i);
    for (i = 0; i < j; i++) {
      b_this->Ymap->data[i] = b_ptsOut->data[i];
    }
  } else {
    m = static_cast<int>(temp);
    input_sizes_idx_1 = static_cast<int>(n);
    coffset = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < coffset; i++) {
      b_ptsOut->data[i] = ptsOut->data[i];
    }

    i = b_this->XmapSingle->size[0] * b_this->XmapSingle->size[1];
    b_this->XmapSingle->size[0] = m;
    b_this->XmapSingle->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real32_T(b_this->XmapSingle, i);
    j = m * input_sizes_idx_1;
    for (i = 0; i < j; i++) {
      b_this->XmapSingle->data[i] = static_cast<float>(b_ptsOut->data[i]);
    }

    coffset = ptsOut->size[0];
    i = b_ptsOut->size[0];
    b_ptsOut->size[0] = ptsOut->size[0];
    emxEnsureCapacity_real_T(b_ptsOut, i);
    for (i = 0; i < coffset; i++) {
      b_ptsOut->data[i] = ptsOut->data[i + ptsOut->size[0]];
    }

    i = b_this->YmapSingle->size[0] * b_this->YmapSingle->size[1];
    b_this->YmapSingle->size[0] = m;
    b_this->YmapSingle->size[1] = input_sizes_idx_1;
    emxEnsureCapacity_real32_T(b_this->YmapSingle, i);
    for (i = 0; i < j; i++) {
      b_this->YmapSingle->data[i] = static_cast<float>(b_ptsOut->data[i]);
    }
  }

  emxFree_real_T(&b_ptsOut);
  emxFree_real_T(&ptsOut);
}

//
// Arguments    : c_vision_internal_calibration_I *b_this
// Return Type  : c_vision_internal_calibration_I *
//
c_vision_internal_calibration_I *c_ImageTransformer_ImageTransfo
  (c_vision_internal_calibration_I *b_this)
{
  c_vision_internal_calibration_I *c_this;
  int i;
  static const char cv[5] = { 'u', 'i', 'n', 't', '8' };

  c_this = b_this;
  c_this->XBounds[0] = -1.0;
  c_this->XBounds[1] = -1.0;
  c_this->YBounds[0] = -1.0;
  c_this->YBounds[1] = -1.0;
  i = c_this->SizeOfImage->size[0] * c_this->SizeOfImage->size[1];
  c_this->SizeOfImage->size[0] = 1;
  c_this->SizeOfImage->size[1] = 2;
  emxEnsureCapacity_real_T(c_this->SizeOfImage, i);
  c_this->SizeOfImage->data[0] = 0.0;
  c_this->SizeOfImage->data[1] = 0.0;
  i = c_this->SizeOfImage->size[0] * c_this->SizeOfImage->size[1];
  c_this->SizeOfImage->size[0] = 1;
  c_this->SizeOfImage->size[1] = 3;
  emxEnsureCapacity_real_T(c_this->SizeOfImage, i);
  c_this->SizeOfImage->data[0] = 0.0;
  c_this->SizeOfImage->data[1] = 0.0;
  c_this->SizeOfImage->data[2] = 0.0;
  i = c_this->ClassOfImage->size[0] * c_this->ClassOfImage->size[1];
  c_this->ClassOfImage->size[0] = 1;
  c_this->ClassOfImage->size[1] = 1;
  emxEnsureCapacity_char_T(c_this->ClassOfImage, i);
  c_this->ClassOfImage->data[0] = 'a';
  i = c_this->ClassOfImage->size[0] * c_this->ClassOfImage->size[1];
  c_this->ClassOfImage->size[0] = 1;
  c_this->ClassOfImage->size[1] = 5;
  emxEnsureCapacity_char_T(c_this->ClassOfImage, i);
  for (i = 0; i < 5; i++) {
    c_this->ClassOfImage->data[i] = cv[i];
  }

  i = c_this->OutputView->size[0] * c_this->OutputView->size[1];
  c_this->OutputView->size[0] = 1;
  c_this->OutputView->size[1] = 1;
  emxEnsureCapacity_char_T(c_this->OutputView, i);
  c_this->OutputView->data[0] = 'a';
  i = c_this->OutputView->size[0] * c_this->OutputView->size[1];
  c_this->OutputView->size[0] = 1;
  c_this->OutputView->size[1] = 4;
  emxEnsureCapacity_char_T(c_this->OutputView, i);
  c_this->OutputView->data[0] = 's';
  c_this->OutputView->data[1] = 'a';
  c_this->OutputView->data[2] = 'm';
  c_this->OutputView->data[3] = 'e';
  i = c_this->Xmap->size[0] * c_this->Xmap->size[1];
  c_this->Xmap->size[0] = 2;
  c_this->Xmap->size[1] = 2;
  emxEnsureCapacity_real_T(c_this->Xmap, i);
  c_this->Xmap->data[0] = 0.0;
  c_this->Xmap->data[1] = 0.0;
  c_this->Xmap->data[2] = 0.0;
  c_this->Xmap->data[3] = 0.0;
  i = c_this->Ymap->size[0] * c_this->Ymap->size[1];
  c_this->Ymap->size[0] = 2;
  c_this->Ymap->size[1] = 2;
  emxEnsureCapacity_real_T(c_this->Ymap, i);
  c_this->Ymap->data[0] = 0.0;
  c_this->Ymap->data[1] = 0.0;
  c_this->Ymap->data[2] = 0.0;
  c_this->Ymap->data[3] = 0.0;
  i = c_this->XmapSingle->size[0] * c_this->XmapSingle->size[1];
  c_this->XmapSingle->size[0] = 2;
  c_this->XmapSingle->size[1] = 2;
  emxEnsureCapacity_real32_T(c_this->XmapSingle, i);
  c_this->XmapSingle->data[0] = 0.0F;
  c_this->XmapSingle->data[1] = 0.0F;
  c_this->XmapSingle->data[2] = 0.0F;
  c_this->XmapSingle->data[3] = 0.0F;
  i = c_this->YmapSingle->size[0] * c_this->YmapSingle->size[1];
  c_this->YmapSingle->size[0] = 2;
  c_this->YmapSingle->size[1] = 2;
  emxEnsureCapacity_real32_T(c_this->YmapSingle, i);
  c_this->YmapSingle->data[0] = 0.0F;
  c_this->YmapSingle->data[1] = 0.0F;
  c_this->YmapSingle->data[2] = 0.0F;
  c_this->YmapSingle->data[3] = 0.0F;
  return c_this;
}

//
// File trailer for ImageTransformer.cpp
//
// [EOF]
//
