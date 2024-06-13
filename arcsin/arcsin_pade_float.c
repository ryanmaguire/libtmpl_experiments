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
 *      Computes the (4, 4) Pade approximant of asin(x) at double precision.  *
 ******************************************************************************/
#include "arcsin.h"

/*  Coefficients for the numerator of the Pade approximant.                   */
#define P0 (+1.6666666666666666666666666666666666666666666666667E-01F)
#define P1 (-1.1262038994597134132017852948085506225041108762039E-01F)
#define P2 (+4.3770531076732627120224019448825650376037972937198E-03F)

/*  Coefficients for the denominator of the Pade approximant.                 */
#define Q0 (+1.0000000000000000000000000000000000000000000000000E+00F)
#define Q1 (-1.1257223396758280479210711768851303735024665257223E+00F)
#define Q2 (+2.6498022864301934069375929841046120115887557748023E-01F)

/*  Function for computing the (4, 4) Pade approximant of asin(x).            */
float Arcsin_Float_Pade(float x)
{
    /*  The polynomials for the numerator and denominator are in terms of x^2.*/
    const float x2 = x*x;

    /*  Use Horner's method to evaluate the two polynomials.                  */
    const float p = P0 + x2*(P1 + x2*P2);
    const float q = Q0 + x2*(Q1 + x2*Q2);
    const float r = x2*p/q;

    /*  p/q is the Pade approximant for (asin(x) - x) / x^3.                  */
    return x*r + x;
}
/*  End of Arcsin_Float_Pade.                                                 */
