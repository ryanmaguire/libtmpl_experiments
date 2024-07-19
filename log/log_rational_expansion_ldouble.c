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
 *  Author:     Ryan Maguire                                                  *
 *  Date:       2021                                                          *
 ******************************************************************************/
#include <libtmpl/include/tmpl_ieee754.h>

/*  Coefficients for the polynomial.                                          */
#define A00 (+2.0000000000000000000000000000000E+00L)
#define A01 (+6.6666666666666666666666666666667E-01L)
#define A02 (+4.0000000000000000000000000000000E-01L)
#define A03 (+2.8571428571428571428571428571429E-01L)
#define A04 (+2.2222222222222222222222222222222E-01L)
#define A05 (+1.8181818181818181818181818181818E-01L)
#define A06 (+1.5384615384615384615384615384615E-01L)
#define A07 (+1.3333333333333333333333333333333E-01L)
#define A08 (+1.1764705882352941176470588235294E-01L)
#define A09 (+1.0526315789473684210526315789474E-01L)
#define A10 (+9.5238095238095238095238095238095E-02L)
#define A11 (+8.6956521739130434782608695652174E-02L)
#define A12 (+8.0000000000000000000000000000000E-02L)

/*  The natural log of two, used as a scale factor.                           */
#define LOG_OF_TWO (+6.9314718055994530941723212145817651E-01L)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define POLY_EVAL(z) \
A00 + z*(\
  A01 + z*(\
    A02 + z*(\
      A03 + z*(\
        A04 + z*(\
          A05 + z*(\
            A06 + z*(\
              A07 + z*(\
                A08 + z*(\
                  A09 + z*(\
                    A10 + z*(\
                      A11 + z*A12\
                    )\
                  )\
                )\
              )\
            )\
          )\
        )\
      )\
    )\
  )\
)

long double Log_LDouble_Rational_Expansion(long double x)
{
    long double mantissa, A, A_sq, poly, exponent;
    tmpl_IEEE754_LDouble w;
    w.r = x;

    if (TMPL_LDOUBLE_IS_NEGATIVE(w))
        return TMPL_NANL;

    if (w.r == 0.0L)
        return -TMPL_INFINITYL;

    if (TMPL_LDOUBLE_IS_NAN_OR_INF(w))
        return x;

    exponent = (long double)(w.bits.expo - TMPL_LDOUBLE_BIAS);
    w.bits.expo = TMPL_LDOUBLE_BIAS;
    mantissa = w.r;

    if (mantissa > 1.5L)
    {
        mantissa *= 0.5L;
        exponent += 1.0L;
    }

    A = (mantissa - 1.0L) / (mantissa + 1.0L);
    A_sq = A*A;
    poly = POLY_EVAL(A_sq);
    return LOG_OF_TWO*exponent + A*poly;
}
