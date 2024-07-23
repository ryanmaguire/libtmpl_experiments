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
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       September 12, 2023                                            *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "polynomial_multiplication.h"

/*  size_t provided here.                                                     */
#include <stddef.h>

/*  Computes P += c * A where P and A are polynomials and c is a constant.    */
void Scaled_AddTo(int *P_coeffs, const int *A_coeffs, size_t len, int scalar)
{
    /*  Variable for indexing over the entries of the polynomial.             */
    size_t n;

    /*  Zero cast to type "size_t" for the for-loop.                          */
    const size_t zero = (size_t)0;

    /*  Loop over the entries and add the scaled product to the P polynomial. */
    for (n = zero; n < len; ++n)
        P_coeffs[n] += scalar * A_coeffs[n];
}
/*  End of Scaled_AddTo.                                                      */
