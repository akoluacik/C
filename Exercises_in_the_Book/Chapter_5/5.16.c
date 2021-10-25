#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_triangle(double, double, double); // helper function to determine if this is a triangle.
double area(double, double, double); // calculates the the area of given triangle if it is a triangle.

int main(){
    double side1, side2, side3;
    int i, j, k;
    //printf("%s", "Enter the sides of the triangle: "); scanf("%lf %lf %lf", &side1, &side2, &side3);
    //printf("Area(%.3lf, %.3lf, %.3lf): %.3lf (If -1, this is not a triangle!)", side1, side2, side3, area(side1, side2, side3));
    for(i = 1; i < 50; ++i)
        for(j = 1; j < 50; ++j)
            for(k = 1; k < 50; ++k){
                if(area(i, j, k) != -1)
                    printf("A(%d %d %d): %.3lf\n", i, j, k, area(i, j, k));
                else
                    printf("%s\n", "[ERROR] This is not a triangle!");
            }
    return 0;
}

int is_triangle(double side1, double side2, double side3){
    return (abs(side1 - side2) < side3 && side3 < side1 + side2) && (abs(side1 - side3) < side2 && side2 < side1 + side3)
        && (abs(side2 - side3) < side1 && side1 < side2 + side3);
}

double area(double side1, double side2, double side3){
    double u = (side1 + side2 + side3) / 2.0;
    return (is_triangle(side1, side2, side3) ? (sqrt(u*(u - side1)*(u - side2)*(u - side3))) : -1);
}