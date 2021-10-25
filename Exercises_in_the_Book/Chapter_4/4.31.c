#include<stdio.h>

int main(){
	int i, j, n;
	printf("Enter n: ");scanf("%d", &n);
	for(i = 0;i < n - 1; i++) {
		for(j = 0; j < (n-i); j++) printf("%s", " ");
		for(j = 0; j < 2 * i - 1; j++) printf("%s", "*");
		puts(" ");
	}

	for(i = 0; i < n - 1 ; i++){
		for(j = 0; j < i; j++) printf("%s", " ");
		for(j = 0; j < 2 * (n-i) - 1; j++) printf("%s", "*");
		puts(" ");
	}
	return 0;
}