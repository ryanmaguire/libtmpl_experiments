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
 *      Computes the angle between two vectors using the arcsin formula.      *
 ******************************************************************************/
#include <libtmpl/include/tmpl_math.h>
#include <libtmpl/include/tmpl_vec3.h>
#include "vec3_angle.h"

/*  Function for computing angles using the arcsin formula.                   */
long double
Angle_Vec3l_Arcsin(const tmpl_ThreeVectorLongDouble * const P,
                   const tmpl_ThreeVectorLongDouble * const Q)
{
    const long double norm_p = tmpl_3DLDouble_L2_Norm(P);
    const long double norm_q = tmpl_3DLDouble_L2_Norm(Q);
    const tmpl_ThreeVectorLongDouble cross = tmpl_3DLDouble_Cross_Product(P, Q);
    const long double arg = tmpl_3DLDouble_L2_Norm(&cross) / (norm_p * norm_q);
    const long double dot = tmpl_3DLDouble_Dot_Product(P, Q);

    if (dot > 0.0L)
        return tmpl_LDouble_Arcsin(arg);

    return tmpl_One_Pi_L - tmpl_LDouble_Arcsin(arg);
}
/*  End of Angle_Vec3l_Arcsin.                                                */
