#include <stdio.h>
#include <stdlib.h>

int isPrime(int, int);

int main(int argc, char *argv[])
{
	int n;

	if (argc == 1)
		n = 13;
	else
		n = atoi(argv[1]);
	
	if (isPrime(n, 2))
		printf("%d is a prime number\n", n);
	else
		printf("%d is not a prime number\n", n);
	return 0;
}

int isPrime(int x, int divider){
	
	if(x <= 2)
		return (x == 2) ? 1 : 0;
	
	if(x % divider == 0) return 0;
	
	if(divider*divider > x)
		return 1;
	
	return isPrime(x, divider + 1);
}