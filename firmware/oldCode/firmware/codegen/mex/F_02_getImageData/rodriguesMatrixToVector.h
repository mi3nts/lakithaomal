/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rodriguesMatrixToVector.h
 *
 * Code generation for function 'rodriguesMatrixToVector'
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
void rodriguesMatrixToVector(const emlrtStack *sp, real_T rotationMatrix[9],
  real_T rotationVector[3]);

/* End of code generation (rodriguesMatrixToVector.h) */
