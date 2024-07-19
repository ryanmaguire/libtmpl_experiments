#include <stdio.h>
#include <math.h>
#include <libtmpl/include/tmpl_math.h>

int main(void)
{
	unsigned int n;
	long double max = 0.0L;

	for (n = 0U; n < 1757U; ++n)
	{
		const long double y0 = tmpl_LDouble_Falling_Factorial(n, 6U);
		const long double factor = tgammal(n - 5U);
		const long double y1 = tgammal(n + 1U) / factor;
		const long double err = tmpl_LDouble_Abs((y0 - y1) / y1);

		if (err > max)
			max = err;

		if (n < 20U)
			printf("%Le %Le\n", y0, y1);
	}

	printf("%Le\n", max);
	return 0;
}
