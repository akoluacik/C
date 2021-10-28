#include <stdio.h>
#include <limits.h>
void displayBits(unsigned int value);

int main(void){
	// demonstrate bitwise AND (&)
	unsigned int number1 = 65535, mask = 1;
	puts("The result of combining the following");
	displayBits(number1);
	displayBits(mask);
	puts("using the bitwise AND operator & is");
	displayBits(number1 & mask);
	
	// demonstrate bitwise inclusive OR (|)
	number1 = 15;
	unsigned int setBits = 241;
	puts("The result of combining the following");
	displayBits(number1);
	displayBits(setBits);
	puts("using the bitwise OR operator | is");
	displayBits(number1 | setBits);
	
	// demonstrate bitwise exclusive OR (^)
	number1 = 139;
	unsigned int number2 = 199;
	puts("The result of combining the following");
	displayBits(number1);
	displayBits(number2);
	puts("using the bitwise OR operator ^ is");
	displayBits(number1 ^ number2);
	
}

void displayBits(unsigned int value){
	unsigned int displayMask = 1 << sizeof(unsigned int) * CHAR_BIT - 1;
	printf("%10u = ",  value);
	
	unsigned int c;
	for(c = 1; c <= 32; ++c){
		putchar(value & displayMask ? '1':'0');
		value <<= 1;
		if(c % 8 == 0) putchar(' ');
	}
	putchar('\n');
}
