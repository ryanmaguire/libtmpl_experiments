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
 *      Computes arccos using a rational Remez approximation.                 *
 ******************************************************************************/
#include "arccos.h"

/*  Coefficients for the numerator.                                           */
#define A00 (+1.66666666666666657415E-01)
#define A01 (-3.25565818622400915405E-01)
#define A02 (+2.01212532134862925881E-01)
#define A03 (-4.00555345006794114027E-02)
#define A04 (+7.91534994289814532176E-04)
#define A05 (+3.47933107596021167570E-05)

/*  Coefficients for the denominator.                                         */
#define B00 (+1.00000000000000000000E+00)
#define B01 (-2.40339491173441421878E+00)
#define B02 (+2.02094576023350569471E+00)
#define B03 (-6.88283971605453293030E-01)
#define B04 (+7.70381505559019352791e-02)

/*  Helper macros for evaluating polynomials using Horner's method.           */
#define NUM_EVAL(z) A00 + z*(A01 + z*(A02 + z*(A03 + z*(A04 + z*A05))))
#define DEN_EVAL(z) B00 + z*(B01 + z*(B02 + z*(B03 + z*B04)))

/*  The constant Pi / 2.                                                      */
#define PI_BY_TWO (+1.5707963267948966192313216916397514420985846996E+00)

/*  Function for computing the (10, 8) minimax approximation for acos(x).     */
double Arccos_Double_Rat_Remez(double x)
{
    /*  The polynomials for the numerator and denominator are in terms of x^2.*/
    const double x2 = x*x;

    /*  Use Horner's method to evaluate the two polynomials.                  */
    const double p = NUM_EVAL(x2);
    const double q = DEN_EVAL(x2);
    const double r = x2*p/q;

    /*  p/q is the rational minimax approximant for (acos(x) - pi/2 + x)/x^3. */
    return PI_BY_TWO - (x + x*r);
}
/*  End of Arccos_Double_Rat_Remez.                                           */
