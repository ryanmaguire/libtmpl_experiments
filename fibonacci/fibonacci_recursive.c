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
 *                             fibonacci_recursive                            *
 ******************************************************************************
 *  Function:                                                                 *
 *      fibonacci_recursive                                                   *
 *  Purpose:                                                                  *
 *      Computes the nth Fibonacci number using the recursion formula.        *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the position in the Fibonacci sequence.               *
 *  Output:                                                                   *
 *      F_n (unsigned int):                                                   *
 *          The nth Fibonacci number.                                         *
 *  Method:                                                                   *
 *      The definition yields a recursion relation:                           *
 *                                                                            *
 *          F(n) = F(n-2) + F(n-1)                                            *
 *          F(0) = 0                                                          *
 *          F(1) = 1                                                          *
 *                                                                            *
 *      This runs in O(2^n). The other methods are O(n). Only use this        *
 *      function if you are very bored and enjoy watching the terminal screen.*
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype is provided here.                                      */
#include "fibonacci.h"

/*  Computes the Fibonacci numbers via a recursion relation.                  */
unsigned int fibonacci_recursive(unsigned int n)
{
    if (n < 2U)
        return n;

    return fibonacci_recursive(n - 1U) + fibonacci_recursive(n - 2U);
}
/*  End of fibonacci_recursive.                                               */
