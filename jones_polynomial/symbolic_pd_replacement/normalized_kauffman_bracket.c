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
#include <stdlib.h>

struct laurent_polynomial normalized_kauffman_bracket(const struct knot *K)
{
    unsigned int n, weight, n_circles;
    const unsigned int number_of_resolutions = 1U << K->number_of_crossings;
    signed int data[MAX_POLY_SIZE];
    struct affine_term *terms = get_affine_terms(K);

    for (n = 0U; n < MAX_POLY_SIZE; ++n)
        data[n] = 0U;

    for (n = 0; n < number_of_resolutions; ++n)
    {
        weight = hamming_weight(n);
        n_circles = circle_count(terms, K->number_of_crossings, n);
        add_normalized_kauffman_summand(n_circles, weight, DEGREE_SHIFT, data);
    }

    free(terms);
    return kauffman_bracket_from_data(data);
}
