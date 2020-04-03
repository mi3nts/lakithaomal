/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * F_02_getImageData_data.c
 *
 * Code generation for function 'F_02_getImageData_data'
 *
 */

/* Include files */
#include "F_02_getImageData_data.h"
#include "F_02_getImageData.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "F_02_getImageData",                 /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 933878966U, 2751585356U, 3052266547U, 2808075253U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo o_emlrtRSI = { 74,         /* lineNo */
  "StereoParametersImpl/StereoParametersImpl",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 62,         /* lineNo */
  "RectificationParameters/RectificationParameters",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/RectificationParameters.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 21,        /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo yb_emlrtRSI = { 76,        /* lineNo */
  "validateattributes",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 221,       /* lineNo */
  "charcmp",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/strcmp.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 16,        /* lineNo */
  "lower",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/lower.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 10,        /* lineNo */
  "eml_string_transform",              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/strfun/eml_string_transform.m"/* pathName */
};

emlrtRSInfo md_emlrtRSI = { 105,       /* lineNo */
  "imread",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pathName */
};

emlrtRSInfo td_emlrtRSI = { 89,        /* lineNo */
  "ImageTransformer/update",           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

emlrtRSInfo de_emlrtRSI = { 28,        /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo ee_emlrtRSI = { 103,       /* lineNo */
  "colon",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo ge_emlrtRSI = { 306,       /* lineNo */
  "eml_float_colon",                   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/colon.m"/* pathName */
};

emlrtRSInfo je_emlrtRSI = { 22,        /* lineNo */
  "cat",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo ke_emlrtRSI = { 102,       /* lineNo */
  "cat_impl",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

emlrtRSInfo se_emlrtRSI = { 55,        /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

emlrtRSInfo we_emlrtRSI = { 18,        /* lineNo */
  "reshapeSizeChecks",                 /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"/* pathName */
};

emlrtRSInfo ye_emlrtRSI = { 32,        /* lineNo */
  "interp2d",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/interp2d.m"/* pathName */
};

emlrtRSInfo af_emlrtRSI = { 34,        /* lineNo */
  "interp2d",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/interp2d.m"/* pathName */
};

emlrtRSInfo bf_emlrtRSI = { 98,        /* lineNo */
  "interp2d",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/interp2d.m"/* pathName */
};

emlrtRSInfo pf_emlrtRSI = { 103,       /* lineNo */
  "flatVectorAllOrAny",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

emlrtRSInfo pg_emlrtRSI = { 23,        /* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"/* pathName */
};

emlrtRSInfo wg_emlrtRSI = { 28,        /* lineNo */
  "xrotg",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

emlrtRSInfo xg_emlrtRSI = { 27,        /* lineNo */
  "xrotg",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/xrotg.m"/* pathName */
};

emlrtRSInfo ch_emlrtRSI = { 17,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo hh_emlrtRSI = { 591,       /* lineNo */
  "computeRowAlignmentRotation",       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

emlrtRSInfo jh_emlrtRSI = { 25,        /* lineNo */
  "dot",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/specfun/dot.m"/* pathName */
};

emlrtRSInfo kh_emlrtRSI = { 104,       /* lineNo */
  "vdotp",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/specfun/dot.m"/* pathName */
};

emlrtRSInfo lh_emlrtRSI = { 89,        /* lineNo */
  "vdot",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/specfun/dot.m"/* pathName */
};

emlrtRSInfo mh_emlrtRSI = { 49,        /* lineNo */
  "xdot",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/xdot.m"/* pathName */
};

emlrtRSInfo nh_emlrtRSI = { 371,       /* lineNo */
  "StereoParametersImpl/computeNewIntrinsics",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

emlrtRSInfo oh_emlrtRSI = { 372,       /* lineNo */
  "StereoParametersImpl/computeNewIntrinsics",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

emlrtRSInfo ph_emlrtRSI = { 377,       /* lineNo */
  "StereoParametersImpl/computeNewIntrinsics",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/StereoParametersImpl.m"/* pathName */
};

emlrtRSInfo qh_emlrtRSI = { 14,        /* lineNo */
  "min",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

emlrtRSInfo rh_emlrtRSI = { 20,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo sh_emlrtRSI = { 45,        /* lineNo */
  "unaryOrBinaryDispatch",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo aj_emlrtRSI = { 979,       /* lineNo */
  "CameraParametersImpl/computeUndistortBounds",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/CameraParametersImpl.m"/* pathName */
};

emlrtRSInfo uj_emlrtRSI = { 33,        /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

emlrtRSInfo wj_emlrtRSI = { 110,       /* lineNo */
  "ImageTransformer/transformImage",   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pathName */
};

emlrtRSInfo xk_emlrtRSI = { 28,        /* lineNo */
  "repmat",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

emlrtRSInfo dl_emlrtRSI = { 14,        /* lineNo */
  "max",                               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

emlrtRSInfo en_emlrtRSI = { 124,       /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo fn_emlrtRSI = { 184,       /* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo gn_emlrtRSI = { 14,        /* lineNo */
  "cumsum",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/cumsum.m"/* pathName */
};

emlrtRSInfo hn_emlrtRSI = { 16,        /* lineNo */
  "cumop",                             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

emlrtRSInfo lo_emlrtRSI = { 355,       /* lineNo */
  "projective2d/get.Tinv",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/projective2d.m"/* pathName */
};

emlrtRSInfo po_emlrtRSI = { 102,       /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"/* pathName */
};

emlrtRSInfo so_emlrtRSI = { 228,       /* lineNo */
  "mtimes",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"/* pathName */
};

emlrtRSInfo uo_emlrtRSI = { 48,        /* lineNo */
  "rgb2gray",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/images/rgb2gray.m"/* pathName */
};

emlrtRTEInfo e_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validatefinite.m"/* pName */
};

emlrtRTEInfo f_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"/* pName */
};

emlrtRTEInfo i_emlrtRTEI = { 13,       /* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validateinteger.m"/* pName */
};

emlrtRTEInfo j_emlrtRTEI = { 14,       /* lineNo */
  37,                                  /* colNo */
  "validatepositive",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validatepositive.m"/* pName */
};

emlrtRTEInfo q_emlrtRTEI = { 283,      /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo r_emlrtRTEI = { 59,       /* lineNo */
  23,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"/* pName */
};

emlrtRTEInfo t_emlrtRTEI = { 52,       /* lineNo */
  13,                                  /* colNo */
  "reshapeSizeChecks",                 /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/reshapeSizeChecks.m"/* pName */
};

emlrtRTEInfo x_emlrtRTEI = { 44,       /* lineNo */
  1,                                   /* colNo */
  "interp2d",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/interp2d.m"/* pName */
};

emlrtRTEInfo ab_emlrtRTEI = { 13,      /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

emlrtRTEInfo bb_emlrtRTEI = { 14,      /* lineNo */
  9,                                   /* colNo */
  "acos",                              /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elfun/acos.m"/* pName */
};

emlrtRTEInfo hb_emlrtRTEI = { 26,      /* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

emlrtRTEInfo ib_emlrtRTEI = { 95,      /* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

emlrtRTEInfo jb_emlrtRTEI = { 13,      /* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonempty.m"/* pName */
};

emlrtRTEInfo ob_emlrtRTEI = { 20,      /* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"/* pName */
};

emlrtRTEInfo ad_emlrtRTEI = { 112,     /* lineNo */
  13,                                  /* colNo */
  "RectificationParameters",           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/RectificationParameters.m"/* pName */
};

emlrtRTEInfo bd_emlrtRTEI = { 62,      /* lineNo */
  31,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo cd_emlrtRTEI = { 63,      /* lineNo */
  41,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo dd_emlrtRTEI = { 64,      /* lineNo */
  37,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo ed_emlrtRTEI = { 79,      /* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo fd_emlrtRTEI = { 80,      /* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo gd_emlrtRTEI = { 81,      /* lineNo */
  13,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo id_emlrtRTEI = { 28,      /* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

emlrtRTEInfo jd_emlrtRTEI = { 305,     /* lineNo */
  14,                                  /* colNo */
  "cat",                               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

emlrtRTEInfo af_emlrtRTEI = { 98,      /* lineNo */
  19,                                  /* colNo */
  "interp2d",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/interp2d.m"/* pName */
};

emlrtRTEInfo gf_emlrtRTEI = { 110,     /* lineNo */
  59,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

emlrtRTEInfo hf_emlrtRTEI = { 111,     /* lineNo */
  25,                                  /* colNo */
  "ImageTransformer",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/vision/vision/+vision/+internal/+calibration/ImageTransformer.m"/* pName */
};

const real_T dv[3] = { 480.0, 640.0, 3.0 };

const real_T dv1[3] = { 480.0, 640.0, 1.0 };

covrtInstance emlrtCoverageInstance;

/* End of code generation (F_02_getImageData_data.c) */
