//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesVectorToMatrix.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "rodriguesVectorToMatrix.h"
#include "F_02_getImageData.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions

//
// Arguments    : const double rotationVector[3]
//                double rotationMatrix[9]
// Return Type  : void
//
void rodriguesVectorToMatrix(const double rotationVector[3], double
  rotationMatrix[9])
{
  double scale;
  double absxk;
  double t;
  double theta;
  double u[3];
  int k;
  signed char a[9];
  double b_u[9];
  scale = 3.3121686421112381E-170;
  absxk = std::abs(rotationVector[0]);
  if (absxk > 3.3121686421112381E-170) {
    theta = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta = t * t;
  }

  absxk = std::abs(rotationVector[1]);
  if (absxk > scale) {
    t = scale / absxk;
    theta = theta * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta += t * t;
  }

  absxk = std::abs(rotationVector[2]);
  if (absxk > scale) {
    t = scale / absxk;
    theta = theta * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta += t * t;
  }

  theta = scale * std::sqrt(theta);
  if (theta < 1.0E-6) {
    std::memset(&rotationMatrix[0], 0, 9U * sizeof(double));
    rotationMatrix[0] = 1.0;
    rotationMatrix[4] = 1.0;
    rotationMatrix[8] = 1.0;
  } else {
    u[0] = rotationVector[0] / theta;
    u[1] = rotationVector[1] / theta;
    u[2] = rotationVector[2] / theta;
    absxk = std::cos(theta);
    scale = std::sin(theta);
    for (k = 0; k < 9; k++) {
      a[k] = 0;
    }

    rotationMatrix[0] = scale * 0.0;
    rotationMatrix[3] = scale * -u[2];
    rotationMatrix[6] = scale * u[1];
    rotationMatrix[1] = scale * u[2];
    rotationMatrix[4] = scale * 0.0;
    rotationMatrix[7] = scale * -u[0];
    rotationMatrix[2] = scale * -u[1];
    rotationMatrix[5] = scale * u[0];
    rotationMatrix[8] = scale * 0.0;
    for (k = 0; k < 3; k++) {
      a[k + 3 * k] = 1;
      b_u[3 * k] = u[0] * u[k];
      b_u[3 * k + 1] = u[1] * u[k];
      b_u[3 * k + 2] = u[2] * u[k];
    }

    for (k = 0; k < 9; k++) {
      rotationMatrix[k] = (static_cast<double>(a[k]) * absxk + rotationMatrix[k])
        + (1.0 - absxk) * b_u[k];
    }
  }
}

//
// File trailer for rodriguesVectorToMatrix.cpp
//
// [EOF]
//
