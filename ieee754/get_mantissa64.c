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
 *                               get_mantissa64                               *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Contains source code for getting the mantissa of an IEEE754 double    *
 *      precision floating point number. Given the number 1.m * 2^b, this     *
 *      returns 1.m. The value "b" is the exponent.                           *
 *  Method:                                                                   *
 *      Extract the low-word via bitwise AND with the magic number            *
 *      0x000FFFFFFFFFFFFF and then add 0x3FF0000000000000, which is the      *
 *      hexidecimal representation for 1.0 in IEEE754 for 64-bit double.      *
 *      Treat this integer as a double according to the IEEE754 format and    *
 *      return.                                                               *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       April 7, 2021                                                 *
 ******************************************************************************/

/*  Definitions, typedefs, and prototypes found here.                         */
#include "ieee754.h"

/*  Function for extracting the mantissa from a 64-bit floating point number. */
double Get_Mantissa64(IEEE754_Word64 w)
{
    /*  Use the IEEE 754 64-bit union to convert between double and binary.   */
    IEEE754_Word64 out;

    /*  Use bitwise AND with 0x000FFFFFFFFFFFFF to extract the low word. Then *
     *  add 0x3FF0000000000000 which is the hexidecimal representation of 1.0.*
     *  This will give use 1.0 + 0.m = 1.m, which is what we want.            */
    out.integer = (w.integer & 0x000FFFFFFFFFFFFF) | 0x3FF0000000000000;

    /*  Return the double part from the IEEE 754 union data type.             */
    return out.real;
}
/*  End of Get_Mantissa64.                                                    */
