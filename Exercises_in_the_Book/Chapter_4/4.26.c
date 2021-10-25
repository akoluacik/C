#include<stdio.h>

int main(){
	
	double num = 4.0, denum = 3.0, result = num, multiplier = 1.0;
	int iter;
	for(iter = 2; iter < 1008; ++iter){ // increase or decrease the iteration count to get the approximate PI values.
		result = result - (multiplier) * (num / denum);
		printf("%dth term: %.5lf\n", iter, result);
		multiplier *= (-1.0);
		denum += 2.0;
	}
	return 0;
}
