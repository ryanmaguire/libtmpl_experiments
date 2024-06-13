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
 *      Various methods of computing the arccos function.                     *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef TMPL_EXPERIMENTS_ARCCOS_H
#define TMPL_EXPERIMENTS_ARCCOS_H

/*  Computes arccos for small values using a Maclaurin series.                */
extern double Arccos_Double_Maclaurin(double x);
extern float Arccos_Float_Maclaurin(float x);
extern long double Arccos_LDouble_Maclaurin(long double x);

/*  Computes arccos using a Pade approximant.                                 */
extern double Arccos_Double_Pade(double x);
extern float Arccos_Float_Pade(float x);
extern long double Arccos_LDouble_Pade(long double x);

/*  Computes arccos using a rational Remez approximation.                     */
extern double Arccos_Double_Rat_Remez(double x);
extern float Arccos_Float_Rat_Remez(float x);
extern long double Arccos_LDouble_Rat_Remez(long double x);

/*  Computes arccos using the reflection formula.                             */
extern double Arccos_Double_Tail_End(double x);
extern float Arccos_Float_Tail_End(float x);
extern long double Arccos_LDouble_Tail_End(long double x);

#endif
/*  End of include guard.                                                     */
