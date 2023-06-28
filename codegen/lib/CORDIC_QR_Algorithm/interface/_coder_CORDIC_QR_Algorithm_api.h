/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_CORDIC_QR_Algorithm_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 27-Jun-2023 11:45:24
 */

#ifndef _CODER_CORDIC_QR_ALGORITHM_API_H
#define _CODER_CORDIC_QR_ALGORITHM_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void CORDIC_QR_Algorithm(real_T M_in[32000], real_T niter, real_T Q[64],
  real_T R[32000]);
extern void CORDIC_QR_Algorithm_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[2]);
extern void CORDIC_QR_Algorithm_atexit(void);
extern void CORDIC_QR_Algorithm_initialize(void);
extern void CORDIC_QR_Algorithm_terminate(void);
extern void CORDIC_QR_Algorithm_xil_shutdown(void);
extern void CORDIC_QR_Algorithm_xil_terminate(void);

#endif

/*
 * File trailer for _coder_CORDIC_QR_Algorithm_api.h
 *
 * [EOF]
 */
