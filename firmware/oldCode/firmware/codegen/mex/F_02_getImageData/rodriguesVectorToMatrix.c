/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rodriguesVectorToMatrix.c
 *
 * Code generation for function 'rodriguesVectorToMatrix'
 *
 */

/* Include files */
#include "rodriguesVectorToMatrix.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void rodriguesVectorToMatrix(const real_T rotationVector[3], real_T
  rotationMatrix[9])
{
  real_T scale;
  real_T absxk;
  real_T t;
  real_T theta;
  real_T u[3];
  int32_T k;
  int8_T a[9];
  real_T b_u[9];
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(rotationVector[0]);
  if (absxk > 3.3121686421112381E-170) {
    theta = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta = t * t;
  }

  absxk = muDoubleScalarAbs(rotationVector[1]);
  if (absxk > scale) {
    t = scale / absxk;
    theta = theta * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta += t * t;
  }

  absxk = muDoubleScalarAbs(rotationVector[2]);
  if (absxk > scale) {
    t = scale / absxk;
    theta = theta * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta += t * t;
  }

  theta = scale * muDoubleScalarSqrt(theta);
  if (theta < 1.0E-6) {
    memset(&rotationMatrix[0], 0, 9U * sizeof(real_T));
    rotationMatrix[0] = 1.0;
    rotationMatrix[4] = 1.0;
    rotationMatrix[8] = 1.0;
  } else {
    u[0] = rotationVector[0] / theta;
    u[1] = rotationVector[1] / theta;
    u[2] = rotationVector[2] / theta;
    absxk = muDoubleScalarCos(theta);
    scale = muDoubleScalarSin(theta);
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
      rotationMatrix[k] = ((real_T)a[k] * absxk + rotationMatrix[k]) + (1.0 -
        absxk) * b_u[k];
    }
  }
}

/* End of code generation (rodriguesVectorToMatrix.c) */
