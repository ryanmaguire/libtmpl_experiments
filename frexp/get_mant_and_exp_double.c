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
 *  Purpose:                                                                  *
 *      Experimental, portable, method of retrieving the scientific notation  *
 *      of a real number. Very slow since it doesn't use IEEE-754 tricks.     *
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <float.h>

/*  The powers 2^(2^(n+1)) for n = 0, ..., 8.                                 */
static const double vals[9] = {
    4.00000000000000000E+00,
    1.60000000000000000E+01,
    2.56000000000000000E+02,
    6.55360000000000000E+04,
    4.29496729600000000E+09,
    1.84467440737095516E+19,
    3.40282366920938463E+38,
    1.15792089237316195E+77,
    1.34078079299425971E+154
};

/*  Gets a number x into scientific notation, |x| = mant * 2^expo.            */
static void get_mant_and_exp(double x, double *mant, signed int *expo)
{
    const double abs_x = (x > 0.0 ? x : -x);
    unsigned int n;

    if (abs_x == 0.0)
    {
        *mant = 0.0;
        *expo = 0;
        return;
    }

    *mant = (abs_x > 1.0 ? abs_x : 1.0 / abs_x);
    *expo = 0;

    for (n = 0U; n < 9U; ++n)
    {
        while (*mant > vals[n])
        {
            *mant /= vals[n];
            *expo += 2 << n;
        }
    }

    while (*mant > 1.0)
    {
        *mant *= 0.5;
        *expo += 1;
    }

    if (abs_x < 1.0)
    {
        *expo = -*expo - 1;
        *mant = 2.0 / *mant;
    }

    if (x < 0.0)
        *mant = -*mant;
}

/*  Test this function against standard library tools.                        */
int main(void)
{
    signed int expo;
    double mant, y, tmp;
    unsigned long int n;
    const unsigned long int N = 1E7;
    const double dx = 0.5*DBL_MAX / (double)N;
    double x = 0.0;
    double err = 0.0;

    for (n = 0U; n < N; ++n)
    {
        get_mant_and_exp(x, &mant, &expo);
        y = mant * pow(2.0, expo);
        tmp = fabs((y - x) / x);

        if (err < tmp)
            err = tmp;

        x += dx;

    }

    printf("Max Relative Error: %E\n", err);
    return 0;
}
