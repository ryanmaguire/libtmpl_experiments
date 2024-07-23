/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of libtmpl_experiments.                                 *
 *                                                                            *
 *  libtmpl_experiments is free software: you can redistribute it and/or      *
 *  modify it under the terms of the GNU General Public License as published  *
 *  by the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl_experiments is distributed in the hope that it will be useful,    *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License along   *
 *  with libtmpl_experiments.  If not, see <https://www.gnu.org/licenses/>.   *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef POLYNOMIAL_MULTIPLICATION_H
#define POLYNOMIAL_MULTIPLICATION_H

#define KARATSUBA_THRESHOLD (32)

/*  size_t typedef is provided here.                                          */
#include <stddef.h>

/*  Naive multiplication,  P = A * B. Assumes A_len <= B_len.                 */
extern void
Naive_Product(int *P_coeffs,
              const int *A_coeffs, size_t A_len,
              const int *B_coeffs, size_t B_len);

/*  Naive multiplication,  P += A * B. Assumes A_len <= B_len.                */
extern void
Naive_AddTo_Product(int *P_coeffs,
                    const int *A_coeffs, size_t A_len,
                    const int *B_coeffs, size_t B_len);

/*  Naive multiplication,  P += (A0 + A1) * B. Assumes A_len <= B_len.        */
extern void
Naive_AddTo_Sum_Product(int *P_coeffs,
                        const int *A0_coeffs,
                        const int *A1_coeffs, size_t A_len,
                        const int *B_coeffs, size_t B_len);

/*  Polynomial addition, P += c*A, where c is a constant scalar.              */
extern void
Scaled_AddTo(int *P_coeffs, const int *A_coeffs, size_t len, int scalar);

extern void
Karatsuba_Product_Same_Degree(int *P,
                              const int *a,
                              const int *b,
                              size_t len);

extern void
Karatsuba_Product_Degree_Differs_By_One(int *P,
                                        const int *a,
                                        const int *b,
                                        size_t len);

extern void
Mixed_Product_Same_Degree(int *P, const int *A, const int *B, size_t len);

extern void
Mixed_AddTo_Product_Same_Degree(int *P, const int *A, const int *B, size_t len);

#endif
/*  End of include guard.                                                     */
