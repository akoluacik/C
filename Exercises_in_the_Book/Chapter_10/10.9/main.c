#include <stdio.h>


union floatingPoint {
	char c;
	short s;
	int i;
	long b;
};

typedef union floatingPoint Float;

int main(){
	Float f;
	f.c = 'a';
	printf("c=%c s=%i i=%d b=%ld\n", f.c, f.s, f.i, f.b);
	f.s = 49;
	printf("c=%c s=%i i=%d b=%ld\n", f.c, f.s, f.i, f.b);
	f.i = 67;
	printf("c=%c s=%i i=%d b=%ld\n", f.c, f.s, f.i, f.b);
	f.b = 77;
	printf("c=%c s=%i i=%d b=%ld\n", f.c, f.s, f.i, f.b);
	return 0;
}
