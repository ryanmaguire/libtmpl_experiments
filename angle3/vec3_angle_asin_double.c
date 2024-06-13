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
double
Angle_Vec3_Arcsin(const tmpl_ThreeVectorDouble * const P,
                  const tmpl_ThreeVectorDouble * const Q)
{
    const double norm_p = tmpl_3DDouble_L2_Norm(P);
    const double norm_q = tmpl_3DDouble_L2_Norm(Q);
    const tmpl_ThreeVectorDouble cross = tmpl_3DDouble_Cross_Product(P, Q);
    const double arg = tmpl_3DDouble_L2_Norm(&cross) / (norm_p * norm_q);
    const double dot = tmpl_3DDouble_Dot_Product(P, Q);

    if (dot > 0.0)
        return tmpl_Double_Arcsin(arg);

    return tmpl_One_Pi - tmpl_Double_Arcsin(arg);
}
/*  End of Angle_Vec3_Arcsin.                                                 */
