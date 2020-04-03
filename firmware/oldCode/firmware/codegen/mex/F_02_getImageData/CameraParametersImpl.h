/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CameraParametersImpl.h
 *
 * Code generation for function 'CameraParametersImpl'
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
d_vision_internal_calibration_C *c_CameraParametersImpl_CameraPa(const
  emlrtStack *sp, d_vision_internal_calibration_C *this, const real_T
  varargin_1_RadialDistortion[2], const real_T varargin_1_TangentialDistortion[2],
  const real_T varargin_1_ImageSize[2], const char_T varargin_1_WorldUnits[11],
  real_T c_varargin_1_NumRadialDistortio, const real_T
  varargin_1_RotationVectors[114], const real_T varargin_1_TranslationVectors
  [114], const real_T varargin_1_IntrinsicMatrix[9]);
void c_CameraParametersImpl_computeU(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, const d_vision_internal_calibration_C *this, real_T xBounds[2],
  real_T yBounds[2]);
void c_CameraParametersImpl_createUn(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, const d_vision_internal_calibration_C *this, emxArray_uint8_T *
  undistortedMask, real_T xBoundsBig[2], real_T yBoundsBig[2]);
void c_CameraParametersImpl_getValid(const emlrtStack *sp, const
  d_vision_internal_calibration_C *this, const emxArray_uint8_T *undistortedMask,
  const real_T xBoundsBig[2], const real_T yBoundsBig[2], real_T xBounds[2],
  real_T yBounds[2]);
c_vision_internal_calibration_C *d_CameraParametersImpl_CameraPa(const
  emlrtStack *sp, c_vision_internal_calibration_C *this, const real_T
  varargin_1_RadialDistortion[2], const real_T varargin_1_TangentialDistortion[2],
  const real_T varargin_1_ImageSize[2], real_T c_varargin_1_NumRadialDistortio,
  const real_T varargin_1_RotationVectors[84], const real_T
  varargin_1_TranslationVectors[84], const real_T varargin_1_IntrinsicMatrix[9]);

/* End of code generation (CameraParametersImpl.h) */
