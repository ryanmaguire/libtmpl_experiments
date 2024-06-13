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
#include "arccos.h"
#include "../cpython.h"

static PyObject *maclaurin(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arccos_Float_Maclaurin;
    c_funcs.double_func = Arccos_Double_Maclaurin;
    c_funcs.ldouble_func = Arccos_LDouble_Maclaurin;
    c_funcs.func_name = "maclaurin";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *pade(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arccos_Float_Pade;
    c_funcs.double_func = Arccos_Double_Pade;
    c_funcs.ldouble_func = Arccos_LDouble_Pade;
    c_funcs.func_name = "pade";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *rat_remez(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arccos_Float_Rat_Remez;
    c_funcs.double_func = Arccos_Double_Rat_Remez;
    c_funcs.ldouble_func = Arccos_LDouble_Rat_Remez;
    c_funcs.func_name = "rat_remez";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *tail_end(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Arccos_Float_Tail_End;
    c_funcs.double_func = Arccos_Double_Tail_End;
    c_funcs.ldouble_func = Arccos_LDouble_Tail_End;
    c_funcs.func_name = "tail_end";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyMethodDef arccos_methods[] =
{
    {
        "maclaurin",
        maclaurin,
        METH_VARARGS,
        "\rComputes arccos(x) using a Maclaurin series.\n\r"
    },
    {
        "pade",
        pade,
        METH_VARARGS,
        "\rComputes arccos(x) using a Pade approximant.\n\r"
    },
    {
        "rat_remez",
        rat_remez,
        METH_VARARGS,
        "\rComputes arccos(x) using a rational Remez approximation.\n\r"
    },
    {
        "tail_end",
        tail_end,
        METH_VARARGS,
        "\rComputes arccos(x) using the reflection formula.\n\r"
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
    "arccos",
    NULL,
    -1,
    arccos_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_arccos(void)
{
    PyObject *m = PyModule_Create(&moduledef);

    if (!m)
        return NULL;

    import_array();
    return m;
}
