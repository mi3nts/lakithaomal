//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
#include "main.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxAPI.h"
#include "F_02_getImageData_terminate.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Declarations
static void argInit_1x11_char_T(char result[11]);
static void argInit_1x23_char_T(char result[23]);
static void argInit_1x26_projective2d(projective2d result[26]);
static void argInit_1x2_real_T(double result[2]);
static void argInit_1x3_char_T(char result[3]);
static void argInit_1x3_real_T(double result[3]);
static void argInit_1x5_char_T(char result[5]);
static void argInit_1x8_char_T(char result[8]);
static void argInit_28x3_real_T(double result[84]);
static void argInit_38x3_real_T(double result[114]);
static void argInit_3x3_real_T(double result[9]);
static void argInit_42x2_real_T(double result[84]);
static void argInit_42x2x28_real_T(double result[2352]);
static void argInit_42x2x38_real_T(double result[3192]);
static void argInit_4x4_real_T(double result[16]);
static boolean_T argInit_boolean_T();
static char argInit_char_T();
static void argInit_projective2d(projective2d *result);
static double argInit_real_T();
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static struct2_T argInit_struct2_T();
static void argInit_struct3_T(struct3_T *result);
static void argInit_struct4_T(struct4_T *result);
static void main_F_02_getImageData();

// Function Definitions

//
// Arguments    : char result[11]
// Return Type  : void
//
static void argInit_1x11_char_T(char result[11])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 11; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_char_T();
  }
}

//
// Arguments    : char result[23]
// Return Type  : void
//
static void argInit_1x23_char_T(char result[23])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 23; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_char_T();
  }
}

//
// Arguments    : projective2d result[26]
// Return Type  : void
//
static void argInit_1x26_projective2d(projective2d result[26])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 26; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    argInit_projective2d(&result[idx1]);
  }
}

//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  double result_tmp;

  // Loop over the array to initialize each element.
  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[1] = result_tmp;
}

//
// Arguments    : char result[3]
// Return Type  : void
//
static void argInit_1x3_char_T(char result[3])
{
  char result_tmp_tmp;

  // Loop over the array to initialize each element.
  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result_tmp_tmp = argInit_char_T();
  result[0] = result_tmp_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[1] = result_tmp_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[2] = result_tmp_tmp;
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_1x3_real_T(double result[3])
{
  double result_tmp_tmp;

  // Loop over the array to initialize each element.
  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result_tmp_tmp = argInit_real_T();
  result[0] = result_tmp_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[1] = result_tmp_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[2] = result_tmp_tmp;
}

//
// Arguments    : char result[5]
// Return Type  : void
//
static void argInit_1x5_char_T(char result[5])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 5; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_char_T();
  }
}

//
// Arguments    : char result[8]
// Return Type  : void
//
static void argInit_1x8_char_T(char result[8])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 8; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_char_T();
  }
}

//
// Arguments    : double result[84]
// Return Type  : void
//
static void argInit_28x3_real_T(double result[84])
{
  int idx0;
  double result_tmp_tmp;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 28; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp_tmp = argInit_real_T();
    result[idx0] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 28] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 56] = result_tmp_tmp;
  }
}

//
// Arguments    : double result[114]
// Return Type  : void
//
static void argInit_38x3_real_T(double result[114])
{
  int idx0;
  double result_tmp_tmp;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 38; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp_tmp = argInit_real_T();
    result[idx0] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 38] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 76] = result_tmp_tmp;
  }
}

//
// Arguments    : double result[9]
// Return Type  : void
//
static void argInit_3x3_real_T(double result[9])
{
  int idx0;
  double result_tmp_tmp;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 3; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp_tmp = argInit_real_T();
    result[idx0] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 3] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 6] = result_tmp_tmp;
  }
}

//
// Arguments    : double result[84]
// Return Type  : void
//
static void argInit_42x2_real_T(double result[84])
{
  int idx0;
  double result_tmp;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 42; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 42] = result_tmp;
  }
}

//
// Arguments    : double result[2352]
// Return Type  : void
//
static void argInit_42x2x28_real_T(double result[2352])
{
  int idx0;
  int idx1;
  int idx2;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 42; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      for (idx2 = 0; idx2 < 28; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + 42 * idx1) + 84 * idx2] = argInit_real_T();
      }
    }
  }
}

//
// Arguments    : double result[3192]
// Return Type  : void
//
static void argInit_42x2x38_real_T(double result[3192])
{
  int idx0;
  int idx1;
  int idx2;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 42; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      for (idx2 = 0; idx2 < 38; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + 42 * idx1) + 84 * idx2] = argInit_real_T();
      }
    }
  }
}

//
// Arguments    : double result[16]
// Return Type  : void
//
static void argInit_4x4_real_T(double result[16])
{
  int idx0;
  double result_tmp_tmp;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 4; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp_tmp = argInit_real_T();
    result[idx0] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 4] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 8] = result_tmp_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 12] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : boolean_T
//
static boolean_T argInit_boolean_T()
{
  return false;
}

//
// Arguments    : void
// Return Type  : char
//
static char argInit_char_T()
{
  return '?';
}

//
// Arguments    : projective2d *result
// Return Type  : void
//
static void argInit_projective2d(projective2d *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result->IsBidirectional = argInit_boolean_T();
  argInit_3x3_real_T(result->T);
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T *result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T *result)
{
  struct1_T result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_struct1_T(&result_tmp);
  result->CameraParameters1 = result_tmp;
  result->CameraParameters2 = result_tmp;
  argInit_3x3_real_T(result->RotationOfCamera2);
  argInit_1x3_real_T(result->TranslationOfCamera2);
  result->Version = argInit_struct2_T();
  argInit_struct3_T(&result->RectificationParams);
}

//
// Arguments    : struct1_T *result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T *result)
{
  double result_tmp_tmp[2];
  double result_tmp[114];

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x2_real_T(result_tmp_tmp);
  result->RadialDistortion[0] = result_tmp_tmp[0];
  result->TangentialDistortion[0] = result_tmp_tmp[0];
  result->ImageSize[0] = result_tmp_tmp[0];
  result->RadialDistortion[1] = result_tmp_tmp[1];
  result->TangentialDistortion[1] = result_tmp_tmp[1];
  result->ImageSize[1] = result_tmp_tmp[1];
  argInit_42x2_real_T(result->WorldPoints);
  argInit_1x11_char_T(result->WorldUnits);
  result->EstimateSkew = argInit_boolean_T();
  result->NumRadialDistortionCoefficients = argInit_real_T();
  result->EstimateTangentialDistortion = argInit_boolean_T();
  argInit_38x3_real_T(result_tmp);
  std::memcpy(&result->RotationVectors[0], &result_tmp[0], 114U * sizeof(double));
  std::memcpy(&result->TranslationVectors[0], &result_tmp[0], 114U * sizeof
              (double));
  argInit_42x2x38_real_T(result->ReprojectionErrors);
  argInit_3x3_real_T(result->IntrinsicMatrix);
  result->Version = argInit_struct2_T();
}

//
// Arguments    : void
// Return Type  : struct2_T
//
static struct2_T argInit_struct2_T()
{
  struct2_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x23_char_T(result.Name);
  argInit_1x3_char_T(result.Version);
  argInit_1x8_char_T(result.Release);
  argInit_1x11_char_T(result.Date);
  return result;
}

//
// Arguments    : struct3_T *result
// Return Type  : void
//
static void argInit_struct3_T(struct3_T *result)
{
  double result_tmp[9];
  double result_tmp_tmp[2];

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result->Initialized = argInit_boolean_T();
  argInit_3x3_real_T(result_tmp);
  std::memcpy(&result->H1[0], &result_tmp[0], 9U * sizeof(double));
  std::memcpy(&result->H2[0], &result_tmp[0], 9U * sizeof(double));
  argInit_4x4_real_T(result->Q);
  argInit_1x2_real_T(result_tmp_tmp);
  result->XBounds[0] = result_tmp_tmp[0];
  result->YBounds[0] = result_tmp_tmp[0];
  result->OriginalImageSize[0] = result_tmp_tmp[0];
  result->XBounds[1] = result_tmp_tmp[1];
  result->YBounds[1] = result_tmp_tmp[1];
  result->OriginalImageSize[1] = result_tmp_tmp[1];
  argInit_1x5_char_T(result->OutputView);
}

//
// Arguments    : struct4_T *result
// Return Type  : void
//
static void argInit_struct4_T(struct4_T *result)
{
  double result_tmp_tmp[2];
  double result_tmp[84];

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x2_real_T(result_tmp_tmp);
  result->RadialDistortion[0] = result_tmp_tmp[0];
  result->TangentialDistortion[0] = result_tmp_tmp[0];
  result->ImageSize[0] = result_tmp_tmp[0];
  result->RadialDistortion[1] = result_tmp_tmp[1];
  result->TangentialDistortion[1] = result_tmp_tmp[1];
  result->ImageSize[1] = result_tmp_tmp[1];
  argInit_42x2_real_T(result->WorldPoints);
  argInit_1x11_char_T(result->WorldUnits);
  result->EstimateSkew = argInit_boolean_T();
  result->NumRadialDistortionCoefficients = argInit_real_T();
  result->EstimateTangentialDistortion = argInit_boolean_T();
  argInit_28x3_real_T(result_tmp);
  std::memcpy(&result->RotationVectors[0], &result_tmp[0], 84U * sizeof(double));
  std::memcpy(&result->TranslationVectors[0], &result_tmp[0], 84U * sizeof
              (double));
  argInit_42x2x28_real_T(result->ReprojectionErrors);
  argInit_3x3_real_T(result->IntrinsicMatrix);
  result->Version = argInit_struct2_T();
}

//
// Arguments    : void
// Return Type  : void
//
static void main_F_02_getImageData()
{
  emxArray_uint8_T *frameLeftRect;
  emxArray_real_T *finalCelciusImage;
  emxArray_real32_T *distanceImage;
  struct0_T r;
  struct4_T r1;
  projective2d rv[26];
  emxInitArray_uint8_T(&frameLeftRect, 3);
  emxInitArray_real_T(&finalCelciusImage, 2);
  emxInitArray_real32_T(&distanceImage, 2);

  // Initialize function 'F_02_getImageData' input arguments.
  // Initialize function input argument 'stereoParamsStruct'.
  // Initialize function input argument 'thermalParamsStruct'.
  // Initialize function input argument 'transformParametors'.
  // Call the entry-point 'F_02_getImageData'.
  argInit_struct0_T(&r);
  argInit_struct4_T(&r1);
  argInit_1x26_projective2d(rv);
  F_02_getImageData(&r, &r1, rv, frameLeftRect, finalCelciusImage, distanceImage);
  emxDestroyArray_real32_T(distanceImage);
  emxDestroyArray_real_T(finalCelciusImage);
  emxDestroyArray_uint8_T(frameLeftRect);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. 
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_F_02_getImageData();

  // Terminate the application.
  // You do not need to do this more than one time.
  F_02_getImageData_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
