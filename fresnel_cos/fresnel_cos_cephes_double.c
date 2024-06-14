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

#define PI_BY_TWO (+1.57079632679489661923132169163975144209858469968755291E+00)
#define ONE_PI (+3.14159265358979323846264338327950288419716939937510582097E+00)

#define PF00 (+4.21543555043677546506E-01)
#define PF01 (+1.43407919780758885261E-01)
#define PF02 (+1.15220955073585758835E-02)
#define PF03 (+3.45017939782574027900E-04)
#define PF04 (+4.63613749287867322088E-06)
#define PF05 (+3.05568983790257605827E-08)
#define PF06 (+1.02304514164907233465E-10)
#define PF07 (+1.72010743268161828879E-13)
#define PF08 (+1.34283276233062758925E-16)
#define PF09 (+3.76329711269987889006E-20)

#define QF00 (+1.00000000000000000000E+00)
#define QF01 (+7.51586398353378947175E-01)
#define QF02 (+1.16888925859191382142E-01)
#define QF03 (+6.44051526508858611005E-03)
#define QF04 (+1.55934409164153020873E-04)
#define QF05 (+1.84627567348930545870E-06)
#define QF06 (+1.12699224763999035261E-08)
#define QF07 (+3.60140029589371370404E-11)
#define QF08 (+5.88754533621578410010E-14)
#define QF09 (+4.52001434074129701496E-17)
#define QF10 (+1.25443237090011264384E-20)

#define PG00 (+5.04442073643383265887E-01)
#define PG01 (+1.97102833525523411709E-01)
#define PG02 (+1.87648584092575249293E-02)
#define PG03 (+6.84079380915393090172E-04)
#define PG04 (+1.15138826111884280931E-05)
#define PG05 (+9.82852443688422223854E-08)
#define PG06 (+4.45344415861750144738E-10)
#define PG07 (+1.08268041139020870318E-12)
#define PG08 (+1.37555460633261799868E-15)
#define PG09 (+8.36354435630677421531E-19)
#define PG10 (+1.86958710162783235106E-22)

#define QG00 (+1.00000000000000000000E+00)
#define QG01 (+1.47495759925128324529E+00)
#define QG02 (+3.37748989120019970451E-01)
#define QG03 (+2.53603741420338795122E-02)
#define QG04 (+8.14679107184306179049E-04)
#define QG05 (+1.27545075667729118702E-05)
#define QG06 (+1.04314589657571990585E-07)
#define QG07 (+4.60680728146520428211E-10)
#define QG08 (+1.10273215066240270757E-12)
#define QG09 (+1.38796531259578871258E-15)
#define QG10 (+8.39158816283118707363E-19)
#define QG11 (+1.86958710162783236342E-22)

#define PF_EVAL(z) \
PF00 + z*(\
    PF01 + z*(\
        PF02 + z*(\
            PF03 + z*(\
                PF04 + z*(\
                    PF05 + z*(\
                        PF06 + z*(\
                            PF07 + z*(\
                                PF08 + z*PF09\
                            )\
                        )\
                    )\
                )\
            )\
        )\
    )\
)

#define QF_EVAL(z) \
QF00 + z*(\
    QF01 + z*(\
        QF02 + z*(\
            QF03 + z*(\
                QF04 + z*(\
                    QF05 + z*(\
                        QF06 + z*(\
                            QF07 + z*(\
                                QF08 + z*(\
                                    QF09 + z*QF10\
                                )\
                            )\
                        )\
                    )\
                )\
            )\
        )\
    )\
)

#define PG_EVAL(z) \
PG00 + z*(\
    PG01 + z*(\
        PG02 + z*(\
            PG03 + z*(\
                PG04 + z*(\
                    PG05 + z*(\
                        PG06 + z*(\
                            PG07 + z*(\
                                PG08 + z*(\
                                    PG09 + z*PG10\
                                )\
                            )\
                        )\
                    )\
                )\
            )\
        )\
    )\
)

#define QG_EVAL(z) \
QG00 + z*(\
    QG01 + z*(\
        QG02 + z*(\
            QG03 + z*(\
                QG04 + z*(\
                    QG05 + z*(\
                        QG06 + z*(\
                            QG07 + z*(\
                                QG08 + z*(\
                                    QG09 + z*(\
                                        QG10 + z*QG11\
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

double Fresnel_Cos_Double_Cephes_Auxiliary(double x)
{
    const double z = PI_BY_TWO * x * x;
    const double cz = tmpl_Double_Cos(z);
    const double sz = tmpl_Double_Sin(z);

    const double t = 1.0 / z;
    const double u = t*t;

    const double fn = PF_EVAL(u);
    const double fd = QF_EVAL(u);

    const double gn = PG_EVAL(u);
    const double gd = QG_EVAL(u);

    const double f = 1.0 - u * (fn / fd);
    const double g = t * (gn / gd);

    return 0.5 + (f*sz - g*cz) / (ONE_PI * x);
}
