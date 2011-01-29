/* $Id: sparse_solve.c,v 1.7 2011/01/25 16:30:50 ellson Exp $ $Revision: 1.7 $ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

#include <assert.h>
#include <string.h>
#include "sparse_solve.h"
#include "sfdpinternal.h"
#include "memory.h"
#include "logic.h"
#include "math.h"
#include "arith.h"
#include "types.h"
#include "globals.h"

#define DEBUG_PRINT
#define MALLOC gmalloc
#define REALLOC grealloc
#define FREE free
#define MEMCPY memcpy

static real *vector_subtract_to(int n, real * x, real * y)
{
    /* y = x-y */
    int i;
    for (i = 0; i < n; i++)
	y[i] = x[i] - y[i];
    return y;
}

static real *vector_saxpy(int n, real * x, real * y, real beta)
{
    /* y = x+beta*y */
    int i;
    for (i = 0; i < n; i++)
	y[i] = x[i] + beta * y[i];
    return y;
}

static real *vector_saxpy2(int n, real * x, real * y, real beta)
{
    /* x = x+beta*y */
    int i;
    for (i = 0; i < n; i++)
	x[i] = x[i] + beta * y[i];
    return x;
}

static real vector_product(int n, real *x, real *y){
  real res = 0;
  int i;
  for (i = 0; i < n; i++) res += x[i]*y[i];
  return res;
}

real *Operator_matmul_apply(Operator o, real *x, real *y){
  SparseMatrix A = (SparseMatrix) o->data;
  SparseMatrix_multiply_vector(A, x, &y, FALSE);
  return y;
}

Operator Operator_matmul_new(SparseMatrix A){
  Operator o;

  o = N_GNEW(1,struct Operator_struct);
  o->data = (void*) A;
  o->Operator_apply = Operator_matmul_apply;
  return o;
}


void Operator_matmul_delete(Operator o){
  
}


real* Operator_diag_precon_apply(Operator o, real *x, real *y){
  int i, m;
  real *diag = (real*) o->data;
  m = (int) diag[0];
  diag++;
  for (i = 0; i < m; i++) y[i] = x[i]*diag[i];
  return y;
}

Operator Operator_diag_precon_new(SparseMatrix A){
  Operator o;
  real *diag;
  int i, j, m = A->m, *ia = A->ia, *ja = A->ja;
  real *a = (real*) A->a;

  assert(A->type == MATRIX_TYPE_REAL);

  assert(a);

  o = N_GNEW(1,struct Operator_struct);
  o->data = N_GNEW((A->m + 1),real);
  diag = (real*) o->data;

  diag[0] = m;
  diag++;
  for (i = 0; i < m; i++){
    diag[i] = 1.;
    for (j = ia[i]; j < ia[i+1]; j++){
      if (i == ja[j] && ABS(a[j]) > 0) diag[i] = 1./a[j];
    }
  }

  o->Operator_apply = Operator_diag_precon_apply;

  return o;
}

void Operator_diag_precon_delete(Operator o){
  FREE(o->data);
}

static real conjugate_gradient(Operator A, Operator precon, int n, real *x, real *rhs, real tol, int maxit, int *flag){
  real *z, *r, *p, *q, res = 10*tol, alpha;
  real rho = 1.0e20, rho_old = 1, res0, beta;
  real* (*Ax)(Operator o, real *in, real *out) = A->Operator_apply;
  real* (*Minvx)(Operator o, real *in, real *out) = precon->Operator_apply;
  int iter = 0;

  z = N_GNEW(n,real);
  r = N_GNEW(n,real);
  p = N_GNEW(n,real);
  q = N_GNEW(n,real);

  r = Ax(A, x, r);
  r = vector_subtract_to(n, rhs, r);

  res0 = res = sqrt(vector_product(n, r, r))/n;
#ifdef DEBUG_PRINT
    if (Verbose && 0){
      fprintf(stderr, "   cg iter = %d, residual = %g\n", iter, res);
    }
#endif

  while ((iter++) < maxit && res > tol*res0){
    z = Minvx(precon, r, z);
    rho = vector_product(n, r, z);

    if (iter > 1){
      beta = rho/rho_old;
      p = vector_saxpy(n, z, p, beta);
    } else {
      MEMCPY(p, z, sizeof(real)*n);
    }

    q = Ax(A, p, q);

    alpha = rho/vector_product(n, p, q);

    x = vector_saxpy2(n, x, p, alpha);
    r = vector_saxpy2(n, r, q, -alpha);
    
    res = sqrt(vector_product(n, r, r))/n;

#ifdef DEBUG_PRINT
    if (Verbose && 0){
      fprintf(stderr, "   cg iter = %d, residual = %g\n", iter, res);
    }
#endif



    rho_old = rho;
  }
#ifdef DEBUG
    _statistics[0] += iter - 1;
#endif

#ifdef DEBUG_PRINT
  if (Verbose && 0){
    fprintf(stderr, "   cg iter = %d, residual = %g\n", iter, res);
  }
#endif
  return res;
}

real SparseMatrix_solve(SparseMatrix A, int dim, real *x0, real *rhs, real tol, int maxit, int method, int *flag){
  Operator Ax, precond;
  real *x, *b, res = 0;
  int n = A->m, k, i;
  
  *flag = 0;

  switch (method){
  case SOLVE_METHOD_CG:
    Ax =  Operator_matmul_new(A);
    precond = Operator_diag_precon_new(A);

    x = N_GNEW(n,real);
    b = N_GNEW(n,real);
    for (k = 0; k < dim; k++){
      for (i = 0; i < n; i++) {
	x[i] = x0[i*dim+k];
	b[i] = rhs[i*dim+k];
      }

      res += conjugate_gradient(Ax, precond, n, x, b, tol, maxit, flag);
      for (i = 0; i < n; i++) {
	rhs[i*dim+k] = x[i];
      }
    }
    Operator_matmul_delete(Ax);
    Operator_diag_precon_delete(precond);
    FREE(x);
    FREE(b);

    break;
  default:
    assert(0);
    break;

  }
  return res;
}

