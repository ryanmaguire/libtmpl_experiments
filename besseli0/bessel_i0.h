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

/*  Include guard to prevent including this file twice.                       */
#ifndef TMPL_EXPERIMENTS_BESSEL_I0_H
#define TMPL_EXPERIMENTS_BESSEL_I0_H

/*  Computes I0(x) using an asymptotic expansion.                             */
extern double I0_Double_Asymptotic(double x);
extern float I0_Float_Asymptotic(float x);
extern long double I0_LDouble_Asymptotic(long double x);

/*  Computes I0(x) using a Chebyshev expansion.                               */
extern double I0_Double_Chebyshev(double x);
extern float I0_Float_Chebyshev(float x);
extern long double I0_LDouble_Chebyshev(long double x);

/*  Computes I0(x) using Holoborodko's expansion.                             */
extern double I0_Double_Holoborodko(double x);
extern float I0_Float_Holoborodko(float x);
extern long double I0_LDouble_Holoborodko(long double x);

/*  Computes I0(x) using a Maclaurin series.                                  */
extern double I0_Double_Maclaurin(double x);
extern float I0_Float_Maclaurin(float x);
extern long double I0_LDouble_Maclaurin(long double x);

/*  Computes I0(x) using a Remez polynomial.                                  */
extern double I0_Double_Remez(double x);
extern float I0_Float_Remez(float x);
extern long double I0_LDouble_Remez(long double x);

/*  Computes I0(x) using an asymptotic expansion.                             */
extern double I0_Double_Very_Large(double x);
extern float I0_Float_Very_Large(float x);
extern long double I0_LDouble_Very_Large(long double x);

#endif
/*  End of include guard.                                                     */
