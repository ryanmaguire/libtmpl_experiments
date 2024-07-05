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
#define P00 (+1.1283790574684878861216799875679133907033770017189E+00F)
#define P01 (+1.1827399481209657409919217013238265667649516777735E-01F)
#define P02 (+1.6282372258179479937180108311345578064577917591169E-02F)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00F)
#define Q01 (+4.3814526297098596654375260669316253166090338311380E-01F)
#define Q02 (+6.0530507610345444974553903042771357179713831714362E-02F)

#define NUM_EVAL(z) P00 + z*(P01 + z*P02)
#define DEN_EVAL(z) Q00 + z*(Q01 + z*Q02)

float Erf_Float_Rat_Remez_Small(float x)
{
    const float x2 = x*x;
    const float p = NUM_EVAL(x2);
    const float q = DEN_EVAL(x2);
    return x * p / q;
}
