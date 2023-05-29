/*
Sorting Integers) Write a program that sorts an array of integers 
into ascending or descending order. Use command-line arguments to
pass either argument -a for ascending order or -d for descending order. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sort(int [], size_t, int(*)(int, int)); // the last parameter decides order, ascending or descending
void swap(int* , int*);
int ascending(int, int);
int descending(int, int);

int main(int argc, char *argv[]){
    int arr[20], i;
    srand(time(NULL));
    if(argc == 1){
        puts("Usage: filename [options]\nOptions: -a || --ascending -> ascending order, -d || --descend - > descending order");
        return 0;
    }
    
    /* random array generation */
    for(i = 0; i < 20; ++i)
        arr[i] = rand() % 40;

    puts("Before sorting");
    for(i = 0; i < 20; ++i)
        printf("%d ", arr[i]);
    
    /* sorting type decision */
    if(!strcmp(argv[1] , "-a") || !strcmp(argv[1], "--ascending")){ // ascending
        sort(arr, 20, ascending);
    }
    else if(!strcmp(argv[1] , "-d") || !strcmp(argv[1], "--descending")) // descending
        sort(arr, 20, descending);
    
    puts("\nAfter sorting");
    for(i = 0; i < 20; ++i)
        printf("%d ", arr[i]);
}

void sort(int arr[], size_t len, int(*compare)(int a, int b)){
    int i, j;
    for(i = 0; i < len - 1; ++i)
        for(j = i + 1; j < len; ++j )
            if((*compare)(arr[i], arr[j]))
                swap(&arr[i], &arr[j]);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int ascending(int a, int b){
    return a > b; // if the current element is larger than next, swap them
}

int descending(int a, int b){
    return a < b; // if the current element is smaller than next, swap them
}
