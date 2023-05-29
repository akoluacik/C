#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double roundToInt(double);
double roundToTenths(double);
double roundToHundreths(double);
double roundToThousandths(double);

int main(int argc, char **argv) {
	double x;
	
	if (argc == 1)
		x = 20.547;
	else
		x = atof(argv[1]);
	printf("%.3lf\n", roundToInt(x));
	printf("%.3lf\n", roundToTenths(x));
	printf("%.3lf\n", roundToHundreths(x));
	printf("%.3lf\n", roundToThousandths(x));
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