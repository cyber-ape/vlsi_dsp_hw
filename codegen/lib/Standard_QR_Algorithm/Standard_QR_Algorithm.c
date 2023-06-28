/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Standard_QR_Algorithm.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 27-Jun-2023 11:45:21
 */

/* Include Files */
#include "Standard_QR_Algorithm.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double M_in[32]
 *                double Q[64]
 *                double R[32]
 * Return Type  : void
 */
void Standard_QR_Algorithm(const double M_in[32], double Q[64], double R[32])
{
  int k;
  int i;
  int loop_ub;
  int b_i;
  int i1;
  int tmp_size_idx_1;
  int b_tmp_size_idx_1;
  int i2;
  double dv[8];
  int i3;
  double dv1[8];
  double tmp_data[4];
  double b_tmp_data[4];
  double t;
  double c;
  int b_loop_ub;

  /*  Standard_QR_Algorithm.m */
  memcpy(&R[0], &M_in[0], 32U * sizeof(double));

  /*  Declare type and size of Q */
  memset(&Q[0], 0, 64U * sizeof(double));
  for (k = 0; k < 8; k++) {
    Q[k + (k << 3)] = 1.0;
  }

  /*  Initialize Q */
  for (k = 0; k < 4; k++) {
    i = (int)(((((double)k + 1.0) + 1.0) + -9.0) / -1.0);
    if (0 <= i - 1) {
      loop_ub = -k;
      i1 = k << 3;
    }

    for (b_i = 0; b_i < i; b_i++) {
      tmp_size_idx_1 = 4 - k;
      b_tmp_size_idx_1 = 4 - k;
      for (i2 = 0; i2 <= loop_ub + 3; i2++) {
        i3 = (k + i2) << 3;
        tmp_data[i2] = R[k + i3];
        b_tmp_data[i2] = R[(i3 - b_i) + 7];
      }

      memcpy(&dv[0], &Q[k * 8], 8U * sizeof(double));
      memcpy(&dv1[0], &Q[b_i * -8 + 56], 8U * sizeof(double));

      /*  Standard_Givens_Rotation */
      /*  The givensrotation function uses division and square root,  */
      /*  which are expensive in fixed-point, but good for floating-point algorithms. */
      i2 = (i1 - b_i) + 7;
      if (!(R[i2] == 0.0)) {
        /*      if abs(b) > abs(a) */
        /*        t = a/b; s = 1/sqrt(1+t^2); c = s*t; */
        /*      else */
        t = R[i2] / R[k + i1];
        c = 1.0 / sqrt(t * t + 1.0);
        t *= c;

        /*      end */
        /*  x and y form R,   u and v form Q */
        tmp_size_idx_1 = 4 - k;
        b_loop_ub = -k;
        for (i2 = 0; i2 <= b_loop_ub + 3; i2++) {
          i3 = (k + i2) << 3;
          tmp_data[i2] = c * R[k + i3] + t * R[(i3 - b_i) + 7];
        }

        for (i2 = 0; i2 < 8; i2++) {
          dv[i2] = c * Q[i2 + i1] + t * Q[i2 + ((7 - b_i) << 3)];
        }

        b_tmp_size_idx_1 = 4 - k;
        b_loop_ub = -k;
        for (i2 = 0; i2 <= b_loop_ub + 3; i2++) {
          i3 = (k + i2) << 3;
          b_tmp_data[i2] = -t * R[k + i3] + c * R[(i3 - b_i) + 7];
        }

        for (i2 = 0; i2 < 8; i2++) {
          dv1[i2] = -t * Q[i2 + i1] + c * Q[i2 + ((7 - b_i) << 3)];
        }
      } else {
        /*  No rotation necessary.  c = 1; s = 0; */
      }

      for (i2 = 0; i2 < tmp_size_idx_1; i2++) {
        R[k + ((k + i2) << 3)] = tmp_data[i2];
      }

      for (i2 = 0; i2 < b_tmp_size_idx_1; i2++) {
        R[(((k + i2) << 3) - b_i) + 7] = b_tmp_data[i2];
      }

      for (i2 = 0; i2 < 8; i2++) {
        Q[i2 + i1] = dv[i2];
        Q[i2 + ((7 - b_i) << 3)] = dv1[i2];
      }
    }
  }
}

/*
 * File trailer for Standard_QR_Algorithm.c
 *
 * [EOF]
 */
