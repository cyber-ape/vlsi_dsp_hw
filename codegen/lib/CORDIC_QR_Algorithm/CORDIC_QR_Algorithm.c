/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CORDIC_QR_Algorithm.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 27-Jun-2023 11:45:24
 */

/* Include Files */
#include "CORDIC_QR_Algorithm.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void CORDIC_Givens(double x_data[], int x_size[2], double y_data[], int
  y_size[2], double u[8], double v[8], double niter);

/* Function Definitions */

/*
 * Arguments    : double x_data[]
 *                int x_size[2]
 *                double y_data[]
 *                int y_size[2]
 *                double u[8]
 *                double v[8]
 *                double niter
 * Return Type  : void
 */
static void CORDIC_Givens(double x_data[], int x_size[2], double y_data[], int
  y_size[2], double u[8], double v[8], double niter)
{
  int i;
  int b_i;
  int nx;
  int x0_size_idx_1;
  double x0_data[4000];
  double u0[8];
  int k;
  short varargin_1;
  double w_data[4000];

  /*  CORDIC_Givens_Rotation.m */
  /*  The heart of this function is applying orthogonal Givens rotations  */
  /*  in-place to the rows of R to zero out sub-diagonal elements,  */
  /*  thus forming an upper-triangular matrix.  */
  if (x_data[0] < 0.0) {
    /*  Compensation for 3rd and 4th quadrants */
    x_size[0] = 1;
    nx = x_size[1];
    for (i = 0; i < nx; i++) {
      x_data[i] = -x_data[i];
    }

    for (i = 0; i < 8; i++) {
      u[i] = -u[i];
    }

    y_size[0] = 1;
    nx = y_size[1];
    for (i = 0; i < nx; i++) {
      y_data[i] = -y_data[i];
    }

    for (i = 0; i < 8; i++) {
      v[i] = -v[i];
    }
  }

  i = (int)((niter - 1.0) + 1.0);
  for (b_i = 0; b_i < i; b_i++) {
    x0_size_idx_1 = x_size[1];
    nx = x_size[0] * x_size[1];
    if (0 <= nx - 1) {
      memcpy(&x0_data[0], &x_data[0], nx * sizeof(double));
    }

    memcpy(&u0[0], &u[0], 8U * sizeof(double));
    if (y_data[0] < 0.0) {
      /*  Counter-clockwise rotation */
      /*  x and y form R,         u and v form Q */
      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      nx = y_size[1];
      for (k = 0; k < nx; k++) {
        w_data[k] = ldexp(y_data[k], varargin_1);
      }

      x_size[0] = 1;
      nx = x_size[1];
      for (k = 0; k < nx; k++) {
        x_data[k] -= w_data[k];
      }

      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      for (k = 0; k < 8; k++) {
        u[k] -= ldexp(v[k], varargin_1);
      }

      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      for (k = 0; k < x0_size_idx_1; k++) {
        w_data[k] = ldexp(x0_data[k], varargin_1);
      }

      y_size[0] = 1;
      nx = y_size[1];
      for (k = 0; k < nx; k++) {
        y_data[k] += w_data[k];
      }

      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      for (k = 0; k < 8; k++) {
        v[k] += ldexp(u0[k], varargin_1);
      }
    } else {
      /*  Clockwise rotation */
      /*  x and y form R,         u and v form Q */
      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      nx = y_size[1];
      for (k = 0; k < nx; k++) {
        w_data[k] = ldexp(y_data[k], varargin_1);
      }

      x_size[0] = 1;
      nx = x_size[1];
      for (k = 0; k < nx; k++) {
        x_data[k] += w_data[k];
      }

      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      for (k = 0; k < 8; k++) {
        u[k] += ldexp(v[k], varargin_1);
      }

      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      for (k = 0; k < x0_size_idx_1; k++) {
        w_data[k] = ldexp(x0_data[k], varargin_1);
      }

      y_size[0] = 1;
      nx = y_size[1];
      for (k = 0; k < nx; k++) {
        y_data[k] -= w_data[k];
      }

      k = b_i;
      if (b_i > 32767) {
        k = 32767;
      }

      varargin_1 = (short)-(short)k;
      for (k = 0; k < 8; k++) {
        v[k] -= ldexp(u0[k], varargin_1);
      }
    }
  }

  /*  Set y(1) to exactly zero so R will be upper triangular without round off */
  /*  showing up in the lower triangle. */
  y_data[0] = 0.0;

  /*  Normalize the CORDIC gain */
  x_size[0] = 1;
  nx = x_size[1];
  for (i = 0; i < nx; i++) {
    x_data[i] *= 0.60725334371201;
  }

  for (i = 0; i < 8; i++) {
    u[i] *= 0.60725334371201;
  }

  y_size[0] = 1;
  nx = y_size[1];
  for (i = 0; i < nx; i++) {
    y_data[i] *= 0.60725334371201;
  }

  for (i = 0; i < 8; i++) {
    v[i] *= 0.60725334371201;
  }
}

/*
 * Kn = Inverse_CORDIC_Growth_Constant(niter);
 * Arguments    : const double M_in[32000]
 *                double niter
 *                double Q[64]
 *                double R[32000]
 * Return Type  : void
 */
void CORDIC_QR_Algorithm(const double M_in[32000], double niter, double Q[64],
  double R[32000])
{
  int k;
  int i;
  int b_i;
  double dv[8];
  int tmp_size[2];
  int loop_ub;
  int b_tmp_size[2];
  int i1;
  double tmp_data[4000];
  double b_tmp_data[4000];
  int i2;

  /*  CORDIC_QR_Algorithm.m */
  /*  This pattern of assignment is one key enabler of data-type independent code. */
  memcpy(&R[0], &M_in[0], 32000U * sizeof(double));

  /*  Declare type and size of Q */
  memset(&Q[0], 0, 64U * sizeof(double));
  for (k = 0; k < 8; k++) {
    Q[k + (k << 3)] = 1.0;
  }

  /*  Initialize Q */
  for (k = 0; k < 4000; k++) {
    i = (int)(((((double)k + 1.0) + 1.0) + -9.0) / -1.0);
    for (b_i = 0; b_i < i; b_i++) {
      memcpy(&dv[0], &Q[b_i * -8 + 56], 8U * sizeof(double));
      tmp_size[0] = 1;
      tmp_size[1] = 4000 - k;
      loop_ub = -k;
      b_tmp_size[0] = 1;
      b_tmp_size[1] = 4000 - k;
      for (i1 = 0; i1 <= loop_ub + 3999; i1++) {
        i2 = (k + i1) << 3;
        tmp_data[i1] = R[k + i2];
        b_tmp_data[i1] = R[(i2 - b_i) + 7];
      }

      CORDIC_Givens(tmp_data, tmp_size, b_tmp_data, b_tmp_size, *(double (*)[8])
                    &Q[k << 3], dv, niter);
      loop_ub = tmp_size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        R[k + ((k + i1) << 3)] = tmp_data[i1];
      }

      loop_ub = b_tmp_size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        R[(((k + i1) << 3) - b_i) + 7] = b_tmp_data[i1];
      }

      memcpy(&Q[b_i * -8 + 56], &dv[0], 8U * sizeof(double));
    }
  }
}

/*
 * File trailer for CORDIC_QR_Algorithm.c
 *
 * [EOF]
 */
