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
#define PF0 (-2.1447177918579579753388433334911075409571981652522E-17)
#define PF1 (+7.9577471545956793464435579966743818103647044950248E-02)
#define PF2 (-1.2981161608641168980253175509340062024354018232720E-02)
#define PF3 (+3.1265770142568086318447462445674196101423129654279E-03)
#define PF4 (+7.7189914096390976785579606078912825867840834363500E-03)
#define PF5 (+1.2152711327644207051269759240566405273724207890213E-03)
#define PF6 (-4.2580086843249039236789916436456229647180162906877E-04)
#define PF7 (+2.5599751814229062968976494152423993700328342606881E-04)
#define PF8 (-9.2991030649511374603974585631455140488901798820494E-06)

#define PF_EVAL(z) \
PF0+z*(PF1+z*(PF2+z*(PF3+z*(PF4+z*(PF5+z*(PF6+z*(PF7+z*PF8)))))))

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define QF0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define QF1 (-1.6312608777091934006569688848947319631644210599940E-01)
#define QF2 (+3.9289725286653476885524131750142019793543796155984E-02)
#define QF3 (+9.6999710172863227181034452265627316168021158412569E-02)
#define QF4 (+1.6458875720410357910114941861796832691658504516205E-02)
#define QF5 (-5.5442943302851907019637247635816813200757166309069E-03)
#define QF6 (+3.2629747328741893876385822248293808741755682623822E-03)

#define QF_EVAL(z) \
QF0+z*(QF1+z*(QF2+z*(QF3+z*(QF4+z*(QF5+z*QF6)))))

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define PG0 (+4.1888470497242228970512655048232789216782855688029E-18)
#define PG1 (-1.9399304561569123981472429874629917184781769350025E-15)
#define PG2 (+1.5079232893754790305784439966341317007503129139523E-13)
#define PG3 (+1.5831434897680803460728630060707251688669525968296E-03)
#define PG4 (-8.5860131430356321612346593614783654305957210855428E-04)
#define PG5 (+4.2520325383513231021011832063304578196045175371085E-04)
#define PG6 (+3.3997508002435750699645210285275720556079846712290E-05)
#define PG7 (-5.5470926830268577613702499017237117454491309503712E-06)
#define PG8 (+7.5271268828364550735383328753338000305964366209750E-06)

#define PG_EVAL(z) \
PG0+z*(PG1+z*(PG2+z*(PG3+z*(PG4+z*(PG5+z*(PG6+z*(PG7+z*PG8)))))))

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define QG0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define QG1 (-5.4233958725410615801476694071713976580197499138498E-01)
#define QG2 (+2.6858208718351641067450334485612139901006052610880E-01)
#define QG3 (+2.1471758208227504686456421042560514470187040155549E-02)
#define QG4 (+2.4456357033936610541923412853466023983394272209113E-03)
#define QG5 (+1.4961320031496760787440948034839831542661075561170E-03)
#define QG6 (+1.6780659196575798229291066904872309116983197533248E-03)

#define QG_EVAL(z) \
QG0+z*(QG1+z*(QG2+z*(QG3+z*(QG4+z*(QG5+z*QG6)))))

double Fresnel_Cos_Double_Auxiliary_Alt(double x)
{
    const double z = x*x*0.5;
    double cz, sz;

    const double t = 4.0 / x;

    const double fn = PF_EVAL(t);
    const double fd = QF_EVAL(t);

    const double gn = PG_EVAL(t);
    const double gd = QG_EVAL(t);

    const double f = fn / fd;
    const double g = gn / gd;

    tmpl_Double_SinCosPi(z, &sz, &cz);

    return 0.5 + (f*sz - g*cz);
}
