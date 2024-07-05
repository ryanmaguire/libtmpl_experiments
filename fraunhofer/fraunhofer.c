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
 *     Old ufuncs written using the Numpy C-API. Very sloppy.                 *
 ******************************************************************************/

/*  Python header for module creation, Py objects, and the rest of the API.   */
#define PY_SSIZE_T_CLEAN
#include <Python.h>

/*  Numpy headers for both the standard C-Numpy API and the UFuncs API.       */
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/ndarraytypes.h"
#include "numpy/ufuncobject.h"

/*  The module initializer for "import fraunhofer" at the Python level.       */
extern PyMODINIT_FUNC PyInit_fraunhofer(void);

/*  libtmpl provides routines for Fraunhofer diffraction.                     */
#include <libtmpl/include/tmpl.h>

/*  Single precision Fraunhofer diffraction for a double slit.                */
static void
fraunf(char **args, const npy_intp *dims, const npy_intp* steps, void* data)
{
    /*  Variables for indexing and looping over the elements of the array.    */
    const npy_intp zero = (npy_intp)0;
    const npy_intp n_elements = dims[0];
    npy_intp n;

    /*  Extract input data and convert to appropriate types. First is the     *
     *  location on the x axis for the points in the array.                   */
    const float * const x = (const float *)args[0];

    /*  Location of the observer on the z-axis.                               */
    const float z = *(const float *)args[1];

    /*  The width of the slits.                                               */
    const float width = *(const float *)args[2];

    /*  The distance between the two slits.                                   */
    const float distance = *(const float *)args[3];

    /*  The wavelength, lambda, of the incident light.                        */
    const float lambda = *(const float *)args[4];

    /* The output is a pointer to a float, an array for the intensity.        */
    float *out = (float *)args[5];

    /*  Loop over the data and compute the diffraction pattern.               */
    for (n = zero; n < n_elements; ++n)
    {
        /*  libtmpl has the routine to compute the diffraction pattern.       */
        out[n] = tmpl_Float_Fraunhofer_Diffraction_Double_Slit(
            x[n],       /*  Location of the point of interest on the x-axis.  */
            z,          /*  Vertical distance to the observer.                */
            width,      /*  Width of the individual slits.                    */
            distance,   /*  Distance between the two slits.                   */
            lambda      /*  The wavelength of the incident light.             */
        );
    }
}
/*  End of fraunf.                                                            */

/*  Double precision Fraunhofer diffraction for a double slit.                */
static void
fraund(char **args, const npy_intp *dims, const npy_intp* steps, void* data)
{
    /*  Variables for indexing and looping over the elements of the array.    */
    const npy_intp zero = (npy_intp)0;
    const npy_intp n_elements = dims[0];
    npy_intp n;

    /*  Extract input data and convert to appropriate types. First is the     *
     *  location on the x axis for the points in the array.                   */
    const double * const x = (const double *)args[0];

    /*  Location of the observer on the z-axis.                               */
    const double z = *(const double *)args[1];

    /*  The width of the slits.                                               */
    const double width = *(const double *)args[2];

    /*  The distance between the two slits.                                   */
    const double distance = *(const double *)args[3];

    /*  The wavelength, lambda, of the incident light.                        */
    const double lambda = *(const double *)args[4];

    /* The output is a pointer to a double, an array for the intensity.       */
    double *out = (double *)args[5];

    /*  Loop over the data and compute the diffraction pattern.               */
    for (n = zero; n < n_elements; ++n)
    {
        /*  libtmpl has the routine to compute the diffraction pattern.       */
        out[n] = tmpl_Double_Fraunhofer_Diffraction_Double_Slit(
            x[n],       /*  Location of the point of interest on the x-axis.  */
            z,          /*  Vertical distance to the observer.                */
            width,      /*  Width of the individual slits.                    */
            distance,   /*  Distance between the two slits.                   */
            lambda      /*  The wavelength of the incident light.             */
        );
    }
}
/*  End of fraund.                                                            */

/*  Long double precision Fraunhofer diffraction for a double slit.           */
static void
fraunld(char **args, const npy_intp *dims, const npy_intp* steps, void* data)
{
    /*  Variables for indexing and looping over the elements of the array.    */
    const npy_intp zero = (npy_intp)0;
    const npy_intp n_elements = dims[0];
    npy_intp n;

    /*  Extract input data and convert to appropriate types. First is the     *
     *  location on the x axis for the points in the array.                   */
    const long double * const x = (const long double *)args[0];

    /*  Location of the observer on the z-axis.                               */
    const long double z = *(const long double *)args[1];

    /*  The width of the slits.                                               */
    const long double width = *(const long double *)args[2];

    /*  The distance between the two slits.                                   */
    const long double distance = *(const long double *)args[3];

    /*  The wavelength, lambda, of the incident light.                        */
    const long double lambda = *(const long double *)args[4];

    /* The output is a pointer to a double, an array for the intensity.       */
    long double *out = (long double *)args[5];

    /*  Loop over the data and compute the diffraction pattern.               */
    for (n = zero; n < n_elements; ++n)
    {
        /*  libtmpl has the routine to compute the diffraction pattern.       */
        out[n] = tmpl_LDouble_Fraunhofer_Diffraction_Double_Slit(
            x[n],       /*  Location of the point of interest on the x-axis.  */
            z,          /*  Vertical distance to the observer.                */
            width,      /*  Width of the individual slits.                    */
            distance,   /*  Distance between the two slits.                   */
            lambda      /*  The wavelength of the incident light.             */
        );
    }
}
/*  End of fraund.                                                            */

static PyMethodDef fraunhofer_methods[] = {
    {NULL, NULL, 0, NULL}
};

/*  This a pointer to the above function.                                     */
static PyUFuncGenericFunction funcs[3] = {&fraunf, &fraund, &fraunld};

/*  These are the input and return dtypes of fraunhofer.                      */
static char types[18] = {

    /*  Single precision: Five floats in, one float out.                      */
    NPY_FLOAT, NPY_FLOAT, NPY_FLOAT, NPY_FLOAT, NPY_FLOAT,
    NPY_FLOAT,

    /*  Double precision: Five doubles in, one double out.                    */
    NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE, NPY_DOUBLE,
    NPY_DOUBLE,

    /*  Long double precision: Five long doubles in, one long double out.     */
    NPY_LONGDOUBLE, NPY_LONGDOUBLE, NPY_LONGDOUBLE, NPY_LONGDOUBLE,
    NPY_LONGDOUBLE, NPY_LONGDOUBLE
};

/*  Module definition. Import via "import fraunhofer" at the Python level.    */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "fraunhofer",
    NULL,
    -1,
    fraunhofer_methods,
    NULL,
    NULL,
    NULL,
    NULL
};

/*  Function for creating the actual Python module.                           */
PyMODINIT_FUNC
PyInit_fraunhofer(void)
{
    /*  Declare necessary variables. C89 requires declarations at the top.    */
    PyObject *m, *fraunhofer, *d;

    /*  Needed for the Numpy API. Segmentation faults occurs without it.      */
    import_array();
    import_umath();

    /*  Try and create the module. This function returns NULL on failure.     */
    m = PyModule_Create(&moduledef);

    /*  Check if PyModule_Create failed.                                      */
    if (!m)
        return NULL;

    fraunhofer = PyUFunc_FromFuncAndData(
        funcs,          /*  Function pointers for the loop functions.         */
        NULL,           /*  Data pointer. Not needed, set to NULL.            */
        types,          /*  Input-Output types for the functions.             */
        3,              /*  The number of function types.                     */
        5,              /*  The number of inputs.                             */
        1,              /*  The number of outputs.                            */
        PyUFunc_None,   /*  Return type for an empty-array input.             */
        "fraunhofer",   /*  Name of the function.                             */
        "docstring",    /*  Docstring for the function at the Python level.   */
        0               /*  Junk for backwards compatibility with API.        */
    );

    d = PyModule_GetDict(m);
    PyDict_SetItemString(d, "fraunhofer", fraunhofer);
    Py_DECREF(fraunhofer);
    return m;
}
