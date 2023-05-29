#include <stdio.h>

void displayInBits(unsigned int, unsigned int);
void displayInInt(unsigned int, unsigned int);

int main(){
	
	unsigned int base, pow;
	printf("%s", "Enter a base(non-negative):"); scanf("%u", &base);
	printf("%s", "Enter a pow(non-negative):"); scanf("%u", &pow);
	displayInBits(base, pow);
	displayInInt(base, pow);
	return 0;
}

void displayInBits(unsigned int base, unsigned int pow){
	base = base << pow;
	unsigned int mask = 1 << 31;
	size_t i;
	for(i = 1; i <= 32; ++i){
		putchar(base & mask ? '1':'0');
		base <<= 1;
		if (!(i % 8)) putchar(' ');
	}
	putchar('\n');
}

void displayInInt(unsigned int base, unsigned int pow){
	base = base << pow;
	printf("%d", base);
}
