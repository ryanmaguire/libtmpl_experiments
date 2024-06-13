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

/*  Square root and exponential functions provided here.                      */
#include <libtmpl/include/tmpl_math.h>

/*  Function prototype provided here.                                         */
#include "error_function.h"

/*  The alpha factor in the approximation is 8(pi-3)/3pi(4-pi). It is better  *
 *  to use alpha = 0.147, which reduces the peak relative error to ~0.00013.  */
#define ALPHA_FACTOR (+1.470E-01F)
#define FOUR_BY_PI (+1.27323954473516268615107010698011E+00F)

/*  Evaluation of the error function using Winitzki's approximation.          */
float Erf_Float_Winitzki(float x)
{
    /*  Compute (4/pi + alpha x^2) / (1 + alpha x^2).                         */
    const float x_sq = x*x;
    const float z = ALPHA_FACTOR * x_sq;
    const float num = FOUR_BY_PI + z;
    const float denom = 1.0F + z;
    const float rat = num/denom;

    /*  The approximation is +/- sqrt(1 - exp(-x^2 * rat)) depending on the   *
     *  sign of x, so compute this.                                           */
    const float val = tmpl_Float_Exp(-rat*x_sq);
    const float erf_x = tmpl_Float_Sqrt(1.0F - val);

    /*  The error function is odd. Return -erf_x for negative x.              */
    if (x < 0.0F)
        return -erf_x;

    /*  Otherwise we have a decent approximation for erf(x). Return this.     */
    return erf_x;
}
/*  End of Erf_Float_Winitzki.                                                */
