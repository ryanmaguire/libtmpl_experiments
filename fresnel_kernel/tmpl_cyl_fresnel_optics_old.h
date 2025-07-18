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
 *                          tmpl_cyl_fresnel_optics                           *
 ******************************************************************************
 *  Purpose:                                                                  *
 *      Provides functions for working in Fresnel optics. In particular, this *
 *      header gives routines for working in cylindrically symmetric          *
 *      environments such as planetary rings. Used by rss_ringoccs frequently.*
 ******************************************************************************
 *                                DEPENDENCIES                                *
 ******************************************************************************
 *  None.                                                                     *
 ******************************************************************************
 *  Author:     Ryan Maguire                                                  *
 *  Date:       March 20, 2023                                                *
 ******************************************************************************
 *                              Revision History                              *
 ******************************************************************************
 *  2023/03/20: Ryan Maguire                                                  *
 *      Moved here from rss_ringoccs. Cleaned up a bit.                       *
 *  2024/06/24: Ryan Maguire                                                  *
 *      Added more routines in degrees.                                       *
 ******************************************************************************/

/*  Include guard to avoid importing this file twice.                         */
#ifndef TMPL_CYL_FRESNEL_OPTICS_H
#define TMPL_CYL_FRESNEL_OPTICS_H

/*  TODO:
 *      Fixed the stationary Psi function. Add float and long double support.
 */

/*  If using with C++ (and not C) we need to wrap the entire header file in   *
 *  an extern "C" statement. Check if C++ is being used with __cplusplus.     */
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
 *  Function:                                                                 *
 *      tmpl_Double_Cyl_Fresnel_dPsi_dPhi_D                                   *
 *  Purpose:                                                                  *
 *      Computes the first partial derivative of the cylindrical Fresnel      *
 *      kernel "Psi" with respect to the azimuthal angle "Phi" (see below).   *
 *      This updates the D component as a function of phi unlike the function *
 *      tmpl_Double_Cyl_Fresnel_dPsi_dPhi which assumes D to be constant.     *
 *  Arguments:                                                                *
 *      k (double):                                                           *
 *          The wavenumber, in the reciprocal of the units of r.              *
 *      r (double):                                                           *
 *          The "dummy" radius, usually a variable that is integrated over.   *
 *      r0 (double):                                                          *
 *          The radius of the point of interest.                              *
 *      phi (double):                                                         *
 *          The "dummy" azimuthal angle, often integrated over.               *
 *      phi0 (double):                                                        *
 *          The azimuthal angle of the point of interest.                     *
 *      B (double):                                                           *
 *          The opening angle of the plane. For planetary ring systems this   *
 *          is the ring opening angle of the rings with respect to Earth.     *
 *      rx (double):                                                          *
 *          The x coordinated of the observer with respect to the plane.      *
 *      ry (double):                                                          *
 *          The y coordinated of the observer with respect to the plane.      *
 *      rz (double):                                                          *
 *          The z coordinated of the observer with respect to the plane.      *
 *  Outputs:                                                                  *
 *      dpsi_dphi (double):                                                   *
 *          The first partial derivative of the cylindrical Fresnel kernel    *
 *          with respect to phi.                                              *
 *  Notes:                                                                    *
 *    Assumes perfect cylindrical symmetry. Accurate for Saturn. Mostly       *
 *    accurate for Uranus. Float and long double precisions are provided.     *
 *                                                                            *
 *    All angles are assumed to be in radians.                                *
 *    All lengths are assumed to be in the same units.                        *
 ******************************************************************************/
double
tmpl_Double_Cyl_Fresnel_dPsi_dPhi_D(double k, double r, double r0,
                                    double phi, double phi0, double B,
                                    double rx, double ry, double rz);

float
tmpl_Float_Cyl_Fresnel_dPsi_dPhi_D(float k, float r, float r0,
                                   float phi, float phi0, float B,
                                   float rx, float ry, float rz);

extern long double
tmpl_LDouble_Cyl_Fresnel_dPsi_dPhi_D(long double k, long double r,
                                     long double r0, long double phi,
                                     long double phi0, long double B,
                                     long double rx, long double ry,
                                     long double rz);

/******************************************************************************
 *  Function:                                                                 *
 *      tmpl_Double_Cyl_Fresnel_dPsi_dPhi_D_Deg                               *
 *  Purpose:                                                                  *
 *      Computes the first partial derivative of the cylindrical Fresnel      *
 *      kernel "Psi" with respect to the azimuthal angle "Phi" (see below).   *
 *      This updates the D component as a function of phi unlike the function *
 *      tmpl_Double_Cyl_Fresnel_dPsi_dPhi_Deg which assumes D to be constant. *
 *      Similar to tmpl_Double_Cyl_Fresnel_dPsi_dPhi_D, but angles are in     *
 *      degrees.                                                              *
 *  Arguments:                                                                *
 *      k (double):                                                           *
 *          The wavenumber, in the reciprocal of the units of r.              *
 *      r (double):                                                           *
 *          The "dummy" radius, usually a variable that is integrated over.   *
 *      r0 (double):                                                          *
 *          The radius of the point of interest.                              *
 *      phi (double):                                                         *
 *          The "dummy" azimuthal angle, often integrated over.               *
 *      phi0 (double):                                                        *
 *          The azimuthal angle of the point of interest.                     *
 *      B (double):                                                           *
 *          The opening angle of the plane. For planetary ring systems this   *
 *          is the ring opening angle of the rings with respect to Earth.     *
 *      rx (double):                                                          *
 *          The x coordinated of the observer with respect to the plane.      *
 *      ry (double):                                                          *
 *          The y coordinated of the observer with respect to the plane.      *
 *      rz (double):                                                          *
 *          The z coordinated of the observer with respect to the plane.      *
 *  Outputs:                                                                  *
 *      dpsi_dphi (double):                                                   *
 *          The first partial derivative of the cylindrical Fresnel kernel    *
 *          with respect to phi.                                              *
 *  Notes:                                                                    *
 *    Assumes perfect cylindrical symmetry. Accurate for Saturn. Mostly       *
 *    accurate for Uranus. Float and long double precisions are provided.     *
 *                                                                            *
 *    All angles are assumed to be in degrees.                                *
 *    All lengths are assumed to be in the same units.                        *
 ******************************************************************************/
double
tmpl_Double_Cyl_Fresnel_dPsi_dPhi_D_Deg(double k, double r, double r0,
                                        double phi, double phi0, double B,
                                        double rx, double ry, double rz);

float
tmpl_Float_Cyl_Fresnel_dPsi_dPhi_D_Deg(float k, float r, float r0,
                                       float phi, float phi0, float B,
                                       float rx, float ry, float rz);

extern long double
tmpl_LDouble_Cyl_Fresnel_dPsi_dPhi_D_Deg(long double k, long double r,
                                         long double r0, long double phi,
                                         long double phi0, long double B,
                                         long double rx, long double ry,
                                         long double rz);

/******************************************************************************
 *  Function:                                                                 *
 *      tmpl_Double_Cyl_Fresnel_Psi_Alt                                       *
 *  Purpose:                                                                  *
 *      Computes the cylindrical Fresnel kernel. Almost identical to          *
 *      tmpl_Double_Cyl_Fresnel_Psi, but computes using the "weighted"        *
 *      wavenumber, which is kD, k being the wavenumber, D being the distance *
 *      from the observer to the plane. This is useful in scenarios where     *
 *      you want the weighted value to be constant, but allow D to vary.      *
 *  Arguments:                                                                *
 *      kD (double):                                                          *
 *          The weighted wavenumber, unitless.                                *
 *      r (double):                                                           *
 *          The "dummy" radius, usually a variable that is integrated over.   *
 *      r0 (double):                                                          *
 *          The radius of the point of interest.                              *
 *      phi (double):                                                         *
 *          The "dummy" azimuthal angle, often integrated over.               *
 *      phi0 (double):                                                        *
 *          The azimuthal angle of the point of interest. Same units as phi.  *
 *      B (double):                                                           *
 *          The opening angle of the plane. For planetary ring systems, this  *
 *          is the ring opening angle of the rings with respect to Earth.     *
 *      D (double):                                                           *
 *          The distance from the observer to the plane.                      *
 *  Outputs:                                                                  *
 *      psi (double):                                                         *
 *          The cylindrical Fresnel kernel as a function of the inputs.       *
 *  Notes:                                                                    *
 *    Assumes perfect cylindrical symmetry. Accurate for Saturn. Mostly       *
 *    accurate for Uranus. Float and long double precisions are provided.     *
 *                                                                            *
 *    All angles are assumed to be in radians.                                *
 *    All lengths are assumed to be in the same units.                        *
 ******************************************************************************/
extern double
tmpl_Double_Cyl_Fresnel_Psi_Alt(double kD, double r, double r0, double phi,
                                double phi0, double B, double D);

extern float
tmpl_Float_Cyl_Fresnel_Psi_Alt(float kD, float r, float r0, float phi,
                               float phi0, float B, float D);

extern long double
tmpl_LDouble_Cyl_Fresnel_Psi_Alt(long double kD, long double r, long double r0,
                                 long double phi, long double phi0,
                                 long double B, long double D);

/******************************************************************************
 *  Function:                                                                 *
 *      tmpl_Double_Cyl_Fresnel_Psi_Alt_Deg                                   *
 *  Purpose:                                                                  *
 *      Computes the cylindrical Fresnel kernel. Almost identical to          *
 *      tmpl_Double_Cyl_Fresnel_Psi, but computes using the "weighted"        *
 *      wavenumber, which is kD, k being the wavenumber, D being the distance *
 *      from the observer to the plane. This is useful in scenarios where     *
 *      you want the weighted value to be constant, but allow D to vary.      *
 *  Arguments:                                                                *
 *      kD (double):                                                          *
 *          The weighted wavenumber, unitless.                                *
 *      r (double):                                                           *
 *          The "dummy" radius, usually a variable that is integrated over.   *
 *      r0 (double):                                                          *
 *          The radius of the point of interest.                              *
 *      phi (double):                                                         *
 *          The "dummy" azimuthal angle, often integrated over.               *
 *      phi0 (double):                                                        *
 *          The azimuthal angle of the point of interest. Same units as phi.  *
 *      B (double):                                                           *
 *          The opening angle of the plane. For planetary ring systems, this  *
 *          is the ring opening angle of the rings with respect to Earth.     *
 *      D (double):                                                           *
 *          The distance from the observer to the plane.                      *
 *  Outputs:                                                                  *
 *      psi (double):                                                         *
 *          The cylindrical Fresnel kernel as a function of the inputs.       *
 *  Notes:                                                                    *
 *    Assumes perfect cylindrical symmetry. Accurate for Saturn. Mostly       *
 *    accurate for Uranus. Float and long double precisions are provided.     *
 *                                                                            *
 *    All angles are assumed to be in degrees.                                *
 *    All lengths are assumed to be in the same units.                        *
 ******************************************************************************/
extern double
tmpl_Double_Cyl_Fresnel_Psi_Alt_Deg(double kD, double r, double r0, double phi,
                                    double phi0, double B, double D);

extern float
tmpl_Float_Cyl_Fresnel_Psi_Alt_Deg(float kD, float r, float r0, float phi,
                                   float phi0, float B, float D);

extern long double
tmpl_LDouble_Cyl_Fresnel_Psi_Alt_Deg(long double kD, long double r,
                                     long double r0, long double phi,
                                     long double phi0, long double B,
                                     long double D);

/******************************************************************************
 *  Function:                                                                 *
 *      tmpl_Double_Stationary_Cyl_Fresnel_Psi_D_Newton                       *
 *  Purpose:                                                                  *
 *      Computes the value phi_s that makes the cylindrical Fresnel kernel    *
 *      stationary. That is, the value phi such that dpsi / dphi = 0, as a    *
 *      function of the other inputs. This is done using Newton's method.     *
 *      This function is used when the stationary phase approximation is      *
 *      needed to reduce the double integral of the plane into a single       *
 *      integral over a curve in the plane.                                   *
 *  Arguments:                                                                *
 *      k (double):                                                           *
 *          The wavenumber, in the reciprocal of the units of r.              *
 *      r (double):                                                           *
 *          The "dummy" radius, usually a variable that is integrated over.   *
 *      r0 (double):                                                          *
 *          The radius of the point of interest.                              *
 *      phi (double):                                                         *
 *          The guess for the stationary value, used as the starting point of *
 *          Newton's method. phi = phi0 is often a good guess.                *
 *      phi0 (double):                                                        *
 *          The azimuthal angle of the point of interest. Same units as phi.  *
 *      B (double):                                                           *
 *          The opening angle of the plane. For planetary ring systems, this  *
 *          is the ring opening angle of the rings with respect to Earth.     *
 *      rx (double):                                                          *
 *          The x coordinated of the observer with respect to the plane.      *
 *      ry (double):                                                          *
 *          The y coordinated of the observer with respect to the plane.      *
 *      rz (double):                                                          *
 *          The z coordinated of the observer with respect to the plane.      *
 *      eps (double):                                                         *
 *          The "epsilon" factor, the allowed error in the computation of the *
 *          stationary phase. Once |dpsi / dphi| < eps, the computation will  *
 *          stop and the resulting phi will be returned.                      *
 *      toler (unsigned int):                                                 *
 *          The tolerance in the computation, the maximum number of           *
 *          iterations allowed in Newton's method before the algorithm is     *
 *          halted and the current value of phi is returned. For most         *
 *          practical application, toler = 4 or toler = 5 is sufficient.      *
 *  Outputs:                                                                  *
 *      phi_s (double):                                                       *
 *          The stationary value of phi.                                      *
 *  Notes:                                                                    *
 *    Assumes perfect cylindrical symmetry. Accurate for Saturn. Mostly       *
 *    accurate for Uranus. Float and long double precisions are provided.     *
 *                                                                            *
 *    All angles are assumed to be in radians.                                *
 *    All lengths are assumed to be in the same units.                        *
 ******************************************************************************/
extern double
tmpl_Double_Stationary_Cyl_Fresnel_Psi_D_Newton(double k,
                                                double r,
                                                double r0,
                                                double phi,
                                                double phi0,
                                                double B,
                                                double rx,
                                                double ry,
                                                double rz,
                                                double eps,
                                                unsigned int toler);

extern float
tmpl_Float_Stationary_Cyl_Fresnel_Psi_D_Newton(float k,
                                               float r,
                                               float r0,
                                               float phi,
                                               float phi0,
                                               float B,
                                               float rx,
                                               float ry,
                                               float rz,
                                               float eps,
                                               unsigned int toler);

extern long double
tmpl_LDouble_Stationary_Cyl_Fresnel_Psi_D_Newton(long double k,
                                                 long double r,
                                                 long double r0,
                                                 long double phi,
                                                 long double phi0,
                                                 long double B,
                                                 long double rx,
                                                 long double ry,
                                                 long double rz,
                                                 long double eps,
                                                 unsigned int toler);

/******************************************************************************
 *  Function:                                                                 *
 *      tmpl_Double_Stationary_Cyl_Fresnel_Psi_D_Newton_Deg                   *
 *  Purpose:                                                                  *
 *      Computes the value phi_s that makes the cylindrical Fresnel kernel    *
 *      stationary. That is, the value phi such that dpsi / dphi = 0, as a    *
 *      function of the other inputs. This is done using Newton's method.     *
 *      This function is used when the stationary phase approximation is      *
 *      needed to reduce the double integral of the plane into a single       *
 *      integral over a curve in the plane.                                   *
 *  Arguments:                                                                *
 *      k (double):                                                           *
 *          The wavenumber, in the reciprocal of the units of r.              *
 *      r (double):                                                           *
 *          The "dummy" radius, usually a variable that is integrated over.   *
 *      r0 (double):                                                          *
 *          The radius of the point of interest.                              *
 *      phi (double):                                                         *
 *          The guess for the stationary value, used as the starting point of *
 *          Newton's method. phi = phi0 is often a good guess.                *
 *      phi0 (double):                                                        *
 *          The azimuthal angle of the point of interest. Same units as phi.  *
 *      B (double):                                                           *
 *          The opening angle of the plane. For planetary ring systems, this  *
 *          is the ring opening angle of the rings with respect to Earth.     *
 *      rx (double):                                                          *
 *          The x coordinated of the observer with respect to the plane.      *
 *      ry (double):                                                          *
 *          The y coordinated of the observer with respect to the plane.      *
 *      rz (double):                                                          *
 *          The z coordinated of the observer with respect to the plane.      *
 *      eps (double):                                                         *
 *          The "epsilon" factor, the allowed error in the computation of the *
 *          stationary phase. Once |dpsi / dphi| < eps, the computation will  *
 *          stop and the resulting phi will be returned.                      *
 *      toler (unsigned int):                                                 *
 *          The tolerance in the computation, the maximum number of           *
 *          iterations allowed in Newton's method before the algorithm is     *
 *          halted and the current value of phi is returned. For most         *
 *          practical application, toler = 4 or toler = 5 is sufficient.      *
 *  Outputs:                                                                  *
 *      phi_s (double):                                                       *
 *          The stationary value of phi.                                      *
 *  Notes:                                                                    *
 *    Assumes perfect cylindrical symmetry. Accurate for Saturn. Mostly       *
 *    accurate for Uranus. Float and long double precisions are provided.     *
 *                                                                            *
 *    All angles are assumed to be in radians.                                *
 *    All lengths are assumed to be in the same units.                        *
 ******************************************************************************/
extern double
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
                                                    unsigned int toler);

extern float
tmpl_Float_Stationary_Cyl_Fresnel_Psi_D_Newton_Deg(float k,
                                                   float r,
                                                   float r0,
                                                   float phi,
                                                   float phi0,
                                                   float B,
                                                   float rx,
                                                   float ry,
                                                   float rz,
                                                   float eps,
                                                   unsigned int toler);

extern long double
tmpl_LDouble_Stationary_Cyl_Fresnel_Psi_D_Newton(long double k,
                                                 long double r,
                                                 long double r0,
                                                 long double phi,
                                                 long double phi0,
                                                 long double B,
                                                 long double rx,
                                                 long double ry,
                                                 long double rz,
                                                 long double eps,
                                                 unsigned int toler);

/******************************************************************************/
extern double
tmpl_Double_Stationary_Cyl_Fresnel_Psi_dD_dPhi_Newton(double k,
                                                      double r,
                                                      double r0,
                                                      double phi,
                                                      double phi0,
                                                      double B,
                                                      double rx,
                                                      double ry,
                                                      double rz,
                                                      double eps,
                                                      unsigned int toler);

extern double
tmpl_Double_Stationary_Cyl_Fresnel_Psi_dD_dPhi_Newton_Deg(double k,
                                                          double r,
                                                          double r0,
                                                          double phi,
                                                          double phi0,
                                                          double B,
                                                          double rx,
                                                          double ry,
                                                          double rz,
                                                          double eps,
                                                          unsigned int toler);

/*  End of extern "C" statement allowing C++ compatibility.                   */
#ifdef __cplusplus
}
#endif

#endif
/*  End of include guard.                                                     */
