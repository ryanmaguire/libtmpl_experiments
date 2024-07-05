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
 *  Function:                                                                 *
 *      fibonacci_iterative                                                   *
 *  Purpose:                                                                  *
 *      Computes the nth Fibonacci number by iteratively summing.             *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the position in the Fibonacci sequence.               *
 *  Output:                                                                   *
 *      F_n (unsigned int):                                                   *
 *          The nth Fibonacci number.                                         *
 *  Method:                                                                   *
 *      Use F_n = F_{n-1} + F_{n-2} to perform the sum iteratively. This will *
 *      run in O(n) time.                                                     *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype is provided here.                                      */
#include "fibonacci.h"

/*  Computes the nth Fibonacci number using an iterative sum.                 */
unsigned int fibonacci_iterative(unsigned int n)
{
    /*  Variable for the n-2 entry in the sequence.                           */
    unsigned int F_n_minus_2 = 1;

    /*  And a variable for the n-1 entry.                                     */
    unsigned int F_n_minus_1 = 1;

    /*  The output, the nth entry in the Fibonacci sequence.                  */
    unsigned int F_n = 1;

    /*  Dummy variable for indexing over the sum.                             */
    unsigned int ind;

    /*  For n < 2 we have F_n = n. Nothing to do, return n.                   */
    if (n < 2U)
        return n;

    /*  Otherwise, start from F_2 and sum until we get to F_n.                */
    for (ind = 2U; ind < n; ++ind)
    {
        /*  Perform the Fibonacci sum.                                        */
        F_n = F_n_minus_1 + F_n_minus_2;

        /*  Reset the previous two entries to their new values.               */
        F_n_minus_2 = F_n_minus_1;
        F_n_minus_1 = F_n;

    }

    return F_n;
}
/*  End of fibonacci_iterative.                                               */
