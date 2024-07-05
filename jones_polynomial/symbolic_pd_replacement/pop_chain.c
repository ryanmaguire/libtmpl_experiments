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
#include <stddef.h>

void pop_chain(struct chain *c)
{
    struct chain *previous, *next;

    if (!c)
        return;

    previous = c->previous;
    next = c->next;

    if (!next)
    {
        if (previous)
            previous->next = NULL;

        return;
    }

    if (!previous)
    {
        if (next)
            next->previous = NULL;

        return;
    }

    previous->next = next;
    next->previous = previous;
}
