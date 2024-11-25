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
 ******************************************************************************/
#include <libtmpl/include/tmpl_floatint.h>
#include <libtmpl/include/tmpl_ieee754_double.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static inline double FloatInt_Split(double x)
{
    tmpl_IEEE754_FloatInt64 word64;
    word64.f = x;
    word64.n &= 0xFFFFFFFFFC000000U;
    return word64.f;
}

static inline double IEEE754_Split(double x)
{
    tmpl_IEEE754_Double w;
    w.r = x;

    w.bits.man3 = 0x0000U;
    w.bits.man2 &= 0xFC00U;
    return w.r;
}

static inline double Portable_Split(double x)
{
    const double split = x * 134217729.0;
    return split - (split - x);
}

int main(void)
{
    const size_t len = (size_t)(1E8);
    double * restrict const x = malloc(sizeof(*x) * len);
    double * restrict const y0 = malloc(sizeof(*y0) * len);
    double * restrict const y1 = malloc(sizeof(*y1) * len);
    double * restrict const y2 = malloc(sizeof(*y2) * len);
    const double start = -1.0;
    const double end = 1.0;
    const double dx = (end - start) / (double)len;
    double err0, err1, tmp;
    clock_t t0, t1;
    size_t n, ind0, ind1;
    tmpl_IEEE754_FloatInt64 out;

    for (n = 0; n < len; ++n)
        x[n] = start + dx * (double)n;

    t0 = clock();
    for (n = 0; n < len; ++n)
        y0[n] = FloatInt_Split(x[n]);
    t1 = clock();
    printf("FloatInt Time: %E\n", (double)(t1 - t0) / CLOCKS_PER_SEC);


    t0 = clock();
    for (n = 0; n < len; ++n)
        y1[n] = IEEE754_Split(x[n]);
    t1 = clock();
    printf("IEEE753 Time:  %E\n", (double)(t1 - t0) / CLOCKS_PER_SEC);


    t0 = clock();
    for (n = 0; n < len; ++n)
        y2[n] = Portable_Split(x[n]);
    t1 = clock();
    printf("Portable Time: %E\n", (double)(t1 - t0) / CLOCKS_PER_SEC);

    err0 = 0.0;
    err1 = 0.0;
    ind0 = 0;
    ind1 = 1;

    for (n = 0; n < len; ++n)
    {
        tmp = fabs((y0[n] - y2[n]) / y2[n]);
        if (tmp > err0)
        {
            ind0 = n;
            err0 = tmp;
        }

        tmp = fabs((y1[n] - y2[n]) / y2[n]);
        if (tmp > err1)
        {
            ind1 = n;
            err1 = tmp;
        }
    }

    printf("FloatInt Error:\n");
    printf("    error  = %+.18E\n", err0);
    printf("    x      = %+.18E\n", x[ind0]);
    printf("    y0     = %+.18E\n", y0[ind0]);
    printf("    y2     = %+.18E\n", y2[ind0]);
    printf("    lo     = %+.18E\n", x[ind0] - y0[ind0]);
    printf("    actual = %+.18E\n", x[ind0] - y2[ind0]);
    printf("IEEE754:\n");
    printf("    error  = %+.18E\n", err1);
    printf("    x      = %+.18E\n", x[ind1]);
    printf("    y1     = %+.18E\n", y0[ind1]);
    printf("    y2     = %+.18E\n", y2[ind1]);
    printf("    lo     = %+.18E\n", x[ind1] - y1[ind1]);
    printf("    actual = %+.18E\n", x[ind1] - y2[ind1]);
    out.f = y0[ind0];
    printf("Hex (y0): %#016lx\n", out.n);
    out.f = y2[ind0];
    printf("Hex (y2): %#016lx\n", out.n);
    free(x);
    free(y0);
    free(y1);
    free(y2);
    return 0;
}
