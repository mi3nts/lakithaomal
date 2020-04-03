/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void b_mtimes(const emlrtStack *sp, const emxArray_real32_T *A, const real32_T
              B[16], emxArray_real32_T *C);
void mtimes(const emlrtStack *sp, const emxArray_real_T *A, const real_T B[9],
            emxArray_real_T *C);

/* End of code generation (mtimes.h) */
