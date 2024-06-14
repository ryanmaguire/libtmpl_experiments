#include"fresnel_cos.h"

long double Fresnel_Cos_LDouble_Auxiliary_Safe_Less_Coeffs(long double x)
{
    const double z = (double)x;
    const double Cz = Fresnel_Cos_Double_Auxiliary_Safe_Less_Coeffs(z);
    return (long double)Cz;
}
