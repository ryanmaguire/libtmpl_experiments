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
#include <stddef.h>
#include <stdio.h>
#include "kauffman.h"

static unsigned char have_visited[4U * MAX_CROSSINGS];

unsigned int
circle_count(const struct knot *K,
             const struct crossing_indices *ind,
             unsigned int resolution)
{
    unsigned int number_of_circles, n, k, m, residual;
    unsigned char dir, crossing_resolution;

    /*  The direction is stored as an unsigned char. There are two            *
     *  possibilities: forwards and backwards.                                */
    const unsigned char backward = 0x00U;
    const unsigned char forward = 0x01U;

    /*  The empty knot has zero circles.                                      */
    if (!K)
        return 0U;

    /*  The unknot has 1 circle.                                              */
    if (K->number_of_crossings == 0U)
        return 1U;

    /*  If ind is a NULL pointer, there's nothing that can be done.           */
    if (!ind)
        return 0U;

    for (n = 0U; n < 4U * K->number_of_crossings; ++n)
        have_visited[n] = 0x00U;

    /*  Initialize number_of_circles to zero.                                 */
    number_of_circles = 0U;

    for (n = 0U; n < 2U*K->number_of_crossings; ++n)
    {
        k = 4U*K->crossing_number[n];

        /*  Each crossing has four entrances. Bottom left, bottom right, top  *
         *  left, top right. Check which one's we have visited.               */
        for (residual = 0U; residual < 3; ++residual)
        {
            if (!have_visited[k])
                break;
            else
                ++k;
        }

        if (have_visited[k])
            continue;

        if (residual < 2U)
            dir = forward;
        else
            dir = backward;

        m = n;

        while (!have_visited[k])
        {
            crossing_resolution = (resolution >> K->crossing_number[m]) & 0x01U;
            have_visited[k] = 0x01U;

            if (K->sign[m] == positive_crossing)
            {
                if (K->type[m] == over_crossing)
                {
                    if (crossing_resolution == 0x00U)
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m] + 3U;
                        else
                            k = 4U*K->crossing_number[m] + 1U;
                    }
                    else
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m] + 1U;
                        else
                            k = 4U*K->crossing_number[m] + 3U;

                        dir = 0x01U - dir;
                    }
                    m = ind[K->crossing_number[m]].under;
                }
                else
                {
                    if (crossing_resolution == 0x00U)
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m] + 2U;
                        else
                            k = 4U*K->crossing_number[m];
                    }
                    else
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m];
                        else
                            k = 4U*K->crossing_number[m] + 2U;

                        dir = 0x01U - dir;
                    }
                    m = ind[K->crossing_number[m]].over;
                }
            }

            /*  Negative sign for the crossing.                               */
            else
            {
                if (K->type[m] == over_crossing)
                {
                    if (crossing_resolution == 0x00U)
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m];
                        else
                            k = 4U*K->crossing_number[m] + 2U;

                        dir = 0x01U - dir;
                    }

                    else
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m] + 2U;
                        else
                            k = 4U*K->crossing_number[m];
                    }

                    m = ind[K->crossing_number[m]].under;
                }
                else
                {
                    if (crossing_resolution == 0x00U)
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m] + 1U;
                        else
                            k = 4U*K->crossing_number[m] + 3U;

                        dir = 0x01U - dir;
                    }

                    else
                    {
                        if (dir == forward)
                            k = 4U*K->crossing_number[m] + 3U;
                        else
                            k = 4U*K->crossing_number[m] + 1U;
                    }

                    m = ind[K->crossing_number[m]].over;
                }
            }

            if (dir == forward)
            {
                if (m == 2U*K->number_of_crossings - 1U)
                    m = 0U;
                else
                    ++m;
            }
            else
            {
                if (m == 0U)
                    m = 2U*K->number_of_crossings - 1U;
                else
                    --m;
            }

            have_visited[k] = 0x01U;

            k = 4U*K->crossing_number[m];

            if (K->sign[m] == positive_crossing)
            {
                if (K->type[m] == over_crossing)
                {
                    if (dir == backward)
                        k += 2U;
                }
                else
                {
                    if (dir == forward)
                        k += 1U;
                    else
                        k += 3U;
                }
            }

            else
            {
                if (K->type[m] == over_crossing)
                {
                    if (dir == forward)
                        k += 1U;
                    else
                        k += 3U;
                }
                else
                {
                    if (dir == backward)
                        k += 2U;
                }
            }
        }

        ++number_of_circles;
    }

    return number_of_circles;
}
