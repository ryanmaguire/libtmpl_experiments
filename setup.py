"""
################################################################################
#                                   LICENSE                                    #
################################################################################
#   This file is part of libtmpl_experiments.                                  #
#                                                                              #
#   libtmpl_experiments is free software: you can redistribute it and/or       #
#   modify it under the terms of the GNU General Public License as published   #
#   by the Free Software Foundation, either version 3 of the License, or       #
#   (at your option) any later version.                                        #
#                                                                              #
#   libtmpl_experiments is distributed in the hope that it will be useful,     #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              #
#   GNU General Public License for more details.                               #
#                                                                              #
#   You should have received a copy of the GNU General Public License along    #
#   with libtmpl_experiments.  If not, see <https://www.gnu.org/licenses/>.    #
################################################################################
"""
import os
import setuptools
import numpy

compile_args = [
    "-pedantic",
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "-Wmissing-field-initializers",
    "-Wconversion",
    "-Wmissing-prototypes",
    "-Wmissing-declarations",
    "-Winit-self",
    "-Wnull-dereference",
    "-Wwrite-strings",
    "-Wdouble-promotion",
    "-Wfloat-conversion",
    "-Wstrict-prototypes",
    "-Wold-style-definition"
]

directories = [
    "arccos",
    "arcsin",
    "besseli0",
    "erf",
    "fibonacci",
    "fresnel_cos",
    "fresnel_sin",
    "fraunhofer",
    "modulo"
]

def get_c_files(directory):
    """
        Returns a list of all C files in a given
        directory. This can be passed on to the
        setuptools functions for creating modules.
    """
    c_list = []
    directory_copy = directory
    if directory_copy[-1] != "/":
        directory_copy += "/"

    for file in os.listdir(directory_copy):
        if file[-1] == "c":
            c_list.append(directory_copy + file)

    return c_list

setuptools.setup(
    name = "tmpl_experiments",
    version = "0.1",
    description = "Experimental routines from libtmpl",
    author = "Ryan Maguire",
    ext_package = "tmpl_experiments",
    ext_modules = [
        setuptools.Extension(
            directory,
            get_c_files(directory),
            include_dirs = [numpy.get_include()],
            libraries = ["tmpl"],
            extra_compile_args = compile_args
        ) for directory in directories
    ]
)
