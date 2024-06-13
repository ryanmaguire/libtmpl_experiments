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

/*  Absolute value and exponential function provided here.                    */
#include <libtmpl/include/tmpl_math.h>

/*  Function prototype provided here.                                         */
#include "error_function.h"

/*  Coefficients for the polynomial part of the approximation.                */
#define A0 (-1.26551223E+00L)
#define A1 (+1.00002368E+00L)
#define A2 (+3.74091960E-01L)
#define A3 (+9.67841800E-02L)
#define A4 (-1.86288060E-01L)
#define A5 (+2.78868070E-01L)
#define A6 (-1.13520398E+00L)
#define A7 (+1.48851587E+00L)
#define A8 (-8.22152230E-01L)
#define A9 (+1.70872770E-01L)

/*  Helper macro for evaluating the polynomial using Horner's method.         */
#define POLY_EVAL(z) \
A0+z*(A1+z*(A2+z*(A3+z*(A4+z*(A5+z*(A6+z*(A7+z*(A8+z*A9))))))))

/*  Algorithm from Numerical Recipes for computing erf(x).                    */
long double Erf_LDouble_Numerical_Recipes(long double x)
{
    /*  erf(x) is odd so compute the absolute value and use this.             */
    const long double abs_x = tmpl_LDouble_Abs(x);

    /*  Rational expression for the polynomial part.                          */
    const long double t = 2.0L / (2.0L + abs_x);

    /*  Compute the polynomial using Horner's method.                         */
    const long double poly = POLY_EVAL(t);

    /*  t * exp(-x^2 + poly) approximates erfc(x). Compute 1 minus this.      */
    const long double erf_abs_x = 1.0L - t*tmpl_LDouble_Exp(-abs_x*abs_x+poly);

    /*  The error function is odd. Return -erf_x for negative x.              */
    if (x < 0.0L)
        return -erf_abs_x;

    /*  Otherwise we have a decent approximation for erf(x). Return this.     */
    return erf_abs_x;
}
/*  End of Erf_LDouble_Numerical_Recipes.                                     */
