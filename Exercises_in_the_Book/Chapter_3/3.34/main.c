#include<stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	int i;
	int j;
	int n;
	int k;

	k = 0;
	if ( argc < 2 ) // if no parameter is passed for n
		n = 10;
	n = ( argc < 2 ) ? 10 : atoi(argv[1]);
	for(i = 0; i < n; i++){
		for(j = 0; j <= i; j++){
			printf("%d", ++k);
		}
		printf("%c", '\n');
	}
	
	return (0);
}