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
#include "bessel_i0.h"
#include <libtmpl/include/tmpl_math.h>

#define A00 (+3.989422804014250978354994e-01L)
#define A01 (+4.986778506049619613671453e-02L)
#define A02 (+2.805062339283126079947372e-02L)
#define A03 (+2.922112251660478887682615e-02L)
#define A04 (+4.442072994936595298209880e-02L)
#define A05 (+1.309705746058567321643551e-01L)
#define A06 (-3.350522802317270176786224e+00L)
#define A07 (+2.330257115835147203597444e+02L)
#define A08 (-1.133663506971723472815938e+04L)
#define A09 (+4.240576743178673204965889e+05L)
#define A10 (-1.231570285956987366080284e+07L)
#define A11 (+2.802319381552675366401672e+08L)
#define A12 (-5.018839997137779235839844e+09L)
#define A13 (+7.080292430151091003417969e+10L)
#define A14 (-7.842610821248111572265625e+11L)
#define A15 (+6.768257378540965820312500e+12L)
#define A16 (-4.490348496961380468750000e+13L)
#define A17 (+2.241552399669590000000000e+14L)
#define A18 (-8.134264678656593750000000e+14L)
#define A19 (+2.023910973916877750000000e+15L)
#define A20 (-3.086757152953709000000000e+15L)
#define A21 (+2.175875438638190750000000e+15L)

/*  Helper macro for evaluating a polynomial via Horner's method.             */
#define POLY_EVAL(z) \
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
                      A11 + z*(\
                        A12 + z*(\
                          A13 + z*(\
                            A14 + z*(\
                              A15 + z*(\
                                A16 + z*(\
                                  A17 + z*(\
                                    A18 + z*(\
                                      A19 + z*(\
                                        A20 + z*A21\
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

long double I0_LDouble_Holoborodko(long double x)
{
    const long double rcpr_x = 1.0L / x;
    const long double exp_x = tmpl_LDouble_Exp_Pos_Kernel(x);
    const long double inv_sqrt_x = tmpl_LDouble_Sqrt(rcpr_x);
    const long double poly = POLY_EVAL(rcpr_x);
    return exp_x * poly * inv_sqrt_x;
}
