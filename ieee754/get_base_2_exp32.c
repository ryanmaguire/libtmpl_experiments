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
 *                              get_base_2_exp32                              *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Computes the exponent part of a 32-bit floating point value that is   *
 *      represented using the IEEE 754 single precision format. That is,      *
 *      given a floating point number x = 1.m * 2^b, this function returns    *
 *      b. The value 1.m is called the mantissa.                              *
 ******************************************************************************
 *                             DEFINED FUNCTIONS                              *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Get's the base-2 exponent of a 32-bit floating point number.          *
 *  Arguments:                                                                *
 *      w (IEEE754_Word32).                                                   *
 *          A union representing a 32-bit floating point value in binary.     *
 *  Output:                                                                   *
 *      exp (int32):                                                          *
 *          A 32-bit signed integer corresponding to the exponent of          *
 *          the input.                                                        *
 *  Method:                                                                   *
 *      Extract the high word of the floating point number and subtract 127   *
 *      from this, as specified in the IEEE 754 format.                       *
 ******************************************************************************
 *                               DEPENDENCIES                                 *
 ******************************************************************************
 *  1.) ieee754.h:                                                            *
 *          Header file that contains union data types for working with       *
 *          floating point numbers using 32 and 64 bit integer data types.    *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       February 27, 2021                                             *
 ******************************************************************************/

/*  Function prototype and IEEE754_Word32 data type defined here.             */
#include "ieee754.h"

/*  Function for extracting the exponent value of a 32-bit float.             */
int32 Get_Base_2_Exp32(IEEE754_Word32 w)
{
    /*  We need to set the signed bit of the float to zero since we don't     *
     *  need this information. The signed bit is the zeroth bit, so we just   *
     *  need to use a bitwise AND with the hexidecimal number 0x7FFFFFFF.     *
     *  0x7FFFFFFF is the hexidecimal number representing 0 in the zeroth bit *
     *  and 1 in the next 31 bits. Using bitwise AND with this number simply  *
     *  zeroes out the zeroth bit. We then need to extract the high word,     *
     *  which is the last 9 bits. To do this, we bit-shift to the right using *
     *  the >> operator, bit-shifting 23 bits. The bitwise AND is performed   *
     *  via the & operator.                                                   */
    const uint32 highword = (0x7FFFFFFFU & w.integer) >> 23;

    /*  The IEEE 754 format specifies that the exponent value of a 32-bit     *
     *  floating point number is the high word minus 127 (which is 2^7 - 1).  *
     *  The high word is an unsigned (non-negative) integer. Subtracting 127  *
     *  from the high word allows for negative exponents, which is useful for *
     *  fractional values like 0.5.                                           */
    return (int32)highword - 127;
}
/*  End of Get_Base_2_Exp32.                                                  */
