/******************************************************************************
 *                                  LICENSE                                   *
 ******************************************************************************
 *  This file is part of libtmpl_experiments.                                 *
 *                                                                            *
 *  libtmpl_experiments is free software: you can redistribute it and/or      *
 *  modify it under the terms of the GNU General Public License as published  *
 *  by the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                       *
 *                                                                            *
 *  libtmpl_experiments is distributed in the hope that it will be useful,    *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 *  GNU General Public License for more details.                              *
 *                                                                            *
 *  You should have received a copy of the GNU General Public License along   *
 *  with libtmpl_experiments.  If not, see <https://www.gnu.org/licenses/>.   *
 ******************************************************************************/

/*  Function prototype provided here.                                         */
#include "error_function.h"

#if 1

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955125745760330241780086119828422823916E+00)
#define P01 (+1.4343640468334056155176867330351335600355211065798E-01)
#define P02 (+4.5474337004727553078898217128747813089436299695619E-02)
#define P03 (+1.8748198087220745226081152760199054494885436089003E-03)
#define P04 (+1.9678567923227989580221676306775698159538851158416E-04)
#define P05 (+7.3696648913103735807806175115005147789227107445326E-08)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00)
#define Q01 (+4.6045053725384797760281438988924454776819834747102E-01)
#define Q02 (+9.3784094288644792593728019540763983359179251368593E-02)
#define Q03 (+1.0687350641996694817758850886555825654428290771055E-02)
#define Q04 (+6.9191595185068288930898768882994885221058241870925E-04)
#define Q05 (+2.0783836614993649468633471293032045438449520367478E-05)

#define NUM_EVAL(z) P00 + z*(P01 + z*(P02 + z*(P03 + z*(P04 + z*P05))))
#define DEN_EVAL(z) Q00 + z*(Q01 + z*(Q02 + z*(Q03 + z*(Q04 + z*Q05))))

#else

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955124938475573609352049610120121044597E+00)
#define P01 (+8.8118554414781385974364141231775809003906275782836E-02)
#define P02 (+3.8174525622960428358232893166516989580842787239161E-02)
#define P03 (-1.6512134579920191241485886315165826201216377171439E-04)
#define P04 (+1.1890825688032048780331583748841205158854213615978E-04)
#define P05 (-3.0921059933069107266669293512244784260617430522963E-06)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00)
#define Q01 (+4.1142636888767124544652890922173692596611590341916E-01)
#define Q02 (+7.0973415436556028065448870524028079599831414989336E-02)
#define Q03 (+6.1783570761603794456940715597216373780221488456877E-03)
#define Q04 (+2.3372686280898360241350381808463274932397135122824E-04)

#define NUM_EVAL(z) P00 + z*(P01 + z*(P02 + z*(P03 + z*(P04 + z*P05))))
#define DEN_EVAL(z) Q00 + z*(Q01 + z*(Q02 + z*(Q03 + z*Q04)))

#endif

double Erf_Double_Rat_Remez_Small(double x)
{
    const double x2 = x*x;
    const double p = NUM_EVAL(x2);
    const double q = DEN_EVAL(x2);
    return x * p / q;
}
