#ifndef LIB_TP_MATH
#define LIB_TP_MATH

#define M_PI ((double)3.141592653589793238462643383279502884e+00)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include <stdint.h>
#include <stdio.h>
#include "addrs.h"
#include "tp.h"

typedef double (*tp_atan_t)(double x);
typedef double (*tp_ceil_t)(double x);
typedef double (*tp_copysign_t)(double x, double y);
typedef double (*tp_cos_t)(double x);
typedef double (*tp_floor_t)(double x);
typedef double (*tp_frexp_t)(double x, int *exponent);
typedef double (*tp_ldexp_t)(double x, int exponent);
typedef double (*tp_modf_t)(double x, double *iptr);
typedef double (*tp_sin_t)(double x);
typedef double (*tp_tan_t)(double x);
typedef double (*tp_acos_t)(double x);
typedef double (*tp_asin_t)(double x);
typedef double (*tp_atan2_t)(double x, double y);
typedef double (*tp_exp_t)(double x);
typedef double (*tp_fmod_t)(double x, double y);
typedef double (*tp_pow_t)(double x, double y);
typedef double (*tp_fastSqrt_t)(double x);
typedef double (*tp_sqrt_t)(double x);

#define tp_atan ((tp_atan_t)tp_atan_addr)
#define tp_ceil ((tp_ceil_t)tp_ceil_addr)
#define tp_copysign ((tp_copysign_t)tp_copysign_addr)
#define tp_cos ((tp_cos_t)tp_cos_addr)
#define tp_floor ((tp_floor_t)tp_floor_addr)
#define tp_frexp ((tp_frexp_t)tp_frexp_addr)
#define tp_ldexp ((tp_ldexp_t)tp_ldexp_addr)
#define tp_modf ((tp_modf_t)tp_modf_addr)
#define tp_sin ((tp_sin_t)tp_sin_addr)
#define tp_tan ((tp_tan_t)tp_tan_addr)
#define tp_acos ((tp_acos_t)tp_acos_addr)
#define tp_asin ((tp_asin_t)tp_asin_addr)
#define tp_atan2 ((tp_atan2_t)tp_atan2_addr)
#define tp_exp ((tp_exp_t)tp_exp_addr)
#define tp_fmod ((tp_fmod_t)tp_fmod_addr)
#define tp_pow ((tp_pow_t)tp_pow_addr)
#define tp_fastSqrt ((tp_fastSqrt_t)tp_fastSqrt_addr)
#define tp_sqrt ((tp_sqrt_t)tp_sqrt_addr)

#endif // !LIB_TP_MATH
