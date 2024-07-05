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
#include <stdlib.h>
#include <stdio.h>

static size_t *
WhereGreater(const double * const data,
			 const size_t dim,
			 const double threshold,
			 size_t * const where_dim)
{
	const size_t zero = (size_t)0;
	size_t index;
	size_t *where;
	void *tmp;

	if (!where_dim)
		return NULL;

	*where_dim = zero;
	where = malloc(sizeof(*where) * dim);

	if (!where)
		return NULL;

    for (index = zero; index < dim; ++index)
	{
        if (data[index] > threshold)
		{
        	where[*where_dim] = index;
            ++(*where_dim);
        }
    }

	tmp = realloc(where, sizeof(*where) * (*where_dim));

	if (tmp)
		where = tmp;
	return where;
}

int main()
{
	const double threshold = 18.0;
	const size_t dim = (size_t)24;
	const size_t zero = (size_t)0;
	size_t index;
	size_t *where = NULL;
	size_t where_dim = zero;

	double * const ptr = malloc(sizeof(*ptr) * dim);

	for (index = zero; index < dim; ++index)
		ptr[index] = (double)index;

	where = WhereGreater(ptr, dim, threshold, &where_dim);

	if (!where)
	{
		puts("WhereGreater returned NULL for where. Aborting.");
		free(ptr);
		return -1;
	}

	for (index = zero; index < where_dim; ++index)
		printf("%zu: %zu\n", index, where[index]);

	free(where);
	free(ptr);
	return 0;
}
