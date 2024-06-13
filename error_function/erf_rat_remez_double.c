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

/*  Function prototype provided here.                                         */
#include "error_function.h"

#if 1

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955126365607040611486440894548731064430E+00)
#define P01 (+6.1856680806948109220677660264677907003149751444417E-02)
#define P02 (+4.1145518213074999565262794018611561200627595655126E-02)
#define P03 (-8.7707136933607770079319073352925173083333681109000E-04)
#define P04 (+2.7125577380014977514418180966266226228905135708230E-04)
#define P05 (-1.3239722107678831460532410663306244658302355190564E-05)
#define P06 (+6.2564335958048129592868311685179924773329314231658E-07)
#define P07 (-1.8239148907346264717934021446679328630982359872721E-08)
#define P08 (+2.5839003238848066077920003511476230831774264021355E-10)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00)
#define Q01 (+3.8815238938359424075188631415877534713061633081189E-01)
#define Q02 (+6.5848395896534329559179312445593670161084460771079E-02)
#define Q03 (+6.1664659079696183164995589642551932095328093191702E-03)
#define Q04 (+3.2313713982428331981430572957719222195415860127493E-04)
#define Q05 (+7.7253055534510380898965062146051908309590150561640E-06)

#define NUM_EVAL(z)\
P00+z*(P01+z*(P02+z*(P03+z*(P04+z*(P05+z*(P06+z*(P07+z*P08)))))))

#define DEN_EVAL(z) Q00+z*(Q01+z*(Q02+z*(Q03+z*(Q04+z*Q05))))

#else

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955125723612641437186387256241615705546E+00)
#define P01 (+1.0940111398090927285374953761427778706084669842879E-01)
#define P02 (+4.5338455858465155889062197671106782138037420887971E-02)
#define P03 (+9.2319971446070099448124582866717035185570900200774E-04)
#define P04 (+2.8826830742872909759230172228668570599509595953392E-04)
#define P05 (-3.8151340259295387675109537081313065536571550818813E-06)
#define P06 (+3.8164528144882835872176531036064413291477962114273E-07)
#define P07 (-9.0529876606885702741678495551392725141093589590910E-09)
#define P08 (+1.1217070195424020804732016985031343598968103097250E-10)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00)
#define Q01 (+4.3028754621774110958770222977337060576443666726374E-01)
#define Q02 (+8.3609342412807814938321077090955081174189145053708E-02)
#define Q03 (+9.4687144365060837330118230890721955696372888120604E-03)
#define Q04 (+6.6608698718115413708421928177696451249655408107128E-04)
#define Q05 (+2.7978890296366625776695792221614616668682474401183E-05)
#define Q06 (+5.5892314500748891314190439277447503961966021076536E-07)

#define NUM_EVAL(z)\
P00+z*(P01+z*(P02+z*(P03+z*(P04+z*(P05+z*(P06+z*(P07+z*P08)))))))

#define DEN_EVAL(z) Q00+z*(Q01+z*(Q02+z*(Q03+z*(Q04+z*(Q05+z*Q06)))))

#endif

double Erf_Double_Rat_Remez(double x)
{
    const double x2 = x*x;
    const double p = NUM_EVAL(x2);
    const double q = DEN_EVAL(x2);
    return x * p / q;
}
