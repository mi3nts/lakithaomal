//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: F_02_getImageData_types.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef F_02_GETIMAGEDATA_TYPES_H
#define F_02_GETIMAGEDATA_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct cell_wrap_26
{
  emxArray_real_T *f1;
};

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct c_struct_T
{
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  emxArray_boolean_T *Image;
  emxArray_boolean_T *FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[16];
  double EquivDiameter;
  double Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  double Perimeter;
  double Circularity;
  emxArray_real_T *PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  double MinIntensity;
  double MaxIntensity;
  emxArray_real_T *SubarrayIdx;
  double SubarrayIdxLengths[2];
};

struct b_emxArray_struct_T
{
  c_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct d_vision_internal_calibration_C
{
  double ImageSize[2];
  double RadialDistortion[2];
  double TangentialDistortion[2];
  char WorldUnits[11];
  double NumRadialDistortionCoefficients;
  double TranslationVectors[114];
  double RotationVectors[114];
  double IntrinsicMatrixInternal[9];
};

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_real32_T
{
  float *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct b_struct_T
{
  double Centroid[2];
  double BoundingBox[4];
};

struct emxArray_struct_T
{
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_char_T
{
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct c_vision_internal_calibration_I
{
  emxArray_real_T *Xmap;
  emxArray_real_T *Ymap;
  emxArray_real32_T *XmapSingle;
  emxArray_real32_T *YmapSingle;
  emxArray_real_T *SizeOfImage;
  emxArray_char_T *ClassOfImage;
  emxArray_char_T *OutputView;
  double XBounds[2];
  double YBounds[2];
};

struct projective2d
{
  boolean_T IsBidirectional;
  double T[9];
};

struct c_vision_internal_calibration_R
{
  projective2d H1;
  projective2d H2;
  double Q[16];
  double XBounds[2];
  double YBounds[2];
  boolean_T Initialized;
  double OriginalImageSize[2];
  emxArray_char_T *OutputView;
};

struct c_vision_internal_calibration_S
{
  d_vision_internal_calibration_C *CameraParameters1;
  d_vision_internal_calibration_C *CameraParameters2;
  double RotationOfCamera2[9];
  double TranslationOfCamera2[3];
  c_vision_internal_calibration_I RectifyMap1;
  c_vision_internal_calibration_I RectifyMap2;
  c_vision_internal_calibration_R RectificationParams;
};

struct c_vision_internal_calibration_C
{
  double ImageSize[2];
  double RadialDistortion[2];
  double TangentialDistortion[2];
  double NumRadialDistortionCoefficients;
  double TranslationVectors[84];
  double RotationVectors[84];
  c_vision_internal_calibration_I UndistortMap;
  double IntrinsicMatrixInternal[9];
};

struct struct2_T
{
  char Name[23];
  char Version[3];
  char Release[8];
  char Date[11];
};

struct struct1_T
{
  double RadialDistortion[2];
  double TangentialDistortion[2];
  double ImageSize[2];
  double WorldPoints[84];
  char WorldUnits[11];
  boolean_T EstimateSkew;
  double NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  double RotationVectors[114];
  double TranslationVectors[114];
  double ReprojectionErrors[3192];
  double IntrinsicMatrix[9];
  struct2_T Version;
};

struct struct3_T
{
  boolean_T Initialized;
  double H1[9];
  double H2[9];
  double Q[16];
  double XBounds[2];
  double YBounds[2];
  double OriginalImageSize[2];
  char OutputView[5];
};

struct struct0_T
{
  struct1_T CameraParameters1;
  struct1_T CameraParameters2;
  double RotationOfCamera2[9];
  double TranslationOfCamera2[3];
  struct2_T Version;
  struct3_T RectificationParams;
};

struct struct4_T
{
  double RadialDistortion[2];
  double TangentialDistortion[2];
  double ImageSize[2];
  double WorldPoints[84];
  char WorldUnits[11];
  boolean_T EstimateSkew;
  double NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  double RotationVectors[84];
  double TranslationVectors[84];
  double ReprojectionErrors[2352];
  double IntrinsicMatrix[9];
  struct2_T Version;
};

struct emxArray_uint8_T
{
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_int16_T
{
  short *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_int8_T
{
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

struct emxArray_uint32_T
{
  unsigned int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif

//
// File trailer for F_02_getImageData_types.h
//
// [EOF]
//
