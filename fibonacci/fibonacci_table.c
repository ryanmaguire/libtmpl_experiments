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
 *                               fibonacci_table                              *
 ******************************************************************************
 *  Function:                                                                 *
 *      fibonacci_table                                                       *
 *  Purpose:                                                                  *
 *      Computes the nth Fibonacci number using a lookup-table.               *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the position in the Fibonacci sequence.               *
 *  Output:                                                                   *
 *      F_n (unsigned int):                                                   *
 *          The nth Fibonacci number.                                         *
 *  Method:                                                                   *
 *      Use a lookup table. For 32-bit integers F_n > 2^32 for n > 47.        *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype is provided here.                                      */
#include "fibonacci.h"

/*  The lookup table. F_n overflows beyond the width of 32-bit integers very  *
 *  quickly. Only need the first 48 (0 <= n <= 47) terms.                     */
static const unsigned int fib_table[48] = {
    0U,
    1U,
    1U,
    2U,
    3U,
    5U,
    8U,
    13U,
    21U,
    34U,
    55U,
    89U,
    144U,
    233U,
    377U,
    610U,
    987U,
    1597U,
    2584U,
    4181U,
    6765U,
    10946U,
    17711U,
    28657U,
    46368U,
    75025U,
    121393U,
    196418U,
    317811U,
    514229U,
    832040U,
    1346269U,
    2178309U,
    3524578U,
    5702887U,
    9227465U,
    14930352U,
    24157817U,
    39088169U,
    63245986U,
    102334155U,
    165580141U,
    267914296U,
    433494437U,
    701408733U,
    1134903170U,
    1836311903U,
    2971215073U
};

/*  Compute the nth Fibonacci number using a lookup table.                    */
unsigned int fibonacci_table(unsigned int n)
{
    /*  For large n, return 0. This somewhat signals an error. The only other *
     *  Fibonacci number to return zero is zero, and many exclude zero from   *
     *  the Fibonacci sequence.                                               */
    if (n >= 48U)
        return 0U;

    /*  For legal inputs use the lookup table defined above.                  */
    return fib_table[n];
}
/*  End of fibonacci_table.                                                   */
