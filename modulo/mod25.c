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
 *                                    mod25                                   *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod25                                                                 *
 *  Purpose:                                                                  *
 *      Computes mod 25 of an integer the fast way.                           *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 25 value of.              *
 *  Output:                                                                   *
 *      n_mod_25 (unsigned int):                                              *
 *          The input integer reduced mod 25.                                 *
 *  Method:                                                                   *
 *      Use the magic number 2748779070, which is the ceiling of 2^36 / 25.   *
 *      By multiplying n by this, and then shifting 36 bits down, we will     *
 *      have efficiently computed integer division for n / 25. By subtracting *
 *      25 times this value from the input we will have n mod 25.             *
 *  Notes:                                                                    *
 *      This function assumes unsigned long long support is available and     *
 *      that int and long long are 32 and 64 bits, respectively.              *
 *                                                                            *
 *      This method is outlined in the book "Hacker's Delight."               *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 25 of an integer using the fast method.        */
unsigned int mod25(unsigned int n)
{
    /*  The magic number, equal to the ceiling of 2^36 / 25.                  */
    const unsigned long long int scale = 2748779070ULL;

    /*  Cast the input to long long to avoid overflow.                        */
    const unsigned long long int n_long = (unsigned long long int)n;

    /*  Compute n * scale / 2^36. This is the integer division of n / 25.     */
    const unsigned int div25 = (unsigned int)((n_long * scale) >> 36U);

    /*  div25 is now n / 25. Subtract 25 times this value from n.             */
    return n - div25 * 25U;
}
/*  End of mod25.                                                             */
