/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.h
 *
 * Code generation for function 'mrdivide_helper'
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
void mrdiv(const emlrtStack *sp, const real_T A[9], const real_T B[9], real_T Y
           [9]);

/* End of code generation (mrdivide_helper.h) */
