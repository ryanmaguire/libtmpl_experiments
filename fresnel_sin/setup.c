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
#include "fresnel_sin.h"
#include "../cpython.h"

extern PyMODINIT_FUNC PyInit_fresnel_sin(void);

static PyObject *heald_three(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Sin_Float_Heald_Three;
    c_funcs.double_func = Fresnel_Sin_Double_Heald_Three;
    c_funcs.ldouble_func = Fresnel_Sin_LDouble_Heald_Three;
    c_funcs.func_name = "heald_three";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *heald_four(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Sin_Float_Heald_Four;
    c_funcs.double_func = Fresnel_Sin_Double_Heald_Four;
    c_funcs.ldouble_func = Fresnel_Sin_LDouble_Heald_Four;
    c_funcs.func_name = "heald_four";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *heald_six(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Sin_Float_Heald_Six;
    c_funcs.double_func = Fresnel_Sin_Double_Heald_Six;
    c_funcs.ldouble_func = Fresnel_Sin_LDouble_Heald_Six;
    c_funcs.func_name = "heald_six";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *heald_eight(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Sin_Float_Heald_Eight;
    c_funcs.double_func = Fresnel_Sin_Double_Heald_Eight;
    c_funcs.ldouble_func = Fresnel_Sin_LDouble_Heald_Eight;
    c_funcs.func_name = "heald_eight";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyMethodDef fresnel_sin_methods[] =
{
    {
        "heald_three",
        heald_three,
        METH_VARARGS,
        "\rComputes S(x) using the Heald approximation.\n\r"
    },
    {
        "heald_four",
        heald_four,
        METH_VARARGS,
        "\rComputes S(x) using the Heald approximation.\n\r"
    },
    {
        "heald_six",
        heald_six,
        METH_VARARGS,
        "\rComputes S(x) using the Heald approximation.\n\r"
    },
    {
        "heald_eight",
        heald_eight,
        METH_VARARGS,
        "\rComputes S(x) using the Heald approximation.\n\r"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "fresnel",
    NULL,
    -1,
    fresnel_sin_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_fresnel_sin(void)
{
    PyObject *m = PyModule_Create(&moduledef);
    if (!m)
        return NULL;

    import_array();
    return m;
}
