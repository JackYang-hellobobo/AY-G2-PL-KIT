/*****************************************************************************/
/* float.h                                                                   */
/*                                                                           */
/* Copyright (c) 1993 Texas Instruments Incorporated                         */
/* http://www.ti.com/                                                        */
/*                                                                           */
/*  Redistribution and  use in source  and binary forms, with  or without    */
/*  modification,  are permitted provided  that the  following conditions    */
/*  are met:                                                                 */
/*                                                                           */
/*     Redistributions  of source  code must  retain the  above copyright    */
/*     notice, this list of conditions and the following disclaimer.         */
/*                                                                           */
/*     Redistributions in binary form  must reproduce the above copyright    */
/*     notice, this  list of conditions  and the following  disclaimer in    */
/*     the  documentation  and/or   other  materials  provided  with  the    */
/*     distribution.                                                         */
/*                                                                           */
/*     Neither the  name of Texas Instruments Incorporated  nor the names    */
/*     of its  contributors may  be used to  endorse or  promote products    */
/*     derived  from   this  software  without   specific  prior  written    */
/*     permission.                                                           */
/*                                                                           */
/*  THIS SOFTWARE  IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS    */
/*  "AS IS"  AND ANY  EXPRESS OR IMPLIED  WARRANTIES, INCLUDING,  BUT NOT    */
/*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR    */
/*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT    */
/*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,    */
/*  SPECIAL,  EXEMPLARY,  OR CONSEQUENTIAL  DAMAGES  (INCLUDING, BUT  NOT    */
/*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,    */
/*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY    */
/*  THEORY OF  LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT    */
/*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    */
/*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     */
/*                                                                           */
/*****************************************************************************/

/********************************************************************/
/*    KEY:  FLT_     - APPLIES TO TYPE FLOAT                        */
/*          DBL_     - APPLIES TO TYPE DOUBLE                       */
/*          LDBL_    - APPLIES TO TYPE LONG DOUBLE                  */
/********************************************************************/
#ifndef _FLOAT_H_
#define _FLOAT_H_

#include <_ti_config.h>

_TI_PROPRIETARY_PRAGMA("diag_push")
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-20.1\")") /* standard headers must define standard names */

#define FLT_RADIX                         2   /* RADIX OF EXPONENT         */
#define FLT_ROUNDS                        1   /* ROUND TO NEAREST          */
#define FLT_EVAL_METHOD                 (-1)  /* INDETERMINABLE            */

#define FLT_DIG                           6   /* DECIMAL PRECISION         */
#define FLT_DECIMAL_DIG                    9  /* DECIMAL PRECISION         */
#define FLT_MANT_DIG                     24   /* BITS IN MANTISSA          */
#define FLT_MIN_EXP                   (-125)  /* SMALLEST EXPONENT         */
#define FLT_MAX_EXP                     128   /* LARGEST EXPONENT          */
#define FLT_MIN_10_EXP                 (-37)  /* MIN POWER OF 10           */
#define FLT_MAX_10_EXP                   38   /* MAX POWER OF 10           */
#define FLT_EPSILON         1.192092896E-07F  /* SMALLEST X WHERE 1+X != 1 */
#define FLT_MIN             1.175494351E-38F  /* MIN NORMALIZED POS VALUE  */
#define FLT_MAX             3.402823466E+38F  /* MAX POSITIVE VALUE        */
#if defined(_TI_C11LIB) || __TI_PROPRIETARY_STRICT_ANSI_MACRO == 0
#define FLT_TRUE_MIN        1.401298464E-45F  /* MIN POSITIVE VALUE        */
#define FLT_HAS_SUBNORM                    0  /* SUPPORTS SUBNORMAL        */
#endif

#if defined(__TMS320C2000__) && !defined(__TI_EABI__) || defined(__MSP430__) && !defined(__TI_EABI__)

#define DBL_DIG             (FLT_DIG)         /* DECIMAL PRECISION         */
#define DBL_DECIMAL_DIG     (FLT_DECIMAL_DIG) /* DECIMAL PRECISION         */
#define DBL_MANT_DIG        (FLT_MANT_DIG)    /* BITS IN MANTISSA          */
#define DBL_MIN_EXP         (FLT_MIN_EXP)     /* SMALLEST EXPONENT         */
#define DBL_MAX_EXP         (FLT_MAX_EXP)     /* LARGEST EXPONENT          */
#define DBL_MIN_10_EXP      (FLT_MIN_10_EXP)  /* MIN POWER OF 10           */
#define DBL_MAX_10_EXP      (FLT_MAX_10_EXP)  /* MAX POWER OF 10           */
#define DBL_EPSILON         1.192092896E-07   /* SMALLEST X WHERE 1+X != 1 */
#define DBL_MIN             1.175494351E-38   /* MIN NORMALIZED POS VALUE  */
#define DBL_MAX             3.402823466E+38   /* MAX POSITIVE VALUE        */
#if defined(_TI_C11LIB) || __TI_PROPRIETARY_STRICT_ANSI_MACRO == 0
#define DBL_TRUE_MIN        ((double)(FLT_TRUE_MIN))
#define DBL_HAS_SUBNORM     (FLT_HAS_SUBNORM)
#endif /* C11 IS VISIBLE */

#else

#define DBL_DIG                          15   /* DECIMAL PRECISION         */
#define DBL_DECIMAL_DIG                  17   /* DECIMAL PRECISION         */
#define DBL_MANT_DIG                     53   /* BITS IN MANTISSA          */
#define DBL_MIN_EXP                  (-1021)  /* SMALLEST EXPONENT         */
#define DBL_MAX_EXP                    1024   /* LARGEST EXPONENT          */
#define DBL_MIN_10_EXP                (-307)  /* MIN POWER OF 10           */
#define DBL_MAX_10_EXP                  308   /* MAX POWER OF 10           */
#define DBL_EPSILON  2.2204460492503131E-16   /* SMALLEST X WHERE 1+X != 1 */
#define DBL_MIN     2.2250738585072014E-308   /* MIN NORMALIZED POS VALUE  */
#define DBL_MAX     1.7976931348623157E+308   /* MAX POSITIVE VALUE        */
#if defined(_TI_C11LIB) || __TI_PROPRIETARY_STRICT_ANSI_MACRO == 0
#define DBL_TRUE_MIN 4.9406564584124654E-324
#define DBL_HAS_SUBNORM                   0
#endif

#endif

#if defined(__MSP430__) && !defined(__TI_EABI__)

#define LDBL_DIG            (FLT_DIG)         /* DECIMAL PRECISION         */
#define LDBL_DECIMAL_DIG    (FLT_DECIMAL_DIGIT)/* DECIMAL PRECISION        */
#define LDBL_MANT_DIG       (FLT_MANT_DIG)    /* BITS IN MANTISSA          */
#define LDBL_MIN_EXP        (FLT_MIN_EXP)     /* SMALLEST EXPONENT         */
#define LDBL_MAX_EXP        (FLT_MAX_EXP)     /* LARGEST EXPONENT          */
#define LDBL_MIN_10_EXP     (FLT_MIN_10_EXP)  /* MIN POWER OF 10           */
#define LDBL_MAX_10_EXP     (FLT_MAX_10_EXP)  /* MAX POWER OF 10           */
#define LDBL_EPSILON        1.192092896E-07L  /* SMALLEST X WHERE 1+X != 1 */
#define LDBL_MIN            1.175494351E-38L  /* MIN NORMALIZED POS VALUE  */
#define LDBL_MAX            3.402823466E+38L  /* MAX POSITIVE VALUE        */
#if defined(_TI_C11LIB) || __TI_PROPRIETARY_STRICT_ANSI_MACRO == 0
#define LDBL_TRUE_MIN       ((long double)FLT_TRUE_MIN)
#define LDBL_HAS_SUBNORM    (FLT_HAS_SUBNORM)              1
#endif

#else

#define LDBL_DIG                         15   /* DECIMAL PRECISION         */
#define LDBL_DECIMAL_DIG                 17   /* DECIMAL PRECISION         */
#define LDBL_MANT_DIG                    53   /* BITS IN MANTISSA          */
#define LDBL_MIN_EXP                 (-1021)  /* SMALLEST EXPONENT         */
#define LDBL_MAX_EXP                   1024   /* LARGEST EXPONENT          */
#define LDBL_MIN_10_EXP               (-307)  /* MIN POWER OF 10           */
#define LDBL_MAX_10_EXP                 308   /* MAX POWER OF 10           */
#define LDBL_EPSILON 2.2204460492503131E-16L  /* SMALLEST X WHERE 1+X != 1 */
#define LDBL_MIN    2.2250738585072014E-308L  /* MIN NORMALIZED POS VALUE  */
#define LDBL_MAX    1.7976931348623157E+308L  /* MAX POSITIVE VALUE        */
#if defined(_TI_C11LIB) || __TI_PROPRIETARY_STRICT_ANSI_MACRO == 0
#define LDBL_TRUE_MIN 4.9406564584124654E-324L
#define LDBL_HAS_SUBNORM                  0
#endif

#endif

#define DECIMAL_DIG        (LDBL_DECIMAL_DIG) /* LARGEST DECIMAL PRECISION */

_TI_PROPRIETARY_PRAGMA("diag_pop")

#endif /* _FLOAT_H_ */
