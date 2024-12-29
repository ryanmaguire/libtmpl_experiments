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
#   References:                                                                #
#       1.) Maguire, R., French, R. (2024)                                     #
#           "Applications of Legendre Polynomials for Fresnel Inversion        #
#               and Occultation Observations"                                  #
#       2.) Marouf, E., Tyler, G., Rosen, P. (June 1986)                       #
#           "Profiling Saturn's Rings by Radio Occultation"                    #
#           Icarus Vol. 68, Pages 120-166.                                     #
#       3.) Goodman, J. (2005)                                                 #
#           "Introduction to Fourier Optics"                                   #
#           McGraw-Hill Series in Electrical and Computer Engineering.         #
################################################################################
#   Author: Ryan Maguire                                                       #
#   Date:   2024/12/23                                                         #
################################################################################
"""

# 6 arguments isn't too many. pylint: disable = too-many-arguments
# xi is a perfectly valid name. pylint: disable = invalid-name
import math
import matplotlib.pyplot as plt

def xi(rho, rho0, phi, phi0, opening, distance):
    """
        The xi factor from [1], which is minus the xi factor from [2].
    """
    factor = rho * math.cos(phi) - rho0 * math.cos(phi0)
    return factor * math.cos(opening) / distance

def xi_prime(rho, phi, opening, distance):
    """
        The partial derivative d xi / d phi.
    """
    return -rho * math.cos(opening) * math.sin(phi) / distance

def xi_2prime(rho, phi, opening, distance):
    """
        The second partial derivative, d^2 xi / d phi^2.
    """
    return -rho * math.cos(opening) * math.cos(phi) / distance

def eta(rho, rho0, phi, phi0, distance):
    """
        The eta factor from [1] and [2].
    """
    numer = rho**2 + rho0**2 - 2*rho*rho0*math.cos(phi - phi0)
    denom = distance**2
    return numer / denom

def eta_prime(rho, rho0, phi, phi0, distance):
    """
        The partial derivative d eta / d phi.
    """
    numer = 2 * rho * rho0 * math.sin(phi - phi0)
    denom = distance**2
    return numer / denom

def eta_2prime(rho, rho0, phi, phi0, distance):
    """
        The second partial derivative d^2 eta / d phi^2.
    """
    numer = 2 * rho * rho0 * math.cos(phi - phi0)
    denom = distance**2
    return numer / denom

def psi_main(xi_val, eta_val):
    """
        The primary part of the Fresnel kernel, sqrt(1 - 2xi + eta). The
        Fresnel kernel is this plus xi - 1.
    """
    return math.sqrt(1 - 2*xi_val + eta_val)

def psi(rho, rho0, phi, phi0, opening, distance):
    """
        The Fresnel kernel: sqrt(1 - 2xi + eta) + xi - 1
    """
    xi_val = xi(rho, rho0, phi, phi0, opening, distance)
    eta_val = eta(rho, rho0, phi, phi0, distance)
    psi_factor = psi_main(xi_val, eta_val)
    return psi_factor + xi_val - 1

def psi_prime(rho, rho0, phi, phi0, opening, distance):
    """
        The partial derivative d psi / d phi.
    """
    xi_val = xi(rho, rho0, phi, phi0, opening, distance)
    xi_prime_val = xi_prime(rho, phi, opening, distance)
    eta_val = eta(rho, rho0, phi, phi0, distance)
    eta_prime_val = eta_prime(rho, rho0, phi, phi0, distance)
    psi_factor = psi_main(xi_val, eta_val)
    return (-2*xi_prime_val + eta_prime_val) / (2 * psi_factor) + xi_prime_val

def psi_2prime(rho, rho0, phi, phi0, opening, distance):
    """
        The second partial derivative d^2 psi / d phi^2.
    """
    xi_val = xi(rho, rho0, phi, phi0, opening, distance)
    xi_prime_val = xi_prime(rho, phi, opening, distance)
    xi_2prime_val = xi_2prime(rho, phi, opening, distance)
    eta_val = eta(rho, rho0, phi, phi0, distance)
    eta_prime_val = eta_prime(rho, rho0, phi, phi0, distance)
    eta_2prime_val = eta_2prime(rho, rho0, phi, phi0, distance)
    psi_factor = psi_main(xi_val, eta_val)
    left = (-2 * xi_2prime_val + eta_2prime_val) / (2 * psi_factor)
    right = (-2 * xi_prime_val + eta_prime_val)**2 / (4 * psi_factor**3)
    return left - right + xi_2prime_val

def newton(initial, func, deriv):
    """
        The next term in the Newton sequence:
            x_{n+1} = x_{n} - f(x_{n}) / f'(x_{n})
    """
    return initial - func / deriv

def psi_newton(rho, rho0, phi0, opening, distance):
    """
        Computes the Fresnel kernel at the stationary azimuth angle using
        Newton's method.
    """
    phi = phi0
    toler = 1.0E-8
    max_iters = 100

    for _ in range(max_iters):
        dpsi = psi_prime(rho, rho0, phi, phi0, opening, distance)
        d2psi = psi_2prime(rho, rho0, phi, phi0, opening, distance)
        phi = newton(phi, dpsi, d2psi)

        if abs(dpsi) < toler:
            break

    return psi(rho, rho0, phi, phi0, opening, distance)

def fresnel_quadratic(rho, rho0, phi0, opening, distance):
    """
        Classic quadratic approximation to the Fresnel kernel.
    """
    x_val = (rho - rho0) / distance
    numer = (math.sin(opening) * x_val)**2
    denom = 2*(1 - (math.sin(phi0) * math.cos(opening))**2)
    return numer / denom

def legendre(pn0, pn1, ind, alpha):
    """
        Bonnet recursion formula for the Legendre polynomials.
    """
    numer = (2*ind + 3) * alpha * pn1 - (ind + 1) * pn0
    denom = ind + 2
    return numer / denom

def chebyshev(un0, un1, alpha):
    """
        Recursion formula for the Chebyshev polynomials.
    """
    return 2 * alpha * un1 - un0

def fresnel_legendre(alpha, beta, x_val, deg):
    """
        Evaluation of the approximate Fresnel kernel by Legendre polynomials.
    """
    out = 0
    un0 = 1
    un1 = 2 * alpha
    pn0 = 1
    pn1 = alpha

    for ind in range(deg - 1):
        pn2 = legendre(pn0, pn1, ind, alpha)
        un2 = chebyshev(un0, un1, alpha)

        left = (pn0 - alpha * pn1) / (ind + 2)
        right = un2 - 2 * pn2

        out += (left - beta * right) * x_val**ind

        pn0 = pn1
        pn1 = pn2
        un0 = un1
        un1 = un2

    return out * x_val**2

def psi_approx(rho, rho0, phi0, opening, distance):
    """
        Fresnel kernel using the Taylor series method. We get:
            psi ~= psi0 - psi0'^2 / 2 psi0''
        where psi0 denotes the Fresnel kernel evaluated with phi = phi0.
        Similarly for the partial derivatives with respect to phi.
    """
    psi0 = psi(rho, rho0, phi0, phi0, opening, distance)
    dpsi0 = psi_prime(rho, rho0, phi0, phi0, opening, distance)
    d2psi0 = psi_2prime(rho, rho0, phi0, phi0, opening, distance)
    return psi0 - dpsi0**2 / (2 * d2psi0)

def psi_careful_legendre(rho, rho0, phi0, opening, distance):
    """
        The Fresnel-Legendre approximation with psi'' computed exactly.
        psi and psi' are computed with quartic Legendre polynomials.
    """
    alpha = math.cos(opening) * math.cos(phi0)
    factor = math.cos(opening) * math.sin(phi0) * rho / distance
    numer = factor**2
    denom = 2 * psi_2prime(rho, rho0, phi0, phi0, opening, distance)
    beta = numer / denom
    x_val = (rho - rho0) / distance
    return fresnel_legendre(alpha, beta, x_val, 4)

def psi_legendre(rho, rho0, phi0, opening, distance):
    """
        Fresnel-Legendre approximation with psi'' treated as a constant.
    """
    alpha = math.cos(opening) * math.cos(phi0)
    factor = math.cos(opening) * math.sin(phi0)
    numer = factor**2
    denom = 2 * (1 - factor**2)
    scale = (rho / rho0) ** 2
    beta = scale * numer / denom
    x_val = (rho - rho0) / distance
    return fresnel_legendre(alpha, beta, x_val, 4)

def psi_fast_legendre(rho, rho0, phi0, opening, distance):
    """
        Fresnel-Legendre approximation with psi'' treated as a constant
        and rho / rho0 ~= 1.
    """
    alpha = math.cos(opening) * math.cos(phi0)
    factor = math.cos(opening) * math.sin(phi0)
    numer = factor**2
    denom = 2 * (1 - factor**2)
    beta = numer / denom
    x_val = (rho - rho0) / distance
    return fresnel_legendre(alpha, beta, x_val, 4)

def psi_curved_legendre(rho, rho0, phi0, opening, distance):
    alpha = math.cos(opening) * math.cos(phi0)
    factor = math.cos(opening) * math.sin(phi0) * rho
    numer = (factor / distance)**2
    x_val = (rho - rho0) / distance

    left = alpha * rho * distance + rho * rho0
    right = factor**2
    legendre_factor = 1 + alpha*x_val
    scale_factor = legendre_factor / distance**2
    shift = alpha * rho / distance

    denom = scale_factor * (left - right * legendre_factor**2) - shift
    beta = numer / denom / 2
    return fresnel_legendre(alpha, beta, x_val, 4)


def quad_factor(phi0, opening, distance):
    """
        Quadratic factor for the Taylor expansion of psi in rho centered
        about rho0 and evaluated at the stationary azimuth angle.
    """
    numer = math.sin(opening)**2
    denom = (1 - (math.sin(phi0) * math.cos(opening))**2) * distance**2
    return numer / denom / 2

def cube_factor(rho0, phi0, opening, distance):
    """
        Cubic factor for the Taylor expansion of psi in rho centered
        about rho0 and evaluated at the stationary azimuth angle.
    """
    cosb = math.cos(opening)
    sinb = math.sin(opening)
    cosp0 = math.cos(phi0)
    sinp0 = math.sin(phi0)
    alpha = cosb * cosp0
    beta = sinp0 * cosb
    factor = (distance * alpha + rho0) * beta ** 2
    numer = 3 * alpha * (factor - rho0) * sinb ** 2
    denom = rho0 * (distance * (beta - 1) * (beta + 1)) ** 3
    return numer / denom / 6

def psi_cubic(rho, rho0, phi0, opening, distance):
    """
        Computes the Fresnel kernel using a cubic Taylor polynomial in
        rho centered about rho0 using the stationary azimuth angle.
    """
    a2 = quad_factor(phi0, opening, distance)
    a3 = cube_factor(rho0, phi0, opening, distance)
    x_val = rho - rho0
    return (a2 + a3 * x_val) * x_val **2

# Rev007E
# ANGLE = -30.571312 * math.pi / 180.0
# DIST = 286794.44
# WINDOW = 37.32
# AZIMUTH = 250.901802 * math.pi / 180.0

# Rev133E
ANGLE = 1.885757 * math.pi / 180.0
DIST = 212918.13
WINDOW = 346.648
AZIMUTH = 261.205477 * math.pi / 180.0

# Edge of the Maxwell ringlet, same for both data sets.
DISPLACEMENT = 0.25
RADIUS = 87410.0

# Wavelength of the signal from Cassini. Nearly the same for both data sets.
# They agree to the first few decimals.
WAVELENGTH = 3.558E-05
WAVENUMBER = 2 * math.pi / WAVELENGTH
# SCALE = WAVENUMBER * DIST

# Create an array for the window.
START = RADIUS - WINDOW / 2
END = RADIUS + WINDOW / 2
NUMBER_OF_ELEMENTS = int((END - START) / DISPLACEMENT)
ARRAY = [START + DISPLACEMENT * n for n in range(NUMBER_OF_ELEMENTS)]

# Compute the various approximations to the Fresnel kernel.
PSIN = [psi_newton(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSIF = [fresnel_quadratic(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSIA = [psi_approx(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSIL = [psi_legendre(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSIC = [psi_careful_legendre(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSIU = [psi_curved_legendre(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSIS = [psi_fast_legendre(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]
PSI3 = [psi_cubic(r, RADIUS, AZIMUTH, ANGLE, DIST) for r in ARRAY]

plt.plot(ARRAY, PSIN, label = "Newton")
plt.plot(ARRAY, PSIF, label = "Fresnel")
#plt.plot(ARRAY, PSIA, label = "Approximate Newton")
#plt.plot(ARRAY, PSIL, label = "Quartic Legendre")
#plt.plot(ARRAY, PSIU, label = "Curved Legendre")
#plt.plot(ARRAY, PSIC, label = "Careful Legendre")
#plt.plot(ARRAY, PSIS, label = "Fast Legendre")
plt.plot(ARRAY, PSI3, label = "Psi Cubic")
plt.legend()
plt.xlim(ARRAY[0], ARRAY[-1])
plt.show()
