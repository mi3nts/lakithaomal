//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: StereoParametersImpl.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef STEREOPARAMETERSIMPL_H
#define STEREOPARAMETERSIMPL_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern c_vision_internal_calibration_S *c_StereoParametersImpl_StereoPa
  (c_vision_internal_calibration_S *b_this, const double
   c_varargin_1_CameraParameters1_[2], const double
   d_varargin_1_CameraParameters1_[2], const double
   e_varargin_1_CameraParameters1_[2], const char
   f_varargin_1_CameraParameters1_[11], double g_varargin_1_CameraParameters1_,
   const double h_varargin_1_CameraParameters1_[114], const double
   i_varargin_1_CameraParameters1_[114], const double
   j_varargin_1_CameraParameters1_[9], const struct1_T
   *varargin_1_CameraParameters2, const double varargin_1_RotationOfCamera2[9],
   const double varargin_1_TranslationOfCamera2[3], const struct3_T
   *varargin_1_RectificationParams, d_vision_internal_calibration_C *iobj_0,
   d_vision_internal_calibration_C *iobj_1);
extern void c_StereoParametersImpl_computeR(c_vision_internal_calibration_S
  *b_this, const double imageSize[2], projective2d *Hleft, projective2d *Hright,
  double Q[16], double xBounds[2], double yBounds[2], boolean_T *success);
extern void d_StereoParametersImpl_computeR(c_vision_internal_calibration_S
  *b_this, const double imageSize[2], projective2d *Hleft, projective2d *Hright,
  double Q[16], double xBounds[2], double yBounds[2], boolean_T *success);

#endif

//
// File trailer for StereoParametersImpl.h
//
// [EOF]
//
