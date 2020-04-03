//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: distortPoints.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef DISTORTPOINTS_H
#define DISTORTPOINTS_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void distortPoints(const emxArray_real_T *points, const double
  intrinsicMatrix[9], const double radialDistortion[2], const double
  tangentialDistortion[2], emxArray_real_T *distortedPoints);

#endif

//
// File trailer for distortPoints.h
//
// [EOF]
//
