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
 *      Computes the angle between two vectors using the formula in           *
 *      W. Kahan's paper "How Futile are Mindless Assessments of Roundoff     *
 *      in Floating-Point Computation?"                                       *
 ******************************************************************************/
#include <libtmpl/include/tmpl_math.h>
#include <libtmpl/include/tmpl_vec3.h>
#include "vec3_angle.h"

/*  Function for computing angles using the Kahan formula.                    */
long double
Angle_Vec3l_Kahan(const tmpl_ThreeVectorLongDouble * const P,
                  const tmpl_ThreeVectorLongDouble * const Q)
{
    const tmpl_ThreeVectorLongDouble Pn = tmpl_3DLDouble_Normalize(P);
    const tmpl_ThreeVectorLongDouble Qn = tmpl_3DLDouble_Normalize(Q);
    const tmpl_ThreeVectorLongDouble diff = tmpl_3DLDouble_Subtract(&Pn, &Qn);
    const tmpl_ThreeVectorLongDouble sum = tmpl_3DLDouble_Add(&Pn, &Qn);
    const long double left = tmpl_3DLDouble_L2_Norm(&diff);
    const long double right = tmpl_3DLDouble_L2_Norm(&sum);
    return 2.0L * tmpl_LDouble_Arctan(left / right);
}
/*  End of Angle_Vec3l_Kahan.                                                 */
