//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef IMAGETRANSFORMER_H
#define IMAGETRANSFORMER_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void ImageTransformer_computeMap(c_vision_internal_calibration_I *b_this,
  const double intrinsicMatrix[9], const double radialDist[2], const double
  tangentialDist[2]);
extern boolean_T ImageTransformer_needToUpdate(const
  c_vision_internal_calibration_I *b_this, const emxArray_uint8_T *b_I);
extern void b_ImageTransformer_computeMap(c_vision_internal_calibration_I
  *b_this, const double intrinsicMatrix[9], const double radialDist[2], const
  double tangentialDist[2], const double H_T[9]);
extern c_vision_internal_calibration_I *c_ImageTransformer_ImageTransfo
  (c_vision_internal_calibration_I *b_this);

#endif

//
// File trailer for ImageTransformer.h
//
// [EOF]
//
