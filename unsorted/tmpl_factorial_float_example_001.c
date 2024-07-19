#include <stdio.h>
#include <libtmpl/include/tmpl_math.h>

int main(void)
{
    FILE * fp = fopen("ah.txt", "w");
    unsigned int n;
    for (n = 0U; n < 34U; ++n)
        fprintf(fp, "%.24e\n", tmpl_Float_Factorial(n));

    fclose(fp);
    return 0;
}
