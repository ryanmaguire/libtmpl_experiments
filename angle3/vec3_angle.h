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
 *      Various algorithms for computing angles in three dimensions.          *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef TMPL_EXPERIMENTS_VEC3_ANGLE_H
#define TMPL_EXPERIMENTS_VEC3_ANGLE_H

/*  libtmpl vector typedef's.                                                 */
#include <libtmpl/include/tmpl_vec3_double.h>
#include <libtmpl/include/tmpl_vec3_float.h>
#include <libtmpl/include/tmpl_vec3_ldouble.h>

/*  Compute angles using the arccos formula.                                  */
extern double
Angle_Vec3_Arccos(const tmpl_ThreeVectorDouble * const P,
                  const tmpl_ThreeVectorDouble * const Q);

extern float
Angle_Vec3f_Arccos(const tmpl_ThreeVectorFloat * const P,
                   const tmpl_ThreeVectorFloat * const Q);

extern long double
Angle_Vec3l_Arccos(const tmpl_ThreeVectorLongDouble * const P,
                   const tmpl_ThreeVectorLongDouble * const Q);

/*  Compute angles using the arcsin formula.                                  */
extern double
Angle_Vec3_Arcsin(const tmpl_ThreeVectorDouble * const P,
                  const tmpl_ThreeVectorDouble * const Q);

extern float
Angle_Vec3f_Arcsin(const tmpl_ThreeVectorFloat * const P,
                   const tmpl_ThreeVectorFloat * const Q);

extern long double
Angle_Vec3l_Arcsin(const tmpl_ThreeVectorLongDouble * const P,
                   const tmpl_ThreeVectorLongDouble * const Q);

/*  Compute angles using the arctan formula.                                  */
extern double
Angle_Vec3_Arctan(const tmpl_ThreeVectorDouble * const P,
                  const tmpl_ThreeVectorDouble * const Q);

extern float
Angle_Vec3f_Arctan(const tmpl_ThreeVectorFloat * const P,
                   const tmpl_ThreeVectorFloat * const Q);

extern long double
Angle_Vec3l_Arctan(const tmpl_ThreeVectorLongDouble * const P,
                   const tmpl_ThreeVectorLongDouble * const Q);

/*  Compute angles using the formula from Kahan's paper.                      */
extern double
Angle_Vec3_Kahan(const tmpl_ThreeVectorDouble * const P,
                 const tmpl_ThreeVectorDouble * const Q);

extern float
Angle_Vec3f_Kahan(const tmpl_ThreeVectorFloat * const P,
                  const tmpl_ThreeVectorFloat * const Q);

extern long double
Angle_Vec3l_Kahan(const tmpl_ThreeVectorLongDouble * const P,
                  const tmpl_ThreeVectorLongDouble * const Q);

#endif
/*  End of include guard.                                                     */
