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
 *                                 mod4_slow                                  *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod4_slow                                                             *
 *  Purpose:                                                                  *
 *      Computes mod 4 of an integer the slow way.                            *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 4 value of.               *
 *  Output:                                                                   *
 *      n_mod_4 (unsigned int):                                               *
 *          The input integer reduced mod 4.                                  *
 *  Method:                                                                   *
 *      Subtract all integers of the form 4 * 2^k away from n until the       *
 *      result is less than 4.                                                *
 *  Notes:                                                                    *
 *      This function assumes int is no wider than 32-bits. This is almost    *
 *      always the case.                                                      *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       January 10, 2024                                              *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 4 of an integer using the by-hand method.      */
unsigned int mod4_slow(unsigned int n)
{
    /*  This is the largest integer of the form 4 * 2^k that does not go      *
     *  beyond the width of 32-bit unsigned integers.                         */
    unsigned int pow_2_times_4 = 2147483648U;

    /*  Loop through all integers of the form 4 * 2^k that are less than      *
     *  2^32. If the value 4 * 2^k is less than n, subtract it away from n.   *
     *  Keep doing this until n is less than 4. The result is n mod 4.        */
    while (n >= 4U)
    {
        /*  If n is larger, subtract the current power away from it. Since    *
         *  this is a multiple of 4 (it is 2^k * 4 for some k), we have       *
         *  pow_2_times_4 mod 4 = 0. Hence n - pow_2_times_4 is congruent     *
         *  to n mod 4.                                                       */
        if (n >= pow_2_times_4)
            n -= pow_2_times_4;

        /*  Shift down to the next power of 2.                                */
        pow_2_times_4 = pow_2_times_4 >> 1U;
    }

    return n;
}
/*  End of mod4_slow.                                                         */
