//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: F_02_getImageData.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef F_02_GETIMAGEDATA_H
#define F_02_GETIMAGEDATA_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void F_02_getImageData(const struct0_T *stereoParamsStruct, const
  struct4_T *thermalParamsStruct, const projective2d transformParametors[26],
  emxArray_uint8_T *frameLeftRect, emxArray_real_T *finalCelciusImage,
  emxArray_real32_T *distanceImage);
extern void F_02_getImageData_free();
extern void F_02_getImageData_init();

#endif

//
// File trailer for F_02_getImageData.h
//
// [EOF]
//
