#include <stdio.h>
#include <stdlib.h>

int get_min(int [], int, int);
void swap(int*, int*);
void print_arr(int [], int);

int main(){

    int arr[] = {7, 4, 1, 3, 5, 6, 25, 18, 11, 17};
    size_t i, len = sizeof(arr)/sizeof(int);
    int min_idx, temp;
    for(i = 0; i < len; ++i){
        min_idx = get_min(arr, i, len);
        swap(&arr[min_idx], &arr[i]);
    }
    print_arr(arr, len);
}

int get_min(int arr[], int start, int size){
    size_t i, j;
    int min = arr[start], min_idx = start;
    for(i = start; i < size; ++i)
        if(min > arr[i]){
            min = arr[i]; // selecting min element
            min_idx = i; // selecting the index of min element
        }
    return min_idx;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_arr(int arr[], int len){
    size_t i;
    for(i = 0; i < len; ++i)
        printf("%d ", arr[i]);
}

// 7, 3, 4, 1, 5, 6, 17, 25, 11, 18

// 1 3 4 7 5 6 17 25 11 18 -> 1 3 4 5 7 6 17 25 11 18
