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
#include "fresnel_cos.h"
#include "../cpython.h"

extern PyMODINIT_FUNC PyInit_fresnel_cos(void);

static PyObject *auxiliary(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Auxiliary;
    c_funcs.double_func = Fresnel_Cos_Double_Auxiliary;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Auxiliary;
    c_funcs.func_name = "auxiliary";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *auxiliary_less_coeffs(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Auxiliary_Less_Coeffs;
    c_funcs.double_func = Fresnel_Cos_Double_Auxiliary_Less_Coeffs;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Auxiliary_Less_Coeffs;
    c_funcs.func_name = "auxiliary_less_coeffs";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *auxiliary_alt(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Auxiliary_Alt;
    c_funcs.double_func = Fresnel_Cos_Double_Auxiliary_Alt;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Auxiliary_Alt;
    c_funcs.func_name = "auxiliary_alt";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *auxiliary_safe(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Auxiliary_Safe;
    c_funcs.double_func = Fresnel_Cos_Double_Auxiliary_Safe;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Auxiliary_Safe;
    c_funcs.func_name = "auxiliary_safe";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *auxiliary_safe_less_coeffs(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Auxiliary_Safe_Less_Coeffs;
    c_funcs.double_func = Fresnel_Cos_Double_Auxiliary_Safe_Less_Coeffs;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Auxiliary_Safe_Less_Coeffs;
    c_funcs.func_name = "auxiliary_safe_less_coeffs";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *cephes_auxiliary(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Cephes_Auxiliary;
    c_funcs.double_func = Fresnel_Cos_Double_Cephes_Auxiliary;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Cephes_Auxiliary;
    c_funcs.func_name = "cephes_auxiliary";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyObject *remez_large(PyObject *self, PyObject *args)
{
    Generic_Function c_funcs;
    c_funcs.float_func = Fresnel_Cos_Float_Remez_Large;
    c_funcs.double_func = Fresnel_Cos_Double_Remez_Large;
    c_funcs.ldouble_func = Fresnel_Cos_LDouble_Remez_Large;
    c_funcs.func_name = "remez_large";
    return Get_Func_From_C(self, args, &c_funcs);
}

static PyMethodDef fresnel_cos_methods[] =
{
    {
        "auxiliary",
        auxiliary,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {
        "auxiliary_less_coeffs",
        auxiliary_less_coeffs,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {
        "auxiliary_alt",
        auxiliary_alt,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {
        "auxiliary_safe",
        auxiliary_safe,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {
        "auxiliary_safe_less_coeffs",
        auxiliary_safe_less_coeffs,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {
        "cephes_auxiliary",
        cephes_auxiliary,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {
        "remez_large",
        remez_large,
        METH_VARARGS,
        "\rComputes C(x) using the auxililary functions.\n\r"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "fresnel",
    NULL,
    -1,
    fresnel_cos_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit_fresnel_cos(void)
{
    PyObject *m = PyModule_Create(&moduledef);
    if (!m)
        return NULL;

    import_array();
    return m;
}
