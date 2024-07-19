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
#ifndef TMPL_EXPERIMENTS_FRESNEL_COS_H
#define TMPL_EXPERIMENTS_FRESNEL_COS_H

extern double Fresnel_Cos_Double_Auxiliary(double x);
extern float Fresnel_Cos_Float_Auxiliary(float x);
extern long double Fresnel_Cos_LDouble_Auxiliary(long double x);

extern double Fresnel_Cos_Double_Auxiliary_Less_Coeffs(double x);
extern float Fresnel_Cos_Float_Auxiliary_Less_Coeffs(float x);
extern long double Fresnel_Cos_LDouble_Auxiliary_Less_Coeffs(long double x);

extern double Fresnel_Cos_Double_Auxiliary_Alt(double x);
extern float Fresnel_Cos_Float_Auxiliary_Alt(float x);
extern long double Fresnel_Cos_LDouble_Auxiliary_Alt(long double x);

extern double Fresnel_Cos_Double_Auxiliary_Safe_Less_Coeffs(double x);
extern float Fresnel_Cos_Float_Auxiliary_Safe_Less_Coeffs(float x);
extern long double Fresnel_Cos_LDouble_Auxiliary_Safe_Less_Coeffs(long double x);

extern double Fresnel_Cos_Double_Auxiliary_Safe(double x);
extern float Fresnel_Cos_Float_Auxiliary_Safe(float x);
extern long double Fresnel_Cos_LDouble_Auxiliary_Safe(long double x);

extern double Fresnel_Cos_Double_Cephes_Auxiliary(double x);
extern float Fresnel_Cos_Float_Cephes_Auxiliary(float x);
extern long double Fresnel_Cos_LDouble_Cephes_Auxiliary(long double x);

extern double Fresnel_Cos_Double_Remez_Large(double x);
extern float Fresnel_Cos_Float_Remez_Large(float x);
extern long double Fresnel_Cos_LDouble_Remez_Large(long double x);

extern double Fresnel_Cos_Double_Heald_Three(double x);
extern float Fresnel_Cos_Float_Heald_Three(float x);
extern long double Fresnel_Cos_LDouble_Heald_Three(long double x);

extern double Fresnel_Cos_Double_Heald_Four(double x);
extern float Fresnel_Cos_Float_Heald_Four(float x);
extern long double Fresnel_Cos_LDouble_Heald_Four(long double x);

extern double Fresnel_Cos_Double_Heald_Six(double x);
extern float Fresnel_Cos_Float_Heald_Six(float x);
extern long double Fresnel_Cos_LDouble_Heald_Six(long double x);

extern double Fresnel_Cos_Double_Heald_Eight(double x);
extern float Fresnel_Cos_Float_Heald_Eight(float x);
extern long double Fresnel_Cos_LDouble_Heald_Eight(long double x);

extern double Fresnel_Cos_Double_Rat_Remez(double x);
extern float Fresnel_Cos_Float_Rat_Remez(float x);
extern long double Fresnel_Cos_LDouble_Rat_Remez(long double x);

#endif
