#include <stdio.h>

int mystery(unsigned int bits);

int main(void){
	unsigned int x;
	scanf("%u", &x);
	printf("The result is %d\n", mystery(x));
}

int mystery(unsigned int bits){
	unsigned int mask = 1 << 31;
	unsigned int total = 0, i;
	for(i = 1; i <= 32; ++i){
		if((bits & mask) == mask)
			++total;
	}
	printf("%d\n", total);
	return !(total % 2) ? 1:0;
}
