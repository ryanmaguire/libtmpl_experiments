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

/*  Coefficients for the asymptotic expansion.                                */
#define A00 (+1.0000000000000000000000000000000000000000000000000E+00)
#define A01 (+1.2500000000000000000000000000000000000000000000000E-01)
#define A02 (+7.0312500000000000000000000000000000000000000000000E-02)
#define A03 (+7.3242187500000000000000000000000000000000000000000E-02)
#define A04 (+1.1215209960937500000000000000000000000000000000000E-01)
#define A05 (+2.2710800170898437500000000000000000000000000000000E-01)

#define POLY_EVAL(z) A00 + z*(A01 + z*(A02 + z*(A03 + z*(A04 + z*A05))))

/*  The value 1 / (2 pi), well beyond double precision.                       */
#define RCPR_TWO_PI (+1.591549430918953357688837633725143620345E-01)

/*  Function for computing the asymptotic expansion of the Bessel I0 function.*/
 double I0_Double_Very_Large(double x)
{
    /*  The asymptotic expansion is in terms of 1 / x. Compute this.          */
    const double rcpr_x = 1.0 / x;

    /*  The polynomial is scaled by exp(x) / sqrt(2 pi x). Compute these.     */
    const double exp_x = tmpl_Double_Exp_Pos_Kernel(x);
    const double inv_sqrt_two_pi_x = tmpl_Double_Sqrt(RCPR_TWO_PI*rcpr_x);

    /*  Lastly, evaluate the polynomial using Horner's method.                */
    const double poly = POLY_EVAL(rcpr_x);

    /*  Compute the asymptotic expansion and return.                          */
    return exp_x * poly * inv_sqrt_two_pi_x;
}
/*  End of I0_Double_Very_Large.                                              */
