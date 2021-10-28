#include <stdio.h>
void displayInBits(unsigned int, unsigned int);

int main(){	
	unsigned int u, shifter=4;
	printf("%s", "Enter a non-negative integer:"); scanf("%u", &u);
	displayInBits(u, shifter);
	return 0;
}

void displayInBits(unsigned int u, unsigned int shifter){
	size_t i;
	u >>= shifter;
	unsigned int mask = 1<<31;
	for(i=1;i<=32;++i){
		putchar(u & mask ? '1':'0');
		u <<= 1;
		if(i % 8 == 0) putchar(' ');
	}
	putchar('\n');
}
