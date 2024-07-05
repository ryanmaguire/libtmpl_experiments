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
 *                                 mod4_shift                                 *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod4_shift                                                            *
 *  Purpose:                                                                  *
 *      Computes mod 4 of an integer.                                         *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 4 value of.               *
 *  Output:                                                                   *
 *      n_mod_4 (unsigned int):                                               *
 *          The input integer reduced mod 4.                                  *
 *  Method:                                                                   *
 *      Use bit-shifting to compute multiplication and division. By shifting  *
 *      the input two slots to the right, and then multiplying by 4, we will  *
 *      zero out the first two bits on the number. Subtracting this value     *
 *      from the input leaves only the last two bits of the input, which is   *
 *      the equivalent of n mod 4.                                            *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 10, 2024                                              *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 4 using the shift method.                      */
unsigned int mod4_shift(unsigned int n)
{
    /*  We can compute n / 4 by bit shifting twice to the right.              */
    const unsigned int shift = n >> 2U;

    /*  Subtracting 4 times this number from the input yields n mod 4.        */
    return n - (shift << 2U);
}
/*  End of mod4_shift.                                                        */
