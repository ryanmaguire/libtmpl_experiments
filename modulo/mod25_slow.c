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
 *                                 mod25_slow                                 *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod25_slow                                                            *
 *  Purpose:                                                                  *
 *      Computes mod 25 of an integer the slow way.                           *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 25 value of.              *
 *  Output:                                                                   *
 *      n_mod_25 (unsigned int):                                              *
 *          The input integer reduced mod 25.                                 *
 *  Method:                                                                   *
 *      Subtract all integers of the form 25 * 2^k away from n until the      *
 *      result is less than 25.                                               *
 *  Notes:                                                                    *
 *      This function assumes int is no wider than 32-bits. This is almost    *
 *      always the case.                                                      *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 25 of an integer using the by-hand method.     */
unsigned int mod25_slow(unsigned int n)
{
    /*  This is the largest integer of the form 25 * 2^k that does not go     *
     *  beyond the width of 32-bit unsigned integers.                         */
    unsigned int pow_2_times_25 = 3355443200U;

    /*  Loop through all integers of the form 25 * 2^k that are less than     *
     *  2^32. If the value 25 * 2^k is less than n, subtract it away from n.  *
     *  Keep doing this until n is less than 25. The result is n mod 25.      */
    while (n >= 25U)
    {
        /*  If n is larger, subtract the current power away from it. Since    *
         *  this is a multiple of 25 (it is 2^k * 25 for some k), we have     *
         *  pow_2_times_25 mod 25 = 0. Hence n - pow_2_times_25 is congruent  *
         *  to n mod 25.                                                      */
        if (n >= pow_2_times_25)
            n -= pow_2_times_25;

        /*  Shift down to the next power of 2.                                */
        pow_2_times_25 = pow_2_times_25 >> 1U;
    }

    return n;
}
/*  End of mod25_slow.                                                        */
