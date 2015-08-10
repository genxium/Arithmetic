#include <stdio.h>
#include <ctype.h>
#include <cstring>

#define EXPRESSION 0
#define FACTOR 1
#define TERM 2

int readInt(char* s, int& len, int &cur) {
	int ret = 0;
	while (cur < len && isdigit(s[cur])) {
		ret *= 10;
		ret += (int)(s[cur] - '0');
		++cur;
	}
	return ret;
}

int eval(char* s, int &len, int &cur, int priority) {
	int ret; char op = ' ';
	while (s[cur] == ' ') ++cur;
	switch (priority) {
		case EXPRESSION:
			while (cur < len) {
				int tmp = eval(s, len, cur, TERM);	
				if (op == '+') ret += tmp;
				else if (op == '-') ret -= tmp;
				else ret = tmp; // op == ' '
				while (s[cur] == ' ') ++cur;
				if (cur == len)	break;
				if (s[cur] != '+' && s[cur] != '-') break;
				op = s[cur++]; 
			}
		break;
		case TERM:
			while (cur < len) {
				int tmp = eval(s, len, cur, FACTOR);
				if (op == '*') ret *= tmp;
				else ret = tmp; // op == ' '
				while (s[cur] == ' ') ++cur;
				if (cur == len) break;
				if (s[cur] != '*') break;
				op = s[cur++];
			}
		break;	
		case FACTOR:
			ret = 0;
			if (isdigit(s[cur])) ret = readInt(s, len, cur); 	
			else {
				++cur; // skip '('
				ret = eval(s, len, cur, EXPRESSION);
				++cur; // skip ')'
			}
		break;
		default:
			ret = 0;
		break;
	}
	return ret;
}

int main() {
	char s[1024];
	while (scanf("%s", s) != EOF) {
		int len = strlen(s);
		int cur = 0;
		int result = eval(s, len, cur, EXPRESSION);
		printf("%d\n", result);
		bzero(s, sizeof s);	
	}
	return 0;
}

/**
 *  sample in:
 *
 *  1+1+1
 *	1+1*2+2*(3+5*4)
 *	1+2*3
 *	55+68*(5*72+32*3*1*1*2*1*1*(4+5*(7+3+2+3*4*(5+2*3*2)*5*5)))
 *
 *	sample out:
 *
 *	3
 *	49
 *	7
 *  333788119
 *
 * */
