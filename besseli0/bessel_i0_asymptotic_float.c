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
 *                         bessel_i0_asymptotic_float                         *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Computes the asymptotic expansion of I0(x) at single precision.       *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Function Name:                                                            *
 *      I0_Float_Asymptotic                                                   *
 *  Purpose:                                                                  *
 *      Computes the asymptotic expansion of I0(x) for large positive x.      *
 *  Arguments:                                                                *
 *      x (float):                                                            *
 *          A real number.                                                    *
 *  Output:                                                                   *
 *      I0_x (float):                                                         *
 *          The asymptotic expansion of x.                                    *
 *  Called Functions:                                                         *
 *      tmpl_math.h:                                                          *
 *          tmpl_Float_Exp_Pos_Kernel:                                        *
 *              Computes exp(x) for x > 1.                                    *
 *          tmpl_Float_Sqrt (tmpl_math.h):                                    *
 *              Computes the square root of a real number.                    *
 *  Method:                                                                   *
 *      Compute the reciprocal of x and use Horner's method to efficiently    *
 *      evaluate the polynomial.                                              *
 *                                                                            *
 *                                 infty                                      *
 *                                 -----                                      *
 *                      exp(x)     \      ((2n+1)!!)^2                        *
 *          I0(x) ~  ------------  /      ------------     x --> infty        *
 *                   sqrt(2 pi x)  -----   n! (8x)^n                          *
 *                                 n = 0                                      *
 *                                                                            *
 *      Use the first 5 terms (0 <= n <= 4) of this expansion to compute.     *
 *  Notes:                                                                    *
 *      Only accurate for large POSITIVE values. For x > 32 this function     *
 *      is accurate to single precision (10^-7 relative error). The closer    *
 *      the input is to 0, the worse the error.                               *
 *                                                                            *
 *      This function can be used for large negative values via:              *
 *          I0(x) ~= I0_Float_Asymptotic(-x).                                 *
 ******************************************************************************
 *                                DEPENDENCIES                                *
 ******************************************************************************
 *  1.) tmpl_math.h:                                                          *
 *          Header file containing exp and sqrt functions.                    *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 10, 2022                                              *
 ******************************************************************************/

/*  Function prototype found here.                                            */
#include "bessel_i0.h"

/*  Exp kernel found here, as is the square root function.                    */
#include <libtmpl/include/tmpl_math.h>

/*  Coefficients for the asymptotic expansion.                                */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00F)
#define A01 (+1.2500000000000000000000000000000000000000000000000E-01F)
#define A02 (+7.0312500000000000000000000000000000000000000000000E-02F)
#define A03 (+7.3242187500000000000000000000000000000000000000000E-02F)
#define A04 (+1.1215209960937500000000000000000000000000000000000E-01F)

/*  Helper macro for evaluating the polynomial part using Horner's method.    */
#define ASYMPTOTIC_EXPANSION(z) A00 + z*(A01 + z*(A02 + z*(A03 + z*A04)))

/*  The value 1 / (2 pi), well beyond single precision.                       */
#define RCPR_TWO_PI (+1.591549430918953357688837633725143620345E-01F)

/*  Function for computing the asymptotic expansion of the Bessel I0 function.*/
float I0_Float_Asymptotic(float x)
{
    /*  The asymptotic expansion is in terms of 1 / x. Compute this.          */
    const float rcpr_x = 1.0F / x;

    /*  The polynomial is scaled by exp(x) / sqrt(2 pi x). Compute these.     */
    const float exp_x = tmpl_Float_Exp_Pos_Kernel(x);
    const float inv_sqrt_two_pi_x = tmpl_Float_Sqrt(RCPR_TWO_PI * rcpr_x);

    /*  Lastly, evaluate the polynomial using Horner's method.                */
    const float poly = ASYMPTOTIC_EXPANSION(rcpr_x);

    /*  Compute the asymptotic expansion and return.                          */
    return exp_x * poly * inv_sqrt_two_pi_x;
}
/*  End of I0_Float_Asymptotic.                                               */
