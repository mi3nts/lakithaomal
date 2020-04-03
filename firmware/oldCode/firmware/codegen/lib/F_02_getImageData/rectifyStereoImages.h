//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rectifyStereoImages.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef RECTIFYSTEREOIMAGES_H
#define RECTIFYSTEREOIMAGES_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void rectifyStereoImages(const emxArray_uint8_T *I1, const
  emxArray_uint8_T *I2, c_vision_internal_calibration_S *stereoParams,
  emxArray_uint8_T *rectifiedImage1, emxArray_uint8_T *rectifiedImage2);

#endif

//
// File trailer for rectifyStereoImages.h
//
// [EOF]
//
