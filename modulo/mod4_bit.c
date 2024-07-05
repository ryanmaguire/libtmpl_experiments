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
 *                                  mod4_bit                                  *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod4_bit                                                              *
 *  Purpose:                                                                  *
 *      Computes mod 4 of an integer.                                         *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 4 value of.               *
 *  Output:                                                                   *
 *      n_mod_4 (unsigned int):                                               *
 *          The input integer reduced mod 4.                                  *
 *  Method:                                                                   *
 *      Use bit-wise and to zero out all but the last two bits. This is the   *
 *      input value mod 4.                                                    *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 4 using the bitwise and method.                */
unsigned int mod4_bit(unsigned int n)
{
    /*  We want to perform bit-wise and with 11_2, written in binary, which   *
     *  is just "3". This is 0x03 in hexidecimal.                             */
    return n & 0x03U;
}
/*  End of mod4_bit.                                                          */
