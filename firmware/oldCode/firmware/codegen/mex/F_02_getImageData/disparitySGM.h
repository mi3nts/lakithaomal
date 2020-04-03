/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * disparitySGM.h
 *
 * Code generation for function 'disparitySGM'
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
void disparitySGM(const emlrtStack *sp, const emxArray_uint8_T *I1, const
                  emxArray_uint8_T *I2, emxArray_real32_T *disparityMap);

/* End of code generation (disparitySGM.h) */
