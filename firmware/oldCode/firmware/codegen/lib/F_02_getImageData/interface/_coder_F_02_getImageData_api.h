/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_F_02_getImageData_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 04-Feb-2020 11:05:06
 */

#ifndef _CODER_F_02_GETIMAGEDATA_API_H
#define _CODER_F_02_GETIMAGEDATA_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Type Definitions */
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

#ifndef typedef_projective2d
#define typedef_projective2d

typedef struct {
  boolean_T IsBidirectional;
  real_T T[9];
} projective2d;

#endif                                 /*typedef_projective2d*/

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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void F_02_getImageData(struct0_T *stereoParamsStruct, struct4_T
  *thermalParamsStruct, projective2d transformParametors[26], emxArray_uint8_T
  *frameLeftRect, emxArray_real_T *finalCelciusImage, emxArray_real32_T
  *distanceImage);
extern void F_02_getImageData_api(const mxArray * const prhs[3], int32_T nlhs,
  const mxArray *plhs[3]);
extern void F_02_getImageData_atexit(void);
extern void F_02_getImageData_initialize(void);
extern void F_02_getImageData_terminate(void);
extern void F_02_getImageData_xil_shutdown(void);
extern void F_02_getImageData_xil_terminate(void);

#endif

/*
 * File trailer for _coder_F_02_getImageData_api.h
 *
 * [EOF]
 */
