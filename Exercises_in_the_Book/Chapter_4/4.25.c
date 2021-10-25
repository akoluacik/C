#include <stdio.h>

int bintodec(int);

int main(){
	int i, number, digit, total, multiplicand;
	printf("%-15s%-15s%-15s\n", "Binary", "Octal", "Hexadecimal");
	for(i = 1; i <= 256; ++i){
		number = i;
		total = 0;
		multiplicand=1; // to add the digit most left part.
		while(number > 0){
			digit = number%2; // getting the LSB of binary equivalent.
			total = digit*multiplicand + total; // make the digit MSB
			number/=2;
			multiplicand *= 10;
	    	}
		printf("%-15d%-15o%-15X\n", total, i, i); // %o for octal and %X for hexa equivalent with CAPITAL LETTER, for non-capitals, use %x.
	}
		
}
