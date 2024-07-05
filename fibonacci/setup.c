/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  This file is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with this file.  If not, see <https://www.gnu.org/licenses/>.       *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Simple example of using the C-Python API for extension modules.       *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/
#include "fibonacci.h"
#include "../cpython.h"

/*  This is the function that initializes the Python module.                  */
extern PyMODINIT_FUNC PyInit_fibonacci(void);

/*  Create Python wrappers for all of the functions.                          */
TMPL_EXPERIMENTS_INTEGER_FUNCTION(fibonacci_iterative, iterative)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(fibonacci_power_law, power_law)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(fibonacci_power_law_naive, power_law_naive)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(fibonacci_recursive, recursive)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(fibonacci_table, table)

/*  All functions available in the Python module.                             */
static PyMethodDef FibonacciMethods[] = {
    {
        "iterative",
        iterative,
        METH_VARARGS,
        "Computes the nth Fibonacci number using an iterative sum."
    },
    {
        "power_law",
        power_law,
        METH_VARARGS,
        "Computes the nth Fibonacci number using the power-law solution to"
        "the difference equation and some tools from libm."
    },
    {
        "power_law_naive",
        power_law_naive,
        METH_VARARGS,
        "Computes the nth Fibonacci number using the power-law solution to"
        "the difference equation. Powers are naively computed."
    },
    {
        "recursive",
        recursive,
        METH_VARARGS,
        "Computes the nth Fibonacci number using the recursive definition."
    },
    {
        "table",
        table,
        METH_VARARGS,
        "Computes the nth Fibonacci number using a precomputed table."
    },

    /*  End of array element. All entries have their zero values.             */
    {NULL, NULL, 0, NULL}
};

/*  The struct representing the Python module. You can import it at the       *
 *  python level via "import fibonacci".                                      */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "fibonacci",
    NULL,
    -1,
    FibonacciMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

/*  And lastly, the function that creates the Python module.                  */
PyMODINIT_FUNC
PyInit_fibonacci(void)
{
    return PyModule_Create(&moduledef);
}
