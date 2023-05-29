#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define SIZE 10

void selectionSortRecursive(int arr[], size_t idx, size_t size); // recursive
void selectionSort(int arr[], size_t size); // non-recursive
void displayArr(int arr[], size_t size);
void swap(int *x, int *y);
int findMin(int arr[], size_t start_idx, size_t size, int *min_idx);
void print_function(int arr[], size_t size, size_t ast_idx, int iter_num);

int main(int argc, char const *argv[])
{
    
    int arr[SIZE];
    
    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 90 + 10;
    }
    
    displayArr(arr, SIZE);
    puts("");
    selectionSortRecursive(arr, 0, SIZE);
    puts("\nAfter Selection Sort:");
    displayArr(arr, SIZE);
    puts("");
    return 0;
}

void selectionSort(int arr[], size_t size) {

    int min, min_idx;
    for (size_t i = 0; i < size; i++) {
        // findMin returns the smallest element, here min_idx is actually an output
        min = findMin(arr, i, size, &min_idx);
        print_function(arr, size, min_idx, i + 1); 
        swap(&arr[i], &arr[min_idx]);
    }
    
}

void selectionSortRecursive(int arr[], size_t idx, size_t size) {

    int min, min_idx;
    
    if(size -1 != idx) {
        min = findMin(arr, idx, size, &min_idx);
        print_function(arr, size, min_idx, idx + 1);
        swap(&arr[idx], &arr[min_idx]);
        selectionSortRecursive(arr, ++idx, size);
    }
}

void print_function(int arr[], size_t size, size_t ast_idx, int iter_num) {

    printf("Iter num: %d: ", iter_num);

    for (size_t i = 0; i < ast_idx; i++)
        printf("%d ", arr[i]);
    
    printf("%d* ", arr[ast_idx]);

    for (size_t i = ast_idx + 1; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int findMin(int arr[], size_t start_idx, size_t size, int *min_idx) {

    int min = INT_MAX;
    for (size_t i = start_idx; i < size; i++) {
        if(arr[i] < min){
            min = arr[i];
            *min_idx = i;       
        }
    }
    return min;
}

void displayArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
}