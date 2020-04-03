/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * F_02_getImageData_initialize.c
 *
 * Code generation for function 'F_02_getImageData_initialize'
 *
 */

/* Include files */
#include "F_02_getImageData_initialize.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "_coder_F_02_getImageData_mex.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Declarations */
static void F_02_getImageData_once(const emlrtStack *sp);

/* Function Definitions */
static void F_02_getImageData_once(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/media/teamlary/Team_Lary_1/gitGubRepos/Lakitha/stereoVisionMatlab/firmware/F_02_getImageData.m",
                  0U, 1U, 5U, 2U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "F_02_getImageData", 735, -1,
               6557);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 5989, -1, 6551);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 5475, -1, 5972);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1342, -1, 5422);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1265, -1, 1329);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 1164, -1, 1227);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1123, 1159, -1, 1232);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1235, 1260, -1, 1334);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 5429, 5465, 5982);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  st.site = NULL;
  F_02_getImageData_init(&st);
}

void F_02_getImageData_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Video_and_Image_Blockset", 2);
  emlrtLicenseCheckR2012b(&st, "Image_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    F_02_getImageData_once(&st);
  }
}

/* End of code generation (F_02_getImageData_initialize.c) */
