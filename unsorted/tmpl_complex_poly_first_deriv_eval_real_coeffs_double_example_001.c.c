#include <stdio.h>
#include <libtmpl/include/tmpl_complex.h>

int main(void)
{
	const double coeffs[4] = {1.0, 2.0, 3.0, 4.0};
	const size_t deg = sizeof(coeffs) / sizeof(coeffs[0]) - 1;
	const tmpl_ComplexDouble z = tmpl_CDouble_Rect(1.0, 1.0);
	const tmpl_ComplexDouble dp = tmpl_CDouble_Poly_First_Deriv_Eval_Real_Coeffs(coeffs, deg, z);

	printf("%e + i%f\n", dp.dat[0], dp.dat[1]);
	return 0;
}
