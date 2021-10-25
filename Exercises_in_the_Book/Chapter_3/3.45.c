#include<stdio.h>
#include<math.h>
int fact(int);
int main() {
	
	int i,x;
	double ex = 1;
	printf("Enter x:");scanf("%d", &x);
	for(i=1;i<11;i++){
		ex = ex + (double)pow(x, i)/fact(i);
	}
	printf("%lf", ex);
	return 0;
}

int fact(int n){
	if(n==1) return 1;
	return n*fact(n-1);
	
}