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

/*  Function prototype provided here.                                         */
#include "error_function.h"

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283792500936792357468612282246335754294528093032E+00F)
#define P01 (+1.4404785710085938449469430497075715069787385141856E-01F)
#define P02 (+3.8671193332867291322816068826200285448434050179743E-02F)
#define P03 (+4.7012258030347397778439878660187630172746911222722E-04F)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00F)
#define Q01 (+4.6099523556810747961213984923160441469503967403520E-01F)
#define Q02 (+8.7919480381435851752733729146603316335501327058064E-02F)
#define Q03 (+7.4722501454901781876838346974059155836429539254916E-03F)

#define TMPL_NUM_EVAL(z) P00 + z*(P01 + z*(P02 + z*P03))
#define TMPL_DEN_EVAL(z) Q00 + z*(Q01 + z*(Q02 + z*Q03))

float Erf_Float_Rat_Remez(float x)
{
    const float x2 = x*x;
    const float p = TMPL_NUM_EVAL(x2);
    const float q = TMPL_DEN_EVAL(x2);
    return x * p / q;
}
