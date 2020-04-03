//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: reconstructScene.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef RECONSTRUCTSCENE_H
#define RECONSTRUCTSCENE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void reconstructScene(const emxArray_real32_T *disparityMap, const
  c_vision_internal_calibration_S *stereoParams, emxArray_real32_T *xyzPoints);

#endif

//
// File trailer for reconstructScene.h
//
// [EOF]
//
