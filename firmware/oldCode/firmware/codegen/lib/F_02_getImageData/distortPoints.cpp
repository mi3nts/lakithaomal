//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: distortPoints.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "distortPoints.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *points
//                const double intrinsicMatrix[9]
//                const double radialDistortion[2]
//                const double tangentialDistortion[2]
//                emxArray_real_T *distortedPoints
// Return Type  : void
//
void distortPoints(const emxArray_real_T *points, const double intrinsicMatrix[9],
                   const double radialDistortion[2], const double
                   tangentialDistortion[2], emxArray_real_T *distortedPoints)
{
  emxArray_real_T *centeredPoints;
  int i;
  int acoef;
  emxArray_real_T *yNorm;
  int k;
  emxArray_real_T *xNorm;
  emxArray_real_T *b;
  emxArray_real_T *b_b;
  emxArray_real_T *r2;
  emxArray_real_T *r4;
  emxArray_real_T *xyProduct;
  double a;
  double b_a;
  emxArray_real_T *b_centeredPoints;
  double d;
  emxArray_real_T *distortedNormalizedPoints;
  emxInit_real_T(&centeredPoints, 2);
  i = centeredPoints->size[0] * centeredPoints->size[1];
  centeredPoints->size[0] = points->size[0];
  centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(centeredPoints, i);
  if (points->size[0] != 0) {
    acoef = (points->size[0] != 1);
    i = points->size[0] - 1;
    for (k = 0; k <= i; k++) {
      centeredPoints->data[k] = points->data[acoef * k] - intrinsicMatrix[2];
    }

    i = centeredPoints->size[0] - 1;
    for (k = 0; k <= i; k++) {
      centeredPoints->data[k + centeredPoints->size[0]] = points->data[acoef * k
        + points->size[0]] - intrinsicMatrix[5];
    }
  }

  emxInit_real_T(&yNorm, 1);
  acoef = centeredPoints->size[0];
  i = yNorm->size[0];
  yNorm->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(yNorm, i);
  for (i = 0; i < acoef; i++) {
    yNorm->data[i] = centeredPoints->data[i + centeredPoints->size[0]] /
      intrinsicMatrix[4];
  }

  emxInit_real_T(&xNorm, 1);
  acoef = centeredPoints->size[0];
  i = xNorm->size[0];
  xNorm->size[0] = centeredPoints->size[0];
  emxEnsureCapacity_real_T(xNorm, i);
  for (i = 0; i < acoef; i++) {
    xNorm->data[i] = centeredPoints->data[i] / intrinsicMatrix[0];
  }

  emxInit_real_T(&b, 1);
  i = b->size[0];
  b->size[0] = xNorm->size[0];
  emxEnsureCapacity_real_T(b, i);
  acoef = xNorm->size[0];
  for (k = 0; k < acoef; k++) {
    b->data[k] = xNorm->data[k] * xNorm->data[k];
  }

  emxInit_real_T(&b_b, 1);
  i = b_b->size[0];
  b_b->size[0] = yNorm->size[0];
  emxEnsureCapacity_real_T(b_b, i);
  acoef = yNorm->size[0];
  for (k = 0; k < acoef; k++) {
    b_b->data[k] = yNorm->data[k] * yNorm->data[k];
  }

  emxInit_real_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = b->size[0];
  emxEnsureCapacity_real_T(r2, i);
  acoef = b->size[0];
  for (i = 0; i < acoef; i++) {
    r2->data[i] = b->data[i] + b_b->data[i];
  }

  emxInit_real_T(&r4, 1);
  i = r4->size[0];
  r4->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(r4, i);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] = r2->data[i] * r2->data[i];
  }

  i = r4->size[0];
  r4->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(r4, i);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    r4->data[i] = (radialDistortion[0] * r2->data[i] + radialDistortion[1] *
                   r4->data[i]) + 0.0 * (r2->data[i] * r4->data[i]);
  }

  emxInit_real_T(&xyProduct, 1);
  i = xyProduct->size[0];
  xyProduct->size[0] = xNorm->size[0];
  emxEnsureCapacity_real_T(xyProduct, i);
  acoef = xNorm->size[0];
  for (i = 0; i < acoef; i++) {
    xyProduct->data[i] = xNorm->data[i] * yNorm->data[i];
  }

  a = 2.0 * tangentialDistortion[0];
  b_a = 2.0 * tangentialDistortion[1];
  i = centeredPoints->size[0] * centeredPoints->size[1];
  centeredPoints->size[0] = xNorm->size[0];
  centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(centeredPoints, i);
  acoef = xNorm->size[0];
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i] = xNorm->data[i];
  }

  emxFree_real_T(&xNorm);
  acoef = yNorm->size[0];
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i + centeredPoints->size[0]] = yNorm->data[i];
  }

  emxFree_real_T(&yNorm);
  emxInit_real_T(&b_centeredPoints, 2);
  i = b_centeredPoints->size[0] * b_centeredPoints->size[1];
  b_centeredPoints->size[0] = centeredPoints->size[0];
  b_centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(b_centeredPoints, i);
  acoef = centeredPoints->size[0];
  for (i = 0; i < acoef; i++) {
    d = centeredPoints->data[i];
    b_centeredPoints->data[i] = d + d * r4->data[i];
  }

  acoef = centeredPoints->size[0];
  for (i = 0; i < acoef; i++) {
    d = centeredPoints->data[i + centeredPoints->size[0]];
    b_centeredPoints->data[i + b_centeredPoints->size[0]] = d + d * r4->data[i];
  }

  emxFree_real_T(&r4);
  i = centeredPoints->size[0] * centeredPoints->size[1];
  centeredPoints->size[0] = xyProduct->size[0];
  centeredPoints->size[1] = 2;
  emxEnsureCapacity_real_T(centeredPoints, i);
  acoef = xyProduct->size[0];
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i] = a * xyProduct->data[i] + tangentialDistortion[1] *
      (r2->data[i] + 2.0 * b->data[i]);
  }

  emxFree_real_T(&b);
  acoef = r2->size[0];
  for (i = 0; i < acoef; i++) {
    centeredPoints->data[i + centeredPoints->size[0]] = tangentialDistortion[0] *
      (r2->data[i] + 2.0 * b_b->data[i]) + b_a * xyProduct->data[i];
  }

  emxFree_real_T(&b_b);
  emxFree_real_T(&xyProduct);
  emxFree_real_T(&r2);
  emxInit_real_T(&distortedNormalizedPoints, 2);
  i = distortedNormalizedPoints->size[0] * distortedNormalizedPoints->size[1];
  distortedNormalizedPoints->size[0] = b_centeredPoints->size[0];
  distortedNormalizedPoints->size[1] = 2;
  emxEnsureCapacity_real_T(distortedNormalizedPoints, i);
  acoef = b_centeredPoints->size[0] * b_centeredPoints->size[1];
  for (i = 0; i < acoef; i++) {
    distortedNormalizedPoints->data[i] = b_centeredPoints->data[i] +
      centeredPoints->data[i];
  }

  emxFree_real_T(&b_centeredPoints);
  emxFree_real_T(&centeredPoints);
  acoef = distortedNormalizedPoints->size[0];
  k = distortedNormalizedPoints->size[0];
  i = distortedPoints->size[0] * distortedPoints->size[1];
  distortedPoints->size[0] = distortedNormalizedPoints->size[0];
  distortedPoints->size[1] = 2;
  emxEnsureCapacity_real_T(distortedPoints, i);
  for (i = 0; i < acoef; i++) {
    distortedPoints->data[i] = (distortedNormalizedPoints->data[i] *
      intrinsicMatrix[0] + intrinsicMatrix[2]) + intrinsicMatrix[1] *
      distortedNormalizedPoints->data[i + distortedNormalizedPoints->size[0]];
  }

  for (i = 0; i < k; i++) {
    distortedPoints->data[i + distortedPoints->size[0]] =
      distortedNormalizedPoints->data[i + distortedNormalizedPoints->size[0]] *
      intrinsicMatrix[4] + intrinsicMatrix[5];
  }

  emxFree_real_T(&distortedNormalizedPoints);
}

//
// File trailer for distortPoints.cpp
//
// [EOF]
//
