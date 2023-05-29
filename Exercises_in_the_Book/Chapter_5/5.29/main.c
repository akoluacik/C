#include<stdio.h>
int LCM(int, int);
int GCD(int, int);
int main(){
	
	int n1, n2;
	printf("Enter number1:");scanf("%d", &n1);
	printf("Enter number2:");scanf("%d", &n2);
	printf("%d", n1*n2/GCD(n1, n2));
	
	return 0;
}

int GCD(int x, int y) {
	return (x > y) ? GCD(x-y, y):((x==y)?(x):GCD(x, y-x));
}

