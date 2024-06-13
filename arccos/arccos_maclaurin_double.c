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
 *      Computes a Maclaurin series for acos(x) at double precision.          *
 ******************************************************************************/
#include "arccos.h"

/*  Only the odd non-constant terms have non-zero coefficients.               */
#define A0 (1.0000000000000000000000000000000000000000000000000E+00)
#define A1 (1.6666666666666666666666666666666666666666666666667E-01)
#define A2 (7.5000000000000000000000000000000000000000000000000E-02)
#define A3 (4.4642857142857142857142857142857142857142857142857E-02)
#define A4 (3.0381944444444444444444444444444444444444444444444E-02)
#define A5 (2.2372159090909090909090909090909090909090909090909E-02)
#define A6 (1.7352764423076923076923076923076923076923076923077E-02)
#define A7 (1.3964843750000000000000000000000000000000000000000E-02)

/*  The constant Pi / 2.                                                      */
#define PI_BY_TWO (+1.5707963267948966192313216916397514420985846996)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define POLY_EVAL(z) \
A0 + z*(A1 + z*(A2 + z*(A3 + z*(A4 + z*(A5 + z*(A6 + z*A7))))))

/*  Computes the degree 15 Maclaurin polynomial for acos(x).                  */
double Arccos_Double_Maclaruin(double x)
{
    /*  The non-constant terms are odd, powers are x^{2n+1}.                  */
    const double x2 = x*x;

    /*  Compute the Maclaurin series of asin(x) / x.                          */
    const double poly = POLY_EVAL(x2);

    /*  acos(x) = pi/2 - asin(x). Compute using this.                         */
    return PI_BY_TWO - x*poly;
}
/*  End of Arccos_Double_Maclaruin.                                           */
