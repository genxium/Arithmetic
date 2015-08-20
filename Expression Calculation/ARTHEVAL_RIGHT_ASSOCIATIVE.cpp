#include <stdio.h>
#include <ctype.h>
#include <cstring>

#define MX 1024
#define MOD 1000000007

#define EXPRESSION 0
#define FACTOR 1
#define TERM 2

long read_int(char** p_s) {
	long ret = 0;
	while (*(*p_s) != '\0' && isdigit(*(*p_s))) {
		ret *= 10;
		ret += (long)(*(*p_s) - '0');
		++(*p_s);
	}
	return ret;
}

long mod_add(long a, long b, long mod) {
	return (a + b) % mod;
}

long mod_sub(long a, long b, long mod) {
	return (a - b + mod) % mod;
}

long mod_mul(long a, long b, long mod) {
	return (a * b + mod) % mod;
}

long mod_pow(long a, long n, long mod) {
	long ret = 1, tmp = 0;
	while(n){
		if(n & 1)	ret = mod_mul(ret, a, mod); 
		a = mod_mul(a, a, mod);
		n >>= 1;
	}
	return ret;
}

long prime_mod_div(long a, long b, long mod) {
	int n = mod - 2;	
	long tmp =  mod_pow(b, n, mod);
	return mod_mul(a, tmp, mod);
}

long eval(char** p_s, int priority) {
	while (*(*p_s) == ' ' && *(*p_s) != '\0') ++(*p_s);
	if (*(*p_s) == '\0') return 0;

	int ret;
	char op = ' ';

	switch (priority) {
		case EXPRESSION: {
			ret = eval(p_s, TERM);	
			while (*(*p_s) == ' ' && *(*p_s) != '\0') ++(*p_s);
			if (*(*p_s) == '\0') return ret;
		
			if (*(*p_s) != '+' && *(*p_s) != '-') break;
			op = *((*p_s)++); 

			int tmp = eval(p_s, EXPRESSION);	
			if (op == '+') ret = mod_add(ret, tmp, MOD);
			else ret = mod_sub(ret, tmp, MOD);

			break;
		}
		case TERM: {
			ret = eval(p_s, FACTOR);	
			while (*(*p_s) == ' ' && *(*p_s) != '\0') ++(*p_s);
			if (*(*p_s) == '\0') return ret;

			if (*(*p_s) != '*' && *(*p_s) != '/') break;
			op = *((*p_s)++); 

			int tmp = eval(p_s, TERM);	
			if (op == '*') ret = mod_mul(ret, tmp, MOD);
			else ret = prime_mod_div(ret, tmp, MOD);
			break;	
		}
		case FACTOR: {
			int unary_factor = 1;
			char possible_op = *(*p_s);
			if (possible_op == '+' || possible_op == '-') ++(*p_s);  
			if (possible_op == '-') unary_factor = (-1); 
			if (isdigit(*(*p_s))) ret = read_int(p_s); 	
			else {
				++(*p_s);
				ret = eval(p_s, EXPRESSION);
				while (*(*p_s) == ' ' && *(*p_s) != ')') ++(*p_s);
				++(*p_s);
			}
			ret *= unary_factor;
			break;
		}
		default:
			ret = 0;
		break;
	}
	return ret;
}

int main() {
	char in_s[MX];
	while (fgets(in_s, MX, stdin)) {
		char* s = in_s;
		long result = eval(&s, EXPRESSION);
		printf("%ld\n", result);
		bzero(in_s, sizeof in_s);	
	}
	return 0;
}
