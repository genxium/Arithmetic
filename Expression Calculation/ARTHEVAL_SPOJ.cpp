#include <stdio.h>
#include <cstring>
#include "eval.h"

#define MX 1024

static long eval(char** p_s, int priority) {
	while (*(*p_s) == ' ' && *(*p_s) != '\0') ++(*p_s);
	if (*(*p_s) == '\0')	return 0;

	long ret;
	char op = ' ';

	switch (priority) {
		case EXPRESSION: {
			while (*(*p_s) != ' ' && *(*p_s) != '\0') {	
				long tmp = eval(p_s, FACTOR);	

				if (op == '+') ret += tmp;
				else if (op == '-') ret -= tmp;
				else if (op == '*') ret *= tmp;
				else ret = tmp; // op == ' '

				while (*(*p_s) == ' ' && *(*p_s) != '\0') ++(*p_s);
				if (*(*p_s) == '\0')	return ret;

				if (*(*p_s) != '+' && *(*p_s) != '-' && *(*p_s) != '*') break;
				op = *((*p_s)++); 
			}
		
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
