//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: F_02_getImageData_emxutil.h
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//
#ifndef F_02_GETIMAGEDATA_EMXUTIL_H
#define F_02_GETIMAGEDATA_EMXUTIL_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "F_02_getImageData_types.h"

// Function Declarations
extern void c_emxFreeStruct_vision_internal(c_vision_internal_calibration_I
  *pStruct);
extern void c_emxInitStruct_vision_internal(c_vision_internal_calibration_C
  *pStruct);
extern void d_emxFreeStruct_vision_internal(c_vision_internal_calibration_S
  *pStruct);
extern void d_emxInitStruct_vision_internal(c_vision_internal_calibration_I
  *pStruct);
extern void e_emxInitStruct_vision_internal(c_vision_internal_calibration_S
  *pStruct);
extern void emxCopyStruct_struct_T(c_struct_T *dst, const c_struct_T *src);
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray, int
  oldNumel);
extern void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);
extern void emxFreeMatrix_cell_wrap_26(cell_wrap_26 pMatrix[2]);
extern void emxFreeStruct_struct_T(c_struct_T *pStruct);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_char_T(emxArray_char_T **pEmxArray);
extern void emxFree_int16_T(emxArray_int16_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);
extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_struct_T(emxArray_struct_T **pEmxArray);
extern void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray);
extern void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);
extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);
extern void emxInitMatrix_cell_wrap_26(cell_wrap_26 pMatrix[2]);
extern void emxInitStruct_struct_T(c_struct_T *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);
extern void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions);
extern void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T(emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray, int numDimensions);
extern void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions);
extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);
extern void f_emxFreeStruct_vision_internal(c_vision_internal_calibration_C
  *pStruct);

#endif

//
// File trailer for F_02_getImageData_emxutil.h
//
// [EOF]
//
