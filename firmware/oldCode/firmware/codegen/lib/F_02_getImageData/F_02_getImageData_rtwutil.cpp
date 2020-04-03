//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: F_02_getImageData_rtwutil.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "F_02_getImageData_rtwutil.h"
#include "F_02_getImageData.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// File trailer for F_02_getImageData_rtwutil.cpp
//
// [EOF]
//
