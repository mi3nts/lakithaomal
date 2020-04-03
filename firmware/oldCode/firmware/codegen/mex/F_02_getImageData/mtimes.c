/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "blas.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo ro_emlrtRSI = { 232,/* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

static emlrtRTEInfo nj_emlrtRTEI = { 211,/* lineNo */
  5,                                   /* colNo */
  "mtimes",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pName */
};

static emlrtRTEInfo oj_emlrtRTEI = { 232,/* lineNo */
  13,                                  /* colNo */
  "mtimes",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pName */
};

/* Function Definitions */
void b_mtimes(const emlrtStack *sp, const emxArray_real32_T *A, const real32_T
              B[16], emxArray_real32_T *C)
{
  char_T TRANSB1;
  char_T TRANSA1;
  real32_T alpha1;
  real32_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T i;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (A->size[0] == 0) {
    C->size[0] = 0;
    C->size[1] = 4;
  } else {
    st.site = &ro_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0F;
    beta1 = 0.0F;
    m_t = (ptrdiff_t)A->size[0];
    n_t = (ptrdiff_t)4;
    k_t = (ptrdiff_t)4;
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)4;
    ldc_t = (ptrdiff_t)A->size[0];
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = 4;
    emxEnsureCapacity_real32_T(&st, C, i, &oj_emlrtRTEI);
    sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A->data[0], &lda_t,
          &B[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
  }
}

void mtimes(const emlrtStack *sp, const emxArray_real_T *A, const real_T B[9],
            emxArray_real_T *C)
{
  int32_T i;
  char_T TRANSB1;
  int32_T loop_ub;
  char_T TRANSA1;
  real_T alpha1;
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = 3;
    emxEnsureCapacity_real_T(sp, C, i, &nj_emlrtRTEI);
    loop_ub = A->size[0] * 3;
    for (i = 0; i < loop_ub; i++) {
      C->data[i] = 0.0;
    }
  } else {
    st.site = &ro_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A->size[0];
    n_t = (ptrdiff_t)3;
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)A->size[0];
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = 3;
    emxEnsureCapacity_real_T(&st, C, i, &oj_emlrtRTEI);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &A->data[0], &lda_t,
          &B[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
  }
}

/* End of code generation (mtimes.c) */
