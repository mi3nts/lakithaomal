/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imref2d.h
 *
 * Code generation for function 'imref2d'
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
void imref2d_set_XWorldLimits(const emlrtStack *sp,
  images_internal_coder_imref2d *obj, const real_T xLimWorld[2]);
void imref2d_set_YWorldLimits(const emlrtStack *sp,
  images_internal_coder_imref2d *obj, const real_T yLimWorld[2]);

/* End of code generation (imref2d.h) */
