/*
 * Copyright (c) 2015-2015 Texas Instruments Incorporated
 *
 * Copyright (c) 2004-2011 David Schultz <das@FreeBSD.ORG>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef	_FENV_H_
#error "This file is meant to be included only by <fenv.h>."
#endif

/*
 * This file implements the functionality of <fenv.h> on platforms that
 * lack an FPU and use softfloat in libc for floating point.  To use it,
 * you must write an <fenv.h> that provides the following:
 *
 *   - a typedef for fenv_t, which may be an integer or struct type
 *   - a typedef for fexcept_t (XXX This file assumes fexcept_t is a
 *     simple integer type containing the exception mask.)
 *   - definitions of FE_* constants for the five exceptions and four
 *     rounding modes in IEEE 754, as described in fenv(3)
 *   - a definition, and the corresponding external symbol, for FE_DFL_ENV
 *   - a macro __set_env(env, flags, mask, rnd), which sets the given fenv_t
 *     from the exception flags, mask, and rounding mode
 *   - macros __env_flags(env), __env_mask(env), and __env_round(env), which
 *     extract fields from an fenv_t
 *   - a definition of __fenv_static.  This should be defined as an
 *     empty macro by fenv.c when including fenv.h, and defined as
 *     "static" by fenv.h iff it's undefined.  When compiling fenv.c,
 *     we're creating library functions.  When including fenv.h in
 *     some other file, we want these functions to be inlined.
 *
 * If the architecture supports an optional FPU, it's recommended that you
 * define fenv_t and fexcept_t to match the hardware ABI.  Otherwise, it
 * doesn't matter how you define them.
 */

_TI_PROPRIETARY_PRAGMA("diag_push")
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-5.7\")") /* no reused identifiers */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-8.1\")") /* visible prototypes */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-8.5\")") /* functions in header files */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-10.1\")") /* implicit integer conversion */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-12.1\")") /* precedence rules */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-12.6\")") /* bool mixed with non-bool */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-12.7\")") /* bitwise ops on signeds */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-14.7\")") /* single exit */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-14.9\")") /* if (...) {...} */
_TI_PROPRIETARY_PRAGMA("CHECK_MISRA(\"-16.3\")") /* named params */

__BEGIN_DECLS
extern _DATA_ACCESS int __softfloat_float_exception_flags;
extern _DATA_ACCESS int __softfloat_float_exception_mask;
extern _DATA_ACCESS int __softfloat_float_rounding_mode;
_CODE_ACCESS void __softfloat_float_raise(int);
__END_DECLS

__fenv_static int
feclearexcept(int __excepts)
{

	__softfloat_float_exception_flags &= ~__excepts;
	return (0);
}

__fenv_static int
fegetexceptflag(fexcept_t *__flagp, int __excepts)
{

	*__flagp = __softfloat_float_exception_flags & __excepts;
	return (0);
}

__fenv_static int
fesetexceptflag(const fexcept_t *__flagp, int __excepts)
{

	__softfloat_float_exception_flags &= ~__excepts;
	__softfloat_float_exception_flags |= *__flagp & __excepts;
	return (0);
}

__fenv_static int
feraiseexcept(int __excepts)
{

	__softfloat_float_raise(__excepts);
	return (0);
}

__fenv_static int
fetestexcept(int __excepts)
{

	return (__softfloat_float_exception_flags & __excepts);
}

__fenv_static int
fegetround(void)
{

	return (__softfloat_float_rounding_mode);
}

__fenv_static int
fesetround(int __round)
{
#if __TI_COMPILER_VERSION__
        if (__round != FE_TONEAREST) return 1;
#endif
	__softfloat_float_rounding_mode = __round;
	return (0);
}

__fenv_static int
fegetenv(fenv_t *__envp)
{

	__set_env(*__envp, __softfloat_float_exception_flags,
	    __softfloat_float_exception_mask, __softfloat_float_rounding_mode);
	return (0);
}

__fenv_static int
feholdexcept(fenv_t *__envp)
{
	fegetenv(__envp);
	__softfloat_float_exception_flags = 0;
	__softfloat_float_exception_mask = 0;
	return (0);
}

__fenv_static int
fesetenv(const fenv_t *__envp)
{

	__softfloat_float_exception_flags = __env_flags(*__envp);
	__softfloat_float_exception_mask = __env_mask(*__envp);
	__softfloat_float_rounding_mode = __env_round(*__envp);
	return (0);
}

__fenv_static int
feupdateenv(const fenv_t *__envp)
{
	int __oflags = __softfloat_float_exception_flags;

	fesetenv(__envp);
	feraiseexcept(__oflags);
	return (0);
}

#if __BSD_VISIBLE

/* We currently provide no external definitions of the functions below. */

__fenv_static int
feenableexcept(int __mask)
{
	int __omask = __softfloat_float_exception_mask;

	__softfloat_float_exception_mask |= __mask;
	return (__omask);
}

__fenv_static int
fedisableexcept(int __mask)
{
	int __omask = __softfloat_float_exception_mask;

	__softfloat_float_exception_mask &= ~__mask;
	return (__omask);
}

__fenv_static int
fegetexcept(void)
{

	return (__softfloat_float_exception_mask);
}

#endif /* __BSD_VISIBLE */

_TI_PROPRIETARY_PRAGMA("diag_pop")
