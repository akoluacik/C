#include<stdio.h>

int isPrime(int, int);

int main(){

	return 0;
}

int isPrime(int x, int divider){
	
	if(x <= 2)
		return (x == 2)?1:0;
	
	if(x % divider == 0) return 0;
	
	if(divider*divider > x)
		return 1;
	
	return isPrime(x, divider + 1);
}