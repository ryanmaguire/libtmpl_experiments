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
 *                              get_base_2_exp64                              *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Computes the exponent part of a 64-bit floating point value that is   *
 *      represented using the IEEE 754 double precision format. That is,      *
 *      given a floating point number x = 1.m * 2^b, this function returns    *
 *      b. The value 1.m is called the mantissa.                              *
 *  Method:                                                                   *
 *      Extract the high word of the floating point number and subtract 1023  *
 *      from this, as specified in the IEEE 754 format.                       *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  2.) ieee754.h:                                                            *
 *          Header file that contains union data types for working with       *
 *          floating point numbers using 32 and 64 bit integer data types.    *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       February 27, 2021                                             *
 ******************************************************************************/

/*  Function prototype and IEEE754_Word64 data type defined here.             */
#include "ieee754.h"

/*  Function for extracting the exponent value of a 64-bit double.            */
int32 Get_Base_2_Exp64(IEEE754_Word64 w)
{
    /*  We need to set the signed bit of the float to zero since we don't     *
     *  need this information. The signed bit is the zeroth bit, so we just   *
     *  need to use a bitwise AND with the hexidecimal number                 *
     *  0x7FFFFFFFFFFFFFFF. 0x7FFFFFFFFFFFFFFF is the hexidecimal number      *
     *  representing 0 in the zeroth bit and 1 in the next 63 bits. Using     *
     *  bitwise AND with this number simply zeroes out the zeroth bit. We     *
     *  then need to extract the high word, which is the last 10 bits. To do  *
     *  this, we bit-shift to the right using the >> operator, bit-shifting   *
     *  52 bits. The bitwise AND is performed via the & operator.             */
    const uint64 highword = (0x7FFFFFFFFFFFFFFFU & w.integer) >> 52;

    /*  The IEEE 754 format specifies that the exponent value of a 64-bit     *
     *  floating point number is the high word minus 1023 (which is 2^10 - 1).*
     *  The high word is an unsigned (non-negative) integer. Subtracting 1023 *
     *  from the high word allows for negative exponents, which is useful for *
     *  fractional values like 0.5.                                           */
    return (int32)highword - 1023;
}
/*  End of Get_Base_2_Exp64.                                                  */
