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
#include "bessel_i0.h"
#include <libtmpl/include/tmpl_math.h>

/*  Location of the TMPL_LDOUBLE_TYPE macro.                                  */
#include <libtmpl/include/tmpl_config.h>

/*  64-bit long double does not need any more precision than 64-bit double.   */
#if TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_64_BIT

/******************************************************************************
 *                               64-bit Double                                *
 ******************************************************************************/

/*  Coefficients for the asymptotic expansion.                                */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+1.2500000000000000000000000000000000000000000000000E-01L)
#define A02 (+7.0312500000000000000000000000000000000000000000000E-02L)
#define A03 (+7.3242187500000000000000000000000000000000000000000E-02L)
#define A04 (+1.1215209960937500000000000000000000000000000000000E-01L)
#define A05 (+2.2710800170898437500000000000000000000000000000000E-01L)

#define POLY_EVAL(z) A00 + z*(A01 + z*(A02 + z*(A03 + z*(A04 + z*A05))))

/*  128-bit double-double, a few more terms.                                  */
#elif TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_DOUBLEDOUBLE

/******************************************************************************
 *                           128-bit Double-Double                            *
 ******************************************************************************/

/*  Coefficients for the asymptotic expansion.                                */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+1.2500000000000000000000000000000000000000000000000E-01L)
#define A02 (+7.0312500000000000000000000000000000000000000000000E-02L)
#define A03 (+7.3242187500000000000000000000000000000000000000000E-02L)
#define A04 (+1.1215209960937500000000000000000000000000000000000E-01L)
#define A05 (+2.2710800170898437500000000000000000000000000000000E-01L)
#define A06 (+5.7250142097473144531250000000000000000000000000000E-01L)
#define A07 (+1.7277275025844573974609375000000000000000000000000E+00L)
#define A08 (+6.0740420012734830379486083984375000000000000000000E+00L)
#define A09 (+2.4380529699556063860654830932617187500000000000000E+01L)
#define A10 (+1.1001714026924673817120492458343505859375000000000E+02L)
#define A11 (+5.5133589612202058560797013342380523681640625000000E+02L)
#define A12 (+3.0380905109223842686105854227207601070404052734375E+03L)
#define A13 (+1.8257755474293174691169383550004567950963973999023E+04L)

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

/*  128-bit quadruple, and a few more terms.                                  */
#elif TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_128_BIT

/******************************************************************************
 *                             128-bit Quadruple                              *
 ******************************************************************************/

/*  Coefficients for the asymptotic expansion.                                */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+1.2500000000000000000000000000000000000000000000000E-01L)
#define A02 (+7.0312500000000000000000000000000000000000000000000E-02L)
#define A03 (+7.3242187500000000000000000000000000000000000000000E-02L)
#define A04 (+1.1215209960937500000000000000000000000000000000000E-01L)
#define A05 (+2.2710800170898437500000000000000000000000000000000E-01L)
#define A06 (+5.7250142097473144531250000000000000000000000000000E-01L)
#define A07 (+1.7277275025844573974609375000000000000000000000000E+00L)
#define A08 (+6.0740420012734830379486083984375000000000000000000E+00L)
#define A09 (+2.4380529699556063860654830932617187500000000000000E+01L)
#define A10 (+1.1001714026924673817120492458343505859375000000000E+02L)
#define A11 (+5.5133589612202058560797013342380523681640625000000E+02L)
#define A12 (+3.0380905109223842686105854227207601070404052734375E+03L)
#define A13 (+1.8257755474293174691169383550004567950963973999023E+04L)
#define A14 (+1.1883842625678325312377214828529758960939943790436E+05L)

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
                                                A12 + z*(\
                                                    A13 + z*A14\
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
    )\
)

/*  80-bit extended and portable version.                                     */
#else

/******************************************************************************
 *                         80-bit Extended / Portable                         *
 ******************************************************************************/

/*  Coefficients for the asymptotic expansion.                                */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define A01 (+1.2500000000000000000000000000000000000000000000000E-01L)
#define A02 (+7.0312500000000000000000000000000000000000000000000E-02L)
#define A03 (+7.3242187500000000000000000000000000000000000000000E-02L)
#define A04 (+1.1215209960937500000000000000000000000000000000000E-01L)
#define A05 (+2.2710800170898437500000000000000000000000000000000E-01L)
#define A06 (+5.7250142097473144531250000000000000000000000000000E-01L)
#define A07 (+1.7277275025844573974609375000000000000000000000000E+00L)

#define POLY_EVAL(z) \
A00 + z*(A01 + z*(A02 + z*(A03 + z*(A04 + z*(A05 + z*(A06 + z*A07))))))

#endif
/*  End of double vs. extended vs. quadruple vs. double-double.               */

/*  The value 1 / (2 pi), well beyond double precision.                       */
#define RCPR_TWO_PI (+1.591549430918953357688837633725143620345E-01L)

/*  Function for computing the asymptotic expansion of the Bessel I0 function.*/
long double I0_LDouble_Very_Large(long double x)
{
    /*  The asymptotic expansion is in terms of 1 / x. Compute this.          */
    const long double rcpr_x = 1.0L / x;

    /*  The polynomial is scaled by exp(x) / sqrt(2 pi x). Compute these.     */
    const long double exp_x = tmpl_LDouble_Exp_Pos_Kernel(x);
    const long double inv_sqrt_two_pi_x = tmpl_LDouble_Sqrt(RCPR_TWO_PI*rcpr_x);

    /*  Lastly, evaluate the polynomial using Horner's method.                */
    const long double poly = POLY_EVAL(rcpr_x);

    /*  Compute the asymptotic expansion and return.                          */
    return exp_x * poly * inv_sqrt_two_pi_x;
}
/*  End of I0_LDouble_Very_Large.                                             */
