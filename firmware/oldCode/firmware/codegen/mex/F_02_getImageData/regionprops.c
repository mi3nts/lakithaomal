/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * regionprops.c
 *
 * Code generation for function 'regionprops'
 *
 */

/* Include files */
#include "regionprops.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "F_02_getImageData_emxutil.h"
#include "assertValidSizeArg.h"
#include "bwconncomp.h"
#include "eml_int_forloop_overflow_check.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T Circularity;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Variable Definitions */
static emlrtRSInfo hm_emlrtRSI = { 197,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo im_emlrtRSI = { 115,/* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo jm_emlrtRSI = { 99, /* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo km_emlrtRSI = { 78, /* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo lm_emlrtRSI = { 75, /* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo mm_emlrtRSI = { 73, /* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo nm_emlrtRSI = { 32, /* lineNo */
  "regionprops",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo in_emlrtRSI = { 32, /* lineNo */
  "useConstantDim",                    /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/useConstantDim.m"/* pathName */
};

static emlrtRSInfo jn_emlrtRSI = { 99, /* lineNo */
  "ndlooper",                          /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo kn_emlrtRSI = { 125,/* lineNo */
  "looper",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo ln_emlrtRSI = { 290,/* lineNo */
  "vcumop",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/private/cumop.m"/* pathName */
};

static emlrtRSInfo mn_emlrtRSI = { 1291,/* lineNo */
  "parseInputsAndInitializeOutStruct", /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo nn_emlrtRSI = { 1460,/* lineNo */
  "getPropsFromInputAndInitializeOutStruct",/* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo on_emlrtRSI = { 1826,/* lineNo */
  "initializeStatsStruct",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo pn_emlrtRSI = { 295,/* lineNo */
  "ComputePixelIdxList",               /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo qn_emlrtRSI = { 534,/* lineNo */
  "ComputeBoundingBox",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo rn_emlrtRSI = { 544,/* lineNo */
  "ComputeBoundingBox",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo sn_emlrtRSI = { 545,/* lineNo */
  "ComputeBoundingBox",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo tn_emlrtRSI = { 768,/* lineNo */
  "ComputePixelList",                  /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo un_emlrtRSI = { 770,/* lineNo */
  "ComputePixelList",                  /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo vn_emlrtRSI = { 19, /* lineNo */
  "ind2sub",                           /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pathName */
};

static emlrtRSInfo wn_emlrtRSI = { 167,/* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo xn_emlrtRSI = { 326,/* lineNo */
  "unaryMinOrMaxDispatch",             /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo yn_emlrtRSI = { 394,/* lineNo */
  "minOrMax2D",                        /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo ao_emlrtRSI = { 476,/* lineNo */
  "minOrMax2DColumnMajorDim1",         /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo bo_emlrtRSI = { 418,/* lineNo */
  "ComputeCentroid",                   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo co_emlrtRSI = { 422,/* lineNo */
  "ComputeCentroid",                   /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pathName */
};

static emlrtRSInfo do_emlrtRSI = { 49, /* lineNo */
  "mean",                              /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/datafun/mean.m"/* pathName */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1884,                                /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1882,                                /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  540,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "ComputeBoundingBox",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  422,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "ComputeCentroid",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  65,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  298,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelIdxList",               /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1885,                                /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1885,                                /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "populateOutputStatsStructure",      /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  542,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputeBoundingBox",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  422,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "ComputeCentroid",                   /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  546,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputeBoundingBox",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  770,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  772,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ac_emlrtRTEI = { 38,/* lineNo */
  15,                                  /* colNo */
  "ind2sub_indexClass",                /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  768,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  767,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "ComputePixelList",                  /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ii_emlrtRTEI = { 1460,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = { 295,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo ki_emlrtRTEI = { 298,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo li_emlrtRTEI = { 32,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = { 75,/* lineNo */
  2,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = { 220,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo oi_emlrtRTEI = { 234,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo ej_emlrtRTEI = { 1826,/* lineNo */
  1,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo fj_emlrtRTEI = { 1711,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo bm_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo cm_emlrtRTEI = { 772,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRTEInfo dm_emlrtRTEI = { 42,/* lineNo */
  5,                                   /* colNo */
  "ind2sub",                           /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/elmat/ind2sub.m"/* pName */
};

static emlrtRTEInfo em_emlrtRTEI = { 770,/* lineNo */
  13,                                  /* colNo */
  "regionprops",                       /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/images/images/eml/regionprops.m"/* pName */
};

static emlrtRSInfo dr_emlrtRSI = { 18, /* lineNo */
  "indexDivide",                       /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/indexDivide.m"/* pathName */
};

/* Function Declarations */
static void ComputePixelList(const emlrtStack *sp, const real_T imageSize[2],
  b_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);
static void initializeStatsStruct(const emlrtStack *sp, real_T numObjs,
  b_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);

/* Function Definitions */
static void ComputePixelList(const emlrtStack *sp, const real_T imageSize[2],
  b_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  int32_T i;
  emxArray_int32_T *idx;
  emxArray_int32_T *vk;
  int32_T k;
  int32_T i1;
  int32_T hi;
  int32_T loop_ub;
  int32_T hi_tmp;
  int32_T b_k;
  boolean_T exitg1;
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
  if (!statsAlreadyComputed->PixelList) {
    statsAlreadyComputed->PixelList = true;
    i = stats->size[0];
    emxInit_int32_T(sp, &idx, 1, &bm_emlrtRTEI, true);
    emxInit_int32_T(sp, &vk, 1, &dm_emlrtRTEI, true);
    for (k = 0; k < i; k++) {
      i1 = stats->size[0];
      hi = k + 1;
      if ((hi < 1) || (hi > i1)) {
        emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &ee_emlrtBCI, sp);
      }

      if (stats->data[k].PixelIdxList->size[0] != 0) {
        st.site = &tn_emlrtRSI;
        i1 = stats->size[0];
        hi = k + 1;
        if ((hi < 1) || (hi > i1)) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &de_emlrtBCI, &st);
        }

        b_st.site = &vn_emlrtRSI;
        i1 = idx->size[0];
        idx->size[0] = stats->data[k].PixelIdxList->size[0];
        emxEnsureCapacity_int32_T(&b_st, idx, i1, &bm_emlrtRTEI);
        loop_ub = stats->data[k].PixelIdxList->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          idx->data[i1] = (int32_T)stats->data[k].PixelIdxList->data[i1];
        }

        hi_tmp = (int32_T)imageSize[0];
        hi = hi_tmp * (int32_T)imageSize[1];
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) && (b_k <= idx->size[0] - 1)) {
          if ((idx->data[b_k] >= 1) && (idx->data[b_k] <= hi)) {
            b_k++;
          } else {
            emlrtErrorWithMessageIdR2018a(&b_st, &ac_emlrtRTEI,
              "Coder:MATLAB:ind2sub_IndexOutOfRange",
              "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
          }
        }

        loop_ub = idx->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          idx->data[i1]--;
        }

        loop_ub = idx->size[0];
        i1 = vk->size[0];
        vk->size[0] = idx->size[0];
        emxEnsureCapacity_int32_T(&b_st, vk, i1, &dm_emlrtRTEI);
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_st.site = &dr_emlrtRSI;
          vk->data[i1] = div_s32(&c_st, idx->data[i1], hi_tmp);
        }

        loop_ub = idx->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          idx->data[i1] -= vk->data[i1] * hi_tmp;
        }

        loop_ub = idx->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          idx->data[i1]++;
        }

        loop_ub = vk->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          vk->data[i1]++;
        }

        st.site = &un_emlrtRSI;
        b_st.site = &je_emlrtRSI;
        c_st.site = &ke_emlrtRSI;
        loop_ub = vk->size[0];
        if (idx->size[0] != vk->size[0]) {
          emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
            "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
        }

        i1 = stats->size[0];
        hi = (int32_T)(k + 1U);
        if ((hi < 1) || (hi > i1)) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &be_emlrtBCI, &b_st);
        }

        b_k = stats->data[hi - 1].PixelList->size[0] * stats->data[hi - 1].
          PixelList->size[1];
        stats->data[hi - 1].PixelList->size[0] = vk->size[0];
        emxEnsureCapacity_real_T(&b_st, stats->data[hi - 1].PixelList, b_k,
          &em_emlrtRTEI);
        hi = (int32_T)(k + 1U);
        if ((hi < 1) || (hi > i1)) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &be_emlrtBCI, &b_st);
        }

        b_k = stats->data[hi - 1].PixelList->size[0] * stats->data[hi - 1].
          PixelList->size[1];
        stats->data[hi - 1].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(&b_st, stats->data[hi - 1].PixelList, b_k,
          &em_emlrtRTEI);
        for (hi = 0; hi < loop_ub; hi++) {
          b_k = (int32_T)(k + 1U);
          if ((b_k < 1) || (b_k > i1)) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, i1, &be_emlrtBCI, &b_st);
          }

          stats->data[b_k - 1].PixelList->data[hi] = vk->data[hi];
        }

        loop_ub = idx->size[0];
        for (hi = 0; hi < loop_ub; hi++) {
          b_k = (int32_T)(k + 1U);
          if ((b_k < 1) || (b_k > i1)) {
            emlrtDynamicBoundsCheckR2012b(b_k, 1, i1, &be_emlrtBCI, &b_st);
          }

          stats->data[b_k - 1].PixelList->data[hi + stats->data[b_k - 1].
            PixelList->size[0]] = idx->data[hi];
        }
      } else {
        i1 = stats->size[0];
        hi = (int32_T)(k + 1U);
        if ((hi < 1) || (hi > i1)) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &ce_emlrtBCI, sp);
        }

        stats->data[hi - 1].PixelList->size[0] = 0;
        i1 = stats->size[0];
        if (hi > i1) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &ce_emlrtBCI, sp);
        }

        i1 = stats->data[hi - 1].PixelList->size[0] * stats->data[hi - 1].
          PixelList->size[1];
        stats->data[hi - 1].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(sp, stats->data[hi - 1].PixelList, i1,
          &cm_emlrtRTEI);
        i1 = stats->size[0];
        if (hi > i1) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &ce_emlrtBCI, sp);
        }

        i1 = stats->size[0];
        if (hi > i1) {
          emlrtDynamicBoundsCheckR2012b(hi, 1, i1, &ce_emlrtBCI, sp);
        }
      }
    }

    emxFree_int32_T(&vk);
    emxFree_int32_T(&idx);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T b_numerator;
  uint32_T b_denominator;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      b_numerator = ~(uint32_T)numerator + 1U;
    } else {
      b_numerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      b_denominator = ~(uint32_T)denominator + 1U;
    } else {
      b_denominator = (uint32_T)denominator;
    }

    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)b_numerator;
    } else {
      quotient = (int32_T)b_numerator;
    }
  }

  return quotient;
}

static void initializeStatsStruct(const emlrtStack *sp, real_T numObjs,
  b_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  c_struct_T statsOneObj;
  int32_T loop_ub;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInitStruct_struct_T(sp, &statsOneObj, &fj_emlrtRTEI, true);
  statsAlreadyComputed->Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed->Centroid = false;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsAlreadyComputed->BoundingBox = false;
  statsOneObj.BoundingBox[0] = 0.0;
  statsOneObj.BoundingBox[1] = 0.0;
  statsOneObj.BoundingBox[2] = 0.0;
  statsOneObj.BoundingBox[3] = 0.0;
  statsAlreadyComputed->MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed->MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed->Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed->Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed->Image = false;
  statsOneObj.Image->size[0] = 0;
  statsOneObj.Image->size[1] = 0;
  statsAlreadyComputed->FilledImage = false;
  statsOneObj.FilledImage->size[0] = 0;
  statsOneObj.FilledImage->size[1] = 0;
  statsAlreadyComputed->FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed->EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed->Extrema = false;
  memset(&statsOneObj.Extrema[0], 0, 16U * sizeof(real_T));
  statsAlreadyComputed->EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed->Extent = false;
  statsOneObj.Extent = 0.0;
  statsAlreadyComputed->PixelIdxList = false;
  statsOneObj.PixelIdxList->size[0] = 0;
  statsAlreadyComputed->PixelList = false;
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  statsAlreadyComputed->Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed->Circularity = false;
  statsOneObj.Circularity = 0.0;
  statsAlreadyComputed->PixelValues = false;
  statsOneObj.PixelValues->size[0] = 0;
  statsAlreadyComputed->WeightedCentroid = false;
  statsAlreadyComputed->MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed->MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed->MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed->SubarrayIdx = false;
  statsOneObj.SubarrayIdx->size[0] = 1;
  statsOneObj.SubarrayIdx->size[1] = 0;
  statsOneObj.WeightedCentroid[0] = 0.0;
  statsOneObj.SubarrayIdxLengths[0] = 0.0;
  statsOneObj.WeightedCentroid[1] = 0.0;
  statsOneObj.SubarrayIdxLengths[1] = 0.0;
  st.site = &on_emlrtRSI;
  b_st.site = &xk_emlrtRSI;
  b_assertValidSizeArg(&b_st, numObjs);
  loop_ub = (int32_T)numObjs;
  i = stats->size[0];
  stats->size[0] = loop_ub;
  emxEnsureCapacity_struct_T1(&st, stats, i, &ej_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct_T(&st, &stats->data[i], &statsOneObj, &ej_emlrtRTEI);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void regionprops(const emlrtStack *sp, const emxArray_boolean_T *varargin_1,
                 emxArray_struct_T *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *regionLengths;
  real_T min_corner_idx_0;
  real_T CC_ImageSize[2];
  real_T min_corner_idx_1;
  b_struct_T s;
  int32_T vlen;
  int32_T i;
  b_emxArray_struct_T *stats;
  struct_T statsAlreadyComputed;
  emxArray_int32_T *idxCount;
  int32_T k;
  int32_T b_k;
  boolean_T overflow;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  real_T b;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
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
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &CC_RegionIndices, 1, &li_emlrtRTEI, true);
  emxInit_int32_T(sp, &regionLengths, 1, &ni_emlrtRTEI, true);
  st.site = &nm_emlrtRSI;
  bwconncomp(&st, varargin_1, &min_corner_idx_0, CC_ImageSize, &min_corner_idx_1,
             CC_RegionIndices, regionLengths);
  st.site = &mm_emlrtRSI;
  b_st.site = &mn_emlrtRSI;
  c_st.site = &nn_emlrtRSI;
  d_st.site = &xk_emlrtRSI;
  b_assertValidSizeArg(&d_st, min_corner_idx_1);
  s.Centroid[0] = 0.0;
  s.Centroid[1] = 0.0;
  s.BoundingBox[0] = 0.0;
  s.BoundingBox[1] = 0.0;
  s.BoundingBox[2] = 0.0;
  s.BoundingBox[3] = 0.0;
  vlen = (int32_T)min_corner_idx_1;
  i = outstats->size[0];
  outstats->size[0] = vlen;
  emxEnsureCapacity_struct_T(&c_st, outstats, i, &ii_emlrtRTEI);
  for (i = 0; i < vlen; i++) {
    outstats->data[i] = s;
  }

  emxInit_struct_T1(&c_st, &stats, 1, &mi_emlrtRTEI, true);
  st.site = &lm_emlrtRSI;
  initializeStatsStruct(&st, min_corner_idx_1, stats, &statsAlreadyComputed);
  st.site = &km_emlrtRSI;
  statsAlreadyComputed.PixelIdxList = true;
  if (min_corner_idx_1 != 0.0) {
    b_st.site = &pn_emlrtRSI;
    c_st.site = &gn_emlrtRSI;
    vlen = 2;
    if (regionLengths->size[0] != 1) {
      vlen = 1;
    }

    d_st.site = &hn_emlrtRSI;
    if (1 == vlen) {
      e_st.site = &in_emlrtRSI;
      f_st.site = &jn_emlrtRSI;
      if (regionLengths->size[0] != 0) {
        g_st.site = &kn_emlrtRSI;
        if (regionLengths->size[0] != 1) {
          vlen = regionLengths->size[0];
          h_st.site = &ln_emlrtRSI;
          for (k = 0; k <= vlen - 2; k++) {
            regionLengths->data[k + 1] += regionLengths->data[k];
          }
        }
      }
    }

    emxInit_int32_T(&d_st, &idxCount, 1, &oi_emlrtRTEI, true);
    i = idxCount->size[0];
    idxCount->size[0] = regionLengths->size[0] + 1;
    emxEnsureCapacity_int32_T(&st, idxCount, i, &ji_emlrtRTEI);
    idxCount->data[0] = 0;
    vlen = regionLengths->size[0];
    for (i = 0; i < vlen; i++) {
      idxCount->data[i + 1] = regionLengths->data[i];
    }

    i = stats->size[0];
    for (k = 0; k < i; k++) {
      b_k = k + 1;
      if ((b_k < 1) || (b_k > idxCount->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_k, 1, idxCount->size[0], &sb_emlrtBCI,
          &st);
      }

      b_k = (int32_T)(((real_T)k + 1.0) + 1.0);
      if ((b_k < 1) || (b_k > idxCount->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_k, 1, idxCount->size[0], &rb_emlrtBCI,
          &st);
      }

      b_k = idxCount->data[k + 1];
      if (idxCount->data[k] + 1 > b_k) {
        i1 = 0;
        b_k = 0;
      } else {
        i1 = idxCount->data[k] + 1;
        if ((i1 < 1) || (i1 > CC_RegionIndices->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, CC_RegionIndices->size[0],
            &qb_emlrtBCI, &st);
        }

        i1--;
        if ((b_k < 1) || (b_k > CC_RegionIndices->size[0])) {
          emlrtDynamicBoundsCheckR2012b(b_k, 1, CC_RegionIndices->size[0],
            &pb_emlrtBCI, &st);
        }
      }

      i2 = stats->size[0];
      i3 = k + 1;
      if ((i3 < 1) || (i3 > stats->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, stats->size[0], &tb_emlrtBCI, &st);
      }

      vlen = b_k - i1;
      b_k = stats->data[i3 - 1].PixelIdxList->size[0];
      stats->data[i3 - 1].PixelIdxList->size[0] = vlen;
      emxEnsureCapacity_real_T(&st, stats->data[i3 - 1].PixelIdxList, b_k,
        &ki_emlrtRTEI);
      for (b_k = 0; b_k < vlen; b_k++) {
        i3 = k + 1;
        if ((i3 < 1) || (i3 > i2)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &tb_emlrtBCI, &st);
        }

        stats->data[i3 - 1].PixelIdxList->data[b_k] = CC_RegionIndices->data[i1
          + b_k];
      }
    }

    emxFree_int32_T(&idxCount);
  }

  emxFree_int32_T(&regionLengths);
  emxFree_real_T(&CC_RegionIndices);
  st.site = &jm_emlrtRSI;
  if (!statsAlreadyComputed.Centroid) {
    statsAlreadyComputed.Centroid = true;
    b_st.site = &bo_emlrtRSI;
    ComputePixelList(&b_st, CC_ImageSize, stats, &statsAlreadyComputed);
    i = stats->size[0];
    for (k = 0; k < i; k++) {
      b_st.site = &co_emlrtRSI;
      b_k = k + 1;
      if ((b_k < 1) || (b_k > stats->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &ob_emlrtBCI,
          &b_st);
      }

      c_st.site = &do_emlrtRSI;
      vlen = stats->data[k].PixelList->size[0];
      if (stats->data[k].PixelList->size[0] == 0) {
        min_corner_idx_0 = 0.0;
        min_corner_idx_1 = 0.0;
      } else {
        d_st.site = &en_emlrtRSI;
        overflow = ((2 <= stats->data[k].PixelList->size[0]) && (stats->data[k].
          PixelList->size[0] > 2147483646));
        min_corner_idx_0 = stats->data[k].PixelList->data[0];
        e_st.site = &fn_emlrtRSI;
        if (overflow) {
          f_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (b_k = 2; b_k <= vlen; b_k++) {
          min_corner_idx_0 += stats->data[k].PixelList->data[b_k - 1];
        }

        min_corner_idx_1 = stats->data[k].PixelList->data[stats->data[k].
          PixelList->size[0]];
        e_st.site = &fn_emlrtRSI;
        for (b_k = 2; b_k <= vlen; b_k++) {
          min_corner_idx_1 += stats->data[k].PixelList->data[(stats->data[k].
            PixelList->size[0] + b_k) - 1];
        }
      }

      b_k = stats->size[0];
      i1 = (int32_T)(k + 1U);
      if ((i1 < 1) || (i1 > stats->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &xb_emlrtBCI, &b_st);
      }

      stats->data[i1 - 1].Centroid[0] = min_corner_idx_0 / (real_T)stats->data[k]
        .PixelList->size[0];
      if (i1 > b_k) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &xb_emlrtBCI, &b_st);
      }

      stats->data[i1 - 1].Centroid[1] = min_corner_idx_1 / (real_T)stats->data[k]
        .PixelList->size[0];
    }
  }

  st.site = &im_emlrtRSI;
  if (!statsAlreadyComputed.BoundingBox) {
    statsAlreadyComputed.BoundingBox = true;
    b_st.site = &qn_emlrtRSI;
    ComputePixelList(&b_st, CC_ImageSize, stats, &statsAlreadyComputed);
    i = stats->size[0];
    for (k = 0; k < i; k++) {
      b_k = k + 1;
      if ((b_k < 1) || (b_k > stats->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &nb_emlrtBCI, &st);
      }

      if (stats->data[k].PixelList->size[0] == 0) {
        b_k = stats->size[0];
        i1 = (int32_T)(k + 1U);
        if ((i1 < 1) || (i1 > stats->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &wb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[0] = 0.5;
        if (i1 > b_k) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &wb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[1] = 0.5;
        if (i1 > b_k) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &wb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[2] = 0.0;
        if (i1 > b_k) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &wb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[3] = 0.0;
      } else {
        b_st.site = &rn_emlrtRSI;
        c_st.site = &qh_emlrtRSI;
        d_st.site = &rh_emlrtRSI;
        e_st.site = &sh_emlrtRSI;
        if (stats->data[k].PixelList->size[0] < 1) {
          emlrtErrorWithMessageIdR2018a(&e_st, &ib_emlrtRTEI,
            "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }

        f_st.site = &wn_emlrtRSI;
        g_st.site = &xn_emlrtRSI;
        h_st.site = &yn_emlrtRSI;
        vlen = stats->data[k].PixelList->size[0];
        overflow = ((2 <= stats->data[k].PixelList->size[0]) && (stats->data[k].
          PixelList->size[0] > 2147483646));
        min_corner_idx_0 = stats->data[k].PixelList->data[0];
        i_st.site = &ao_emlrtRSI;
        if (overflow) {
          j_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }

        for (b_k = 2; b_k <= vlen; b_k++) {
          b = stats->data[k].PixelList->data[b_k - 1];
          overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN
            (min_corner_idx_0) || (min_corner_idx_0 > b)));
          if (overflow) {
            min_corner_idx_0 = b;
          }
        }

        min_corner_idx_1 = stats->data[k].PixelList->data[stats->data[k].
          PixelList->size[0]];
        i_st.site = &ao_emlrtRSI;
        for (b_k = 2; b_k <= vlen; b_k++) {
          b = stats->data[k].PixelList->data[(b_k + stats->data[k]
            .PixelList->size[0]) - 1];
          overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN
            (min_corner_idx_1) || (min_corner_idx_1 > b)));
          if (overflow) {
            min_corner_idx_1 = b;
          }
        }

        min_corner_idx_0 -= 0.5;
        min_corner_idx_1 -= 0.5;
        b_st.site = &sn_emlrtRSI;
        c_st.site = &dl_emlrtRSI;
        d_st.site = &rh_emlrtRSI;
        e_st.site = &sh_emlrtRSI;
        if (stats->data[k].PixelList->size[0] < 1) {
          emlrtErrorWithMessageIdR2018a(&e_st, &ib_emlrtRTEI,
            "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }

        f_st.site = &wn_emlrtRSI;
        g_st.site = &xn_emlrtRSI;
        h_st.site = &yn_emlrtRSI;
        vlen = stats->data[k].PixelList->size[0];
        overflow = ((2 <= stats->data[k].PixelList->size[0]) && (stats->data[k].
          PixelList->size[0] > 2147483646));
        CC_ImageSize[0] = stats->data[k].PixelList->data[0];
        i_st.site = &ao_emlrtRSI;
        if (overflow) {
          j_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }

        for (b_k = 2; b_k <= vlen; b_k++) {
          b = stats->data[k].PixelList->data[b_k - 1];
          overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN
            (CC_ImageSize[0]) || (CC_ImageSize[0] < b)));
          if (overflow) {
            CC_ImageSize[0] = b;
          }
        }

        CC_ImageSize[1] = stats->data[k].PixelList->data[stats->data[k].
          PixelList->size[0]];
        i_st.site = &ao_emlrtRSI;
        for (b_k = 2; b_k <= vlen; b_k++) {
          b = stats->data[k].PixelList->data[(b_k + stats->data[k]
            .PixelList->size[0]) - 1];
          overflow = ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarIsNaN
            (CC_ImageSize[1]) || (CC_ImageSize[1] < b)));
          if (overflow) {
            CC_ImageSize[1] = b;
          }
        }

        b_k = stats->size[0];
        i1 = (int32_T)(k + 1U);
        if ((i1 < 1) || (i1 > stats->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &yb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[0] = min_corner_idx_0;
        i1 = (int32_T)(k + 1U);
        if ((i1 < 1) || (i1 > b_k)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &yb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[1] = min_corner_idx_1;
        i1 = (int32_T)(k + 1U);
        if ((i1 < 1) || (i1 > b_k)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &yb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[2] = (CC_ImageSize[0] + 0.5) -
          min_corner_idx_0;
        i1 = (int32_T)(k + 1U);
        if ((i1 < 1) || (i1 > b_k)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_k, &yb_emlrtBCI, &st);
        }

        stats->data[i1 - 1].BoundingBox[3] = (CC_ImageSize[1] + 0.5) -
          min_corner_idx_1;
      }
    }
  }

  st.site = &hm_emlrtRSI;
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    b_k = k + 1;
    if ((b_k < 1) || (b_k > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &mb_emlrtBCI, &st);
    }

    b_k = k + 1;
    if ((b_k < 1) || (b_k > outstats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &lb_emlrtBCI, &st);
    }

    b_k = (int32_T)(k + 1U);
    if ((b_k < 1) || (b_k > outstats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &ub_emlrtBCI, &st);
    }

    if (b_k > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &vb_emlrtBCI, &st);
    }

    outstats->data[b_k - 1].Centroid[0] = stats->data[b_k - 1].Centroid[0];
    if (b_k > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &ub_emlrtBCI, &st);
    }

    if (b_k > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &vb_emlrtBCI, &st);
    }

    outstats->data[b_k - 1].Centroid[1] = stats->data[b_k - 1].Centroid[1];
    i1 = k + 1;
    if ((i1 < 1) || (i1 > stats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, stats->size[0], &mb_emlrtBCI, &st);
    }

    i1 = k + 1;
    if ((i1 < 1) || (i1 > outstats->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, outstats->size[0], &lb_emlrtBCI, &st);
    }

    if (b_k > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &ub_emlrtBCI, &st);
    }

    if (b_k > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &vb_emlrtBCI, &st);
    }

    outstats->data[b_k - 1].BoundingBox[0] = stats->data[b_k - 1].BoundingBox[0];
    if (b_k > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &ub_emlrtBCI, &st);
    }

    if (b_k > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &vb_emlrtBCI, &st);
    }

    outstats->data[b_k - 1].BoundingBox[1] = stats->data[b_k - 1].BoundingBox[1];
    if (b_k > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &ub_emlrtBCI, &st);
    }

    if (b_k > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &vb_emlrtBCI, &st);
    }

    outstats->data[b_k - 1].BoundingBox[2] = stats->data[b_k - 1].BoundingBox[2];
    if (b_k > outstats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, outstats->size[0], &ub_emlrtBCI, &st);
    }

    if (b_k > stats->size[0]) {
      emlrtDynamicBoundsCheckR2012b(b_k, 1, stats->size[0], &vb_emlrtBCI, &st);
    }

    outstats->data[b_k - 1].BoundingBox[3] = stats->data[b_k - 1].BoundingBox[3];
  }

  emxFree_struct_T1(&stats);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (regionprops.c) */
