//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imread.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "imread.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "libmwjpegreader.h"
#include "rt_nonfinite.h"

// Variable Definitions
static const double dv[3] = { 480.0, 640.0, 3.0 };

// Function Definitions

//
// Arguments    : emxArray_uint8_T *X
// Return Type  : void
//
void b_imread(emxArray_uint8_T *X)
{
  int i;
  char libjpegWarnBuffer[200];
  static const char fname[30] = "2019_11_07_15_29_37_right.jpg";
  static unsigned char out[921600];
  signed char fileStatus;
  signed char libjpegReadDone;
  double libjpegMsgCode;
  signed char errWarnType;
  for (i = 0; i < 200; i++) {
    libjpegWarnBuffer[i] = ' ';
  }

  jpegreader_uint8(fname, out, dv, 3.0, &fileStatus, &libjpegReadDone,
                   &libjpegMsgCode, libjpegWarnBuffer, &errWarnType);
  if ((fileStatus == -1) || (libjpegReadDone == 0) || (errWarnType == -1)) {
    X->size[0] = 0;
    X->size[1] = 0;
    X->size[2] = 0;
  } else {
    i = X->size[0] * X->size[1] * X->size[2];
    X->size[0] = 480;
    X->size[1] = 640;
    X->size[2] = 3;
    emxEnsureCapacity_uint8_T(X, i);
    for (i = 0; i < 921600; i++) {
      X->data[i] = out[i];
    }
  }
}

//
// Arguments    : emxArray_uint8_T *X
// Return Type  : void
//
void imread(emxArray_uint8_T *X)
{
  int i;
  char libjpegWarnBuffer[200];
  static const char fname[29] = "2019_11_07_15_29_37_left.jpg";
  static unsigned char out[921600];
  signed char fileStatus;
  signed char libjpegReadDone;
  double libjpegMsgCode;
  signed char errWarnType;
  for (i = 0; i < 200; i++) {
    libjpegWarnBuffer[i] = ' ';
  }

  jpegreader_uint8(fname, out, dv, 3.0, &fileStatus, &libjpegReadDone,
                   &libjpegMsgCode, libjpegWarnBuffer, &errWarnType);
  if ((fileStatus == -1) || (libjpegReadDone == 0) || (errWarnType == -1)) {
    X->size[0] = 0;
    X->size[1] = 0;
    X->size[2] = 0;
  } else {
    i = X->size[0] * X->size[1] * X->size[2];
    X->size[0] = 480;
    X->size[1] = 640;
    X->size[2] = 3;
    emxEnsureCapacity_uint8_T(X, i);
    for (i = 0; i < 921600; i++) {
      X->data[i] = out[i];
    }
  }
}

//
// File trailer for imread.cpp
//
// [EOF]
//
