/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_F_02_getImageData_mex.c
 *
 * Code generation for function '_coder_F_02_getImageData_mex'
 *
 */

/* Include files */
#include "_coder_F_02_getImageData_mex.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_initialize.h"
#include "F_02_getImageData_terminate.h"
#include "_coder_F_02_getImageData_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void F_02_getImageData_mexFunction
  (F_02_getImageDataStackData *SD, int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
   const mxArray *prhs[3]);

/* Function Definitions */
void F_02_getImageData_mexFunction(F_02_getImageDataStackData *SD, int32_T nlhs,
  mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[3];
  int32_T nOutputs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        17, "F_02_getImageData");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "F_02_getImageData");
  }

  /* Call the function. */
  F_02_getImageData_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    nOutputs = 1;
  } else {
    nOutputs = nlhs;
  }

  emlrtReturnArrays(nOutputs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  F_02_getImageDataStackData *c_F_02_getImageDataStackDataGlo = NULL;
  c_F_02_getImageDataStackDataGlo = (F_02_getImageDataStackData *)emlrtMxCalloc
    (1, (size_t)1U * sizeof(F_02_getImageDataStackData));
  mexAtExit(F_02_getImageData_atexit);

  /* Module initialization. */
  F_02_getImageData_initialize();

  /* Dispatch the entry-point. */
  F_02_getImageData_mexFunction(c_F_02_getImageDataStackDataGlo, nlhs, plhs,
    nrhs, prhs);

  /* Module termination. */
  F_02_getImageData_terminate();
  emlrtMxFree(c_F_02_getImageDataStackDataGlo);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_F_02_getImageData_mex.c) */
