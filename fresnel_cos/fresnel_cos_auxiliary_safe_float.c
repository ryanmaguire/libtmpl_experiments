#include"fresnel_cos.h"

float Fresnel_Cos_Float_Auxiliary_Safe(float x)
{
    const double z = (double)x;
    const double Cz = Fresnel_Cos_Double_Auxiliary_Safe(z);
    return (float)Cz;
}
