/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xscal.h
 *
 * Code generation for function 'xscal'
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
void b_xscal(const emlrtStack *sp, real_T a, real_T x[3], int32_T ix0);
void c_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0);
void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0);

/* End of code generation (xscal.h) */
