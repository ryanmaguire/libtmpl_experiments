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

/*  All of the tools are found here.                                          */
#include "kauffman.h"
#include "knot_data.h"

/*  Test of the Jones polynomial algorithm.                                   */
int main(void)
{
    // struct crossing crossings[2] = {{{1, 0, 2, 3}}, {{2, 1, 3, 0}}};
    struct crossing crossings[] = FIGURE_EIGHT;
    struct knot K = {sizeof(crossings) / sizeof(crossings[0]), crossings};

    /*  Compute the Jones polynomial. This is exponential in the number of    *
     *  crossings. For a very large input this will take a while. For a small *
     *  input like the figure-eight its instant.                              */
    struct laurent_polynomial out = normalized_jones(&K);

    /*  And print the result to the screen.                                   */
    print_poly(&out);
    return 0;
}
/*  End of main.                                                              */
