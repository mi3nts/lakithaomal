/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * reconstructScene.h
 *
 * Code generation for function 'reconstructScene'
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
void reconstructScene(const emlrtStack *sp, const emxArray_real32_T
                      *disparityMap, const c_vision_internal_calibration_S
                      *stereoParams, emxArray_real32_T *xyzPoints);

/* End of code generation (reconstructScene.h) */
