/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.c
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include "strcmp.h"
#include "F_02_getImageData.h"
#include "F_02_getImageData_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T b_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T b_cv[6] = { 'd', 'o', 'u', 'b', 'l', 'e' };

  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a->data[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

/* End of code generation (strcmp.c) */
