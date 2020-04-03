/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sprintf.c
 *
 * Code generation for function 'sprintf'
 *
 */

/* Include files */
#include "sprintf.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "F_02_getImageData_mexutil.h"
#include "rt_nonfinite.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo lp_emlrtRSI = { 28, /* lineNo */
  "sprintf",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m"/* pathName */
};

static emlrtMCInfo f_emlrtMCI = { 52,  /* lineNo */
  14,                                  /* colNo */
  "nonConstPrint",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m"/* pName */
};

static emlrtMCInfo g_emlrtMCI = { 54,  /* lineNo */
  15,                                  /* colNo */
  "nonConstPrint",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m"/* pName */
};

static emlrtDCInfo k_emlrtDCI = { 56,  /* lineNo */
  53,                                  /* colNo */
  "nonConstPrint",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRSInfo br_emlrtRSI = { 52, /* lineNo */
  "nonConstPrint",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m"/* pathName */
};

static emlrtRSInfo cr_emlrtRSI = { 54, /* lineNo */
  "nonConstPrint",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m"/* pathName */
};

static emlrtRSInfo er_emlrtRSI = { 57, /* lineNo */
  "nonConstPrint",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/sprintf.m"/* pathName */
};

/* Function Declarations */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_length_, const char_T *identifier);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmpStr,
  const char_T *identifier, emxArray_char_T *y);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret);
static const mxArray *length(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location);

/* Function Definitions */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_length_, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(a__output_of_length_), &thisId);
  emlrtDestroyArray(&a__output_of_length_);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmpStr,
  const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(tmpStr), &thisId, y);
  emlrtDestroyArray(&tmpStr);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_char_T *y)
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_char_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims, &bv[0], iv);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 1, false);
  emlrtDestroyArray(&src);
}

static const mxArray *length(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
  *location)
{
  const mxArray *pArray;
  const mxArray *m;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m, 1, &pArray, "length", true, location);
}

void b_sprintf(const emlrtStack *sp, int32_T varargin_1, emxArray_char_T *str)
{
  const mxArray *tmpStr;
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 7 };

  static const char_T u[7] = { 's', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 1, 2 };

  static const char_T formatSpec[2] = { '%', 'd' };

  const mxArray *c_y;
  const mxArray *m2;
  real_T strSize;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lp_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tmpStr = NULL;
  y = NULL;
  m = emlrtCreateCharArray(2, iv);
  emlrtInitCharArrayR2013a(&st, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(&st, 2, m1, &formatSpec[0]);
  emlrtAssign(&b_y, m1);
  c_y = NULL;
  m2 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m2) = varargin_1;
  emlrtAssign(&c_y, m2);
  b_st.site = &br_emlrtRSI;
  emlrtAssign(&tmpStr, d_feval(&b_st, y, b_y, c_y, &f_emlrtMCI));
  b_st.site = &cr_emlrtRSI;
  strSize = c_emlrt_marshallIn(&b_st, length(&b_st, emlrtAlias(tmpStr),
    &g_emlrtMCI), "<output of length>");
  if (!(strSize >= 0.0)) {
    emlrtNonNegativeCheckR2012b(strSize, &k_emlrtDCI, &st);
  }

  b_st.site = &er_emlrtRSI;
  e_emlrt_marshallIn(&b_st, emlrtAlias(tmpStr), "tmpStr", str);
  emlrtDestroyArray(&tmpStr);
}

/* End of code generation (sprintf.c) */
