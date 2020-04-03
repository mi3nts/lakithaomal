/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * F_02_getImageData.h
 *
 * Code generation for function 'F_02_getImageData'
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
void F_02_getImageData(F_02_getImageDataStackData *SD, const emlrtStack *sp,
  const struct0_T *stereoParamsStruct, const struct4_T *thermalParamsStruct,
  const projective2d transformParametors[26], emxArray_uint8_T *frameLeftRect,
  emxArray_real_T *finalCelciusImage, emxArray_real32_T *distanceImage);
void F_02_getImageData_free(void);
void F_02_getImageData_init(const emlrtStack *sp);

/* End of code generation (F_02_getImageData.h) */
