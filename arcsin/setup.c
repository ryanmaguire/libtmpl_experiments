/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of error_function.                                      *
 *                                                                            *
 *  error_function is free software: you can redistribute it and/or modify    *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  error_function is distributed in the hope that it will be useful,         *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with error_function.  If not, see <https://www.gnu.org/licenses/>.  *
 ******************************************************************************/
#include "arcsin.h"
#include "../cpython.h"

static PyObject *maclaurin(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arcsin_Float_Maclaurin;
    c_funcs.double_func = Arcsin_Double_Maclaurin;
    c_funcs.ldouble_func = Arcsin_LDouble_Maclaurin;
    c_funcs.func_name = "maclaurin";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *pade(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arcsin_Float_Pade;
    c_funcs.double_func = Arcsin_Double_Pade;
    c_funcs.ldouble_func = Arcsin_LDouble_Pade;
    c_funcs.func_name = "pade";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *rat_remez(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arcsin_Float_Rat_Remez;
    c_funcs.double_func = Arcsin_Double_Rat_Remez;
    c_funcs.ldouble_func = Arcsin_LDouble_Rat_Remez;
    c_funcs.func_name = "rat_remez";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *tail_end(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arcsin_Float_Tail_End;
    c_funcs.double_func = Arcsin_Double_Tail_End;
    c_funcs.ldouble_func = Arcsin_LDouble_Tail_End;
    c_funcs.func_name = "tail_end";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyMethodDef arcsin_methods[] =
{
    {
        "maclaurin",
        maclaurin,
        METH_VARARGS,
        "\rComputes arcsin(x) using a Maclaurin series.\n\r"
    },
    {
        "pade",
        pade,
        METH_VARARGS,
        "\rComputes arcsin(x) using a Pade approximant.\n\r"
    },
    {
        "rat_remez",
        rat_remez,
        METH_VARARGS,
        "\rComputes arcsin(x) using a rational Remez approximation.\n\r"
    },
    {
        "tail_end",
        tail_end,
        METH_VARARGS,
        "\rComputes arcsin(x) using the reflection formula.\n\r"
    },
    {
        NULL,
        NULL,
        0,
        NULL
    }
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "arcsin",
    NULL,
    -1,
    arcsin_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_arcsin(void)
{
    PyObject *m = PyModule_Create(&moduledef);

    if (!m)
        return NULL;

    import_array();
    return m;
}
