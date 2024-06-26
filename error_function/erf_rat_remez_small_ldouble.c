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

/*  TMPL_LDOUBLE_TYPE macro found here.                                       */
#include <libtmpl/include/tmpl_config.h>

/*  Function prototype provided here.                                         */
#include "error_function.h"

/*  64-bit long double does not need any more precision than 64-bit double.   */
#if TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_64_BIT

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

/*  double-double, more terms are needed.                                     */
#elif TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_DOUBLEDOUBLE

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955125738961589031215432827939072819249E+00L)
#define P01 (+1.3277572378802697922684058080094055871668002103359E-01L)
#define P02 (+4.9713619106779251453168012931635739154021515385982E-02L)
#define P03 (+2.0841657617009362809389628063446071466069255668076E-03L)
#define P04 (+3.9160383012310425251346794154496293702480056636002E-04L)
#define P05 (+4.3581825047857757019489711814076071330870575002132E-06L)
#define P06 (+7.7502082411323306795698384230515173569172674839945E-07L)
#define P07 (-5.1188550788408121839042226807438584564749127424985E-09L)
#define P08 (+3.0131551019545373733205394790554933574527328757833E-10L)
#define P09 (-2.8671685583841521684919428180941038041502081454069E-12L)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define Q01 (+4.5100275480076110791366163062511366830491389437151E-01L)
#define Q02 (+9.4391799414384164745122590564964356167532201835832E-02L)
#define Q03 (+1.2020225282701879927744837177646169333738860376235E-02L)
#define Q04 (+1.0231428767876535522837177035532528199099376993219E-03L)
#define Q05 (+5.9911272493617434906379752832485516323507877868084E-05L)
#define Q06 (+2.3708963086637415746296190137820587375022318822063E-06L)
#define Q07 (+5.8385792517932240596859779924747512184911368640894E-08L)
#define Q08 (+6.9094999069421294000315396462065516458445628698350E-10L)

#define NUM_EVAL(z) \
P00+z*(P01+z*(P02+z*(P03+z*(P04+z*(P05+z*(P06+z*(P07+z*(P08+z*P09))))))))

#define DEN_EVAL(z) \
Q00+z*(Q01+z*(Q02+z*(Q03+z*(Q04+z*(Q05+z*(Q06+z*(Q07+z*Q08)))))))

/*  128-bit quadruple, a few more terms.                                      */
#elif TMPL_LDOUBLE_TYPE == TMPL_LDOUBLE_128_BIT

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955125738961589031215451821960287522086E+00L)
#define P01 (+1.6361739190757145556381195049496074798217293625218E-01L)
#define P02 (+5.4233901026078197887180087599953387763896446237791E-02L)
#define P03 (+3.5428385690321877908729572320113338024540668987843E-03L)
#define P04 (+4.8641092478003358728868510937771221629041679954841E-04L)
#define P05 (+1.6404161420441645656555492549718280010124579988967E-05L)
#define P06 (+1.1609935763499093787527359210081208912076678479098E-06L)
#define P07 (+1.7028589250383024422214664870174459242127706199879E-08L)
#define P08 (+5.5882782777746446839920053943335514862577247293087E-10L)
#define P09 (+1.2999618709065797164934672499604365981535355121690E-13L)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define Q01 (+4.7833547151417935397394026031707792465082005291844E-01L)
#define Q02 (+1.0750870053304357741541869552116078157049713387478E-01L)
#define Q03 (+1.4951969101529244496677322540912090673802505444482E-02L)
#define Q04 (+1.4235002739068539910616152745411097675365480396773E-03L)
#define Q05 (+9.6631641512948249482034763427784443780811431323481E-05L)
#define Q06 (+4.7009728094086930901818961792428380494221587715944E-06L)
#define Q07 (+1.5898390787909563546730038561907585485586867411174E-07L)
#define Q08 (+3.4158434955715543503487896252406480016879421400964E-09L)
#define Q09 (+3.5831638168065023936748103313360044201908867651531E-11L)

#define NUM_EVAL(z) \
P00+z*(P01+z*(P02+z*(P03+z*(P04+z*(P05+z*(P06+z*(P07+z*(P08+z*P09))))))))

#define DEN_EVAL(z) \
Q00+z*(Q01+z*(Q02+z*(Q03+z*(Q04+z*(Q05+z*(Q06+z*(Q07+z*(Q08+z*Q09))))))))

#else

/*  Coefficients for the numerator of the Remez rational approximation.       */
#define P00 (+1.1283791670955125739044434138319433938942556519782E+00L)
#define P01 (+1.0386485782565763952735372734147588245859288293155E-01L)
#define P02 (+4.2334249282530358644247733361231408692311569236430E-02L)
#define P03 (+5.3326914778191522038431155309525314977180912270042E-04L)
#define P04 (+2.0113953435167009916508487730458985080770107018735E-04L)
#define P05 (-4.0513529169880760452814132801702632479243698271236E-06L)
#define P06 (+1.0587940983771269183186790761552683489285076098459E-07L)

/*  Coefficients for the denominator of the Remez rational approximation.     */
#define Q00 (+1.0000000000000000000000000000000000000000000000000E+00L)
#define Q01 (+4.2538116694675373829554577839774257968847736850513E-01L)
#define Q02 (+7.9311473898591970937834987858418259198183680614847E-02L)
#define Q03 (+8.1811625583256249733158184915865231754251887740349E-03L)
#define Q04 (+4.7265546025345986641687578185702585937097522379811E-04L)
#define Q05 (+1.2432075704897938138859501021741494931597401927988E-05L)

#define NUM_EVAL(z) P00+z*(P01+z*(P02+z*(P03+z*(P04+z*(P05+z*P06)))))
#define DEN_EVAL(z) Q00+z*(Q01+z*(Q02+z*(Q03+z*(Q04+z*Q05))))

#endif

long double Erf_LDouble_Rat_Remez_Small(long double x)
{
    const long double x2 = x*x;
    const long double p = NUM_EVAL(x2);
    const long double q = DEN_EVAL(x2);
    return x * p / q;
}
