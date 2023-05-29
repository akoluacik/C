#include<stdio.h>

#define	ITER_MAX	1008 // change this to get more accureate results

int main()
{
	double num;
	double denum;
	double result;
	double multiplier;
	int iter;

	num = 4;
	denum = 1;
	result = num;
	multiplier = 1.0;
	for(iter = 2; iter < ITER_MAX; ++iter){ // increase or decrease the iteration count to get the approximate PI values.
		result = result - (multiplier) * (num / denum);
		printf("%dth term: %.5lf\n", iter, result);
		multiplier *= (-1.0);
		denum += 2.0;
	}
	return (0);
}
