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

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define A00 (+1.0000000101768264596644949176701798625154736063433E+00F)
#define A01 (+2.4999996188096179966896407666550451827968845884198E-01F)
#define A02 (+1.5625023594801814838785360044976365412877526660974E-02F)
#define A03 (+4.3402208606083211544619903230676725391854302633740E-04F)
#define A04 (+6.7823872024199776276007071260815198092066179642135E-06F)
#define A05 (+6.7766273755484727573969380382882195148248475225689E-08F)
#define A06 (+4.7320922530282525252074561247109800622196646623472E-10F)
#define A07 (+2.3383767653714605649063769775364293656364190812023E-12F)
#define A08 (+1.0554317724276635892174473826139187630804284900294E-14F)
#define A09 (+1.6087975333054007060145708747915892665674486587076E-17F)
#define A10 (+1.4841134515142611287427505334041273350593724053887E-19F)

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
                                    A09 + z*A10\
                                )\
                            )\
                        )\
                    )\
                )\
            )\
        )\
    )\
)

float I0_Float_Remez(float x)
{
    const float x2 = x*x;
    return POLY_EVAL(x2);
}
