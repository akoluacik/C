#include <stdio.h>
#include <stdlib.h>

int power(int, int);

int main(int argc, char *argv[]){
	int base;
	int exponent;

	if (argc == 1)
	{
		base = 1;
		exponent = 0;
	}
	else if (argc == 2)
	{
		base = atoi(argv[1]);
		exponent = 0;
	}
	else 
	{
		base = atoi(argv[1]);
		exponent = atoi(argv[2]);
	}
	printf("%d^%d = %d", base, exponent, power(base, exponent));
	return 0;
}

int power(int base, int exponent){
	if(exponent == 0){
		return 1;
	}
	return base * power(base, exponent - 1);
}