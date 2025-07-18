/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of libtmpl.                                             *
 *                                                                            *
 *  libtmpl is free software: you can redistribute it and/or modify           *
 *  it under the terms of the GNU General Public License as published by      *
 *  the Free Software Foundation, either version 3 of the License, or         *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl is distributed in the hope that it will be useful,                *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License         *
 *  along with libtmpl.  If not, see <https://www.gnu.org/licenses/>.         *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       June 8, 2021                                                  *
 ******************************************************************************
 *                              Revision History                              *
 ******************************************************************************
 *  2023/03/24: Ryan Maguire                                                  *
 *      Migrated from rss_ringoccs.                                           *
 ******************************************************************************/

/*
 * TODO: Add doc string and comments.
 */

/*  Trig functions and square root found here.                                */
#include <libtmpl/include/tmpl_math.h>

/*  Function prototype given here.                                            */
#include <libtmpl/include/tmpl_cyl_fresnel_optics.h>

double
tmpl_Double_Stationary_Cyl_Fresnel_Psi_D_Newton_Deg(double k,
                                                    double r,
                                                    double r0,
                                                    double phi,
                                                    double phi0,
                                                    double B,
                                                    double rx,
                                                    double ry,
                                                    double rz,
                                                    double eps,
                                                    unsigned int toler)
{
    /*  Declare necessary variables. C89 requires this at the top.            */
    double xi, eta, psi0, dxi, deta, deta2, dxi2, rcpr_psi0, rcpr_psi0_cubed;
    double cos_phi, sin_phi, cos_phi0, sin_phi0, cos_phi_phi0, sin_phi_phi0;
    double dpsi, d2psi, err, num_factor, rcpr_D, rcpr_D_squared;
    double D, x, y, dx, dy, xi_factor, eta_factor;

    /*  Index for keeping track of the number of iterations.                  */
    unsigned int n = 0U;

    /*  Precompute cosines and sines to save on computations.                 */
    const double cos_B = tmpl_Double_Cosd(B);

    /*  Simultaneously compute sine and cosine of phi.                        */
    tmpl_Double_SinCosd(phi0, &sin_phi0, &cos_phi0);

    /*  Compute the Cartesian coordinates of the ring point.                  */
    x = r0 * cos_phi0;
    y = r0 * sin_phi0;

    /*  Compute the distances in the individual components.                   */
    dx = x - rx;
    dy = y - ry;

    /*  No physical system could possibly have dx, dy, or rz so large         *
     *  that the sum of the squares may overflow. The system would need       *
     *  to have distances that are roughly 10^125 times the radius of the     *
     *  observable universe for the sum of the squares to exceed              *
     *  2^(2^10 - 1), the max exponent of double. Because of this, we can     *
     *  safely pass to sqrt.                                                  */
    D = tmpl_Double_Sqrt(dx*dx + dy*dy + rz*rz);

    /*  Compute 1/D and it's square to save the number of divisions we        *
     *  need to compute. Multiplication is usually ~10 times faster.          */
    rcpr_D = 1.0 / D;
    rcpr_D_squared = rcpr_D * rcpr_D;

    /*  Normalize the requested error by the wavenumber and distance.         */
    eps /= k;

    /*  Iteratively perform Newton's method until the error is small.         */
    do {

        /*  If we've performed enough iterations, stop Newton's method.       */
        if (n > toler)
            break;

        /*  Simultaneously compute sine and cosine of phi.                    */
        tmpl_Double_SinCosd(phi, &sin_phi, &cos_phi);

        /*  Since we've computed cos and sin of phi and phi0, cos and sin of  *
         *  phi-phi0 can be computed without the need to call cos and sin.    */
        cos_phi_phi0 = cos_phi*cos_phi0 + sin_phi*sin_phi0;
        sin_phi_phi0 = sin_phi*cos_phi0 - cos_phi*sin_phi0;

        /*  These terms occur frequently.                                     */
        xi_factor = cos_B * rcpr_D;
        eta_factor = 2.0 * r * r0 * rcpr_D_squared;

        /*  The derivatives of eta can be computed from the eta factor and    *
         *  the sine and cosine of the angle difference.                      */
        deta = eta_factor * sin_phi_phi0;
        deta2 = eta_factor * cos_phi_phi0;

        /*  Similarly, we can compute the derivatives of xi.                  */
        dxi = -xi_factor * r * sin_phi;
        dxi2 = -xi_factor * r * cos_phi;

        /*  Compute xi variable (MTR86 Equation 4b) and eta (Equation 4c).    */
        xi = xi_factor * (r * cos_phi - r0 * cos_phi0);
        eta = (r0*r0 + r*r)*rcpr_D_squared - deta2;
        psi0 = tmpl_Double_Sqrt(1.0 + eta - 2.0*xi);
        rcpr_psi0 = 1.0 / psi0;
        rcpr_psi0_cubed = rcpr_psi0 * rcpr_psi0 * rcpr_psi0;

        num_factor = deta - 2.0*dxi;
        dpsi = 0.5 * rcpr_psi0 * num_factor + dxi;

        d2psi = -0.25 * rcpr_psi0_cubed * num_factor * num_factor;
        d2psi += 0.5 * rcpr_psi0 * (deta2 - 2.0*dxi2) + dxi2;

        /*  Perform the Newton iteration, and increment n.                    */
        phi = phi - tmpl_Double_Rad_To_Deg * dpsi / d2psi;
        ++n;

        /*  Update the error. We want the partial derivative to be small.     */
        err = tmpl_Double_Abs(D * dpsi);

    } while (err > eps);

    return phi;
}
