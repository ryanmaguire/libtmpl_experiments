/******************************************************************************
 *                                 LICENSE                                    *
 ******************************************************************************
 *  This file is part of libtmpl.                                             *
 *                                                                            *
 *  libtmpl is free software: you can redistribute it and/or modify it        *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl is distributed in the hope that it will be useful,                *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.         *
 ******************************************************************************
 *                               get_low_word64                               *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains source code for getting the "low word" of an IEEE754         *
 *      double precision 64-bit floating point number. This is the            *
 *      fractional part of the number.                                        *
 *  Method:                                                                   *
 *      Get the unsigned integer equivalent of the double-precision number    *
 *      and perform bitwise AND with the magic number                         *
 *      11111111111111111111111111111111111111111111111111_2                  *
 *          = 4503599627370495                                                *
 *          = 0xFFFFFFFFFFFFF (in hexidecimal).                               *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 22, 2021                                              *
 ******************************************************************************/

/*  Definitions, typedefs, and prototypes found here.                         */
#include "ieee754.h"

/*  Computes the low word of a 64-bit floating-point number.                  */
uint64 Get_Low_Word64(IEEE754_Word64 x)
{
    /*  x.real is a double. Use the union and look at x.integer. This will    *
     *  give us the actual binary value of x.real and we can pretend it is    *
     *  an unsigned integer.                                                  *
     *                                                                        *
     *  Bit-wise AND can help us zero out the high-word. If we have:          *
     *  s eeeeeeeeee xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     *
     *  - ---------- ----------------------------------------------------     *
     *                                                                        *
     *  And then perform bitwise AND with 4503599627370495, we get:           *
     *    s eeeeeeeeee xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   *
     *  & 0 0000000000 1111111111111111111111111111111111111111111111111111   *
     *  = 0 0000000000 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   *
     *                                                                        *
     *  In other words, we get the low-word.                                  */
    return x.integer & 0xFFFFFFFFFFFFF;
}
/*  End of Get_Low_Word64.                                                    */

