#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high); 
void displayArr(int arr[], size_t size);
void swap(int* x, int* y);

int main(int argc, char const *argv[])
{
    
    int arr[SIZE];
    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++)
        arr[i] = rand() % 90 + 10;
    
    puts("Before sorting:");
    displayArr(arr, SIZE);
    puts("");
    quicksort(arr, 0, SIZE - 1);
    puts("After sorting:");
    displayArr(arr, SIZE);
    puts("");
    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (size_t j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {

    if(low < high) {
        int idx = partition(arr, low, high);
        quicksort(arr, low, idx - 1);
        quicksort(arr, idx + 1, high);
    }
}

void displayArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%d ", arr[i]);  
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}