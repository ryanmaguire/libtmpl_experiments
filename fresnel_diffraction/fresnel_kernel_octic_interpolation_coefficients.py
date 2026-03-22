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
import sympy as sp
import numpy as np
from sympy import latex
from IPython.display import display, Math

# Interpolation order.
N = 8
M = N // 2

W = sp.symbols('W')
psi_bar = sp.symbols(f'psi_bar1:{M+1}')  # psi_bar1, psi_bar2, ...
Dpsi = sp.symbols(f'Dpsi1:{M+1}')        # Dpsi1, Dpsi2, ...
c = sp.symbols(f'c1:{N+1}')              # c1, c2, ..., cN

# Set interpolation points.
s = [k * W/(2 * M) for k in range (1, M+1)] # Evenly spaced points

# Even coeffs -> average.
even_mat = sp.Matrix([[s_k**(2*j) for j in range(1, M+1)] for s_k in s])
c_even = even_mat.LUsolve(sp.Matrix(psi_bar))

# Odd coeffs -> difference.
odd_mat = sp.Matrix([[s_k**(2*j-1) for j in range(1, M+1)] for s_k in s])
c_odd = odd_mat.LUsolve(sp.Matrix([d/2 for d in Dpsi]))

solutions = [None] * N

for j in range(1, M+1):
    solutions[2*j-2] = sp.simplify(c_odd[j-1])    # odd
    solutions[2*j-1] = sp.simplify(c_even[j-1])   # even


# used gpt to output solutions nicely.
symbol_map = {
    psi_bar[i]: fr'\overline{{\psi}}_{{{i+1}}}' for i in range(M)
}

symbol_map.update(
    {
        Dpsi[i]: fr'\Delta\psi_{{{i+1}}}' for i in range(M)
    }
)

for i, expr in enumerate(solutions, start=1):
    tex = latex(expr, symbol_names=symbol_map)
    display(Math(rf"c_{{{i}}} = {tex}"))
