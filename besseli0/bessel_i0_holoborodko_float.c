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

/*  Coefficients for the Remez polynomial.                                    */
#define A0 (3.98942651588301770E-01F)
#define A1 (4.98327234176892844E-02F)
#define A2 (2.91866904423115499E-02F)
#define A3 (1.35614940793742178E-02F)
#define A4 (1.31409251787866793E-01F)

#define POLY_EVAL(z) A0 + z*(A1 + z*(A2 + z*(A3 + z*A4)))

float I0_Float_Holoborodko(float x)
{
    const float rcpr_x = 1.0F / x;
    const float exp_x = tmpl_Float_Exp_Pos_Kernel(x);
    const float inv_sqrt_x = tmpl_Float_Sqrt(rcpr_x);
    const float poly = POLY_EVAL(rcpr_x);
    return exp_x * poly * inv_sqrt_x;
}
