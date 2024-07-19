/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of libtmpl_experiments.                                 *
 *                                                                            *
 *  libtmpl_experiments is free software: you can redistribute it and/or      *
 *  modify it under the terms of the GNU General Public License as published  *
 *  by the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl_experiments is distributed in the hope that it will be useful,    *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License along   *
 *  with libtmpl_experiments.  If not, see <https://www.gnu.org/licenses/>.   *
 ******************************************************************************/
#include "fresnel_cos.h"

/*  Coefficients for the numerator of the Remez approximation.                */
#define A00 (+4.4526117603982156032388213107819550206967391804909E-01F)
#define A01 (-8.3334036635901973518937405375160182044773289377646E-01F)
#define A02 (+8.4680412959869615893531389091680676074316604983320E-01F)
#define A03 (-7.6123922740958624836670244181323989592075146496563E-02F)
#define A04 (-1.2329212255377990265474880986608857659521484751018E-01F)
#define A05 (-6.0419030994089509939221381955663145429720111357372E-03F)
#define A06 (+6.3132885525905539585998858867894754758876598044245E-03F)
#define A07 (+4.1880362893435900858175201483539479578650853711670E-03F)
#define A08 (+1.2735844601517730536091375285283813866952304063988E-04F)
#define A09 (-1.0363668586827811325817191194258638318759494527212E-04F)
#define A10 (-5.7209791023008541265407044839774561538525836583206E-05F)
#define A11 (-5.3016542893325400435166607759232989057855198119143E-06F)

/*  Coefficients for the denominator of the Remez approximation.              */
#define B00 (+1.0000000000000000000000000000000000000000000000000E+00F)
#define B01 (-8.3411853556744023822991522756879607000668461497415E-01F)
#define B02 (+5.3018873471562757054137585476681082560286697072935E-01F)
#define B03 (-2.1481875670377854908120720782945360305401677743313E-01F)
#define B04 (+7.3673369414656135887761136955830344618585351140663E-02F)
#define B05 (-1.8192494909601028737426644514868084145515615613161E-02F)
#define B06 (+3.8870441306395275979695981918514969410855225997572E-03F)
#define B07 (-5.3226383933882880044864189913187136221912710182617E-04F)
#define B08 (+6.1773735926767966038143092918830436707063385629880E-05F)

/*  Helper macro for evaluating the numerator via Horner's method.            */
#define TMPL_NUM_EVAL(z) \
A00 + z*(\
  A01 + z*(\
    A02 + z*(\
      A03 + z*(\
        A04 + z*(\
          A05 + z*(\
            A06 + z*(\
              A07 + z*(\
                A08 + z*(\
                  A09 + z*(\
                    A10 + z*A11\
                  )\
                )\
              )\
            )\
          )\
        )\
      )\
    )\
  )\
)

/*  Helper macro for evaluating the denominator via Horner's method.          */
#define TMPL_DEN_EVAL(z) \
B00+z*(B01+z*(B02+z*(B03+z*(B04+z*(B05+z*(B06+z*(B07+z*B08)))))))

/*  Computes the normalized Fresnel cosine using a rational Remez expansion.  */
float Fresnel_Cos_Float_Rat_Remez(float x)
{
    const float t = 2.0F * (x - 1.5F);
    const float num = TMPL_NUM_EVAL(t);
    const float den = TMPL_DEN_EVAL(t);
    return num / den;
}
/*  End of Fresnel_Cos_Float_Rat_Remez.                                       */
