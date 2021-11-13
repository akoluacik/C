#include <stdio.h>
#include <stdlib.h>
#define PRINTARRAY(ARR, LEN) \
    int i; \
    for(i = 0; i < LEN; ++i) \
    printf("%d ", ARR[i]);

int main(){
    int arr[] = {1, 2, 7, 4, 5, 9};
    PRINTARRAY(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}