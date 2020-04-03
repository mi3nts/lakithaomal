//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CameraParametersImpl.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef CAMERAPARAMETERSIMPL_H
#define CAMERAPARAMETERSIMPL_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void c_CameraParametersImpl_computeU(const
  d_vision_internal_calibration_C *b_this, const double imageSize[2], double
  xBounds[2], double yBounds[2]);
extern void d_CameraParametersImpl_computeU(const
  d_vision_internal_calibration_C *b_this, const double imageSize[2], double
  xBounds[2], double yBounds[2]);

#endif

//
// File trailer for CameraParametersImpl.h
//
// [EOF]
//
