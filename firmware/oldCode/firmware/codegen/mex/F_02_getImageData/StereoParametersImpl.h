/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * StereoParametersImpl.h
 *
 * Code generation for function 'StereoParametersImpl'
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
c_vision_internal_calibration_S *c_StereoParametersImpl_StereoPa(const
  emlrtStack *sp, c_vision_internal_calibration_S *this, const real_T
  c_varargin_1_CameraParameters1_[2], const real_T
  d_varargin_1_CameraParameters1_[2], const real_T
  e_varargin_1_CameraParameters1_[2], const char_T
  f_varargin_1_CameraParameters1_[11], real_T g_varargin_1_CameraParameters1_,
  const real_T h_varargin_1_CameraParameters1_[114], const real_T
  i_varargin_1_CameraParameters1_[114], const real_T
  j_varargin_1_CameraParameters1_[9], const struct1_T
  *varargin_1_CameraParameters2, const real_T varargin_1_RotationOfCamera2[9],
  const real_T varargin_1_TranslationOfCamera2[3], const struct3_T
  *varargin_1_RectificationParams, d_vision_internal_calibration_C *iobj_0,
  d_vision_internal_calibration_C *iobj_1);
void c_StereoParametersImpl_computeR(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, c_vision_internal_calibration_S *this, projective2d *Hleft,
  projective2d *Hright, real_T Q[16], real_T xBounds[2], real_T yBounds[2],
  boolean_T *success);
void d_StereoParametersImpl_computeR(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, c_vision_internal_calibration_S *this, projective2d *Hleft,
  projective2d *Hright, real_T Q[16], real_T xBounds[2], real_T yBounds[2],
  boolean_T *success);

/* End of code generation (StereoParametersImpl.h) */
