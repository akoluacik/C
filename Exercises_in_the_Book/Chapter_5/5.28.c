#include<stdio.h>

int sum(int);

int main(){
	int n;
	printf("Enter n:"); scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}

int sum(int number){
	if(number == 0)
		return 0;
	return (number % 10) + sum(number / 10);
}