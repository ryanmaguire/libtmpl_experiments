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

arccos_list = []
arcsin_list = []
i0_list = []
erf_list = []
fresnel_cos_list = []

for file in os.listdir("arccos/"):
    if file[-1] == "c":
        arccos_list.append("arccos/" + file)

for file in os.listdir("arcsin/"):
    if file[-1] == "c":
        arcsin_list.append("arcsin/" + file)

for file in os.listdir("besseli0/"):
    if file[-1] == "c":
        i0_list.append("besseli0/" + file)

for file in os.listdir("error_function/"):
    if file[-1] == "c":
        erf_list.append("error_function/" + file)

for file in os.listdir("fresnel_cos/"):
    if file[-1] == "c":
        fresnel_cos_list.append("fresnel_cos/" + file)

setuptools.setup(
    name = "tmpl_experiments",
    version = "0.1",
    description = "Experimental routines from libtmpl",
    author = "Ryan Maguire",
    ext_package = "tmpl_experiments",
    ext_modules = [
        setuptools.Extension(
            "arccos",
            arccos_list,
            include_dirs = [numpy.get_include()],
            libraries = ["tmpl"],
            extra_compile_args = compile_args
        ),
        setuptools.Extension(
            "arcsin",
            arcsin_list,
            include_dirs = [numpy.get_include()],
            libraries = ["tmpl"],
            extra_compile_args = compile_args
        ),
        setuptools.Extension(
            "erf",
            erf_list,
            include_dirs = [numpy.get_include()],
            libraries = ["tmpl"],
            extra_compile_args = compile_args
        ),
        setuptools.Extension(
            "besseli0",
            i0_list,
            include_dirs = [numpy.get_include()],
            libraries = ["tmpl"],
            extra_compile_args = compile_args
        ),
        setuptools.Extension(
            "fresnel_cos",
            fresnel_cos_list,
            include_dirs = [numpy.get_include()],
            libraries = ["tmpl"],
            extra_compile_args = compile_args
        )
    ]
)
