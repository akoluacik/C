#include <stdio.h>

void packChars(char []);
void displayInBits(unsigned int);
void unpackChars(unsigned int);
int main(){
	unsigned int x;
	char c[4], temp;
	size_t i;
	for(i=0;i<4;++i){
		printf("Enter a char:");scanf("%c", &c[i]);
		scanf("%c", &temp);
		x = c[i];
	}
	puts(" ");
	packChars(c);
	return 0;
}

void packChars(char c[]){
	unsigned int x;
	size_t i=1;
	x = c[0];
	while(i < 4){
		x = x << 8;
		x = x | c[i++];
	}
	displayInBits(x);
	unpackChars(x);
}

void unpackChars(unsigned int x){
	unsigned int mask = 4278190080;
	char c[4];
	size_t i, shifter;
	for(i=0,shifter=24;i<4;i++, shifter -= 8){
		c[i] = (x & mask)>>shifter;
		putchar(c[i]);
		mask = mask >> 8;
	}
	
	
}

void displayInBits(unsigned int x){
	unsigned int mask = 1 << 31;
	size_t i;
	for(i = 1; i <= 32; ++i){
		putchar(x & mask ? '1':'0');
		x <<= 1;
		if(i % 8 == 0) putchar(' ');
	}
	putchar('\n');
}


