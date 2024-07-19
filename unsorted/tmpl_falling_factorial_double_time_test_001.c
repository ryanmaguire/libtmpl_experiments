#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <libtmpl/include/tmpl_math.h>

static double fall(unsigned int n, unsigned int m)
{
    if (m > n)
        return 0.0;

    return tgamma(n + 1U) / tgamma((n - m) + 1U);
}

int main(void)
{
    clock_t tstart, tend;
    const unsigned int N = (unsigned int)(1E3);
    const unsigned int M = (unsigned int)(1E3);
    double * const y0 = malloc(sizeof(*y0) * M);
    double * const y1 = malloc(sizeof(*y1) * M);
    unsigned int m, n;
    double tmp, t0, t1, tdiff;
    double max = 0.0;
    FILE * const fp = fopen("data.txt", "w");

    for (n = 0U; n < N; ++n)
    {
        tstart = clock();
        for (m = 0U; m < M; ++m)
            y0[m] = tmpl_Double_Falling_Factorial(n, m);
        tend = clock();

        t0 = (double)(tend - tstart) / CLOCKS_PER_SEC;

        tstart = clock();
        for (m = 0U; m < M; ++m)
            y1[m] = fall(n, m);
        tend = clock();

        t1 = (double)(tend - tstart) / CLOCKS_PER_SEC;
        tdiff = t1 - t0;

        for (m = 0U; m < M; ++m)
        {
            tmp = fabs(y0[m] - y1[m]) / y1[m];

            if (tmp > max)
                max = tmp;
        }

        fprintf(fp, "%e\n", tdiff);
    }

    free(y0);
    free(y1);
    printf("%e\n", max);
    return 0;
}
