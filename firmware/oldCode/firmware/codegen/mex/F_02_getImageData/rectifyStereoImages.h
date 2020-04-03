/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rectifyStereoImages.h
 *
 * Code generation for function 'rectifyStereoImages'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

/* Function Declarations */
void rectifyStereoImages(F_02_getImageDataStackData *SD, const emlrtStack *sp,
  const uint8_T I1[921600], const uint8_T I2[921600],
  c_vision_internal_calibration_S *stereoParams, emxArray_uint8_T
  *rectifiedImage1, emxArray_uint8_T *rectifiedImage2);

/* End of code generation (rectifyStereoImages.h) */
