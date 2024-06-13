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
#include "error_function.h"
#include "../cpython.h"

static PyObject *abramowitz_and_stegun(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Abramowitz_and_Stegun;
    c_funcs.double_func = Erf_Double_Abramowitz_and_Stegun;
    c_funcs.ldouble_func = Erf_LDouble_Abramowitz_and_Stegun;
    c_funcs.func_name = "abramowitz_and_stegun";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *abramowitz_and_stegun_rational(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Abramowitz_and_Stegun_Rational;
    c_funcs.double_func = Erf_Double_Abramowitz_and_Stegun_Rational;
    c_funcs.ldouble_func = Erf_LDouble_Abramowitz_and_Stegun_Rational;
    c_funcs.func_name = "abramowitz_and_stegun_rational";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *chebyshev(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Chebyshev;
    c_funcs.double_func = Erf_Double_Chebyshev;
    c_funcs.ldouble_func = Erf_LDouble_Chebyshev;
    c_funcs.func_name = "chebyshev";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *karagiannidis_and_lioumpas(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Karagiannidis_and_Lioumpas;
    c_funcs.double_func = Erf_Double_Karagiannidis_and_Lioumpas;
    c_funcs.ldouble_func = Erf_LDouble_Karagiannidis_and_Lioumpas;
    c_funcs.func_name = "karagiannidis_and_lioumpas";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *error_function(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = tmpl_Float_Erf;
    c_funcs.double_func = tmpl_Double_Erf;
    c_funcs.ldouble_func = tmpl_LDouble_Erf;
    c_funcs.func_name = "erf";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *numerical_recipes(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Numerical_Recipes;
    c_funcs.double_func = Erf_Double_Numerical_Recipes;
    c_funcs.ldouble_func = Erf_LDouble_Numerical_Recipes;
    c_funcs.func_name = "numerical_recipes";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *pade(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Pade;
    c_funcs.double_func = Erf_Double_Pade;
    c_funcs.ldouble_func = Erf_LDouble_Pade;
    c_funcs.func_name = "pade";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *rat_remez(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Rat_Remez;
    c_funcs.double_func = Erf_Double_Rat_Remez;
    c_funcs.ldouble_func = Erf_LDouble_Rat_Remez;
    c_funcs.func_name = "rat_remez";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *rat_remez_small(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Rat_Remez_Small;
    c_funcs.double_func = Erf_Double_Rat_Remez_Small;
    c_funcs.ldouble_func = Erf_LDouble_Rat_Remez_Small;
    c_funcs.func_name = "rat_remez_small";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *sun(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Sun;
    c_funcs.double_func = Erf_Double_Sun;
    c_funcs.ldouble_func = Erf_LDouble_Sun;
    c_funcs.func_name = "sun";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *winitzki(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Erf_Float_Winitzki;
    c_funcs.double_func = Erf_Double_Winitzki;
    c_funcs.ldouble_func = Erf_LDouble_Winitzki;
    c_funcs.func_name = "winitzki";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyMethodDef erf_methods[] =
{
    {
        "abramowitz_and_stegun",
        abramowitz_and_stegun,
        METH_VARARGS,
        "\rComputes erf(x) using the exponential approximation in A&S.\n\r"
    },
    {
        "abramowitz_and_stegun_rational",
        abramowitz_and_stegun_rational,
        METH_VARARGS,
        "\rComputes erf(x) using the rational approximation in A&S.\n\r"
    },
    {
        "chebyshev",
        chebyshev,
        METH_VARARGS,
        "\rComputes erf(x) using a Chebyshev polynomial.\n\r"
    },
    {
        "karagiannidis_and_lioumpas",
        karagiannidis_and_lioumpas,
        METH_VARARGS,
        "\rComputes erf(x) using the approximation in K&L.\n\r"
    },
    {
        "erf",
        error_function,
        METH_VARARGS,
        "\rComputes erf(x) using libtmpl.\n\r"
    },
    {
        "numerical_recipes",
        numerical_recipes,
        METH_VARARGS,
        "\rComputes erf(x) using the algorithm in Numerical Recipes.\n\r"
    },
    {
        "pade",
        pade,
        METH_VARARGS,
        "\rComputes erf(x) using a Pade approximant.\n\r"
    },
    {
        "rat_remez",
        rat_remez,
        METH_VARARGS,
        "\rComputes erf(x) using a rational Remez approximation.\n\r"
    },
    {
        "rat_remez_small",
        rat_remez_small,
        METH_VARARGS,
        "\rComputes erf(x) using a rational Remez approximation.\n\r"
    },
    {
        "sun",
        sun,
        METH_VARARGS,
        "\rComputes erf(x) using the algorithm in Sun's libm.\n\r"
    },
    {
        "winitzki",
        winitzki,
        METH_VARARGS,
        "\rComputes erf(x) using Winitzki's approximation.\n\r"
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
    "erf",
    NULL,
    -1,
    erf_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_erf(void)
{
    PyObject *m = PyModule_Create(&moduledef);
    if (!m)
        return NULL;

    import_array();
    return m;
}
