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
 *  Purpose:                                                                  *
 *      Simple example of using the C-Python API for extension modules.       *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       May 3, 2022                                                   *
 ******************************************************************************/
#include "modulo.h"
#include "../cpython.h"

/*  Create Python wrappers for all of the functions.                          */
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod4, pymod4)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod4_basic, pymod4_basic)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod4_bit, pymod4_bit)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod4_shift, pymod4_shift)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod4_slow, pymod4_slow)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod25, pymod25)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod25_basic, pymod25_basic)
TMPL_EXPERIMENTS_INTEGER_FUNCTION(mod25_slow, pymod25_slow)

/*  All functions available in the Python module.                             */
static PyMethodDef ModuloMethods[] = {
    {
        "mod4",
        pymod4,
        METH_VARARGS,
        "Computes mod 4 of an integer using tricks in Hacker's Delight."
    },
    {
        "mod4_basic",
        pymod4_basic,
        METH_VARARGS,
        "Computes mod 4 of an integer using the \% operator."
    },
    {
        "mod4_bit",
        pymod4_bit,
        METH_VARARGS,
        "Computes mod 4 of an integer using the bit-wise-and method."
    },
    {
        "mod4_shift",
        pymod4_shift,
        METH_VARARGS,
        "Computes mod 4 of an integer using the bit-shifting trick."
    },
    {
        "mod4_slow",
        pymod4_slow,
        METH_VARARGS,
        "Computes mod 4 of an integer using the by-hand method."
    },
    {
        "mod25",
        pymod25,
        METH_VARARGS,
        "Computes mod 25 of an integer using tricks in Hacker's Delight."
    },
    {
        "mod25_basic",
        pymod25_basic,
        METH_VARARGS,
        "Computes mod 25 of an integer using the \% operator."
    },
    {
        "mod25_slow",
        pymod25_slow,
        METH_VARARGS,
        "Computes mod 25 of an integer using the by-hand method."
    },

    /*  End of array element. All entries have their zero values.             */
    {NULL, NULL, 0, NULL}
};

/*  The struct representing the Python module. You can import it at the       *
 *  python level via "import modulo".                                         */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "modulo",
    NULL,
    -1,
    ModuloMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

/*  And lastly, the function that creates the Python module.                  */
PyMODINIT_FUNC
PyInit_modulo(void)
{
    return PyModule_Create(&moduledef);
}
