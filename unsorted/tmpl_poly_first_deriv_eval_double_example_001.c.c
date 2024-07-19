#include <stdio.h>
#include <libtmpl/include/tmpl_math.h>

int main(void)
{
	const double coeffs[4] = {1.0, 2.0, 3.0, 4.0};
	const size_t deg = sizeof(coeffs) / sizeof(coeffs[0]) - 1;
	const double x = 6.0;
	const double dp = tmpl_Double_Poly_First_Deriv_Eval(coeffs, deg, x);

	printf("%e\n", dp);
	return 0;
}
