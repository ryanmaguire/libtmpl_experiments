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
 *                             fibonacci_power_law                            *
 ******************************************************************************
 *  Function:                                                                 *
 *      fibonacci_power_law                                                   *
 *  Purpose:                                                                  *
 *      Computes the nth Fibonacci number using the power law.                *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the position in the Fibonacci sequence.               *
 *  Output:                                                                   *
 *      F_n (unsigned int):                                                   *
 *          The nth Fibonacci number.                                         *
 *  Method:                                                                   *
 *      The difference equation F_n = F_{n-1} + F_{n-2} can be solved by a    *
 *      power law. We note that it is linear, and propose a solution          *
 *      F_n = a * b^n. We have:                                               *
 *                                                                            *
 *              F_n = F_{n-1} + F_{n-2}                                       *
 *          a * b^n = a * b^{n-1} + a * b^{n-2}                               *
 *              b^2 = b + 1                                                   *
 *                b = (1 +/- sqrt(5)) / 2                                     *
 *                                                                            *
 *      So a linear combination of the positive and negative golden ratios.   *
 *      Let's get the coefficients.                                           *
 *                                                                            *
 *          0 = F_0                                                           *
 *            = a_{+} + a_{-}                                                 *
 *                                                                            *
 *          1 = a_{+}*phi_{+} + a_{-}*phi_{-}                                 *
 *                                                                            *
 *      We get:                                                               *
 *                                                                            *
 *          a_{+} =  1 / (phi_{+} - phi_{-}) =  1 / sqrt(5)                   *
 *          a_{-} = -1 / (phi_{+} - phi_{-}) = -1 / sqrt(5)                   *
 *                                                                            *
 *      Numerically this is +/- 0.447213595499...                             *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype is provided here.                                      */
#include "fibonacci.h"

/*  Power and rounding routines found here.                                   */
#include <math.h>

/*  Computes the nth Fibonacci number using the power law.                    */
unsigned int fibonacci_power_law(unsigned int n)
{
    /*  The positive and negative golden ratios. These are the solutions to   *
     *  x^2 - x - 1 = 0. The solutions are (1 +/- sqrt(5)) / 2.               */
    const long double phi_minus = -0.6180339887498948482045870L;
    const long double phi_plus = 1.6180339887498948482045870L;

    /*  Scale factors from the difference equation.                           */
    const long double scale_minus = -4.47213595499957939281834733746255247E-01L;
    const long double scale_plus = 4.47213595499957939281834733746255247E-01L;

    /*  Values for phi_plus and phi_minus raised to the nth power.            */
    const long double fib_minus = powl(phi_minus, n);
    const long double fib_plus = powl(phi_plus, n);

    /*  The real-valued fibonacci number. It will have some error in it due   *
     *  to floating point round off. We will need to correct for this.        */
    const long double fib = roundl(fib_minus*scale_minus + fib_plus*scale_plus);

    /*  Cast to an integer and return.                                        */
    return (unsigned int)fib;
}
/*  End of fibonacci_power_law.                                               */
