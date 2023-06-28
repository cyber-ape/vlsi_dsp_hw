/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Standard_QR_Algorithm_mex.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 27-Jun-2023 11:45:21
 */

/* Include Files */
#include "_coder_Standard_QR_Algorithm_mex.h"
#include "_coder_Standard_QR_Algorithm_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_Standard_QR_Algorithm_mexFunc(int32_T nlhs, mxArray
  *plhs[2], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[2]
 *                int32_T nrhs
 *                const mxArray *prhs[1]
 * Return Type  : void
 */
void c_Standard_QR_Algorithm_mexFunc(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[1])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        21, "Standard_QR_Algorithm");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "Standard_QR_Algorithm");
  }

  /* Call the function. */
  Standard_QR_Algorithm_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&Standard_QR_Algorithm_atexit);

  /* Module initialization. */
  Standard_QR_Algorithm_initialize();

  /* Dispatch the entry-point. */
  c_Standard_QR_Algorithm_mexFunc(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Standard_QR_Algorithm_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_Standard_QR_Algorithm_mex.c
 *
 * [EOF]
 */
