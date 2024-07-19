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
 *  Date:       April 5, 2021                                                 *
 ******************************************************************************/
#include <stdio.h>
#include "../ieee754.h"

/*  Function for testing the Get_Mantissa32 function.                         */
int main(void)
{
    /*  Declare variables for the mantissa.                                   */
    float y0, y1, y2, y3;

    /*  And declare variables for the IEEE 754 float union.                   */
    IEEE754_Word32 w0, w1, w2, w3;

    /*  Set the float part of the IEEE 754 union to various values.           */
    w0.real = 8.0F;
    w1.real = 3.333333333F;
    w2.real = 0.5F;
    w3.real = 0.3333333333F;

    /*  Extract the mantissa from the floating point numbers.                 */
    y0 = Get_Mantissa32(w0);
    y1 = Get_Mantissa32(w1);
    y2 = Get_Mantissa32(w2);
    y3 = Get_Mantissa32(w3);

    /*  Print the results.                                                    */
    printf("Mantissa of %f: %f\n", (double)w0.real, (double)y0);
    printf("Mantissa of %f: %f\n", (double)w1.real, (double)y1);
    printf("Mantissa of %f: %f\n", (double)w2.real, (double)y2);
    printf("Mantissa of %f: %f\n", (double)w3.real, (double)y3);

    return 0;
}
/*  End of main.                                                              */

