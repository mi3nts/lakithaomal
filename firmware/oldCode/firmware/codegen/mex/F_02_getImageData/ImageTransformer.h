/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ImageTransformer.h
 *
 * Code generation for function 'ImageTransformer'
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
void ImageTransformer_computeMap(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2]);
boolean_T ImageTransformer_needToUpdate(const emlrtStack *sp, const
  c_vision_internal_calibration_I *this);
void ImageTransformer_update(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2], const real_T xBounds[2],
  const real_T yBounds[2]);
void b_ImageTransformer_computeMap(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2], const real_T H_T[9]);
void b_ImageTransformer_update(const emlrtStack *sp,
  c_vision_internal_calibration_I *this, const real_T intrinsicMatrix[9], const
  real_T radialDist[2], const real_T tangentialDist[2], const real_T xBounds[2],
  const real_T yBounds[2]);
c_vision_internal_calibration_I *c_ImageTransformer_ImageTransfo(const
  emlrtStack *sp, c_vision_internal_calibration_I *this);

/* End of code generation (ImageTransformer.h) */
