/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 27-Jun-2023 11:45:21
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "Standard_QR_Algorithm.h"
#include "Standard_QR_Algorithm_terminate.h"

/* Function Declarations */
static void argInit_8x4_real_T(double result[32]);
static double argInit_real_T(void);
static void main_Standard_QR_Algorithm(void);

/* Function Definitions */

/*
 * Arguments    : double result[32]
 * Return Type  : void
 */
static void argInit_8x4_real_T(double result[32])
{
  double result_tmp;
  int idx0;

  /* Loop over the array to initialize each element. */
  result_tmp = argInit_real_T();
  for (idx0 = 0; idx0 < 8; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 8] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 16] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 24] = result_tmp;
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_Standard_QR_Algorithm(void)
{
  double dv[32];
  double Q[64];
  double R[32];

  /* Initialize function 'Standard_QR_Algorithm' input arguments. */
  /* Initialize function input argument 'M_in'. */
  /* Call the entry-point 'Standard_QR_Algorithm'. */
  argInit_8x4_real_T(dv);
  Standard_QR_Algorithm(dv, Q, R);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Standard_QR_Algorithm();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Standard_QR_Algorithm_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
