#include<stdio.h>
int power(int, int);
int main(){
	int base, exponent;
	printf("Enter base and exponent: ");scanf("%d %d", &base, &exponent);
	printf("%d^%d = %d", base, exponent, power(base, exponent));
	return 0;
}

int power(int base, int exponent){
	if(exponent == 0){
		return 1;
	}
	return base * power(base, exponent - 1);
}