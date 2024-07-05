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
 *                                 mod4_basic                                 *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod4_basic                                                            *
 *  Purpose:                                                                  *
 *      Computes mod 4 of an integer.                                         *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 4 value of.               *
 *  Output:                                                                   *
 *      n_mod_4 (unsigned int):                                               *
 *          The input integer reduced mod 4.                                  *
 *  Method:                                                                   *
 *      Use the modulo operator "%".                                          *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 4 using the Hacker's Delight method.           */
unsigned int mod4_basic(unsigned int n)
{
    /*  Modulo is a built-in operator.                                        */
    return n % 4U;
}
/*  End of mod4_basic.                                                        */
