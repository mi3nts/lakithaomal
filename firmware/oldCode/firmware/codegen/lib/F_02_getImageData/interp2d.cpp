//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp2d.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "interp2d.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "libmwimterp2d.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions

//
// Arguments    : const emxArray_uint8_T *inputImage__
//                const emxArray_real32_T *Xin
//                const emxArray_real32_T *Yin
//                emxArray_uint8_T *outputImage_
// Return Type  : void
//
void b_interp2d(const emxArray_uint8_T *inputImage__, const emxArray_real32_T
                *Xin, const emxArray_real32_T *Yin, emxArray_uint8_T
                *outputImage_)
{
  emxArray_real32_T *X_T;
  int i;
  unsigned char fillValues;
  int loop_ub;
  emxArray_real32_T *Y_T;
  double b_inputImage__[3];
  double b_outputImage_[2];
  emxInit_real32_T(&X_T, 2);
  i = outputImage_->size[0] * outputImage_->size[1];
  outputImage_->size[0] = Xin->size[0];
  outputImage_->size[1] = Xin->size[1];
  emxEnsureCapacity_uint8_T(outputImage_, i);
  fillValues = 0U;
  i = X_T->size[0] * X_T->size[1];
  X_T->size[0] = Yin->size[0];
  X_T->size[1] = Yin->size[1];
  emxEnsureCapacity_real32_T(X_T, i);
  loop_ub = Yin->size[0] * Yin->size[1];
  for (i = 0; i < loop_ub; i++) {
    X_T->data[i] = Yin->data[i];
  }

  emxInit_real32_T(&Y_T, 2);
  i = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = Xin->size[0];
  Y_T->size[1] = Xin->size[1];
  emxEnsureCapacity_real32_T(Y_T, i);
  loop_ub = Xin->size[0] * Xin->size[1];
  for (i = 0; i < loop_ub; i++) {
    Y_T->data[i] = Xin->data[i];
  }

  b_inputImage__[2] = 1.0;
  b_inputImage__[0] = inputImage__->size[0];
  b_outputImage_[0] = Xin->size[0];
  b_inputImage__[1] = inputImage__->size[1];
  b_outputImage_[1] = Xin->size[1];
  imterp2d32f_uint8(&inputImage__->data[0], b_inputImage__, &X_T->data[0],
                    &Y_T->data[0], b_outputImage_, 1.0, true, &fillValues,
                    &outputImage_->data[0]);
  emxFree_real32_T(&Y_T);
  emxFree_real32_T(&X_T);
}

//
// Arguments    : const emxArray_uint8_T *inputImage__
//                const emxArray_real32_T *Xin
//                const emxArray_real32_T *Yin
//                const unsigned char fillValuesIn_data[]
//                const int fillValuesIn_size[3]
//                emxArray_uint8_T *outputImage_
// Return Type  : void
//
void c_interp2d(const emxArray_uint8_T *inputImage__, const emxArray_real32_T
                *Xin, const emxArray_real32_T *Yin, const unsigned char
                fillValuesIn_data[], const int fillValuesIn_size[3],
                emxArray_uint8_T *outputImage_)
{
  int fill_size_idx_0;
  int fill_size_idx_2;
  int loop_ub;
  int i;
  unsigned char fill_data[9];
  emxArray_real32_T *X_T;
  emxArray_real32_T *Y_T;
  double outputImageSize[3];
  double b_outputImage_[3];
  if (fillValuesIn_size[2] == 1) {
    fill_size_idx_0 = static_cast<signed char>(inputImage__->size[2]);
    fill_size_idx_2 = 1;
    if (static_cast<signed char>(inputImage__->size[2]) != 0) {
      i = static_cast<signed char>(inputImage__->size[2]) - 1;
      if (0 <= i) {
        std::memset(&fill_data[0], 0, (i + 1) * sizeof(unsigned char));
      }
    }
  } else {
    fill_size_idx_0 = 1;
    fill_size_idx_2 = fillValuesIn_size[2];
    loop_ub = fillValuesIn_size[0] * fillValuesIn_size[1] * fillValuesIn_size[2];
    if (0 <= loop_ub - 1) {
      std::memcpy(&fill_data[0], &fillValuesIn_data[0], loop_ub * sizeof
                  (unsigned char));
    }
  }

  emxInit_real32_T(&X_T, 2);
  i = outputImage_->size[0] * outputImage_->size[1] * outputImage_->size[2];
  outputImage_->size[0] = Xin->size[0];
  outputImage_->size[1] = Xin->size[1];
  outputImage_->size[2] = static_cast<short>(inputImage__->size[2]);
  emxEnsureCapacity_uint8_T(outputImage_, i);
  i = X_T->size[0] * X_T->size[1];
  X_T->size[0] = Yin->size[0];
  X_T->size[1] = Yin->size[1];
  emxEnsureCapacity_real32_T(X_T, i);
  loop_ub = Yin->size[0] * Yin->size[1];
  for (i = 0; i < loop_ub; i++) {
    X_T->data[i] = Yin->data[i];
  }

  emxInit_real32_T(&Y_T, 2);
  i = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = Xin->size[0];
  Y_T->size[1] = Xin->size[1];
  emxEnsureCapacity_real32_T(Y_T, i);
  loop_ub = Xin->size[0] * Xin->size[1];
  for (i = 0; i < loop_ub; i++) {
    Y_T->data[i] = Xin->data[i];
  }

  outputImageSize[0] = static_cast<short>(inputImage__->size[0]);
  outputImageSize[1] = static_cast<short>(inputImage__->size[1]);
  outputImageSize[2] = static_cast<short>(inputImage__->size[2]);
  b_outputImage_[0] = Xin->size[0];
  b_outputImage_[1] = Xin->size[1];
  b_outputImage_[2] = outputImage_->size[2];
  imterp2d32f_uint8(&inputImage__->data[0], outputImageSize, &X_T->data[0],
                    &Y_T->data[0], b_outputImage_, 2.0, fill_size_idx_0 *
                    fill_size_idx_2 == 1, &fill_data[0], &outputImage_->data[0]);
  emxFree_real32_T(&Y_T);
  emxFree_real32_T(&X_T);
}

//
// Arguments    : const double inputImage__[307200]
//                const emxArray_real_T *Xin
//                const emxArray_real_T *Yin
//                emxArray_real_T *outputImage_
// Return Type  : void
//
void interp2d(const double inputImage__[307200], const emxArray_real_T *Xin,
              const emxArray_real_T *Yin, emxArray_real_T *outputImage_)
{
  emxArray_real_T *X_T;
  int i;
  double fillValues;
  int loop_ub;
  emxArray_real_T *Y_T;
  double b_outputImage_[2];
  double b_dv[3];
  emxInit_real_T(&X_T, 2);
  i = outputImage_->size[0] * outputImage_->size[1];
  outputImage_->size[0] = Xin->size[0];
  outputImage_->size[1] = Xin->size[1];
  emxEnsureCapacity_real_T(outputImage_, i);
  fillValues = 0.0;
  i = X_T->size[0] * X_T->size[1];
  X_T->size[0] = Yin->size[0];
  X_T->size[1] = Yin->size[1];
  emxEnsureCapacity_real_T(X_T, i);
  loop_ub = Yin->size[0] * Yin->size[1];
  for (i = 0; i < loop_ub; i++) {
    X_T->data[i] = Yin->data[i];
  }

  emxInit_real_T(&Y_T, 2);
  i = Y_T->size[0] * Y_T->size[1];
  Y_T->size[0] = Xin->size[0];
  Y_T->size[1] = Xin->size[1];
  emxEnsureCapacity_real_T(Y_T, i);
  loop_ub = Xin->size[0] * Xin->size[1];
  for (i = 0; i < loop_ub; i++) {
    Y_T->data[i] = Xin->data[i];
  }

  b_outputImage_[0] = Xin->size[0];
  b_outputImage_[1] = Xin->size[1];
  b_dv[0] = dv1[0];
  b_dv[1] = dv1[1];
  b_dv[2] = dv1[2];
  imterp2d64f_real64(inputImage__, b_dv, &X_T->data[0], &Y_T->data[0],
                     b_outputImage_, 2.0, true, &fillValues, &outputImage_->
                     data[0]);
  emxFree_real_T(&Y_T);
  emxFree_real_T(&X_T);
}

//
// File trailer for interp2d.cpp
//
// [EOF]
//
