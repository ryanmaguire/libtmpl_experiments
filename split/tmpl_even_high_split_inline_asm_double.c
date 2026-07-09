/*  GCC, Clang, and Solaris Developer Studio C all support inline assembly.   *
 *  Note, several compilers (AOCC, ICX, IBM Open XL C, etc.) define the       *
 *  __clang__ macro, and hence will also trigger this branch.                 */
#if defined(__GNUC__) || defined(__clang__) || defined(__SUNPRO_C)

/*  AVX, AVX2, and AVX-512 support VEX scalar operations that can be used.    */
#if defined(__AVX__) || defined(__AVX2__) || defined(__AVX512F__)

/******************************************************************************
 *                      x86-64 / amd64 with AVX Support                       *
 ******************************************************************************/

/*  Function for splitting a double evenly down the middle.                   */
TMPL_ALWAYS_INLINE
double tmpl_Double_Even_High_Split(const double x)
{
    /*  The scale factor for the split is 2^27 + 1.                           */
    const double c = 134217729.0;

    /*  Variables for the product, difference, and output, respectively.      */
    double prod, diff, result;

    /*  With AVX / AVX2 / AVX-512, the split can be performed in 3 lines.     */
    __asm__(

        /*  AVX, AVX2, and AVX-512 have VEX instructions. First set           *
         *  prod = x * c. This rounds out the lower order bits of the input.  */
        "vmulsd %[c], %[x], %[prod]\n\t"

        /*  Compute diff = prod - x, which clears out the lower order bits of *
         *  the product, which means the bits from "x" have been removed.     */
        "vsubsd %[x], %[prod], %[diff]\n\t"

        /*  Finally, compute result = prod - diff. Since diff contains only   *
         *  the higher bits of the product, and since prod contains the bits  *
         *  from the product and the higher bits from the input, this clears  *
         *  the higher bits from the product, leaving us only with the higher *
         *  bits from the input.                                              */
        "vsubsd %[diff], %[prod], %[result]"

        :

        /*  The difference requires the product and the input x to have been  *
         *  already computed. Use an early clobber (&) with the product and   *
         *  difference to prevent the compiler from overwriting registers.    */
        [prod] "=&x" (prod),
        [diff] "=&x" (diff),

        /*  The result is output only, and loaded into an SSE / AVX register. */
        [result] "=x"  (result)

        :

        /*  The input comes from a register, use "x" for this.                */
        [x] "x" (x),

        /*  The constant c will likely be stored in read-only memory, but it  *
         *  may also live in a register. "x" allows registers, "m" allows     *
         *  memory, provide both options to the compiler.                     */
        [c] "xm" (c)
    );

    return result;
}
/*  End of tmpl_Double_Even_High_Split.                                       */

/*  SSE2 support means we can use XMM registers.                              */
#elif defined(__SSE2__) || defined(__SSE3__) || defined(__SSE4_1__)

/******************************************************************************
 *                      x86-64 / amd64 with SSE Support                       *
 ******************************************************************************/

/*  Function for splitting a double evenly down the middle.                   */
TMPL_ALWAYS_INLINE
double tmpl_Double_Even_High_Split(const double x)
{
    /*  The scale factor for the split is 2^27 + 1.                           */
    const double c = 134217729.0;

    /*  Variables for the product, difference, and output, respectively.      */
    double prod, diff, result;

    /*  With SSE we operate on two operands at a time. This means extra moves *
     *  are required to perform something like prod = x * c.                  */
    __asm__(

        /*  Load the constant 2^27 + 1 into a register.                       */
        "movsd %[c], %[prod]\n\t"

        /*  prod now has c stored in it. Compute x * c and store it in prod.  */
        "mulsd %[x], %[prod]\n\t"

        /*  The difference is x * c - x. Store x * c in diff.                 */
        "movapd %[prod], %[diff]\n\t"

        /*  Compute diff = prod - x, which clears out the lower order bits of *
         *  the product, which means the bits from "x" have been removed.     */
        "subsd %[x], %[diff]\n\t"

        /*  Finally, compute result = prod - diff. Since diff contains only   *
         *  the higher bits of the product, and since prod contains the bits  *
         *  from the product and the higher bits from the input, this clears  *
         *  the higher bits from the product, leaving us only with the higher *
         *  bits from the input.                                              */
        "subsd %[diff], %[prod]\n\t"

        /*  Copy the final value into the result so it may be returned.       */
        "movapd %[prod], %[result]"

        :

        /*  Use "x" for SSE registers.                                        */
        [prod] "=&x" (prod),
        [diff] "=&x" (diff),
        [result] "=x" (result)

        :

        /*  The input comes from a register, use "x" for this.                */
        [x] "x" (x),

        /*  The constant will live in a register or memory. Use "xm".         */
        [c] "xm" (c)
    );

    return result;
}
/*  End of tmpl_Double_Even_High_Split.                                       */

/*  armv8 and higher have hardware floating-point instructions.               */
#elif defined(__aarch64__)

/******************************************************************************
 *                             armv8-a / aarch64                              *
 ******************************************************************************/

/*  Function for splitting a double evenly down the middle.                   */
TMPL_ALWAYS_INLINE
double tmpl_Double_Even_High_Split(const double x)
{
    /*  The scale factor for the split is 2^27 + 1.                           */
    const double c = 134217729.0;

    /*  Variables for the product, difference, and output, respectively.      */
    double prod, diff, result;

    /*  Splitting algorithm using armv8 (aarch64) instructions.               */
    __asm__(

        /*  Set prod = x * c.                                                 */
        "fmul %d[prod], %d[x], %d[c]\n\t"

        /*  Compute diff = prod - x = x * c - x.                              */
        "fsub %d[diff], %d[prod], %d[x]\n\t"

        /*  Lastly, compute result = prod - diff = (x * c) - ((x * c) - x).   */
        "fsub %d[result], %d[prod], %d[diff]"

        :

        /*  "w" is the identifier for 64-bit floating-point registers d0-d31. */
        [prod] "=&w" (prod),
        [diff] "=&w" (diff),
        [result] "=w" (result)

        :

        /*  The inputs live in registers, use "w" for this.                   */
        [x] "w" (x),
        [c] "w" (c)
    );

    return result;
}
/*  End of tmpl_Double_Even_High_Split.                                       */

/*  armv7 may have VFP registers but it may also use soft float. Check first. */
#elif defined(__arm__) && defined(__ARM_PCS_VFP) && defined(__VFP_FP__)

/******************************************************************************
 *                         armv7 with Hardware Float                          *
 ******************************************************************************/

/*  Function for splitting a double evenly down the middle.                   */
TMPL_ALWAYS_INLINE
double tmpl_Double_Even_High_Split(const double x)
{
    /*  The scale factor for the split is 2^27 + 1.                           */
    const double c = 134217729.0;

    /*  Variables for the product, difference, and output, respectively.      */
    double prod, diff, result;

    /*  Splitting algorithm using armv7 (armhf) instructions.                 */
    __asm__(

        /*  Set prod = x * c.                                                 */
        "vmul.f64 %P[prod], %P[x], %P[c]\n\t"

        /*  Compute diff = prod - x = x * c - x.                              */
        "vsub.f64 %P[diff], %P[prod], %P[x]\n\t"

        /*  Lastly, compute result = prod - diff = (x * c) - ((x * c) - x).   */
        "vsub.f64 %P[result], %P[prod], %P[diff]"

        :

        /*  "w" is the identifier for 64-bit floating-point registers d0-d31, *
         *  just like aarch64 / armv8.                                        */
        [prod] "=&w" (prod),
        [diff] "=&w" (diff),
        [result] "=w"  (result)

        :

        /*  The inputs live in registers, use "w" for this.                   */
        [x] "w" (x),
        [c] "w" (c)
    );

    return result;
}
/*  End of tmpl_Double_Even_High_Split.                                       */

/*  GCC can magically handle PowerPC, ppc64, and ppc64le with the same code.  */
#elif defined(__powerpc__)

/******************************************************************************
 *           PowerPC (32-bit / 64-bit / little-endian / big-endian)           *
 ******************************************************************************/

/*  Function for splitting a double evenly down the middle.                   */
TMPL_ALWAYS_INLINE
double tmpl_Double_Even_High_Split(const double x)
{
    /*  The scale factor for the split is 2^27 + 1.                           */
    const double c = 134217729.0;

    /*  Variables for the product, difference, and output, respectively.      */
    double prod, diff, result;

    /*  Splitting algorithm with PowerPC assembly.                            */
    __asm__(

        /*  Compute prod = x * c.                                             */
        "fmul %[prod], %[x], %[c]\n\t"

        /*  Compute diff = prod - x.                                          */
        "fsub %[diff], %[prod], %[x]\n\t"

        /*  Lastly, compute result = prod - diff.                             */
        "fsub %[result], %[prod], %[diff]"

        :

        /*  "f" is the identifier for 64-bit floating-point registers.        */
        [prod] "=&f" (prod),
        [diff] "=&f" (diff),
        [result] "=f"  (result)

        :

        /*  The inputs live in registers, use "f" for this.                   */
        [x] "f" (x),
        [c] "f" (c)
    );

    return result;
}
/*  End of tmpl_Double_Even_High_Split.                                       */

#else
/*  Else for AVX vs. SSE vs. ...                                              */

/*  Other architectures (HPPA, SH4, SPARC, SPARC64) use the default method.   */
#define TMPL_DOUBLE_EVEN_HIGH_SPLIT_USE_DEFAULT 1

#endif
/*  End of AVX vs SSE vs ...                                                  */

#else
/*  Else for GCC / Clang / Solaris C.                                         */

/*  Recent versions of IBM XL C and Intel's ICX provide the __clang__ macro,  *
 *  and hence will be handled by one of the versions above. Other compilers   *
 *  like TCC, PCC, and MSVC use the default method.                           */
#define TMPL_DOUBLE_EVEN_HIGH_SPLIT_USE_DEFAULT 1

#endif
/*  End of GCC / Clang / Solaris C.                                           */
