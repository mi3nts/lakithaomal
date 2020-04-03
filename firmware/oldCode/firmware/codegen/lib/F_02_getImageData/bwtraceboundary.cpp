//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwtraceboundary.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "bwtraceboundary.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : const emxArray_uint8_T *varargin_1
//                const double varargin_2[2]
//                emxArray_real_T *B
// Return Type  : void
//
void bwtraceboundary(const emxArray_uint8_T *varargin_1, const double
                     varargin_2[2], emxArray_real_T *B)
{
  emxArray_boolean_T *bw;
  int i;
  int checkDir;
  int numRows;
  double maxNumPoints;
  emxArray_boolean_T *b;
  unsigned int sizeB_idx_0;
  unsigned int sizeB_idx_1;
  int i1;
  int j;
  emxArray_uint8_T *bwPadImage;
  int currentCircIdx;
  double idx;
  double fOffsets[8];
  double fVOffsets[8];
  boolean_T tf;
  boolean_T exitg1;
  int nextSearchDir;
  emxArray_real_T *fScratch;
  double numPixels;
  int initDepartureDir;
  emxArray_real_T *b_fScratch;
  boolean_T foundNextPixel;
  boolean_T guard1 = false;
  static const signed char iv[8] = { 8, 8, 2, 2, 4, 4, 6, 6 };

  double neighbor;
  static const signed char iv1[8] = { 2, 3, 4, 5, 6, 7, 8, 1 };

  emxInit_boolean_T(&bw, 2);
  i = bw->size[0] * bw->size[1];
  bw->size[0] = varargin_1->size[0];
  bw->size[1] = varargin_1->size[1];
  emxEnsureCapacity_boolean_T(bw, i);
  checkDir = varargin_1->size[0] * varargin_1->size[1];
  for (i = 0; i < checkDir; i++) {
    bw->data[i] = (varargin_1->data[i] != 0);
  }

  numRows = bw->size[0];
  maxNumPoints = 2.0 * static_cast<double>(bw->size[0]) * static_cast<double>
    (bw->size[1]) + 2.0;
  emxInit_boolean_T(&b, 2);
  if ((bw->size[0] == 0) || (bw->size[1] == 0)) {
    sizeB_idx_0 = bw->size[0] + 2U;
    sizeB_idx_1 = bw->size[1] + 2U;
    i = b->size[0] * b->size[1];
    b->size[0] = static_cast<int>(sizeB_idx_0);
    b->size[1] = static_cast<int>(sizeB_idx_1);
    emxEnsureCapacity_boolean_T(b, i);
    checkDir = static_cast<int>(sizeB_idx_0) * static_cast<int>(sizeB_idx_1);
    for (i = 0; i < checkDir; i++) {
      b->data[i] = false;
    }
  } else {
    sizeB_idx_0 = static_cast<unsigned int>((static_cast<double>(bw->size[0]) +
      2.0));
    i = b->size[0] * b->size[1];
    b->size[0] = static_cast<int>(sizeB_idx_0);
    b->size[1] = static_cast<int>(static_cast<unsigned int>((static_cast<double>
      (bw->size[1]) + 2.0)));
    emxEnsureCapacity_boolean_T(b, i);
    i = static_cast<int>(sizeB_idx_0);
    for (checkDir = 0; checkDir < i; checkDir++) {
      b->data[checkDir] = false;
    }

    i = bw->size[1] + 2;
    i1 = b->size[1];
    for (j = i; j <= i1; j++) {
      currentCircIdx = b->size[0];
      for (checkDir = 0; checkDir < currentCircIdx; checkDir++) {
        b->data[checkDir + b->size[0] * (j - 1)] = false;
      }
    }

    i = bw->size[1];
    for (j = 0; j < i; j++) {
      b->data[b->size[0] * (j + 1)] = false;
    }

    i = bw->size[1];
    for (j = 0; j < i; j++) {
      i1 = bw->size[0] + 2;
      currentCircIdx = b->size[0];
      for (checkDir = i1; checkDir <= currentCircIdx; checkDir++) {
        b->data[(checkDir + b->size[0] * (j + 1)) - 1] = false;
      }
    }

    i = bw->size[1];
    for (j = 0; j < i; j++) {
      i1 = bw->size[0];
      for (checkDir = 0; checkDir < i1; checkDir++) {
        b->data[(checkDir + b->size[0] * (j + 1)) + 1] = bw->data[checkDir +
          bw->size[0] * j];
      }
    }
  }

  emxInit_uint8_T(&bwPadImage, 2);
  i = bwPadImage->size[0] * bwPadImage->size[1];
  bwPadImage->size[0] = b->size[0];
  bwPadImage->size[1] = b->size[1];
  emxEnsureCapacity_uint8_T(bwPadImage, i);
  checkDir = b->size[0] * b->size[1];
  for (i = 0; i < checkDir; i++) {
    bwPadImage->data[i] = b->data[i];
  }

  emxFree_boolean_T(&b);
  idx = (varargin_2[1] * (static_cast<double>(bw->size[0]) + 2.0) + varargin_2[0])
    + 1.0;
  fOffsets[0] = -1.0;
  fOffsets[1] = (static_cast<double>(bw->size[0]) + 2.0) - 1.0;
  fOffsets[2] = static_cast<double>(bw->size[0]) + 2.0;
  fOffsets[3] = (static_cast<double>(bw->size[0]) + 2.0) + 1.0;
  fOffsets[4] = 1.0;
  fOffsets[5] = -(static_cast<double>(bw->size[0]) + 2.0) + 1.0;
  fOffsets[6] = -(static_cast<double>(bw->size[0]) + 2.0);
  fOffsets[7] = -(static_cast<double>(bw->size[0]) + 2.0) - 1.0;
  fVOffsets[0] = -1.0;
  fVOffsets[1] = static_cast<double>(bw->size[0]) + 2.0;
  fVOffsets[2] = 1.0;
  fVOffsets[3] = -(static_cast<double>(bw->size[0]) + 2.0);
  tf = false;
  i = static_cast<int>(idx) - 1;
  emxFree_boolean_T(&bw);
  if (static_cast<signed char>(bwPadImage->data[i]) != 0) {
    checkDir = 0;
    exitg1 = false;
    while ((!exitg1) && (checkDir < 4)) {
      if (static_cast<signed char>(bwPadImage->data[static_cast<int>((idx +
             fVOffsets[checkDir])) - 1]) == 0) {
        tf = true;
        exitg1 = true;
      } else {
        checkDir++;
      }
    }
  }

  if (tf) {
    nextSearchDir = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 8)) {
      currentCircIdx = static_cast<int>(std::fmod(static_cast<double>(j) + 6.0,
        8.0));
      checkDir = currentCircIdx + -1;
      if (currentCircIdx + -1 < 0) {
        checkDir = 7;
      }

      if (checkDir == 0) {
        checkDir = 0;
      } else {
        checkDir = static_cast<int>(std::fmod(static_cast<double>(checkDir), 8.0));
        if (checkDir == 0) {
          checkDir = 0;
        }
      }

      if (static_cast<signed char>(bwPadImage->data[static_cast<int>((idx +
             fOffsets[checkDir])) - 1]) == 0) {
        nextSearchDir = currentCircIdx + 1;
        exitg1 = true;
      } else {
        j++;
      }
    }

    emxInit_real_T(&fScratch, 1);
    numPixels = 1.0;
    i1 = fScratch->size[0];
    fScratch->size[0] = 1;
    emxEnsureCapacity_real_T(fScratch, i1);
    fScratch->data[0] = idx;
    bwPadImage->data[i] = 2U;
    tf = false;
    initDepartureDir = -1;
    emxInit_real_T(&b_fScratch, 1);
    while (!tf) {
      checkDir = nextSearchDir;
      foundNextPixel = false;
      j = 0;
      guard1 = false;
      exitg1 = false;
      while ((!exitg1) && (j < 8)) {
        currentCircIdx = checkDir - 1;
        neighbor = idx + fOffsets[currentCircIdx];
        i = static_cast<int>(neighbor) - 1;
        if (static_cast<signed char>(bwPadImage->data[i]) != 0) {
          i1 = static_cast<int>(idx) - 1;
          if ((static_cast<signed char>(bwPadImage->data[i1]) == 2) &&
              (initDepartureDir == -1)) {
            initDepartureDir = checkDir;
            guard1 = true;
          } else if ((static_cast<signed char>(bwPadImage->data[i1]) == 2) &&
                     (initDepartureDir == checkDir)) {
            tf = true;
            foundNextPixel = true;
          } else {
            guard1 = true;
          }

          exitg1 = true;
        } else {
          checkDir = iv1[currentCircIdx];
          j++;
          guard1 = false;
        }
      }

      if (guard1) {
        nextSearchDir = iv[currentCircIdx];
        foundNextPixel = true;
        numPixels++;
        i1 = fScratch->size[0];
        currentCircIdx = fScratch->size[0];
        fScratch->size[0]++;
        emxEnsureCapacity_real_T(fScratch, currentCircIdx);
        fScratch->data[i1] = neighbor;
        if (numPixels == maxNumPoints) {
          tf = true;
        } else {
          if (static_cast<signed char>(bwPadImage->data[i]) != 2) {
            bwPadImage->data[i] = 3U;
          }

          idx = neighbor;
        }
      }

      if (!foundNextPixel) {
        numPixels = 2.0;
        i = b_fScratch->size[0];
        b_fScratch->size[0] = fScratch->size[0] + fScratch->size[0];
        emxEnsureCapacity_real_T(b_fScratch, i);
        checkDir = fScratch->size[0];
        for (i = 0; i < checkDir; i++) {
          b_fScratch->data[i] = fScratch->data[i];
        }

        checkDir = fScratch->size[0];
        for (i = 0; i < checkDir; i++) {
          b_fScratch->data[i + fScratch->size[0]] = fScratch->data[i];
        }

        i = fScratch->size[0];
        fScratch->size[0] = b_fScratch->size[0];
        emxEnsureCapacity_real_T(fScratch, i);
        checkDir = b_fScratch->size[0];
        for (i = 0; i < checkDir; i++) {
          fScratch->data[i] = b_fScratch->data[i];
        }

        tf = true;
      }
    }

    emxFree_real_T(&b_fScratch);
    i = static_cast<int>(numPixels);
    i1 = B->size[0] * B->size[1];
    B->size[0] = i;
    B->size[1] = 2;
    emxEnsureCapacity_real_T(B, i1);
    for (checkDir = 0; checkDir < i; checkDir++) {
      if (rtIsNaN(fScratch->data[checkDir] - 1.0)) {
        maxNumPoints = rtNaN;
      } else if (fScratch->data[checkDir] - 1.0 == 0.0) {
        maxNumPoints = 0.0;
      } else {
        maxNumPoints = std::fmod(fScratch->data[checkDir] - 1.0, static_cast<
          double>(numRows) + 2.0);
      }

      B->data[checkDir] = maxNumPoints;
      B->data[static_cast<int>((numPixels + (static_cast<double>(checkDir) + 1.0)))
        - 1] = std::floor((fScratch->data[checkDir] - 1.0) / (static_cast<double>
        (numRows) + 2.0));
    }

    emxFree_real_T(&fScratch);
  } else {
    B->size[0] = 0;
    B->size[1] = 2;
  }

  emxFree_uint8_T(&bwPadImage);
}

//
// File trailer for bwtraceboundary.cpp
//
// [EOF]
//
