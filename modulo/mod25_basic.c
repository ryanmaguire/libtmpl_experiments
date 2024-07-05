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
 *                                 mod25_basic                                *
 ******************************************************************************
 *  Function:                                                                 *
 *      mod25_basic                                                           *
 *  Purpose:                                                                  *
 *      Computes mod 25 of an integer.                                        *
 *  Arguments:                                                                *
 *      n (unsigned int):                                                     *
 *          An integer, the integer we want the mod 25 value of.              *
 *  Output:                                                                   *
 *      n_mod_25 (unsigned int):                                              *
 *          The input integer reduced mod 25.                                 *
 *  Method:                                                                   *
 *      Use the modulo operator "%".                                          *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/

/*  Function prototype given here.                                            */
#include "modulo.h"

/*  Function for computing mod 25 using the Hacker's Delight method.          */
unsigned int mod25_basic(unsigned int n)
{
    /*  Modulo is a built-in operator.                                        */
    return n % 25U;
}
/*  End of mod25_basic.                                                       */
