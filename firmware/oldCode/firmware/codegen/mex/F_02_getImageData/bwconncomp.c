/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwconncomp.c
 *
 * Code generation for function 'bwconncomp'
 *
 */

/* Include files */
#include "bwconncomp.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo om_emlrtRSI = { 23, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo pm_emlrtRSI = { 44, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo qm_emlrtRSI = { 57, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo rm_emlrtRSI = { 69, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo sm_emlrtRSI = { 70, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo tm_emlrtRSI = { 71, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo um_emlrtRSI = { 79, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pathName */
};

static emlrtRSInfo vm_emlrtRSI = { 33, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo wm_emlrtRSI = { 51, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo xm_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo ym_emlrtRSI = { 149,/* lineNo */
  "uf_new_pair",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo an_emlrtRSI = { 150,/* lineNo */
  "uf_new_pair",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo bn_emlrtRSI = { 153,/* lineNo */
  "uf_new_pair",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pathName */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  171,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  167,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  170,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_union",                          /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  183,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  79,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "uf_find_root",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  238,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  235,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  234,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 69,  /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 69,  /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  233,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  232,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  228,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "fillRunVectors",                    /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 55,  /* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  204,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "numberOfRuns",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  204,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "numberOfRuns",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 48,  /* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  198,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "numberOfRuns",                      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  82,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo pi_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo ri_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo si_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo ti_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = { 69,/* lineNo */
  31,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo vi_emlrtRTEI = { 70,/* lineNo */
  46,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo wi_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo xi_emlrtRTEI = { 89,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo yi_emlrtRTEI = { 11,/* lineNo */
  6,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo aj_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/bwconncomp.m"/* pName */
};

static emlrtRTEInfo bj_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo cj_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo dj_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/+images/+internal/+coder/intermediateLabelRuns.m"/* pName */
};

/* Function Definitions */
void bwconncomp(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
                real_T *CC_Connectivity, real_T CC_ImageSize[2], real_T
                *CC_NumObjects, emxArray_real_T *CC_RegionIndices,
                emxArray_int32_T *CC_RegionLengths)
{
  int32_T numRuns;
  int32_T i;
  int32_T lastRunOnPreviousColumn;
  emxArray_int32_T *startRow;
  emxArray_int32_T *endRow;
  int32_T firstRunOnThisColumn;
  emxArray_int32_T *startCol;
  int32_T k;
  int32_T currentColumn;
  emxArray_int32_T *labelsRenumbered;
  int32_T runCounter;
  real_T numComponents;
  int32_T row;
  boolean_T exitg1;
  emlrtStack *r;
  real_T d;
  emxArray_int32_T *pixelIdxList;
  emxArray_int32_T *x;
  int32_T p;
  emxArray_int32_T *idxCount;
  int32_T root_k;
  int32_T exitg2;
  int32_T root_p;
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
  st.site = &om_emlrtRSI;
  b_st.site = &vm_emlrtRSI;
  numRuns = 0;
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    i = varargin_1->size[1];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < i;
         lastRunOnPreviousColumn++) {
      firstRunOnThisColumn = lastRunOnPreviousColumn + 1;
      if ((firstRunOnThisColumn < 1) || (firstRunOnThisColumn > varargin_1->
           size[1])) {
        emlrtDynamicBoundsCheckR2012b(firstRunOnThisColumn, 1, varargin_1->size
          [1], &td_emlrtBCI, &b_st);
      }

      if (varargin_1->data[varargin_1->size[0] * (firstRunOnThisColumn - 1)]) {
        numRuns++;
      }

      firstRunOnThisColumn = varargin_1->size[0];
      for (k = 0; k <= firstRunOnThisColumn - 2; k++) {
        currentColumn = lastRunOnPreviousColumn + 1;
        if ((currentColumn < 1) || (currentColumn > varargin_1->size[1])) {
          emlrtDynamicBoundsCheckR2012b(currentColumn, 1, varargin_1->size[1],
            &sd_emlrtBCI, &b_st);
        }

        runCounter = k + 2;
        if ((runCounter < 1) || (runCounter > varargin_1->size[0])) {
          emlrtDynamicBoundsCheckR2012b(runCounter, 1, varargin_1->size[0],
            &sd_emlrtBCI, &b_st);
        }

        if (varargin_1->data[(runCounter + varargin_1->size[0] * (currentColumn
              - 1)) - 1]) {
          currentColumn = lastRunOnPreviousColumn + 1;
          if ((currentColumn < 1) || (currentColumn > varargin_1->size[1])) {
            emlrtDynamicBoundsCheckR2012b(currentColumn, 1, varargin_1->size[1],
              &rd_emlrtBCI, &b_st);
          }

          runCounter = k + 1;
          if ((runCounter < 1) || (runCounter > varargin_1->size[0])) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, varargin_1->size[0],
              &rd_emlrtBCI, &b_st);
          }

          if (!varargin_1->data[(runCounter + varargin_1->size[0] *
                                 (currentColumn - 1)) - 1]) {
            numRuns++;
          }
        }
      }
    }
  }

  emxInit_int32_T(&st, &startRow, 1, &bj_emlrtRTEI, true);
  emxInit_int32_T(&st, &endRow, 1, &cj_emlrtRTEI, true);
  emxInit_int32_T(&st, &startCol, 1, &dj_emlrtRTEI, true);
  if (numRuns == 0) {
    startRow->size[0] = 0;
    endRow->size[0] = 0;
    startCol->size[0] = 0;
    CC_RegionLengths->size[0] = 0;
  } else {
    if (numRuns < 0) {
      emlrtNonNegativeCheckR2012b(numRuns, &j_emlrtDCI, &st);
    }

    i = startRow->size[0];
    startRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, startRow, i, &pi_emlrtRTEI);
    i = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, endRow, i, &pi_emlrtRTEI);
    i = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, startCol, i, &pi_emlrtRTEI);
    b_st.site = &wm_emlrtRSI;
    currentColumn = varargin_1->size[0];
    runCounter = 1;
    i = varargin_1->size[1];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < i;
         lastRunOnPreviousColumn++) {
      row = 1;
      while (row <= currentColumn) {
        exitg1 = false;
        while ((!exitg1) && (row <= currentColumn)) {
          firstRunOnThisColumn = lastRunOnPreviousColumn + 1;
          if ((firstRunOnThisColumn < 1) || (firstRunOnThisColumn >
               varargin_1->size[1])) {
            emlrtDynamicBoundsCheckR2012b(firstRunOnThisColumn, 1,
              varargin_1->size[1], &md_emlrtBCI, &b_st);
          }

          if ((row < 1) || (row > varargin_1->size[0])) {
            emlrtDynamicBoundsCheckR2012b(row, 1, varargin_1->size[0],
              &md_emlrtBCI, &b_st);
          }

          if (!varargin_1->data[(row + varargin_1->size[0] *
                                 (firstRunOnThisColumn - 1)) - 1]) {
            row++;
          } else {
            exitg1 = true;
          }
        }

        if (row <= currentColumn) {
          firstRunOnThisColumn = lastRunOnPreviousColumn + 1;
          if ((firstRunOnThisColumn < 1) || (firstRunOnThisColumn >
               varargin_1->size[1])) {
            emlrtDynamicBoundsCheckR2012b(firstRunOnThisColumn, 1,
              varargin_1->size[1], &ld_emlrtBCI, &b_st);
          }

          if (row > varargin_1->size[0]) {
            emlrtDynamicBoundsCheckR2012b(row, 1, varargin_1->size[0],
              &ld_emlrtBCI, &b_st);
          }

          if (varargin_1->data[(row + varargin_1->size[0] *
                                (firstRunOnThisColumn - 1)) - 1]) {
            if ((runCounter < 1) || (runCounter > startCol->size[0])) {
              emlrtDynamicBoundsCheckR2012b(runCounter, 1, startCol->size[0],
                &kd_emlrtBCI, &b_st);
            }

            startCol->data[runCounter - 1] = lastRunOnPreviousColumn + 1;
            if (runCounter > startRow->size[0]) {
              emlrtDynamicBoundsCheckR2012b(runCounter, 1, startRow->size[0],
                &jd_emlrtBCI, &b_st);
            }

            startRow->data[runCounter - 1] = row;
            exitg1 = false;
            while ((!exitg1) && (row <= currentColumn)) {
              firstRunOnThisColumn = lastRunOnPreviousColumn + 1;
              if ((firstRunOnThisColumn < 1) || (firstRunOnThisColumn >
                   varargin_1->size[1])) {
                emlrtDynamicBoundsCheckR2012b(firstRunOnThisColumn, 1,
                  varargin_1->size[1], &cd_emlrtBCI, &b_st);
              }

              if ((row < 1) || (row > varargin_1->size[0])) {
                emlrtDynamicBoundsCheckR2012b(row, 1, varargin_1->size[0],
                  &cd_emlrtBCI, &b_st);
              }

              if (varargin_1->data[(row + varargin_1->size[0] *
                                    (firstRunOnThisColumn - 1)) - 1]) {
                row++;
              } else {
                exitg1 = true;
              }
            }

            if (runCounter > endRow->size[0]) {
              emlrtDynamicBoundsCheckR2012b(runCounter, 1, endRow->size[0],
                &bd_emlrtBCI, &b_st);
            }

            endRow->data[runCounter - 1] = row - 1;
            runCounter++;
          }
        }
      }
    }

    i = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = numRuns;
    emxEnsureCapacity_int32_T(&st, CC_RegionLengths, i, &si_emlrtRTEI);
    for (i = 0; i < numRuns; i++) {
      CC_RegionLengths->data[i] = 0;
    }

    k = 1;
    currentColumn = 1;
    runCounter = 1;
    row = -1;
    lastRunOnPreviousColumn = -1;
    firstRunOnThisColumn = 1;
    while (k <= numRuns) {
      if ((k < 1) || (k > startCol->size[0])) {
        emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &id_emlrtBCI, &st);
      }

      i = startCol->data[k - 1];
      if (i == currentColumn + 1) {
        row = firstRunOnThisColumn;
        firstRunOnThisColumn = k;
        lastRunOnPreviousColumn = k - 1;
        if (k > startCol->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &ad_emlrtBCI,
            &st);
        }

        currentColumn = i;
      } else {
        if (k > startCol->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &hd_emlrtBCI,
            &st);
        }

        if (i > currentColumn + 1) {
          row = -1;
          lastRunOnPreviousColumn = -1;
          firstRunOnThisColumn = k;
          if (k > startCol->size[0]) {
            emlrtDynamicBoundsCheckR2012b(k, 1, startCol->size[0], &yc_emlrtBCI,
              &st);
          }

          currentColumn = i;
        }
      }

      if (row >= 0) {
        for (p = row; p <= lastRunOnPreviousColumn; p++) {
          if ((p < 1) || (p > startRow->size[0])) {
            emlrtDynamicBoundsCheckR2012b(p, 1, startRow->size[0], &uc_emlrtBCI,
              &st);
          }

          if (k > endRow->size[0]) {
            emlrtDynamicBoundsCheckR2012b(k, 1, endRow->size[0], &vc_emlrtBCI,
              &st);
          }

          if (endRow->data[k - 1] >= startRow->data[p - 1] - 1) {
            if (p > endRow->size[0]) {
              emlrtDynamicBoundsCheckR2012b(p, 1, endRow->size[0], &sc_emlrtBCI,
                &st);
            }

            if (k > startRow->size[0]) {
              emlrtDynamicBoundsCheckR2012b(k, 1, startRow->size[0],
                &tc_emlrtBCI, &st);
            }

            if (startRow->data[k - 1] <= endRow->data[p - 1] + 1) {
              if (k > CC_RegionLengths->size[0]) {
                emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
                  &rc_emlrtBCI, &st);
              }

              i = CC_RegionLengths->data[k - 1];
              if (i == 0) {
                if (k > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
                    &nc_emlrtBCI, &st);
                }

                if (p > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, CC_RegionLengths->size[0],
                    &oc_emlrtBCI, &st);
                }

                CC_RegionLengths->data[k - 1] = CC_RegionLengths->data[p - 1];
                runCounter++;
              } else {
                if (p > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, CC_RegionLengths->size[0],
                    &pc_emlrtBCI, &st);
                }

                if (k > CC_RegionLengths->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
                    &qc_emlrtBCI, &st);
                }

                if (i != CC_RegionLengths->data[p - 1]) {
                  b_st.site = &xm_emlrtRSI;
                  c_st.site = &ym_emlrtRSI;
                  root_k = k;
                  do {
                    exitg2 = 0;
                    if ((root_k < 1) || (root_k > CC_RegionLengths->size[0])) {
                      emlrtDynamicBoundsCheckR2012b(root_k, 1,
                        CC_RegionLengths->size[0], &lc_emlrtBCI, &c_st);
                    }

                    i = CC_RegionLengths->data[root_k - 1];
                    if (root_k != i) {
                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &jc_emlrtBCI, &c_st);
                      }

                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &kc_emlrtBCI, &c_st);
                      }

                      if ((i < 1) || (i > CC_RegionLengths->size[0])) {
                        emlrtDynamicBoundsCheckR2012b(CC_RegionLengths->
                          data[root_k - 1], 1, CC_RegionLengths->size[0],
                          &kc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_k - 1] =
                        CC_RegionLengths->data[i - 1];
                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &hc_emlrtBCI, &c_st);
                      }

                      root_k = CC_RegionLengths->data[root_k - 1];
                    } else {
                      exitg2 = 1;
                    }
                  } while (exitg2 == 0);

                  c_st.site = &an_emlrtRSI;
                  root_p = p;
                  do {
                    exitg2 = 0;
                    if ((root_p < 1) || (root_p > CC_RegionLengths->size[0])) {
                      emlrtDynamicBoundsCheckR2012b(root_p, 1,
                        CC_RegionLengths->size[0], &lc_emlrtBCI, &c_st);
                    }

                    i = CC_RegionLengths->data[root_p - 1];
                    if (root_p != i) {
                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &jc_emlrtBCI, &c_st);
                      }

                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &kc_emlrtBCI, &c_st);
                      }

                      if ((i < 1) || (i > CC_RegionLengths->size[0])) {
                        emlrtDynamicBoundsCheckR2012b(CC_RegionLengths->
                          data[root_p - 1], 1, CC_RegionLengths->size[0],
                          &kc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_p - 1] =
                        CC_RegionLengths->data[i - 1];
                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &hc_emlrtBCI, &c_st);
                      }

                      root_p = CC_RegionLengths->data[root_p - 1];
                    } else {
                      exitg2 = 1;
                    }
                  } while (exitg2 == 0);

                  if (root_k != root_p) {
                    c_st.site = &bn_emlrtRSI;
                    if (root_p < root_k) {
                      if (root_k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_k, 1,
                          CC_RegionLengths->size[0], &ec_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_k - 1] = root_p;
                      if (k > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(k, 1,
                          CC_RegionLengths->size[0], &cc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[k - 1] = root_p;
                    } else {
                      if (root_p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(root_p, 1,
                          CC_RegionLengths->size[0], &fc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[root_p - 1] = root_k;
                      if (p > CC_RegionLengths->size[0]) {
                        emlrtDynamicBoundsCheckR2012b(p, 1,
                          CC_RegionLengths->size[0], &dc_emlrtBCI, &c_st);
                      }

                      CC_RegionLengths->data[p - 1] = root_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      if (k > CC_RegionLengths->size[0]) {
        emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
          &xc_emlrtBCI, &st);
      }

      if (CC_RegionLengths->data[k - 1] == 0) {
        if (k > CC_RegionLengths->size[0]) {
          emlrtDynamicBoundsCheckR2012b(k, 1, CC_RegionLengths->size[0],
            &wc_emlrtBCI, &st);
        }

        CC_RegionLengths->data[k - 1] = runCounter;
        runCounter++;
      }

      k++;
    }
  }

  if (numRuns == 0) {
    CC_ImageSize[0] = varargin_1->size[0];
    CC_ImageSize[1] = varargin_1->size[1];
    currentColumn = 0;
    CC_RegionIndices->size[0] = 0;
    i = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity_int32_T(sp, CC_RegionLengths, i, &ri_emlrtRTEI);
    CC_RegionLengths->data[0] = 0;
  } else {
    emxInit_int32_T(sp, &labelsRenumbered, 1, &aj_emlrtRTEI, true);
    i = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(sp, labelsRenumbered, i, &qi_emlrtRTEI);
    numComponents = 0.0;
    st.site = &pm_emlrtRSI;
    for (k = 0; k < numRuns; k++) {
      i = k + 1;
      if (i > CC_RegionLengths->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, CC_RegionLengths->size[0],
          &qd_emlrtBCI, sp);
      }

      if (CC_RegionLengths->data[i - 1] == k + 1) {
        numComponents++;
        i = k + 1;
        if (i > labelsRenumbered->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, labelsRenumbered->size[0],
            &nd_emlrtBCI, sp);
        }

        labelsRenumbered->data[i - 1] = (int32_T)numComponents;
      }

      i = k + 1;
      if (i > labelsRenumbered->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, labelsRenumbered->size[0],
          &od_emlrtBCI, sp);
      }

      firstRunOnThisColumn = k + 1;
      if (firstRunOnThisColumn > CC_RegionLengths->size[0]) {
        emlrtDynamicBoundsCheckR2012b(firstRunOnThisColumn, 1,
          CC_RegionLengths->size[0], &pd_emlrtBCI, sp);
      }

      currentColumn = CC_RegionLengths->data[firstRunOnThisColumn - 1];
      if ((currentColumn < 1) || (currentColumn > labelsRenumbered->size[0])) {
        emlrtDynamicBoundsCheckR2012b(CC_RegionLengths->
          data[firstRunOnThisColumn - 1], 1, labelsRenumbered->size[0],
          &pd_emlrtBCI, sp);
      }

      labelsRenumbered->data[i - 1] = labelsRenumbered->data[currentColumn - 1];
    }

    i = (int32_T)numComponents;
    if (numComponents != i) {
      emlrtIntegerCheckR2012b(numComponents, &i_emlrtDCI, sp);
    }

    runCounter = (int32_T)numComponents;
    firstRunOnThisColumn = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = (int32_T)numComponents;
    emxEnsureCapacity_int32_T(sp, CC_RegionLengths, firstRunOnThisColumn,
      &ti_emlrtRTEI);
    if ((int32_T)numComponents != i) {
      emlrtIntegerCheckR2012b(numComponents, &i_emlrtDCI, sp);
    }

    for (i = 0; i < runCounter; i++) {
      CC_RegionLengths->data[i] = 0;
    }

    st.site = &qm_emlrtRSI;
    for (k = 0; k < numRuns; k++) {
      i = k + 1;
      if (i > labelsRenumbered->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, labelsRenumbered->size[0],
          &ud_emlrtBCI, sp);
      }

      if (labelsRenumbered->data[k] > 0) {
        if ((labelsRenumbered->data[k] < 1) || (labelsRenumbered->data[k] >
             CC_RegionLengths->size[0])) {
          emlrtDynamicBoundsCheckR2012b(labelsRenumbered->data[k], 1,
            CC_RegionLengths->size[0], &dd_emlrtBCI, sp);
        }

        i = k + 1;
        if (i > startRow->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, startRow->size[0], &ed_emlrtBCI,
            sp);
        }

        firstRunOnThisColumn = k + 1;
        if (firstRunOnThisColumn > endRow->size[0]) {
          emlrtDynamicBoundsCheckR2012b(firstRunOnThisColumn, 1, endRow->size[0],
            &fd_emlrtBCI, sp);
        }

        if ((labelsRenumbered->data[k] < 1) || (labelsRenumbered->data[k] >
             CC_RegionLengths->size[0])) {
          emlrtDynamicBoundsCheckR2012b(labelsRenumbered->data[k], 1,
            CC_RegionLengths->size[0], &gd_emlrtBCI, sp);
        }

        CC_RegionLengths->data[labelsRenumbered->data[k] - 1] =
          ((CC_RegionLengths->data[labelsRenumbered->data[k] - 1] + endRow->
            data[firstRunOnThisColumn - 1]) - startRow->data[i - 1]) + 1;
      }
    }

    st.site = &rm_emlrtRSI;
    r = &st;
    d = sum(r, CC_RegionLengths);
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &g_emlrtDCI, &st);
    }

    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &h_emlrtDCI, &st);
    }

    emxInit_int32_T(&st, &pixelIdxList, 1, &yi_emlrtRTEI, true);
    emxInit_int32_T(&st, &x, 1, &vi_emlrtRTEI, true);
    i = pixelIdxList->size[0];
    pixelIdxList->size[0] = (int32_T)d;
    emxEnsureCapacity_int32_T(&st, pixelIdxList, i, &ui_emlrtRTEI);
    b_st.site = &sm_emlrtRSI;
    i = x->size[0];
    x->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(&b_st, x, i, &vi_emlrtRTEI);
    runCounter = CC_RegionLengths->size[0];
    for (i = 0; i < runCounter; i++) {
      x->data[i] = CC_RegionLengths->data[i];
    }

    c_st.site = &gn_emlrtRSI;
    currentColumn = 2;
    if (CC_RegionLengths->size[0] != 1) {
      currentColumn = 1;
    }

    d_st.site = &hn_emlrtRSI;
    if ((1 == currentColumn) && (CC_RegionLengths->size[0] != 0) &&
        (CC_RegionLengths->size[0] != 1)) {
      currentColumn = CC_RegionLengths->size[0];
      for (k = 0; k <= currentColumn - 2; k++) {
        x->data[k + 1] += x->data[k];
      }
    }

    emxInit_int32_T(&d_st, &idxCount, 1, &wi_emlrtRTEI, true);
    i = idxCount->size[0];
    idxCount->size[0] = x->size[0] + 1;
    emxEnsureCapacity_int32_T(&st, idxCount, i, &wi_emlrtRTEI);
    idxCount->data[0] = 0;
    runCounter = x->size[0];
    for (i = 0; i < runCounter; i++) {
      idxCount->data[i + 1] = x->data[i];
    }

    emxFree_int32_T(&x);
    b_st.site = &tm_emlrtRSI;
    for (k = 0; k < numRuns; k++) {
      i = k + 1;
      if (i > startCol->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, startCol->size[0], &vd_emlrtBCI, &st);
      }

      row = (startCol->data[k] - 1) * varargin_1->size[0];
      i = k + 1;
      if (i > labelsRenumbered->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, labelsRenumbered->size[0],
          &mc_emlrtBCI, &st);
      }

      lastRunOnPreviousColumn = labelsRenumbered->data[i - 1];
      if (labelsRenumbered->data[k] > 0) {
        i = k + 1;
        if (i > startRow->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, startRow->size[0], &ic_emlrtBCI,
            &st);
        }

        firstRunOnThisColumn = startRow->data[i - 1];
        i = k + 1;
        if (i > endRow->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, endRow->size[0], &gc_emlrtBCI, &st);
        }

        currentColumn = endRow->data[i - 1];
        b_st.site = &um_emlrtRSI;
        for (runCounter = firstRunOnThisColumn; runCounter <= currentColumn;
             runCounter++) {
          if ((lastRunOnPreviousColumn < 1) || (lastRunOnPreviousColumn >
               idxCount->size[0])) {
            emlrtDynamicBoundsCheckR2012b(lastRunOnPreviousColumn, 1,
              idxCount->size[0], &wd_emlrtBCI, &st);
          }

          if (lastRunOnPreviousColumn > idxCount->size[0]) {
            emlrtDynamicBoundsCheckR2012b(lastRunOnPreviousColumn, 1,
              idxCount->size[0], &bc_emlrtBCI, &st);
          }

          idxCount->data[lastRunOnPreviousColumn - 1]++;
          if (lastRunOnPreviousColumn > idxCount->size[0]) {
            emlrtDynamicBoundsCheckR2012b(lastRunOnPreviousColumn, 1,
              idxCount->size[0], &ac_emlrtBCI, &st);
          }

          if ((idxCount->data[lastRunOnPreviousColumn - 1] < 1) ||
              (idxCount->data[lastRunOnPreviousColumn - 1] > pixelIdxList->size
               [0])) {
            emlrtDynamicBoundsCheckR2012b(idxCount->data[lastRunOnPreviousColumn
              - 1], 1, pixelIdxList->size[0], &ac_emlrtBCI, &st);
          }

          pixelIdxList->data[idxCount->data[lastRunOnPreviousColumn - 1] - 1] =
            runCounter + row;
        }
      }
    }

    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    CC_ImageSize[0] = varargin_1->size[0];
    CC_ImageSize[1] = varargin_1->size[1];
    currentColumn = (int32_T)numComponents;
    i = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity_real_T(&st, CC_RegionIndices, i, &xi_emlrtRTEI);
    runCounter = pixelIdxList->size[0];
    for (i = 0; i < runCounter; i++) {
      CC_RegionIndices->data[i] = pixelIdxList->data[i];
    }

    emxFree_int32_T(&pixelIdxList);
  }

  emxFree_int32_T(&startCol);
  emxFree_int32_T(&endRow);
  emxFree_int32_T(&startRow);
  *CC_Connectivity = 8.0;
  *CC_NumObjects = currentColumn;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bwconncomp.c) */
