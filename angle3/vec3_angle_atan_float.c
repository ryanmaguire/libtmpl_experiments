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
 *      Computes the angle between two vectors using the arctan formula.      *
 ******************************************************************************/
#include <libtmpl/include/tmpl_math.h>
#include <libtmpl/include/tmpl_vec3.h>
#include "vec3_angle.h"

/*  Function for computing angles using the arctan formula.                   */
float
Angle_Vec3f_Arctan(const tmpl_ThreeVectorFloat * const P,
                   const tmpl_ThreeVectorFloat * const Q)
{
    tmpl_ThreeVectorFloat cross = tmpl_3DFloat_Cross_Product(P, Q);
    float norm_cross = tmpl_3DFloat_L2_Norm(&cross);
    float dot = tmpl_3DFloat_Dot_Product(P, Q);
    return tmpl_Float_Arctan2(norm_cross, dot);
}
/*  End of Angle_Vec3f_Arctan.                                                */
