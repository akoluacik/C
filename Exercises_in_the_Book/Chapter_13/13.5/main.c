#include <stdio.h>
#define print(...) printf(__VA_ARGS__) // changing a function name
#define SUM(X, Y) ((X) + (Y))

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    print("%s%d\n", "The sum of x and y is", SUM(x, y));
}