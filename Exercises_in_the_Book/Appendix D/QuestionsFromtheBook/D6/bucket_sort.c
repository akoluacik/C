#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW     10
#define COL     5
#define SIZE    COL

int getDigitNumber(int n);
int getDigit(int number, int digitVal);
int getMax(int arr[], size_t size);
void bucket_sort(int arr[]); 
void insertionSort(int array[], size_t length);
void displayArr(int arr[], size_t size);

int main(int argc, char const *argv[])
{
    
    int arr[SIZE];

    srand(time(NULL));
    for (size_t i = 0; i < SIZE; i++)
        arr[i] =  (rand() % 90) + 10;
    
    
    displayArr(arr, SIZE);
    puts("");
    
    bucket_sort(arr);
    
    puts("After sorting:");
    puts("");
    displayArr(arr, SIZE);
    
    return 0;
}


void displayArr(int arr[], size_t size) {

    for (size_t i = 0; i < size; i++)
        printf("%-3d ", arr[i]);
    
}

int getDigit(int number, int digitVal) {
    return (number / digitVal) % 10;
}

void bucket_sort(int arr[]) {
    
    int **bucket_arr = (int**)malloc(sizeof(int*) * ROW);

    int idx = 0;

    for (size_t i = 0; i < ROW; i++)
        bucket_arr[i] = (int*)calloc(COL, sizeof(int));
    
    int *numOfElems = (int*)calloc(ROW, sizeof(int));
    
    int remainder;
    int maxElem = getMax(arr, SIZE);
    int digNum = getDigitNumber(maxElem);

    for (size_t i = 0; i < digNum; i++) {
        idx = 0;
        for (size_t j = 0; j < SIZE; j++) {
            remainder = getDigit(arr[j], pow(10, i));
            bucket_arr[remainder][numOfElems[remainder]] = arr[j];
            numOfElems[remainder]++;
        }
        
        for (size_t k = 0; k < ROW; k++) {
            for (size_t p = 0; p < COL; p++) {
                if(!bucket_arr[k][p]) continue;
                arr[idx++] = bucket_arr[k][p];
                bucket_arr[k][p] = 0;
            }
        }
        
        for (size_t k = 0; k < ROW; k++)
            numOfElems[k] = 0;

    }
    
    free(numOfElems);
    
    for (size_t i = 0; i < ROW; i++)
        free(bucket_arr[i]);
    
    free(bucket_arr);
    insertionSort(arr, SIZE);

}


void insertionSort(int array[], size_t length) {
    for (size_t i = 1; i < length; i++) {
        size_t moveItem = i;   // initialize location to place element
        int insert = array[i]; // holds element to insert

        // search for place to put current element
        while (moveItem > 0 && array[moveItem - 1] > insert) {
            // shift element right one slot
            array[moveItem] = array[moveItem - 1];
            --moveItem;
        }
        
        array[moveItem] = insert; // place inserted element
        //printPass(array, length, i, moveItem);
    }
}

int getDigitNumber(int n) {
    int total = 0;
    
    while( n > 0 ) {
        n /= 10;
        total++;
    }

    return total;
}

int getMax(int arr[], size_t size) {
    
    int max = arr[0];
    
    for (size_t i = 1; i < size; i++) {
        if(max < arr[i])
            max = arr[i];
    }

    return max;
}