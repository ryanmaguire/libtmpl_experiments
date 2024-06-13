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
double
Angle_Vec3_Kahan(const tmpl_ThreeVectorDouble * const P,
                 const tmpl_ThreeVectorDouble * const Q)
{
    const tmpl_ThreeVectorDouble Pn = tmpl_3DDouble_Normalize(P);
    const tmpl_ThreeVectorDouble Qn = tmpl_3DDouble_Normalize(Q);
    const tmpl_ThreeVectorDouble diff = tmpl_3DDouble_Subtract(&Pn, &Qn);
    const tmpl_ThreeVectorDouble sum = tmpl_3DDouble_Add(&Pn, &Qn);
    const double left = tmpl_3DDouble_L2_Norm(&diff);
    const double right = tmpl_3DDouble_L2_Norm(&sum);
    return 2.0 * tmpl_Double_Arctan(left / right);
}
/*  End of Angle_Vec3_Kahan.                                                  */
