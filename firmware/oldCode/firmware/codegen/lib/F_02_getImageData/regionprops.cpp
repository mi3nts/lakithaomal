//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: regionprops.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "regionprops.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "bwconncomp.h"
#include "rt_nonfinite.h"
#include <cstring>

// Type Definitions
struct struct_T
{
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T Circularity;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
};

// Function Declarations
static void ComputePixelList(const double imageSize[2], b_emxArray_struct_T
  *stats, struct_T *statsAlreadyComputed);
static int div_s32(int numerator, int denominator);

// Function Definitions

//
// Arguments    : const double imageSize[2]
//                b_emxArray_struct_T *stats
//                struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputePixelList(const double imageSize[2], b_emxArray_struct_T
  *stats, struct_T *statsAlreadyComputed)
{
  int i;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  int k;
  int i1;
  int loop_ub;
  if (!statsAlreadyComputed->PixelList) {
    statsAlreadyComputed->PixelList = true;
    i = stats->size[0];
    emxInit_int32_T(&v1, 1);
    emxInit_int32_T(&vk, 1);
    for (k = 0; k < i; k++) {
      if (stats->data[k].PixelIdxList->size[0] != 0) {
        i1 = v1->size[0];
        v1->size[0] = stats->data[k].PixelIdxList->size[0];
        emxEnsureCapacity_int32_T(v1, i1);
        loop_ub = stats->data[k].PixelIdxList->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          v1->data[i1] = static_cast<int>(stats->data[k].PixelIdxList->data[i1])
            - 1;
        }

        loop_ub = v1->size[0];
        i1 = vk->size[0];
        vk->size[0] = v1->size[0];
        emxEnsureCapacity_int32_T(vk, i1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          vk->data[i1] = div_s32(v1->data[i1], static_cast<int>(imageSize[0]));
        }

        loop_ub = v1->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          v1->data[i1] -= vk->data[i1] * static_cast<int>(imageSize[0]);
        }

        loop_ub = vk->size[0];
        i1 = stats->data[k].PixelList->size[0] * stats->data[k].PixelList->size
          [1];
        stats->data[k].PixelList->size[0] = vk->size[0];
        stats->data[k].PixelList->size[1] = 2;
        emxEnsureCapacity_real_T(stats->data[k].PixelList, i1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          stats->data[k].PixelList->data[i1] = vk->data[i1] + 1;
        }

        loop_ub = v1->size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          stats->data[k].PixelList->data[i1 + stats->data[k].PixelList->size[0]]
            = v1->data[i1] + 1;
        }
      } else {
        stats->data[k].PixelList->size[0] = 0;
        stats->data[k].PixelList->size[1] = 2;
      }
    }

    emxFree_int32_T(&vk);
    emxFree_int32_T(&v1);
  }
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32(int numerator, int denominator)
{
  int quotient;
  unsigned int b_numerator;
  unsigned int b_denominator;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator < 0) {
      b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }

    if (denominator < 0) {
      b_denominator = ~static_cast<unsigned int>(denominator) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }

    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int>(b_numerator);
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }

  return quotient;
}

//
// Arguments    : const emxArray_boolean_T *varargin_1
//                emxArray_struct_T *outstats
// Return Type  : void
//
void regionprops(const emxArray_boolean_T *varargin_1, emxArray_struct_T
                 *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *regionLengths;
  double min_corner_idx_0;
  double CC_ImageSize[2];
  double min_corner_idx_1;
  b_struct_T s;
  int loop_ub;
  int i;
  c_struct_T statsOneObj;
  struct_T statsAlreadyComputed;
  b_emxArray_struct_T *stats;
  emxArray_int32_T *idxCount;
  int k;
  int b_loop_ub;
  int i1;
  double b;
  emxInit_real_T(&CC_RegionIndices, 1);
  emxInit_int32_T(&regionLengths, 1);
  bwconncomp(varargin_1, &min_corner_idx_0, CC_ImageSize, &min_corner_idx_1,
             CC_RegionIndices, regionLengths);
  s.Centroid[0] = 0.0;
  s.Centroid[1] = 0.0;
  s.BoundingBox[0] = 0.0;
  s.BoundingBox[1] = 0.0;
  s.BoundingBox[2] = 0.0;
  s.BoundingBox[3] = 0.0;
  loop_ub = static_cast<int>(min_corner_idx_1);
  i = outstats->size[0];
  outstats->size[0] = loop_ub;
  emxEnsureCapacity_struct_T(outstats, i);
  for (i = 0; i < loop_ub; i++) {
    outstats->data[i] = s;
  }

  emxInitStruct_struct_T(&statsOneObj);
  statsAlreadyComputed.Area = false;
  statsOneObj.Area = 0.0;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsAlreadyComputed.BoundingBox = false;
  statsOneObj.BoundingBox[0] = 0.0;
  statsOneObj.BoundingBox[1] = 0.0;
  statsOneObj.BoundingBox[2] = 0.0;
  statsOneObj.BoundingBox[3] = 0.0;
  statsAlreadyComputed.MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed.MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed.Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed.Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed.Image = false;
  statsOneObj.Image->size[0] = 0;
  statsOneObj.Image->size[1] = 0;
  statsAlreadyComputed.FilledImage = false;
  statsOneObj.FilledImage->size[0] = 0;
  statsOneObj.FilledImage->size[1] = 0;
  statsAlreadyComputed.FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed.EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed.Extrema = false;
  std::memset(&statsOneObj.Extrema[0], 0, 16U * sizeof(double));
  emxInit_struct_T1(&stats, 1);
  statsAlreadyComputed.EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed.Extent = false;
  statsOneObj.Extent = 0.0;
  statsOneObj.PixelIdxList->size[0] = 0;
  statsAlreadyComputed.PixelList = false;
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  statsAlreadyComputed.Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed.Circularity = false;
  statsOneObj.Circularity = 0.0;
  statsAlreadyComputed.PixelValues = false;
  statsOneObj.PixelValues->size[0] = 0;
  statsAlreadyComputed.WeightedCentroid = false;
  statsAlreadyComputed.MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed.MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed.MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed.SubarrayIdx = false;
  statsOneObj.SubarrayIdx->size[0] = 1;
  statsOneObj.SubarrayIdx->size[1] = 0;
  statsOneObj.WeightedCentroid[0] = 0.0;
  statsOneObj.SubarrayIdxLengths[0] = 0.0;
  statsOneObj.WeightedCentroid[1] = 0.0;
  statsOneObj.SubarrayIdxLengths[1] = 0.0;
  i = stats->size[0];
  stats->size[0] = loop_ub;
  emxEnsureCapacity_struct_T1(stats, i);
  for (i = 0; i < loop_ub; i++) {
    emxCopyStruct_struct_T(&stats->data[i], &statsOneObj);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  statsAlreadyComputed.PixelIdxList = true;
  if (min_corner_idx_1 != 0.0) {
    if ((regionLengths->size[0] != 1) && (regionLengths->size[0] != 0) &&
        (regionLengths->size[0] != 1)) {
      i = regionLengths->size[0];
      for (k = 0; k <= i - 2; k++) {
        regionLengths->data[k + 1] += regionLengths->data[k];
      }
    }

    emxInit_int32_T(&idxCount, 1);
    i = idxCount->size[0];
    idxCount->size[0] = regionLengths->size[0] + 1;
    emxEnsureCapacity_int32_T(idxCount, i);
    idxCount->data[0] = 0;
    b_loop_ub = regionLengths->size[0];
    for (i = 0; i < b_loop_ub; i++) {
      idxCount->data[i + 1] = regionLengths->data[i];
    }

    for (k = 0; k < loop_ub; k++) {
      i = idxCount->data[k + 1];
      if (idxCount->data[k] + 1 > i) {
        i1 = 0;
        i = 0;
      } else {
        i1 = idxCount->data[k];
      }

      b_loop_ub = i - i1;
      i = stats->data[k].PixelIdxList->size[0];
      stats->data[k].PixelIdxList->size[0] = b_loop_ub;
      emxEnsureCapacity_real_T(stats->data[k].PixelIdxList, i);
      for (i = 0; i < b_loop_ub; i++) {
        stats->data[k].PixelIdxList->data[i] = CC_RegionIndices->data[i1 + i];
      }
    }

    emxFree_int32_T(&idxCount);
  }

  emxFree_int32_T(&regionLengths);
  emxFree_real_T(&CC_RegionIndices);
  statsAlreadyComputed.Centroid = true;
  ComputePixelList(CC_ImageSize, stats, &statsAlreadyComputed);
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    i1 = stats->data[k].PixelList->size[0];
    if (stats->data[k].PixelList->size[0] == 0) {
      min_corner_idx_0 = 0.0;
      min_corner_idx_1 = 0.0;
    } else {
      min_corner_idx_0 = stats->data[k].PixelList->data[0];
      for (loop_ub = 2; loop_ub <= i1; loop_ub++) {
        min_corner_idx_0 += stats->data[k].PixelList->data[loop_ub - 1];
      }

      min_corner_idx_1 = stats->data[k].PixelList->data[stats->data[k].
        PixelList->size[0]];
      for (loop_ub = 2; loop_ub <= i1; loop_ub++) {
        min_corner_idx_1 += stats->data[k].PixelList->data[(stats->data[k].
          PixelList->size[0] + loop_ub) - 1];
      }
    }

    stats->data[k].Centroid[0] = min_corner_idx_0 / static_cast<double>
      (stats->data[k].PixelList->size[0]);
    stats->data[k].Centroid[1] = min_corner_idx_1 / static_cast<double>
      (stats->data[k].PixelList->size[0]);
  }

  if (!statsAlreadyComputed.BoundingBox) {
    statsAlreadyComputed.BoundingBox = true;
    ComputePixelList(CC_ImageSize, stats, &statsAlreadyComputed);
    i = stats->size[0];
    for (k = 0; k < i; k++) {
      i1 = stats->data[k].PixelList->size[0];
      if (stats->data[k].PixelList->size[0] == 0) {
        stats->data[k].BoundingBox[0] = 0.5;
        stats->data[k].BoundingBox[1] = 0.5;
        stats->data[k].BoundingBox[2] = 0.0;
        stats->data[k].BoundingBox[3] = 0.0;
      } else {
        min_corner_idx_0 = stats->data[k].PixelList->data[0];
        for (loop_ub = 2; loop_ub <= i1; loop_ub++) {
          b = stats->data[k].PixelList->data[loop_ub - 1];
          if ((!rtIsNaN(b)) && (rtIsNaN(min_corner_idx_0) || (min_corner_idx_0 >
                b))) {
            min_corner_idx_0 = b;
          }
        }

        min_corner_idx_0 -= 0.5;
        CC_ImageSize[0] = stats->data[k].PixelList->data[0];
        for (loop_ub = 2; loop_ub <= i1; loop_ub++) {
          b = stats->data[k].PixelList->data[loop_ub - 1];
          if ((!rtIsNaN(b)) && (rtIsNaN(CC_ImageSize[0]) || (CC_ImageSize[0] < b)))
          {
            CC_ImageSize[0] = b;
          }
        }

        stats->data[k].BoundingBox[0] = min_corner_idx_0;
        stats->data[k].BoundingBox[2] = (CC_ImageSize[0] + 0.5) -
          min_corner_idx_0;
        min_corner_idx_1 = stats->data[k].PixelList->data[stats->data[k].
          PixelList->size[0]];
        for (loop_ub = 2; loop_ub <= i1; loop_ub++) {
          b = stats->data[k].PixelList->data[(loop_ub + stats->data[k].
            PixelList->size[0]) - 1];
          if ((!rtIsNaN(b)) && (rtIsNaN(min_corner_idx_1) || (min_corner_idx_1 >
                b))) {
            min_corner_idx_1 = b;
          }
        }

        min_corner_idx_1 -= 0.5;
        CC_ImageSize[1] = stats->data[k].PixelList->data[stats->data[k].
          PixelList->size[0]];
        for (loop_ub = 2; loop_ub <= i1; loop_ub++) {
          b = stats->data[k].PixelList->data[(loop_ub + stats->data[k].
            PixelList->size[0]) - 1];
          if ((!rtIsNaN(b)) && (rtIsNaN(CC_ImageSize[1]) || (CC_ImageSize[1] < b)))
          {
            CC_ImageSize[1] = b;
          }
        }

        stats->data[k].BoundingBox[1] = min_corner_idx_1;
        stats->data[k].BoundingBox[3] = (CC_ImageSize[1] + 0.5) -
          min_corner_idx_1;
      }
    }
  }

  i = stats->size[0];
  for (k = 0; k < i; k++) {
    outstats->data[k].Centroid[0] = stats->data[k].Centroid[0];
    outstats->data[k].Centroid[1] = stats->data[k].Centroid[1];
    outstats->data[k].BoundingBox[0] = stats->data[k].BoundingBox[0];
    outstats->data[k].BoundingBox[1] = stats->data[k].BoundingBox[1];
    outstats->data[k].BoundingBox[2] = stats->data[k].BoundingBox[2];
    outstats->data[k].BoundingBox[3] = stats->data[k].BoundingBox[3];
  }

  emxFree_struct_T1(&stats);
}

//
// File trailer for regionprops.cpp
//
// [EOF]
//
