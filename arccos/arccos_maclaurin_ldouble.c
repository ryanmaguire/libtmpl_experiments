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
 *      Computes a Maclaurin series for acos(x) at single precision.          *
 ******************************************************************************/
#include "arccos.h"

/*  Location of the TMPL_LDOUBLE_TYPE macro.                                  */
#include <libtmpl/include/tmpl_config.h>

/*  The constant Pi / 2.                                                      */
#define PI_BY_TWO (+1.5707963267948966192313216916397514420985846996L)

/*  64-bit long double does not need any more precision than 64-bit double.   */
#if TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_64_BIT

/******************************************************************************
 *                           64-Bit Double Version                            *
 ******************************************************************************/

/*  Only the odd non-constant terms have non-zero coefficients.               */
#define A00 (1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (1.6666666666666666666666666666666666666666666666667E-01L)
#define A02 (7.5000000000000000000000000000000000000000000000000E-02L)
#define A03 (4.4642857142857142857142857142857142857142857142857E-02L)
#define A04 (3.0381944444444444444444444444444444444444444444444E-02L)
#define A05 (2.2372159090909090909090909090909090909090909090909E-02L)
#define A06 (1.7352764423076923076923076923076923076923076923077E-02L)
#define A07 (1.3964843750000000000000000000000000000000000000000E-02L)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define POLY_EVAL(z) \
A00 + z*(A01 + z*(A02 + z*(A03 + z*(A04 + z*(A05 + z*(A06 + z*A07))))))

/*  128-bit quadruple and double-double, a few more terms.                    */
#elif TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_128_BIT || \
      TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_DOUBLEDOUBLE

/******************************************************************************
 *                 128-bit Quadruple / 128-bit Double-Double                  *
 ******************************************************************************/

/*  Coefficients for the polynomial.                                          */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+1.6666666666666666666666666666666666666666666666667E-01L)
#define A02 (+7.5000000000000000000000000000000000000000000000000E-02L)
#define A03 (+4.4642857142857142857142857142857142857142857142857E-02L)
#define A04 (+3.0381944444444444444444444444444444444444444444444E-02L)
#define A05 (+2.2372159090909090909090909090909090909090909090909E-02L)
#define A06 (+1.7352764423076923076923076923076923076923076923077E-02L)
#define A07 (+1.3964843750000000000000000000000000000000000000000E-02L)
#define A08 (+1.1551800896139705882352941176470588235294117647059E-02L)
#define A09 (+9.7616095291940789473684210526315789473684210526316E-03L)
#define A10 (+8.3903358096168154761904761904761904761904761904762E-03L)
#define A11 (+7.3125258735988451086956521739130434782608695652174E-03L)
#define A12 (+6.4472103118896484375000000000000000000000000000000E-03L)
#define A13 (+5.7400376708419234664351851851851851851851851851852E-03L)

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
                                            A11 + z*(\
                                                A12 + z*A13\
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
    )\
)

/*  Lastly, extended precision and portable versions.                         */
#else

/******************************************************************************
 *                         80-Bit Extended / Portable                         *
 ******************************************************************************/

/*  Coefficients for the polynomial.                                          */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+1.6666666666666666666666666666666666666666666666667E-01L)
#define A02 (+7.5000000000000000000000000000000000000000000000000E-02L)
#define A03 (+4.4642857142857142857142857142857142857142857142857E-02L)
#define A04 (+3.0381944444444444444444444444444444444444444444444E-02L)
#define A05 (+2.2372159090909090909090909090909090909090909090909E-02L)
#define A06 (+1.7352764423076923076923076923076923076923076923077E-02L)
#define A07 (+1.3964843750000000000000000000000000000000000000000E-02L)
#define A08 (+1.1551800896139705882352941176470588235294117647059E-02L)
#define A09 (+9.7616095291940789473684210526315789473684210526316E-03L)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define POLY_EVAL(z) \
A00+z*(A01+z*(A02+z*(A03+z*(A04+z*(A05+z*(A06+z*(A07+z*(A08+z*A09))))))))

#endif
/*  End of 80-bit extended / portable version.                                */

/*  Computes the Maclaurin polynomial for acos(x).                            */
long double Arccos_LDouble_Maclaurin(long double x)
{
    /*  The non-constant terms are odd, powers are x^{2n+1}.                  */
    const long double x2 = x*x;

    /*  Compute the Maclaurin series of asin(x) / x.                          */
    const long double poly = POLY_EVAL(x2);

    /*  acos(x) = pi/2 - asin(x). Compute using this.                         */
    return PI_BY_TWO - x*poly;
}
/*  End of Arccos_LDouble_Maclaurin.                                          */
