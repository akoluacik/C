#include<stdio.h>
#include<math.h>

int fact(int n); // factorial calculator

int main() {
	
	int 	i;
	int 	x;
	int		power;
	double ex;

	ex = 1;
	do
	{
		printf("Enter x(i.e., 2 for e^2):");
		scanf("%d", &x);
	} while (x < 0);

	// part b&c, if x = 0, it is part b.
	// computes the value with first 11 elements.
	for(i=1;i<11;i++){
		ex = ex + (double)pow(x, i)/fact(i);
	}
	printf("%lf", ex);
	return 0;
}
// part a
int fact(int n){
	if(n==1) return 1;
	return (n*fact(n-1));
	
}