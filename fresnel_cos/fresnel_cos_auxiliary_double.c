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
#include"fresnel_cos.h"
#include <libtmpl/include/tmpl_math.h>

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define PF0 (+3.9785785606985516260315031176402616177768523646707E-02)
#define PF1 (+3.1460524171189207051526939740019997338493021397842E-02)
#define PF2 (-3.4116138175139630548259571559587921103080712981879E-03)
#define PF3 (+4.9057613235844597326380118525485610398847358871345E-03)
#define PF4 (+7.2271750630598318136026426156173319563228287427898E-05)
#define PF5 (+8.5782717396192594263145359652575385082196979923528E-05)
#define PF6 (+8.2022105238272390862120766434939021389939052429335E-06)
#define PF7 (+2.3778411765897237859773123052390608226667576107399E-06)
#define PF8 (-1.9969727952933804675602292366140025824000908251325E-07)

#define PF_EVAL(z) \
PF0+z*(PF1+z*(PF2+z*(PF3+z*(PF4+z*(PF5+z*(PF6+z*(PF7+z*PF8)))))))

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define QF0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define QF1 (-2.0895580722899259140488226532546522073820016999006E-01)
#define QF2 (+1.2388417067390880096267209253020918172907109799969E-01)
#define QF3 (+3.9118866773592830587747139355838508067164302189331E-05)
#define QF4 (+2.0782033278687181244405907230025134172616214410866E-03)
#define QF5 (+1.6028131460017157855141073648141094463073982604636E-04)
#define QF6 (+7.3479384914638557161942939258429353420683079774060E-05)
#define QF7 (-4.7957838438596052306189910601148042968894938264726E-06)
#define QF8 (+1.0516421346067489741514646580833935222012116877897E-07)

#define QF_EVAL(z) \
QF0+z*(QF1+z*(QF2+z*(QF3+z*(QF4+z*(QF5+z*(QF6+z*(QF7+z*QF8)))))))

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define PG0 (+1.9781962280286553944842597971257431973123214453157E-04)
#define PG1 (+4.0007037737023907056468852046671232862655719766325E-04)
#define PG2 (+7.7873346259075461622781744914528902652982974404521E-05)
#define PG3 (-2.0459129783470188978718809989099541130247451752683E-04)
#define PG4 (-4.6551169553995577251522929852029024356845962916715E-05)
#define PG5 (+1.9781733072754765590175832724221439049060511381685E-05)
#define PG6 (-1.2832469370310248016164186919085053121191010074045E-05)
#define PG7 (+1.0460913850504924071841788932576590826491317740504E-06)
#define PG8 (-2.4261442898409229851471504040934985295809887388313E-09)

#define PG_EVAL(z) \
PG0+z*(PG1+z*(PG2+z*(PG3+z*(PG4+z*(PG5+z*(PG6+z*(PG7+z*PG8)))))))

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define QG0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define QG1 (-9.7611999670750202875302260224423355484417638120864E-01)
#define QG2 (+3.2722503048409242950629708700697148377684360085038E-01)
#define QG3 (-8.1028576497746761430974957244329382968410755179354E-02)
#define QG4 (+4.8420609528806341077699430640017396411668602373050E-03)
#define QG5 (-6.3456582984581089585799277042303190888585855947148E-05)
#define QG6 (+1.7116330061921710199781726359684266632421609876146E-05)
#define QG7 (-1.9129039444255146575307913206552468605172881514005E-05)
#define QG8 (+2.6618093583186304364105899603456337376004312466385E-06)

#define QG_EVAL(z) \
QG0+z*(QG1+z*(QG2+z*(QG3+z*(QG4+z*(QG5+z*(QG6+z*(QG7+z*QG8)))))))

double Fresnel_Cos_Double_Auxiliary(double x)
{
    const double z = x*x*0.5;
    double cz, sz;

    const double t = -1.0 + 8.0 / x;

    const double fn = PF_EVAL(t);
    const double fd = QF_EVAL(t);

    const double gn = PG_EVAL(t);
    const double gd = QG_EVAL(t);

    const double f = fn / fd;
    const double g = gn / gd;

    tmpl_Double_SinCosPi(z, &sz, &cz);

    return 0.5 + (f*sz - g*cz);
}
