/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * padarray.c
 *
 * Code generation for function 'padarray'
 *
 */

/* Include files */
#include "padarray.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo vk_emlrtRSI = { 66, /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo wk_emlrtRSI = { 72, /* lineNo */
  "padarray",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo yk_emlrtRSI = { 405,/* lineNo */
  "ConstantPad",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo al_emlrtRSI = { 420,/* lineNo */
  "ConstantPad",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  400,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  414,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  407,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  444,                                 /* lineNo */
  100,                                 /* colNo */
  "",                                  /* aName */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  444,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  421,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 251, /* lineNo */
  35,                                  /* colNo */
  "ConstantPad",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo bi_emlrtRTEI = { 66,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = { 72,/* lineNo */
  13,                                  /* colNo */
  "padarray",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/padarray.m"/* pName */
};

/* Function Definitions */
void padarray(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
              emxArray_boolean_T *b)
{
  uint32_T sizeB_idx_0;
  uint32_T sizeB_idx_1;
  real_T b_varargin_1[2];
  int32_T i;
  int32_T a;
  int32_T b_i;
  int32_T i1;
  int32_T b_b;
  boolean_T overflow;
  int32_T j;
  int32_T i2;
  int32_T i3;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    sizeB_idx_0 = varargin_1->size[0] + 2U;
    sizeB_idx_1 = varargin_1->size[1] + 2U;
    st.site = &vk_emlrtRSI;
    b_varargin_1[0] = sizeB_idx_0;
    b_varargin_1[1] = sizeB_idx_1;
    b_st.site = &xk_emlrtRSI;
    assertValidSizeArg(&b_st, b_varargin_1);
    i = b->size[0] * b->size[1];
    b->size[0] = (int32_T)sizeB_idx_0;
    b->size[1] = (int32_T)sizeB_idx_1;
    emxEnsureCapacity_boolean_T(&st, b, i, &bi_emlrtRTEI);
    a = (int32_T)sizeB_idx_0 * (int32_T)sizeB_idx_1;
    for (i = 0; i < a; i++) {
      b->data[i] = false;
    }
  } else {
    st.site = &wk_emlrtRSI;
    if ((real_T)varargin_1->size[0] + 2.0 != (int32_T)((real_T)varargin_1->size
         [0] + 2.0)) {
      emlrtIntegerCheckR2012b((real_T)varargin_1->size[0] + 2.0, &f_emlrtDCI,
        &st);
    }

    sizeB_idx_0 = (uint32_T)((real_T)varargin_1->size[0] + 2.0);
    if ((real_T)varargin_1->size[1] + 2.0 != (int32_T)((real_T)varargin_1->size
         [1] + 2.0)) {
      emlrtIntegerCheckR2012b((real_T)varargin_1->size[1] + 2.0, &f_emlrtDCI,
        &st);
    }

    i = b->size[0] * b->size[1];
    b->size[0] = (int32_T)sizeB_idx_0;
    b->size[1] = (int32_T)(uint32_T)((real_T)varargin_1->size[1] + 2.0);
    emxEnsureCapacity_boolean_T(&st, b, i, &ci_emlrtRTEI);
    i = (int32_T)sizeB_idx_0;
    for (b_i = 0; b_i < i; b_i++) {
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > b->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b->size[0], &bb_emlrtBCI, &st);
      }

      b->data[i1 - 1] = false;
    }

    a = varargin_1->size[1] + 2;
    b_b = b->size[1];
    b_st.site = &yk_emlrtRSI;
    overflow = ((varargin_1->size[1] + 2 <= b->size[1]) && (b->size[1] >
      2147483646));
    if (overflow) {
      c_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (j = a; j <= b_b; j++) {
      i = b->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        i1 = b_i + 1;
        if ((i1 < 1) || (i1 > b->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b->size[0], &db_emlrtBCI, &st);
        }

        if ((j < 1) || (j > b->size[1])) {
          emlrtDynamicBoundsCheckR2012b(j, 1, b->size[1], &db_emlrtBCI, &st);
        }

        b->data[(i1 + b->size[0] * (j - 1)) - 1] = false;
      }
    }

    i = varargin_1->size[1];
    for (j = 0; j < i; j++) {
      i1 = j + 2;
      if ((i1 < 1) || (i1 > b->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b->size[1], &cb_emlrtBCI, &st);
      }

      b->data[b->size[0] * (i1 - 1)] = false;
    }

    i = varargin_1->size[1];
    for (j = 0; j < i; j++) {
      a = varargin_1->size[0] + 2;
      b_b = b->size[0];
      b_st.site = &al_emlrtRSI;
      overflow = ((varargin_1->size[0] + 2 <= b->size[0]) && (b->size[0] >
        2147483646));
      if (overflow) {
        c_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (b_i = a; b_i <= b_b; b_i++) {
        if ((b_i < 1) || (b_i > b->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, b->size[0], &gb_emlrtBCI, &st);
        }

        i1 = j + 2;
        if ((i1 < 1) || (i1 > b->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b->size[1], &gb_emlrtBCI, &st);
        }

        b->data[(b_i + b->size[0] * (i1 - 1)) - 1] = false;
      }
    }

    i = varargin_1->size[1];
    for (j = 0; j < i; j++) {
      i1 = varargin_1->size[0];
      for (b_i = 0; b_i < i1; b_i++) {
        a = b_i + 1;
        if ((a < 1) || (a > varargin_1->size[0])) {
          emlrtDynamicBoundsCheckR2012b(a, 1, varargin_1->size[0], &eb_emlrtBCI,
            &st);
        }

        b_b = j + 1;
        if ((b_b < 1) || (b_b > varargin_1->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_b, 1, varargin_1->size[1],
            &eb_emlrtBCI, &st);
        }

        i2 = b_i + 2;
        if ((i2 < 1) || (i2 > b->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, b->size[0], &fb_emlrtBCI, &st);
        }

        i3 = j + 2;
        if ((i3 < 1) || (i3 > b->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, b->size[1], &fb_emlrtBCI, &st);
        }

        b->data[(i2 + b->size[0] * (i3 - 1)) - 1] = varargin_1->data[(a +
          varargin_1->size[0] * (b_b - 1)) - 1];
      }
    }
  }
}

/* End of code generation (padarray.c) */
