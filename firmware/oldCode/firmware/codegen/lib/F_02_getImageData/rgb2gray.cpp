//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rgb2gray.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "rgb2gray.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "libmwrgb2gray_tbb.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const emxArray_uint8_T *X
//                emxArray_uint8_T *b_I
// Return Type  : void
//
void rgb2gray(const emxArray_uint8_T *X, emxArray_uint8_T *b_I)
{
  emxArray_uint8_T *inputImage;
  int i;
  int loop_ub;
  emxInit_uint8_T(&inputImage, 3);
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = X->size[0];
  b_I->size[1] = X->size[1];
  emxEnsureCapacity_uint8_T(b_I, i);
  i = inputImage->size[0] * inputImage->size[1] * inputImage->size[2];
  inputImage->size[0] = X->size[0];
  inputImage->size[1] = X->size[1];
  inputImage->size[2] = X->size[2];
  emxEnsureCapacity_uint8_T(inputImage, i);
  loop_ub = X->size[0] * X->size[1] * X->size[2];
  for (i = 0; i < loop_ub; i++) {
    inputImage->data[i] = X->data[i];
  }

  rgb2gray_tbb_uint8(&inputImage->data[0], static_cast<double>(X->size[0]) *
                     static_cast<double>(X->size[1]), &b_I->data[0], true);
  emxFree_uint8_T(&inputImage);
}

//
// File trailer for rgb2gray.cpp
//
// [EOF]
//
