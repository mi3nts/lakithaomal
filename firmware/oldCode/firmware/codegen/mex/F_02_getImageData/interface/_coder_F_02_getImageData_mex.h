/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_F_02_getImageData_mex.h
 *
 * Code generation for function '_coder_F_02_getImageData_mex'
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
MEXFUNCTION_LINKAGE void F_02_getImageData_mexFunction
  (F_02_getImageDataStackData *SD, int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
   const mxArray *prhs[3]);
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
  const mxArray *prhs[]);
emlrtCTX mexFunctionCreateRootTLS(void);

/* End of code generation (_coder_F_02_getImageData_mex.h) */
