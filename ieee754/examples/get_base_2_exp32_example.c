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
 *  Author:     Ryan Maguire                                                  *
 *  Date:       March 31, 2021                                                *
 ******************************************************************************/
#include <stdio.h>
#include "../ieee754.h"

/*  Function for testing the Get_Base_2_Exp32 function.                       */
int main(void)
{
    /*  Set several floating point values to test.                            */
    float x0, x1, x2, x3;

    /*  Declare variables for the exponents.                                  */
    int32 b0, b1, b2, b3;

    /*  And declare variables for the IEEE 754 float union.                   */
    IEEE754_Word32 w0, w1, w2, w3;

    /*  This is a power of two. The function should return 3.                 */
    x0 = 8.0F;

    /*  This is not a power of 2, but the function should return 1.           */
    x1 = 3.333333333F;

    /*  And a few other values.                                               */
    x2 = 0.5F;
    x3 = 0.33333333333F;

    /*  Set the float part of the IEEE 754 union to these values.             */
    w0.real = x0;
    w1.real = x1;
    w2.real = x2;
    w3.real = x3;

    /*  Extract the exponent values from the floating point numbers.          */
    b0 = Get_Base_2_Exp32(w0);
    b1 = Get_Base_2_Exp32(w1);
    b2 = Get_Base_2_Exp32(w2);
    b3 = Get_Base_2_Exp32(w3);

    /*  Print the results.                                                    */
    printf("Base 2 exponent of %f: %d\n", (double)x0, b0);
    printf("Base 2 exponent of %f: %d\n", (double)x1, b1);
    printf("Base 2 exponent of %f: %d\n", (double)x2, b2);
    printf("Base 2 exponent of %f: %d\n", (double)x3, b3);

    return 0;
}
/*  End of main.                                                              */
