/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * StereoParametersImpl.c
 *
 * Code generation for function 'StereoParametersImpl'
 *
 */

/* Include files */
#include "StereoParametersImpl.h"
#include "CameraParametersImpl.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "ImageTransformer.h"
#include "det.h"
#include "dot.h"
#include "mrdivide_helper.h"
#include "mwmathutil.h"
#include "rodriguesMatrixToVector.h"
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 75,  /* lineNo */
  "StereoParametersImpl",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 76,  /* lineNo */
  "StereoParametersImpl",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 77,  /* lineNo */
  "StereoParametersImpl",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 81,  /* lineNo */
  "StereoParametersImpl/StereoParametersImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 331,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 333,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 334,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 340,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 350,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 342,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 343,/* lineNo */
  "StereoParametersImpl/fromStruct",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 465,/* lineNo */
  "validateParamStruct",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 475,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 482,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 489,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 496,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 503,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 510,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 518,/* lineNo */
  "validateRectificationParams",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 67, /* lineNo */
  "validatestring",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/lang/validatestring.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 98, /* lineNo */
  "fullValidatestring",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/lang/validatestring.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 140,/* lineNo */
  "get_match",                         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/lang/validatestring.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 63, /* lineNo */
  "strcmp",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/strcmp.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 138,/* lineNo */
  "loc_strcmp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/strcmp.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 219,/* lineNo */
  "charcmp",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/strcmp.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 220,/* lineNo */
  "charcmp",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/strcmp.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 113,/* lineNo */
  "projective2d/projective2d",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 332,/* lineNo */
  "projective2d/set.T",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 338,/* lineNo */
  "projective2d/set.T",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 440,/* lineNo */
  "validateInputs",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 444,/* lineNo */
  "validateInputs",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 450,/* lineNo */
  "validateInputs",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 359,/* lineNo */
  "StereoParametersImpl/computeHalfRotations",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 604,/* lineNo */
  "computeRowAlignmentRotation",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo xh_emlrtRSI = { 20, /* lineNo */
  "mrdivide_helper",                   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo oi_emlrtRSI = { 243,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo pi_emlrtRSI = { 250,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo qi_emlrtRSI = { 256,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ri_emlrtRSI = { 257,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo si_emlrtRSI = { 258,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ti_emlrtRSI = { 260,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ui_emlrtRSI = { 261,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo vi_emlrtRSI = { 266,/* lineNo */
  "StereoParametersImpl/computeRectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo wi_emlrtRSI = { 399,/* lineNo */
  "StereoParametersImpl/computeOutputBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo xi_emlrtRSI = { 405,/* lineNo */
  "StereoParametersImpl/computeOutputBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo yi_emlrtRSI = { 418,/* lineNo */
  "StereoParametersImpl/computeOutputBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo bj_emlrtRSI = { 986,/* lineNo */
  "CameraParametersImpl/computeUndistortBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo il_emlrtRSI = { 559,/* lineNo */
  "computeOutputBoundsValid",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo jl_emlrtRSI = { 560,/* lineNo */
  "computeOutputBoundsValid",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo kl_emlrtRSI = { 567,/* lineNo */
  "computeOutputBoundsValid",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ll_emlrtRSI = { 568,/* lineNo */
  "computeOutputBoundsValid",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ml_emlrtRSI = { 569,/* lineNo */
  "computeOutputBoundsValid",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo nl_emlrtRSI = { 570,/* lineNo */
  "computeOutputBoundsValid",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

static emlrtRSInfo ol_emlrtRSI = { 32, /* lineNo */
  "sort",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/sort.m"/* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = { 338,/* lineNo */
  13,                                  /* colNo */
  "projective2d/set.T",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 440,/* lineNo */
  1,                                   /* colNo */
  "validateInputs",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "assertSupportedString",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/assertSupportedString.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 107,/* lineNo */
  9,                                   /* colNo */
  "fullValidatestring",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/lang/validatestring.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 63,/* lineNo */
  13,                                  /* colNo */
  "RectificationParameters",           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/RectificationParameters.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 64,/* lineNo */
  13,                                  /* colNo */
  "RectificationParameters",           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/RectificationParameters.m"/* pName */
};

static emlrtRTEInfo if_emlrtRTEI = { 240,/* lineNo */
  17,                                  /* colNo */
  "StereoParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pName */
};

static const char_T cv[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
  '\x06', '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
  '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
  '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$', '%',
  '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4',
  '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
  't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

/* Function Declarations */
static void StereoParametersImpl_fromStruct(const emlrtStack *sp,
  c_vision_internal_calibration_S *this, const real_T
  c_paramStruct_CameraParameters1[2], const real_T
  d_paramStruct_CameraParameters1[2], const real_T
  e_paramStruct_CameraParameters1[2], const char_T
  f_paramStruct_CameraParameters1[11], real_T g_paramStruct_CameraParameters1,
  const real_T h_paramStruct_CameraParameters1[114], const real_T
  i_paramStruct_CameraParameters1[114], const real_T
  j_paramStruct_CameraParameters1[9], const struct1_T
  *paramStruct_CameraParameters2, const real_T paramStruct_RotationOfCamera2[9],
  const real_T c_paramStruct_TranslationOfCame[3], const struct3_T
  *paramStruct_RectificationParams, d_vision_internal_calibration_C *iobj_0,
  d_vision_internal_calibration_C *iobj_1);
static void c_StereoParametersImpl_computeN(c_vision_internal_calibration_S
  *this, real_T K_new[9]);
static void c_StereoParametersImpl_computeO(F_02_getImageDataStackData *SD,
  const emlrtStack *sp, const c_vision_internal_calibration_S *this, const
  real_T Hleft_T[9], const real_T Hright_T[9], real_T xBounds[2], real_T
  yBounds[2], boolean_T *success);
static void computeOutputBoundsValid(const emlrtStack *sp, real_T outBounds1[8],
  real_T outBounds2[8], real_T xBounds[2], real_T yBounds[2], boolean_T *isValid);
static void computeRowAlignmentRotation(const emlrtStack *sp, const real_T t[3],
  real_T RrowAlign[9]);
static void validateRectificationParams(const emlrtStack *sp, const real_T
  rectificationParams_H1[9], const real_T rectificationParams_H2[9], const
  real_T rectificationParams_Q[16], const real_T rectificationParams_XBounds[2],
  const real_T rectificationParams_YBounds[2], const real_T
  c_rectificationParams_OriginalI[2], const char_T
  rectificationParams_OutputView[5]);

/* Function Definitions */
static void StereoParametersImpl_fromStruct(const emlrtStack *sp,
  c_vision_internal_calibration_S *this, const real_T
  c_paramStruct_CameraParameters1[2], const real_T
  d_paramStruct_CameraParameters1[2], const real_T
  e_paramStruct_CameraParameters1[2], const char_T
  f_paramStruct_CameraParameters1[11], real_T g_paramStruct_CameraParameters1,
  const real_T h_paramStruct_CameraParameters1[114], const real_T
  i_paramStruct_CameraParameters1[114], const real_T
  j_paramStruct_CameraParameters1[9], const struct1_T
  *paramStruct_CameraParameters2, const real_T paramStruct_RotationOfCamera2[9],
  const real_T c_paramStruct_TranslationOfCame[3], const struct3_T
  *paramStruct_RectificationParams, d_vision_internal_calibration_C *iobj_0,
  d_vision_internal_calibration_C *iobj_1)
{
  d_vision_internal_calibration_C *camParams1;
  d_vision_internal_calibration_C *camParams2;
  int32_T k;
  boolean_T p;
  char_T a[11];
  boolean_T exitg1;
  char_T b[11];
  int32_T kstr;
  int32_T exitg2;
  int32_T i;
  real_T x1;
  real_T self_T[9];
  real_T b_self_T[9];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (paramStruct_RectificationParams->Initialized) {
    b_st.site = &qb_emlrtRSI;
    validateRectificationParams(&b_st, paramStruct_RectificationParams->H1,
      paramStruct_RectificationParams->H2, paramStruct_RectificationParams->Q,
      paramStruct_RectificationParams->XBounds,
      paramStruct_RectificationParams->YBounds,
      paramStruct_RectificationParams->OriginalImageSize,
      paramStruct_RectificationParams->OutputView);
  }

  st.site = &kb_emlrtRSI;
  camParams1 = c_CameraParametersImpl_CameraPa(&st, iobj_0,
    c_paramStruct_CameraParameters1, d_paramStruct_CameraParameters1,
    e_paramStruct_CameraParameters1, f_paramStruct_CameraParameters1,
    g_paramStruct_CameraParameters1, h_paramStruct_CameraParameters1,
    i_paramStruct_CameraParameters1, j_paramStruct_CameraParameters1);
  st.site = &lb_emlrtRSI;
  camParams2 = c_CameraParametersImpl_CameraPa(&st, iobj_1,
    paramStruct_CameraParameters2->RadialDistortion,
    paramStruct_CameraParameters2->TangentialDistortion,
    paramStruct_CameraParameters2->ImageSize,
    paramStruct_CameraParameters2->WorldUnits,
    paramStruct_CameraParameters2->NumRadialDistortionCoefficients,
    paramStruct_CameraParameters2->RotationVectors,
    paramStruct_CameraParameters2->TranslationVectors,
    paramStruct_CameraParameters2->IntrinsicMatrix);
  if (paramStruct_RectificationParams->Initialized) {
    st.site = &ob_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if ((!muDoubleScalarIsInf(paramStruct_RectificationParams->H1[k])) &&
          (!muDoubleScalarIsNaN(paramStruct_RectificationParams->H1[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
    }

    d_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!muDoubleScalarIsNaN(paramStruct_RectificationParams->H1[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
    }

    c_st.site = &gd_emlrtRSI;
    x1 = det(&c_st, paramStruct_RectificationParams->H1);
    p = (x1 == 0.0);
    if (p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
        "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
    }

    memcpy(&self_T[0], &paramStruct_RectificationParams->H1[0], 9U * sizeof
           (real_T));
    st.site = &pb_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    d_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if ((!muDoubleScalarIsInf(paramStruct_RectificationParams->H2[k])) &&
          (!muDoubleScalarIsNaN(paramStruct_RectificationParams->H2[k]))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
    }

    d_st.site = &yb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!muDoubleScalarIsNaN(paramStruct_RectificationParams->H2[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
    }

    c_st.site = &gd_emlrtRSI;
    x1 = det(&c_st, paramStruct_RectificationParams->H2);
    p = (x1 == 0.0);
    if (p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
        "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
    }

    memcpy(&b_self_T[0], &paramStruct_RectificationParams->H2[0], 9U * sizeof
           (real_T));
    st.site = &mb_emlrtRSI;
    this->RectificationParams.Initialized = true;
    this->RectificationParams.OriginalImageSize[0] =
      paramStruct_RectificationParams->OriginalImageSize[0];
    this->RectificationParams.OriginalImageSize[1] =
      paramStruct_RectificationParams->OriginalImageSize[1];
    for (k = 0; k < 9; k++) {
      this->RectificationParams.H1.T[k] = self_T[k];
    }

    for (k = 0; k < 9; k++) {
      this->RectificationParams.H2.T[k] = b_self_T[k];
    }

    for (k = 0; k < 16; k++) {
      this->RectificationParams.Q[k] = paramStruct_RectificationParams->Q[k];
    }

    k = this->RectificationParams.OutputView->size[0] *
      this->RectificationParams.OutputView->size[1];
    this->RectificationParams.OutputView->size[0] = 1;
    this->RectificationParams.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(&st, this->RectificationParams.OutputView, k,
      &ad_emlrtRTEI);
    for (k = 0; k < 5; k++) {
      this->RectificationParams.OutputView->data[k] =
        paramStruct_RectificationParams->OutputView[k];
    }

    this->RectificationParams.XBounds[0] =
      paramStruct_RectificationParams->XBounds[0];
    this->RectificationParams.XBounds[1] =
      paramStruct_RectificationParams->XBounds[1];
    this->RectificationParams.YBounds[0] =
      paramStruct_RectificationParams->YBounds[0];
    this->RectificationParams.YBounds[1] =
      paramStruct_RectificationParams->YBounds[1];
  }

  st.site = &nb_emlrtRSI;
  b_st.site = &jd_emlrtRSI;
  for (k = 0; k < 11; k++) {
    a[k] = camParams1->WorldUnits[k];
  }

  for (k = 0; k < 11; k++) {
    b[k] = camParams2->WorldUnits[k];
  }

  c_st.site = &dc_emlrtRSI;
  d_st.site = &ec_emlrtRSI;
  p = false;
  kstr = 0;
  do {
    exitg2 = 0;
    if (kstr < 11) {
      e_st.site = &fc_emlrtRSI;
      k = (uint8_T)a[kstr];
      if (k > 127) {
        emlrtErrorWithMessageIdR2018a(&e_st, &g_emlrtRTEI,
          "Coder:toolbox:unsupportedString", "Coder:toolbox:unsupportedString",
          2, 12, 127);
      }

      e_st.site = &gc_emlrtRSI;
      i = (uint8_T)b[kstr];
      if (i > 127) {
        emlrtErrorWithMessageIdR2018a(&e_st, &g_emlrtRTEI,
          "Coder:toolbox:unsupportedString", "Coder:toolbox:unsupportedString",
          2, 12, 127);
      }

      if (cv[k] != cv[i]) {
        exitg2 = 1;
      } else {
        kstr++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
      "vision:calibrate:sameWorldUnits", "vision:calibrate:sameWorldUnits", 0);
  }

  b_st.site = &kd_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(paramStruct_RotationOfCamera2[k])) &&
        (!muDoubleScalarIsNaN(paramStruct_RotationOfCamera2[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 17, "rotationOfCamera2");
  }

  b_st.site = &ld_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(c_paramStruct_TranslationOfCame[k])) &&
        (!muDoubleScalarIsNaN(c_paramStruct_TranslationOfCame[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 20, "translationOfCamera2");
  }

  this->CameraParameters1 = camParams1;
  this->CameraParameters2 = camParams2;
  for (k = 0; k < 9; k++) {
    this->RotationOfCamera2[k] = paramStruct_RotationOfCamera2[k];
  }

  this->TranslationOfCamera2[0] = c_paramStruct_TranslationOfCame[0];
  this->TranslationOfCamera2[1] = c_paramStruct_TranslationOfCame[1];
  this->TranslationOfCamera2[2] = c_paramStruct_TranslationOfCame[2];
}

static void c_StereoParametersImpl_computeN(c_vision_internal_calibration_S
  *this, real_T K_new[9])
{
  d_vision_internal_calibration_C *b_this;
  int32_T i;
  real_T intrinsicMatrix[9];
  real_T Kl[9];
  real_T Kr[9];
  real_T f_new;
  b_this = this->CameraParameters1;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = b_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 3; i++) {
    Kl[3 * i] = intrinsicMatrix[i];
    Kl[3 * i + 1] = intrinsicMatrix[i + 3];
    Kl[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  b_this = this->CameraParameters2;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = b_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = b_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = b_this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 3; i++) {
    Kr[3 * i] = intrinsicMatrix[i];
    Kr[3 * i + 1] = intrinsicMatrix[i + 3];
    Kr[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  memcpy(&K_new[0], &Kl[0], 9U * sizeof(real_T));
  if ((Kr[0] > Kl[0]) || (muDoubleScalarIsNaN(Kr[0]) && (!muDoubleScalarIsNaN
        (Kl[0])))) {
    f_new = Kl[0];
  } else {
    f_new = Kr[0];
  }

  K_new[0] = f_new;
  K_new[4] = f_new;
  K_new[7] = (Kr[7] + Kl[7]) / 2.0;
  K_new[3] = 0.0;
}

static void c_StereoParametersImpl_computeO(F_02_getImageDataStackData *SD,
  const emlrtStack *sp, const c_vision_internal_calibration_S *this, const
  real_T Hleft_T[9], const real_T Hright_T[9], real_T xBounds[2], real_T
  yBounds[2], boolean_T *success)
{
  real_T minXY[2];
  real_T maxXY[2];
  real_T xBoundsUndistort2[2];
  real_T yBoundsUndistort2[2];
  real_T b_minXY[12];
  int32_T i;
  int32_T jtilecol;
  real_T d;
  real_T X[12];
  int32_T i1;
  real_T d1;
  real_T d2;
  real_T b_X[12];
  real_T d3;
  real_T d4;
  int32_T i2;
  int32_T i3;
  real_T d5;
  boolean_T p;
  real_T d6;
  real_T d7;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wi_emlrtRSI;
  c_CameraParametersImpl_computeU(SD, &st, this->CameraParameters1, minXY, maxXY);
  st.site = &xi_emlrtRSI;
  c_CameraParametersImpl_computeU(SD, &st, this->CameraParameters2,
    xBoundsUndistort2, yBoundsUndistort2);
  b_minXY[0] = minXY[0];
  b_minXY[4] = maxXY[0];
  b_minXY[1] = minXY[1];
  b_minXY[5] = maxXY[0];
  b_minXY[2] = minXY[1];
  b_minXY[6] = maxXY[1];
  b_minXY[3] = minXY[0];
  b_minXY[7] = maxXY[1];
  for (i = 0; i < 4; i++) {
    b_minXY[i + 8] = 1.0;
    d = b_minXY[i + 4];
    for (i1 = 0; i1 < 3; i1++) {
      X[i + (i1 << 2)] = (b_minXY[i] * Hleft_T[3 * i1] + d * Hleft_T[3 * i1 + 1])
        + Hleft_T[3 * i1 + 2];
    }
  }

  for (jtilecol = 0; jtilecol < 2; jtilecol++) {
    d = X[9];
    d1 = X[10];
    d2 = X[11];
    i = jtilecol << 2;
    X[i] /= X[8];
    i1 = i + 1;
    X[i1] /= d;
    i1 = i + 2;
    X[i1] /= d1;
    i += 3;
    X[i] /= d2;
  }

  b_minXY[0] = xBoundsUndistort2[0];
  b_minXY[4] = yBoundsUndistort2[0];
  b_minXY[1] = xBoundsUndistort2[1];
  b_minXY[5] = yBoundsUndistort2[0];
  b_minXY[2] = xBoundsUndistort2[1];
  b_minXY[6] = yBoundsUndistort2[1];
  b_minXY[3] = xBoundsUndistort2[0];
  b_minXY[7] = yBoundsUndistort2[1];
  for (i = 0; i < 4; i++) {
    b_minXY[i + 8] = 1.0;
    d = b_minXY[i + 4];
    for (i1 = 0; i1 < 3; i1++) {
      b_X[i + (i1 << 2)] = (b_minXY[i] * Hright_T[3 * i1] + d * Hright_T[3 * i1
                            + 1]) + Hright_T[3 * i1 + 2];
    }
  }

  for (jtilecol = 0; jtilecol < 2; jtilecol++) {
    d = b_X[9];
    d1 = b_X[10];
    d2 = b_X[11];
    i = jtilecol << 2;
    d3 = b_X[i] / b_X[8];
    d4 = d3;
    b_X[i] = d3;
    i1 = i + 1;
    d3 = b_X[i1] / d;
    d = d3;
    b_X[i1] = d3;
    i2 = i + 2;
    d3 = b_X[i2] / d1;
    d1 = d3;
    b_X[i2] = d3;
    i3 = i + 3;
    d3 = b_X[i3] / d2;
    b_X[i3] = d3;
    d2 = X[i];
    d5 = X[i];
    p = ((!muDoubleScalarIsNaN(X[i1])) && (muDoubleScalarIsNaN(X[i]) || (X[i] >
           X[i1])));
    if (p) {
      d2 = X[i1];
    }

    p = ((!muDoubleScalarIsNaN(X[i1])) && (muDoubleScalarIsNaN(X[i]) || (X[i] <
           X[i1])));
    if (p) {
      d5 = X[i1];
    }

    p = ((!muDoubleScalarIsNaN(X[i2])) && (muDoubleScalarIsNaN(d2) || (d2 > X[i2])));
    if (p) {
      d2 = X[i2];
    }

    p = ((!muDoubleScalarIsNaN(X[i2])) && (muDoubleScalarIsNaN(d5) || (d5 < X[i2])));
    if (p) {
      d5 = X[i2];
    }

    p = ((!muDoubleScalarIsNaN(X[i3])) && (muDoubleScalarIsNaN(d2) || (d2 > X[i3])));
    if (p) {
      d2 = X[i3];
    }

    p = ((!muDoubleScalarIsNaN(X[i3])) && (muDoubleScalarIsNaN(d5) || (d5 < X[i3])));
    if (p) {
      d5 = X[i3];
    }

    d6 = d2;
    d7 = d5;
    d2 = d4;
    d5 = d4;
    p = ((!muDoubleScalarIsNaN(d)) && (muDoubleScalarIsNaN(d4) || (d4 > d)));
    if (p) {
      d2 = d;
    }

    p = ((!muDoubleScalarIsNaN(d)) && (muDoubleScalarIsNaN(d4) || (d4 < d)));
    if (p) {
      d5 = d;
    }

    p = ((!muDoubleScalarIsNaN(d1)) && (muDoubleScalarIsNaN(d2) || (d2 > d1)));
    if (p) {
      d2 = d1;
    }

    p = ((!muDoubleScalarIsNaN(d1)) && (muDoubleScalarIsNaN(d5) || (d5 < d1)));
    if (p) {
      d5 = d1;
    }

    p = ((!muDoubleScalarIsNaN(d3)) && (muDoubleScalarIsNaN(d2) || (d2 > d3)));
    if (p) {
      d2 = d3;
    }

    p = ((!muDoubleScalarIsNaN(d3)) && (muDoubleScalarIsNaN(d5) || (d5 < d3)));
    if (p) {
      d5 = d3;
    }

    p = ((!muDoubleScalarIsNaN(d2)) && (muDoubleScalarIsNaN(d6) || (d6 > d2)));
    if (p) {
      d6 = d2;
    }

    d6 = muDoubleScalarRound(d6);
    minXY[jtilecol] = d6;
    p = ((!muDoubleScalarIsNaN(d5)) && (muDoubleScalarIsNaN(d7) || (d7 < d5)));
    if (p) {
      d7 = d5;
    }

    d7 = muDoubleScalarRound(d7);
    maxXY[jtilecol] = d7;
  }

  xBounds[0] = minXY[0];
  xBounds[1] = maxXY[0];
  yBounds[0] = minXY[1];
  yBounds[1] = maxXY[1];
  if ((minXY[0] >= maxXY[0]) || (minXY[1] >= maxXY[1])) {
    *success = false;
  } else {
    *success = true;
  }
}

static void computeOutputBoundsValid(const emlrtStack *sp, real_T outBounds1[8],
  real_T outBounds2[8], real_T xBounds[2], real_T yBounds[2], boolean_T *isValid)
{
  int32_T idx;
  int32_T outPts_tmp;
  real_T xSort[8];
  real_T outPts[16];
  int32_T b_outPts_tmp;
  int32_T c_outPts_tmp;
  real_T ySort[8];
  boolean_T b;
  boolean_T exitg1;
  real_T xmin1;
  real_T d;
  real_T xmax1;
  real_T xmin2;
  real_T xmax2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (idx = 0; idx < 2; idx++) {
    outPts_tmp = idx << 2;
    b_outPts_tmp = idx << 3;
    outPts[b_outPts_tmp] = outBounds1[outPts_tmp];
    outPts[b_outPts_tmp + 4] = outBounds2[outPts_tmp];
    c_outPts_tmp = outPts_tmp + 1;
    outPts[b_outPts_tmp + 1] = outBounds1[c_outPts_tmp];
    outPts[b_outPts_tmp + 5] = outBounds2[c_outPts_tmp];
    c_outPts_tmp = outPts_tmp + 2;
    outPts[b_outPts_tmp + 2] = outBounds1[c_outPts_tmp];
    outPts[b_outPts_tmp + 6] = outBounds2[c_outPts_tmp];
    outPts_tmp += 3;
    outPts[b_outPts_tmp + 3] = outBounds1[outPts_tmp];
    outPts[b_outPts_tmp + 7] = outBounds2[outPts_tmp];
  }

  st.site = &il_emlrtRSI;
  memcpy(&xSort[0], &outPts[0], 8U * sizeof(real_T));
  b_st.site = &ol_emlrtRSI;
  b_sort(&b_st, xSort);
  st.site = &jl_emlrtRSI;
  memcpy(&ySort[0], &outPts[8], 8U * sizeof(real_T));
  b_st.site = &ol_emlrtRSI;
  b_sort(&b_st, ySort);
  xBounds[0] = 0.0;
  yBounds[0] = 0.0;
  xBounds[1] = 0.0;
  yBounds[1] = 0.0;
  for (outPts_tmp = 0; outPts_tmp < 8; outPts_tmp++) {
    outBounds1[outPts_tmp] = muDoubleScalarRound(outBounds1[outPts_tmp]);
    outBounds2[outPts_tmp] = muDoubleScalarRound(outBounds2[outPts_tmp]);
  }

  st.site = &kl_emlrtRSI;
  b = muDoubleScalarIsNaN(outBounds1[0]);
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!muDoubleScalarIsNaN(outBounds1[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmin1 = outBounds1[0];
  } else {
    xmin1 = outBounds1[idx - 1];
    idx++;
    for (outPts_tmp = idx; outPts_tmp < 5; outPts_tmp++) {
      d = outBounds1[outPts_tmp - 1];
      if (xmin1 > d) {
        xmin1 = d;
      }
    }
  }

  st.site = &ll_emlrtRSI;
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!muDoubleScalarIsNaN(outBounds1[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmax1 = outBounds1[0];
  } else {
    xmax1 = outBounds1[idx - 1];
    idx++;
    for (outPts_tmp = idx; outPts_tmp < 5; outPts_tmp++) {
      d = outBounds1[outPts_tmp - 1];
      if (xmax1 < d) {
        xmax1 = d;
      }
    }
  }

  st.site = &ml_emlrtRSI;
  b = muDoubleScalarIsNaN(outBounds2[0]);
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!muDoubleScalarIsNaN(outBounds2[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmin2 = outBounds2[0];
  } else {
    xmin2 = outBounds2[idx - 1];
    idx++;
    for (outPts_tmp = idx; outPts_tmp < 5; outPts_tmp++) {
      d = outBounds2[outPts_tmp - 1];
      if (xmin2 > d) {
        xmin2 = d;
      }
    }
  }

  st.site = &nl_emlrtRSI;
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!muDoubleScalarIsNaN(outBounds2[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmax2 = outBounds2[0];
  } else {
    xmax2 = outBounds2[idx - 1];
    idx++;
    for (outPts_tmp = idx; outPts_tmp < 5; outPts_tmp++) {
      d = outBounds2[outPts_tmp - 1];
      if (xmax2 < d) {
        xmax2 = d;
      }
    }
  }

  if ((xmin1 >= xmax2) || (xmax1 <= xmin2)) {
    *isValid = false;
  } else {
    xBounds[0] = muDoubleScalarRound(xSort[3]);
    xBounds[1] = muDoubleScalarRound(xSort[4]);
    yBounds[0] = muDoubleScalarRound(ySort[3]);
    yBounds[1] = muDoubleScalarRound(ySort[4]);
    *isValid = !(xBounds[1] - xBounds[0] < 0.4 * muDoubleScalarMin(xmax1 - xmin1,
      xmax2 - xmin2));
  }
}

static void computeRowAlignmentRotation(const emlrtStack *sp, const real_T t[3],
  real_T RrowAlign[9])
{
  real_T xUnitVector[3];
  static const real_T b_xUnitVector[3] = { 1.0, 0.0, 0.0 };

  real_T rotationAxis[3];
  real_T scale;
  real_T b_t;
  real_T angle;
  real_T absxk;
  real_T x;
  real_T y;
  int32_T b_absxk;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  xUnitVector[0] = 1.0;
  xUnitVector[1] = 0.0;
  xUnitVector[2] = 0.0;
  if (dot(b_xUnitVector, t) < 0.0) {
    xUnitVector[0] = -1.0;
    xUnitVector[1] = 0.0;
    xUnitVector[2] = 0.0;
  }

  rotationAxis[0] = t[1] * 0.0 - t[2] * 0.0;
  rotationAxis[1] = t[2] * xUnitVector[0] - t[0] * 0.0;
  rotationAxis[2] = t[0] * 0.0 - t[1] * xUnitVector[0];
  scale = 3.3121686421112381E-170;
  b_t = rotationAxis[0] / 3.3121686421112381E-170;
  angle = b_t * b_t;
  absxk = muDoubleScalarAbs(rotationAxis[1]);
  if (absxk > 3.3121686421112381E-170) {
    b_t = 3.3121686421112381E-170 / absxk;
    angle = angle * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / 3.3121686421112381E-170;
    angle += b_t * b_t;
  }

  absxk = muDoubleScalarAbs(rotationAxis[2]);
  if (absxk > scale) {
    b_t = scale / absxk;
    angle = angle * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    angle += b_t * b_t;
  }

  angle = scale * muDoubleScalarSqrt(angle);
  if (angle == 0.0) {
    memset(&RrowAlign[0], 0, 9U * sizeof(real_T));
    RrowAlign[0] = 1.0;
    RrowAlign[4] = 1.0;
    RrowAlign[8] = 1.0;
  } else {
    rotationAxis[0] /= angle;
    rotationAxis[1] /= angle;
    rotationAxis[2] /= angle;
    x = dot(t, xUnitVector);
    st.site = &ih_emlrtRSI;
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(t[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      y = b_t * b_t;
    }

    absxk = muDoubleScalarAbs(t[1]);
    if (absxk > scale) {
      b_t = scale / absxk;
      y = y * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      y += b_t * b_t;
    }

    absxk = muDoubleScalarAbs(t[2]);
    if (absxk > scale) {
      b_t = scale / absxk;
      y = y * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      y += b_t * b_t;
    }

    y = scale * muDoubleScalarSqrt(y);
    scale = 3.3121686421112381E-170;
    b_absxk = (int32_T)muDoubleScalarAbs(xUnitVector[0]);
    if (b_absxk > 3.3121686421112381E-170) {
      angle = 1.0;
      scale = 1.0;
    } else {
      b_t = (real_T)b_absxk / 3.3121686421112381E-170;
      angle = b_t * b_t;
    }

    angle = scale * muDoubleScalarSqrt(angle);
    angle = muDoubleScalarAbs(x) / (y * angle);
    if (angle > 1.0) {
      emlrtErrorWithMessageIdR2018a(&st, &bb_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "acos");
    }

    angle = muDoubleScalarAcos(angle);
    rotationAxis[0] *= angle;
    rotationAxis[1] *= angle;
    rotationAxis[2] *= angle;
    rodriguesVectorToMatrix(rotationAxis, RrowAlign);
  }
}

static void validateRectificationParams(const emlrtStack *sp, const real_T
  rectificationParams_H1[9], const real_T rectificationParams_H2[9], const
  real_T rectificationParams_Q[16], const real_T rectificationParams_XBounds[2],
  const real_T rectificationParams_YBounds[2], const real_T
  c_rectificationParams_OriginalI[2], const char_T
  rectificationParams_OutputView[5])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  int32_T exitg2;
  int32_T i;
  int8_T partial_match_size_idx_1;
  char_T b_cv[10];
  static const char_T b_cv1[5] = { 'v', 'a', 'l', 'i', 'd' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(rectificationParams_H1[k])) &&
        (!muDoubleScalarIsNaN(rectificationParams_H1[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 34,
      "paramStruct.RectificationParams.H1");
  }

  st.site = &sb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(rectificationParams_H2[k])) &&
        (!muDoubleScalarIsNaN(rectificationParams_H2[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 34,
      "paramStruct.RectificationParams.H2");
  }

  st.site = &tb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16)) {
    if ((!muDoubleScalarIsInf(rectificationParams_Q[k])) &&
        (!muDoubleScalarIsNaN(rectificationParams_Q[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 33,
      "paramStruct.RectificationParams.Q");
  }

  st.site = &ub_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(rectificationParams_XBounds[k])) &&
        (!muDoubleScalarIsNaN(rectificationParams_XBounds[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 39,
      "paramStruct.RectificationParams.XBounds");
  }

  st.site = &vb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(rectificationParams_YBounds[k])) &&
        (!muDoubleScalarIsNaN(rectificationParams_YBounds[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 39,
      "paramStruct.RectificationParams.YBounds");
  }

  st.site = &wb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(c_rectificationParams_OriginalI[k])) &&
        (!muDoubleScalarIsNaN(c_rectificationParams_OriginalI[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:stereoParameters:expectedFinite", 3, 4, 49,
      "paramStruct.RectificationParams.OriginalImageSize");
  }

  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(c_rectificationParams_OriginalI[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedPositive",
      "MATLAB:stereoParameters:expectedPositive", 3, 4, 49,
      "paramStruct.RectificationParams.OriginalImageSize");
  }

  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(c_rectificationParams_OriginalI[k])) &&
        (!muDoubleScalarIsNaN(c_rectificationParams_OriginalI[k])) &&
        (muDoubleScalarFloor(c_rectificationParams_OriginalI[k]) ==
         c_rectificationParams_OriginalI[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedInteger",
      "MATLAB:stereoParameters:expectedInteger", 3, 4, 49,
      "paramStruct.RectificationParams.OriginalImageSize");
  }

  st.site = &xb_emlrtRSI;
  b_st.site = &ac_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
  d_st.site = &cc_emlrtRSI;
  e_st.site = &dc_emlrtRSI;
  f_st.site = &ec_emlrtRSI;
  p = false;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 5) {
      g_st.site = &fc_emlrtRSI;
      i = (uint8_T)rectificationParams_OutputView[k];
      if (i > 127) {
        emlrtErrorWithMessageIdR2018a(&g_st, &g_emlrtRTEI,
          "Coder:toolbox:unsupportedString", "Coder:toolbox:unsupportedString",
          2, 12, 127);
      }

      if (cv[i] != cv[(int32_T)b_cv1[k]]) {
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (p) {
    k = 1;
    partial_match_size_idx_1 = 5;
  } else {
    k = 0;
    partial_match_size_idx_1 = 0;
  }

  if ((k == 0) || (partial_match_size_idx_1 == 0)) {
    b_cv[0] = ',';
    b_cv[1] = ' ';
    b_cv[2] = '\'';
    for (i = 0; i < 5; i++) {
      b_cv[i + 3] = rectificationParams_OutputView[i];
    }

    b_cv[8] = '\'';
    b_cv[9] = ',';
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
      "Coder:toolbox:ValidatestringUnrecognizedStringChoice",
      "MATLAB:stereoParameters:unrecognizedStringChoice", 9, 4, 42,
      "paramStruct.RectificationParams.OutputView", 4, 15, "\'full\', \'valid\'",
      4, 10, b_cv);
  }
}

c_vision_internal_calibration_S *c_StereoParametersImpl_StereoPa(const
  emlrtStack *sp, c_vision_internal_calibration_S *this, const real_T
  c_varargin_1_CameraParameters1_[2], const real_T
  d_varargin_1_CameraParameters1_[2], const real_T
  e_varargin_1_CameraParameters1_[2], const char_T
  f_varargin_1_CameraParameters1_[11], real_T g_varargin_1_CameraParameters1_,
  const real_T h_varargin_1_CameraParameters1_[114], const real_T
  i_varargin_1_CameraParameters1_[114], const real_T
  j_varargin_1_CameraParameters1_[9], const struct1_T
  *varargin_1_CameraParameters2, const real_T varargin_1_RotationOfCamera2[9],
  const real_T varargin_1_TranslationOfCamera2[3], const struct3_T
  *varargin_1_RectificationParams, d_vision_internal_calibration_C *iobj_0,
  d_vision_internal_calibration_C *iobj_1)
{
  c_vision_internal_calibration_S *b_this;
  int32_T i;
  static const int8_T iv[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  static const char_T b_cv[5] = { 'v', 'a', 'l', 'i', 'd' };

  static const int8_T T[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_this = this;
  st.site = &p_emlrtRSI;
  for (i = 0; i < 16; i++) {
    b_this->RectificationParams.Q[i] = iv[i];
  }

  b_this->RectificationParams.XBounds[0] = 0.0;
  b_this->RectificationParams.XBounds[1] = 0.0;
  b_this->RectificationParams.YBounds[0] = 0.0;
  b_this->RectificationParams.YBounds[1] = 0.0;
  b_this->RectificationParams.Initialized = false;
  b_this->RectificationParams.OriginalImageSize[0] = 0.0;
  b_this->RectificationParams.OriginalImageSize[1] = 0.0;
  i = b_this->RectificationParams.OutputView->size[0] *
    b_this->RectificationParams.OutputView->size[1];
  b_this->RectificationParams.OutputView->size[0] = 1;
  b_this->RectificationParams.OutputView->size[1] = 4;
  emxEnsureCapacity_char_T(&st, b_this->RectificationParams.OutputView, i,
    &xc_emlrtRTEI);
  b_this->RectificationParams.OutputView->data[0] = 'f';
  b_this->RectificationParams.OutputView->data[1] = 'u';
  b_this->RectificationParams.OutputView->data[2] = 'l';
  b_this->RectificationParams.OutputView->data[3] = 'l';
  i = b_this->RectificationParams.OutputView->size[0] *
    b_this->RectificationParams.OutputView->size[1];
  b_this->RectificationParams.OutputView->size[0] = 1;
  b_this->RectificationParams.OutputView->size[1] = 5;
  emxEnsureCapacity_char_T(&st, b_this->RectificationParams.OutputView, i,
    &yc_emlrtRTEI);
  for (i = 0; i < 5; i++) {
    b_this->RectificationParams.OutputView->data[i] = b_cv[i];
  }

  for (i = 0; i < 9; i++) {
    b_this->RectificationParams.H1.T[i] = T[i];
  }

  for (i = 0; i < 9; i++) {
    b_this->RectificationParams.H2.T[i] = T[i];
  }

  st.site = &q_emlrtRSI;
  c_ImageTransformer_ImageTransfo(&st, &b_this->RectifyMap1);
  st.site = &r_emlrtRSI;
  c_ImageTransformer_ImageTransfo(&st, &b_this->RectifyMap2);
  st.site = &s_emlrtRSI;
  StereoParametersImpl_fromStruct(&st, b_this, c_varargin_1_CameraParameters1_,
    d_varargin_1_CameraParameters1_, e_varargin_1_CameraParameters1_,
    f_varargin_1_CameraParameters1_, g_varargin_1_CameraParameters1_,
    h_varargin_1_CameraParameters1_, i_varargin_1_CameraParameters1_,
    j_varargin_1_CameraParameters1_, varargin_1_CameraParameters2,
    varargin_1_RotationOfCamera2, varargin_1_TranslationOfCamera2,
    varargin_1_RectificationParams, iobj_0, iobj_1);
  return b_this;
}

void c_StereoParametersImpl_computeR(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, c_vision_internal_calibration_S *this, projective2d *Hleft,
  projective2d *Hright, real_T Q[16], real_T xBounds[2], real_T yBounds[2],
  boolean_T *success)
{
  int32_T i;
  real_T b_this[9];
  real_T r[3];
  real_T At[9];
  real_T t[3];
  real_T RrowAlign[9];
  d_vision_internal_calibration_C *c_this;
  real_T intrinsicMatrix[9];
  real_T b_intrinsicMatrix[9];
  real_T K_new[9];
  real_T x1;
  real_T d;
  int32_T i1;
  real_T b_K_new[9];
  real_T Y[9];
  real_T A[9];
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emxArray_uint8_T *undistortedMask;
  real_T xBoundsBig[2];
  real_T yBoundsBig[2];
  real_T b_xBounds[2];
  real_T b_yBounds[2];
  real_T c_xBounds[12];
  real_T X[12];
  real_T d1;
  real_T b_X[12];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &oi_emlrtRSI;
  for (i = 0; i < 3; i++) {
    b_this[3 * i] = this->RotationOfCamera2[i];
    b_this[3 * i + 1] = this->RotationOfCamera2[i + 3];
    b_this[3 * i + 2] = this->RotationOfCamera2[i + 6];
  }

  b_st.site = &gf_emlrtRSI;
  rodriguesMatrixToVector(&b_st, b_this, r);
  r[0] /= -2.0;
  r[1] /= -2.0;
  r[2] /= -2.0;
  rodriguesVectorToMatrix(r, At);
  r[0] = this->TranslationOfCamera2[0];
  r[1] = this->TranslationOfCamera2[1];
  r[2] = this->TranslationOfCamera2[2];
  for (i = 0; i < 3; i++) {
    t[i] = (At[i] * r[0] + At[i + 3] * r[1]) + At[i + 6] * r[2];
  }

  st.site = &pi_emlrtRSI;
  computeRowAlignmentRotation(&st, t, RrowAlign);
  st.site = &qi_emlrtRSI;
  c_this = this->CameraParameters1;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = c_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = c_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = c_this->IntrinsicMatrixInternal[i + 6];
  }

  st.site = &ri_emlrtRSI;
  c_this = this->CameraParameters2;
  for (i = 0; i < 3; i++) {
    b_intrinsicMatrix[3 * i] = c_this->IntrinsicMatrixInternal[i];
    b_intrinsicMatrix[3 * i + 1] = c_this->IntrinsicMatrixInternal[i + 3];
    b_intrinsicMatrix[3 * i + 2] = c_this->IntrinsicMatrixInternal[i + 6];
  }

  st.site = &si_emlrtRSI;
  c_StereoParametersImpl_computeN(this, K_new);
  st.site = &ti_emlrtRSI;
  for (i = 0; i < 3; i++) {
    x1 = RrowAlign[i + 3];
    d = RrowAlign[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_this[i + 3 * i1] = (RrowAlign[i] * At[i1] + x1 * At[i1 + 3]) + d * At[i1
        + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    x1 = K_new[i + 3];
    d = K_new[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_K_new[i + 3 * i1] = (K_new[i] * b_this[3 * i1] + x1 * b_this[3 * i1 + 1])
        + d * b_this[3 * i1 + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    b_this[3 * i] = intrinsicMatrix[i];
    b_this[3 * i + 1] = intrinsicMatrix[i + 3];
    b_this[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  b_st.site = &xh_emlrtRSI;
  mrdiv(&b_st, b_K_new, b_this, Y);
  st.site = &ti_emlrtRSI;
  for (i = 0; i < 3; i++) {
    A[3 * i] = Y[i];
    A[3 * i + 1] = Y[i + 3];
    A[3 * i + 2] = Y[i + 6];
  }

  b_st.site = &ed_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(A[k])) && (!muDoubleScalarIsNaN(A[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }

  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!muDoubleScalarIsNaN(A[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }

  c_st.site = &gd_emlrtRSI;
  x1 = det(&c_st, A);
  p = (x1 == 0.0);
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
      "images:geotrans:singularTransformationMatrix",
      "images:geotrans:singularTransformationMatrix", 0);
  }

  memcpy(&Hleft->T[0], &A[0], 9U * sizeof(real_T));
  st.site = &ui_emlrtRSI;
  for (i = 0; i < 3; i++) {
    x1 = RrowAlign[i + 3];
    d = RrowAlign[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      b_this[i + 3 * i1] = (RrowAlign[i] * At[3 * i1] + x1 * At[3 * i1 + 1]) + d
        * At[3 * i1 + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    x1 = K_new[i + 3];
    d = K_new[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      k = i + 3 * i1;
      b_K_new[k] = (K_new[i] * b_this[3 * i1] + x1 * b_this[3 * i1 + 1]) + d *
        b_this[3 * i1 + 2];
      intrinsicMatrix[i1 + 3 * i] = b_intrinsicMatrix[k];
    }
  }

  b_st.site = &xh_emlrtRSI;
  mrdiv(&b_st, b_K_new, intrinsicMatrix, Y);
  st.site = &ui_emlrtRSI;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = Y[i];
    intrinsicMatrix[3 * i + 1] = Y[i + 3];
    intrinsicMatrix[3 * i + 2] = Y[i + 6];
  }

  b_st.site = &ed_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(intrinsicMatrix[k])) && (!muDoubleScalarIsNaN
         (intrinsicMatrix[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }

  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!muDoubleScalarIsNaN(intrinsicMatrix[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }

  c_st.site = &gd_emlrtRSI;
  x1 = det(&c_st, intrinsicMatrix);
  p = (x1 == 0.0);
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
      "images:geotrans:singularTransformationMatrix",
      "images:geotrans:singularTransformationMatrix", 0);
  }

  memcpy(&Hright->T[0], &intrinsicMatrix[0], 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    r[i] = (RrowAlign[i] * t[0] + RrowAlign[i + 3] * t[1]) + RrowAlign[i + 6] *
      t[2];
  }

  emxInit_uint8_T(sp, &undistortedMask, 2, &if_emlrtRTEI, true);
  st.site = &vi_emlrtRSI;
  b_st.site = &wi_emlrtRSI;
  c_this = this->CameraParameters1;
  c_st.site = &aj_emlrtRSI;
  c_CameraParametersImpl_createUn(SD, &c_st, c_this, undistortedMask, xBoundsBig,
    yBoundsBig);
  c_st.site = &bj_emlrtRSI;
  c_CameraParametersImpl_getValid(&c_st, c_this, undistortedMask, xBoundsBig,
    yBoundsBig, xBounds, yBounds);
  b_st.site = &xi_emlrtRSI;
  c_this = this->CameraParameters2;
  c_st.site = &aj_emlrtRSI;
  c_CameraParametersImpl_createUn(SD, &c_st, c_this, undistortedMask, xBoundsBig,
    yBoundsBig);
  c_st.site = &bj_emlrtRSI;
  c_CameraParametersImpl_getValid(&c_st, c_this, undistortedMask, xBoundsBig,
    yBoundsBig, b_xBounds, b_yBounds);
  c_xBounds[0] = xBounds[0];
  c_xBounds[4] = yBounds[0];
  c_xBounds[1] = xBounds[1];
  c_xBounds[5] = yBounds[0];
  c_xBounds[2] = xBounds[1];
  c_xBounds[6] = yBounds[1];
  c_xBounds[3] = xBounds[0];
  c_xBounds[7] = yBounds[1];
  emxFree_uint8_T(&undistortedMask);
  for (i = 0; i < 4; i++) {
    c_xBounds[i + 8] = 1.0;
    x1 = c_xBounds[i + 4];
    for (i1 = 0; i1 < 3; i1++) {
      X[i + (i1 << 2)] = (c_xBounds[i] * A[3 * i1] + x1 * A[3 * i1 + 1]) + A[3 *
        i1 + 2];
    }
  }

  for (k = 0; k < 2; k++) {
    x1 = X[9];
    d = X[10];
    d1 = X[11];
    i = k << 2;
    X[i] /= X[8];
    i1 = i + 1;
    X[i1] /= x1;
    i1 = i + 2;
    X[i1] /= d;
    i += 3;
    X[i] /= d1;
  }

  c_xBounds[0] = b_xBounds[0];
  c_xBounds[4] = b_yBounds[0];
  c_xBounds[1] = b_xBounds[1];
  c_xBounds[5] = b_yBounds[0];
  c_xBounds[2] = b_xBounds[1];
  c_xBounds[6] = b_yBounds[1];
  c_xBounds[3] = b_xBounds[0];
  c_xBounds[7] = b_yBounds[1];
  for (i = 0; i < 4; i++) {
    c_xBounds[i + 8] = 1.0;
    x1 = c_xBounds[i + 4];
    for (i1 = 0; i1 < 3; i1++) {
      b_X[i + (i1 << 2)] = (c_xBounds[i] * intrinsicMatrix[3 * i1] + x1 *
                            intrinsicMatrix[3 * i1 + 1]) + intrinsicMatrix[3 *
        i1 + 2];
    }
  }

  for (k = 0; k < 2; k++) {
    x1 = b_X[9];
    d = b_X[10];
    d1 = b_X[11];
    i = k << 2;
    b_X[i] /= b_X[8];
    i1 = i + 1;
    b_X[i1] /= x1;
    i1 = i + 2;
    b_X[i1] /= d;
    i += 3;
    b_X[i] /= d1;
  }

  b_st.site = &yi_emlrtRSI;
  computeOutputBoundsValid(&b_st, *(real_T (*)[8])&X[0], *(real_T (*)[8])&b_X[0],
    xBounds, yBounds, success);
  Q[0] = 1.0;
  Q[1] = 0.0;
  Q[2] = 0.0;
  Q[3] = -(K_new[6] - xBounds[0]);
  Q[4] = 0.0;
  Q[5] = 1.0;
  Q[6] = 0.0;
  Q[7] = -(K_new[7] - yBounds[0]);
  Q[8] = 0.0;
  Q[9] = 0.0;
  Q[10] = 0.0;
  Q[11] = K_new[4];
  Q[12] = 0.0;
  Q[13] = 0.0;
  Q[14] = -1.0 / r[0];
  Q[15] = 0.0;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void d_StereoParametersImpl_computeR(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, c_vision_internal_calibration_S *this, projective2d *Hleft,
  projective2d *Hright, real_T Q[16], real_T xBounds[2], real_T yBounds[2],
  boolean_T *success)
{
  int32_T k;
  real_T b_this[9];
  real_T r[3];
  real_T At[9];
  real_T t[3];
  real_T RrowAlign[9];
  d_vision_internal_calibration_C *c_this;
  real_T intrinsicMatrix[9];
  real_T b_intrinsicMatrix[9];
  real_T K_new[9];
  real_T x1;
  real_T d;
  int32_T i;
  real_T b_K_new[9];
  boolean_T p;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  for (k = 0; k < 3; k++) {
    b_this[3 * k] = this->RotationOfCamera2[k];
    b_this[3 * k + 1] = this->RotationOfCamera2[k + 3];
    b_this[3 * k + 2] = this->RotationOfCamera2[k + 6];
  }

  b_st.site = &gf_emlrtRSI;
  rodriguesMatrixToVector(&b_st, b_this, r);
  r[0] /= -2.0;
  r[1] /= -2.0;
  r[2] /= -2.0;
  rodriguesVectorToMatrix(r, At);
  r[0] = this->TranslationOfCamera2[0];
  r[1] = this->TranslationOfCamera2[1];
  r[2] = this->TranslationOfCamera2[2];
  for (k = 0; k < 3; k++) {
    t[k] = (At[k] * r[0] + At[k + 3] * r[1]) + At[k + 6] * r[2];
  }

  st.site = &pi_emlrtRSI;
  computeRowAlignmentRotation(&st, t, RrowAlign);
  st.site = &qi_emlrtRSI;
  c_this = this->CameraParameters1;
  for (k = 0; k < 3; k++) {
    intrinsicMatrix[3 * k] = c_this->IntrinsicMatrixInternal[k];
    intrinsicMatrix[3 * k + 1] = c_this->IntrinsicMatrixInternal[k + 3];
    intrinsicMatrix[3 * k + 2] = c_this->IntrinsicMatrixInternal[k + 6];
  }

  st.site = &ri_emlrtRSI;
  c_this = this->CameraParameters2;
  for (k = 0; k < 3; k++) {
    b_intrinsicMatrix[3 * k] = c_this->IntrinsicMatrixInternal[k];
    b_intrinsicMatrix[3 * k + 1] = c_this->IntrinsicMatrixInternal[k + 3];
    b_intrinsicMatrix[3 * k + 2] = c_this->IntrinsicMatrixInternal[k + 6];
  }

  st.site = &si_emlrtRSI;
  c_StereoParametersImpl_computeN(this, K_new);
  st.site = &ti_emlrtRSI;
  for (k = 0; k < 3; k++) {
    x1 = RrowAlign[k + 3];
    d = RrowAlign[k + 6];
    for (i = 0; i < 3; i++) {
      b_this[k + 3 * i] = (RrowAlign[k] * At[i] + x1 * At[i + 3]) + d * At[i + 6];
    }
  }

  for (k = 0; k < 3; k++) {
    x1 = K_new[k + 3];
    d = K_new[k + 6];
    for (i = 0; i < 3; i++) {
      b_K_new[k + 3 * i] = (K_new[k] * b_this[3 * i] + x1 * b_this[3 * i + 1]) +
        d * b_this[3 * i + 2];
    }
  }

  for (k = 0; k < 3; k++) {
    b_this[3 * k] = intrinsicMatrix[k];
    b_this[3 * k + 1] = intrinsicMatrix[k + 3];
    b_this[3 * k + 2] = intrinsicMatrix[k + 6];
  }

  b_st.site = &xh_emlrtRSI;
  mrdiv(&b_st, b_K_new, b_this, intrinsicMatrix);
  st.site = &ti_emlrtRSI;
  for (k = 0; k < 3; k++) {
    b_this[3 * k] = intrinsicMatrix[k];
    b_this[3 * k + 1] = intrinsicMatrix[k + 3];
    b_this[3 * k + 2] = intrinsicMatrix[k + 6];
  }

  b_st.site = &ed_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(b_this[k])) && (!muDoubleScalarIsNaN(b_this[k])))
    {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }

  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!muDoubleScalarIsNaN(b_this[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }

  c_st.site = &gd_emlrtRSI;
  x1 = det(&c_st, b_this);
  p = (x1 == 0.0);
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
      "images:geotrans:singularTransformationMatrix",
      "images:geotrans:singularTransformationMatrix", 0);
  }

  memcpy(&Hleft->T[0], &b_this[0], 9U * sizeof(real_T));
  st.site = &ui_emlrtRSI;
  for (k = 0; k < 3; k++) {
    x1 = RrowAlign[k + 3];
    d = RrowAlign[k + 6];
    for (i = 0; i < 3; i++) {
      b_this[k + 3 * i] = (RrowAlign[k] * At[3 * i] + x1 * At[3 * i + 1]) + d *
        At[3 * i + 2];
    }
  }

  for (k = 0; k < 3; k++) {
    x1 = K_new[k + 3];
    d = K_new[k + 6];
    for (i = 0; i < 3; i++) {
      b_K_new[k + 3 * i] = (K_new[k] * b_this[3 * i] + x1 * b_this[3 * i + 1]) +
        d * b_this[3 * i + 2];
    }
  }

  for (k = 0; k < 3; k++) {
    b_this[3 * k] = b_intrinsicMatrix[k];
    b_this[3 * k + 1] = b_intrinsicMatrix[k + 3];
    b_this[3 * k + 2] = b_intrinsicMatrix[k + 6];
  }

  b_st.site = &xh_emlrtRSI;
  mrdiv(&b_st, b_K_new, b_this, intrinsicMatrix);
  st.site = &ui_emlrtRSI;
  for (k = 0; k < 3; k++) {
    b_this[3 * k] = intrinsicMatrix[k];
    b_this[3 * k + 1] = intrinsicMatrix[k + 3];
    b_this[3 * k + 2] = intrinsicMatrix[k + 6];
  }

  b_st.site = &ed_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(b_this[k])) && (!muDoubleScalarIsNaN(b_this[k])))
    {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }

  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if (!muDoubleScalarIsNaN(b_this[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }

  c_st.site = &gd_emlrtRSI;
  x1 = det(&c_st, b_this);
  p = (x1 == 0.0);
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
      "images:geotrans:singularTransformationMatrix",
      "images:geotrans:singularTransformationMatrix", 0);
  }

  memcpy(&Hright->T[0], &b_this[0], 9U * sizeof(real_T));
  for (k = 0; k < 3; k++) {
    r[k] = (RrowAlign[k] * t[0] + RrowAlign[k + 3] * t[1]) + RrowAlign[k + 6] *
      t[2];
  }

  st.site = &vi_emlrtRSI;
  c_StereoParametersImpl_computeO(SD, &st, this, Hleft->T, Hright->T, xBounds,
    yBounds, success);
  Q[0] = 1.0;
  Q[1] = 0.0;
  Q[2] = 0.0;
  Q[3] = -(K_new[6] - xBounds[0]);
  Q[4] = 0.0;
  Q[5] = 1.0;
  Q[6] = 0.0;
  Q[7] = -(K_new[7] - yBounds[0]);
  Q[8] = 0.0;
  Q[9] = 0.0;
  Q[10] = 0.0;
  Q[11] = K_new[4];
  Q[12] = 0.0;
  Q[13] = 0.0;
  Q[14] = -1.0 / r[0];
  Q[15] = 0.0;
}

/* End of code generation (StereoParametersImpl.c) */
