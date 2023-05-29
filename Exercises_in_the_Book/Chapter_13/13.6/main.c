#include <stdio.h>

#define MINIMUM2(X, Y) ((X < Y) ? X : Y)
#define MINIMUM3(X, Y, Z) (MINIMUM2(X, Y) < Z ? MINIMUM2(X, Y) : Z)
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%s%d\n", "The minimum is: ", MINIMUM2(x, y));
}