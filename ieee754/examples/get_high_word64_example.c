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

/*  Function for testing the Get_High_Word64 function.                        */
int main(void)
{
    /*  Declare variables for the high words.                                 */
    uint32 b0, b1, b2, b3;

    /*  And declare variables for the IEEE 754 double union.                  */
    IEEE754_Word64 w0, w1, w2, w3;

    /*  Set the double part of the IEEE 754 union to various values.          */
    w0.real = 8.0;
    w1.real = 3.333333333;
    w2.real = 0.5;
    w3.real = 0.3333333333;

    /*  Extract the high words from the floating point numbers.               */
    b0 = Get_High_Word64(w0);
    b1 = Get_High_Word64(w1);
    b2 = Get_High_Word64(w2);
    b3 = Get_High_Word64(w3);

    /*  Print the results.                                                    */
    printf("High Word of %f: %u\n", w0.real, b0);
    printf("High Word of %f: %u\n", w1.real, b1);
    printf("High Word of %f: %u\n", w2.real, b2);
    printf("High Word of %f: %u\n", w3.real, b3);

    return 0;
}
/*  End of main.                                                              */
