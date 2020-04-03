//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: disparitySGM.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "disparitySGM.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "cvstCG_disparitySGM.h"
#include "rt_nonfinite.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const emxArray_uint8_T *I1
//                const emxArray_uint8_T *I2
//                emxArray_real32_T *disparityMap
// Return Type  : void
//
void disparitySGM(const emxArray_uint8_T *I1, const emxArray_uint8_T *I2,
                  emxArray_real32_T *disparityMap)
{
  emxArray_uint32_T *leftCT;
  emxArray_uint32_T *rightCT;
  emxArray_char_T *str;
  emxArray_char_T *b_str;
  emxArray_char_T *c_str;
  unsigned int imageSize_idx_1;
  int nbytes;
  int i;
  emxArray_int16_T *matchingCost;
  emxArray_int16_T *dirCostSum;
  long i1;
  emxArray_int16_T *oneRowMinDirCostBuf1;
  emxArray_int16_T *oneRowMinDirCostBuf2;
  emxArray_int16_T *oneRowDirCostBuf1;
  emxArray_int16_T *oneRowDirCostBuf2;
  emxArray_int16_T *tenRowDirCostBuf1;
  emxArray_int16_T *tenRowDirCostBuf2;
  emxArray_uint8_T *I1Transpose;
  cvstDisparitySGMStruct_T paramStruct;
  int loop_ub;
  emxArray_uint8_T *I2Transpose;
  int b_loop_ub;
  emxArray_real32_T *outDispTranspose;
  emxInit_uint32_T(&leftCT, 2);
  emxInit_uint32_T(&rightCT, 2);
  emxInit_char_T(&str, 2);
  emxInit_char_T(&b_str, 2);
  emxInit_char_T(&c_str, 2);
  imageSize_idx_1 = static_cast<unsigned int>(I1->size[1]);
  nbytes = (int)snprintf(NULL, 0, "%d", static_cast<int>(imageSize_idx_1)) + 1;
  i = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes;
  emxEnsureCapacity_char_T(str, i);
  snprintf(&str->data[0], (size_t)nbytes, "%d", static_cast<int>(imageSize_idx_1));
  nbytes = (int)snprintf(NULL, 0, "%d", static_cast<int>(imageSize_idx_1)) + 1;
  i = b_str->size[0] * b_str->size[1];
  b_str->size[0] = 1;
  b_str->size[1] = nbytes;
  emxEnsureCapacity_char_T(b_str, i);
  snprintf(&b_str->data[0], (size_t)nbytes, "%d", static_cast<int>
           (imageSize_idx_1));
  nbytes = (int)snprintf(NULL, 0, "%d", static_cast<int>(imageSize_idx_1)) + 1;
  i = c_str->size[0] * c_str->size[1];
  c_str->size[0] = 1;
  c_str->size[1] = nbytes;
  emxEnsureCapacity_char_T(c_str, i);
  snprintf(&c_str->data[0], (size_t)nbytes, "%d", static_cast<int>
           (imageSize_idx_1));
  i = leftCT->size[0] * leftCT->size[1];
  leftCT->size[0] = I1->size[0];
  leftCT->size[1] = I1->size[1];
  emxEnsureCapacity_uint32_T(leftCT, i);
  i = rightCT->size[0] * rightCT->size[1];
  rightCT->size[0] = I1->size[0];
  rightCT->size[1] = I1->size[1];
  emxEnsureCapacity_uint32_T(rightCT, i);
  i = I1->size[1] - 128;
  emxFree_char_T(&c_str);
  emxFree_char_T(&b_str);
  emxFree_char_T(&str);
  if (i > 16777215) {
    i = MAX_int32_T;
  } else if (i <= -16777216) {
    i = MIN_int32_T;
  } else {
    i <<= 7;
  }

  emxInit_int16_T(&matchingCost, 2);
  emxInit_int16_T(&dirCostSum, 2);
  nbytes = matchingCost->size[0] * matchingCost->size[1];
  matchingCost->size[0] = I1->size[0];
  matchingCost->size[1] = i;
  emxEnsureCapacity_int16_T(matchingCost, nbytes);
  nbytes = dirCostSum->size[0] * dirCostSum->size[1];
  dirCostSum->size[0] = I1->size[0];
  dirCostSum->size[1] = i;
  emxEnsureCapacity_int16_T(dirCostSum, nbytes);
  i1 = (I1->size[1] - 126) * 3L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  emxInit_int16_T(&oneRowMinDirCostBuf1, 2);
  emxInit_int16_T(&oneRowMinDirCostBuf2, 2);
  nbytes = static_cast<int>(i1);
  i = oneRowMinDirCostBuf1->size[0] * oneRowMinDirCostBuf1->size[1];
  oneRowMinDirCostBuf1->size[0] = 1;
  oneRowMinDirCostBuf1->size[1] = nbytes;
  emxEnsureCapacity_int16_T(oneRowMinDirCostBuf1, i);
  i = oneRowMinDirCostBuf2->size[0] * oneRowMinDirCostBuf2->size[1];
  oneRowMinDirCostBuf2->size[0] = 1;
  oneRowMinDirCostBuf2->size[1] = nbytes;
  emxEnsureCapacity_int16_T(oneRowMinDirCostBuf2, i);
  i1 = nbytes * 144L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  nbytes = static_cast<int>(i1);
  if (nbytes > 2147483646) {
    nbytes = MAX_int32_T;
  } else {
    nbytes++;
  }

  emxInit_int16_T(&oneRowDirCostBuf1, 2);
  emxInit_int16_T(&oneRowDirCostBuf2, 2);
  i = oneRowDirCostBuf1->size[0] * oneRowDirCostBuf1->size[1];
  oneRowDirCostBuf1->size[0] = 1;
  oneRowDirCostBuf1->size[1] = nbytes;
  emxEnsureCapacity_int16_T(oneRowDirCostBuf1, i);
  i = oneRowDirCostBuf2->size[0] * oneRowDirCostBuf2->size[1];
  oneRowDirCostBuf2->size[0] = 1;
  oneRowDirCostBuf2->size[1] = nbytes;
  emxEnsureCapacity_int16_T(oneRowDirCostBuf2, i);
  i1 = nbytes * 10L;
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else {
    if (i1 < -2147483648L) {
      i1 = -2147483648L;
    }
  }

  emxInit_int16_T(&tenRowDirCostBuf1, 2);
  emxInit_int16_T(&tenRowDirCostBuf2, 2);
  emxInit_uint8_T(&I1Transpose, 2);
  nbytes = static_cast<int>(i1);
  i = tenRowDirCostBuf1->size[0] * tenRowDirCostBuf1->size[1];
  tenRowDirCostBuf1->size[0] = 1;
  tenRowDirCostBuf1->size[1] = nbytes;
  emxEnsureCapacity_int16_T(tenRowDirCostBuf1, i);
  i = tenRowDirCostBuf2->size[0] * tenRowDirCostBuf2->size[1];
  tenRowDirCostBuf2->size[0] = 1;
  tenRowDirCostBuf2->size[1] = nbytes;
  emxEnsureCapacity_int16_T(tenRowDirCostBuf2, i);
  paramStruct.minDisparity = 0;
  paramStruct.numberOfDisparities = 128;
  paramStruct.UniquenessThreshold = 15;
  paramStruct.Directions = 5;
  paramStruct.Penalty1 = 15;
  paramStruct.Penalty2 = 200;
  i = I1Transpose->size[0] * I1Transpose->size[1];
  I1Transpose->size[0] = I1->size[1];
  I1Transpose->size[1] = I1->size[0];
  emxEnsureCapacity_uint8_T(I1Transpose, i);
  loop_ub = I1->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = I1->size[1];
    for (nbytes = 0; nbytes < b_loop_ub; nbytes++) {
      I1Transpose->data[nbytes + I1Transpose->size[0] * i] = I1->data[i +
        I1->size[0] * nbytes];
    }
  }

  emxInit_uint8_T(&I2Transpose, 2);
  i = I2Transpose->size[0] * I2Transpose->size[1];
  I2Transpose->size[0] = I2->size[1];
  I2Transpose->size[1] = I2->size[0];
  emxEnsureCapacity_uint8_T(I2Transpose, i);
  loop_ub = I2->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = I2->size[1];
    for (nbytes = 0; nbytes < b_loop_ub; nbytes++) {
      I2Transpose->data[nbytes + I2Transpose->size[0] * i] = I2->data[i +
        I2->size[0] * nbytes];
    }
  }

  emxInit_real32_T(&outDispTranspose, 2);
  i = outDispTranspose->size[0] * outDispTranspose->size[1];
  outDispTranspose->size[0] = I1->size[1];
  outDispTranspose->size[1] = I1->size[0];
  emxEnsureCapacity_real32_T(outDispTranspose, i);
  disparitySGMCompute(&I1Transpose->data[0], &I2Transpose->data[0],
                      &leftCT->data[0], &rightCT->data[0], &matchingCost->data[0],
                      &oneRowMinDirCostBuf1->data[0],
                      &oneRowMinDirCostBuf2->data[0], &oneRowDirCostBuf1->data[0],
                      &oneRowDirCostBuf2->data[0], &tenRowDirCostBuf1->data[0],
                      &tenRowDirCostBuf2->data[0], &dirCostSum->data[0],
                      I1->size[0], I1->size[1], &outDispTranspose->data[0],
                      &paramStruct);
  i = disparityMap->size[0] * disparityMap->size[1];
  disparityMap->size[0] = outDispTranspose->size[1];
  disparityMap->size[1] = outDispTranspose->size[0];
  emxEnsureCapacity_real32_T(disparityMap, i);
  loop_ub = outDispTranspose->size[0];
  emxFree_uint8_T(&I2Transpose);
  emxFree_uint8_T(&I1Transpose);
  emxFree_int16_T(&tenRowDirCostBuf2);
  emxFree_int16_T(&tenRowDirCostBuf1);
  emxFree_int16_T(&oneRowDirCostBuf2);
  emxFree_int16_T(&oneRowDirCostBuf1);
  emxFree_int16_T(&oneRowMinDirCostBuf2);
  emxFree_int16_T(&oneRowMinDirCostBuf1);
  emxFree_int16_T(&dirCostSum);
  emxFree_int16_T(&matchingCost);
  emxFree_uint32_T(&rightCT);
  emxFree_uint32_T(&leftCT);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = outDispTranspose->size[1];
    for (nbytes = 0; nbytes < b_loop_ub; nbytes++) {
      disparityMap->data[nbytes + disparityMap->size[0] * i] =
        outDispTranspose->data[i + outDispTranspose->size[0] * nbytes];
    }
  }

  emxFree_real32_T(&outDispTranspose);
}

//
// File trailer for disparitySGM.cpp
//
// [EOF]
//
