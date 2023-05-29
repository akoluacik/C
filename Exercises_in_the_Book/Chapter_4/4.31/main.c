#include<stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int i;
	int j;
	int n;

	if (argc == 1) // if no argument was passed for n
		n = 5;
	else
		n = atoi(argv[1]);
	for(i = 0; i < n; i++) {
		for(j = 0; j < (n-i); j++)
			printf("%c", ' ');
		for(j = 0; j < 2 * i - 1; j++)
			printf("%c", '*');
		puts(" ");
	}
	for(i = 0; i < n ; i++){
		for(j = 0; j < i; j++)
			printf("%c", ' ');
		for(j = 0; j < 2 * (n-i) - 1; j++)
			printf("%c", '*');
		puts(" ");
	}
	return (0);
}