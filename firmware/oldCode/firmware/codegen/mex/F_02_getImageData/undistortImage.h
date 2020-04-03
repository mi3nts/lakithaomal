/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * undistortImage.h
 *
 * Code generation for function 'undistortImage'
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
void undistortImage(const emlrtStack *sp, const real_T b_I[307200],
                    c_vision_internal_calibration_C *intrinsics, real_T J[307200]);

/* End of code generation (undistortImage.h) */
