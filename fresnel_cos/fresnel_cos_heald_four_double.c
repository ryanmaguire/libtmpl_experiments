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
#include"fresnel_cos.h"
#include <libtmpl/include/tmpl_math.h>

/******************************************************************************
 *  Coeofficients defined in:                                                 *
 *      Mark. A. Heald.                                                       *
 *      Rational Approximations for the Fresnel Integrals,                    *
 *      Mathematics of Computation                                            *
 *      Vol. 44, No. 170 (Apr., 1985), pp. 459-461                            *
 *  Error bounded by 10^-4.                                                   *
 ******************************************************************************/
#define A0 (+1.0000000000000000E+00)
#define A1 (+1.7650000000000000E-01)
#define B0 (+2.0000000000000000E+00)
#define B1 (+2.9150000000000000E+00)
#define B2 (+2.0790000000000000E+00)
#define B3 (+1.5190000000000000E+00)
#define C0 (+1.0000000000000000E+00)
#define C1 (+5.0830000000000000E-01)
#define C2 (+3.5690000000000000E-01)
#define D0 (+1.4142135623730951E+00)
#define D1 (+2.1416000000000000E+00)
#define D2 (+1.8515000000000000E+00)
#define D3 (+1.1021000000000000E+00)

#define SQRT_2_BY_PI (+7.978845608028654E-01)
#define PI_BY_TWO (+1.5707963267948966E+00)
#define SQRT_PI_BY_2 (+1.2533141373155001E+00)
#define SQRT_PI_BY_8 (+6.266570686577501E-01)

double Fresnel_Cos_Double_Heald_Four(double x)
{
    /*  The argument for the Heald approximation.                             */
    const double arg = SQRT_2_BY_PI * tmpl_Double_Abs(x);

    /* Compute the Numerator of the A_jk Function.                            */
    const double a = A0 + arg*A1;

    /* Compute the Denominator of the A_jk Function.                          */
    const double b = B0 + arg*(B1 + arg*(B2 + arg*B3));

    /* Compute the Numerator of the R_lm Function.                            */
    const double c = C0 + arg*(C1 + arg*C2);

    /* Compute the Denominator of the R_lm Function.                          */
    const double d = D0 + arg*(D1 + arg*(D2 + arg*D3));

    /*  The two rational functions.                                           */
    const double A = (a/b - arg*arg) * PI_BY_TWO;
    const double R = SQRT_PI_BY_2 * (c / d);

    /*  The Heald approximation.                                              */
    const double out = SQRT_PI_BY_8 - R*tmpl_Double_Sin(A);

    /*  C(x) is an odd function. Negate if the input is negative.             */
    if (x < 0.0)
        return -out;

    return out;
}
