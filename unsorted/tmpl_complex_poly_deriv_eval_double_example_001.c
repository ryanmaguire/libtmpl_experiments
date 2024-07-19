#include <stdio.h>
#include <libtmpl/include/tmpl_complex.h>

int main(void)
{
    const tmpl_ComplexDouble coeffs[5] = {
        {{1.0, 1.0}}, {{0.0, 2.0}}, {{-3.0, 0.0}}, {{0.5, 0.25}}, {{3.0, 2.0}}
    };
    const tmpl_ComplexDouble z = tmpl_CDouble_Rect(1.0, 1.0);
    const size_t deg = 4;

    const tmpl_ComplexDouble w = tmpl_CDouble_Poly_Deriv_Eval(coeffs, deg, 3, z);

    printf("%e + i%e\n", w.dat[0], w.dat[1]);
    return 0;
}
