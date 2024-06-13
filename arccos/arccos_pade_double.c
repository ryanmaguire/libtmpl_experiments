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
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Computes the (12, 12) Pade approximant of acos(x) at double precision.*
 ******************************************************************************/
#include "arccos.h"

/*  Coefficients for the numerator of the Pade approximant.                   */
#define P0 (+1.6666666666666666666666666666666666666666666666667E-01)
#define P1 (-4.5183467789315450573566044285447580081757824962844E-01)
#define P2 (+4.5268338285839953885847747489466534382453836599311E-01)
#define P3 (-2.0451170074586957459619221134199241262964264122754E-01)
#define P4 (+4.0161699156136797388526896443437389593682105247059E-02)
#define P5 (-2.6043612272315037174810668430207303056407157408729E-03)
#define P6 (+8.5298365158969137130716621168483153368286640425841E-06)

/*  Coefficients for the denominator of the Pade approximant.                 */
#define Q0 (+1.0000000000000000000000000000000000000000000000000E+00)
#define Q1 (-3.1610080673589270344139626571268548049054694977706E+00)
#define Q2 (+3.8706967846047715414942909022179338680118343270983E+00)
#define Q3 (-2.3044768347428901379839394147005695603073114886090E+00)
#define Q4 (+6.8318346338074073586036792129413385817260793401216E-01)
#define Q5 (-9.1189047491786682631147583983250333633502470655541E-02)
#define Q6 (+3.9268447888541310343247866236378900929051188393826E-03)

/*  The constant Pi / 2.                                                      */
#define TMPL_PI_BY_TWO (+1.5707963267948966192313216916397514420985846996E+00)

/*  Helper macros for evaluating a polynomial via Horner's method.            */
#define TMPL_NUM_EVAL(z) P0 + z*(P1 + z*(P2 + z*(P3 + z*(P4 + z*(P5 + z*P6)))))
#define TMPL_DEN_EVAL(z) Q0 + z*(Q1 + z*(Q2 + z*(Q3 + z*(Q4 + z*(Q5 + z*Q6)))))

/*  Function for computing the (12, 12) Pade approximant of acos(x).          */
double Arccos_Double_Pade(double x)
{
    /*  The polynomials for the numerator and denominator are in terms of x^2.*/
    const double x2 = x*x;

    /*  Use Horner's method to evaluate the two polynomials.                  */
    const double p = TMPL_NUM_EVAL(x2);
    const double q = TMPL_DEN_EVAL(x2);
    const double r = x2*p/q;

    /*  p/q is the Pade approximant for (acos(x) - pi/2 + x) / x^3.           */
    return TMPL_PI_BY_TWO - (x + x*r);
}
/*  End of Arccos_Double_Pade.                                                */
