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

# Interpolation order.
N = 4
M = N // 2

W = sp.symbols('W')
mean = sp.symbols(f'mean[1:{M+1}]')  # mean[1], mean[2]
diff = sp.symbols(f'diff[1:{M+1}]')  # diff[1], diff[2]

# Set interpolation points.
s = [k * W/(2 * M) for k in range(1, M + 1)]

# Build even and odd systems
even_mat = sp.Matrix([[s_k**(2*j) for j in range(1, M + 1)] for s_k in s])
c_even = even_mat.LUsolve(sp.Matrix(mean))

odd_mat = sp.Matrix([[s_k**(2*j - 1) for j in range(1, M + 1)] for s_k in s])
c_odd = odd_mat.LUsolve(sp.Matrix([d / 2 for d in diff]))

# Combine into full coefficient list.
solutions = [None] * N
for j in range(1, M + 1):
    solutions[2*j - 2] = sp.simplify(c_odd[j - 1])   # odd
    solutions[2*j - 1] = sp.simplify(c_even[j - 1])  # even

# Extract and print coefficients.
for i, expr in enumerate(solutions):
    expr = expr.expand()
    is_odd = (i % 2 == 0)
    vars_list = diff if is_odd else mean

    for j, var in enumerate(vars_list):
        coeff = expr.coeff(var)

        if coeff != 0:

            # Remove W factors if present.
            coeff_no_W = coeff.subs(W, 1)
            coeff_rational = sp.nsimplify(coeff_no_W, rational=True)

            # Convert to scientific notation and print.
            coeff_float = coeff_rational.evalf(24)
            print(f"#define C{i}{j} ({coeff_float:+.24E})")
