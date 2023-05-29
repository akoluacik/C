#include <stdio.h>
#include <stdlib.h>

int sum(int);

int main(int argc, char **argv){
	int n;

	if (argc == 1)
		n = 7631;
	else
		n = atoi(argv[1]);
	printf("%d", sum(n));
	return 0;
}

int sum(int number){
	if(number == 0)
		return 0;
	return (number % 10) + sum(number / 10);
}