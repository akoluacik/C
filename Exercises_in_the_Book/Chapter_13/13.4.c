#include <stdio.h>

#define PI 3.14
#define VOLUME_SPHERE(R) ((4.0/3) * PI * (R) * (R) * (R))


int main(){
    printf("%lf\n", PI);
    printf("volume: %lf\n", VOLUME_SPHERE(5));
}