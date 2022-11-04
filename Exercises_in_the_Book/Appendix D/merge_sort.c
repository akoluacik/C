#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

// function prototypes
void mergeSort(int array[], size_t length);
void sortSubArray(int array[], size_t low, size_t high);
void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right);
void displayElements(int array[], size_t length);
void displaySubArray(int array[], size_t left, size_t right);

int main(int argc, char const *argv[])
{
    int array[SIZE];
    srand(time(NULL));
    
    for (size_t i = 0; i < SIZE; i++) {
        array[i] = rand() % 90 + 10;
    }
    
    puts("Unsorted array:");
    displayElements(array, SIZE);
    puts("\n");
    mergeSort(array, SIZE);
    puts("Sorted array:");
    displayElements(array, SIZE);
    return 0;
}

// function that merge sorts the array
void mergeSort(int array[], size_t length) {
    sortSubArray(array, 0, length - 1);
}

void sortSubArray(int array[], size_t low, size_t high) {
    if ( (high - low) >= 1 ) {
        size_t middle1 = (low + high) / 2;
        size_t middle2 = middle1 + 1;

        // output split step
        printf("%s", "split:   ");
        displaySubArray(array, low, high);
        printf("%s", "\n   ");
        displaySubArray(array, low, middle1);
        printf("%s", "\n   ");
        displaySubArray(array, middle2, high);
        puts("\n");

        // split array in half and sort each half recursively
        sortSubArray(array, low, middle1);
        sortSubArray(array, middle2, high);

        // merge the two sorted arrays
        merge(array, low, middle1, middle2, high);
    }    
}

void merge(int array[], size_t left, size_t middle1, size_t middle2, size_t right) {

    size_t leftIndex = left;
    size_t rightIndex = middle2;
    size_t combinedIndex = left;
    int tempArray[SIZE];

    // output two subarrays before merging
    printf("%s","merge:   ");
    displaySubArray(array, left, middle1);
    printf("%s", "\n   ");
    displaySubArray(array, middle2, right);
    puts("");

    // merge the subarrays until the end of one is reached
    while(leftIndex <= middle1 && rightIndex <= right) {
        // place the smaller of the two current elements in result
        // and move tot the next space in the subarray

        if(array[leftIndex] <= array[rightIndex])
            tempArray[combinedIndex++] = array[leftIndex++];
        else
            tempArray[combinedIndex++] = array[rightIndex++];
    }

    if(leftIndex == middle2) { // if at end of left subarray ...
        while(rightIndex <= right)
            tempArray[combinedIndex++] = array[rightIndex++];
    }

    else {
        while (leftIndex <= middle1) {
            tempArray[combinedIndex++] = array[leftIndex++];
        }
    }
    
    // copy values back into original array
    for (size_t i = left; i <= right; i++) {
        array[i] = tempArray[i];
    }
    
    // output merged subarray
    printf("%s", "   ");
    displaySubArray(array, left, right);
    puts("\n");

}

void displayElements(int array[], size_t length) {
    displaySubArray(array, 0, length - 1);
}

void displaySubArray(int array[], size_t left, size_t right) {
    
    // output spaces for alignment
    for (size_t i = 0; i < left; i++)
        printf("%s", "   ");
    
    // output elements left in array
    for (size_t i = left; i <= right; i++)
        printf(" %d", array[i]);
    
}