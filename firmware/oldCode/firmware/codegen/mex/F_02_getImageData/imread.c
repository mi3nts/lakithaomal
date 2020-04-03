/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imread.c
 *
 * Code generation for function 'imread'
 *
 */

/* Include files */
#include "imread.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "libmwjpegreader.h"
#include "rt_nonfinite.h"
#include "warning.h"

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = { 149,/* lineNo */
  "imread",                            /* fcnName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = { 118,/* lineNo */
  13,                                  /* colNo */
  "imread",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 120,/* lineNo */
  9,                                   /* colNo */
  "imread",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 125,/* lineNo */
  9,                                   /* colNo */
  "imread",                            /* fName */
  "/usr/local/MATLAB/R2019b/toolbox/eml/lib/matlab/imagesci/imread.m"/* pName */
};

/* Function Definitions */
void b_imread(const emlrtStack *sp, uint8_T X[921600])
{
  int32_T i;
  char_T libjpegWarnBuffer[200];
  static const char_T fname[30] = "2019_11_07_15_29_37_right.jpg";
  int8_T fileStatus;
  int8_T libjpegReadDone;
  real_T libjpegMsgCode;
  int8_T errWarnType;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 200; i++) {
    libjpegWarnBuffer[i] = ' ';
  }

  jpegreader_uint8(fname, X, dv, 3.0, &fileStatus, &libjpegReadDone,
                   &libjpegMsgCode, libjpegWarnBuffer, &errWarnType);
  if ((fileStatus == -1) || (libjpegReadDone == 0) || (errWarnType == -1)) {
    if (fileStatus == -1) {
      emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
        "MATLAB:imagesci:imread:codegenFileOpenError",
        "MATLAB:imagesci:imread:codegenFileOpenError", 3, 4, 29,
        "2019_11_07_15_29_37_right.jpg");
    }

    if (errWarnType == -1) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
        "MATLAB:imagesci:jpg:unhandledLibraryError",
        "MATLAB:imagesci:jpg:unhandledLibraryError", 5, 6, 8.0, 4, 200,
        libjpegWarnBuffer);
    }

    if (libjpegReadDone != 1) {
      emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
        "MATLAB:imagesci:jpg:unhandledLibraryError",
        "MATLAB:imagesci:jpg:unhandledLibraryError", 5, 6, 8.0, 4, 200,
        libjpegWarnBuffer);
    }
  }

  if (errWarnType == -2) {
    st.site = &nd_emlrtRSI;
    warning(&st, libjpegWarnBuffer);
  }
}

void imread(const emlrtStack *sp, uint8_T X[921600])
{
  int32_T i;
  char_T libjpegWarnBuffer[200];
  static const char_T fname[29] = "2019_11_07_15_29_37_left.jpg";
  int8_T fileStatus;
  int8_T libjpegReadDone;
  real_T libjpegMsgCode;
  int8_T errWarnType;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i = 0; i < 200; i++) {
    libjpegWarnBuffer[i] = ' ';
  }

  jpegreader_uint8(fname, X, dv, 3.0, &fileStatus, &libjpegReadDone,
                   &libjpegMsgCode, libjpegWarnBuffer, &errWarnType);
  if ((fileStatus == -1) || (libjpegReadDone == 0) || (errWarnType == -1)) {
    if (fileStatus == -1) {
      emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
        "MATLAB:imagesci:imread:codegenFileOpenError",
        "MATLAB:imagesci:imread:codegenFileOpenError", 3, 4, 28,
        "2019_11_07_15_29_37_left.jpg");
    }

    if (errWarnType == -1) {
      emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI,
        "MATLAB:imagesci:jpg:unhandledLibraryError",
        "MATLAB:imagesci:jpg:unhandledLibraryError", 5, 6, 8.0, 4, 200,
        libjpegWarnBuffer);
    }

    if (libjpegReadDone != 1) {
      emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
        "MATLAB:imagesci:jpg:unhandledLibraryError",
        "MATLAB:imagesci:jpg:unhandledLibraryError", 5, 6, 8.0, 4, 200,
        libjpegWarnBuffer);
    }
  }

  if (errWarnType == -2) {
    st.site = &nd_emlrtRSI;
    warning(&st, libjpegWarnBuffer);
  }
}

/* End of code generation (imread.c) */
