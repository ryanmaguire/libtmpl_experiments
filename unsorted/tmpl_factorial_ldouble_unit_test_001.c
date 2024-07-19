#include <stdio.h>
#include <math.h>
#include <libtmpl/include/tmpl_math.h>

int main(void)
{
	unsigned int n;
	long double max = 0.0L;

	for (n = 1588; n < 1757U; ++n)
	{
		const long double y0 = tmpl_LDouble_Factorial(n);
		const long double y1 = tgammal(n+1U);
		const long double err = tmpl_LDouble_Abs((y0 - y1) / y1);

		if (err > max)
			max = err;
	}

	printf("%Le\n", max);
	return 0;
}
