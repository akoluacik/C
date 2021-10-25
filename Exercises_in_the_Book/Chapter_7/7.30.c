#include <stdio.h>

#define PI 3.14

void circumference(double);
void area(double);
void volume(double);

int main(){
	
	void (*f[3])(double) = {circumference, area, volume};
	double radius;
	int i;
	while(1){
		printf("Enter a radius: ");scanf("%lf", &radius);
		if(radius <= 0.0){
			printf("Wrong value. Program execution is ended!\n");
			break;
		}
		for(i=0;i<3;i++){
			f[i](radius);
		}
	}
	
	
	return 0;
}

void circumference(double radius){
	printf("Circumference is: %lf\n", 2*PI*radius);
}

void area(double radius){
	printf("Area is: %lf\n", PI*radius*radius);
}

void volume(double radius){
	printf("Volume is: %lf\n", (double)(4/3)*PI*radius*radius*radius);
}
