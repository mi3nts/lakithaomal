/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * validateattributes.h
 *
 * Code generation for function 'validateattributes'
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
void b_validateattributes(const emlrtStack *sp, const emxArray_real32_T *a);
void c_validateattributes(const emlrtStack *sp, const real_T a[3]);
void validateattributes(const emlrtStack *sp, const emxArray_real32_T *a);

/* End of code generation (validateattributes.h) */
