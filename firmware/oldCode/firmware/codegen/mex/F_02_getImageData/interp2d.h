/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp2d.h
 *
 * Code generation for function 'interp2d'
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
void b_interp2d(F_02_getImageDataStackData *SD, const emlrtStack *sp, const
                emxArray_real32_T *Xin, const emxArray_real32_T *Yin,
                emxArray_uint8_T *outputImage_);
void c_interp2d(const emlrtStack *sp, const uint8_T inputImage__[921600], const
                emxArray_real32_T *Xin, const emxArray_real32_T *Yin,
                emxArray_uint8_T *outputImage_);
void interp2d(const emlrtStack *sp, const real_T inputImage__[307200], const
              emxArray_real_T *Xin, const emxArray_real_T *Yin, emxArray_real_T *
              outputImage_);

/* End of code generation (interp2d.h) */
