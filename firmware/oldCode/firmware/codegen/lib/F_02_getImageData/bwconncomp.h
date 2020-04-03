//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwconncomp.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef BWCONNCOMP_H
#define BWCONNCOMP_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void bwconncomp(const emxArray_boolean_T *varargin_1, double
  *CC_Connectivity, double CC_ImageSize[2], double *CC_NumObjects,
  emxArray_real_T *CC_RegionIndices, emxArray_int32_T *CC_RegionLengths);

#endif

//
// File trailer for bwconncomp.h
//
// [EOF]
//
