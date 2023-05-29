#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SALESPERSON 4
#define PRODUCT 5

int main(){
	int i;
	int j;
	int total; 
	int arr[PRODUCT][SALESPERSON];
	
	total = 0;
	srand(time(NULL));
	for(i = 0; i < PRODUCT; i++)
		for(j = 0; j < SALESPERSON; j++)
			arr[i][j] = 300 + rand()%2000;
	printf("%10d%7d%8d%9d\n",1,2,3,4);
	for(i = 0; i < PRODUCT; i++){
		printf("%d\t", i);
		for(j = 0; j < SALESPERSON; j++){
			printf("%d\t ", arr[i][j]);
		}
		puts(" ");
	}
	puts("Summarizing by product");
	for(i = 0; i < PRODUCT; i++){
		printf("%d\t", i + 1);
		for(j = 0;j < SALESPERSON; j++){
			total += arr[i][j];
		}
		printf("%d\n", total);
		total = 0;
	}
	puts("Summarizing by salesperson");
	printf("%2d%9d%8d%8d\n",1,2,3,4);
	for(i = 0; i < 4; i++){
		for(j = 0;j < 5; j++){
			total += arr[j][i];
		}
		printf("%d\t", total);
		total = 0;
	}
	return 0;
}