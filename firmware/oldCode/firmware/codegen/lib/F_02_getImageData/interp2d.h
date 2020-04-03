//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp2d.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef INTERP2D_H
#define INTERP2D_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void b_interp2d(const emxArray_uint8_T *inputImage__, const
  emxArray_real32_T *Xin, const emxArray_real32_T *Yin, emxArray_uint8_T
  *outputImage_);
extern void c_interp2d(const emxArray_uint8_T *inputImage__, const
  emxArray_real32_T *Xin, const emxArray_real32_T *Yin, const unsigned char
  fillValuesIn_data[], const int fillValuesIn_size[3], emxArray_uint8_T
  *outputImage_);
extern void interp2d(const double inputImage__[307200], const emxArray_real_T
                     *Xin, const emxArray_real_T *Yin, emxArray_real_T
                     *outputImage_);

#endif

//
// File trailer for interp2d.h
//
// [EOF]
//
