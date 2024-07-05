/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  This file is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this file.  If not, see <https://www.gnu.org/licenses/>.       *
 ******************************************************************************
 *                                    mod4                                    *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod4                                                                  *
 *  Purpose:                                                                  *
 *      Computes mod 4 of an integer.                                         *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 4 value of.               *
 *  Output:                                                                   *
 *      n_mod_4 (unsigned int):                                               *
 *          The input integer reduced mod 4.                                  *
 *  Method:                                                                   *
 *      Use the Hacker's delight method for mod 4. The magic numbers are all  *
 *      powers of 2 since 4 itself is a power of 2.                           *
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

/*  Function for computing mod 4 using the Hacker's Delight method.           */
unsigned int mod4(unsigned int n)
{
    /*  The magic number, 2^36 / 4 = 2^34.                                    */
    const unsigned long long int scale = 17179869184ULL;

    /*  Cast the input to long long to avoid overflow.                        */
    const unsigned long long int n_long = (unsigned long long int)n;

    /*  Compute integer division by multiplying and bit shifting.             */
    const unsigned int div4 = (unsigned int)((n_long * scale) >> 36U);

    /*  We now have div4 = n / 4. Subtract 4 times this number from n.        */
    return n - div4 * 4U;
}
/*  End of mod4.                                                              */
