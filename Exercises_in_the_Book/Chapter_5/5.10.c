#include<stdio.h>
#include<math.h>


double roundToInt(double);
double roundToTenths(double);
double roundToHundreths(double);
double roundToThousandths(double);


int main() {
	
	double x = 20.547;
	printf("%lf\n", roundToInt(x));
	printf("%lf\n", roundToTenths(x));
	printf("%lf\n", roundToHundreths(x));
	printf("%lf\n", roundToThousandths(x));
	return 0;
}


double roundToInt(double x) {
	return floor(x + .5);
}

double roundToTenths(double x) {
	return floor(x * 10 + .5) / 10;
}

double roundToHundreths(double x){
	return floor(x * 100 + .5) / 100;
}

double roundToThousandths(double x){
	return floor(x * 1000 + .5) / 1000;
}