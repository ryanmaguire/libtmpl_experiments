<!---
    LICENSE

    This file is part of libtmpl_experiments.

    libtmpl_experiments is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libtmpl_experiments is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with libtmpl_experiments.  If not, see <https://www.gnu.org/licenses/>.

    AUTHOR
        Ryan Maguire
--->
# libtmpl_experiments
Experimenting with various algorithms for libtmpl.

## Building
The only dependency is [`libtmpl`](https://github.com/ryanmaguire/libtmpl).
Build and install this first.
You can then compile for `C` use using the Makefile.
```sh
make
```
You can choose compiler with the `CC` option.
```sh
make CC=clang
```
And add extra flags if you want.
```sh
make CC=clang Extra_Flags=-Weverything
```
A small Python wrapper is available with `numpy` support so you can plot the
functions with `matplotlib`. To build this make sure `numpy` and `python3`
are installed. After building and installing `libtmpl`, type
```sh
python3 setup.py build_ext --inplace
```
# License
    libtmpl_experiments is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libtmpl_experiments is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with libtmpl_experiments.  If not, see <https://www.gnu.org/licenses/>.
