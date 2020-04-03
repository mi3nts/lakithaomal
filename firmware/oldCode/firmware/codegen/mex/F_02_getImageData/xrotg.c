/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xrotg.c
 *
 * Code generation for function 'xrotg'
 *
 */

/* Include files */
#include "xrotg.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "blas.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  *c = 0.0;
  *s = 0.0;
  drotg(a, b, c, s);
}

/* End of code generation (xrotg.c) */
