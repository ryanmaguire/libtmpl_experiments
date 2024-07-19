/******************************************************************************
 *                                 LICENSE                                    *
 ******************************************************************************
 *  This file is part of libtmpl.                                             *
 *                                                                            *
 *  libtmpl is free software: you can redistribute it and/or modify it        *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl is distributed in the hope that it will be useful,                *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.         *
 ******************************************************************************/
#include "lambertw.h"

/*  Coefficients for the numerator.                                           */
#define P0 (-8.63399505615014331E-02)
#define P1 (-1.64303871814816464E+00)
#define P2 (-7.71247913918273738E+00)
#define P3 (-1.41014495545382454E+01)
#define P4 (-1.02269079949257616E+01)
#define P5 (-2.17236002836306691E+00)

/*  Coefficients for the denominator.                                         */
#define Q0 (+1.00000000000000000E+00)
#define Q1 (+7.44775406945739243E+00)
#define Q2 (+2.04392643087266541E+01)
#define Q3 (+2.51001961077774193E+01)
#define Q4 (+1.31256080849023319E+01)
#define Q5 (+2.11640324843601588E+00)

/*  Constant shift. The approximation is x*(A0 + P(x) / Q(x)).                */
#define A0 (+1.08633995056152344E+00)

/*  Helper macros for evaluating polynomials using Horner's method.           */
#define NUM_EVAL(x) P0 + x*(P1 + x*(P2 + x*(P3 + x*(P4 + x*P5))))
#define DEN_EVAL(x) Q0 + x*(Q1 + x*(Q2 + x*(Q3 + x*(Q4 + x*Q5))))

/*  Rational Remez approximation for LambertW on [-0.1, 0.0].                 */
double LambertW_Double_Rat_Remez_Neg_One_Tenth_To_Zero(double x)
{
    const double p = NUM_EVAL(x);
    const double q = DEN_EVAL(x);
    return x * (A0 + p / q);
}
/*  End of LambertW_Double_Rat_Remez_Neg_One_Tenth_To_Zero.                   */
