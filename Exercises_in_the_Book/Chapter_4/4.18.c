#include<stdio.h>
int main() {

	int i, j, n;
	for(i = 0;i < 5;i++){
		printf("Enter n:"); scanf("%d", &n);
		for(j = n;j > 0; j--){
			printf("%s", "*");
		}
		puts("");
	}
	return 0;
}