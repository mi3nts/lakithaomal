//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: reconstructScene.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "reconstructScene.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const emxArray_real32_T *disparityMap
//                const c_vision_internal_calibration_S *stereoParams
//                emxArray_real32_T *xyzPoints
// Return Type  : void
//
void reconstructScene(const emxArray_real32_T *disparityMap, const
                      c_vision_internal_calibration_S *stereoParams,
                      emxArray_real32_T *xyzPoints)
{
  int i;
  emxArray_real_T *y;
  float Q[16];
  emxArray_real_T *b_y;
  int nx;
  emxArray_real32_T *x;
  emxArray_real32_T *c_y;
  emxArray_real32_T *X;
  emxArray_real32_T *Y;
  int ny;
  int j;
  int b_i;
  emxArray_real32_T *points2dHomog;
  int boffset;
  emxArray_real32_T *points3dHomog;
  emxArray_real32_T *b;
  float temp;
  int aoffset;
  emxArray_real32_T *points3d;
  emxArray_real32_T *Z;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  for (i = 0; i < 16; i++) {
    Q[i] = static_cast<float>(stereoParams->RectificationParams.Q[i]);
  }

  emxInit_real_T(&y, 2);
  if (disparityMap->size[1] < 1) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = static_cast<int>((static_cast<double>(disparityMap->size[1]) -
      1.0)) + 1;
    emxEnsureCapacity_real_T(y, i);
    nx = static_cast<int>((static_cast<double>(disparityMap->size[1]) - 1.0));
    for (i = 0; i <= nx; i++) {
      y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real_T(&b_y, 2);
  if (disparityMap->size[0] < 1) {
    b_y->size[0] = 1;
    b_y->size[1] = 0;
  } else {
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = static_cast<int>((static_cast<double>(disparityMap->size[0])
      - 1.0)) + 1;
    emxEnsureCapacity_real_T(b_y, i);
    nx = static_cast<int>((static_cast<double>(disparityMap->size[0]) - 1.0));
    for (i = 0; i <= nx; i++) {
      b_y->data[i] = static_cast<double>(i) + 1.0;
    }
  }

  emxInit_real32_T(&x, 2);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = y->size[1];
  emxEnsureCapacity_real32_T(x, i);
  nx = y->size[0] * y->size[1];
  for (i = 0; i < nx; i++) {
    x->data[i] = static_cast<float>(y->data[i]);
  }

  emxFree_real_T(&y);
  emxInit_real32_T(&c_y, 2);
  i = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = b_y->size[1];
  emxEnsureCapacity_real32_T(c_y, i);
  nx = b_y->size[0] * b_y->size[1];
  for (i = 0; i < nx; i++) {
    c_y->data[i] = static_cast<float>(b_y->data[i]);
  }

  emxFree_real_T(&b_y);
  emxInit_real32_T(&X, 2);
  emxInit_real32_T(&Y, 2);
  nx = x->size[1];
  ny = c_y->size[1];
  i = X->size[0] * X->size[1];
  X->size[0] = c_y->size[1];
  X->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(X, i);
  i = Y->size[0] * Y->size[1];
  Y->size[0] = c_y->size[1];
  Y->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(Y, i);
  if ((x->size[1] != 0) && (c_y->size[1] != 0)) {
    for (j = 0; j < nx; j++) {
      for (b_i = 0; b_i < ny; b_i++) {
        X->data[b_i + X->size[0] * j] = x->data[j];
        Y->data[b_i + Y->size[0] * j] = c_y->data[b_i];
      }
    }
  }

  emxFree_real32_T(&c_y);
  emxFree_real32_T(&x);
  emxInit_real32_T(&points2dHomog, 2);
  nx = X->size[0] * X->size[1];
  ny = Y->size[0] * Y->size[1];
  boffset = disparityMap->size[0] * disparityMap->size[1];
  i = points2dHomog->size[0] * points2dHomog->size[1];
  points2dHomog->size[0] = nx;
  points2dHomog->size[1] = 4;
  emxEnsureCapacity_real32_T(points2dHomog, i);
  for (i = 0; i < nx; i++) {
    points2dHomog->data[i] = X->data[i];
  }

  for (i = 0; i < ny; i++) {
    points2dHomog->data[i + points2dHomog->size[0]] = Y->data[i];
  }

  for (i = 0; i < boffset; i++) {
    points2dHomog->data[i + points2dHomog->size[0] * 2] = disparityMap->data[i];
  }

  nx = disparityMap->size[0] * disparityMap->size[1];
  for (i = 0; i < nx; i++) {
    points2dHomog->data[i + points2dHomog->size[0] * 3] = 1.0F;
  }

  emxInit_real32_T(&points3dHomog, 2);
  nx = points2dHomog->size[0];
  i = points3dHomog->size[0] * points3dHomog->size[1];
  points3dHomog->size[0] = points2dHomog->size[0];
  points3dHomog->size[1] = 4;
  emxEnsureCapacity_real32_T(points3dHomog, i);
  for (j = 0; j < 4; j++) {
    ny = j * nx;
    boffset = j << 2;
    for (b_i = 0; b_i < nx; b_i++) {
      points3dHomog->data[ny + b_i] = 0.0F;
    }

    for (b_i = 0; b_i < nx; b_i++) {
      i = ny + b_i;
      points3dHomog->data[i] += Q[boffset] * points2dHomog->data[b_i];
    }

    temp = Q[boffset + 1];
    for (b_i = 0; b_i < nx; b_i++) {
      i = ny + b_i;
      points3dHomog->data[i] += temp * points2dHomog->data[nx + b_i];
    }

    aoffset = nx << 1;
    temp = Q[boffset + 2];
    for (b_i = 0; b_i < nx; b_i++) {
      i = ny + b_i;
      points3dHomog->data[i] += temp * points2dHomog->data[aoffset + b_i];
    }

    aoffset = 3 * nx;
    temp = Q[boffset + 3];
    for (b_i = 0; b_i < nx; b_i++) {
      i = ny + b_i;
      points3dHomog->data[i] += temp * points2dHomog->data[aoffset + b_i];
    }
  }

  emxFree_real32_T(&points2dHomog);
  emxInit_real32_T(&b, 1);
  nx = points3dHomog->size[0];
  i = b->size[0];
  b->size[0] = points3dHomog->size[0];
  emxEnsureCapacity_real32_T(b, i);
  for (i = 0; i < nx; i++) {
    b->data[i] = 1.0F / points3dHomog->data[i + points3dHomog->size[0] * 3];
  }

  if (b->size[0] == 1) {
    nx = points3dHomog->size[0];
  } else if (points3dHomog->size[0] == 1) {
    nx = b->size[0];
  } else if (points3dHomog->size[0] == b->size[0]) {
    nx = points3dHomog->size[0];
  } else if (b->size[0] < points3dHomog->size[0]) {
    nx = b->size[0];
  } else {
    nx = points3dHomog->size[0];
  }

  emxInit_real32_T(&points3d, 2);
  i = points3d->size[0] * points3d->size[1];
  points3d->size[0] = nx;
  points3d->size[1] = 3;
  emxEnsureCapacity_real32_T(points3d, i);
  if (nx != 0) {
    boffset = (points3dHomog->size[0] != 1);
    nx = (b->size[0] != 1);
    for (ny = 0; ny < 3; ny++) {
      i = points3d->size[0] - 1;
      for (aoffset = 0; aoffset <= i; aoffset++) {
        points3d->data[aoffset + points3d->size[0] * ny] = points3dHomog->
          data[boffset * aoffset + points3dHomog->size[0] * ny] * b->data[nx *
          aoffset];
      }
    }
  }

  emxFree_real32_T(&points3dHomog);
  nx = points3d->size[0];
  i = b->size[0];
  b->size[0] = points3d->size[0];
  emxEnsureCapacity_real32_T(b, i);
  for (i = 0; i < nx; i++) {
    b->data[i] = points3d->data[i];
  }

  i = X->size[0] * X->size[1];
  X->size[0] = disparityMap->size[0];
  X->size[1] = disparityMap->size[1];
  emxEnsureCapacity_real32_T(X, i);
  nx = disparityMap->size[0] * disparityMap->size[1];
  for (i = 0; i < nx; i++) {
    X->data[i] = b->data[i];
  }

  nx = points3d->size[0];
  i = b->size[0];
  b->size[0] = points3d->size[0];
  emxEnsureCapacity_real32_T(b, i);
  for (i = 0; i < nx; i++) {
    b->data[i] = points3d->data[i + points3d->size[0]];
  }

  i = Y->size[0] * Y->size[1];
  Y->size[0] = disparityMap->size[0];
  Y->size[1] = disparityMap->size[1];
  emxEnsureCapacity_real32_T(Y, i);
  nx = disparityMap->size[0] * disparityMap->size[1];
  for (i = 0; i < nx; i++) {
    Y->data[i] = b->data[i];
  }

  nx = points3d->size[0];
  i = b->size[0];
  b->size[0] = points3d->size[0];
  emxEnsureCapacity_real32_T(b, i);
  for (i = 0; i < nx; i++) {
    b->data[i] = points3d->data[i + points3d->size[0] * 2];
  }

  emxFree_real32_T(&points3d);
  emxInit_real32_T(&Z, 2);
  i = Z->size[0] * Z->size[1];
  Z->size[0] = disparityMap->size[0];
  Z->size[1] = disparityMap->size[1];
  emxEnsureCapacity_real32_T(Z, i);
  nx = disparityMap->size[0] * disparityMap->size[1];
  for (i = 0; i < nx; i++) {
    Z->data[i] = b->data[i];
  }

  emxFree_real32_T(&b);
  ny = disparityMap->size[0] * disparityMap->size[1] - 1;
  nx = 0;
  for (b_i = 0; b_i <= ny; b_i++) {
    if (disparityMap->data[b_i] == -3.402823466E+38F) {
      nx++;
    }
  }

  emxInit_int32_T(&r, 1);
  i = r->size[0];
  r->size[0] = nx;
  emxEnsureCapacity_int32_T(r, i);
  nx = 0;
  for (b_i = 0; b_i <= ny; b_i++) {
    if (disparityMap->data[b_i] == -3.402823466E+38F) {
      r->data[nx] = b_i + 1;
      nx++;
    }
  }

  nx = r->size[0];
  for (i = 0; i < nx; i++) {
    X->data[r->data[i] - 1] = rtNaNF;
  }

  emxFree_int32_T(&r);
  ny = disparityMap->size[0] * disparityMap->size[1] - 1;
  nx = 0;
  for (b_i = 0; b_i <= ny; b_i++) {
    if (disparityMap->data[b_i] == -3.402823466E+38F) {
      nx++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = nx;
  emxEnsureCapacity_int32_T(r1, i);
  nx = 0;
  for (b_i = 0; b_i <= ny; b_i++) {
    if (disparityMap->data[b_i] == -3.402823466E+38F) {
      r1->data[nx] = b_i + 1;
      nx++;
    }
  }

  nx = r1->size[0];
  for (i = 0; i < nx; i++) {
    Y->data[r1->data[i] - 1] = rtNaNF;
  }

  emxFree_int32_T(&r1);
  ny = disparityMap->size[0] * disparityMap->size[1] - 1;
  nx = 0;
  for (b_i = 0; b_i <= ny; b_i++) {
    if (disparityMap->data[b_i] == -3.402823466E+38F) {
      nx++;
    }
  }

  emxInit_int32_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = nx;
  emxEnsureCapacity_int32_T(r2, i);
  nx = 0;
  for (b_i = 0; b_i <= ny; b_i++) {
    if (disparityMap->data[b_i] == -3.402823466E+38F) {
      r2->data[nx] = b_i + 1;
      nx++;
    }
  }

  nx = r2->size[0];
  for (i = 0; i < nx; i++) {
    Z->data[r2->data[i] - 1] = rtNaNF;
  }

  emxFree_int32_T(&r2);
  i = xyzPoints->size[0] * xyzPoints->size[1] * xyzPoints->size[2];
  xyzPoints->size[0] = X->size[0];
  xyzPoints->size[1] = X->size[1];
  xyzPoints->size[2] = 3;
  emxEnsureCapacity_real32_T(xyzPoints, i);
  nx = -1;
  i = X->size[0] * X->size[1];
  for (j = 0; j < i; j++) {
    nx++;
    xyzPoints->data[nx] = X->data[j];
  }

  emxFree_real32_T(&X);
  i = Y->size[0] * Y->size[1];
  for (j = 0; j < i; j++) {
    nx++;
    xyzPoints->data[nx] = Y->data[j];
  }

  emxFree_real32_T(&Y);
  i = Z->size[0] * Z->size[1];
  for (j = 0; j < i; j++) {
    nx++;
    xyzPoints->data[nx] = Z->data[j];
  }

  emxFree_real32_T(&Z);
}

//
// File trailer for reconstructScene.cpp
//
// [EOF]
//
