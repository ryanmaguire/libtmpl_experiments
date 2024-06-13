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
 *      Provides helper functions for using the C-Python / C-Numpy APIs.      *
 ******************************************************************************/

/*  Include guard to prevent including this file twice.                       */
#ifndef TMPL_EXPERIMENTS_CPYTHON_H
#define TMPL_EXPERIMENTS_CPYTHON_H

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>
#include <numpy/ndarraytypes.h>
#include <numpy/ufuncobject.h>
#include <libtmpl/include/tmpl.h>

typedef struct Generic_Function_Obj {
    float (*float_func)(float);
    double (*double_func)(double);
    long double (*ldouble_func)(long double);
    const char *func_name;
} Generic_Function;

static void Capsule_Cleanup(PyObject *capsule)
{
    void *memory = PyCapsule_GetPointer(capsule, NULL);
    free(memory);
}

static PyObject *Get_Out_From_Array(PyObject *x, Generic_Function *c_func)
{
    unsigned long int n, dim;
    npy_intp np_dim;
    long int signed_dim;
    void *data, *out;
    double *temp;
    int typenum;
    PyObject *capsule, *output;
    PyArrayObject *x_as_arr = (PyArrayObject *)x;

    if (PyArray_NDIM(x_as_arr) != 1)
    {
        PyErr_Format(
            PyExc_RuntimeError,
            "\n\rError Encountered: tmpl_experiments\n"
            "\r\tFunction Name: %s\n\n"
            "\n\rInput is not 1-dimensional.\n",
            c_func->func_name
        );

        return NULL;
    }

    typenum = PyArray_TYPE(x_as_arr);
    np_dim = PyArray_DIM(x_as_arr, 0);
    data = PyArray_DATA(x_as_arr);

    if (np_dim < 0)
        goto FAILURE;

    dim = (unsigned long int)np_dim;
    if (dim == 0)
    {
        PyErr_Format(
            PyExc_RuntimeError,
            "\n\rError Encountered: tmpl_experiments\n"
            "\r\tFunction Name: %s\n\n"
            "\n\n\rInput numpy array is empty.\n",
            c_func->func_name
        );

        return NULL;
    }

    switch (typenum)
    {
        case NPY_FLOAT:
            out = malloc(sizeof(float) * dim);

            if (out == NULL)
                goto MALLOC_FAILURE;

            tmpl_get_void_from_void_f2f(data, out, dim, c_func->float_func);
            break;

        case NPY_DOUBLE:
            out = malloc(sizeof(double) * dim);

            if (out == NULL)
                goto MALLOC_FAILURE;

            tmpl_get_void_from_void_d2d(data, out, dim, c_func->double_func);
            break;

        case NPY_LONGDOUBLE:
            out = malloc(sizeof(long double) * dim);

            if (out == NULL)
                goto MALLOC_FAILURE;

            tmpl_get_void_from_void_ld2ld(data, out, dim, c_func->ldouble_func);
            break;

        case NPY_LONG:
            temp = malloc(sizeof(*temp) * dim);

            if (!temp)
                goto MALLOC_FAILURE;

            typenum = NPY_DOUBLE;
            out = malloc(sizeof(double) * dim);

            if (!out)
            {
                free(temp);
                goto MALLOC_FAILURE;
            }

            /*  Loop through the data and cast to double.                     */
            for (n = 0UL; n < dim; ++n)
                temp[n] = (double)(((long *)data)[n]);

            tmpl_get_void_from_void_d2d(temp, out, dim, c_func->double_func);
            free(temp);
            break;

        default:
            goto FAILURE;
    }

    signed_dim = (long int)dim;
    output = PyArray_SimpleNewFromData(1, &signed_dim, typenum, out);
    capsule = PyCapsule_New(out, NULL, Capsule_Cleanup);
    PyArray_SetBaseObject((PyArrayObject *)output, capsule);
    return Py_BuildValue("N", output);

FAILURE:
    PyErr_Format(
        PyExc_RuntimeError,
        "\n\rError Encountered: tmpl_experiments\n"
        "\r\tFunction Name: %s\n\n"
        "\rCould not parse inputs.\n",
        c_func->func_name
    );

    return NULL;

MALLOC_FAILURE:
    PyErr_Format(
        PyExc_RuntimeError,
        "\n\rError Encountered: tmpl_experiments\n"
        "\r\tFunction Name: %s\n\n"
        "\rmalloc failed to allocate memory. Aborting.\n",
        c_func->func_name
    );

    return NULL;
}

static PyObject *Get_Out_From_Long(PyObject *x, Generic_Function *c_func)
{
    const double x_val = PyLong_AsDouble(x);
    const double y_val = c_func->double_func(x_val);
    return PyFloat_FromDouble(y_val);
}

static PyObject *Get_Out_From_Float(PyObject *x, Generic_Function *c_func)
{
    const double x_val = PyFloat_AsDouble(x);
    const double y_val = c_func->double_func(x_val);
    return PyFloat_FromDouble(y_val);
}


static PyObject *Get_Out_From_List(PyObject *x, Generic_Function *c_func)
{
    PyObject *nth_item;
    PyObject *current_item;
    long int dim = PyList_Size(x);
    PyObject *output = PyList_New(dim);
    long int n;

    for (n = 0; n < dim; ++n)
    {
        nth_item = PyList_GetItem(x, n);

        if (PyLong_Check(nth_item))
            current_item = Get_Out_From_Long(nth_item, c_func);
        else if (PyFloat_Check(nth_item))
            current_item = Get_Out_From_Float(nth_item, c_func);
        else
        {
            PyErr_Format(
                PyExc_RuntimeError,
                "\n\rError Encountered: tmpl_experiments\n"
                "\r\tFunction Name: %s\n\n"
                "\rInput list must contain real numbers only.\n\r",
                c_func->func_name
            );

            return NULL;
        }

        PyList_SET_ITEM(output, n, current_item);
    }

    return output;
}

static PyObject *
Get_Func_From_C(PyObject *self, PyObject *args, Generic_Function *c_func)
{
    PyObject *x;

    if (!PyArg_ParseTuple(args, "O", &x))
        goto FAILURE;

    if (PyLong_Check(x))
        return Get_Out_From_Long(x, c_func);
    else if (PyFloat_Check(x))
        return Get_Out_From_Float(x, c_func);
    else if (PyList_Check(x))
        return Get_Out_From_List(x, c_func);
    else if (PyArray_Check(x))
        return Get_Out_From_Array(x, c_func);

FAILURE:
    PyErr_Format(
        PyExc_RuntimeError,
        "\n\rError Encountered: tmpl_experiments\n"
        "\r\tFunction Name: %s\n\n"
        "\rCould not parse inputs.\n",
        c_func->func_name
    );

    return NULL;
}

#endif
/*  End of include guard.                                                     */
