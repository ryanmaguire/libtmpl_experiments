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
#include "kauffman.h"
#include <stdio.h>

void print_knot(const struct knot *K)
{
    unsigned int n;

    if (!K)
        printf("\n");

    for (n = 0U; n < K->number_of_crossings; ++n)
        printf("X[%u, %u, %u, %u] ",
               K->index[n].dat[0],
               K->index[n].dat[1],
               K->index[n].dat[2],
               K->index[n].dat[3]);

    printf("\n");
}
