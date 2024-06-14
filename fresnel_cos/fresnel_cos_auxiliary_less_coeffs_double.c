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
#define PF0 (+3.9785785606985520526099231243458288489237086040017E-02)
#define PF1 (+3.8844093326268630487293357390915761465620661439132E-02)
#define PF2 (+1.2135884591861022790525234951264418865314671914792E-03)
#define PF3 (+2.7996213063709778950016967542724498396929410660997E-03)
#define PF4 (+6.7986470135401774701137100727906988187462652603753E-04)
#define PF5 (+4.0393662027350155120236085728641369131057482363176E-05)
#define PF6 (+6.7240691661302780155493993223041710864623135733106E-06)
#define PF7 (+1.8159540797528401100251307468231041094889887031802E-06)
#define PF8 (-3.8587945082094147733147164507628318319389679356811E-08)

#define PF_EVAL(z) \
PF0+z*(PF1+z*(PF2+z*(PF3+z*(PF4+z*(PF5+z*(PF6+z*(PF7+z*PF8)))))))

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define QF0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define QF1 (-2.3372714110847874819411804366935566849950659684115E-02)
#define QF2 (+5.4608706558057553746065409828812135353165464642892E-02)
#define QF3 (+1.6494360278188175198300382361499134878599675455618E-02)
#define QF4 (+9.8493126176679339920406604732328741854557316166453E-04)
#define QF5 (+1.4090930351355615737821693520431301105149453860659E-04)
#define QF6 (+5.4162561463348917696916578721055668522052577053254E-05)

#define QF_EVAL(z) \
QF0+z*(QF1+z*(QF2+z*(QF3+z*(QF4+z*(QF5+z*QF6)))))

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define PG0 (+1.9781962280296780618833881243685688669832402651221E-04)
#define PG1 (+5.7584468591493533360166690660671347038478527076488E-04)
#define PG2 (+5.5586328996919195719202768326654436314495954286618E-04)
#define PG3 (+1.9140859793774630450525370978145168379150500605558E-04)
#define PG4 (+3.0466151481449889127628555055880820906890609844656E-05)
#define PG5 (+1.8121557207127908775983301104372551753475601437723E-05)
#define PG6 (+1.4933577657765725296781671200461082140502195107915E-06)
#define PG7 (+2.6758095970257555721201897452876509871075617214375E-07)

#define PG_EVAL(z) \
PG0+z*(PG1+z*(PG2+z*(PG3+z*(PG4+z*(PG5+z*(PG6+z*PG7))))))

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define QG0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define QG1 (-8.7561490459433708965220684645229903124355388995600E-02)
#define QG2 (+7.9156562998866982504467817898042230744836304195380E-02)
#define QG3 (+4.8674933602818384192935293548813029052255412043042E-03)
#define QG4 (+1.7393473692326990976390416201437849864987696528001E-03)
#define QG5 (+6.8469390893263375877448838072538412525798534135041E-05)
#define QG6 (+2.5567732745154095152807975674484879904832785386625E-05)

#define QG_EVAL(z) \
QG0+z*(QG1+z*(QG2+z*(QG3+z*(QG4+z*(QG5+z*QG6)))))

double Fresnel_Cos_Double_Auxiliary_Less_Coeffs(double x)
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
