//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: undistortImage.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef UNDISTORTIMAGE_H
#define UNDISTORTIMAGE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void undistortImage(const double b_I[307200],
  c_vision_internal_calibration_C *intrinsics, double J[307200]);

#endif

//
// File trailer for undistortImage.h
//
// [EOF]
//
