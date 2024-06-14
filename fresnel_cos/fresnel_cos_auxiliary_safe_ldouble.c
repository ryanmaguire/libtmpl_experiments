#include"fresnel_cos.h"

long double Fresnel_Cos_LDouble_Auxiliary_Safe(long double x)
{
    const double z = (double)x;
    const double Cz = Fresnel_Cos_Double_Auxiliary_Safe(z);
    return (long double)Cz;
}
