#include <libtmpl/include/tmpl.h>
#include <stdio.h>

static tmpl_ComplexDouble f(tmpl_ComplexDouble z)
{
	tmpl_ComplexDouble z2 = tmpl_CDouble_Multiply(z, z);
	tmpl_ComplexDouble z3 = tmpl_CDouble_Multiply(z2, z);
	z3.dat[0] -= 1.0;
	return z3;
}

static tmpl_ComplexDouble fp(tmpl_ComplexDouble z)
{
        tmpl_ComplexDouble z2 = tmpl_CDouble_Multiply(z, z);
        z2.dat[0] *= 3.0;
        z2.dat[1] *= 3.0;
        return z2;
}

static tmpl_ComplexDouble fpp(tmpl_ComplexDouble z)
{
        return tmpl_CDouble_Multiply_Real(6.0, z);
}

int main(void)
{
	tmpl_ComplexDouble z = tmpl_CDouble_Rect(6.0E4, 1.0E4);
	tmpl_ComplexDouble w = tmpl_CDouble_Halleys_Method_Explicit_With_Vars(z, f, fp, fpp, 32, 1.0E-15);
	printf("%f + i%f\n", w.dat[0], w.dat[1]);
	return 0;
}
