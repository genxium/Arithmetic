#ifndef _EVALH_
#define _EVALH_

#include <ctype.h>

#define EXPRESSION 0
#define FACTOR 1
#define TERM 2

long read_int(char** p_s);
long mod_add(long a, long b, long mod);
long mod_sub(long a, long b, long mod);
long mod_mul(long a, long b, long mod);
long mod_pow(long a, long n, long mod);
long prime_mod_div(long a, long b, long mod);

#endif
