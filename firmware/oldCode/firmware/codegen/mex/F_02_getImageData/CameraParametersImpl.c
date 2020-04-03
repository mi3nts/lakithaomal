/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CameraParametersImpl.c
 *
 * Code generation for function 'CameraParametersImpl'
 *
 */

/* Include files */
#include "CameraParametersImpl.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "ImageTransformer.h"
#include "abs.h"
#include "bwtraceboundary.h"
#include "ceil.h"
#include "colon.h"
#include "distortPoints.h"
#include "eml_int_forloop_overflow_check.h"
#include "floor.h"
#include "interp2d.h"
#include "meshgrid.h"
#include "mwmathutil.h"
#include "regionprops.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sub2ind.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = { 6,   /* lineNo */
  "HandleCodegen/HandleCodegen",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+enforcescalar/HandleCodegen.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 6,   /* lineNo */
  "HandleBase/HandleBase",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+enforcescalar/HandleBase.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 43, /* lineNo */
  "ImageTransformer/ImageTransformer", /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 198,/* lineNo */
  "CameraParametersImpl/CameraParametersImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 251,/* lineNo */
  "CameraParametersImpl/CameraParametersImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 271,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 315,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 321,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 326,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 329,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 331,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 336,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 341,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 361,/* lineNo */
  "CameraParametersImpl/parseInputsCodegen",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 753,/* lineNo */
  "CameraParametersImpl/checkIntrinsicMatrix",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 761,/* lineNo */
  "CameraParametersImpl/checkRadialDistortion",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 771,/* lineNo */
  "CameraParametersImpl/checkTangentialDistortion",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 389,/* lineNo */
  "CameraParametersImpl/set.ImageSize",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 781,/* lineNo */
  "CameraParametersImpl/checkImageSize",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 791,/* lineNo */
  "CameraParametersImpl/checkRotationVectors",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 801,/* lineNo */
  "CameraParametersImpl/checkTranslationVectors",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 836,/* lineNo */
  "CameraParametersImpl/checkNumRadialCoeffs",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 43, /* lineNo */
  "unaryOrBinaryDispatch",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 131,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 932,/* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 992,/* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo th_emlrtRSI = { 155,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo uh_emlrtRSI = { 1015,/* lineNo */
  "minRealVectorOmitNaN",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo vh_emlrtRSI = { 924,/* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo wh_emlrtRSI = { 975,/* lineNo */
  "findFirst",                         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo cj_emlrtRSI = { 1012,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo dj_emlrtRSI = { 1027,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ej_emlrtRSI = { 1047,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo fj_emlrtRSI = { 1048,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo gj_emlrtRSI = { 1049,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo hj_emlrtRSI = { 1050,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ij_emlrtRSI = { 1058,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo jj_emlrtRSI = { 1057,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo kj_emlrtRSI = { 1062,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo lj_emlrtRSI = { 1063,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo mj_emlrtRSI = { 1064,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo nj_emlrtRSI = { 1065,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo oj_emlrtRSI = { 1069,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo pj_emlrtRSI = { 1091,/* lineNo */
  "CameraParametersImpl",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo qj_emlrtRSI = { 1092,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo rj_emlrtRSI = { 1096,/* lineNo */
  "CameraParametersImpl/createUndistortedMask",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo sj_emlrtRSI = { 16, /* lineNo */
  "sub2ind",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pathName */
};

static emlrtRSInfo xj_emlrtRSI = { 1129,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo yj_emlrtRSI = { 1130,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ak_emlrtRSI = { 1141,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo bk_emlrtRSI = { 1146,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ck_emlrtRSI = { 1147,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo dk_emlrtRSI = { 1148,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ek_emlrtRSI = { 1149,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo fk_emlrtRSI = { 1150,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo gk_emlrtRSI = { 1151,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo hk_emlrtRSI = { 1152,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo ik_emlrtRSI = { 1153,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo jk_emlrtRSI = { 1166,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo kk_emlrtRSI = { 1167,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo lk_emlrtRSI = { 1168,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo mk_emlrtRSI = { 1169,/* lineNo */
  "CameraParametersImpl/getValidBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo bl_emlrtRSI = { 888,/* lineNo */
  "CameraParametersImpl/distortPoints",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo cl_emlrtRSI = { 887,/* lineNo */
  "CameraParametersImpl/distortPoints",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo el_emlrtRSI = { 145,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo fl_emlrtRSI = { 1019,/* lineNo */
  "maxRealVectorOmitNaN",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo cm_emlrtRSI = { 983,/* lineNo */
  "CameraParametersImpl/computeUndistortBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo dm_emlrtRSI = { 1196,/* lineNo */
  "getFullBounds",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo em_emlrtRSI = { 1202,/* lineNo */
  "getFullBounds",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo fm_emlrtRSI = { 1203,/* lineNo */
  "getFullBounds",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo gm_emlrtRSI = { 1205,/* lineNo */
  "getFullBounds",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

static emlrtRSInfo eo_emlrtRSI = { 16, /* lineNo */
  "min",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = { 22,/* lineNo */
  27,                                  /* colNo */
  "validatege",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validatege.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 22,/* lineNo */
  27,                                  /* colNo */
  "validatele",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validatele.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { -1,  /* nDims */
  1066,                                /* lineNo */
  36,                                  /* colNo */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 1050,  /* lineNo */
  42,                                  /* colNo */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 1049,/* lineNo */
  42,                                  /* colNo */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 1048,/* lineNo */
  61,                                  /* colNo */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 1047,/* lineNo */
  61,                                  /* colNo */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  1028,                                /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  1070,                                /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1068,                                /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/createUndistortedMask",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo fb_emlrtRTEI = { 1228,/* lineNo */
  9,                                   /* colNo */
  "getInitialBoundaryPixel",           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1229,                                /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "getInitialBoundaryPixel",           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo s_emlrtECI = { -1,  /* nDims */
  1137,                                /* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtECInfo t_emlrtECI = { -1,  /* nDims */
  1138,                                /* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 1162,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1156,                                /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1157,                                /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1158,                                /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  1159,                                /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "CameraParametersImpl/getValidBounds",/* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1206,                                /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "getFullBounds",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1202,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "getFullBounds",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1203,                                /* lineNo */
  10,                                  /* colNo */
  "",                                  /* aName */
  "getFullBounds",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1202,                                /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "getFullBounds",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo jf_emlrtRTEI = { 996,/* lineNo */
  17,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = { 1026,/* lineNo */
  22,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = { 1027,/* lineNo */
  42,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo mf_emlrtRTEI = { 1027,/* lineNo */
  55,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = { 1027,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo of_emlrtRTEI = { 1028,/* lineNo */
  18,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = { 99,/* lineNo */
  9,                                   /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = { 1047,/* lineNo */
  30,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo rf_emlrtRTEI = { 1048,/* lineNo */
  30,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = { 1049,/* lineNo */
  48,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = { 1050,/* lineNo */
  48,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = { 1047,/* lineNo */
  29,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = { 1063,/* lineNo */
  31,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = { 1063,/* lineNo */
  50,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = { 1064,/* lineNo */
  31,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo yf_emlrtRTEI = { 1064,/* lineNo */
  49,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = { 1062,/* lineNo */
  31,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = { 1062,/* lineNo */
  21,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = { 1066,/* lineNo */
  36,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = { 1066,/* lineNo */
  53,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = { 1067,/* lineNo */
  27,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo fg_emlrtRTEI = { 1067,/* lineNo */
  55,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = { 1068,/* lineNo */
  30,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = { 1068,/* lineNo */
  21,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ig_emlrtRTEI = { 1069,/* lineNo */
  50,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo jg_emlrtRTEI = { 1069,/* lineNo */
  63,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo kg_emlrtRTEI = { 1069,/* lineNo */
  21,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = { 1070,/* lineNo */
  26,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = { 1091,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ng_emlrtRTEI = { 1007,/* lineNo */
  17,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo og_emlrtRTEI = { 1026,/* lineNo */
  29,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo pg_emlrtRTEI = { 1068,/* lineNo */
  37,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo qg_emlrtRTEI = { 1047,/* lineNo */
  31,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = { 1048,/* lineNo */
  50,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = { 1049,/* lineNo */
  31,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = { 1050,/* lineNo */
  31,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = { 16,/* lineNo */
  14,                                  /* colNo */
  "sub2ind",                           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/sub2ind.m"/* pName */
};

static emlrtRTEInfo wg_emlrtRTEI = { 1134,/* lineNo */
  41,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo xg_emlrtRTEI = { 1134,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo yg_emlrtRTEI = { 1137,/* lineNo */
  47,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = { 1138,/* lineNo */
  47,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo bh_emlrtRTEI = { 1150,/* lineNo */
  26,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = { 1150,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo dh_emlrtRTEI = { 1151,/* lineNo */
  26,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo eh_emlrtRTEI = { 1151,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo fh_emlrtRTEI = { 1152,/* lineNo */
  27,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = { 1152,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo hh_emlrtRTEI = { 1153,/* lineNo */
  28,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ih_emlrtRTEI = { 1153,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo jh_emlrtRTEI = { 1125,/* lineNo */
  39,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo kh_emlrtRTEI = { 1130,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = { 1141,/* lineNo */
  13,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo mh_emlrtRTEI = { 1156,/* lineNo */
  51,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo nh_emlrtRTEI = { 1157,/* lineNo */
  51,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo oh_emlrtRTEI = { 1158,/* lineNo */
  52,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ph_emlrtRTEI = { 1159,/* lineNo */
  53,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo qh_emlrtRTEI = { 1150,/* lineNo */
  22,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = { 1196,/* lineNo */
  21,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = { 1200,/* lineNo */
  1,                                   /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = { 979,/* lineNo */
  18,                                  /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

static emlrtRTEInfo hi_emlrtRTEI = { 1196,/* lineNo */
  1,                                   /* colNo */
  "CameraParametersImpl",              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pName */
};

/* Function Declarations */
static void c_CameraParametersImpl_checkIma(const emlrtStack *sp, const real_T
  imageSize[2]);
static void c_CameraParametersImpl_checkInt(const emlrtStack *sp, const real_T
  IntrinsicMatrix[9]);
static void c_CameraParametersImpl_checkNum(const emlrtStack *sp, real_T
  numRadialCoeffs);
static void c_CameraParametersImpl_checkRad(const emlrtStack *sp, const real_T
  radialDistortion[2]);
static void c_CameraParametersImpl_checkTan(const emlrtStack *sp, const real_T
  tangentialDistortion[2]);
static void d_CameraParametersImpl_createUn(F_02_getImageDataStackData *SD,
  const emlrtStack *sp, const d_vision_internal_calibration_C *this,
  emxArray_uint8_T *undistortedMask, real_T xBoundsBig[2], real_T yBoundsBig[2]);
static void getInitialBoundaryPixel(const emlrtStack *sp, const emxArray_uint8_T
  *undistortedMask, real_T boundaryPixel[2]);

/* Function Definitions */
static void c_CameraParametersImpl_checkIma(const emlrtStack *sp, const real_T
  imageSize[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ad_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(imageSize[k])) && (!muDoubleScalarIsNaN
         (imageSize[k])) && (muDoubleScalarFloor(imageSize[k]) == imageSize[k]))
    {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedInteger",
      "MATLAB:CameraParametersImpl:expectedInteger", 3, 4, 9, "imageSize");
  }

  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(imageSize[k] <= 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedPositive",
      "MATLAB:CameraParametersImpl:expectedPositive", 3, 4, 9, "imageSize");
  }
}

static void c_CameraParametersImpl_checkInt(const emlrtStack *sp, const real_T
  IntrinsicMatrix[9])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    if ((!muDoubleScalarIsInf(IntrinsicMatrix[k])) && (!muDoubleScalarIsNaN
         (IntrinsicMatrix[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 15, "IntrinsicMatrix");
  }
}

static void c_CameraParametersImpl_checkNum(const emlrtStack *sp, real_T
  numRadialCoeffs)
{
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  if (muDoubleScalarIsInf(numRadialCoeffs) || muDoubleScalarIsNaN
      (numRadialCoeffs) || (!(muDoubleScalarFloor(numRadialCoeffs) ==
        numRadialCoeffs))) {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedInteger",
      "MATLAB:cameraParameters:expectedInteger", 3, 4, 31,
      "NumRadialDistortionCoefficients");
  }

  b_st.site = &yb_emlrtRSI;
  p = (numRadialCoeffs >= 2.0);
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &k_emlrtRTEI,
      "MATLAB:validateattributes:expectedScalar",
      "MATLAB:cameraParameters:notGreaterEqual", 9, 4, 31,
      "NumRadialDistortionCoefficients", 4, 2, ">=", 4, 1, "2");
  }

  b_st.site = &yb_emlrtRSI;
  p = (numRadialCoeffs <= 3.0);
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
      "MATLAB:validateattributes:expectedScalar",
      "MATLAB:cameraParameters:notLessEqual", 9, 4, 31,
      "NumRadialDistortionCoefficients", 4, 2, "<=", 4, 1, "3");
  }
}

static void c_CameraParametersImpl_checkRad(const emlrtStack *sp, const real_T
  radialDistortion[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(radialDistortion[k])) && (!muDoubleScalarIsNaN
         (radialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 16, "RadialDistortion");
  }
}

static void c_CameraParametersImpl_checkTan(const emlrtStack *sp, const real_T
  tangentialDistortion[2])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(tangentialDistortion[k])) && (!muDoubleScalarIsNaN
         (tangentialDistortion[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 20, "TangentialDistortion");
  }
}

static void d_CameraParametersImpl_createUn(F_02_getImageDataStackData *SD,
  const emlrtStack *sp, const d_vision_internal_calibration_C *this,
  emxArray_uint8_T *undistortedMask, real_T xBoundsBig[2], real_T yBoundsBig[2])
{
  c_vision_internal_calibration_I myMap;
  int32_T i;
  real_T b_dv[640];
  real_T b_dv1[480];
  real_T intrinsicMatrix[9];
  int32_T k;
  real_T allPts_tmp;
  int32_T b_i;
  emxArray_int32_T *r;
  boolean_T b;
  boolean_T b1;
  emxArray_real_T *allPts;
  emxArray_real_T *b_allPts;
  emxArray_real_T *c_allPts;
  emxArray_real_T *d_allPts;
  emxArray_real_T *indices;
  emxArray_int32_T *r1;
  real_T numUnmapped;
  real_T p1_idx_0;
  real_T p2_idx_0;
  real_T p1_idx_1;
  real_T p2_idx_1;
  int32_T numTrials;
  emxArray_real_T *newPts;
  emxArray_real_T *ptsOut;
  emxArray_real32_T *b_myMap;
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *y;
  emxArray_real_T *varargin_1;
  emxArray_real_T *b_y;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *c_y;
  emxArray_real_T *varargin_2;
  emxArray_real_T *d_y;
  emxArray_real_T *b_varargin_2;
  emxArray_real32_T *c_myMap;
  emxArray_real_T *r5;
  emxArray_real_T *c_varargin_1;
  real_T w;
  real_T h;
  int32_T lastNumUnmapped;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  d_emxInitStruct_vision_internal(sp, &myMap, &mg_emlrtRTEI, true);
  xBoundsBig[0] = 1.0;
  yBoundsBig[0] = 1.0;
  xBoundsBig[1] = 640.0;
  yBoundsBig[1] = 480.0;
  for (i = 0; i < 640; i++) {
    b_dv[i] = (real_T)i + 1.0;
  }

  for (i = 0; i < 480; i++) {
    b_dv1[i] = (real_T)i + 1.0;
  }

  b_meshgrid(b_dv, b_dv1, SD->u2.f2.b_X, SD->u2.f2.Y);
  st.site = &cj_emlrtRSI;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 307200; i++) {
    SD->u2.f2.X[i] = SD->u2.f2.b_X[i];
    SD->u2.f2.X[i + 307200] = SD->u2.f2.Y[i];
  }

  b_distortPoints(SD, SD->u2.f2.X, intrinsicMatrix, this->RadialDistortion,
                  this->TangentialDistortion, SD->u2.f2.ptsOut);
  memset(&SD->u2.f2.mask[0], 0, 307200U * sizeof(int8_T));
  for (k = 0; k < 614400; k++) {
    SD->u2.f2.X[k] = muDoubleScalarFloor(SD->u2.f2.ptsOut[k]);
  }

  for (k = 0; k < 307200; k++) {
    SD->u2.f2.b_X[k] = muDoubleScalarFloor(SD->u2.f2.ptsOut[k]);
    allPts_tmp = SD->u2.f2.ptsOut[k + 307200];
    SD->u2.f2.Y[k] = muDoubleScalarCeil(allPts_tmp);
    SD->u2.f2.b_ptsOut[k] = muDoubleScalarCeil(SD->u2.f2.ptsOut[k]);
    SD->u2.f2.x[k] = muDoubleScalarFloor(allPts_tmp);
  }

  for (k = 0; k < 614400; k++) {
    SD->u2.f2.ptsOut[k] = muDoubleScalarCeil(SD->u2.f2.ptsOut[k]);
  }

  for (i = 0; i < 2; i++) {
    memcpy(&SD->u2.f2.allPts[i * 1228800], &SD->u2.f2.X[i * 307200], 307200U *
           sizeof(real_T));
  }

  for (i = 0; i < 307200; i++) {
    SD->u2.f2.allPts[i + 307200] = SD->u2.f2.b_X[i];
    SD->u2.f2.allPts[i + 1536000] = SD->u2.f2.Y[i];
    SD->u2.f2.allPts[i + 614400] = SD->u2.f2.b_ptsOut[i];
    SD->u2.f2.allPts[i + 1843200] = SD->u2.f2.x[i];
  }

  for (i = 0; i < 2; i++) {
    memcpy(&SD->u2.f2.allPts[i * 1228800 + 921600], &SD->u2.f2.ptsOut[i * 307200],
           307200U * sizeof(real_T));
  }

  k = 0;
  for (b_i = 0; b_i < 1228800; b_i++) {
    allPts_tmp = SD->u2.f2.allPts[b_i + 1228800];
    b = ((SD->u2.f2.allPts[b_i] >= 1.0) && (allPts_tmp >= 1.0) &&
         (SD->u2.f2.allPts[b_i] <= 640.0));
    SD->u2.f2.bv[b_i] = b;
    b1 = (allPts_tmp <= 480.0);
    SD->u2.f2.bv1[b_i] = b1;
    if (b && b1) {
      k++;
    }
  }

  emxInit_int32_T(sp, &r, 1, &og_emlrtRTEI, true);
  i = r->size[0];
  r->size[0] = k;
  emxEnsureCapacity_int32_T(sp, r, i, &jf_emlrtRTEI);
  k = 0;
  for (b_i = 0; b_i < 1228800; b_i++) {
    if (SD->u2.f2.bv[b_i] && SD->u2.f2.bv1[b_i]) {
      r->data[k] = b_i + 1;
      k++;
    }
  }

  emxInit_real_T(sp, &allPts, 2, &kf_emlrtRTEI, true);
  emxInit_real_T(sp, &b_allPts, 2, &kf_emlrtRTEI, true);
  st.site = &dj_emlrtRSI;
  i = allPts->size[0] * allPts->size[1];
  allPts->size[0] = r->size[0];
  allPts->size[1] = 2;
  emxEnsureCapacity_real_T(&st, allPts, i, &kf_emlrtRTEI);
  i = b_allPts->size[0] * b_allPts->size[1];
  b_allPts->size[0] = r->size[0];
  b_allPts->size[1] = 2;
  emxEnsureCapacity_real_T(&st, b_allPts, i, &kf_emlrtRTEI);
  k = r->size[0];
  for (i = 0; i < k; i++) {
    allPts_tmp = SD->u2.f2.allPts[r->data[i] - 1];
    allPts->data[i] = allPts_tmp;
    b_allPts->data[i] = allPts_tmp;
  }

  for (i = 0; i < k; i++) {
    allPts_tmp = SD->u2.f2.allPts[r->data[i] + 1228799];
    allPts->data[i + allPts->size[0]] = allPts_tmp;
    b_allPts->data[i + b_allPts->size[0]] = allPts_tmp;
  }

  emxInit_real_T(&st, &c_allPts, 1, &lf_emlrtRTEI, true);
  k = r->size[0];
  i = c_allPts->size[0];
  c_allPts->size[0] = r->size[0];
  emxEnsureCapacity_real_T(&st, c_allPts, i, &lf_emlrtRTEI);
  for (i = 0; i < k; i++) {
    c_allPts->data[i] = allPts->data[i + allPts->size[0]];
  }

  emxFree_real_T(&allPts);
  emxInit_real_T(&st, &d_allPts, 1, &mf_emlrtRTEI, true);
  k = r->size[0];
  i = d_allPts->size[0];
  d_allPts->size[0] = r->size[0];
  emxEnsureCapacity_real_T(&st, d_allPts, i, &mf_emlrtRTEI);
  for (i = 0; i < k; i++) {
    d_allPts->data[i] = b_allPts->data[i];
  }

  emxFree_real_T(&b_allPts);
  emxInit_real_T(&st, &indices, 1, &nf_emlrtRTEI, true);
  emxInit_int32_T(&st, &r1, 1, &ug_emlrtRTEI, true);
  b_st.site = &sj_emlrtRSI;
  eml_sub2ind(&b_st, c_allPts, d_allPts, r1);
  i = indices->size[0];
  indices->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(&st, indices, i, &nf_emlrtRTEI);
  k = r1->size[0];
  emxFree_real_T(&d_allPts);
  emxFree_real_T(&c_allPts);
  for (i = 0; i < k; i++) {
    indices->data[i] = r1->data[i];
  }

  i = r->size[0];
  r->size[0] = indices->size[0];
  emxEnsureCapacity_int32_T(sp, r, i, &of_emlrtRTEI);
  k = indices->size[0];
  for (i = 0; i < k; i++) {
    b_i = (int32_T)indices->data[i];
    if ((b_i < 1) || (b_i > 307200)) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, 307200, &e_emlrtBCI, sp);
    }

    r->data[i] = b_i;
  }

  k = r->size[0];
  for (i = 0; i < k; i++) {
    SD->u2.f2.mask[r->data[i] - 1] = 1;
  }

  emxFree_int32_T(&r);
  allPts_tmp = SD->u2.f2.mask[0];
  for (k = 0; k < 307199; k++) {
    allPts_tmp += (real_T)SD->u2.f2.mask[k + 1];
  }

  numUnmapped = 307200.0 - allPts_tmp;
  if (307200.0 - allPts_tmp > 0.0) {
    p1_idx_0 = 1.0;
    p2_idx_0 = 640.0;
    p1_idx_1 = 1.0;
    p2_idx_1 = 480.0;
    numTrials = 0;
    emxInit_real_T(sp, &newPts, 2, &bg_emlrtRTEI, true);
    emxInit_real_T(sp, &ptsOut, 2, &ng_emlrtRTEI, true);
    emxInit_boolean_T(sp, &r2, 1, &jf_emlrtRTEI, true);
    emxInit_boolean_T(sp, &r3, 1, &jf_emlrtRTEI, true);
    emxInit_int32_T(sp, &r4, 1, &pg_emlrtRTEI, true);
    emxInit_real_T(sp, &y, 2, &qg_emlrtRTEI, true);
    emxInit_real_T(sp, &varargin_1, 1, &qf_emlrtRTEI, true);
    emxInit_real_T(sp, &b_y, 1, &rg_emlrtRTEI, true);
    emxInit_real_T(sp, &b_varargin_1, 1, &rf_emlrtRTEI, true);
    emxInit_real_T(sp, &c_y, 1, &sg_emlrtRTEI, true);
    emxInit_real_T(sp, &varargin_2, 1, &sf_emlrtRTEI, true);
    emxInit_real_T(sp, &d_y, 1, &tg_emlrtRTEI, true);
    emxInit_real_T(sp, &b_varargin_2, 1, &tf_emlrtRTEI, true);
    emxInit_real_T(sp, &r5, 2, &ag_emlrtRTEI, true);
    emxInit_real_T(sp, &c_varargin_1, 2, &uf_emlrtRTEI, true);
    while ((numTrials < 5) && (numUnmapped > 0.0)) {
      p1_idx_0--;
      p2_idx_0++;
      p1_idx_1--;
      p2_idx_1++;
      w = (p2_idx_0 - p1_idx_0) + 1.0;
      h = (p2_idx_1 - p1_idx_1) + 1.0;
      lastNumUnmapped = (int32_T)numUnmapped;
      st.site = &ej_emlrtRSI;
      allPts_tmp = (p1_idx_0 + w) - 1.0;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_0) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_0 == allPts_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        k = (int32_T)(allPts_tmp - p1_idx_0);
        y->size[1] = k + 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        for (i = 0; i <= k; i++) {
          y->data[i] = p1_idx_0 + (real_T)i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_0, allPts_tmp, y);
      }

      i = (int32_T)w;
      if (w != i) {
        emlrtIntegerCheckR2012b(w, &d_emlrtDCI, sp);
      }

      k = (int32_T)w;
      b_i = indices->size[0];
      indices->size[0] = (int32_T)w;
      emxEnsureCapacity_real_T(sp, indices, b_i, &pf_emlrtRTEI);
      for (b_i = 0; b_i < k; b_i++) {
        indices->data[b_i] = p1_idx_1;
      }

      st.site = &ej_emlrtRSI;
      b_i = varargin_1->size[0];
      varargin_1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, varargin_1, b_i, &qf_emlrtRTEI);
      loop_ub = y->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        varargin_1->data[b_i] = y->data[b_i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (indices->size[0] != varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      st.site = &fj_emlrtRSI;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_0) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_0 == allPts_tmp)) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = (int32_T)(allPts_tmp - p1_idx_0);
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          y->data[b_i] = p1_idx_0 + (real_T)b_i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_0, allPts_tmp, y);
      }

      if ((int32_T)w != i) {
        emlrtIntegerCheckR2012b(w, &c_emlrtDCI, sp);
      }

      i = b_y->size[0];
      b_y->size[0] = (int32_T)w;
      emxEnsureCapacity_real_T(sp, b_y, i, &pf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        b_y->data[i] = p2_idx_1;
      }

      st.site = &fj_emlrtRSI;
      i = b_varargin_1->size[0];
      b_varargin_1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, b_varargin_1, i, &rf_emlrtRTEI);
      k = y->size[1];
      for (i = 0; i < k; i++) {
        b_varargin_1->data[i] = y->data[i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (b_y->size[0] != b_varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      i = (int32_T)h;
      if (h != i) {
        emlrtIntegerCheckR2012b(h, &b_emlrtDCI, sp);
      }

      k = (int32_T)h;
      b_i = c_y->size[0];
      c_y->size[0] = (int32_T)h;
      emxEnsureCapacity_real_T(sp, c_y, b_i, &pf_emlrtRTEI);
      for (b_i = 0; b_i < k; b_i++) {
        c_y->data[b_i] = p1_idx_0;
      }

      st.site = &gj_emlrtRSI;
      allPts_tmp = (p1_idx_1 + h) - 1.0;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_1) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_1 == allPts_tmp)) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = (int32_T)(allPts_tmp - p1_idx_1);
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          y->data[b_i] = p1_idx_1 + (real_T)b_i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_1, allPts_tmp, y);
      }

      st.site = &gj_emlrtRSI;
      b_i = varargin_2->size[0];
      varargin_2->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, varargin_2, b_i, &sf_emlrtRTEI);
      loop_ub = y->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        varargin_2->data[b_i] = y->data[b_i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (varargin_2->size[0] != c_y->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if ((int32_T)h != i) {
        emlrtIntegerCheckR2012b(h, &emlrtDCI, sp);
      }

      i = d_y->size[0];
      d_y->size[0] = (int32_T)h;
      emxEnsureCapacity_real_T(sp, d_y, i, &pf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        d_y->data[i] = p2_idx_0;
      }

      st.site = &hj_emlrtRSI;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_1) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_1 == allPts_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        k = (int32_T)(allPts_tmp - p1_idx_1);
        y->size[1] = k + 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        for (i = 0; i <= k; i++) {
          y->data[i] = p1_idx_1 + (real_T)i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_1, allPts_tmp, y);
      }

      st.site = &hj_emlrtRSI;
      i = b_varargin_2->size[0];
      b_varargin_2->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, b_varargin_2, i, &tf_emlrtRTEI);
      k = y->size[1];
      for (i = 0; i < k; i++) {
        b_varargin_2->data[i] = y->data[i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (b_varargin_2->size[0] != d_y->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      st.site = &ij_emlrtRSI;
      for (i = 0; i < 3; i++) {
        intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
        intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
        intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
      }

      i = c_varargin_1->size[0] * c_varargin_1->size[1];
      c_varargin_1->size[0] = ((varargin_1->size[0] + b_varargin_1->size[0]) +
        c_y->size[0]) + d_y->size[0];
      c_varargin_1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, c_varargin_1, i, &uf_emlrtRTEI);
      k = varargin_1->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[i] = varargin_1->data[i];
      }

      k = indices->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[i + c_varargin_1->size[0]] = indices->data[i];
      }

      k = b_varargin_1->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[i + varargin_1->size[0]] = b_varargin_1->data[i];
      }

      k = b_y->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[(i + varargin_1->size[0]) + c_varargin_1->size[0]] =
          b_y->data[i];
      }

      k = c_y->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[(i + varargin_1->size[0]) + b_varargin_1->size[0]] =
          c_y->data[i];
      }

      k = varargin_2->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[((i + varargin_1->size[0]) + b_varargin_1->size[0]) +
          c_varargin_1->size[0]] = varargin_2->data[i];
      }

      k = d_y->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[((i + varargin_1->size[0]) + b_varargin_1->size[0]) +
          c_y->size[0]] = d_y->data[i];
      }

      k = b_varargin_2->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[(((i + varargin_1->size[0]) + b_varargin_1->size[0])
                            + c_y->size[0]) + c_varargin_1->size[0]] =
          b_varargin_2->data[i];
      }

      st.site = &jj_emlrtRSI;
      distortPoints(&st, c_varargin_1, intrinsicMatrix, this->RadialDistortion,
                    this->TangentialDistortion, ptsOut);
      st.site = &lj_emlrtRSI;
      k = ptsOut->size[0];
      i = varargin_1->size[0];
      varargin_1->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, varargin_1, i, &vf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        varargin_1->data[i] = ptsOut->data[i];
      }

      b_st.site = &lj_emlrtRSI;
      c_floor(&b_st, varargin_1);
      k = ptsOut->size[0];
      i = varargin_2->size[0];
      varargin_2->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, varargin_2, i, &wf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        varargin_2->data[i] = ptsOut->data[i + ptsOut->size[0]];
      }

      b_st.site = &lj_emlrtRSI;
      b_ceil(&b_st, varargin_2);
      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (varargin_2->size[0] != varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      st.site = &mj_emlrtRSI;
      k = ptsOut->size[0];
      i = b_varargin_1->size[0];
      b_varargin_1->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, b_varargin_1, i, &xf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        b_varargin_1->data[i] = ptsOut->data[i];
      }

      b_st.site = &mj_emlrtRSI;
      b_ceil(&b_st, b_varargin_1);
      k = ptsOut->size[0];
      i = b_varargin_2->size[0];
      b_varargin_2->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, b_varargin_2, i, &yf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        b_varargin_2->data[i] = ptsOut->data[i + ptsOut->size[0]];
      }

      b_st.site = &mj_emlrtRSI;
      c_floor(&b_st, b_varargin_2);
      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (b_varargin_2->size[0] != b_varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      i = r5->size[0] * r5->size[1];
      r5->size[0] = ptsOut->size[0];
      r5->size[1] = 2;
      emxEnsureCapacity_real_T(sp, r5, i, &ag_emlrtRTEI);
      k = ptsOut->size[0] * ptsOut->size[1];
      for (i = 0; i < k; i++) {
        r5->data[i] = ptsOut->data[i];
      }

      st.site = &kj_emlrtRSI;
      b_floor(&st, r5);
      st.site = &nj_emlrtRSI;
      c_ceil(&st, ptsOut);
      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = ((r5->size[0] + varargin_1->size[0]) +
                         b_varargin_1->size[0]) + ptsOut->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(sp, newPts, i, &bg_emlrtRTEI);
      k = r5->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[i] = r5->data[i];
      }

      for (i = 0; i < k; i++) {
        newPts->data[i + newPts->size[0]] = r5->data[i + r5->size[0]];
      }

      k = varargin_1->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[i + r5->size[0]] = varargin_1->data[i];
      }

      k = varargin_2->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[(i + r5->size[0]) + newPts->size[0]] = varargin_2->data[i];
      }

      k = b_varargin_1->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[(i + r5->size[0]) + varargin_1->size[0]] =
          b_varargin_1->data[i];
      }

      k = b_varargin_2->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[((i + r5->size[0]) + varargin_1->size[0]) + newPts->size[0]]
          = b_varargin_2->data[i];
      }

      k = ptsOut->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[((i + r5->size[0]) + varargin_1->size[0]) +
          b_varargin_1->size[0]] = ptsOut->data[i];
      }

      for (i = 0; i < k; i++) {
        newPts->data[(((i + r5->size[0]) + varargin_1->size[0]) +
                      b_varargin_1->size[0]) + newPts->size[0]] = ptsOut->data[i
          + ptsOut->size[0]];
      }

      k = newPts->size[0];
      i = r2->size[0];
      r2->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r2, i, &cg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r2->data[i] = (newPts->data[i] >= 1.0);
      }

      k = newPts->size[0];
      i = r3->size[0];
      r3->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r3, i, &dg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r3->data[i] = (newPts->data[i + newPts->size[0]] >= 1.0);
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &r_emlrtECI, sp);
      }

      k = r2->size[0];
      for (i = 0; i < k; i++) {
        r2->data[i] = (r2->data[i] && r3->data[i]);
      }

      k = newPts->size[0];
      i = r3->size[0];
      r3->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r3, i, &eg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r3->data[i] = (newPts->data[i] <= 640.0);
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &r_emlrtECI, sp);
      }

      k = r2->size[0];
      for (i = 0; i < k; i++) {
        r2->data[i] = (r2->data[i] && r3->data[i]);
      }

      k = newPts->size[0];
      i = r3->size[0];
      r3->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r3, i, &fg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r3->data[i] = (newPts->data[i + newPts->size[0]] <= 480.0);
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &r_emlrtECI, sp);
      }

      loop_ub = r2->size[0] - 1;
      k = 0;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        if (r2->data[b_i] && r3->data[b_i]) {
          k++;
        }
      }

      i = r4->size[0];
      r4->size[0] = k;
      emxEnsureCapacity_int32_T(sp, r4, i, &jf_emlrtRTEI);
      k = 0;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        if (r2->data[b_i] && r3->data[b_i]) {
          r4->data[k] = b_i + 1;
          k++;
        }
      }

      i = c_varargin_1->size[0] * c_varargin_1->size[1];
      c_varargin_1->size[0] = r4->size[0];
      c_varargin_1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, c_varargin_1, i, &gg_emlrtRTEI);
      k = r4->size[0];
      for (i = 0; i < k; i++) {
        if ((r4->data[i] < 1) || (r4->data[i] > newPts->size[0])) {
          emlrtDynamicBoundsCheckR2012b(r4->data[i], 1, newPts->size[0],
            &g_emlrtBCI, sp);
        }

        c_varargin_1->data[i] = newPts->data[r4->data[i] - 1];
      }

      for (i = 0; i < k; i++) {
        if ((r4->data[i] < 1) || (r4->data[i] > newPts->size[0])) {
          emlrtDynamicBoundsCheckR2012b(r4->data[i], 1, newPts->size[0],
            &g_emlrtBCI, sp);
        }

        c_varargin_1->data[i + c_varargin_1->size[0]] = newPts->data[(r4->data[i]
          + newPts->size[0]) - 1];
      }

      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = c_varargin_1->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(sp, newPts, i, &hg_emlrtRTEI);
      k = c_varargin_1->size[0] * c_varargin_1->size[1];
      for (i = 0; i < k; i++) {
        newPts->data[i] = c_varargin_1->data[i];
      }

      st.site = &oj_emlrtRSI;
      k = newPts->size[0];
      i = indices->size[0];
      indices->size[0] = newPts->size[0];
      emxEnsureCapacity_real_T(&st, indices, i, &ig_emlrtRTEI);
      for (i = 0; i < k; i++) {
        indices->data[i] = newPts->data[i + newPts->size[0]];
      }

      k = newPts->size[0];
      i = varargin_1->size[0];
      varargin_1->size[0] = newPts->size[0];
      emxEnsureCapacity_real_T(&st, varargin_1, i, &jg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        varargin_1->data[i] = newPts->data[i];
      }

      b_st.site = &sj_emlrtRSI;
      eml_sub2ind(&b_st, indices, varargin_1, r1);
      i = indices->size[0];
      indices->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(&st, indices, i, &kg_emlrtRTEI);
      k = r1->size[0];
      for (i = 0; i < k; i++) {
        indices->data[i] = r1->data[i];
      }

      i = r1->size[0];
      r1->size[0] = indices->size[0];
      emxEnsureCapacity_int32_T(sp, r1, i, &lg_emlrtRTEI);
      k = indices->size[0];
      for (i = 0; i < k; i++) {
        b_i = (int32_T)indices->data[i];
        if ((b_i < 1) || (b_i > 307200)) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, 307200, &f_emlrtBCI, sp);
        }

        r1->data[i] = b_i;
      }

      k = r1->size[0];
      for (i = 0; i < k; i++) {
        SD->u2.f2.mask[r1->data[i] - 1] = 1;
      }

      allPts_tmp = SD->u2.f2.mask[0];
      for (k = 0; k < 307199; k++) {
        allPts_tmp += (real_T)SD->u2.f2.mask[k + 1];
      }

      numUnmapped = 307200.0 - allPts_tmp;
      if (lastNumUnmapped == 307200.0 - allPts_tmp) {
        numTrials++;
      } else {
        numTrials = 0;
      }

      xBoundsBig[0] = p1_idx_0;
      xBoundsBig[1] = p2_idx_0;
      yBoundsBig[0] = p1_idx_1;
      yBoundsBig[1] = p2_idx_1;
    }

    emxFree_real_T(&c_varargin_1);
    emxFree_real_T(&r5);
    emxFree_real_T(&b_varargin_2);
    emxFree_real_T(&d_y);
    emxFree_real_T(&varargin_2);
    emxFree_real_T(&c_y);
    emxFree_real_T(&b_varargin_1);
    emxFree_real_T(&b_y);
    emxFree_real_T(&varargin_1);
    emxFree_real_T(&y);
    emxFree_int32_T(&r4);
    emxFree_boolean_T(&r3);
    emxFree_boolean_T(&r2);
    emxFree_real_T(&ptsOut);
    emxFree_real_T(&newPts);
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&indices);
  st.site = &pj_emlrtRSI;
  c_ImageTransformer_ImageTransfo(&st, &myMap);
  st.site = &qj_emlrtRSI;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
  }

  emxInit_real32_T(&st, &b_myMap, 2, &gf_emlrtRTEI, true);
  st.site = &qj_emlrtRSI;
  b_ImageTransformer_update(&st, &myMap, intrinsicMatrix, this->RadialDistortion,
    this->TangentialDistortion, xBoundsBig, yBoundsBig);
  st.site = &rj_emlrtRSI;
  i = b_myMap->size[0] * b_myMap->size[1];
  b_myMap->size[0] = myMap.XmapSingle->size[0];
  b_myMap->size[1] = myMap.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(&st, b_myMap, i, &gf_emlrtRTEI);
  k = myMap.XmapSingle->size[0] * myMap.XmapSingle->size[1] - 1;
  for (i = 0; i <= k; i++) {
    b_myMap->data[i] = myMap.XmapSingle->data[i];
  }

  emxInit_real32_T(&st, &c_myMap, 2, &hf_emlrtRTEI, true);
  i = c_myMap->size[0] * c_myMap->size[1];
  c_myMap->size[0] = myMap.YmapSingle->size[0];
  c_myMap->size[1] = myMap.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(&st, c_myMap, i, &hf_emlrtRTEI);
  k = myMap.YmapSingle->size[0] * myMap.YmapSingle->size[1] - 1;
  for (i = 0; i <= k; i++) {
    c_myMap->data[i] = myMap.YmapSingle->data[i];
  }

  b_st.site = &wj_emlrtRSI;
  b_interp2d(SD, &b_st, b_myMap, c_myMap, undistortedMask);
  emxFree_real32_T(&c_myMap);
  emxFree_real32_T(&b_myMap);
  c_emxFreeStruct_vision_internal(&myMap);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void getInitialBoundaryPixel(const emlrtStack *sp, const emxArray_uint8_T
  *undistortedMask, real_T boundaryPixel[2])
{
  int32_T sRow;
  int32_T sCol;
  int32_T cx;
  int32_T i;
  int32_T i1;
  int32_T b_i;
  boolean_T exitg1;
  int32_T i2;
  sRow = -1;
  sCol = -1;
  cx = (int32_T)muDoubleScalarFloor((real_T)undistortedMask->size[1] / 2.0);
  i = (int32_T)muDoubleScalarFloor((real_T)undistortedMask->size[0] / 2.0);
  i1 = undistortedMask->size[0] - i;
  emlrtForLoopVectorCheckR2012b(i, 1.0, undistortedMask->size[0], mxDOUBLE_CLASS,
    i1 + 1, &fb_emlrtRTEI, sp);
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= i1)) {
    i2 = (int32_T)((real_T)i + (real_T)b_i);
    if ((i2 < 1) || (i2 > undistortedMask->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, undistortedMask->size[0], &h_emlrtBCI,
        sp);
    }

    if ((cx < 1) || (cx > undistortedMask->size[1])) {
      emlrtDynamicBoundsCheckR2012b(cx, 1, undistortedMask->size[1], &h_emlrtBCI,
        sp);
    }

    if (undistortedMask->data[(i2 + undistortedMask->size[0] * (cx - 1)) - 1] ==
        0) {
      sRow = i2 - 1;
      sCol = cx;
      exitg1 = true;
    } else {
      b_i++;
    }
  }

  if (sRow == -1) {
    sRow = undistortedMask->size[0];
    sCol = cx;
  }

  boundaryPixel[0] = sRow;
  boundaryPixel[1] = sCol;
}

d_vision_internal_calibration_C *c_CameraParametersImpl_CameraPa(const
  emlrtStack *sp, d_vision_internal_calibration_C *this, const real_T
  varargin_1_RadialDistortion[2], const real_T varargin_1_TangentialDistortion[2],
  const real_T varargin_1_ImageSize[2], const char_T varargin_1_WorldUnits[11],
  real_T c_varargin_1_NumRadialDistortio, const real_T
  varargin_1_RotationVectors[114], const real_T varargin_1_TranslationVectors
  [114], const real_T varargin_1_IntrinsicMatrix[9])
{
  d_vision_internal_calibration_C *b_this;
  int32_T k;
  real_T c_this[2];
  real_T rotationVectors[114];
  boolean_T p;
  boolean_T exitg1;
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
  b_this = this;
  st.site = &kc_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  st.site = &lc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  c_CameraParametersImpl_checkInt(&b_st, varargin_1_IntrinsicMatrix);
  for (k = 0; k < 3; k++) {
    b_this->IntrinsicMatrixInternal[3 * k] = varargin_1_IntrinsicMatrix[k];
    b_this->IntrinsicMatrixInternal[3 * k + 1] = varargin_1_IntrinsicMatrix[k +
      3];
    b_this->IntrinsicMatrixInternal[3 * k + 2] = varargin_1_IntrinsicMatrix[k +
      6];
  }

  b_this->RadialDistortion[0] = varargin_1_RadialDistortion[0];
  b_this->RadialDistortion[1] = varargin_1_RadialDistortion[1];
  c_this[0] = b_this->RadialDistortion[0];
  c_this[1] = b_this->RadialDistortion[1];
  b_st.site = &oc_emlrtRSI;
  c_CameraParametersImpl_checkRad(&b_st, c_this);
  b_this->TangentialDistortion[0] = varargin_1_TangentialDistortion[0];
  b_this->TangentialDistortion[1] = varargin_1_TangentialDistortion[1];
  c_this[0] = b_this->TangentialDistortion[0];
  c_this[1] = b_this->TangentialDistortion[1];
  b_st.site = &pc_emlrtRSI;
  c_CameraParametersImpl_checkTan(&b_st, c_this);
  b_st.site = &qc_emlrtRSI;
  c_st.site = &yc_emlrtRSI;
  c_CameraParametersImpl_checkIma(&c_st, varargin_1_ImageSize);
  b_this->ImageSize[0] = varargin_1_ImageSize[0];
  b_this->ImageSize[1] = varargin_1_ImageSize[1];
  c_this[0] = b_this->ImageSize[0];
  c_this[1] = b_this->ImageSize[1];
  b_st.site = &rc_emlrtRSI;
  c_CameraParametersImpl_checkIma(&b_st, c_this);
  for (k = 0; k < 114; k++) {
    b_this->RotationVectors[k] = varargin_1_RotationVectors[k];
  }

  b_st.site = &sc_emlrtRSI;
  for (k = 0; k < 114; k++) {
    rotationVectors[k] = b_this->RotationVectors[k];
  }

  c_st.site = &bd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 114)) {
    if ((!muDoubleScalarIsInf(rotationVectors[k])) && (!muDoubleScalarIsNaN
         (rotationVectors[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 15, "RotationVectors");
  }

  for (k = 0; k < 114; k++) {
    b_this->TranslationVectors[k] = varargin_1_TranslationVectors[k];
  }

  b_st.site = &tc_emlrtRSI;
  for (k = 0; k < 114; k++) {
    rotationVectors[k] = b_this->TranslationVectors[k];
  }

  c_st.site = &cd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 114)) {
    if ((!muDoubleScalarIsInf(rotationVectors[k])) && (!muDoubleScalarIsNaN
         (rotationVectors[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 18, "TranslationVectors");
  }

  for (k = 0; k < 11; k++) {
    b_this->WorldUnits[k] = varargin_1_WorldUnits[k];
  }

  b_this->NumRadialDistortionCoefficients = c_varargin_1_NumRadialDistortio;
  b_st.site = &uc_emlrtRSI;
  c_CameraParametersImpl_checkNum(&b_st, b_this->NumRadialDistortionCoefficients);
  st.site = &mc_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  return b_this;
}

void c_CameraParametersImpl_computeU(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, const d_vision_internal_calibration_C *this, real_T xBounds[2],
  real_T yBounds[2])
{
  emxArray_uint8_T *undistortedMask;
  emxArray_boolean_T *b_undistortedMask;
  real_T xBoundsBig[2];
  real_T yBoundsBig[2];
  int32_T i;
  int32_T n;
  emxArray_struct_T *props;
  emxArray_real_T *dists;
  int32_T center_idx_0;
  int32_T center_idx_1;
  int32_T idx;
  real_T a;
  int32_T iidx;
  real_T b_a;
  boolean_T exitg1;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  st.prev = sp;
  st.tls = sp->tls;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_uint8_T(sp, &undistortedMask, 2, &gi_emlrtRTEI, true);
  emxInit_boolean_T(sp, &b_undistortedMask, 2, &ei_emlrtRTEI, true);
  st.site = &aj_emlrtRSI;
  d_CameraParametersImpl_createUn(SD, &st, this, undistortedMask, xBoundsBig,
    yBoundsBig);
  st.site = &cm_emlrtRSI;
  i = b_undistortedMask->size[0] * b_undistortedMask->size[1];
  b_undistortedMask->size[0] = undistortedMask->size[0];
  b_undistortedMask->size[1] = undistortedMask->size[1];
  emxEnsureCapacity_boolean_T(&st, b_undistortedMask, i, &ei_emlrtRTEI);
  n = undistortedMask->size[0] * undistortedMask->size[1];
  for (i = 0; i < n; i++) {
    b_undistortedMask->data[i] = (undistortedMask->data[i] != 0);
  }

  emxInit_struct_T(&st, &props, 1, &hi_emlrtRTEI, true);
  emxInit_real_T(&st, &dists, 2, &fi_emlrtRTEI, true);
  b_st.site = &dm_emlrtRSI;
  regionprops(&b_st, b_undistortedMask, props);
  center_idx_0 = (int32_T)muDoubleScalarRound((real_T)undistortedMask->size[0] /
    2.0);
  center_idx_1 = (int32_T)muDoubleScalarRound((real_T)undistortedMask->size[1] /
    2.0);
  i = dists->size[0] * dists->size[1];
  dists->size[0] = 1;
  dists->size[1] = props->size[0];
  emxEnsureCapacity_real_T(&st, dists, i, &fi_emlrtRTEI);
  n = props->size[0];
  emxFree_boolean_T(&b_undistortedMask);
  emxFree_uint8_T(&undistortedMask);
  for (i = 0; i < n; i++) {
    dists->data[i] = 0.0;
  }

  i = props->size[0];
  for (n = 0; n < i; n++) {
    b_st.site = &em_emlrtRSI;
    idx = n + 1;
    if ((idx < 1) || (idx > props->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, props->size[0], &ib_emlrtBCI, &b_st);
    }

    a = props->data[idx - 1].Centroid[0] - (real_T)center_idx_1;
    c_st.site = &se_emlrtRSI;
    b_st.site = &fm_emlrtRSI;
    idx = n + 1;
    if ((idx < 1) || (idx > props->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, props->size[0], &jb_emlrtBCI, &b_st);
    }

    b_a = props->data[idx - 1].Centroid[1] - (real_T)center_idx_0;
    c_st.site = &se_emlrtRSI;
    idx = n + 1;
    if ((idx < 1) || (idx > dists->size[1])) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, dists->size[1], &kb_emlrtBCI, &st);
    }

    dists->data[idx - 1] = a * a + b_a * b_a;
  }

  b_st.site = &gm_emlrtRSI;
  c_st.site = &eo_emlrtRSI;
  d_st.site = &ch_emlrtRSI;
  e_st.site = &dh_emlrtRSI;
  if (dists->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&e_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  f_st.site = &eh_emlrtRSI;
  n = dists->size[1];
  if (dists->size[1] <= 2) {
    if (dists->size[1] == 1) {
      iidx = 0;
    } else if ((dists->data[0] > dists->data[1]) || (muDoubleScalarIsNaN
                (dists->data[0]) && (!muDoubleScalarIsNaN(dists->data[1])))) {
      iidx = 1;
    } else {
      iidx = 0;
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    if (!muDoubleScalarIsNaN(dists->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      if (dists->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      center_idx_0 = 2;
      exitg1 = false;
      while ((!exitg1) && (center_idx_0 <= dists->size[1])) {
        if (!muDoubleScalarIsNaN(dists->data[center_idx_0 - 1])) {
          idx = center_idx_0;
          exitg1 = true;
        } else {
          center_idx_0++;
        }
      }
    }

    if (idx == 0) {
      iidx = 0;
    } else {
      g_st.site = &fh_emlrtRSI;
      a = dists->data[idx - 1];
      iidx = idx - 1;
      center_idx_1 = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= dists->size[1]) && (dists->size[1] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (center_idx_0 = center_idx_1; center_idx_0 <= n; center_idx_0++) {
        b_a = dists->data[center_idx_0 - 1];
        if (a > b_a) {
          a = b_a;
          iidx = center_idx_0 - 1;
        }
      }
    }
  }

  emxFree_real_T(&dists);
  i = iidx + 1;
  if ((i < 1) || (i > props->size[0])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, props->size[0], &hb_emlrtBCI, &st);
  }

  xBounds[0] = muDoubleScalarCeil((xBoundsBig[0] + props->data[iidx]
    .BoundingBox[0]) - 1.0);
  xBounds[1] = muDoubleScalarFloor(xBounds[0] + props->data[iidx].BoundingBox[2]);
  yBounds[0] = muDoubleScalarCeil((yBoundsBig[0] + props->data[iidx]
    .BoundingBox[1]) - 1.0);
  yBounds[1] = muDoubleScalarFloor(yBounds[0] + props->data[iidx].BoundingBox[3]);
  emxFree_struct_T(&props);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_CameraParametersImpl_createUn(F_02_getImageDataStackData *SD, const
  emlrtStack *sp, const d_vision_internal_calibration_C *this, emxArray_uint8_T *
  undistortedMask, real_T xBoundsBig[2], real_T yBoundsBig[2])
{
  c_vision_internal_calibration_I myMap;
  int32_T i;
  real_T b_dv[640];
  real_T b_dv1[480];
  real_T intrinsicMatrix[9];
  int32_T k;
  real_T allPts_tmp;
  int32_T b_i;
  emxArray_int32_T *r;
  boolean_T b;
  boolean_T b1;
  emxArray_real_T *allPts;
  emxArray_real_T *b_allPts;
  emxArray_real_T *c_allPts;
  emxArray_real_T *d_allPts;
  emxArray_real_T *indices;
  emxArray_int32_T *r1;
  real_T numUnmapped;
  real_T p1_idx_0;
  real_T p2_idx_0;
  real_T p1_idx_1;
  real_T p2_idx_1;
  int32_T numTrials;
  emxArray_real_T *newPts;
  emxArray_real_T *ptsOut;
  emxArray_real32_T *b_myMap;
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *y;
  emxArray_real_T *varargin_1;
  emxArray_real_T *b_y;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *c_y;
  emxArray_real_T *varargin_2;
  emxArray_real_T *d_y;
  emxArray_real_T *b_varargin_2;
  emxArray_real32_T *c_myMap;
  emxArray_real_T *r5;
  emxArray_real_T *c_varargin_1;
  real_T w;
  real_T h;
  int32_T lastNumUnmapped;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  d_emxInitStruct_vision_internal(sp, &myMap, &mg_emlrtRTEI, true);
  xBoundsBig[0] = 1.0;
  yBoundsBig[0] = 1.0;
  xBoundsBig[1] = 640.0;
  yBoundsBig[1] = 480.0;
  for (i = 0; i < 640; i++) {
    b_dv[i] = (real_T)i + 1.0;
  }

  for (i = 0; i < 480; i++) {
    b_dv1[i] = (real_T)i + 1.0;
  }

  b_meshgrid(b_dv, b_dv1, SD->u2.f3.b_X, SD->u2.f3.Y);
  st.site = &cj_emlrtRSI;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 307200; i++) {
    SD->u2.f3.X[i] = SD->u2.f3.b_X[i];
    SD->u2.f3.X[i + 307200] = SD->u2.f3.Y[i];
  }

  b_distortPoints(SD, SD->u2.f3.X, intrinsicMatrix, this->RadialDistortion,
                  this->TangentialDistortion, SD->u2.f3.ptsOut);
  memset(&SD->u2.f3.mask[0], 0, 307200U * sizeof(int8_T));
  for (k = 0; k < 614400; k++) {
    SD->u2.f3.X[k] = muDoubleScalarFloor(SD->u2.f3.ptsOut[k]);
  }

  for (k = 0; k < 307200; k++) {
    SD->u2.f3.b_X[k] = muDoubleScalarFloor(SD->u2.f3.ptsOut[k]);
    allPts_tmp = SD->u2.f3.ptsOut[k + 307200];
    SD->u2.f3.Y[k] = muDoubleScalarCeil(allPts_tmp);
    SD->u2.f3.b_ptsOut[k] = muDoubleScalarCeil(SD->u2.f3.ptsOut[k]);
    SD->u2.f3.x[k] = muDoubleScalarFloor(allPts_tmp);
  }

  for (k = 0; k < 614400; k++) {
    SD->u2.f3.ptsOut[k] = muDoubleScalarCeil(SD->u2.f3.ptsOut[k]);
  }

  for (i = 0; i < 2; i++) {
    memcpy(&SD->u2.f3.allPts[i * 1228800], &SD->u2.f3.X[i * 307200], 307200U *
           sizeof(real_T));
  }

  for (i = 0; i < 307200; i++) {
    SD->u2.f3.allPts[i + 307200] = SD->u2.f3.b_X[i];
    SD->u2.f3.allPts[i + 1536000] = SD->u2.f3.Y[i];
    SD->u2.f3.allPts[i + 614400] = SD->u2.f3.b_ptsOut[i];
    SD->u2.f3.allPts[i + 1843200] = SD->u2.f3.x[i];
  }

  for (i = 0; i < 2; i++) {
    memcpy(&SD->u2.f3.allPts[i * 1228800 + 921600], &SD->u2.f3.ptsOut[i * 307200],
           307200U * sizeof(real_T));
  }

  k = 0;
  for (b_i = 0; b_i < 1228800; b_i++) {
    allPts_tmp = SD->u2.f3.allPts[b_i + 1228800];
    b = ((SD->u2.f3.allPts[b_i] >= 1.0) && (allPts_tmp >= 1.0) &&
         (SD->u2.f3.allPts[b_i] <= 640.0));
    SD->u2.f3.bv[b_i] = b;
    b1 = (allPts_tmp <= 480.0);
    SD->u2.f3.bv1[b_i] = b1;
    if (b && b1) {
      k++;
    }
  }

  emxInit_int32_T(sp, &r, 1, &og_emlrtRTEI, true);
  i = r->size[0];
  r->size[0] = k;
  emxEnsureCapacity_int32_T(sp, r, i, &jf_emlrtRTEI);
  k = 0;
  for (b_i = 0; b_i < 1228800; b_i++) {
    if (SD->u2.f3.bv[b_i] && SD->u2.f3.bv1[b_i]) {
      r->data[k] = b_i + 1;
      k++;
    }
  }

  emxInit_real_T(sp, &allPts, 2, &kf_emlrtRTEI, true);
  emxInit_real_T(sp, &b_allPts, 2, &kf_emlrtRTEI, true);
  st.site = &dj_emlrtRSI;
  i = allPts->size[0] * allPts->size[1];
  allPts->size[0] = r->size[0];
  allPts->size[1] = 2;
  emxEnsureCapacity_real_T(&st, allPts, i, &kf_emlrtRTEI);
  i = b_allPts->size[0] * b_allPts->size[1];
  b_allPts->size[0] = r->size[0];
  b_allPts->size[1] = 2;
  emxEnsureCapacity_real_T(&st, b_allPts, i, &kf_emlrtRTEI);
  k = r->size[0];
  for (i = 0; i < k; i++) {
    allPts_tmp = SD->u2.f3.allPts[r->data[i] - 1];
    allPts->data[i] = allPts_tmp;
    b_allPts->data[i] = allPts_tmp;
  }

  for (i = 0; i < k; i++) {
    allPts_tmp = SD->u2.f3.allPts[r->data[i] + 1228799];
    allPts->data[i + allPts->size[0]] = allPts_tmp;
    b_allPts->data[i + b_allPts->size[0]] = allPts_tmp;
  }

  emxInit_real_T(&st, &c_allPts, 1, &lf_emlrtRTEI, true);
  k = r->size[0];
  i = c_allPts->size[0];
  c_allPts->size[0] = r->size[0];
  emxEnsureCapacity_real_T(&st, c_allPts, i, &lf_emlrtRTEI);
  for (i = 0; i < k; i++) {
    c_allPts->data[i] = allPts->data[i + allPts->size[0]];
  }

  emxFree_real_T(&allPts);
  emxInit_real_T(&st, &d_allPts, 1, &mf_emlrtRTEI, true);
  k = r->size[0];
  i = d_allPts->size[0];
  d_allPts->size[0] = r->size[0];
  emxEnsureCapacity_real_T(&st, d_allPts, i, &mf_emlrtRTEI);
  for (i = 0; i < k; i++) {
    d_allPts->data[i] = b_allPts->data[i];
  }

  emxFree_real_T(&b_allPts);
  emxInit_real_T(&st, &indices, 1, &nf_emlrtRTEI, true);
  emxInit_int32_T(&st, &r1, 1, &ug_emlrtRTEI, true);
  b_st.site = &sj_emlrtRSI;
  eml_sub2ind(&b_st, c_allPts, d_allPts, r1);
  i = indices->size[0];
  indices->size[0] = r1->size[0];
  emxEnsureCapacity_real_T(&st, indices, i, &nf_emlrtRTEI);
  k = r1->size[0];
  emxFree_real_T(&d_allPts);
  emxFree_real_T(&c_allPts);
  for (i = 0; i < k; i++) {
    indices->data[i] = r1->data[i];
  }

  i = r->size[0];
  r->size[0] = indices->size[0];
  emxEnsureCapacity_int32_T(sp, r, i, &of_emlrtRTEI);
  k = indices->size[0];
  for (i = 0; i < k; i++) {
    b_i = (int32_T)indices->data[i];
    if ((b_i < 1) || (b_i > 307200)) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, 307200, &e_emlrtBCI, sp);
    }

    r->data[i] = b_i;
  }

  k = r->size[0];
  for (i = 0; i < k; i++) {
    SD->u2.f3.mask[r->data[i] - 1] = 1;
  }

  emxFree_int32_T(&r);
  allPts_tmp = SD->u2.f3.mask[0];
  for (k = 0; k < 307199; k++) {
    allPts_tmp += (real_T)SD->u2.f3.mask[k + 1];
  }

  numUnmapped = 307200.0 - allPts_tmp;
  if (307200.0 - allPts_tmp > 0.0) {
    p1_idx_0 = 1.0;
    p2_idx_0 = 640.0;
    p1_idx_1 = 1.0;
    p2_idx_1 = 480.0;
    numTrials = 0;
    emxInit_real_T(sp, &newPts, 2, &bg_emlrtRTEI, true);
    emxInit_real_T(sp, &ptsOut, 2, &ng_emlrtRTEI, true);
    emxInit_boolean_T(sp, &r2, 1, &jf_emlrtRTEI, true);
    emxInit_boolean_T(sp, &r3, 1, &jf_emlrtRTEI, true);
    emxInit_int32_T(sp, &r4, 1, &pg_emlrtRTEI, true);
    emxInit_real_T(sp, &y, 2, &qg_emlrtRTEI, true);
    emxInit_real_T(sp, &varargin_1, 1, &qf_emlrtRTEI, true);
    emxInit_real_T(sp, &b_y, 1, &rg_emlrtRTEI, true);
    emxInit_real_T(sp, &b_varargin_1, 1, &rf_emlrtRTEI, true);
    emxInit_real_T(sp, &c_y, 1, &sg_emlrtRTEI, true);
    emxInit_real_T(sp, &varargin_2, 1, &sf_emlrtRTEI, true);
    emxInit_real_T(sp, &d_y, 1, &tg_emlrtRTEI, true);
    emxInit_real_T(sp, &b_varargin_2, 1, &tf_emlrtRTEI, true);
    emxInit_real_T(sp, &r5, 2, &ag_emlrtRTEI, true);
    emxInit_real_T(sp, &c_varargin_1, 2, &uf_emlrtRTEI, true);
    while ((numTrials < 5) && (numUnmapped > 0.0)) {
      p1_idx_0--;
      p2_idx_0++;
      p1_idx_1--;
      p2_idx_1++;
      w = (p2_idx_0 - p1_idx_0) + 1.0;
      h = (p2_idx_1 - p1_idx_1) + 1.0;
      lastNumUnmapped = (int32_T)numUnmapped;
      st.site = &ej_emlrtRSI;
      allPts_tmp = (p1_idx_0 + w) - 1.0;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_0) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_0 == allPts_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        k = (int32_T)(allPts_tmp - p1_idx_0);
        y->size[1] = k + 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        for (i = 0; i <= k; i++) {
          y->data[i] = p1_idx_0 + (real_T)i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_0, allPts_tmp, y);
      }

      i = (int32_T)w;
      if (w != i) {
        emlrtIntegerCheckR2012b(w, &d_emlrtDCI, sp);
      }

      k = (int32_T)w;
      b_i = indices->size[0];
      indices->size[0] = (int32_T)w;
      emxEnsureCapacity_real_T(sp, indices, b_i, &pf_emlrtRTEI);
      for (b_i = 0; b_i < k; b_i++) {
        indices->data[b_i] = p1_idx_1;
      }

      st.site = &ej_emlrtRSI;
      b_i = varargin_1->size[0];
      varargin_1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, varargin_1, b_i, &qf_emlrtRTEI);
      loop_ub = y->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        varargin_1->data[b_i] = y->data[b_i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (indices->size[0] != varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      st.site = &fj_emlrtRSI;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_0) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_0 == allPts_tmp)) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_0 == p1_idx_0) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = (int32_T)(allPts_tmp - p1_idx_0);
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          y->data[b_i] = p1_idx_0 + (real_T)b_i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_0, allPts_tmp, y);
      }

      if ((int32_T)w != i) {
        emlrtIntegerCheckR2012b(w, &c_emlrtDCI, sp);
      }

      i = b_y->size[0];
      b_y->size[0] = (int32_T)w;
      emxEnsureCapacity_real_T(sp, b_y, i, &pf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        b_y->data[i] = p2_idx_1;
      }

      st.site = &fj_emlrtRSI;
      i = b_varargin_1->size[0];
      b_varargin_1->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, b_varargin_1, i, &rf_emlrtRTEI);
      k = y->size[1];
      for (i = 0; i < k; i++) {
        b_varargin_1->data[i] = y->data[i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (b_y->size[0] != b_varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      i = (int32_T)h;
      if (h != i) {
        emlrtIntegerCheckR2012b(h, &b_emlrtDCI, sp);
      }

      k = (int32_T)h;
      b_i = c_y->size[0];
      c_y->size[0] = (int32_T)h;
      emxEnsureCapacity_real_T(sp, c_y, b_i, &pf_emlrtRTEI);
      for (b_i = 0; b_i < k; b_i++) {
        c_y->data[b_i] = p1_idx_0;
      }

      st.site = &gj_emlrtRSI;
      allPts_tmp = (p1_idx_1 + h) - 1.0;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_1) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_1 == allPts_tmp)) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        b_i = y->size[0] * y->size[1];
        y->size[0] = 1;
        loop_ub = (int32_T)(allPts_tmp - p1_idx_1);
        y->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&b_st, y, b_i, &id_emlrtRTEI);
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          y->data[b_i] = p1_idx_1 + (real_T)b_i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_1, allPts_tmp, y);
      }

      st.site = &gj_emlrtRSI;
      b_i = varargin_2->size[0];
      varargin_2->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, varargin_2, b_i, &sf_emlrtRTEI);
      loop_ub = y->size[1];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        varargin_2->data[b_i] = y->data[b_i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (varargin_2->size[0] != c_y->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      if ((int32_T)h != i) {
        emlrtIntegerCheckR2012b(h, &emlrtDCI, sp);
      }

      i = d_y->size[0];
      d_y->size[0] = (int32_T)h;
      emxEnsureCapacity_real_T(sp, d_y, i, &pf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        d_y->data[i] = p2_idx_0;
      }

      st.site = &hj_emlrtRSI;
      b_st.site = &de_emlrtRSI;
      if (allPts_tmp < p1_idx_1) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(p1_idx_1) || muDoubleScalarIsInf
                  (allPts_tmp)) && (p1_idx_1 == allPts_tmp)) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        y->data[0] = rtNaN;
      } else if (p1_idx_1 == p1_idx_1) {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        k = (int32_T)(allPts_tmp - p1_idx_1);
        y->size[1] = k + 1;
        emxEnsureCapacity_real_T(&b_st, y, i, &id_emlrtRTEI);
        for (i = 0; i <= k; i++) {
          y->data[i] = p1_idx_1 + (real_T)i;
        }
      } else {
        c_st.site = &ee_emlrtRSI;
        eml_float_colon(&c_st, p1_idx_1, allPts_tmp, y);
      }

      st.site = &hj_emlrtRSI;
      i = b_varargin_2->size[0];
      b_varargin_2->size[0] = y->size[1];
      emxEnsureCapacity_real_T(&st, b_varargin_2, i, &tf_emlrtRTEI);
      k = y->size[1];
      for (i = 0; i < k; i++) {
        b_varargin_2->data[i] = y->data[i];
      }

      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (b_varargin_2->size[0] != d_y->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      st.site = &ij_emlrtRSI;
      for (i = 0; i < 3; i++) {
        intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
        intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
        intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
      }

      i = c_varargin_1->size[0] * c_varargin_1->size[1];
      c_varargin_1->size[0] = ((varargin_1->size[0] + b_varargin_1->size[0]) +
        c_y->size[0]) + d_y->size[0];
      c_varargin_1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, c_varargin_1, i, &uf_emlrtRTEI);
      k = varargin_1->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[i] = varargin_1->data[i];
      }

      k = indices->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[i + c_varargin_1->size[0]] = indices->data[i];
      }

      k = b_varargin_1->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[i + varargin_1->size[0]] = b_varargin_1->data[i];
      }

      k = b_y->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[(i + varargin_1->size[0]) + c_varargin_1->size[0]] =
          b_y->data[i];
      }

      k = c_y->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[(i + varargin_1->size[0]) + b_varargin_1->size[0]] =
          c_y->data[i];
      }

      k = varargin_2->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[((i + varargin_1->size[0]) + b_varargin_1->size[0]) +
          c_varargin_1->size[0]] = varargin_2->data[i];
      }

      k = d_y->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[((i + varargin_1->size[0]) + b_varargin_1->size[0]) +
          c_y->size[0]] = d_y->data[i];
      }

      k = b_varargin_2->size[0];
      for (i = 0; i < k; i++) {
        c_varargin_1->data[(((i + varargin_1->size[0]) + b_varargin_1->size[0])
                            + c_y->size[0]) + c_varargin_1->size[0]] =
          b_varargin_2->data[i];
      }

      st.site = &jj_emlrtRSI;
      distortPoints(&st, c_varargin_1, intrinsicMatrix, this->RadialDistortion,
                    this->TangentialDistortion, ptsOut);
      st.site = &lj_emlrtRSI;
      k = ptsOut->size[0];
      i = varargin_1->size[0];
      varargin_1->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, varargin_1, i, &vf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        varargin_1->data[i] = ptsOut->data[i];
      }

      b_st.site = &lj_emlrtRSI;
      c_floor(&b_st, varargin_1);
      k = ptsOut->size[0];
      i = varargin_2->size[0];
      varargin_2->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, varargin_2, i, &wf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        varargin_2->data[i] = ptsOut->data[i + ptsOut->size[0]];
      }

      b_st.site = &lj_emlrtRSI;
      b_ceil(&b_st, varargin_2);
      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (varargin_2->size[0] != varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      st.site = &mj_emlrtRSI;
      k = ptsOut->size[0];
      i = b_varargin_1->size[0];
      b_varargin_1->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, b_varargin_1, i, &xf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        b_varargin_1->data[i] = ptsOut->data[i];
      }

      b_st.site = &mj_emlrtRSI;
      b_ceil(&b_st, b_varargin_1);
      k = ptsOut->size[0];
      i = b_varargin_2->size[0];
      b_varargin_2->size[0] = ptsOut->size[0];
      emxEnsureCapacity_real_T(&st, b_varargin_2, i, &yf_emlrtRTEI);
      for (i = 0; i < k; i++) {
        b_varargin_2->data[i] = ptsOut->data[i + ptsOut->size[0]];
      }

      b_st.site = &mj_emlrtRSI;
      c_floor(&b_st, b_varargin_2);
      b_st.site = &je_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      if (b_varargin_2->size[0] != b_varargin_1->size[0]) {
        emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      i = r5->size[0] * r5->size[1];
      r5->size[0] = ptsOut->size[0];
      r5->size[1] = 2;
      emxEnsureCapacity_real_T(sp, r5, i, &ag_emlrtRTEI);
      k = ptsOut->size[0] * ptsOut->size[1];
      for (i = 0; i < k; i++) {
        r5->data[i] = ptsOut->data[i];
      }

      st.site = &kj_emlrtRSI;
      b_floor(&st, r5);
      st.site = &nj_emlrtRSI;
      c_ceil(&st, ptsOut);
      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = ((r5->size[0] + varargin_1->size[0]) +
                         b_varargin_1->size[0]) + ptsOut->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(sp, newPts, i, &bg_emlrtRTEI);
      k = r5->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[i] = r5->data[i];
      }

      for (i = 0; i < k; i++) {
        newPts->data[i + newPts->size[0]] = r5->data[i + r5->size[0]];
      }

      k = varargin_1->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[i + r5->size[0]] = varargin_1->data[i];
      }

      k = varargin_2->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[(i + r5->size[0]) + newPts->size[0]] = varargin_2->data[i];
      }

      k = b_varargin_1->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[(i + r5->size[0]) + varargin_1->size[0]] =
          b_varargin_1->data[i];
      }

      k = b_varargin_2->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[((i + r5->size[0]) + varargin_1->size[0]) + newPts->size[0]]
          = b_varargin_2->data[i];
      }

      k = ptsOut->size[0];
      for (i = 0; i < k; i++) {
        newPts->data[((i + r5->size[0]) + varargin_1->size[0]) +
          b_varargin_1->size[0]] = ptsOut->data[i];
      }

      for (i = 0; i < k; i++) {
        newPts->data[(((i + r5->size[0]) + varargin_1->size[0]) +
                      b_varargin_1->size[0]) + newPts->size[0]] = ptsOut->data[i
          + ptsOut->size[0]];
      }

      k = newPts->size[0];
      i = r2->size[0];
      r2->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r2, i, &cg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r2->data[i] = (newPts->data[i] >= 1.0);
      }

      k = newPts->size[0];
      i = r3->size[0];
      r3->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r3, i, &dg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r3->data[i] = (newPts->data[i + newPts->size[0]] >= 1.0);
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &r_emlrtECI, sp);
      }

      k = r2->size[0];
      for (i = 0; i < k; i++) {
        r2->data[i] = (r2->data[i] && r3->data[i]);
      }

      k = newPts->size[0];
      i = r3->size[0];
      r3->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r3, i, &eg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r3->data[i] = (newPts->data[i] <= 640.0);
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &r_emlrtECI, sp);
      }

      k = r2->size[0];
      for (i = 0; i < k; i++) {
        r2->data[i] = (r2->data[i] && r3->data[i]);
      }

      k = newPts->size[0];
      i = r3->size[0];
      r3->size[0] = newPts->size[0];
      emxEnsureCapacity_boolean_T(sp, r3, i, &fg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        r3->data[i] = (newPts->data[i + newPts->size[0]] <= 480.0);
      }

      if (r2->size[0] != r3->size[0]) {
        emlrtSizeEqCheck1DR2012b(r2->size[0], r3->size[0], &r_emlrtECI, sp);
      }

      loop_ub = r2->size[0] - 1;
      k = 0;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        if (r2->data[b_i] && r3->data[b_i]) {
          k++;
        }
      }

      i = r4->size[0];
      r4->size[0] = k;
      emxEnsureCapacity_int32_T(sp, r4, i, &jf_emlrtRTEI);
      k = 0;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        if (r2->data[b_i] && r3->data[b_i]) {
          r4->data[k] = b_i + 1;
          k++;
        }
      }

      i = c_varargin_1->size[0] * c_varargin_1->size[1];
      c_varargin_1->size[0] = r4->size[0];
      c_varargin_1->size[1] = 2;
      emxEnsureCapacity_real_T(sp, c_varargin_1, i, &gg_emlrtRTEI);
      k = r4->size[0];
      for (i = 0; i < k; i++) {
        if ((r4->data[i] < 1) || (r4->data[i] > newPts->size[0])) {
          emlrtDynamicBoundsCheckR2012b(r4->data[i], 1, newPts->size[0],
            &g_emlrtBCI, sp);
        }

        c_varargin_1->data[i] = newPts->data[r4->data[i] - 1];
      }

      for (i = 0; i < k; i++) {
        if ((r4->data[i] < 1) || (r4->data[i] > newPts->size[0])) {
          emlrtDynamicBoundsCheckR2012b(r4->data[i], 1, newPts->size[0],
            &g_emlrtBCI, sp);
        }

        c_varargin_1->data[i + c_varargin_1->size[0]] = newPts->data[(r4->data[i]
          + newPts->size[0]) - 1];
      }

      i = newPts->size[0] * newPts->size[1];
      newPts->size[0] = c_varargin_1->size[0];
      newPts->size[1] = 2;
      emxEnsureCapacity_real_T(sp, newPts, i, &hg_emlrtRTEI);
      k = c_varargin_1->size[0] * c_varargin_1->size[1];
      for (i = 0; i < k; i++) {
        newPts->data[i] = c_varargin_1->data[i];
      }

      st.site = &oj_emlrtRSI;
      k = newPts->size[0];
      i = indices->size[0];
      indices->size[0] = newPts->size[0];
      emxEnsureCapacity_real_T(&st, indices, i, &ig_emlrtRTEI);
      for (i = 0; i < k; i++) {
        indices->data[i] = newPts->data[i + newPts->size[0]];
      }

      k = newPts->size[0];
      i = varargin_1->size[0];
      varargin_1->size[0] = newPts->size[0];
      emxEnsureCapacity_real_T(&st, varargin_1, i, &jg_emlrtRTEI);
      for (i = 0; i < k; i++) {
        varargin_1->data[i] = newPts->data[i];
      }

      b_st.site = &sj_emlrtRSI;
      eml_sub2ind(&b_st, indices, varargin_1, r1);
      i = indices->size[0];
      indices->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(&st, indices, i, &kg_emlrtRTEI);
      k = r1->size[0];
      for (i = 0; i < k; i++) {
        indices->data[i] = r1->data[i];
      }

      i = r1->size[0];
      r1->size[0] = indices->size[0];
      emxEnsureCapacity_int32_T(sp, r1, i, &lg_emlrtRTEI);
      k = indices->size[0];
      for (i = 0; i < k; i++) {
        b_i = (int32_T)indices->data[i];
        if ((b_i < 1) || (b_i > 307200)) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, 307200, &f_emlrtBCI, sp);
        }

        r1->data[i] = b_i;
      }

      k = r1->size[0];
      for (i = 0; i < k; i++) {
        SD->u2.f3.mask[r1->data[i] - 1] = 1;
      }

      allPts_tmp = SD->u2.f3.mask[0];
      for (k = 0; k < 307199; k++) {
        allPts_tmp += (real_T)SD->u2.f3.mask[k + 1];
      }

      numUnmapped = 307200.0 - allPts_tmp;
      if (lastNumUnmapped == 307200.0 - allPts_tmp) {
        numTrials++;
      } else {
        numTrials = 0;
      }

      xBoundsBig[0] = p1_idx_0;
      xBoundsBig[1] = p2_idx_0;
      yBoundsBig[0] = p1_idx_1;
      yBoundsBig[1] = p2_idx_1;
    }

    emxFree_real_T(&c_varargin_1);
    emxFree_real_T(&r5);
    emxFree_real_T(&b_varargin_2);
    emxFree_real_T(&d_y);
    emxFree_real_T(&varargin_2);
    emxFree_real_T(&c_y);
    emxFree_real_T(&b_varargin_1);
    emxFree_real_T(&b_y);
    emxFree_real_T(&varargin_1);
    emxFree_real_T(&y);
    emxFree_int32_T(&r4);
    emxFree_boolean_T(&r3);
    emxFree_boolean_T(&r2);
    emxFree_real_T(&ptsOut);
    emxFree_real_T(&newPts);
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&indices);
  st.site = &pj_emlrtRSI;
  c_ImageTransformer_ImageTransfo(&st, &myMap);
  st.site = &qj_emlrtRSI;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
  }

  emxInit_real32_T(&st, &b_myMap, 2, &gf_emlrtRTEI, true);
  st.site = &qj_emlrtRSI;
  ImageTransformer_update(&st, &myMap, intrinsicMatrix, this->RadialDistortion,
    this->TangentialDistortion, xBoundsBig, yBoundsBig);
  st.site = &rj_emlrtRSI;
  i = b_myMap->size[0] * b_myMap->size[1];
  b_myMap->size[0] = myMap.XmapSingle->size[0];
  b_myMap->size[1] = myMap.XmapSingle->size[1];
  emxEnsureCapacity_real32_T(&st, b_myMap, i, &gf_emlrtRTEI);
  k = myMap.XmapSingle->size[0] * myMap.XmapSingle->size[1] - 1;
  for (i = 0; i <= k; i++) {
    b_myMap->data[i] = myMap.XmapSingle->data[i];
  }

  emxInit_real32_T(&st, &c_myMap, 2, &hf_emlrtRTEI, true);
  i = c_myMap->size[0] * c_myMap->size[1];
  c_myMap->size[0] = myMap.YmapSingle->size[0];
  c_myMap->size[1] = myMap.YmapSingle->size[1];
  emxEnsureCapacity_real32_T(&st, c_myMap, i, &hf_emlrtRTEI);
  k = myMap.YmapSingle->size[0] * myMap.YmapSingle->size[1] - 1;
  for (i = 0; i <= k; i++) {
    c_myMap->data[i] = myMap.YmapSingle->data[i];
  }

  b_st.site = &wj_emlrtRSI;
  b_interp2d(SD, &b_st, b_myMap, c_myMap, undistortedMask);
  emxFree_real32_T(&c_myMap);
  emxFree_real32_T(&b_myMap);
  c_emxFreeStruct_vision_internal(&myMap);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_CameraParametersImpl_getValid(const emlrtStack *sp, const
  d_vision_internal_calibration_C *this, const emxArray_uint8_T *undistortedMask,
  const real_T xBoundsBig[2], const real_T yBoundsBig[2], real_T xBounds[2],
  real_T yBounds[2])
{
  emxArray_real_T *boundaryPixelsUndistorted;
  emxArray_real_T *boundaryPixelsDistorted;
  real_T boundaryPixel[2];
  int32_T n;
  int32_T i;
  emxArray_real_T *b_boundaryPixelsUndistorted;
  int32_T c_boundaryPixelsUndistorted[1];
  int32_T iv[1];
  real_T intrinsicMatrix[9];
  real_T ex;
  int32_T idx;
  boolean_T overflow;
  int32_T k;
  int32_T a;
  boolean_T exitg1;
  real_T minX;
  real_T d;
  real_T maxX;
  real_T minY;
  real_T maxY;
  emxArray_boolean_T *topIdx;
  emxArray_real_T *r;
  emxArray_boolean_T *botIdx;
  emxArray_boolean_T *leftIdx;
  emxArray_boolean_T *rightIdx;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_int32_T *r7;
  emxArray_int32_T *r8;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  st.prev = sp;
  st.tls = sp->tls;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &boundaryPixelsUndistorted, 2, &kh_emlrtRTEI, true);
  emxInit_real_T(sp, &boundaryPixelsDistorted, 2, &lh_emlrtRTEI, true);
  st.site = &xj_emlrtRSI;
  getInitialBoundaryPixel(&st, undistortedMask, boundaryPixel);
  st.site = &yj_emlrtRSI;
  bwtraceboundary(&st, undistortedMask, boundaryPixel, boundaryPixelsUndistorted);
  n = boundaryPixelsUndistorted->size[0] - 1;
  i = boundaryPixelsDistorted->size[0] * boundaryPixelsDistorted->size[1];
  boundaryPixelsDistorted->size[0] = boundaryPixelsUndistorted->size[0];
  boundaryPixelsDistorted->size[1] = 2;
  emxEnsureCapacity_real_T(sp, boundaryPixelsDistorted, i, &wg_emlrtRTEI);
  for (i = 0; i <= n; i++) {
    boundaryPixelsDistorted->data[i] = boundaryPixelsUndistorted->data[i +
      boundaryPixelsUndistorted->size[0]];
  }

  for (i = 0; i <= n; i++) {
    boundaryPixelsDistorted->data[i + boundaryPixelsDistorted->size[0]] =
      boundaryPixelsUndistorted->data[i];
  }

  i = boundaryPixelsUndistorted->size[0] * boundaryPixelsUndistorted->size[1];
  boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  boundaryPixelsUndistorted->size[1] = 2;
  emxEnsureCapacity_real_T(sp, boundaryPixelsUndistorted, i, &xg_emlrtRTEI);
  n = boundaryPixelsDistorted->size[0] * boundaryPixelsDistorted->size[1];
  for (i = 0; i < n; i++) {
    boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i];
  }

  emxInit_real_T(sp, &b_boundaryPixelsUndistorted, 1, &yg_emlrtRTEI, true);
  c_boundaryPixelsUndistorted[0] = boundaryPixelsUndistorted->size[0];
  iv[0] = boundaryPixelsUndistorted->size[0];
  emlrtSubAssignSizeCheckR2012b(&c_boundaryPixelsUndistorted[0], 1, &iv[0], 1,
    &s_emlrtECI, sp);
  n = boundaryPixelsUndistorted->size[0] - 1;
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(sp, b_boundaryPixelsUndistorted, i, &yg_emlrtRTEI);
  for (i = 0; i <= n; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsUndistorted->data[i] +
      xBoundsBig[0];
  }

  n = b_boundaryPixelsUndistorted->size[0];
  for (i = 0; i < n; i++) {
    boundaryPixelsUndistorted->data[i] = b_boundaryPixelsUndistorted->data[i];
  }

  c_boundaryPixelsUndistorted[0] = boundaryPixelsUndistorted->size[0];
  iv[0] = boundaryPixelsUndistorted->size[0];
  emlrtSubAssignSizeCheckR2012b(&c_boundaryPixelsUndistorted[0], 1, &iv[0], 1,
    &t_emlrtECI, sp);
  n = boundaryPixelsUndistorted->size[0] - 1;
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsUndistorted->size[0];
  emxEnsureCapacity_real_T(sp, b_boundaryPixelsUndistorted, i, &ah_emlrtRTEI);
  for (i = 0; i <= n; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsUndistorted->data[i +
      boundaryPixelsUndistorted->size[0]] + yBoundsBig[0];
  }

  n = b_boundaryPixelsUndistorted->size[0];
  for (i = 0; i < n; i++) {
    boundaryPixelsUndistorted->data[i + boundaryPixelsUndistorted->size[0]] =
      b_boundaryPixelsUndistorted->data[i];
  }

  st.site = &ak_emlrtRSI;
  b_st.site = &bl_emlrtRSI;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = this->IntrinsicMatrixInternal[i + 6];
  }

  b_st.site = &cl_emlrtRSI;
  distortPoints(&b_st, boundaryPixelsUndistorted, intrinsicMatrix,
                this->RadialDistortion, this->TangentialDistortion,
                boundaryPixelsDistorted);
  st.site = &bk_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (boundaryPixelsDistorted->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &th_emlrtRSI;
  f_st.site = &uh_emlrtRSI;
  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[0];
    } else if ((boundaryPixelsDistorted->data[0] > boundaryPixelsDistorted->
                data[1]) || (muDoubleScalarIsNaN(boundaryPixelsDistorted->data[0])
                && (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[1])))) {
      ex = boundaryPixelsDistorted->data[1];
    } else {
      ex = boundaryPixelsDistorted->data[0];
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[0];
    } else {
      g_st.site = &fh_emlrtRSI;
      ex = boundaryPixelsDistorted->data[idx - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= i; k++) {
        d = boundaryPixelsDistorted->data[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }

  minX = muDoubleScalarMax(1.0, ex);
  st.site = &ck_emlrtRSI;
  b_st.site = &dl_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (boundaryPixelsDistorted->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &el_emlrtRSI;
  f_st.site = &fl_emlrtRSI;
  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[0];
    } else if ((boundaryPixelsDistorted->data[0] < boundaryPixelsDistorted->
                data[1]) || (muDoubleScalarIsNaN(boundaryPixelsDistorted->data[0])
                && (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[1])))) {
      ex = boundaryPixelsDistorted->data[1];
    } else {
      ex = boundaryPixelsDistorted->data[0];
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[0];
    } else {
      g_st.site = &fh_emlrtRSI;
      ex = boundaryPixelsDistorted->data[idx - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= i; k++) {
        d = boundaryPixelsDistorted->data[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }

  maxX = muDoubleScalarMin(640.0, ex);
  st.site = &dk_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (boundaryPixelsDistorted->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &th_emlrtRSI;
  f_st.site = &uh_emlrtRSI;
  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else if ((boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]] >
                boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] +
                1]) || (muDoubleScalarIsNaN(boundaryPixelsDistorted->
                 data[boundaryPixelsDistorted->size[0]]) &&
                        (!muDoubleScalarIsNaN(boundaryPixelsDistorted->
                  data[boundaryPixelsDistorted->size[0] + 1])))) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] + 1];
    } else {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->
         data[boundaryPixelsDistorted->size[0]])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[(k +
              boundaryPixelsDistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else {
      g_st.site = &fh_emlrtRSI;
      ex = boundaryPixelsDistorted->data[(idx + boundaryPixelsDistorted->size[0])
        - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= i; k++) {
        d = boundaryPixelsDistorted->data[(k + boundaryPixelsDistorted->size[0])
          - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }

  minY = muDoubleScalarMax(1.0, ex);
  st.site = &ek_emlrtRSI;
  b_st.site = &dl_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (boundaryPixelsDistorted->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &el_emlrtRSI;
  f_st.site = &fl_emlrtRSI;
  i = boundaryPixelsDistorted->size[0];
  if (boundaryPixelsDistorted->size[0] <= 2) {
    if (boundaryPixelsDistorted->size[0] == 1) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else if ((boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]] <
                boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] +
                1]) || (muDoubleScalarIsNaN(boundaryPixelsDistorted->
                 data[boundaryPixelsDistorted->size[0]]) &&
                        (!muDoubleScalarIsNaN(boundaryPixelsDistorted->
                  data[boundaryPixelsDistorted->size[0] + 1])))) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0] + 1];
    } else {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->
         data[boundaryPixelsDistorted->size[0]])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= boundaryPixelsDistorted->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsDistorted->data[(k +
              boundaryPixelsDistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = boundaryPixelsDistorted->data[boundaryPixelsDistorted->size[0]];
    } else {
      g_st.site = &fh_emlrtRSI;
      ex = boundaryPixelsDistorted->data[(idx + boundaryPixelsDistorted->size[0])
        - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= boundaryPixelsDistorted->size[0]) &&
                  (boundaryPixelsDistorted->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= i; k++) {
        d = boundaryPixelsDistorted->data[(k + boundaryPixelsDistorted->size[0])
          - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }

  maxY = muDoubleScalarMin(480.0, ex);
  n = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(sp, b_boundaryPixelsUndistorted, i, &bh_emlrtRTEI);
  for (i = 0; i < n; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i +
      boundaryPixelsDistorted->size[0]] - minY;
  }

  emxInit_boolean_T(sp, &topIdx, 1, &ch_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 1, &qh_emlrtRTEI, true);
  st.site = &fk_emlrtRSI;
  b_abs(&st, b_boundaryPixelsUndistorted, r);
  i = topIdx->size[0];
  topIdx->size[0] = r->size[0];
  emxEnsureCapacity_boolean_T(sp, topIdx, i, &ch_emlrtRTEI);
  n = r->size[0];
  for (i = 0; i < n; i++) {
    topIdx->data[i] = (r->data[i] < 7.0);
  }

  n = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(sp, b_boundaryPixelsUndistorted, i, &dh_emlrtRTEI);
  for (i = 0; i < n; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i +
      boundaryPixelsDistorted->size[0]] - maxY;
  }

  emxInit_boolean_T(sp, &botIdx, 1, &eh_emlrtRTEI, true);
  st.site = &gk_emlrtRSI;
  b_abs(&st, b_boundaryPixelsUndistorted, r);
  i = botIdx->size[0];
  botIdx->size[0] = r->size[0];
  emxEnsureCapacity_boolean_T(sp, botIdx, i, &eh_emlrtRTEI);
  n = r->size[0];
  for (i = 0; i < n; i++) {
    botIdx->data[i] = (r->data[i] < 7.0);
  }

  n = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(sp, b_boundaryPixelsUndistorted, i, &fh_emlrtRTEI);
  for (i = 0; i < n; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i] -
      minX;
  }

  emxInit_boolean_T(sp, &leftIdx, 1, &gh_emlrtRTEI, true);
  st.site = &hk_emlrtRSI;
  b_abs(&st, b_boundaryPixelsUndistorted, r);
  i = leftIdx->size[0];
  leftIdx->size[0] = r->size[0];
  emxEnsureCapacity_boolean_T(sp, leftIdx, i, &gh_emlrtRTEI);
  n = r->size[0];
  for (i = 0; i < n; i++) {
    leftIdx->data[i] = (r->data[i] < 7.0);
  }

  n = boundaryPixelsDistorted->size[0];
  i = b_boundaryPixelsUndistorted->size[0];
  b_boundaryPixelsUndistorted->size[0] = boundaryPixelsDistorted->size[0];
  emxEnsureCapacity_real_T(sp, b_boundaryPixelsUndistorted, i, &hh_emlrtRTEI);
  for (i = 0; i < n; i++) {
    b_boundaryPixelsUndistorted->data[i] = boundaryPixelsDistorted->data[i] -
      maxX;
  }

  emxFree_real_T(&boundaryPixelsDistorted);
  emxInit_boolean_T(sp, &rightIdx, 1, &ih_emlrtRTEI, true);
  st.site = &ik_emlrtRSI;
  b_abs(&st, b_boundaryPixelsUndistorted, r);
  i = rightIdx->size[0];
  rightIdx->size[0] = r->size[0];
  emxEnsureCapacity_boolean_T(sp, rightIdx, i, &ih_emlrtRTEI);
  n = r->size[0];
  emxFree_real_T(&b_boundaryPixelsUndistorted);
  for (i = 0; i < n; i++) {
    rightIdx->data[i] = (r->data[i] < 7.0);
  }

  emxFree_real_T(&r);
  idx = topIdx->size[0];
  for (k = 0; k < idx; k++) {
    if (topIdx->data[k]) {
      i = k + 1;
      if ((i < 1) || (i > boundaryPixelsUndistorted->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, boundaryPixelsUndistorted->size[0],
          &i_emlrtBCI, sp);
      }
    }
  }

  idx = botIdx->size[0];
  for (k = 0; k < idx; k++) {
    if (botIdx->data[k]) {
      i = k + 1;
      if ((i < 1) || (i > boundaryPixelsUndistorted->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, boundaryPixelsUndistorted->size[0],
          &j_emlrtBCI, sp);
      }
    }
  }

  idx = leftIdx->size[0];
  for (k = 0; k < idx; k++) {
    if (leftIdx->data[k]) {
      i = k + 1;
      if ((i < 1) || (i > boundaryPixelsUndistorted->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, boundaryPixelsUndistorted->size[0],
          &k_emlrtBCI, sp);
      }
    }
  }

  idx = rightIdx->size[0];
  for (k = 0; k < idx; k++) {
    if (rightIdx->data[k]) {
      i = k + 1;
      if ((i < 1) || (i > boundaryPixelsUndistorted->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, boundaryPixelsUndistorted->size[0],
          &l_emlrtBCI, sp);
      }
    }
  }

  idx = topIdx->size[0] - 1;
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (topIdx->data[k]) {
      n++;
    }
  }

  emxInit_int32_T(sp, &r1, 1, &mh_emlrtRTEI, true);
  i = r1->size[0];
  r1->size[0] = n;
  emxEnsureCapacity_int32_T(sp, r1, i, &jh_emlrtRTEI);
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (topIdx->data[k]) {
      r1->data[n] = k + 1;
      n++;
    }
  }

  emxInit_int32_T(sp, &r2, 1, &nh_emlrtRTEI, true);
  emxInit_int32_T(sp, &r3, 1, &oh_emlrtRTEI, true);
  emxInit_int32_T(sp, &r4, 1, &ph_emlrtRTEI, true);
  if (r1->size[0] == 0) {
    overflow = true;
  } else {
    idx = botIdx->size[0] - 1;
    n = 0;
    for (k = 0; k <= idx; k++) {
      if (botIdx->data[k]) {
        n++;
      }
    }

    i = r2->size[0];
    r2->size[0] = n;
    emxEnsureCapacity_int32_T(sp, r2, i, &jh_emlrtRTEI);
    n = 0;
    for (k = 0; k <= idx; k++) {
      if (botIdx->data[k]) {
        r2->data[n] = k + 1;
        n++;
      }
    }

    if (r2->size[0] == 0) {
      overflow = true;
    } else {
      idx = leftIdx->size[0] - 1;
      n = 0;
      for (k = 0; k <= idx; k++) {
        if (leftIdx->data[k]) {
          n++;
        }
      }

      i = r3->size[0];
      r3->size[0] = n;
      emxEnsureCapacity_int32_T(sp, r3, i, &jh_emlrtRTEI);
      n = 0;
      for (k = 0; k <= idx; k++) {
        if (leftIdx->data[k]) {
          r3->data[n] = k + 1;
          n++;
        }
      }

      if (r3->size[0] == 0) {
        overflow = true;
      } else {
        idx = rightIdx->size[0] - 1;
        n = 0;
        for (k = 0; k <= idx; k++) {
          if (rightIdx->data[k]) {
            n++;
          }
        }

        i = r4->size[0];
        r4->size[0] = n;
        emxEnsureCapacity_int32_T(sp, r4, i, &jh_emlrtRTEI);
        n = 0;
        for (k = 0; k <= idx; k++) {
          if (rightIdx->data[k]) {
            r4->data[n] = k + 1;
            n++;
          }
        }

        if (r4->size[0] == 0) {
          overflow = true;
        } else {
          overflow = false;
        }
      }
    }
  }

  emxFree_int32_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  emxFree_int32_T(&r1);
  if (overflow) {
    emlrtErrorWithMessageIdR2018a(sp, &gb_emlrtRTEI,
      "vision:calibrate:cannotComputeValidBounds",
      "vision:calibrate:cannotComputeValidBounds", 0);
  }

  idx = topIdx->size[0] - 1;
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (topIdx->data[k]) {
      n++;
    }
  }

  emxInit_int32_T(sp, &r5, 1, &mh_emlrtRTEI, true);
  i = r5->size[0];
  r5->size[0] = n;
  emxEnsureCapacity_int32_T(sp, r5, i, &jh_emlrtRTEI);
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (topIdx->data[k]) {
      r5->data[n] = k + 1;
      n++;
    }
  }

  emxFree_boolean_T(&topIdx);
  st.site = &jk_emlrtRSI;
  b_st.site = &dl_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (r5->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &el_emlrtRSI;
  f_st.site = &fl_emlrtRSI;
  n = r5->size[0];
  if (r5->size[0] <= 2) {
    if (r5->size[0] == 1) {
      ex = boundaryPixelsUndistorted->data[(r5->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
    } else {
      d = boundaryPixelsUndistorted->data[(r5->data[1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      ex = boundaryPixelsUndistorted->data[(r5->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
      if ((ex < d) || (muDoubleScalarIsNaN(boundaryPixelsUndistorted->data
            [(r5->data[0] + boundaryPixelsUndistorted->size[0]) - 1]) &&
                       (!muDoubleScalarIsNaN(d)))) {
        ex = d;
      }
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    ex = boundaryPixelsUndistorted->data[(r5->data[0] +
      boundaryPixelsUndistorted->size[0]) - 1];
    if (!muDoubleScalarIsNaN(ex)) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= r5->size[0]) && (r5->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r5->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsUndistorted->data[(r5->data[k - 1]
              + boundaryPixelsUndistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      g_st.site = &fh_emlrtRSI;
      ex = boundaryPixelsUndistorted->data[(r5->data[idx - 1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= r5->size[0]) && (r5->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[(r5->data[k - 1] +
          boundaryPixelsUndistorted->size[0]) - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }

  emxFree_int32_T(&r5);
  idx = botIdx->size[0] - 1;
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (botIdx->data[k]) {
      n++;
    }
  }

  emxInit_int32_T(sp, &r6, 1, &nh_emlrtRTEI, true);
  i = r6->size[0];
  r6->size[0] = n;
  emxEnsureCapacity_int32_T(sp, r6, i, &jh_emlrtRTEI);
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (botIdx->data[k]) {
      r6->data[n] = k + 1;
      n++;
    }
  }

  emxFree_boolean_T(&botIdx);
  st.site = &kk_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (r6->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &th_emlrtRSI;
  f_st.site = &uh_emlrtRSI;
  n = r6->size[0];
  if (r6->size[0] <= 2) {
    if (r6->size[0] == 1) {
      maxY = boundaryPixelsUndistorted->data[(r6->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
    } else {
      d = boundaryPixelsUndistorted->data[(r6->data[1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      maxY = boundaryPixelsUndistorted->data[(r6->data[0] +
        boundaryPixelsUndistorted->size[0]) - 1];
      if ((maxY > d) || (muDoubleScalarIsNaN(boundaryPixelsUndistorted->data
            [(r6->data[0] + boundaryPixelsUndistorted->size[0]) - 1]) &&
                         (!muDoubleScalarIsNaN(d)))) {
        maxY = d;
      }
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    maxY = boundaryPixelsUndistorted->data[(r6->data[0] +
      boundaryPixelsUndistorted->size[0]) - 1];
    if (!muDoubleScalarIsNaN(maxY)) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= r6->size[0]) && (r6->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r6->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsUndistorted->data[(r6->data[k - 1]
              + boundaryPixelsUndistorted->size[0]) - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      g_st.site = &fh_emlrtRSI;
      maxY = boundaryPixelsUndistorted->data[(r6->data[idx - 1] +
        boundaryPixelsUndistorted->size[0]) - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= r6->size[0]) && (r6->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[(r6->data[k - 1] +
          boundaryPixelsUndistorted->size[0]) - 1];
        if (maxY > d) {
          maxY = d;
        }
      }
    }
  }

  emxFree_int32_T(&r6);
  idx = leftIdx->size[0] - 1;
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (leftIdx->data[k]) {
      n++;
    }
  }

  emxInit_int32_T(sp, &r7, 1, &oh_emlrtRTEI, true);
  i = r7->size[0];
  r7->size[0] = n;
  emxEnsureCapacity_int32_T(sp, r7, i, &jh_emlrtRTEI);
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (leftIdx->data[k]) {
      r7->data[n] = k + 1;
      n++;
    }
  }

  emxFree_boolean_T(&leftIdx);
  st.site = &lk_emlrtRSI;
  b_st.site = &dl_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (r7->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &el_emlrtRSI;
  f_st.site = &fl_emlrtRSI;
  n = r7->size[0];
  if (r7->size[0] <= 2) {
    if (r7->size[0] == 1) {
      minX = boundaryPixelsUndistorted->data[r7->data[0] - 1];
    } else {
      d = boundaryPixelsUndistorted->data[r7->data[1] - 1];
      minX = boundaryPixelsUndistorted->data[r7->data[0] - 1];
      if ((minX < d) || (muDoubleScalarIsNaN(boundaryPixelsUndistorted->data
            [r7->data[0] - 1]) && (!muDoubleScalarIsNaN(d)))) {
        minX = d;
      }
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    minX = boundaryPixelsUndistorted->data[r7->data[0] - 1];
    if (!muDoubleScalarIsNaN(minX)) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= r7->size[0]) && (r7->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r7->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsUndistorted->data[r7->data[k - 1]
             - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      g_st.site = &fh_emlrtRSI;
      minX = boundaryPixelsUndistorted->data[r7->data[idx - 1] - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= r7->size[0]) && (r7->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[r7->data[k - 1] - 1];
        if (minX < d) {
          minX = d;
        }
      }
    }
  }

  emxFree_int32_T(&r7);
  idx = rightIdx->size[0] - 1;
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (rightIdx->data[k]) {
      n++;
    }
  }

  emxInit_int32_T(sp, &r8, 1, &ph_emlrtRTEI, true);
  i = r8->size[0];
  r8->size[0] = n;
  emxEnsureCapacity_int32_T(sp, r8, i, &jh_emlrtRTEI);
  n = 0;
  for (k = 0; k <= idx; k++) {
    if (rightIdx->data[k]) {
      r8->data[n] = k + 1;
      n++;
    }
  }

  emxFree_boolean_T(&rightIdx);
  st.site = &mk_emlrtRSI;
  b_st.site = &qh_emlrtRSI;
  c_st.site = &rh_emlrtRSI;
  d_st.site = &sh_emlrtRSI;
  if (r8->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &th_emlrtRSI;
  f_st.site = &uh_emlrtRSI;
  n = r8->size[0];
  if (r8->size[0] <= 2) {
    if (r8->size[0] == 1) {
      maxX = boundaryPixelsUndistorted->data[r8->data[0] - 1];
    } else {
      d = boundaryPixelsUndistorted->data[r8->data[1] - 1];
      maxX = boundaryPixelsUndistorted->data[r8->data[0] - 1];
      if ((maxX > d) || (muDoubleScalarIsNaN(boundaryPixelsUndistorted->data
            [r8->data[0] - 1]) && (!muDoubleScalarIsNaN(d)))) {
        maxX = d;
      }
    }
  } else {
    g_st.site = &vh_emlrtRSI;
    maxX = boundaryPixelsUndistorted->data[r8->data[0] - 1];
    if (!muDoubleScalarIsNaN(maxX)) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &wh_emlrtRSI;
      overflow = ((2 <= r8->size[0]) && (r8->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= r8->size[0])) {
        if (!muDoubleScalarIsNaN(boundaryPixelsUndistorted->data[r8->data[k - 1]
             - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      g_st.site = &fh_emlrtRSI;
      maxX = boundaryPixelsUndistorted->data[r8->data[idx - 1] - 1];
      a = idx + 1;
      h_st.site = &gh_emlrtRSI;
      overflow = ((idx + 1 <= r8->size[0]) && (r8->size[0] > 2147483646));
      if (overflow) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = a; k <= n; k++) {
        d = boundaryPixelsUndistorted->data[r8->data[k - 1] - 1];
        if (maxX > d) {
          maxX = d;
        }
      }
    }
  }

  emxFree_int32_T(&r8);
  emxFree_real_T(&boundaryPixelsUndistorted);
  minX = muDoubleScalarCeil(minX);
  maxX = muDoubleScalarFloor(maxX);
  xBounds[0] = minX;
  xBounds[1] = maxX;
  sort(xBounds);
  ex = muDoubleScalarCeil(ex);
  maxY = muDoubleScalarFloor(maxY);
  yBounds[0] = ex;
  yBounds[1] = maxY;
  sort(yBounds);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

c_vision_internal_calibration_C *d_CameraParametersImpl_CameraPa(const
  emlrtStack *sp, c_vision_internal_calibration_C *this, const real_T
  varargin_1_RadialDistortion[2], const real_T varargin_1_TangentialDistortion[2],
  const real_T varargin_1_ImageSize[2], real_T c_varargin_1_NumRadialDistortio,
  const real_T varargin_1_RotationVectors[84], const real_T
  varargin_1_TranslationVectors[84], const real_T varargin_1_IntrinsicMatrix[9])
{
  c_vision_internal_calibration_C *b_this;
  int32_T k;
  real_T c_this[2];
  real_T rotationVectors[84];
  boolean_T p;
  boolean_T exitg1;
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
  b_this = this;
  st.site = &kc_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  st.site = &lc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  c_CameraParametersImpl_checkInt(&b_st, varargin_1_IntrinsicMatrix);
  for (k = 0; k < 3; k++) {
    b_this->IntrinsicMatrixInternal[3 * k] = varargin_1_IntrinsicMatrix[k];
    b_this->IntrinsicMatrixInternal[3 * k + 1] = varargin_1_IntrinsicMatrix[k +
      3];
    b_this->IntrinsicMatrixInternal[3 * k + 2] = varargin_1_IntrinsicMatrix[k +
      6];
  }

  b_this->RadialDistortion[0] = varargin_1_RadialDistortion[0];
  b_this->RadialDistortion[1] = varargin_1_RadialDistortion[1];
  c_this[0] = b_this->RadialDistortion[0];
  c_this[1] = b_this->RadialDistortion[1];
  b_st.site = &oc_emlrtRSI;
  c_CameraParametersImpl_checkRad(&b_st, c_this);
  b_this->TangentialDistortion[0] = varargin_1_TangentialDistortion[0];
  b_this->TangentialDistortion[1] = varargin_1_TangentialDistortion[1];
  c_this[0] = b_this->TangentialDistortion[0];
  c_this[1] = b_this->TangentialDistortion[1];
  b_st.site = &pc_emlrtRSI;
  c_CameraParametersImpl_checkTan(&b_st, c_this);
  b_st.site = &qc_emlrtRSI;
  c_st.site = &yc_emlrtRSI;
  c_CameraParametersImpl_checkIma(&c_st, varargin_1_ImageSize);
  b_this->ImageSize[0] = varargin_1_ImageSize[0];
  b_this->ImageSize[1] = varargin_1_ImageSize[1];
  c_this[0] = b_this->ImageSize[0];
  c_this[1] = b_this->ImageSize[1];
  b_st.site = &rc_emlrtRSI;
  c_CameraParametersImpl_checkIma(&b_st, c_this);
  for (k = 0; k < 84; k++) {
    b_this->RotationVectors[k] = varargin_1_RotationVectors[k];
  }

  b_st.site = &sc_emlrtRSI;
  for (k = 0; k < 84; k++) {
    rotationVectors[k] = b_this->RotationVectors[k];
  }

  c_st.site = &bd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 84)) {
    if ((!muDoubleScalarIsInf(rotationVectors[k])) && (!muDoubleScalarIsNaN
         (rotationVectors[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 15, "RotationVectors");
  }

  for (k = 0; k < 84; k++) {
    b_this->TranslationVectors[k] = varargin_1_TranslationVectors[k];
  }

  b_st.site = &tc_emlrtRSI;
  for (k = 0; k < 84; k++) {
    rotationVectors[k] = b_this->TranslationVectors[k];
  }

  c_st.site = &cd_emlrtRSI;
  d_st.site = &yb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 84)) {
    if ((!muDoubleScalarIsInf(rotationVectors[k])) && (!muDoubleScalarIsNaN
         (rotationVectors[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedFinite",
      "MATLAB:cameraParameters:expectedFinite", 3, 4, 18, "TranslationVectors");
  }

  b_this->NumRadialDistortionCoefficients = c_varargin_1_NumRadialDistortio;
  b_st.site = &uc_emlrtRSI;
  c_CameraParametersImpl_checkNum(&b_st, b_this->NumRadialDistortionCoefficients);
  st.site = &mc_emlrtRSI;
  c_ImageTransformer_ImageTransfo(&st, &b_this->UndistortMap);
  return b_this;
}

/* End of code generation (CameraParametersImpl.c) */
