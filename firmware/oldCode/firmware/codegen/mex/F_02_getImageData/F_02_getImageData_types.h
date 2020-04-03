/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * F_02_getImageData_types.h
 *
 * Code generation for function 'F_02_getImageData_types'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_F_02_getImageDataStackData
#define typedef_F_02_getImageDataStackData

typedef struct {
  union
  {
    struct {
      uint8_T inputImage[307200];
    } f0;

    struct {
      real_T centeredPoints[614400];
      real_T distortedNormalizedPoints[614400];
    } f1;
  } u1;

  union
  {
    struct {
      real_T allPts[2457600];
      real_T X[614400];
      real_T ptsOut[614400];
      real_T b_X[307200];
      real_T Y[307200];
      real_T b_ptsOut[307200];
      real_T x[307200];
      boolean_T bv[1228800];
      boolean_T bv1[1228800];
      int8_T mask[307200];
    } f2;

    struct {
      real_T allPts[2457600];
      real_T X[614400];
      real_T ptsOut[614400];
      real_T b_X[307200];
      real_T Y[307200];
      real_T b_ptsOut[307200];
      real_T x[307200];
      boolean_T bv[1228800];
      boolean_T bv1[1228800];
      int8_T mask[307200];
    } f3;
  } u2;

  struct {
    real_T frameCelciusRect[307200];
    uint8_T frameLeft[921600];
    uint8_T frameRight[921600];
  } f4;
} F_02_getImageDataStackData;

#endif                                 /*typedef_F_02_getImageDataStackData*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  real_T Area;
  real_T Centroid[2];
  real_T BoundingBox[4];
  real_T MajorAxisLength;
  real_T MinorAxisLength;
  real_T Eccentricity;
  real_T Orientation;
  emxArray_boolean_T *Image;
  emxArray_boolean_T *FilledImage;
  real_T FilledArea;
  real_T EulerNumber;
  real_T Extrema[16];
  real_T EquivDiameter;
  real_T Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  real_T Perimeter;
  real_T Circularity;
  emxArray_real_T *PixelValues;
  real_T WeightedCentroid[2];
  real_T MeanIntensity;
  real_T MinIntensity;
  real_T MaxIntensity;
  emxArray_real_T *SubarrayIdx;
  real_T SubarrayIdxLengths[2];
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T

typedef struct {
  c_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;

#endif                                 /*typedef_b_emxArray_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  real_T Centroid[2];
  real_T BoundingBox[4];
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/

#ifndef typedef_c_vision_internal_calibration_I
#define typedef_c_vision_internal_calibration_I

typedef struct {
  emxArray_real_T *Xmap;
  emxArray_real_T *Ymap;
  emxArray_real32_T *XmapSingle;
  emxArray_real32_T *YmapSingle;
  emxArray_real_T *SizeOfImage;
  emxArray_char_T *ClassOfImage;
  emxArray_char_T *OutputView;
  real_T XBounds[2];
  real_T YBounds[2];
} c_vision_internal_calibration_I;

#endif                                 /*typedef_c_vision_internal_calibration_I*/

#ifndef typedef_c_vision_internal_calibration_C
#define typedef_c_vision_internal_calibration_C

typedef struct {
  real_T ImageSize[2];
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T NumRadialDistortionCoefficients;
  real_T TranslationVectors[84];
  real_T RotationVectors[84];
  c_vision_internal_calibration_I UndistortMap;
  real_T IntrinsicMatrixInternal[9];
} c_vision_internal_calibration_C;

#endif                                 /*typedef_c_vision_internal_calibration_C*/

#ifndef typedef_projective2d
#define typedef_projective2d

typedef struct {
  boolean_T IsBidirectional;
  real_T T[9];
} projective2d;

#endif                                 /*typedef_projective2d*/

#ifndef typedef_c_vision_internal_calibration_R
#define typedef_c_vision_internal_calibration_R

typedef struct {
  projective2d H1;
  projective2d H2;
  real_T Q[16];
  real_T XBounds[2];
  real_T YBounds[2];
  boolean_T Initialized;
  real_T OriginalImageSize[2];
  emxArray_char_T *OutputView;
} c_vision_internal_calibration_R;

#endif                                 /*typedef_c_vision_internal_calibration_R*/

#ifndef typedef_d_vision_internal_calibration_C
#define typedef_d_vision_internal_calibration_C

typedef struct {
  real_T ImageSize[2];
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  char_T WorldUnits[11];
  real_T NumRadialDistortionCoefficients;
  real_T TranslationVectors[114];
  real_T RotationVectors[114];
  real_T IntrinsicMatrixInternal[9];
} d_vision_internal_calibration_C;

#endif                                 /*typedef_d_vision_internal_calibration_C*/

#ifndef typedef_c_vision_internal_calibration_S
#define typedef_c_vision_internal_calibration_S

typedef struct {
  d_vision_internal_calibration_C *CameraParameters1;
  d_vision_internal_calibration_C *CameraParameters2;
  real_T RotationOfCamera2[9];
  real_T TranslationOfCamera2[3];
  c_vision_internal_calibration_I RectifyMap1;
  c_vision_internal_calibration_I RectifyMap2;
  c_vision_internal_calibration_R RectificationParams;
} c_vision_internal_calibration_S;

#endif                                 /*typedef_c_vision_internal_calibration_S*/

#ifndef struct_emxArray_int16_T
#define struct_emxArray_int16_T

struct emxArray_int16_T
{
  int16_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int16_T*/

#ifndef typedef_emxArray_int16_T
#define typedef_emxArray_int16_T

typedef struct emxArray_int16_T emxArray_int16_T;

#endif                                 /*typedef_emxArray_int16_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T

struct emxArray_int8_T
{
  int8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int8_T*/

#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T

typedef struct emxArray_int8_T emxArray_int8_T;

#endif                                 /*typedef_emxArray_int8_T*/

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T

typedef struct {
  b_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;

#endif                                 /*typedef_emxArray_struct_T*/

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T

struct emxArray_uint32_T
{
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint32_T*/

#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T

typedef struct emxArray_uint32_T emxArray_uint32_T;

#endif                                 /*typedef_emxArray_uint32_T*/

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif                                 /*typedef_emxArray_uint8_T*/

#ifndef typedef_images_internal_coder_imref2d
#define typedef_images_internal_coder_imref2d

typedef struct {
  real_T XWorldLimits[2];
  real_T YWorldLimits[2];
  real_T ImageSizeAlias[2];
  boolean_T ForcePixelExtentToOne;
} images_internal_coder_imref2d;

#endif                                 /*typedef_images_internal_coder_imref2d*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  char_T Name[23];
  char_T Version[3];
  char_T Release[8];
  char_T Date[11];
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  real_T WorldPoints[84];
  char_T WorldUnits[11];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  real_T RotationVectors[114];
  real_T TranslationVectors[114];
  real_T ReprojectionErrors[3192];
  real_T IntrinsicMatrix[9];
  struct2_T Version;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  boolean_T Initialized;
  real_T H1[9];
  real_T H2[9];
  real_T Q[16];
  real_T XBounds[2];
  real_T YBounds[2];
  real_T OriginalImageSize[2];
  char_T OutputView[5];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T CameraParameters1;
  struct1_T CameraParameters2;
  real_T RotationOfCamera2[9];
  real_T TranslationOfCamera2[3];
  struct2_T Version;
  struct3_T RectificationParams;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T RadialDistortion[2];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  real_T WorldPoints[84];
  char_T WorldUnits[11];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  real_T RotationVectors[84];
  real_T TranslationVectors[84];
  real_T ReprojectionErrors[2352];
  real_T IntrinsicMatrix[9];
  struct2_T Version;
} struct4_T;

#endif                                 /*typedef_struct4_T*/

/* End of code generation (F_02_getImageData_types.h) */
