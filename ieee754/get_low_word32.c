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
 *                               get_low_word32                               *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains source code for getting the "low word" of an IEEE754         *
 *      single precision 32-bit floating point number. This is the            *
 *      fractional part of the number.                                        *
 *  Method:                                                                   *
 *      Get the 32-bit unsigned integer equivalent of the single-precision    *
 *      number and perform bitwise AND with the magic number                  *
 *      11111111111111111111111_2                                             *
 *          = 8388607                                                         *
 *          = 0x7FFFFF (in hexidecimal)                                       *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 22, 2021                                              *
 ******************************************************************************/

/*  Definitions, typedefs, and prototypes found here.                         */
#include "ieee754.h"

/*  Computes the low word of a 32-bit floating-point number.                  */
uint32 Get_Low_Word32(IEEE754_Word32 x)
{
    /*  x.real is a float. Use the union and look at x.integer. This will     *
     *  give us the actual binary value of x.real and we can pretend it is    *
     *  a 32-bit unsigned integer. Bit-wise AND zeros out the high-word.      */
    return x.integer & 0x7FFFFF;
}
/*  End of Get_Low_Word32.                                                    */
