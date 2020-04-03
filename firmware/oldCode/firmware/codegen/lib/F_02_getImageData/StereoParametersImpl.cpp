//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: StereoParametersImpl.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "StereoParametersImpl.h"
#include "CameraParametersImpl.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "F_02_getImageData_rtwutil.h"
#include "ImageTransformer.h"
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "svd.h"
#include <cmath>
#include <cstring>

// Function Declarations
static void c_StereoParametersImpl_computeH(const
  c_vision_internal_calibration_S *b_this, double Rl[9], double Rr[9]);
static void c_StereoParametersImpl_computeN(c_vision_internal_calibration_S
  *b_this, double K_new[9]);
static void computeOutputBoundsValid(double outBounds1[8], double outBounds2[8],
  double xBounds[2], double yBounds[2], boolean_T *isValid);
static void computeRowAlignmentRotation(const double t[3], double RrowAlign[9]);

// Function Definitions

//
// Arguments    : const c_vision_internal_calibration_S *b_this
//                double Rl[9]
//                double Rr[9]
// Return Type  : void
//
static void c_StereoParametersImpl_computeH(const
  c_vision_internal_calibration_S *b_this, double Rl[9], double Rr[9])
{
  int s_tmp_tmp;
  boolean_T p;
  double rotationMatrix[9];
  int k;
  double U[9];
  double r[3];
  double V[9];
  double t;
  double absxk;
  double theta;
  double s;
  int idx;
  boolean_T exitg1;
  int iidx;
  int s_tmp;
  int b_s_tmp_tmp;
  int b_s_tmp;
  double y;
  for (s_tmp_tmp = 0; s_tmp_tmp < 3; s_tmp_tmp++) {
    rotationMatrix[3 * s_tmp_tmp] = b_this->RotationOfCamera2[s_tmp_tmp];
    rotationMatrix[3 * s_tmp_tmp + 1] = b_this->RotationOfCamera2[s_tmp_tmp + 3];
    rotationMatrix[3 * s_tmp_tmp + 2] = b_this->RotationOfCamera2[s_tmp_tmp + 6];
  }

  p = true;
  for (k = 0; k < 9; k++) {
    if ((!p) || (rtIsInf(rotationMatrix[k]) || rtIsNaN(rotationMatrix[k]))) {
      p = false;
    }
  }

  if (p) {
    svd(rotationMatrix, U, r, V);
  } else {
    for (s_tmp_tmp = 0; s_tmp_tmp < 9; s_tmp_tmp++) {
      U[s_tmp_tmp] = rtNaN;
      V[s_tmp_tmp] = rtNaN;
    }
  }

  for (s_tmp_tmp = 0; s_tmp_tmp < 3; s_tmp_tmp++) {
    absxk = U[s_tmp_tmp + 3];
    s = U[s_tmp_tmp + 6];
    for (idx = 0; idx < 3; idx++) {
      rotationMatrix[s_tmp_tmp + 3 * idx] = (U[s_tmp_tmp] * V[idx] + absxk *
        V[idx + 3]) + s * V[idx + 6];
    }
  }

  t = (rotationMatrix[0] + rotationMatrix[4]) + rotationMatrix[8];
  theta = std::acos((t - 1.0) / 2.0);
  r[0] = rotationMatrix[5] - rotationMatrix[7];
  r[1] = rotationMatrix[6] - rotationMatrix[2];
  r[2] = rotationMatrix[1] - rotationMatrix[3];
  absxk = std::sin(theta);
  if (absxk >= 0.0001) {
    s = 1.0 / (2.0 * absxk);
    r[0] = theta * (r[0] * s);
    r[1] = theta * (r[1] * s);
    r[2] = theta * (r[2] * s);
  } else if (t - 1.0 > 0.0) {
    s = 0.5 - (t - 3.0) / 12.0;
    r[0] *= s;
    r[1] *= s;
    r[2] *= s;
  } else {
    r[0] = rotationMatrix[0];
    r[1] = rotationMatrix[4];
    r[2] = rotationMatrix[8];
    if (!rtIsNaN(rotationMatrix[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!rtIsNaN(r[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      iidx = 0;
    } else {
      s = r[idx - 1];
      iidx = idx - 1;
      s_tmp_tmp = idx + 1;
      for (k = s_tmp_tmp; k < 4; k++) {
        absxk = r[k - 1];
        if (s < absxk) {
          s = absxk;
          iidx = k - 1;
        }
      }
    }

    idx = iidx + 1;
    s_tmp = static_cast<int>(std::fmod(static_cast<double>(idx), 3.0)) + 1;
    idx = static_cast<int>(std::fmod(static_cast<double>(idx) + 1.0, 3.0)) + 1;
    s_tmp_tmp = s_tmp - 1;
    k = 3 * s_tmp_tmp;
    b_s_tmp_tmp = idx - 1;
    b_s_tmp = 3 * b_s_tmp_tmp;
    s = std::sqrt(((rotationMatrix[iidx + 3 * iidx] - rotationMatrix[(s_tmp + k)
                    - 1]) - rotationMatrix[(idx + b_s_tmp) - 1]) + 1.0);
    r[0] = 0.0;
    r[1] = 0.0;
    r[2] = 0.0;
    r[iidx] = s / 2.0;
    r[s_tmp_tmp] = (rotationMatrix[(s_tmp + 3 * iidx) - 1] + rotationMatrix[iidx
                    + k]) / (2.0 * s);
    r[b_s_tmp_tmp] = (rotationMatrix[(idx + 3 * iidx) - 1] + rotationMatrix[iidx
                      + b_s_tmp]) / (2.0 * s);
    s = 3.3121686421112381E-170;
    absxk = std::abs(r[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      s = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    absxk = std::abs(r[1]);
    if (absxk > s) {
      t = s / absxk;
      y = y * t * t + 1.0;
      s = absxk;
    } else {
      t = absxk / s;
      y += t * t;
    }

    absxk = std::abs(r[2]);
    if (absxk > s) {
      t = s / absxk;
      y = y * t * t + 1.0;
      s = absxk;
    } else {
      t = absxk / s;
      y += t * t;
    }

    y = s * std::sqrt(y);
    r[0] = theta * r[0] / y;
    r[1] = theta * r[1] / y;
    r[2] = theta * r[2] / y;
  }

  r[0] /= -2.0;
  r[1] /= -2.0;
  r[2] /= -2.0;
  rodriguesVectorToMatrix(r, Rr);
  for (s_tmp_tmp = 0; s_tmp_tmp < 3; s_tmp_tmp++) {
    Rl[3 * s_tmp_tmp] = Rr[s_tmp_tmp];
    Rl[3 * s_tmp_tmp + 1] = Rr[s_tmp_tmp + 3];
    Rl[3 * s_tmp_tmp + 2] = Rr[s_tmp_tmp + 6];
  }
}

//
// Arguments    : c_vision_internal_calibration_S *b_this
//                double K_new[9]
// Return Type  : void
//
static void c_StereoParametersImpl_computeN(c_vision_internal_calibration_S
  *b_this, double K_new[9])
{
  d_vision_internal_calibration_C *c_this;
  int i;
  double intrinsicMatrix[9];
  double Kl[9];
  double Kr[9];
  double f_new;
  c_this = b_this->CameraParameters1;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = c_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = c_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = c_this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 3; i++) {
    Kl[3 * i] = intrinsicMatrix[i];
    Kl[3 * i + 1] = intrinsicMatrix[i + 3];
    Kl[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  c_this = b_this->CameraParameters2;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = c_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = c_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = c_this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 3; i++) {
    Kr[3 * i] = intrinsicMatrix[i];
    Kr[3 * i + 1] = intrinsicMatrix[i + 3];
    Kr[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  std::memcpy(&K_new[0], &Kl[0], 9U * sizeof(double));
  if ((Kr[0] > Kl[0]) || (rtIsNaN(Kr[0]) && (!rtIsNaN(Kl[0])))) {
    f_new = Kl[0];
  } else {
    f_new = Kr[0];
  }

  K_new[0] = f_new;
  K_new[4] = f_new;
  K_new[7] = (Kr[7] + Kl[7]) / 2.0;
  K_new[3] = 0.0;
}

//
// Arguments    : double outBounds1[8]
//                double outBounds2[8]
//                double xBounds[2]
//                double yBounds[2]
//                boolean_T *isValid
// Return Type  : void
//
static void computeOutputBoundsValid(double outBounds1[8], double outBounds2[8],
  double xBounds[2], double yBounds[2], boolean_T *isValid)
{
  int i;
  double xSort[8];
  double outPts[16];
  int idx;
  int outPts_tmp;
  double ySort[8];
  int b_outPts_tmp;
  boolean_T b;
  boolean_T exitg1;
  double xmin1;
  double u1;
  double xmax1;
  double xmin2;
  double xmax2;
  for (i = 0; i < 2; i++) {
    idx = i << 2;
    outPts_tmp = i << 3;
    outPts[outPts_tmp] = outBounds1[idx];
    outPts[outPts_tmp + 4] = outBounds2[idx];
    b_outPts_tmp = idx + 1;
    outPts[outPts_tmp + 1] = outBounds1[b_outPts_tmp];
    outPts[outPts_tmp + 5] = outBounds2[b_outPts_tmp];
    b_outPts_tmp = idx + 2;
    outPts[outPts_tmp + 2] = outBounds1[b_outPts_tmp];
    outPts[outPts_tmp + 6] = outBounds2[b_outPts_tmp];
    idx += 3;
    outPts[outPts_tmp + 3] = outBounds1[idx];
    outPts[outPts_tmp + 7] = outBounds2[idx];
  }

  std::memcpy(&xSort[0], &outPts[0], 8U * sizeof(double));
  b_sort(xSort);
  std::memcpy(&ySort[0], &outPts[8], 8U * sizeof(double));
  b_sort(ySort);
  xBounds[0] = 0.0;
  yBounds[0] = 0.0;
  xBounds[1] = 0.0;
  yBounds[1] = 0.0;
  for (outPts_tmp = 0; outPts_tmp < 8; outPts_tmp++) {
    outBounds1[outPts_tmp] = rt_roundd_snf(outBounds1[outPts_tmp]);
    outBounds2[outPts_tmp] = rt_roundd_snf(outBounds2[outPts_tmp]);
  }

  b = rtIsNaN(outBounds1[0]);
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!rtIsNaN(outBounds1[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmin1 = outBounds1[0];
  } else {
    xmin1 = outBounds1[idx - 1];
    i = idx + 1;
    for (outPts_tmp = i; outPts_tmp < 5; outPts_tmp++) {
      u1 = outBounds1[outPts_tmp - 1];
      if (xmin1 > u1) {
        xmin1 = u1;
      }
    }
  }

  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!rtIsNaN(outBounds1[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmax1 = outBounds1[0];
  } else {
    xmax1 = outBounds1[idx - 1];
    i = idx + 1;
    for (outPts_tmp = i; outPts_tmp < 5; outPts_tmp++) {
      u1 = outBounds1[outPts_tmp - 1];
      if (xmax1 < u1) {
        xmax1 = u1;
      }
    }
  }

  b = rtIsNaN(outBounds2[0]);
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!rtIsNaN(outBounds2[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmin2 = outBounds2[0];
  } else {
    xmin2 = outBounds2[idx - 1];
    i = idx + 1;
    for (outPts_tmp = i; outPts_tmp < 5; outPts_tmp++) {
      u1 = outBounds2[outPts_tmp - 1];
      if (xmin2 > u1) {
        xmin2 = u1;
      }
    }
  }

  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    outPts_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (outPts_tmp <= 4)) {
      if (!rtIsNaN(outBounds2[outPts_tmp - 1])) {
        idx = outPts_tmp;
        exitg1 = true;
      } else {
        outPts_tmp++;
      }
    }
  }

  if (idx == 0) {
    xmax2 = outBounds2[0];
  } else {
    xmax2 = outBounds2[idx - 1];
    i = idx + 1;
    for (outPts_tmp = i; outPts_tmp < 5; outPts_tmp++) {
      u1 = outBounds2[outPts_tmp - 1];
      if (xmax2 < u1) {
        xmax2 = u1;
      }
    }
  }

  if ((xmin1 >= xmax2) || (xmax1 <= xmin2)) {
    *isValid = false;
  } else {
    xBounds[0] = rt_roundd_snf(xSort[3]);
    xBounds[1] = rt_roundd_snf(xSort[4]);
    yBounds[0] = rt_roundd_snf(ySort[3]);
    yBounds[1] = rt_roundd_snf(ySort[4]);
    xmin1 = xmax1 - xmin1;
    u1 = xmax2 - xmin2;
    if ((xmin1 < u1) || rtIsNaN(u1)) {
      u1 = xmin1;
    }

    *isValid = !(xBounds[1] - xBounds[0] < 0.4 * u1);
  }
}

//
// Arguments    : const double t[3]
//                double RrowAlign[9]
// Return Type  : void
//
static void computeRowAlignmentRotation(const double t[3], double RrowAlign[9])
{
  signed char xUnitVector_idx_0;
  double rotationAxis[3];
  double scale;
  double b_t;
  double d;
  double absxk;
  double y;
  int b_absxk;
  xUnitVector_idx_0 = 1;
  if ((t[0] + 0.0 * t[1]) + 0.0 * t[2] < 0.0) {
    xUnitVector_idx_0 = -1;
  }

  rotationAxis[0] = t[1] * 0.0 - t[2] * 0.0;
  rotationAxis[1] = t[2] * static_cast<double>(xUnitVector_idx_0) - t[0] * 0.0;
  rotationAxis[2] = t[0] * 0.0 - t[1] * static_cast<double>(xUnitVector_idx_0);
  scale = 3.3121686421112381E-170;
  b_t = rotationAxis[0] / 3.3121686421112381E-170;
  d = b_t * b_t;
  absxk = std::abs(rotationAxis[1]);
  if (absxk > 3.3121686421112381E-170) {
    b_t = 3.3121686421112381E-170 / absxk;
    d = d * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / 3.3121686421112381E-170;
    d += b_t * b_t;
  }

  absxk = std::abs(rotationAxis[2]);
  if (absxk > scale) {
    b_t = scale / absxk;
    d = d * b_t * b_t + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    d += b_t * b_t;
  }

  d = scale * std::sqrt(d);
  if (d == 0.0) {
    std::memset(&RrowAlign[0], 0, 9U * sizeof(double));
    RrowAlign[0] = 1.0;
    RrowAlign[4] = 1.0;
    RrowAlign[8] = 1.0;
  } else {
    scale = 3.3121686421112381E-170;
    rotationAxis[0] /= d;
    absxk = std::abs(t[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      y = b_t * b_t;
    }

    rotationAxis[1] /= d;
    absxk = std::abs(t[1]);
    if (absxk > scale) {
      b_t = scale / absxk;
      y = y * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      y += b_t * b_t;
    }

    rotationAxis[2] /= d;
    absxk = std::abs(t[2]);
    if (absxk > scale) {
      b_t = scale / absxk;
      y = y * b_t * b_t + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      y += b_t * b_t;
    }

    y = scale * std::sqrt(y);
    scale = 3.3121686421112381E-170;
    b_absxk = static_cast<int>(std::abs(static_cast<double>(xUnitVector_idx_0)));
    if (b_absxk > 3.3121686421112381E-170) {
      b_t = 1.0;
      scale = 1.0;
    } else {
      b_t = static_cast<double>(b_absxk) / 3.3121686421112381E-170;
      b_t *= b_t;
    }

    b_t = scale * std::sqrt(b_t);
    b_t = std::acos(std::abs((t[0] * static_cast<double>(xUnitVector_idx_0) + t
      [1] * 0.0) + t[2] * 0.0) / (y * b_t));
    rotationAxis[0] *= b_t;
    rotationAxis[1] *= b_t;
    rotationAxis[2] *= b_t;
    rodriguesVectorToMatrix(rotationAxis, RrowAlign);
  }
}

//
// Arguments    : c_vision_internal_calibration_S *b_this
//                const double c_varargin_1_CameraParameters1_[2]
//                const double d_varargin_1_CameraParameters1_[2]
//                const double e_varargin_1_CameraParameters1_[2]
//                const char f_varargin_1_CameraParameters1_[11]
//                double g_varargin_1_CameraParameters1_
//                const double h_varargin_1_CameraParameters1_[114]
//                const double i_varargin_1_CameraParameters1_[114]
//                const double j_varargin_1_CameraParameters1_[9]
//                const struct1_T *varargin_1_CameraParameters2
//                const double varargin_1_RotationOfCamera2[9]
//                const double varargin_1_TranslationOfCamera2[3]
//                const struct3_T *varargin_1_RectificationParams
//                d_vision_internal_calibration_C *iobj_0
//                d_vision_internal_calibration_C *iobj_1
// Return Type  : c_vision_internal_calibration_S *
//
c_vision_internal_calibration_S *c_StereoParametersImpl_StereoPa
  (c_vision_internal_calibration_S *b_this, const double
   c_varargin_1_CameraParameters1_[2], const double
   d_varargin_1_CameraParameters1_[2], const double
   e_varargin_1_CameraParameters1_[2], const char
   f_varargin_1_CameraParameters1_[11], double g_varargin_1_CameraParameters1_,
   const double h_varargin_1_CameraParameters1_[114], const double
   i_varargin_1_CameraParameters1_[114], const double
   j_varargin_1_CameraParameters1_[9], const struct1_T
   *varargin_1_CameraParameters2, const double varargin_1_RotationOfCamera2[9],
   const double varargin_1_TranslationOfCamera2[3], const struct3_T
   *varargin_1_RectificationParams, d_vision_internal_calibration_C *iobj_0,
   d_vision_internal_calibration_C *iobj_1)
{
  c_vision_internal_calibration_S *c_this;
  int i;
  static const signed char iv[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 1 };

  static const char cv[5] = { 'v', 'a', 'l', 'i', 'd' };

  static const signed char T[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  double obj_T[9];
  double self_T[9];
  c_this = b_this;
  for (i = 0; i < 16; i++) {
    c_this->RectificationParams.Q[i] = iv[i];
  }

  c_this->RectificationParams.XBounds[0] = 0.0;
  c_this->RectificationParams.XBounds[1] = 0.0;
  c_this->RectificationParams.YBounds[0] = 0.0;
  c_this->RectificationParams.YBounds[1] = 0.0;
  c_this->RectificationParams.Initialized = false;
  c_this->RectificationParams.OriginalImageSize[0] = 0.0;
  c_this->RectificationParams.OriginalImageSize[1] = 0.0;
  i = c_this->RectificationParams.OutputView->size[0] *
    c_this->RectificationParams.OutputView->size[1];
  c_this->RectificationParams.OutputView->size[0] = 1;
  c_this->RectificationParams.OutputView->size[1] = 4;
  emxEnsureCapacity_char_T(c_this->RectificationParams.OutputView, i);
  c_this->RectificationParams.OutputView->data[0] = 'f';
  c_this->RectificationParams.OutputView->data[1] = 'u';
  c_this->RectificationParams.OutputView->data[2] = 'l';
  c_this->RectificationParams.OutputView->data[3] = 'l';
  i = c_this->RectificationParams.OutputView->size[0] *
    c_this->RectificationParams.OutputView->size[1];
  c_this->RectificationParams.OutputView->size[0] = 1;
  c_this->RectificationParams.OutputView->size[1] = 5;
  emxEnsureCapacity_char_T(c_this->RectificationParams.OutputView, i);
  for (i = 0; i < 5; i++) {
    c_this->RectificationParams.OutputView->data[i] = cv[i];
  }

  for (i = 0; i < 9; i++) {
    c_this->RectificationParams.H1.T[i] = T[i];
  }

  for (i = 0; i < 9; i++) {
    c_this->RectificationParams.H2.T[i] = T[i];
  }

  c_ImageTransformer_ImageTransfo(&c_this->RectifyMap1);
  c_ImageTransformer_ImageTransfo(&c_this->RectifyMap2);
  for (i = 0; i < 3; i++) {
    iobj_0->IntrinsicMatrixInternal[3 * i] = j_varargin_1_CameraParameters1_[i];
    iobj_0->IntrinsicMatrixInternal[3 * i + 1] =
      j_varargin_1_CameraParameters1_[i + 3];
    iobj_0->IntrinsicMatrixInternal[3 * i + 2] =
      j_varargin_1_CameraParameters1_[i + 6];
  }

  iobj_0->RadialDistortion[0] = c_varargin_1_CameraParameters1_[0];
  iobj_0->RadialDistortion[1] = c_varargin_1_CameraParameters1_[1];
  iobj_0->TangentialDistortion[0] = d_varargin_1_CameraParameters1_[0];
  iobj_0->TangentialDistortion[1] = d_varargin_1_CameraParameters1_[1];
  iobj_0->ImageSize[0] = e_varargin_1_CameraParameters1_[0];
  iobj_0->ImageSize[1] = e_varargin_1_CameraParameters1_[1];
  for (i = 0; i < 114; i++) {
    iobj_0->RotationVectors[i] = h_varargin_1_CameraParameters1_[i];
  }

  for (i = 0; i < 114; i++) {
    iobj_0->TranslationVectors[i] = i_varargin_1_CameraParameters1_[i];
  }

  for (i = 0; i < 11; i++) {
    iobj_0->WorldUnits[i] = f_varargin_1_CameraParameters1_[i];
  }

  iobj_0->NumRadialDistortionCoefficients = g_varargin_1_CameraParameters1_;
  for (i = 0; i < 3; i++) {
    iobj_1->IntrinsicMatrixInternal[3 * i] =
      varargin_1_CameraParameters2->IntrinsicMatrix[i];
    iobj_1->IntrinsicMatrixInternal[3 * i + 1] =
      varargin_1_CameraParameters2->IntrinsicMatrix[i + 3];
    iobj_1->IntrinsicMatrixInternal[3 * i + 2] =
      varargin_1_CameraParameters2->IntrinsicMatrix[i + 6];
  }

  iobj_1->RadialDistortion[0] = varargin_1_CameraParameters2->RadialDistortion[0];
  iobj_1->RadialDistortion[1] = varargin_1_CameraParameters2->RadialDistortion[1];
  iobj_1->TangentialDistortion[0] =
    varargin_1_CameraParameters2->TangentialDistortion[0];
  iobj_1->TangentialDistortion[1] =
    varargin_1_CameraParameters2->TangentialDistortion[1];
  iobj_1->ImageSize[0] = varargin_1_CameraParameters2->ImageSize[0];
  iobj_1->ImageSize[1] = varargin_1_CameraParameters2->ImageSize[1];
  for (i = 0; i < 114; i++) {
    iobj_1->RotationVectors[i] = varargin_1_CameraParameters2->RotationVectors[i];
  }

  for (i = 0; i < 114; i++) {
    iobj_1->TranslationVectors[i] =
      varargin_1_CameraParameters2->TranslationVectors[i];
  }

  for (i = 0; i < 11; i++) {
    iobj_1->WorldUnits[i] = varargin_1_CameraParameters2->WorldUnits[i];
  }

  iobj_1->NumRadialDistortionCoefficients =
    varargin_1_CameraParameters2->NumRadialDistortionCoefficients;
  if (varargin_1_RectificationParams->Initialized) {
    std::memcpy(&obj_T[0], &varargin_1_RectificationParams->H1[0], 9U * sizeof
                (double));
    std::memcpy(&self_T[0], &varargin_1_RectificationParams->H2[0], 9U * sizeof
                (double));
    c_this->RectificationParams.Initialized = true;
    c_this->RectificationParams.OriginalImageSize[0] =
      varargin_1_RectificationParams->OriginalImageSize[0];
    c_this->RectificationParams.OriginalImageSize[1] =
      varargin_1_RectificationParams->OriginalImageSize[1];
    for (i = 0; i < 9; i++) {
      c_this->RectificationParams.H1.T[i] = obj_T[i];
    }

    for (i = 0; i < 9; i++) {
      c_this->RectificationParams.H2.T[i] = self_T[i];
    }

    for (i = 0; i < 16; i++) {
      c_this->RectificationParams.Q[i] = varargin_1_RectificationParams->Q[i];
    }

    i = c_this->RectificationParams.OutputView->size[0] *
      c_this->RectificationParams.OutputView->size[1];
    c_this->RectificationParams.OutputView->size[0] = 1;
    c_this->RectificationParams.OutputView->size[1] = 5;
    emxEnsureCapacity_char_T(c_this->RectificationParams.OutputView, i);
    for (i = 0; i < 5; i++) {
      c_this->RectificationParams.OutputView->data[i] =
        varargin_1_RectificationParams->OutputView[i];
    }

    c_this->RectificationParams.XBounds[0] =
      varargin_1_RectificationParams->XBounds[0];
    c_this->RectificationParams.XBounds[1] =
      varargin_1_RectificationParams->XBounds[1];
    c_this->RectificationParams.YBounds[0] =
      varargin_1_RectificationParams->YBounds[0];
    c_this->RectificationParams.YBounds[1] =
      varargin_1_RectificationParams->YBounds[1];
  }

  c_this->CameraParameters1 = iobj_0;
  c_this->CameraParameters2 = iobj_1;
  for (i = 0; i < 9; i++) {
    c_this->RotationOfCamera2[i] = varargin_1_RotationOfCamera2[i];
  }

  c_this->TranslationOfCamera2[0] = varargin_1_TranslationOfCamera2[0];
  c_this->TranslationOfCamera2[1] = varargin_1_TranslationOfCamera2[1];
  c_this->TranslationOfCamera2[2] = varargin_1_TranslationOfCamera2[2];
  return c_this;
}

//
// Arguments    : c_vision_internal_calibration_S *b_this
//                const double imageSize[2]
//                projective2d *Hleft
//                projective2d *Hright
//                double Q[16]
//                double xBounds[2]
//                double yBounds[2]
//                boolean_T *success
// Return Type  : void
//
void c_StereoParametersImpl_computeR(c_vision_internal_calibration_S *b_this,
  const double imageSize[2], projective2d *Hleft, projective2d *Hright, double
  Q[16], double xBounds[2], double yBounds[2], boolean_T *success)
{
  double Rl[9];
  double Rr[9];
  double maxval;
  double a21;
  double b_idx_2;
  int Rl_tmp;
  double t[3];
  double RrowAlign[9];
  d_vision_internal_calibration_C *c_this;
  double intrinsicMatrix[9];
  double Kl[9];
  double K_new[9];
  double Kr[9];
  int r1;
  int b_Rl_tmp;
  int r2;
  int r3;
  double y[9];
  int rtemp;
  int k;
  double xBoundsUndistort1[2];
  double yBoundsUndistort1[2];
  double xBoundsUndistort2[2];
  double yBoundsUndistort2[2];
  double b_xBoundsUndistort1[12];
  double X[12];
  double b_RrowAlign[3];
  double b_X[12];
  c_StereoParametersImpl_computeH(b_this, Rl, Rr);
  maxval = b_this->TranslationOfCamera2[0];
  a21 = b_this->TranslationOfCamera2[1];
  b_idx_2 = b_this->TranslationOfCamera2[2];
  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    t[Rl_tmp] = (Rr[Rl_tmp] * maxval + Rr[Rl_tmp + 3] * a21) + Rr[Rl_tmp + 6] *
      b_idx_2;
  }

  computeRowAlignmentRotation(t, RrowAlign);
  c_this = b_this->CameraParameters1;
  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    intrinsicMatrix[3 * Rl_tmp] = c_this->IntrinsicMatrixInternal[Rl_tmp];
    intrinsicMatrix[3 * Rl_tmp + 1] = c_this->IntrinsicMatrixInternal[Rl_tmp + 3];
    intrinsicMatrix[3 * Rl_tmp + 2] = c_this->IntrinsicMatrixInternal[Rl_tmp + 6];
  }

  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    Kl[3 * Rl_tmp] = intrinsicMatrix[Rl_tmp];
    Kl[3 * Rl_tmp + 1] = intrinsicMatrix[Rl_tmp + 3];
    Kl[3 * Rl_tmp + 2] = intrinsicMatrix[Rl_tmp + 6];
  }

  c_this = b_this->CameraParameters2;
  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    intrinsicMatrix[3 * Rl_tmp] = c_this->IntrinsicMatrixInternal[Rl_tmp];
    intrinsicMatrix[3 * Rl_tmp + 1] = c_this->IntrinsicMatrixInternal[Rl_tmp + 3];
    intrinsicMatrix[3 * Rl_tmp + 2] = c_this->IntrinsicMatrixInternal[Rl_tmp + 6];
  }

  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    Kr[3 * Rl_tmp] = intrinsicMatrix[Rl_tmp];
    Kr[3 * Rl_tmp + 1] = intrinsicMatrix[Rl_tmp + 3];
    Kr[3 * Rl_tmp + 2] = intrinsicMatrix[Rl_tmp + 6];
  }

  c_StereoParametersImpl_computeN(b_this, K_new);
  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    maxval = RrowAlign[Rl_tmp + 3];
    a21 = RrowAlign[Rl_tmp + 6];
    for (b_Rl_tmp = 0; b_Rl_tmp < 3; b_Rl_tmp++) {
      intrinsicMatrix[Rl_tmp + 3 * b_Rl_tmp] = (RrowAlign[Rl_tmp] * Rl[3 *
        b_Rl_tmp] + maxval * Rl[3 * b_Rl_tmp + 1]) + a21 * Rl[3 * b_Rl_tmp + 2];
    }
  }

  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    maxval = K_new[Rl_tmp + 3];
    a21 = K_new[Rl_tmp + 6];
    for (b_Rl_tmp = 0; b_Rl_tmp < 3; b_Rl_tmp++) {
      y[Rl_tmp + 3 * b_Rl_tmp] = (K_new[Rl_tmp] * intrinsicMatrix[3 * b_Rl_tmp]
        + maxval * intrinsicMatrix[3 * b_Rl_tmp + 1]) + a21 * intrinsicMatrix[3 *
        b_Rl_tmp + 2];
    }
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(Kl[0]);
  a21 = std::abs(Kl[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(Kl[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  Kl[r2] /= Kl[r1];
  Kl[r3] /= Kl[r1];
  Kl[r2 + 3] -= Kl[r2] * Kl[r1 + 3];
  Kl[r3 + 3] -= Kl[r3] * Kl[r1 + 3];
  Kl[r2 + 6] -= Kl[r2] * Kl[r1 + 6];
  Kl[r3 + 6] -= Kl[r3] * Kl[r1 + 6];
  if (std::abs(Kl[r3 + 3]) > std::abs(Kl[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  Kl[r3 + 3] /= Kl[r2 + 3];
  Kl[r3 + 6] -= Kl[r3 + 3] * Kl[r2 + 6];
  for (k = 0; k < 3; k++) {
    rtemp = k + 3 * r1;
    Rl[rtemp] = y[k] / Kl[r1];
    Rl_tmp = k + 3 * r2;
    Rl[Rl_tmp] = y[k + 3] - Rl[rtemp] * Kl[r1 + 3];
    b_Rl_tmp = k + 3 * r3;
    Rl[b_Rl_tmp] = y[k + 6] - Rl[rtemp] * Kl[r1 + 6];
    Rl[Rl_tmp] /= Kl[r2 + 3];
    Rl[b_Rl_tmp] -= Rl[Rl_tmp] * Kl[r2 + 6];
    Rl[b_Rl_tmp] /= Kl[r3 + 6];
    Rl[Rl_tmp] -= Rl[b_Rl_tmp] * Kl[r3 + 3];
    Rl[rtemp] -= Rl[b_Rl_tmp] * Kl[r3];
    Rl[rtemp] -= Rl[Rl_tmp] * Kl[r2];
    maxval = RrowAlign[k + 3];
    a21 = RrowAlign[k + 6];
    for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
      b_Rl_tmp = k + 3 * Rl_tmp;
      Hleft->T[Rl_tmp + 3 * k] = Rl[b_Rl_tmp];
      intrinsicMatrix[b_Rl_tmp] = (RrowAlign[k] * Rr[3 * Rl_tmp] + maxval * Rr[3
        * Rl_tmp + 1]) + a21 * Rr[3 * Rl_tmp + 2];
    }
  }

  for (Rl_tmp = 0; Rl_tmp < 3; Rl_tmp++) {
    maxval = K_new[Rl_tmp + 3];
    a21 = K_new[Rl_tmp + 6];
    for (b_Rl_tmp = 0; b_Rl_tmp < 3; b_Rl_tmp++) {
      y[Rl_tmp + 3 * b_Rl_tmp] = (K_new[Rl_tmp] * intrinsicMatrix[3 * b_Rl_tmp]
        + maxval * intrinsicMatrix[3 * b_Rl_tmp + 1]) + a21 * intrinsicMatrix[3 *
        b_Rl_tmp + 2];
    }
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(Kr[0]);
  a21 = std::abs(Kr[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(Kr[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  Kr[r2] /= Kr[r1];
  Kr[r3] /= Kr[r1];
  Kr[r2 + 3] -= Kr[r2] * Kr[r1 + 3];
  Kr[r3 + 3] -= Kr[r3] * Kr[r1 + 3];
  Kr[r2 + 6] -= Kr[r2] * Kr[r1 + 6];
  Kr[r3 + 6] -= Kr[r3] * Kr[r1 + 6];
  if (std::abs(Kr[r3 + 3]) > std::abs(Kr[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  Kr[r3 + 3] /= Kr[r2 + 3];
  Kr[r3 + 6] -= Kr[r3 + 3] * Kr[r2 + 6];
  for (k = 0; k < 3; k++) {
    rtemp = k + 3 * r1;
    intrinsicMatrix[rtemp] = y[k] / Kr[r1];
    Rl_tmp = k + 3 * r2;
    intrinsicMatrix[Rl_tmp] = y[k + 3] - intrinsicMatrix[rtemp] * Kr[r1 + 3];
    b_Rl_tmp = k + 3 * r3;
    intrinsicMatrix[b_Rl_tmp] = y[k + 6] - intrinsicMatrix[rtemp] * Kr[r1 + 6];
    intrinsicMatrix[Rl_tmp] /= Kr[r2 + 3];
    intrinsicMatrix[b_Rl_tmp] -= intrinsicMatrix[Rl_tmp] * Kr[r2 + 6];
    intrinsicMatrix[b_Rl_tmp] /= Kr[r3 + 6];
    intrinsicMatrix[Rl_tmp] -= intrinsicMatrix[b_Rl_tmp] * Kr[r3 + 3];
    intrinsicMatrix[rtemp] -= intrinsicMatrix[b_Rl_tmp] * Kr[r3];
    intrinsicMatrix[rtemp] -= intrinsicMatrix[Rl_tmp] * Kr[r2];
    Hright->T[3 * k] = intrinsicMatrix[k];
    Hright->T[3 * k + 1] = intrinsicMatrix[k + 3];
    Hright->T[3 * k + 2] = intrinsicMatrix[k + 6];
    b_RrowAlign[k] = (RrowAlign[k] * t[0] + RrowAlign[k + 3] * t[1]) +
      RrowAlign[k + 6] * t[2];
  }

  c_CameraParametersImpl_computeU(b_this->CameraParameters1, imageSize,
    xBoundsUndistort1, yBoundsUndistort1);
  c_CameraParametersImpl_computeU(b_this->CameraParameters2, imageSize,
    xBoundsUndistort2, yBoundsUndistort2);
  b_xBoundsUndistort1[0] = xBoundsUndistort1[0];
  b_xBoundsUndistort1[4] = yBoundsUndistort1[0];
  b_xBoundsUndistort1[1] = xBoundsUndistort1[1];
  b_xBoundsUndistort1[5] = yBoundsUndistort1[0];
  b_xBoundsUndistort1[2] = xBoundsUndistort1[1];
  b_xBoundsUndistort1[6] = yBoundsUndistort1[1];
  b_xBoundsUndistort1[3] = xBoundsUndistort1[0];
  b_xBoundsUndistort1[7] = yBoundsUndistort1[1];
  for (Rl_tmp = 0; Rl_tmp < 4; Rl_tmp++) {
    b_xBoundsUndistort1[Rl_tmp + 8] = 1.0;
    maxval = b_xBoundsUndistort1[Rl_tmp + 4];
    for (b_Rl_tmp = 0; b_Rl_tmp < 3; b_Rl_tmp++) {
      X[Rl_tmp + (b_Rl_tmp << 2)] = (b_xBoundsUndistort1[Rl_tmp] * Rl[b_Rl_tmp]
        + maxval * Rl[b_Rl_tmp + 3]) + Rl[b_Rl_tmp + 6];
    }
  }

  for (rtemp = 0; rtemp < 2; rtemp++) {
    maxval = X[9];
    a21 = X[10];
    b_idx_2 = X[11];
    Rl_tmp = rtemp << 2;
    X[Rl_tmp] /= X[8];
    b_Rl_tmp = Rl_tmp + 1;
    X[b_Rl_tmp] /= maxval;
    b_Rl_tmp = Rl_tmp + 2;
    X[b_Rl_tmp] /= a21;
    Rl_tmp += 3;
    X[Rl_tmp] /= b_idx_2;
  }

  b_xBoundsUndistort1[0] = xBoundsUndistort2[0];
  b_xBoundsUndistort1[4] = yBoundsUndistort2[0];
  b_xBoundsUndistort1[1] = xBoundsUndistort2[1];
  b_xBoundsUndistort1[5] = yBoundsUndistort2[0];
  b_xBoundsUndistort1[2] = xBoundsUndistort2[1];
  b_xBoundsUndistort1[6] = yBoundsUndistort2[1];
  b_xBoundsUndistort1[3] = xBoundsUndistort2[0];
  b_xBoundsUndistort1[7] = yBoundsUndistort2[1];
  for (Rl_tmp = 0; Rl_tmp < 4; Rl_tmp++) {
    b_xBoundsUndistort1[Rl_tmp + 8] = 1.0;
    maxval = b_xBoundsUndistort1[Rl_tmp + 4];
    for (b_Rl_tmp = 0; b_Rl_tmp < 3; b_Rl_tmp++) {
      b_X[Rl_tmp + (b_Rl_tmp << 2)] = (b_xBoundsUndistort1[Rl_tmp] *
        intrinsicMatrix[b_Rl_tmp] + maxval * intrinsicMatrix[b_Rl_tmp + 3]) +
        intrinsicMatrix[b_Rl_tmp + 6];
    }
  }

  for (rtemp = 0; rtemp < 2; rtemp++) {
    maxval = b_X[9];
    a21 = b_X[10];
    b_idx_2 = b_X[11];
    Rl_tmp = rtemp << 2;
    b_X[Rl_tmp] /= b_X[8];
    b_Rl_tmp = Rl_tmp + 1;
    b_X[b_Rl_tmp] /= maxval;
    b_Rl_tmp = Rl_tmp + 2;
    b_X[b_Rl_tmp] /= a21;
    Rl_tmp += 3;
    b_X[Rl_tmp] /= b_idx_2;
  }

  computeOutputBoundsValid(*(double (*)[8])&X[0], *(double (*)[8])&b_X[0],
    xBounds, yBounds, success);
  Q[0] = 1.0;
  Q[1] = 0.0;
  Q[2] = 0.0;
  Q[3] = -(K_new[6] - xBounds[0]);
  Q[4] = 0.0;
  Q[5] = 1.0;
  Q[6] = 0.0;
  Q[7] = -(K_new[7] - yBounds[0]);
  Q[8] = 0.0;
  Q[9] = 0.0;
  Q[10] = 0.0;
  Q[11] = K_new[4];
  Q[12] = 0.0;
  Q[13] = 0.0;
  Q[14] = -1.0 / b_RrowAlign[0];
  Q[15] = 0.0;
}

//
// Arguments    : c_vision_internal_calibration_S *b_this
//                const double imageSize[2]
//                projective2d *Hleft
//                projective2d *Hright
//                double Q[16]
//                double xBounds[2]
//                double yBounds[2]
//                boolean_T *success
// Return Type  : void
//
void d_StereoParametersImpl_computeR(c_vision_internal_calibration_S *b_this,
  const double imageSize[2], projective2d *Hleft, projective2d *Hright, double
  Q[16], double xBounds[2], double yBounds[2], boolean_T *success)
{
  double Rl[9];
  double Rr[9];
  double maxval;
  double a21;
  double b_idx_2;
  int i;
  double t[3];
  double RrowAlign[9];
  d_vision_internal_calibration_C *c_this;
  double intrinsicMatrix[9];
  double Kl[9];
  double K_new[9];
  double Kr[9];
  int r1;
  int i1;
  int r2;
  int r3;
  int rtemp;
  int k;
  int intrinsicMatrix_tmp;
  int b_intrinsicMatrix_tmp;
  double minXY[2];
  double maxXY[2];
  double xBoundsUndistort2[2];
  double yBoundsUndistort2[2];
  double b_minXY[12];
  double X[12];
  double b_RrowAlign[3];
  double b_X[12];
  double d;
  double d1;
  double d2;
  boolean_T b;
  boolean_T b1;
  double d3;
  c_StereoParametersImpl_computeH(b_this, Rl, Rr);
  maxval = b_this->TranslationOfCamera2[0];
  a21 = b_this->TranslationOfCamera2[1];
  b_idx_2 = b_this->TranslationOfCamera2[2];
  for (i = 0; i < 3; i++) {
    t[i] = (Rr[i] * maxval + Rr[i + 3] * a21) + Rr[i + 6] * b_idx_2;
  }

  computeRowAlignmentRotation(t, RrowAlign);
  c_this = b_this->CameraParameters1;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = c_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = c_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = c_this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 3; i++) {
    Kl[3 * i] = intrinsicMatrix[i];
    Kl[3 * i + 1] = intrinsicMatrix[i + 3];
    Kl[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  c_this = b_this->CameraParameters2;
  for (i = 0; i < 3; i++) {
    intrinsicMatrix[3 * i] = c_this->IntrinsicMatrixInternal[i];
    intrinsicMatrix[3 * i + 1] = c_this->IntrinsicMatrixInternal[i + 3];
    intrinsicMatrix[3 * i + 2] = c_this->IntrinsicMatrixInternal[i + 6];
  }

  for (i = 0; i < 3; i++) {
    Kr[3 * i] = intrinsicMatrix[i];
    Kr[3 * i + 1] = intrinsicMatrix[i + 3];
    Kr[3 * i + 2] = intrinsicMatrix[i + 6];
  }

  c_StereoParametersImpl_computeN(b_this, K_new);
  for (i = 0; i < 3; i++) {
    maxval = RrowAlign[i + 3];
    a21 = RrowAlign[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      intrinsicMatrix[i + 3 * i1] = (RrowAlign[i] * Rl[3 * i1] + maxval * Rl[3 *
        i1 + 1]) + a21 * Rl[3 * i1 + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    maxval = K_new[i + 3];
    a21 = K_new[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      Rl[i + 3 * i1] = (K_new[i] * intrinsicMatrix[3 * i1] + maxval *
                        intrinsicMatrix[3 * i1 + 1]) + a21 * intrinsicMatrix[3 *
        i1 + 2];
    }
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(Kl[0]);
  a21 = std::abs(Kl[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(Kl[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  Kl[r2] /= Kl[r1];
  Kl[r3] /= Kl[r1];
  Kl[r2 + 3] -= Kl[r2] * Kl[r1 + 3];
  Kl[r3 + 3] -= Kl[r3] * Kl[r1 + 3];
  Kl[r2 + 6] -= Kl[r2] * Kl[r1 + 6];
  Kl[r3 + 6] -= Kl[r3] * Kl[r1 + 6];
  if (std::abs(Kl[r3 + 3]) > std::abs(Kl[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  Kl[r3 + 3] /= Kl[r2 + 3];
  Kl[r3 + 6] -= Kl[r3 + 3] * Kl[r2 + 6];
  for (k = 0; k < 3; k++) {
    rtemp = k + 3 * r1;
    intrinsicMatrix[rtemp] = Rl[k] / Kl[r1];
    intrinsicMatrix_tmp = k + 3 * r2;
    intrinsicMatrix[intrinsicMatrix_tmp] = Rl[k + 3] - intrinsicMatrix[rtemp] *
      Kl[r1 + 3];
    b_intrinsicMatrix_tmp = k + 3 * r3;
    intrinsicMatrix[b_intrinsicMatrix_tmp] = Rl[k + 6] - intrinsicMatrix[rtemp] *
      Kl[r1 + 6];
    intrinsicMatrix[intrinsicMatrix_tmp] /= Kl[r2 + 3];
    intrinsicMatrix[b_intrinsicMatrix_tmp] -=
      intrinsicMatrix[intrinsicMatrix_tmp] * Kl[r2 + 6];
    intrinsicMatrix[b_intrinsicMatrix_tmp] /= Kl[r3 + 6];
    intrinsicMatrix[intrinsicMatrix_tmp] -=
      intrinsicMatrix[b_intrinsicMatrix_tmp] * Kl[r3 + 3];
    intrinsicMatrix[rtemp] -= intrinsicMatrix[b_intrinsicMatrix_tmp] * Kl[r3];
    intrinsicMatrix[rtemp] -= intrinsicMatrix[intrinsicMatrix_tmp] * Kl[r2];
    maxval = RrowAlign[k + 3];
    a21 = RrowAlign[k + 6];
    for (i = 0; i < 3; i++) {
      i1 = k + 3 * i;
      Hleft->T[i + 3 * k] = intrinsicMatrix[i1];
      intrinsicMatrix[i1] = (RrowAlign[k] * Rr[3 * i] + maxval * Rr[3 * i + 1])
        + a21 * Rr[3 * i + 2];
    }
  }

  for (i = 0; i < 3; i++) {
    maxval = K_new[i + 3];
    a21 = K_new[i + 6];
    for (i1 = 0; i1 < 3; i1++) {
      Rl[i + 3 * i1] = (K_new[i] * intrinsicMatrix[3 * i1] + maxval *
                        intrinsicMatrix[3 * i1 + 1]) + a21 * intrinsicMatrix[3 *
        i1 + 2];
    }
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(Kr[0]);
  a21 = std::abs(Kr[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(Kr[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  Kr[r2] /= Kr[r1];
  Kr[r3] /= Kr[r1];
  Kr[r2 + 3] -= Kr[r2] * Kr[r1 + 3];
  Kr[r3 + 3] -= Kr[r3] * Kr[r1 + 3];
  Kr[r2 + 6] -= Kr[r2] * Kr[r1 + 6];
  Kr[r3 + 6] -= Kr[r3] * Kr[r1 + 6];
  if (std::abs(Kr[r3 + 3]) > std::abs(Kr[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  Kr[r3 + 3] /= Kr[r2 + 3];
  Kr[r3 + 6] -= Kr[r3 + 3] * Kr[r2 + 6];
  for (k = 0; k < 3; k++) {
    rtemp = k + 3 * r1;
    intrinsicMatrix[rtemp] = Rl[k] / Kr[r1];
    intrinsicMatrix_tmp = k + 3 * r2;
    intrinsicMatrix[intrinsicMatrix_tmp] = Rl[k + 3] - intrinsicMatrix[rtemp] *
      Kr[r1 + 3];
    b_intrinsicMatrix_tmp = k + 3 * r3;
    intrinsicMatrix[b_intrinsicMatrix_tmp] = Rl[k + 6] - intrinsicMatrix[rtemp] *
      Kr[r1 + 6];
    intrinsicMatrix[intrinsicMatrix_tmp] /= Kr[r2 + 3];
    intrinsicMatrix[b_intrinsicMatrix_tmp] -=
      intrinsicMatrix[intrinsicMatrix_tmp] * Kr[r2 + 6];
    intrinsicMatrix[b_intrinsicMatrix_tmp] /= Kr[r3 + 6];
    intrinsicMatrix[intrinsicMatrix_tmp] -=
      intrinsicMatrix[b_intrinsicMatrix_tmp] * Kr[r3 + 3];
    intrinsicMatrix[rtemp] -= intrinsicMatrix[b_intrinsicMatrix_tmp] * Kr[r3];
    intrinsicMatrix[rtemp] -= intrinsicMatrix[intrinsicMatrix_tmp] * Kr[r2];
    Hright->T[3 * k] = intrinsicMatrix[k];
    Hright->T[3 * k + 1] = intrinsicMatrix[k + 3];
    Hright->T[3 * k + 2] = intrinsicMatrix[k + 6];
    b_RrowAlign[k] = (RrowAlign[k] * t[0] + RrowAlign[k + 3] * t[1]) +
      RrowAlign[k + 6] * t[2];
  }

  d_CameraParametersImpl_computeU(b_this->CameraParameters1, imageSize, minXY,
    maxXY);
  d_CameraParametersImpl_computeU(b_this->CameraParameters2, imageSize,
    xBoundsUndistort2, yBoundsUndistort2);
  b_minXY[0] = minXY[0];
  b_minXY[4] = maxXY[0];
  b_minXY[1] = minXY[1];
  b_minXY[5] = maxXY[0];
  b_minXY[2] = minXY[1];
  b_minXY[6] = maxXY[1];
  b_minXY[3] = minXY[0];
  b_minXY[7] = maxXY[1];
  for (i = 0; i < 4; i++) {
    b_minXY[i + 8] = 1.0;
    maxval = b_minXY[i + 4];
    for (i1 = 0; i1 < 3; i1++) {
      X[i + (i1 << 2)] = (b_minXY[i] * Hleft->T[3 * i1] + maxval * Hleft->T[3 *
                          i1 + 1]) + Hleft->T[3 * i1 + 2];
    }
  }

  for (rtemp = 0; rtemp < 2; rtemp++) {
    maxval = X[9];
    a21 = X[10];
    b_idx_2 = X[11];
    i = rtemp << 2;
    X[i] /= X[8];
    i1 = i + 1;
    X[i1] /= maxval;
    i1 = i + 2;
    X[i1] /= a21;
    i += 3;
    X[i] /= b_idx_2;
  }

  b_minXY[0] = xBoundsUndistort2[0];
  b_minXY[4] = yBoundsUndistort2[0];
  b_minXY[1] = xBoundsUndistort2[1];
  b_minXY[5] = yBoundsUndistort2[0];
  b_minXY[2] = xBoundsUndistort2[1];
  b_minXY[6] = yBoundsUndistort2[1];
  b_minXY[3] = xBoundsUndistort2[0];
  b_minXY[7] = yBoundsUndistort2[1];
  for (i = 0; i < 4; i++) {
    b_minXY[i + 8] = 1.0;
    maxval = b_minXY[i + 4];
    for (i1 = 0; i1 < 3; i1++) {
      b_X[i + (i1 << 2)] = (b_minXY[i] * Hright->T[3 * i1] + maxval * Hright->T
                            [3 * i1 + 1]) + Hright->T[3 * i1 + 2];
    }
  }

  for (rtemp = 0; rtemp < 2; rtemp++) {
    maxval = b_X[9];
    a21 = b_X[10];
    b_idx_2 = b_X[11];
    i = rtemp << 2;
    d = b_X[i] / b_X[8];
    d1 = d;
    b_X[i] = d;
    i1 = i + 1;
    d = b_X[i1] / maxval;
    maxval = d;
    b_X[i1] = d;
    intrinsicMatrix_tmp = i + 2;
    d = b_X[intrinsicMatrix_tmp] / a21;
    a21 = d;
    b_X[intrinsicMatrix_tmp] = d;
    b_intrinsicMatrix_tmp = i + 3;
    d = b_X[b_intrinsicMatrix_tmp] / b_idx_2;
    b_X[b_intrinsicMatrix_tmp] = d;
    b_idx_2 = X[i];
    d2 = X[i];
    b = !rtIsNaN(X[i1]);
    b1 = rtIsNaN(X[i]);
    if (b && (b1 || (X[i] > X[i1]))) {
      b_idx_2 = X[i1];
    }

    if (b && (b1 || (X[i] < X[i1]))) {
      d2 = X[i1];
    }

    b = !rtIsNaN(X[intrinsicMatrix_tmp]);
    if (b && (rtIsNaN(b_idx_2) || (b_idx_2 > X[intrinsicMatrix_tmp]))) {
      b_idx_2 = X[intrinsicMatrix_tmp];
    }

    if (b && (rtIsNaN(d2) || (d2 < X[intrinsicMatrix_tmp]))) {
      d2 = X[intrinsicMatrix_tmp];
    }

    b = !rtIsNaN(X[b_intrinsicMatrix_tmp]);
    if (b && (rtIsNaN(b_idx_2) || (b_idx_2 > X[b_intrinsicMatrix_tmp]))) {
      b_idx_2 = X[b_intrinsicMatrix_tmp];
    }

    if (b && (rtIsNaN(d2) || (d2 < X[b_intrinsicMatrix_tmp]))) {
      d2 = X[b_intrinsicMatrix_tmp];
    }

    d3 = d1;
    b = !rtIsNaN(maxval);
    b1 = rtIsNaN(d1);
    if (b && (b1 || (d1 > maxval))) {
      d3 = maxval;
    }

    if (b && (b1 || (d1 < maxval))) {
      d1 = maxval;
    }

    b = !rtIsNaN(a21);
    if (b && (rtIsNaN(d3) || (d3 > a21))) {
      d3 = a21;
    }

    if (b && (rtIsNaN(d1) || (d1 < a21))) {
      d1 = a21;
    }

    b = !rtIsNaN(d);
    if (b && (rtIsNaN(d3) || (d3 > d))) {
      d3 = d;
    }

    if (b && (rtIsNaN(d1) || (d1 < d))) {
      d1 = d;
    }

    if ((!rtIsNaN(d3)) && (rtIsNaN(b_idx_2) || (b_idx_2 > d3))) {
      b_idx_2 = d3;
    }

    b_idx_2 = rt_roundd_snf(b_idx_2);
    minXY[rtemp] = b_idx_2;
    if ((!rtIsNaN(d1)) && (rtIsNaN(d2) || (d2 < d1))) {
      d2 = d1;
    }

    d2 = rt_roundd_snf(d2);
    maxXY[rtemp] = d2;
  }

  xBounds[0] = minXY[0];
  xBounds[1] = maxXY[0];
  yBounds[0] = minXY[1];
  yBounds[1] = maxXY[1];
  if ((minXY[0] >= maxXY[0]) || (minXY[1] >= maxXY[1])) {
    *success = false;
  } else {
    *success = true;
  }

  Q[0] = 1.0;
  Q[1] = 0.0;
  Q[2] = 0.0;
  Q[3] = -(K_new[6] - minXY[0]);
  Q[4] = 0.0;
  Q[5] = 1.0;
  Q[6] = 0.0;
  Q[7] = -(K_new[7] - minXY[1]);
  Q[8] = 0.0;
  Q[9] = 0.0;
  Q[10] = 0.0;
  Q[11] = K_new[4];
  Q[12] = 0.0;
  Q[13] = 0.0;
  Q[14] = -1.0 / b_RrowAlign[0];
  Q[15] = 0.0;
}

//
// File trailer for StereoParametersImpl.cpp
//
// [EOF]
//
