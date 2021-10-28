#include <stdio.h>

union integer {
	char c;
	short s;
	int i;
	long b;
};
typedef union integer integer;

int main(){
	integer Int;
	Int.c =  'a';
	printf("c=%c s=%i i=%d b=%l\n", Int.c, Int.s, Int.i, Int.b);
	Int.s = 30;
	printf("c=%c s=%i i=%d b=%l\n", Int.c, Int.s, Int.i, Int.b);
	Int.i = 47;
	printf("c=%c s=%i i=%d b=%l\n", Int.c, Int.s, Int.i, Int.b);
	Int.b = 79;
	printf("c=%c s=%i i=%d b=%ld", Int.c, Int.s, Int.i, Int.b);
	return 0;
}
