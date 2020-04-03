//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: F_02_getImageData_terminate.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "F_02_getImageData_terminate.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void F_02_getImageData_terminate()
{
  F_02_getImageData_free();
  isInitialized_F_02_getImageData = false;
}

//
// File trailer for F_02_getImageData_terminate.cpp
//
// [EOF]
//
