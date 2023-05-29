#include <stdio.h>

int dec2bin(int);

int main(){
	int i;
	int binary;
	
	printf("%-15s%-15s%-15s\n", "Binary", "Octal", "Hexadecimal");
	for(i = 1; i <= 256; ++i){
		binary = dec2bin(i);
		printf("%-15d%-15o%-15X\n", binary, i, i); // %o for octal and %X for hexa equivalent with CAPITAL LETTER, for non-capitals, use %x.
	}
	return (0);
}

int dec2bin(int number)
{
	int res;
	int multiplicand;
	int digit;

	res = 0;
	multiplicand = 1; // to add the digit most left part.
	while(number > 0){
		digit = number % 2; // getting the LSB of binary equivalent.
		res = digit*multiplicand + res; // make the digit MSB
		number /= 2;
		multiplicand *= 10;
	}
	return (res);
}