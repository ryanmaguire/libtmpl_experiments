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
#include <libtmpl/include/tmpl_math.h>
#include <libtmpl/include/tmpl_minmax.h>
#include "l2_norm.h"

#define TMPL_BIG_SCALE (+1.340780792994259709957402E+154)
#define TMPL_RCPR_BIG_SCALE (+7.458340731200206743290965E-155)

/*  Function for computing the length of three dimensional vectors.           */
double Hypot3_Double_IEEE754(double x, double y, double z)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    tmpl_IEEE754_Double wx, wy, wz;
    unsigned int max_expo;

    /*  Given P = (x, y, z), compute |x|, |y|, and |z|.                       */
    wx.r = x;
    wy.r = y;
    wz.r = z;

    /*  Compute the maximum of |x|, |y|, and |z| and store it in the double   *
     *  part of the tmpl_IEEE754_Double union w.                              */
    max_expo = TMPL_MAX3(wx.bits.expo, wy.bits.expo, wz.bits.expo);

    /*  We want to check if the exponent is less than 512, which is 0x200 in  *
     *  hexidecimal. The exponent of a double is offset by a biased. To check *
     *  if the exponent is less than 512, check if the exponent part of the   *
     *  double is less than 512 plus the bias.                                */
    if (max_expo < TMPL_DOUBLE_UBIAS + 0x200U)
    {
        /*  If the exponent is greater than -512, then all values of |x|,     *
         *  |y|, and |z| lie between 2^-512 and 2^512 meaning none of the     *
         *  values x^2, y^2, z^2 will overflow or underflow. It is possible   *
         *  the maximum of |x|, |y|, |z| has exponent slightly greater than   *
         *  -512, but the other values have exponent slightly less. To ensure *
         *  accuracy to 16 decimals, check if the exponent is greater than    *
         *  -486. If the difference in the exponents of the largest and       *
         *  second largest of |x|, |y|, and |z| is greater than 26, then to   *
         *  at least 16 decimals we have ||P|| = max(|x|, |y|, |z|). 486 is   *
         *  0x1E6 in hexidecimal.                                             */
        if (max_expo > TMPL_DOUBLE_UBIAS - 0x1E6U)
            return tmpl_Double_Sqrt(wx.r*wx.r + wy.r*wy.r + wz.r*wz.r);

        /*  Denormal values, need to normalize.                               */
        if (max_expo == 0x00U)
        {
            wx.r *= TMPL_BIG_SCALE*TMPL_DOUBLE_NORMALIZE;
            wy.r *= TMPL_BIG_SCALE*TMPL_DOUBLE_NORMALIZE;
            wz.r *= TMPL_BIG_SCALE*TMPL_DOUBLE_NORMALIZE;
            return (TMPL_RCPR_BIG_SCALE / TMPL_DOUBLE_NORMALIZE) *
                   tmpl_Double_Sqrt(wx.r*wx.r + wy.r*wy.r + wz.r*wz.r);
        }

        /*  All values of |x|, |y|, and |z| are very small. To avoid          *
         *  underflow errors, scale these values by 2^512.                    */
        wx.r *= TMPL_BIG_SCALE;
        wy.r *= TMPL_BIG_SCALE;
        wz.r *= TMPL_BIG_SCALE;

        /*  ||P|| can now be computed as 2^-512 * sqrt(x^2 + y^2 + z^2)       *
         *  without the risk of underflow. Return this.                       */
        return TMPL_RCPR_BIG_SCALE *
               tmpl_Double_Sqrt(wx.r*wx.r + wy.r*wy.r + wz.r*wz.r);
    }

    /*  All values of |x|, |y|, and |z| are very large and x^2, y^2, and      *
     *  z^2 will all overflow to infinity. Scale by 2^-512.                   */
    wx.r *= TMPL_RCPR_BIG_SCALE;
    wy.r *= TMPL_RCPR_BIG_SCALE;
    wz.r *= TMPL_RCPR_BIG_SCALE;

    /*  ||P|| can now be computed as 2^512 * sqrt(x^2 + y^2 + z^2) without    *
     *  the risk of overflow. Return this.                                    */
    return TMPL_BIG_SCALE * tmpl_Double_Sqrt(wx.r*wx.r + wy.r*wy.r + wz.r*wz.r);
}
/*  End of Hypot3_Double_IEEE754.                                             */
