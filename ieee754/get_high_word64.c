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
 *                              get_high_word64                               *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains source code for getting the "high word" of an IEEE754        *
 *      double precision 64-bit floating point number. This is the            *
 *      exponent part of the number and the sign.                             *
 *  Method:                                                                   *
 *      Get the unsigned integer equivalent of the double-precision number,   *
 *      bit shift it over 52-binary digits.                                   *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 22, 2021                                              *
 ******************************************************************************/

/*  Definitions, typedefs, and prototypes found here.                         */
#include "ieee754.h"

/*  Computes the high word of a 64-bit floating-point number.                 */
uint32 Get_High_Word64(IEEE754_Word64 x)
{
    /*  x.real is a double. Use the union and look at x.integer. This will    *
     *  give us the actual binary value of x.real and we can pretend it is    *
     *  an unsigned long.                                                     *
     *                                                                        *
     *  The first bit is the sign, the next 11 are the exponent, and the last *
     *  52 are the fractional parts. We don't care about the fractional part  *
     *  since we are trying to get the high-word. Shift the "decimal"         *
     *  (i.e. the "point") over 52 digits. This is equivalent to dividing by  *
     *  2^52 and looking at the integer part, but is a lot faster.            *
     *                                                                        *
     *  To put the problem into decimal, if asked to divide 1000 by 100, you  *
     *  would not perform long division, but rather just shift the decimal    *
     *  point over by 2, giving 10. This is the binary version of this.       */
    return (uint32)(x.integer >> 52);
}
/*  End of tmpl_Get_High_Word64.                                              */
