#include <stdio.h>

#define MINIMUM2(X, Y) ((X < Y) ? X : Y)
#define MINIMUM3(X, Y, Z) (MINIMUM2(X, Y) < Z ? MINIMUM2(X, Y) : Z)
int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("%s%d\n", "The minimum is: ", MINIMUM3(x, y, z));
}