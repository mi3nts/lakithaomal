/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imwarp.h
 *
 * Code generation for function 'imwarp'
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
void imwarp(const emlrtStack *sp, const real_T varargin_1[307200], const real_T
            varargin_2_T[9], const real_T varargin_4_ImageSizeAlias[2],
            emxArray_real_T *outputImage);

/* End of code generation (imwarp.h) */
