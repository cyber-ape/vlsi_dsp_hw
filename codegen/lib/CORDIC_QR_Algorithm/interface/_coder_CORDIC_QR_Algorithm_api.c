/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_CORDIC_QR_Algorithm_api.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 27-Jun-2023 11:45:24
 */

/* Include Files */
#include "_coder_CORDIC_QR_Algorithm_api.h"
#include "_coder_CORDIC_QR_Algorithm_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "CORDIC_QR_Algorithm",               /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

static const int32_T iv[3] = { 8, 4, 1000 };

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[32000];
static const mxArray *b_emlrt_marshallOut(const real_T u[32000]);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *niter,
  const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[32000];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *M_in,
  const char_T *identifier))[32000];
static const mxArray *emlrt_marshallOut(const real_T u[64]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[32000]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[32000]
{
  real_T (*y)[32000];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const real_T u[32000]
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const real_T u[32000])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T b_iv[3] = { 0, 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(3, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv, 3);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *niter
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *niter,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(niter), &thisId);
  emlrtDestroyArray(&niter);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[32000]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[32000]
{
  real_T (*ret)[32000];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv);
  ret = (real_T (*)[32000])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *M_in
 *                const char_T *identifier
 * Return Type  : real_T (*)[32000]
 */
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *M_in,
  const char_T *identifier))[32000]
{
  real_T (*y)[32000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(M_in), &thisId);
  emlrtDestroyArray(&M_in);
  return y;
}

/*
 * Arguments    : const real_T u[64]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[64])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T b_iv[2] = { 0, 0 };

  static const int32_T iv1[2] = { 8, 8 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void CORDIC_QR_Algorithm_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[2])
{
  real_T (*Q)[64];
  real_T (*R)[32000];
  real_T (*M_in)[32000];
  real_T niter;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  Q = (real_T (*)[64])mxMalloc(sizeof(real_T [64]));
  R = (real_T (*)[32000])mxMalloc(sizeof(real_T [32000]));

  /* Marshall function inputs */
  M_in = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "M_in");
  niter = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "niter");

  /* Invoke the target function */
  CORDIC_QR_Algorithm(*M_in, niter, *Q, *R);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*Q);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*R);
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CORDIC_QR_Algorithm_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  CORDIC_QR_Algorithm_xil_terminate();
  CORDIC_QR_Algorithm_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CORDIC_QR_Algorithm_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 2U, "ForceOff");
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void CORDIC_QR_Algorithm_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_CORDIC_QR_Algorithm_api.c
 *
 * [EOF]
 */
