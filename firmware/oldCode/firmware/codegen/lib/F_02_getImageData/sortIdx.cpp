//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 4.3
// C/C++ source code generated on  : 04-Feb-2020 11:05:06
//

// Include Files
#include "sortIdx.h"
#include "F_02_getImageData.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : int idx[8]
//                double x[8]
//                int offset
//                int np
//                int nq
//                int iwork[8]
//                double xwork[8]
// Return Type  : void
//
void merge(int idx[8], double x[8], int offset, int np, int nq, int iwork[8],
           double xwork[8])
{
  int n_tmp;
  int iout;
  int p;
  int i;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i = offset + iout;
      iwork[iout] = idx[i];
      xwork[iout] = x[i];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i = q + iout;
            idx[i] = iwork[iout - 1];
            x[i] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
