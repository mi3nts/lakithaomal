//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrotg.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "xrotg.h"
#include "F_02_getImageData.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : double *a
//                double *b
//                double *c
//                double *s
// Return Type  : void
//
void xrotg(double *a, double *b, double *c, double *s)
{
  double roe;
  double absa;
  double absb;
  double scale;
  double ads;
  double bds;
  roe = *b;
  absa = std::abs(*a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

//
// File trailer for xrotg.cpp
//
// [EOF]
//
