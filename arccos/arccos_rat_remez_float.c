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
#define A00 (+1.6666586697E-01F)
#define A01 (-4.2743422091E-02F)
#define A02 (-8.6563630030E-03F)

/*  Coefficients for the denominator.                                         */
#define B00 (+1.0000000000E+00F)
#define B01 (-7.0662963390E-01F)

/*  The constant Pi / 2.                                                      */
#define PI_BY_TWO (+1.5707963267948966192313216916397514420985846996F)

/*  Function for computing the (4, 2) minimax approximation of acos(x).       */
float Arccos_Float_Rat_Remez(float x)
{
    /*  The polynomials for the numerator and denominator are in terms of x^2.*/
    const float x2 = x*x;

    /*  Use Horner's method to evaluate the two polynomials.                  */
    const float p = A00 + x2*(A01 + x2*A02);
    const float q = B00 + x2*B01;
    const float r = x2*p/q;

    /*  p/q is the minimax approximation for (acos(x) - pi/2 + x) / x^3.      */
    return PI_BY_TWO - (x + x*r);
}
/*  End of Arccos_Float_Rat_Remez.                                            */
