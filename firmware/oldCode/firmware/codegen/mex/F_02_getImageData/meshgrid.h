/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * meshgrid.h
 *
 * Code generation for function 'meshgrid'
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
void b_meshgrid(const real_T x[640], const real_T y[480], real_T xx[307200],
                real_T yy[307200]);
void c_meshgrid(const emlrtStack *sp, const emxArray_real32_T *x, const
                emxArray_real32_T *y, emxArray_real32_T *xx, emxArray_real32_T
                *yy);
void meshgrid(const emlrtStack *sp, const emxArray_real_T *x, const
              emxArray_real_T *y, emxArray_real_T *xx, emxArray_real_T *yy);

/* End of code generation (meshgrid.h) */
