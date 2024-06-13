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
#include "bessel_i0.h"
#include "../cpython.h"

static PyObject *asymptotic(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = I0_Float_Asymptotic;
    c_funcs.double_func = I0_Double_Asymptotic;
    c_funcs.ldouble_func = I0_LDouble_Asymptotic;
    c_funcs.func_name = "asymptotic";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *chebyshev(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = I0_Float_Chebyshev;
    c_funcs.double_func = I0_Double_Chebyshev;
    c_funcs.ldouble_func = I0_LDouble_Chebyshev;
    c_funcs.func_name = "chebyshev";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *holoborodko(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = I0_Float_Holoborodko;
    c_funcs.double_func = I0_Double_Holoborodko;
    c_funcs.ldouble_func = I0_LDouble_Holoborodko;
    c_funcs.func_name = "holoborodko";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *i0(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = tmpl_Float_Bessel_I0;
    c_funcs.double_func = tmpl_Double_Bessel_I0;
    c_funcs.ldouble_func = tmpl_LDouble_Bessel_I0;
    c_funcs.func_name = "i0";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *maclaurin(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = I0_Float_Maclaurin;
    c_funcs.double_func = I0_Double_Maclaurin;
    c_funcs.ldouble_func = I0_LDouble_Maclaurin;
    c_funcs.func_name = "maclaurin";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *remez(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = I0_Float_Remez;
    c_funcs.double_func = I0_Double_Remez;
    c_funcs.ldouble_func = I0_LDouble_Remez;
    c_funcs.func_name = "remez";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *very_large(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = I0_Float_Very_Large;
    c_funcs.double_func = I0_Double_Very_Large;
    c_funcs.ldouble_func = I0_LDouble_Very_Large;
    c_funcs.func_name = "very_large";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyMethodDef i0_methods[] =
{
    {
        "asymptotic", asymptotic, METH_VARARGS,
        "\rComputes I0(x) using the asymptotic expansion.\n\r"
    },
    {
        "chebyshev", chebyshev, METH_VARARGS,
        "\rComputes I0(x) using a chebyshev expansion.\n\r"
    },
    {
        "holoborodko", holoborodko, METH_VARARGS,
        "\rComputes I0(x) using a Holoborodko's Remez expansion.\n\r"
    },
    {
        "i0", i0, METH_VARARGS,
        "\rComputes I0(x) using libtmpl.\n\r"
    },
    {
        "maclaurin", maclaurin, METH_VARARGS,
        "\rComputes I0(x) using a Maclaurin expansion.\n\r"
    },
    {
        "remez", remez, METH_VARARGS,
        "\rComputes I0(x) using a Remez polynomial.\n\r"
    },
    {
        "very_large", very_large, METH_VARARGS,
        "\rComputes I0(x) using the asymptotic expansion for large values.\n\r"
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
    "besseli0",
    NULL,
    -1,
    i0_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_besseli0(void)
{
    PyObject *m = PyModule_Create(&moduledef);
    if (!m)
        return NULL;

    import_array();
    return m;
}
