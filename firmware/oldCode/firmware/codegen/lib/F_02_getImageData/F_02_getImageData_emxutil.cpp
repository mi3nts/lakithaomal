//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: F_02_getImageData_emxutil.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "F_02_getImageData_emxutil.h"
#include "F_02_getImageData.h"
#include "rt_nonfinite.h"
#include <cstdlib>
#include <cstring>

// Function Declarations
static void e_emxFreeStruct_vision_internal(c_vision_internal_calibration_R
  *pStruct);
static void emxCopyMatrix_real_T(double dst[2], const double src[2]);
static void emxCopyMatrix_real_T1(double dst[4], const double src[4]);
static void emxCopyMatrix_real_T2(double dst[16], const double src[16]);
static void emxCopy_boolean_T(emxArray_boolean_T **dst, emxArray_boolean_T *
  const *src);
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src);
static void emxExpand_struct_T(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void emxFreeStruct_cell_wrap_26(cell_wrap_26 *pStruct);
static void emxInitStruct_cell_wrap_26(cell_wrap_26 *pStruct);
static void emxTrim_struct_T(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex);
static void f_emxInitStruct_vision_internal(c_vision_internal_calibration_R
  *pStruct);

// Function Definitions

//
// Arguments    : c_vision_internal_calibration_R *pStruct
// Return Type  : void
//
static void e_emxFreeStruct_vision_internal(c_vision_internal_calibration_R
  *pStruct)
{
  emxFree_char_T(&pStruct->OutputView);
}

//
// Arguments    : double dst[2]
//                const double src[2]
// Return Type  : void
//
static void emxCopyMatrix_real_T(double dst[2], const double src[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    dst[i] = src[i];
  }
}

//
// Arguments    : double dst[4]
//                const double src[4]
// Return Type  : void
//
static void emxCopyMatrix_real_T1(double dst[4], const double src[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    dst[i] = src[i];
  }
}

//
// Arguments    : double dst[16]
//                const double src[16]
// Return Type  : void
//
static void emxCopyMatrix_real_T2(double dst[16], const double src[16])
{
  int i;
  for (i = 0; i < 16; i++) {
    dst[i] = src[i];
  }
}

//
// Arguments    : emxArray_boolean_T **dst
//                emxArray_boolean_T * const *src
// Return Type  : void
//
static void emxCopy_boolean_T(emxArray_boolean_T **dst, emxArray_boolean_T *
  const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_boolean_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

//
// Arguments    : emxArray_real_T **dst
//                emxArray_real_T * const *src
// Return Type  : void
//
static void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T * const *src)
{
  int numElDst;
  int numElSrc;
  int i;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

//
// Arguments    : b_emxArray_struct_T *emxArray
//                int fromIndex
//                int toIndex
// Return Type  : void
//
static void emxExpand_struct_T(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T(&emxArray->data[i]);
  }
}

//
// Arguments    : cell_wrap_26 *pStruct
// Return Type  : void
//
static void emxFreeStruct_cell_wrap_26(cell_wrap_26 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

//
// Arguments    : cell_wrap_26 *pStruct
// Return Type  : void
//
static void emxInitStruct_cell_wrap_26(cell_wrap_26 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 1);
}

//
// Arguments    : b_emxArray_struct_T *emxArray
//                int fromIndex
//                int toIndex
// Return Type  : void
//
static void emxTrim_struct_T(b_emxArray_struct_T *emxArray, int fromIndex, int
  toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T(&emxArray->data[i]);
  }
}

//
// Arguments    : c_vision_internal_calibration_R *pStruct
// Return Type  : void
//
static void f_emxInitStruct_vision_internal(c_vision_internal_calibration_R
  *pStruct)
{
  emxInit_char_T(&pStruct->OutputView, 2);
}

//
// Arguments    : c_vision_internal_calibration_I *pStruct
// Return Type  : void
//
void c_emxFreeStruct_vision_internal(c_vision_internal_calibration_I *pStruct)
{
  emxFree_real_T(&pStruct->Xmap);
  emxFree_real_T(&pStruct->Ymap);
  emxFree_real32_T(&pStruct->XmapSingle);
  emxFree_real32_T(&pStruct->YmapSingle);
  emxFree_real_T(&pStruct->SizeOfImage);
  emxFree_char_T(&pStruct->ClassOfImage);
  emxFree_char_T(&pStruct->OutputView);
}

//
// Arguments    : c_vision_internal_calibration_C *pStruct
// Return Type  : void
//
void c_emxInitStruct_vision_internal(c_vision_internal_calibration_C *pStruct)
{
  d_emxInitStruct_vision_internal(&pStruct->UndistortMap);
}

//
// Arguments    : c_vision_internal_calibration_S *pStruct
// Return Type  : void
//
void d_emxFreeStruct_vision_internal(c_vision_internal_calibration_S *pStruct)
{
  c_emxFreeStruct_vision_internal(&pStruct->RectifyMap1);
  c_emxFreeStruct_vision_internal(&pStruct->RectifyMap2);
  e_emxFreeStruct_vision_internal(&pStruct->RectificationParams);
}

//
// Arguments    : c_vision_internal_calibration_I *pStruct
// Return Type  : void
//
void d_emxInitStruct_vision_internal(c_vision_internal_calibration_I *pStruct)
{
  emxInit_real_T(&pStruct->Xmap, 2);
  emxInit_real_T(&pStruct->Ymap, 2);
  emxInit_real32_T(&pStruct->XmapSingle, 2);
  emxInit_real32_T(&pStruct->YmapSingle, 2);
  emxInit_real_T(&pStruct->SizeOfImage, 2);
  emxInit_char_T(&pStruct->ClassOfImage, 2);
  emxInit_char_T(&pStruct->OutputView, 2);
}

//
// Arguments    : c_vision_internal_calibration_S *pStruct
// Return Type  : void
//
void e_emxInitStruct_vision_internal(c_vision_internal_calibration_S *pStruct)
{
  d_emxInitStruct_vision_internal(&pStruct->RectifyMap1);
  d_emxInitStruct_vision_internal(&pStruct->RectifyMap2);
  f_emxInitStruct_vision_internal(&pStruct->RectificationParams);
}

//
// Arguments    : c_struct_T *dst
//                const c_struct_T *src
// Return Type  : void
//
void emxCopyStruct_struct_T(c_struct_T *dst, const c_struct_T *src)
{
  dst->Area = src->Area;
  emxCopyMatrix_real_T(dst->Centroid, src->Centroid);
  emxCopyMatrix_real_T1(dst->BoundingBox, src->BoundingBox);
  dst->MajorAxisLength = src->MajorAxisLength;
  dst->MinorAxisLength = src->MinorAxisLength;
  dst->Eccentricity = src->Eccentricity;
  dst->Orientation = src->Orientation;
  emxCopy_boolean_T(&dst->Image, &src->Image);
  emxCopy_boolean_T(&dst->FilledImage, &src->FilledImage);
  dst->FilledArea = src->FilledArea;
  dst->EulerNumber = src->EulerNumber;
  emxCopyMatrix_real_T2(dst->Extrema, src->Extrema);
  dst->EquivDiameter = src->EquivDiameter;
  dst->Extent = src->Extent;
  emxCopy_real_T(&dst->PixelIdxList, &src->PixelIdxList);
  emxCopy_real_T(&dst->PixelList, &src->PixelList);
  dst->Perimeter = src->Perimeter;
  dst->Circularity = src->Circularity;
  emxCopy_real_T(&dst->PixelValues, &src->PixelValues);
  emxCopyMatrix_real_T(dst->WeightedCentroid, src->WeightedCentroid);
  dst->MeanIntensity = src->MeanIntensity;
  dst->MinIntensity = src->MinIntensity;
  dst->MaxIntensity = src->MaxIntensity;
  emxCopy_real_T(&dst->SubarrayIdx, &src->SubarrayIdx);
  emxCopyMatrix_real_T(dst->SubarrayIdxLengths, src->SubarrayIdxLengths);
}

//
// Arguments    : emxArray_boolean_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(boolean_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(boolean_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_char_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(char));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(char) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_int16_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(short));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(short) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (short *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_int32_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(int));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(int) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_int8_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(signed char));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(signed char) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (signed char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_real32_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(float));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(float) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (float *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_real_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(double));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_struct_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(b_struct_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(b_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (b_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : b_emxArray_struct_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(c_struct_T) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct_T(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct_T(emxArray, oldNumel, newNumel);
    }
  }
}

//
// Arguments    : emxArray_uint32_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(unsigned int));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(unsigned int) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (unsigned int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_uint8_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = std::calloc(static_cast<unsigned int>(i), sizeof(unsigned char));
    if (emxArray->data != NULL) {
      std::memcpy(newData, emxArray->data, sizeof(unsigned char) * oldNumel);
      if (emxArray->canFreeData) {
        std::free(emxArray->data);
      }
    }

    emxArray->data = (unsigned char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : cell_wrap_26 pMatrix[2]
// Return Type  : void
//
void emxFreeMatrix_cell_wrap_26(cell_wrap_26 pMatrix[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    emxFreeStruct_cell_wrap_26(&pMatrix[i]);
  }
}

//
// Arguments    : c_struct_T *pStruct
// Return Type  : void
//
void emxFreeStruct_struct_T(c_struct_T *pStruct)
{
  emxFree_boolean_T(&pStruct->Image);
  emxFree_boolean_T(&pStruct->FilledImage);
  emxFree_real_T(&pStruct->PixelIdxList);
  emxFree_real_T(&pStruct->PixelList);
  emxFree_real_T(&pStruct->PixelValues);
  emxFree_real_T(&pStruct->SubarrayIdx);
}

//
// Arguments    : emxArray_boolean_T **pEmxArray
// Return Type  : void
//
void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

//
// Arguments    : emxArray_char_T **pEmxArray
// Return Type  : void
//
void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

//
// Arguments    : emxArray_int16_T **pEmxArray
// Return Type  : void
//
void emxFree_int16_T(emxArray_int16_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int16_T *)NULL) {
    if (((*pEmxArray)->data != (short *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_int16_T *)NULL;
  }
}

//
// Arguments    : emxArray_int32_T **pEmxArray
// Return Type  : void
//
void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

//
// Arguments    : emxArray_int8_T **pEmxArray
// Return Type  : void
//
void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (signed char *)NULL) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

//
// Arguments    : emxArray_real32_T **pEmxArray
// Return Type  : void
//
void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (float *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

//
// Arguments    : emxArray_real_T **pEmxArray
// Return Type  : void
//
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

//
// Arguments    : emxArray_struct_T **pEmxArray
// Return Type  : void
//
void emxFree_struct_T(emxArray_struct_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct_T *)NULL) {
    if (((*pEmxArray)->data != (b_struct_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_struct_T *)NULL;
  }
}

//
// Arguments    : b_emxArray_struct_T **pEmxArray
// Return Type  : void
//
void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray)
{
  int numEl;
  int i;
  if (*pEmxArray != (b_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (c_struct_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        std::free((*pEmxArray)->data);
      }
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (b_emxArray_struct_T *)NULL;
  }
}

//
// Arguments    : emxArray_uint32_T **pEmxArray
// Return Type  : void
//
void emxFree_uint32_T(emxArray_uint32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint32_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned int *)NULL) && (*pEmxArray)
        ->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_uint32_T *)NULL;
  }
}

//
// Arguments    : emxArray_uint8_T **pEmxArray
// Return Type  : void
//
void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) && (*pEmxArray)
        ->canFreeData) {
      std::free((*pEmxArray)->data);
    }

    std::free((*pEmxArray)->size);
    std::free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

//
// Arguments    : cell_wrap_26 pMatrix[2]
// Return Type  : void
//
void emxInitMatrix_cell_wrap_26(cell_wrap_26 pMatrix[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    emxInitStruct_cell_wrap_26(&pMatrix[i]);
  }
}

//
// Arguments    : c_struct_T *pStruct
// Return Type  : void
//
void emxInitStruct_struct_T(c_struct_T *pStruct)
{
  emxInit_boolean_T(&pStruct->Image, 2);
  emxInit_boolean_T(&pStruct->FilledImage, 2);
  emxInit_real_T(&pStruct->PixelIdxList, 1);
  emxInit_real_T(&pStruct->PixelList, 2);
  emxInit_real_T(&pStruct->PixelValues, 1);
  emxInit_real_T(&pStruct->SubarrayIdx, 2);
}

//
// Arguments    : emxArray_boolean_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)std::malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_char_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxArray_char_T *emxArray;
  int i;
  *pEmxArray = (emxArray_char_T *)std::malloc(sizeof(emxArray_char_T));
  emxArray = *pEmxArray;
  emxArray->data = (char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_int16_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_int16_T(emxArray_int16_T **pEmxArray, int numDimensions)
{
  emxArray_int16_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int16_T *)std::malloc(sizeof(emxArray_int16_T));
  emxArray = *pEmxArray;
  emxArray->data = (short *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_int32_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)std::malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_int8_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions)
{
  emxArray_int8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int8_T *)std::malloc(sizeof(emxArray_int8_T));
  emxArray = *pEmxArray;
  emxArray->data = (signed char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_real32_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions)
{
  emxArray_real32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real32_T *)std::malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (float *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_real_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)std::malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_struct_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_struct_T(emxArray_struct_T **pEmxArray, int numDimensions)
{
  emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct_T *)std::malloc(sizeof(emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (b_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : b_emxArray_struct_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray, int numDimensions)
{
  b_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (b_emxArray_struct_T *)std::malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_uint32_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_uint32_T(emxArray_uint32_T **pEmxArray, int numDimensions)
{
  emxArray_uint32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint32_T *)std::malloc(sizeof(emxArray_uint32_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_uint8_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)std::malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)std::malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : c_vision_internal_calibration_C *pStruct
// Return Type  : void
//
void f_emxFreeStruct_vision_internal(c_vision_internal_calibration_C *pStruct)
{
  c_emxFreeStruct_vision_internal(&pStruct->UndistortMap);
}

//
// File trailer for F_02_getImageData_emxutil.cpp
//
// [EOF]
//
