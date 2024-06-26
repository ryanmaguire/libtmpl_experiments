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

/*  TMPL_LDOUBLE_TYPE macro found here.                                       */
#include <libtmpl/include/tmpl_config.h>

/*  Function prototype provided here.                                         */
#include "error_function.h"

/*  64-bit long double does not need any more precision than 64-bit double.   */
#if TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_64_BIT

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define A00 (+1.1283791670955126365607040611486440894548731064430E+00L)
#define A01 (+6.1856680806948109220677660264677907003149751444417E-02L)
#define A02 (+4.1145518213074999565262794018611561200627595655126E-02L)
#define A03 (-8.7707136933607770079319073352925173083333681109000E-04L)
#define A04 (+2.7125577380014977514418180966266226228905135708230E-04L)
#define A05 (-1.3239722107678831460532410663306244658302355190564E-05L)
#define A06 (+6.2564335958048129592868311685179924773329314231658E-07L)
#define A07 (-1.8239148907346264717934021446679328630982359872721E-08L)
#define A08 (+2.5839003238848066077920003511476230831774264021355E-10L)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define B00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define B01 (+3.8815238938359424075188631415877534713061633081189E-01L)
#define B02 (+6.5848395896534329559179312445593670161084460771079E-02L)
#define B03 (+6.1664659079696183164995589642551932095328093191702E-03L)
#define B04 (+3.2313713982428331981430572957719222195415860127493E-04L)
#define B05 (+7.7253055534510380898965062146051908309590150561640E-06L)

#define NUM_EVAL(z)\
A00+z*(A01+z*(A02+z*(A03+z*(A04+z*(A05+z*(A06+z*(A07+z*A08)))))))

#define DEN_EVAL(z) B00+z*(B01+z*(B02+z*(B03+z*(B04+z*B05))))

/*  double-double, more terms are needed.                                     */
#elif TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_DOUBLEDOUBLE || \
      TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_128_BIT

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define A00 (+1.1283791670955125738961589031215450925461937445034E+00L)
#define A01 (+1.9167553809685773590090320842736491469982132290186E-01L)
#define A02 (+6.0430270116129290485566314692192123276810942583437E-02L)
#define A03 (+5.2349408752396594611785160546430214710107182146056E-03L)
#define A04 (+6.8157644700161560605219470675111811301735830588175E-04L)
#define A05 (+3.6809637459405074974689809528622789561307343123609E-05L)
#define A06 (+2.5819892780684951650988197546541824706777328399458E-06L)
#define A07 (+9.0637781626484216357375437695628661566850235662313E-08L)
#define A08 (+3.5711426154090411220577697422034066201228889291404E-09L)
#define A09 (+7.6606077908323609985294261855033263569443815161059E-11L)
#define A10 (+1.4727195396209061813861131529033475289357638160584E-12L)
#define A11 (+1.4368673777640053659681760206830409665051904804155E-14L)
#define A12 (+4.0099201423628270409224462118525426216683603722692E-17L)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define B00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define B01 (+5.0320135614541455267710547396532579869360674475609E-01L)
#define B02 (+1.2128871787110179396387996592506591654856264576184E-01L)
#define B03 (+1.8558306375473565718630262303472210468546138864339E-02L)
#define B04 (+2.0126167776342206012873580739822615661532108354688E-03L)
#define B05 (+1.6342977897047831419027732242198902130279251886932E-04L)
#define B06 (+1.0221280919029929361034269583405622449498283669106E-05L)
#define B07 (+4.9788030615281327892591485758581555391913863431080E-07L)
#define B08 (+1.8824152040975166387148890250641629886628579191817E-08L)
#define B09 (+5.4138092093559879054959413876064527702175675028954E-10L)
#define B10 (+1.1307770492449121543261611414199506879232122192075E-11L)
#define B11 (+1.5510533383141102786900561491342341846191486585449E-13L)
#define B12 (+1.0660611242615620734576686895535117293102950380867E-15L)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define NUM_EVAL(z) \
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
                                        A10 + z*(\
                                            A11 + z*A12\
                                        )\
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

#define DEN_EVAL(z) \
B00 + z*(\
    B01 + z*(\
        B02 + z*(\
            B03 + z*(\
                B04 + z*(\
                    B05 + z*(\
                        B06 + z*(\
                            B07 + z*(\
                                B08 + z*(\
                                    B09 + z*(\
                                        B10 + z*(\
                                            B11 + z*B12\
                                        )\
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

#else

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define A00 (+1.1283791670955125739314171099502484148921208531728E+00L)
#define A01 (+1.4920278237619000520975885116068698561112023586927E-01L)
#define A02 (+5.0588484962684315204267352164775505017461778659975E-02L)
#define A03 (+2.6489483697996107296745572800020345150179790692195E-03L)
#define A04 (+3.7382085181878354886406664584462812986478153325447E-04L)
#define A05 (+6.9849093394408771121764941438879029490407386521203E-06L)
#define A06 (+5.2271592348959230742733499169922504752755806934622E-07L)
#define A07 (-2.2548217663449974511513795025550328723019126737930E-09L)
#define A08 (+4.4833375185725042453350109956947121349577136152256E-11L)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define B00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define B01 (+4.6556085642758115526601848367010609878104037398728E-01L)
#define B02 (+1.0001982963431972190942543669112576477130666430471E-01L)
#define B03 (+1.2940950747657570801136517026358823617460758702752E-02L)
#define B04 (+1.0981100562225000377092715573987637968278869464382E-03L)
#define B05 (+6.1757762759998746846404373055996794564606731333935E-05L)
#define B06 (+2.1612799584693033700667928383065551889479216822305E-06L)
#define B07 (+3.7024380616574339157661134936776156061716153770560E-08L)

#define NUM_EVAL(z) \
A00+z*(A01+z*(A02+z*(A03+z*(A04+z*(A05+z*(A06+z*(A07+z*A08)))))))

#define DEN_EVAL(z) \
B00+z*(B01+z*(B02+z*(B03+z*(B04+z*(B05+z*(B06+z*B07))))))

#endif

long double Erf_LDouble_Rat_Remez(long double x)
{
    const long double x2 = x*x;
    const long double p = NUM_EVAL(x2);
    const long double q = DEN_EVAL(x2);
    return x * p / q;
}
