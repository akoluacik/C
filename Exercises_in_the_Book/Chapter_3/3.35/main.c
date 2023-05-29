#include<stdlib.h> // for atoi
#include <stdio.h>

#define UNUSED(X) (void)X

int main(int argc, char **argv){
	
	int number;
	int dec_result;
	int rem;
	int multiplier;

	UNUSED(argc);
	dec_result = 0;
	number = atoi(argv[1]);
	multiplier = 1;
	while(number > 0){
		rem = number % 2;
		dec_result += rem * multiplier;
		multiplier *= 2;
		number = number / 10;
	}
	printf("%d\n", dec_result);
	return (0);
}