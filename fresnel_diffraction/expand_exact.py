import sympy

r, r0, phi, phi0, B = sympy.symbols("r r_0 phi phi_0 B")
x, y, z = sympy.symbols("x y z")
alpha = sympy.symbols("alpha")

D = sympy.sqrt((x - r*sympy.cos(phi))**2 + (y - r*sympy.sin(phi))**2 + z**2)

phir = sympy.Function("phi")(r)
dphir = sympy.diff(phir, r)

xi = sympy.cos(B) * (r*sympy.cos(phi) - r0*sympy.cos(phi0)) / D
eta = (r**2 + r0**2 - 2*r*r0*sympy.cos(phi - phi0)) / D**2

psi = sympy.sqrt(1 - 2*xi + eta) + xi - 1
psi_prime = sympy.diff(psi, phi)

dpsir0 = sympy.diff(psi_prime.subs(phi, phir), r).subs(dphir, alpha).subs(phir, phi0).subs(r, r0)

sol = sympy.simplify(sympy.solvers.solve(dpsir0, alpha)[0])

psi_rr = sympy.diff(psi, r, r)
psi_rp = sympy.diff(psi, r, phi)
psi_pp = sympy.diff(psi, phi, phi)

d2psir = psi_rr + 2 * sol * psi_rp + sol**2 * psi_pp

d2psir0 = sympy.simplify(d2psir.subs(phi, phi0).subs(r, r0))

print(sol)
print(d2psir0)
