#include<stdio.h>
int GCD(int, int);
int main(){
	int num1, num2;
	printf("Enter number1 and number 2: ");scanf("%d %d", &num1, &num2);
	printf("GCD(%d, %d)=%d", num1, num2,GCD(num1, num2));
	return 0;
}

int GCD(int x, int y){
	int res = ((y==0) ? x : GCD(y, x%y));
	return res;
}