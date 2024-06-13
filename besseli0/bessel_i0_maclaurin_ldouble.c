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
 *                        bessel_i0_maclaurin_ldouble                         *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Computes the Maclaurin expansion of I0(x) at double precision.        *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      I0_LDouble_Maclaurin                                                  *
 *  Purpose:                                                                  *
 *      Computes the Maclaurin expansion of I0(x) for small x.                *
 *  Arguments:                                                                *
 *      x (double):                                                           *
 *          A real number.                                                    *
 *  Output:                                                                   *
 *      I0_x (double):                                                        *
 *          The modified Bessel function I0 at x.                             *
 *  Called Functions:                                                         *
 *      None.                                                                 *
 *  Method:                                                                   *
 *      Compute the Maclaurin series of I0(x) using Horner's method:          *
 *                                                                            *
 *                   infty                                                    *
 *                   -----                                                    *
 *                   \          x^2n                                          *
 *          I0(x) =  /      ------------                                      *
 *                   -----   (n!)^2 4^n                                       *
 *                   n = 0                                                    *
 *                                                                            *
 *      Use the first 9 terms (0 <= n <= 8) of this expansion to compute.     *
 *  Notes:                                                                    *
 *      For |x| < 0.5 this is accurate to double precision.                   *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 10, 2022                                              *
 ******************************************************************************/
#include "bessel_i0.h"

/*  Coefficients for the polynomial.                                          */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+2.5000000000000000000000000000000000000000000000000E-01L)
#define A02 (+1.5625000000000000000000000000000000000000000000000E-02L)
#define A03 (+4.3402777777777777777777777777777777777777777777778E-04L)
#define A04 (+6.7816840277777777777777777777777777777777777777778E-06L)
#define A05 (+6.7816840277777777777777777777777777777777777777778E-08L)
#define A06 (+4.7095027970679012345679012345679012345679012345679E-10L)
#define A07 (+2.4028075495244394053917863441672965482489292013102E-12L)
#define A08 (+9.3859669903298414273116654069035021415973796926178E-15L)

/*  Helper macro for evaluating a polynomial with Horner's method.            */
#define POLY_EVAL(z) \
A00+z*(A01+z*(A02+z*(A03+z*(A04+z*(A05+z*(A06+z*(A07+z*A08)))))))

/*  Compute the modified Bessel function I0 with a Maclaurin series.          */
long double I0_LDouble_Maclaurin(long double x)
{
    /*  The function is even and the series is in terms of x^2.               */
    const long double x2 = x*x;

    /*  Use Horner's method to compute and return.                            */
    return POLY_EVAL(x2);
}
/*  End of I0_LDouble_Maclaurin.                                              */
