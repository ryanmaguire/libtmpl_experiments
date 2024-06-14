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

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.0000000000000001123919676354452323391255224072742E+00)
#define P01 (-1.4498233326923865122488459468980747538297064568854E-01)
#define P02 (-2.0045236415543053324925417422227381696690500534450E-01)
#define P03 (+3.0391281310843797255185898047449100054458034406149E-02)
#define P04 (+1.7693185823005328992166988197676597649130439992243E-02)
#define P05 (-2.8404217703389510233458709107932781658991140210552E-03)
#define P06 (-5.2026806734099569779381353409292068105243965508871E-04)
#define P07 (+1.0071096242797246165192242454042976473037890307982E-04)
#define P08 (+3.7448574994752405703891854644847220572092642682598E-06)
#define P09 (-1.3917104285246302422727075023909844081633078830308E-06)
#define P10 (+6.3068205693179655448528429852216816165796012808672E-08)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00)
#define Q01 (-1.4498233326921766398245016702939590951007763781512E-01)
#define Q02 (+4.6287745871150310069531339392601041095196433522611E-02)
#define Q03 (-5.3816755439295514120527522644290159186317185493657E-03)
#define Q04 (+9.2872840141556568402245654755620200438778270950895E-04)
#define Q05 (-8.1897093463233130234578914823976559342260264454676E-05)
#define Q06 (+9.1257545310252648076808646041974946632707546551295E-06)
#define Q07 (-4.8977532454245339328991757738709780721036054181882E-07)
#define Q08 (+3.0754504055633316606582025653771724519569715529121E-08)

#define NUM_EVAL(z) \
P00 + z*(\
    P01 + z*(\
        P02 + z*(\
            P03 + z*(\
                P04 + z*(\
                    P05 + z*(\
                        P06 + z*(\
                            P07 + z*(\
                                P08 + z*(\
                                    P09 + z*P10\
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
Q00 + z*(\
    Q01 + z*(\
        Q02 + z*(\
            Q03 + z*(\
                Q04 + z*(\
                    Q05 + z*(\
                        Q06 + z*(\
                            Q07 + z*Q08\
                        )\
                    )\
                )\
            )\
        )\
    )\
)

double Fresnel_Cos_Double_Remez_Large(double x)
{
    const double x2 = x*x;
    const double num = NUM_EVAL(x2);
    const double den = DEN_EVAL(x2);

    return x * num / den;
}
