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
 *  Purpose:                                                                  *
 *      Computes a Maclaurin series for asin(x).                              *
 ******************************************************************************/
#include "arcsin.h"

/*  Only the odd non-constant terms have non-zero coefficients.               */
#define A00 (1.0000000000000000000000000000000000000000000000000E+00)
#define A01 (1.6666666666666666666666666666666666666666666666667E-01)
#define A02 (7.5000000000000000000000000000000000000000000000000E-02)
#define A03 (4.4642857142857142857142857142857142857142857142857E-02)
#define A04 (3.0381944444444444444444444444444444444444444444444E-02)
#define A05 (2.2372159090909090909090909090909090909090909090909E-02)
#define A06 (1.7352764423076923076923076923076923076923076923077E-02)
#define A07 (1.3964843750000000000000000000000000000000000000000E-02)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define POLY_EVAL(z) \
A00 + z*(A01 + z*(A02 + z*(A03 + z*(A04 + z*(A05 + z*(A06 + z*A07))))))

/*  Computes the degree 15 Maclaurin polynomial for asin(x).                  */
double Arcsin_Double_Maclaurin(double x)
{
    /*  The non-constant terms are odd, powers are x^{2n+1}.                  */
    const double x2 = x*x;

    /*  Compute the Maclaurin series of asin(x) / x.                          */
    const double poly = POLY_EVAL(x2);

    /*  Scale by the input to complete the computation.                       */
    return x*poly;
}
/*  End of Arcsin_Double_Maclaurin.                                           */
