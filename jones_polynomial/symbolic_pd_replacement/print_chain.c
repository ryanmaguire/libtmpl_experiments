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

void print_chain(const struct chain *c)
{
    if (!c)
    {
        printf("\n");
        return;
    }

    while (1)
    {
        /*  If this is not the last element, print spaces.                    */
        if (c->next)
        {
            printf("(%u, %u) ", c->current->dat[0], c->current->dat[1]);
            c = c->next;
        }

        /*  Otherwise print a newline.                                        */
        else
        {
            printf("(%u, %u)\n", c->current->dat[0], c->current->dat[1]);
            return;
        }
    }
}
