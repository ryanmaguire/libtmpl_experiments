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
import matplotlib.pyplot as plt
import numpy as np
import scipy.special as sc

def linear_wave(xi, xi_D, amplitude, phideg):
    """
        Create a linear density wave.
    """

    phi = np.radians(phideg)
    factor = 1.0 / np.sqrt(np.pi) - 2.0j * xi * h_xi(xi)
    scale = np.exp(-(xi / xi_D)**3)
    argument = -1.0j * amplitude * factor  * np.exp(1.0j * phi) * scale
    return 1.0 + np.real(argument)

def linear_wave2(xi, xi_D, amplitude, phideg):
    """
        Create a linear density wave.
    """

    phi = np.radians(phideg)
    factor = 1.0 / np.sqrt(np.pi) - 2.0j * xi * h_xi(xi)
    scale = np.exp(-(xi / xi_D)**3)
    argument = -1.0j * amplitude * factor  * np.exp(1.0j * phi) * scale
    return 1.0 / (1.0 - np.real(argument))

def linear_wave_optical_depth(x_vals, wave, mean_depth, slope):
    """
        Compute tau_norm for a linear density wave.
    """
    return mean_depth * (wave + x_vals * slope)

def h_xi(xi, q_value = 1.0):
    """
        Helper function for the density wave.
    """
    iq = 1.0j * q_value
    z = np.sqrt(2.0 / np.pi) * xi
    C, S = sc.fresnel(z)
    return np.exp(-iq*xi**2) * ((1.0 + iq) / 2.0 + C + iq * S) / np.sqrt(2.0)

R_RES = 77000.0

NUMBER_OF_POINTS = 10000
START = 0.0
END = 12.0

R_VALS = R_RES + np.linspace(START, END, NUMBER_OF_POINTS)

KM_PER_XI = 1
TAU_MEAN = 0.1
XI_D = 6.0
A_L= 0.05
SLOPE = 0.0
PHI_DEG = 0.0
SIN_OPENING = 0.3
X_VALS = R_VALS - R_RES
XI_VALS = X_VALS / KM_PER_XI

WAVE = linear_wave(XI_VALS, XI_D, A_L, PHI_DEG)
TAU_NORM = linear_wave_optical_depth(X_VALS, WAVE, TAU_MEAN, SLOPE)
POWER = np.exp(-TAU_NORM / SIN_OPENING)

plt.plot(R_VALS, WAVE)
plt.xlabel('r(km)')
plt.ylabel(r'$\tau_{norm}$')
plt.title('Linear density wave')
plt.show()

plt.plot(R_VALS, POWER)
plt.xlabel('r(km)')
plt.ylabel('Power')
plt.title('Linear density wave')
plt.show()
