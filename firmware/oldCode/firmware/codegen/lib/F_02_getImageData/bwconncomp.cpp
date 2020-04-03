//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwconncomp.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "bwconncomp.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const emxArray_boolean_T *varargin_1
//                double *CC_Connectivity
//                double CC_ImageSize[2]
//                double *CC_NumObjects
//                emxArray_real_T *CC_RegionIndices
//                emxArray_int32_T *CC_RegionLengths
// Return Type  : void
//
void bwconncomp(const emxArray_boolean_T *varargin_1, double *CC_Connectivity,
                double CC_ImageSize[2], double *CC_NumObjects, emxArray_real_T
                *CC_RegionIndices, emxArray_int32_T *CC_RegionLengths)
{
  int numRuns;
  int p;
  int lastRunOnPreviousColumn;
  emxArray_int32_T *startRow;
  emxArray_int32_T *endRow;
  emxArray_int32_T *startCol;
  double numComponents;
  int firstRunOnThisColumn;
  int k;
  int currentColumn;
  int runCounter;
  int row;
  emxArray_int32_T *labelsRenumbered;
  int root_k;
  int root_p;
  double y;
  emxArray_int32_T *pixelIdxList;
  emxArray_int32_T *x;
  emxArray_int32_T *idxCount;
  numRuns = 0;
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    p = varargin_1->size[1];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < p;
         lastRunOnPreviousColumn++) {
      if (varargin_1->data[varargin_1->size[0] * lastRunOnPreviousColumn]) {
        numRuns++;
      }

      firstRunOnThisColumn = varargin_1->size[0];
      for (k = 0; k <= firstRunOnThisColumn - 2; k++) {
        if (varargin_1->data[(k + varargin_1->size[0] * lastRunOnPreviousColumn)
            + 1] && (!varargin_1->data[k + varargin_1->size[0] *
                     lastRunOnPreviousColumn])) {
          numRuns++;
        }
      }
    }
  }

  if (numRuns == 0) {
    CC_ImageSize[0] = varargin_1->size[0];
    CC_ImageSize[1] = varargin_1->size[1];
    numComponents = 0.0;
    CC_RegionIndices->size[0] = 0;
    p = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity_int32_T(CC_RegionLengths, p);
    CC_RegionLengths->data[0] = 0;
  } else {
    emxInit_int32_T(&startRow, 1);
    emxInit_int32_T(&endRow, 1);
    emxInit_int32_T(&startCol, 1);
    p = startRow->size[0];
    startRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(startRow, p);
    p = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity_int32_T(endRow, p);
    p = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity_int32_T(startCol, p);
    currentColumn = varargin_1->size[0];
    runCounter = 0;
    p = varargin_1->size[1];
    for (lastRunOnPreviousColumn = 0; lastRunOnPreviousColumn < p;
         lastRunOnPreviousColumn++) {
      row = 1;
      while (row <= currentColumn) {
        while ((row <= currentColumn) && (!varargin_1->data[(row +
                 varargin_1->size[0] * lastRunOnPreviousColumn) - 1])) {
          row++;
        }

        if ((row <= currentColumn) && varargin_1->data[(row + varargin_1->size[0]
             * lastRunOnPreviousColumn) - 1]) {
          startCol->data[runCounter] = lastRunOnPreviousColumn + 1;
          startRow->data[runCounter] = row;
          while ((row <= currentColumn) && varargin_1->data[(row +
                  varargin_1->size[0] * lastRunOnPreviousColumn) - 1]) {
            row++;
          }

          endRow->data[runCounter] = row - 1;
          runCounter++;
        }
      }
    }

    p = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = numRuns;
    emxEnsureCapacity_int32_T(CC_RegionLengths, p);
    for (p = 0; p < numRuns; p++) {
      CC_RegionLengths->data[p] = 0;
    }

    k = 0;
    currentColumn = 1;
    runCounter = 1;
    row = -1;
    lastRunOnPreviousColumn = -1;
    firstRunOnThisColumn = 0;
    while (k + 1 <= numRuns) {
      if (startCol->data[k] == currentColumn + 1) {
        row = firstRunOnThisColumn + 1;
        firstRunOnThisColumn = k;
        lastRunOnPreviousColumn = k;
        currentColumn = startCol->data[k];
      } else {
        if (startCol->data[k] > currentColumn + 1) {
          row = -1;
          lastRunOnPreviousColumn = -1;
          firstRunOnThisColumn = k;
          currentColumn = startCol->data[k];
        }
      }

      if (row >= 0) {
        for (p = row - 1; p < lastRunOnPreviousColumn; p++) {
          if ((endRow->data[k] >= startRow->data[p] - 1) && (startRow->data[k] <=
               endRow->data[p] + 1)) {
            if (CC_RegionLengths->data[k] == 0) {
              CC_RegionLengths->data[k] = CC_RegionLengths->data[p];
              runCounter++;
            } else {
              if (CC_RegionLengths->data[k] != CC_RegionLengths->data[p]) {
                for (root_k = k; root_k + 1 != CC_RegionLengths->data[root_k];
                     root_k = CC_RegionLengths->data[root_k] - 1) {
                  CC_RegionLengths->data[root_k] = CC_RegionLengths->
                    data[CC_RegionLengths->data[root_k] - 1];
                }

                for (root_p = p; root_p + 1 != CC_RegionLengths->data[root_p];
                     root_p = CC_RegionLengths->data[root_p] - 1) {
                  CC_RegionLengths->data[root_p] = CC_RegionLengths->
                    data[CC_RegionLengths->data[root_p] - 1];
                }

                if (root_k + 1 != root_p + 1) {
                  if (root_p + 1 < root_k + 1) {
                    CC_RegionLengths->data[root_k] = root_p + 1;
                    CC_RegionLengths->data[k] = root_p + 1;
                  } else {
                    CC_RegionLengths->data[root_p] = root_k + 1;
                    CC_RegionLengths->data[p] = root_k + 1;
                  }
                }
              }
            }
          }
        }
      }

      if (CC_RegionLengths->data[k] == 0) {
        CC_RegionLengths->data[k] = runCounter;
        runCounter++;
      }

      k++;
    }

    emxInit_int32_T(&labelsRenumbered, 1);
    p = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(labelsRenumbered, p);
    numComponents = 0.0;
    for (k = 0; k < numRuns; k++) {
      if (CC_RegionLengths->data[k] == k + 1) {
        numComponents++;
        labelsRenumbered->data[k] = static_cast<int>(numComponents);
      }

      labelsRenumbered->data[k] = labelsRenumbered->data[CC_RegionLengths->
        data[k] - 1];
    }

    currentColumn = static_cast<int>(numComponents);
    p = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = currentColumn;
    emxEnsureCapacity_int32_T(CC_RegionLengths, p);
    for (p = 0; p < currentColumn; p++) {
      CC_RegionLengths->data[p] = 0;
    }

    for (k = 0; k < numRuns; k++) {
      if (labelsRenumbered->data[k] > 0) {
        CC_RegionLengths->data[labelsRenumbered->data[k] - 1] =
          ((CC_RegionLengths->data[labelsRenumbered->data[k] - 1] + endRow->
            data[k]) - startRow->data[k]) + 1;
      }
    }

    currentColumn = CC_RegionLengths->size[0];
    if (CC_RegionLengths->size[0] == 0) {
      y = 0.0;
    } else {
      y = CC_RegionLengths->data[0];
      for (k = 2; k <= currentColumn; k++) {
        y += static_cast<double>(CC_RegionLengths->data[k - 1]);
      }
    }

    emxInit_int32_T(&pixelIdxList, 1);
    emxInit_int32_T(&x, 1);
    p = pixelIdxList->size[0];
    pixelIdxList->size[0] = static_cast<int>(y);
    emxEnsureCapacity_int32_T(pixelIdxList, p);
    p = x->size[0];
    x->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity_int32_T(x, p);
    currentColumn = CC_RegionLengths->size[0];
    for (p = 0; p < currentColumn; p++) {
      x->data[p] = CC_RegionLengths->data[p];
    }

    if ((CC_RegionLengths->size[0] != 1) && (CC_RegionLengths->size[0] != 0) &&
        (CC_RegionLengths->size[0] != 1)) {
      p = CC_RegionLengths->size[0];
      for (k = 0; k <= p - 2; k++) {
        x->data[k + 1] += x->data[k];
      }
    }

    emxInit_int32_T(&idxCount, 1);
    p = idxCount->size[0];
    idxCount->size[0] = x->size[0] + 1;
    emxEnsureCapacity_int32_T(idxCount, p);
    idxCount->data[0] = 0;
    currentColumn = x->size[0];
    for (p = 0; p < currentColumn; p++) {
      idxCount->data[p + 1] = x->data[p];
    }

    emxFree_int32_T(&x);
    for (k = 0; k < numRuns; k++) {
      currentColumn = (startCol->data[k] - 1) * varargin_1->size[0];
      p = labelsRenumbered->data[k];
      if (labelsRenumbered->data[k] > 0) {
        firstRunOnThisColumn = startRow->data[k];
        runCounter = endRow->data[k];
        for (row = firstRunOnThisColumn; row <= runCounter; row++) {
          idxCount->data[p - 1]++;
          pixelIdxList->data[idxCount->data[p - 1] - 1] = row + currentColumn;
        }
      }
    }

    emxFree_int32_T(&startCol);
    emxFree_int32_T(&endRow);
    emxFree_int32_T(&startRow);
    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    CC_ImageSize[0] = varargin_1->size[0];
    CC_ImageSize[1] = varargin_1->size[1];
    p = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity_real_T(CC_RegionIndices, p);
    currentColumn = pixelIdxList->size[0];
    for (p = 0; p < currentColumn; p++) {
      CC_RegionIndices->data[p] = pixelIdxList->data[p];
    }

    emxFree_int32_T(&pixelIdxList);
  }

  *CC_Connectivity = 8.0;
  *CC_NumObjects = numComponents;
}

//
// File trailer for bwconncomp.cpp
//
// [EOF]
//
