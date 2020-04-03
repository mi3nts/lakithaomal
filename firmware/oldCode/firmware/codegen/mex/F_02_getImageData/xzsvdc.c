/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xscal.h"
#include "xswap.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo tf_emlrtRSI = { 428,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 407,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 394,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 391,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 380,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo yf_emlrtRSI = { 353,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo ag_emlrtRSI = { 351,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo bg_emlrtRSI = { 334,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo cg_emlrtRSI = { 251,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo dg_emlrtRSI = { 240,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo eg_emlrtRSI = { 215,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo fg_emlrtRSI = { 194,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo gg_emlrtRSI = { 184,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 120,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 114,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 94, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 82, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 77, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 21, /* lineNo */
  "scaleVectorByRecip",                /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/scaleVectorByRecip.m"/* pathName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 269,/* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/eml/+coder/+internal/+reflapack/xzsvdc.m"/* pName */
};

/* Function Definitions */
void xzsvdc(const emlrtStack *sp, real_T A[9], real_T U[9], real_T S[3], real_T
            V[9])
{
  real_T e[3];
  real_T work[3];
  boolean_T apply_transform;
  real_T nrm;
  real_T s[3];
  int32_T kase;
  real_T rt;
  int32_T qp1;
  int32_T qjj;
  int32_T m;
  int32_T q;
  int32_T qq;
  real_T snorm;
  boolean_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  real_T scale;
  real_T sm;
  real_T sqds;
  real_T b;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  e[0] = 0.0;
  work[0] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  memset(&U[0], 0, 9U * sizeof(real_T));
  memset(&V[0], 0, 9U * sizeof(real_T));
  apply_transform = false;
  st.site = &lg_emlrtRSI;
  nrm = xnrm2(&st, 3, A, 1);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[0] < 0.0) {
      rt = -nrm;
      s[0] = -nrm;
    } else {
      rt = nrm;
      s[0] = nrm;
    }

    st.site = &kg_emlrtRSI;
    if (muDoubleScalarAbs(rt) >= 1.0020841800044864E-292) {
      b_st.site = &og_emlrtRSI;
      xscal(&b_st, 3, 1.0 / rt, A, 1);
    } else {
      for (qjj = 1; qjj < 4; qjj++) {
        A[qjj - 1] /= s[0];
      }
    }

    A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (kase = 2; kase < 4; kase++) {
    qjj = 3 * (kase - 1);
    if (apply_transform) {
      st.site = &jg_emlrtRSI;
      nrm = xdotc(&st, 3, A, 1, A, qjj + 1);
      nrm = -(nrm / A[0]);
      xaxpy(3, nrm, 1, A, qjj + 1);
    }

    e[kase - 1] = A[qjj];
  }

  for (qp1 = 1; qp1 < 4; qp1++) {
    U[qp1 - 1] = A[qp1 - 1];
  }

  st.site = &ig_emlrtRSI;
  nrm = b_xnrm2(&st, e, 2);
  if (nrm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }

    st.site = &hg_emlrtRSI;
    nrm = e[0];
    if (muDoubleScalarAbs(e[0]) >= 1.0020841800044864E-292) {
      b_st.site = &og_emlrtRSI;
      b_xscal(&b_st, 1.0 / e[0], e, 2);
    } else {
      for (qjj = 2; qjj < 4; qjj++) {
        e[qjj - 1] /= nrm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (qp1 = 2; qp1 < 4; qp1++) {
      work[qp1 - 1] = 0.0;
    }

    for (kase = 2; kase < 4; kase++) {
      b_xaxpy(2, e[kase - 1], A, 3 * (kase - 1) + 2, work, 2);
    }

    for (kase = 2; kase < 4; kase++) {
      c_xaxpy(2, -e[kase - 1] / e[1], work, 2, A, 3 * (kase - 1) + 2);
    }
  }

  for (qp1 = 2; qp1 < 4; qp1++) {
    V[qp1 - 1] = e[qp1 - 1];
  }

  apply_transform = false;
  st.site = &lg_emlrtRSI;
  nrm = xnrm2(&st, 2, A, 5);
  if (nrm > 0.0) {
    apply_transform = true;
    if (A[4] < 0.0) {
      rt = -nrm;
      s[1] = -nrm;
    } else {
      rt = nrm;
      s[1] = nrm;
    }

    st.site = &kg_emlrtRSI;
    if (muDoubleScalarAbs(rt) >= 1.0020841800044864E-292) {
      b_st.site = &og_emlrtRSI;
      xscal(&b_st, 2, 1.0 / rt, A, 5);
    } else {
      for (qjj = 5; qjj < 7; qjj++) {
        A[qjj - 1] /= s[1];
      }
    }

    A[4]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (kase = 3; kase < 4; kase++) {
    if (apply_transform) {
      st.site = &jg_emlrtRSI;
      nrm = xdotc(&st, 2, A, 5, A, 8);
      nrm = -(nrm / A[4]);
      xaxpy(2, nrm, 5, A, 8);
    }
  }

  for (qp1 = 2; qp1 < 4; qp1++) {
    U[qp1 + 2] = A[qp1 + 2];
  }

  m = 1;
  s[2] = A[8];
  e[1] = A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + 3 * (kase - 1)) + 1;
        st.site = &gg_emlrtRSI;
        nrm = xdotc(&st, 3 - q, U, qq + 1, U, qjj);
        nrm = -(nrm / U[qq]);
        xaxpy(3 - q, nrm, qq + 1, U, qjj);
      }

      for (qp1 = q + 1; qp1 < 4; qp1++) {
        kase = (qp1 + 3 * q) - 1;
        U[kase] = -U[kase];
      }

      U[qq]++;
      st.site = &fg_emlrtRSI;
      if (0 <= q - 1) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (q = 2; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      st.site = &eg_emlrtRSI;
      nrm = xdotc(&st, 2, V, 2, V, 5);
      nrm = -(nrm / V[1]);
      xaxpy(2, nrm, 2, V, 5);
      st.site = &eg_emlrtRSI;
      nrm = xdotc(&st, 2, V, 2, V, 8);
      nrm = -(nrm / V[1]);
      xaxpy(2, nrm, 2, V, 8);
    }

    V[3 * q] = 0.0;
    V[3 * q + 1] = 0.0;
    V[3 * q + 2] = 0.0;
    V[q + 3 * q] = 1.0;
  }

  if (s[0] != 0.0) {
    rt = muDoubleScalarAbs(s[0]);
    nrm = s[0] / rt;
    s[0] = rt;
    e[0] /= nrm;
    st.site = &dg_emlrtRSI;
    c_xscal(&st, nrm, U, 1);
  }

  if (e[0] != 0.0) {
    rt = muDoubleScalarAbs(e[0]);
    nrm = rt / e[0];
    e[0] = rt;
    s[1] *= nrm;
    st.site = &cg_emlrtRSI;
    c_xscal(&st, nrm, V, 4);
  }

  if (s[1] != 0.0) {
    rt = muDoubleScalarAbs(s[1]);
    nrm = s[1] / rt;
    s[1] = rt;
    e[1] = A[7] / nrm;
    st.site = &dg_emlrtRSI;
    c_xscal(&st, nrm, U, 4);
  }

  if (e[1] != 0.0) {
    rt = muDoubleScalarAbs(e[1]);
    nrm = rt / e[1];
    e[1] = rt;
    s[2] = A[8] * nrm;
    st.site = &cg_emlrtRSI;
    c_xscal(&st, nrm, V, 7);
  }

  if (s[2] != 0.0) {
    rt = muDoubleScalarAbs(s[2]);
    nrm = s[2] / rt;
    s[2] = rt;
    st.site = &dg_emlrtRSI;
    c_xscal(&st, nrm, U, 7);
  }

  qq = 0;
  snorm = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax(s[0], e[0]),
    muDoubleScalarMax(s[1], e[1])), muDoubleScalarMax(s[2], 0.0));
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (qq >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &cb_emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      qp1 = m;
      do {
        exitg2 = 0;
        q = qp1 + 1;
        if (qp1 + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[qp1]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[qp1]) +
                muDoubleScalarAbs(s[qp1 + 1]))) || (nrm <=
               1.0020841800044864E-292) || ((qq > 20) && (nrm <=
                2.2204460492503131E-16 * snorm))) {
            e[qp1] = 0.0;
            exitg2 = 1;
          } else {
            qp1--;
          }
        }
      } while (exitg2 == 0);

      if (qp1 + 1 == m + 1) {
        kase = 4;
      } else {
        qjj = m + 2;
        kase = m + 2;
        exitg3 = false;
        while ((!exitg3) && (kase >= qp1 + 1)) {
          qjj = kase;
          if (kase == qp1 + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (kase < m + 2) {
              nrm = muDoubleScalarAbs(e[kase - 1]);
            }

            if (kase > qp1 + 2) {
              nrm += muDoubleScalarAbs(e[kase - 2]);
            }

            rt = muDoubleScalarAbs(s[kase - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
                 1.0020841800044864E-292)) {
              s[kase - 1] = 0.0;
              exitg3 = true;
            } else {
              kase--;
            }
          }
        }

        if (qjj == qp1 + 1) {
          kase = 3;
        } else if (qjj == m + 2) {
          kase = 1;
        } else {
          kase = 2;
          q = qjj;
        }
      }

      switch (kase) {
       case 1:
        rt = e[m];
        e[m] = 0.0;
        kase = m + 1;
        for (qjj = kase; qjj >= q + 1; qjj--) {
          st.site = &bg_emlrtRSI;
          xrotg(&s[qjj - 1], &rt, &sm, &sqds);
          if (qjj > q + 1) {
            rt = -sqds * e[0];
            e[0] *= sm;
          }

          xrot(V, 3 * (qjj - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
        }
        break;

       case 2:
        rt = e[q - 1];
        e[q - 1] = 0.0;
        st.site = &ag_emlrtRSI;
        for (qjj = q + 1; qjj <= m + 2; qjj++) {
          st.site = &yf_emlrtRSI;
          xrotg(&s[qjj - 1], &rt, &sm, &sqds);
          b = e[qjj - 1];
          rt = -sqds * b;
          e[qjj - 1] = b * sm;
          xrot(U, 3 * (qjj - 1) + 1, 3 * (q - 1) + 1, sm, sqds);
        }
        break;

       case 3:
        kase = m + 1;
        nrm = s[m + 1];
        scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
          (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(s[m])),
           muDoubleScalarAbs(e[m])), muDoubleScalarAbs(s[q])), muDoubleScalarAbs
          (e[q]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &xf_emlrtRSI;
          b_sqrt(&st, &rt);
          if (b < 0.0) {
            rt = -rt;
          }

          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }

        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        st.site = &wf_emlrtRSI;
        for (qjj = q + 1; qjj <= kase; qjj++) {
          st.site = &vf_emlrtRSI;
          xrotg(&rt, &nrm, &sm, &sqds);
          if (qjj > q + 1) {
            e[0] = rt;
          }

          nrm = e[qjj - 1];
          b = s[qjj - 1];
          e[qjj - 1] = sm * nrm - sqds * b;
          rt = sqds * s[qjj];
          s[qjj] *= sm;
          xrot(V, 3 * (qjj - 1) + 1, 3 * qjj + 1, sm, sqds);
          s[qjj - 1] = sm * b + sqds * nrm;
          st.site = &uf_emlrtRSI;
          xrotg(&s[qjj - 1], &rt, &sm, &sqds);
          rt = sm * e[qjj - 1] + sqds * s[qjj];
          s[qjj] = -sqds * e[qjj - 1] + sm * s[qjj];
          nrm = sqds * e[qjj];
          e[qjj] *= sm;
          xrot(U, 3 * (qjj - 1) + 1, 3 * qjj + 1, sm, sqds);
        }

        e[m] = rt;
        qq++;
        break;

       default:
        if (s[q] < 0.0) {
          s[q] = -s[q];
          st.site = &tf_emlrtRSI;
          c_xscal(&st, -1.0, V, 3 * q + 1);
        }

        qp1 = q + 1;
        while ((q + 1 < 3) && (s[q] < s[qp1])) {
          rt = s[q];
          s[q] = s[qp1];
          s[qp1] = rt;
          xswap(V, 3 * q + 1, 3 * (q + 1) + 1);
          xswap(U, 3 * q + 1, 3 * (q + 1) + 1);
          q = qp1;
          qp1++;
        }

        qq = 0;
        m--;
        break;
      }
    }
  }

  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

/* End of code generation (xzsvdc.c) */
