//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: meshgrid.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "meshgrid.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_emxutil.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                const emxArray_real_T *y
//                emxArray_real_T *xx
//                emxArray_real_T *yy
// Return Type  : void
//
void meshgrid(const emxArray_real_T *x, const emxArray_real_T *y,
              emxArray_real_T *xx, emxArray_real_T *yy)
{
  int nx;
  int ny;
  int j;
  int i;
  nx = x->size[1];
  ny = y->size[1];
  j = xx->size[0] * xx->size[1];
  xx->size[0] = y->size[1];
  xx->size[1] = x->size[1];
  emxEnsureCapacity_real_T(xx, j);
  j = yy->size[0] * yy->size[1];
  yy->size[0] = y->size[1];
  yy->size[1] = x->size[1];
  emxEnsureCapacity_real_T(yy, j);
  if ((x->size[1] != 0) && (y->size[1] != 0)) {
    for (j = 0; j < nx; j++) {
      for (i = 0; i < ny; i++) {
        xx->data[i + xx->size[0] * j] = x->data[j];
        yy->data[i + yy->size[0] * j] = y->data[i];
      }
    }
  }
}

//
// File trailer for meshgrid.cpp
//
// [EOF]
//
