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

# pylint: disable = no-member
import sympy
import sympy.vector
sympy.init_printing()

x, y, z = sympy.symbols("x y z")
ux, uy, uz = sympy.symbols("ux uy uz")
dx, dy, dz = sympy.symbols("dx dy dz")
rx, ry, rz = sympy.symbols("rx ry rz")
r, r0, phi, phi0 = sympy.symbols("rho rho0 phi phi0", positive = True)
B, D, k = sympy.symbols("B D k", positive = True)

N = sympy.vector.CoordSys3D("N")
R = x*N.i + y*N.j + z*N.k
rho = r*sympy.cos(phi)*N.i + r*sympy.sin(phi)*N.j
rho0 = r0*sympy.cos(phi0)*N.i + r0*sympy.sin(phi0)*N.j

u = R - rho0
un = u.normalize()

mag = (R - rho).magnitude()
dot = un.dot(rho - R)

psi = mag + dot
dpsi = psi.diff(phi)
d2psi = dpsi.diff(phi)
d3psi = d2psi.diff(phi)
d4psi = d3psi.diff(phi)

a = []
for arg in d4psi.args:
    a.append(arg.simplify())

A = a[0] + a[2] + a[3]
B = a[1]
C = a[4] + a[5]
D = a[6] + a[7] + a[8]
E = a[9]

D_numer = D.args[0] / D.args[0].args[3] + D.args[1] / D.args[1].args[3]
