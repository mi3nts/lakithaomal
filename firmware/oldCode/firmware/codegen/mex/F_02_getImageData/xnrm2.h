/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xnrm2.h
 *
 * Code generation for function 'xnrm2'
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
real_T b_xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0);
real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0);

/* End of code generation (xnrm2.h) */
